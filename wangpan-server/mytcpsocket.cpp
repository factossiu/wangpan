#include "mytcpsocket.h"
#include "mytcpserver.h"
#include <QFile>
MyTcpSocket::MyTcpSocket(QObject *parent)
    : QTcpSocket{parent}
{
    connect(this,SIGNAL(readyRead()),this,SLOT(receiveMsg()));
    connect(this, SIGNAL(disconnected()), this, SLOT(clientOffline())); // 关联Socket连接断开与客户端下线处理槽函数
    m_bUploadt = false;
    m_pTimer = new QTimer;
    connect(m_pTimer,SIGNAL(timeout()),
            this,SLOT(sendFileToClient()));
}

/*void MyTcpSocket::receiveMsg()
{
    qDebug() << this -> bytesAvailable(); // 输出接收到的数据大小
    uint uiPDULen = 0;
    this -> read((char*)&uiPDULen, sizeof(uint)); // 先读取uint大小的数据，首个uint正是总数据大小
    uint uiMsgLen = uiPDULen - sizeof(PDU); // 实际消息大小，sizeof(PDU)只会计算结构体大小，而不是分配的大小
    PDU *pdu = mkPDU(uiMsgLen);
    this -> read((char*)pdu + sizeof(uint), uiPDULen - sizeof(uint)); // 接收剩余部分数据（第一个uint已读取）
    // qDebug() << pdu -> uiMsgType << ' ' << (char*)pdu -> caMsg; // 输出

    // 根据不同消息类型，执行不同操作
    PDU* resPdu = NULL; // 响应报文
    switch(pdu -> uiMsgType)
    {
    case ENUM_MSG_TYPE_REGIST_REQUEST: // 注册请求
    {
        resPdu = handleRegistRequest(pdu); // 请求处理
        break;
    }
    default:
        break;
    }

    // 响应客户端
    if(NULL != resPdu)
    {
        qDebug() << resPdu -> uiMsgType << " " << resPdu ->caData;
        this -> write((char*)resPdu, resPdu -> uiPDULen);
        // 释放空间
        free(resPdu);
        resPdu = NULL;
    }
    // 释放空间
    free(pdu);
    pdu = NULL;
}*/


// 处理注册请求并返回响应PDU
void MyTcpSocket::receiveMsg()
{
    if(!m_bUploadt){
    //qDebug() <<"收到的数据大小："<<this -> bytesAvailable(); // 输出接收到的数据大小
    uint uiPDULen = 0;
    this -> read((char*)&uiPDULen, sizeof(uint)); // 先读取uint大小的数据，首个uint正是总数据大小
    uint uiMsgLen = uiPDULen - sizeof(PDU); // 实际消息大小，sizeof(PDU)只会计算结构体大小，而不是分配的大小
    PDU *pdu = mkPDU(uiMsgLen);
    this -> read((char*)pdu + sizeof(uint), uiPDULen - sizeof(uint)); // 接收剩余部分数据（第一个uint已读取）
    // qDebug() << pdu -> uiMsgType << ' ' << (char*)pdu -> caMsg; // 输出

    // 根据不同消息类型，执行不同操作
    //PDU* resPdu = NULL; // 响应报文
    switch(pdu -> uiMsgType)
    {

    case ENUM_MSG_TYPE_REGIST_REQUEST: // 注册请求
    {
        char caName[32] = {'\0'};
        char caPwd[32] = {'\0'};
        strncpy(caName,pdu->caData,32);
        strncpy(caPwd,pdu->caData+32,32);
        bool ret = opedb::getInstance().handleRegist(caName,caPwd);
        PDU *respdu =mkPDU(0);
        respdu->uiMsgType = ENUM_MSG_TYPE_REGIST_RESPOND;
        if(ret){

            strcpy(respdu->caData,REGIST_OK);
            QDir dir;
            qDebug()<<"create dir:"<<dir.mkdir(QString("./%1").arg(caName));

        }
        else{
            strcpy(respdu->caData,REGIST_FAILED);
        }
        write((char*)respdu,respdu->uiPDULen);
        free(respdu);
        respdu = NULL;
        break;
    }
    case ENUM_MSG_TYPE_LOGIN_REQUEST: // 注册请求
    {
        char caName[32] = {'\0'};
        char caPwd[32] = {'\0'};
        strncpy(caName,pdu->caData,32);
        strncpy(caPwd,pdu->caData+32,32);
        bool ret = opedb::getInstance().handleLogin(caName,caPwd);
        PDU *respdu =mkPDU(0);
        respdu->uiMsgType = ENUM_MSG_TYPE_LOGIN_RESPOND;
        if(ret){
            strcpy(respdu->caData,LOGIN_OK);
            m_strName = caName;
        }
        else{
            strcpy(respdu->caData,LOGIN_FAILED);
        }
        write((char*)respdu,respdu->uiPDULen);
        free(respdu);
        respdu = NULL;
        break;
    }
    case ENUM_MSG_TYPE_ALL_ONLINE_REQUEST: // 查询在线用户
    {
        QStringList ret = opedb::getInstance().handleAllOnline();
        uint uiMsgLen = ret.size()*32;
        PDU *respdu = mkPDU(uiMsgLen);
        respdu->uiMsgType = ENUM_MSG_TYPE_ALL_ONLINE_RESPOND;
        for(int i=0;i<ret.size();i++){
            memcpy((char*)(respdu->caMsg)+i*32,ret.at(i).toStdString().
            c_str(),ret.at(i).size());
        }
        write((char*)respdu,respdu->uiPDULen);
        free(respdu);
        respdu = NULL;
        break;
    }
    case ENUM_MSG_TYPE_SEARCH_USER_REQUEST: // 查找用户信息
    {
        int ret = opedb::getInstance().handleSearchUser(pdu->caData);
        PDU *respdu = mkPDU(0);
        respdu->uiMsgType = ENUM_MSG_TYPE_SEARCH_USER_RESPOND;
        if(-1 == ret){
            strcpy(respdu->caData,SEARCH_USER_NO);
        }
        else if(1 == ret){
            strcpy(respdu->caData,SEARCH_USER_ONLINE);
        }
        else if(0 == ret){
            strcpy(respdu->caData,SEARCH_USER_OFFLINE);
        }
        write((char*)respdu,respdu->uiPDULen);
        free(respdu);
        respdu = NULL;
        break;
    }
    case ENUM_MSG_TYPE_ADD_FRIEND_REQUEST:
    {
        char caPerName[32] = {'\0'};
        char caName[32] = {'\0'};
        strncpy(caPerName,pdu->caData,32);
        strncpy(caName,pdu->caData+32,32);
        int ret = opedb::getInstance().handleAddFriend(caPerName,caName);
        // 0对方存在不在线，1对方存在在线，2不存在，3已是好友，4请求错误
        PDU *respdu = NULL;
        if(ret == 4){
            respdu = mkPDU(0);
            respdu->uiMsgType = ENUM_MSG_TYPE_ADD_FRIEND_RESPOND;
            strcpy(respdu->caData,UNKNOW_ERROR);
            write((char*)respdu,respdu->uiPDULen);
            free(respdu);
            respdu = NULL;
        }
        else if(ret == 0){
           respdu = mkPDU(0);
           respdu->uiMsgType = ENUM_MSG_TYPE_ADD_FRIEND_RESPOND;
           strcpy(respdu->caData,ADD_FRIEND_OFFLINE);
           write((char*)respdu,respdu->uiPDULen);
           free(respdu);
           respdu = NULL;
        }
        else if(ret == 1){
           MyTcpServer::getInstance().resend(caPerName,pdu);

        }
        else if(ret == 2){
           respdu = mkPDU(0);
           respdu->uiMsgType = ENUM_MSG_TYPE_ADD_FRIEND_RESPOND;
           strcpy(respdu->caData,ADD_FRIEND_NOEXIST);
           write((char*)respdu,respdu->uiPDULen);
           free(respdu);
           respdu = NULL;
        }
        else if(ret == 3){
            respdu = mkPDU(0);
            respdu->uiMsgType = ENUM_MSG_TYPE_ADD_FRIEND_RESPOND;
            strcpy(respdu->caData,EXISTED_FRINEND);
            write((char*)respdu,respdu->uiPDULen);
            free(respdu);
            respdu = NULL;
        }
        break;
    }
    case  ENUM_MSG_TYPE_ADD_FRIEND_AGGREE: // 同意加好友
    {
        this->handleAddFriendAgree(pdu);
        break;
    }
    case ENUM_MSG_TYPE_ADD_FRIEND_REFUSE: // 拒绝加好友
    {
        this->handleAddFriendReject(pdu);
        break;
    }
    case ENUM_MSG_TYPE_FLUSG_REQUEST:{
        char caName[32] = {'\0'};
        strncpy(caName,pdu->caData,32);

        QStringList ret = opedb::getInstance().handleFlushFriend(caName);
        uint uiMsgLen = ret.size()*32;
        PDU *respdu = mkPDU(uiMsgLen);
        respdu->uiMsgType = ENUM_MSG_TYPE_FLUSH_RESPOND;
        for(int i = 0;i<ret.size();i++){
            memcpy((char*)(respdu->caMsg)+i*32,ret.at(i).toStdString()
                                                          .c_str(),ret.at(i).size());
        }

        write((char*)respdu,respdu->uiPDULen);
        free(respdu);
        respdu = NULL;
        break;
    }
    case ENUM_MSG_TYPE_DEL_REQUEST:
    {
        char caName[32] = {'\0'};
        char caFriName[32] = {'\0'};
        strncpy(caName,pdu->caData,32);
        strncpy(caFriName,pdu->caData+32,32);
        opedb::getInstance().handleDelFriend(caName,caFriName);

        PDU *respdu = mkPDU(0);
        respdu->uiMsgType = ENUM_MSG_TYPE_DEL_RESPOND;
        strcpy(respdu->caData,DEL_FRIEND_OK);
        write((char*)respdu,respdu->uiPDULen);
        free(respdu);
        respdu = NULL;
        MyTcpServer::getInstance().resend(caFriName,pdu);

        break;

    }
    case ENUM_MSG_TYPE_PRIVATE_CHAT_REQUEST:{
        char caPerName[32] = {'\0'};
        memcpy(caPerName,pdu->caData+32,32);
        MyTcpServer::getInstance().resend(caPerName,pdu);

        break;
    }
    case ENUM_MSG_TYPE_GROUP_CHAT_REQUEST:
    {
        char caName[32] = {'\0'};
        strncpy(caName,pdu->caData,32);
        QStringList onlineFriend = opedb::getInstance().handleFlushFriend(caName);
        QString tmp;
        for(int i = 0;i<onlineFriend.size();i++){
            tmp = onlineFriend.at(i);
            MyTcpServer::getInstance().resend(tmp.toStdString().c_str(),pdu);
        }
        break;
    }
    case ENUM_MSG_TYPE_CREATE_DIR_REQUEST:{
        QDir dir;
        QString strCurPath = QString("%1").arg((char*)pdu->caMsg);
        bool ret = dir.exists(QString(strCurPath));
        PDU *respdu = NULL;
        if(ret){ //当前目录存在
            char caNewDir[32] = {'\0'};
            memcpy(caNewDir,pdu->caData+32,32);
            QString strNewPath = strCurPath+"/"+caNewDir;
            qDebug() << strNewPath;
            ret = dir.exists(strNewPath);
            qDebug()<<"-->"<<ret;
            if(ret){ //创建的文件已存在
                respdu = mkPDU(0);
                respdu->uiMsgType = ENUM_MSG_TYPE_CREATE_DIR_RESPOND;
                strcpy(respdu->caData,DIR_NAME_EXIST);
            }
            else{//创建的文件名不存在
                dir.mkdir(strNewPath);
                respdu = mkPDU(0);
                respdu->uiMsgType = ENUM_MSG_TYPE_CREATE_DIR_RESPOND;
                strcpy(respdu->caData,CREATE_DIR_OK);
            }
        }
        else{//当前目录不存在
            respdu = mkPDU(0);
            respdu->uiMsgType = ENUM_MSG_TYPE_CREATE_DIR_RESPOND;
            strcpy(respdu->caData,DIR_NOT_EXIST);
        }
        write((char*)respdu,respdu->uiPDULen);
        free(respdu);
        respdu = NULL;
        break;
    }
    case ENUM_MSG_TYPE_FLUSH_FILE_REQUEST:
    {
        char *pCurPath = new char[pdu->uiMsgLen];
        memcpy(pCurPath,pdu->caMsg,pdu->uiMsgLen);
        QDir dir(pCurPath);
        QFileInfoList fileInfoList = dir.entryInfoList(QDir::Files|QDir::Dirs | QDir::NoDotAndDotDot);
        qDebug()<<fileInfoList.size();
        int iFileCount = fileInfoList.size();
        PDU *respdu = mkPDU(sizeof(FileInfo)*iFileCount);
        respdu->uiMsgType = ENUM_MSG_TYPE_FLUSH_FILE_RESPOND;
        FileInfo *pFileInfo = NULL;
        QString strFileName;
        for(int i=0;i<iFileCount;i++){
            pFileInfo = (FileInfo*)(respdu->caMsg)+i;
            strFileName = fileInfoList[i].fileName();
            qDebug()<<"strFileName:"<<strFileName;
            memcpy(pFileInfo->caFileName,strFileName.toStdString().c_str(),strFileName.size());
            if(fileInfoList[i].isDir()){
                pFileInfo->iFileType = 0;
            }
            else if(fileInfoList[i].isFile()){
                pFileInfo->iFileType = 1;
            }
            qDebug()<<fileInfoList[i].fileName()<<fileInfoList[i].size() << fileInfoList[i].filePath();

        }
        write((char*)respdu,respdu->uiPDULen);
        free(respdu);
        respdu = NULL;
        break;
    }
    case ENUM_MSG_TYPE_DEL_DIR_REQUEST:{
        char caName[32] = {'\0'};
        strcpy(caName,pdu->caData);
        char *pPath = new char[pdu->uiMsgLen];
        memcpy(pPath,pdu->caMsg,pdu->uiMsgLen);
        QString strPath = QString("%1/%2").arg(pPath).arg(caName);
        qDebug()<<strPath;
        QFileInfo fileInfo(strPath);
        bool ret = false;
        if(fileInfo.isDir()){
            QDir dir;
            dir.setPath(strPath);
            ret = dir.removeRecursively();
        }
        else if(fileInfo.isFile()){ //常规文件
            ret =false;
        }
        PDU *respdu = NULL;
        if(ret){
            respdu = mkPDU(strlen(DEL_DIR_OK+1));
            respdu->uiMsgType = ENUM_MSG_TYPE_DEL_DIR_RESPOND;
            memcpy(respdu->caData,DEL_DIR_OK,strlen(DEL_DIR_OK));
        }
        else{
            respdu = mkPDU(strlen(DEL_DIR_FAILURED+1));
            respdu->uiMsgType = ENUM_MSG_TYPE_DEL_DIR_RESPOND;
            memcpy(respdu->caData,DEL_DIR_FAILURED,strlen(DEL_DIR_FAILURED));
        }
        write((char*)respdu,respdu->uiPDULen);
        free(respdu);
        respdu = NULL;
        break;
    }
    case ENUM_MSG_TYPE_RENAME_FILE_REQUEST:{
        char caOldName[32] = {'\0'};
        char caNewName[32] = {'\0'};
        strncpy(caOldName,pdu->caData,32);
        strncpy(caNewName,pdu->caData+32,32);

        char *pPath = new char[pdu->uiMsgLen];
        memcpy(pPath,pdu->caMsg,pdu->uiMsgLen);

        QString strOldPath=QString("%1/%2").arg(pPath).arg(caOldName);
        QString strNewPath=QString("%1/%2").arg(pPath).arg(caNewName);
        qDebug()<<strOldPath;
        qDebug()<<strNewPath;
        QDir dir;
        bool ret = dir.rename(strOldPath,strNewPath);
        PDU *respdu = mkPDU(0);
        pdu->uiMsgType = ENUM_MSG_TYPE_RENAME_FILE_RESPOND;
        if(ret){
            strncpy(respdu->caData,RENAME_FILE_OK,32);
        }
        else{
            strncpy(respdu->caData,RENAME_FILE_FAILURED,32);
        }

        write((char*)respdu,respdu->uiPDULen);
        free(respdu);
        respdu = NULL;
        break;
    }
    case ENUM_MSG_TYPE_ENTER_FILE_REQUEST:{
        char caEnterName[32] = {'\0'};
        char caNewName[32] = {'\0'};
        strncpy(caEnterName,pdu->caData,32);

        char *pPath = new char[pdu->uiMsgLen];
        memcpy(pPath,pdu->caMsg,pdu->uiMsgLen);

        QString strPath=QString("%1/%2").arg(pPath).arg(caEnterName);
        qDebug()<<strPath;
        QFileInfo fileInfo(strPath);
        PDU *respdu = NULL;

        if(fileInfo.isDir()){
            QDir dir(strPath);
            QFileInfoList fileInfoList = dir.entryInfoList(QDir::Files|QDir::Dirs | QDir::NoDotAndDotDot);
            int iFileCount = fileInfoList.size();
            PDU *respdu = mkPDU(sizeof(FileInfo)*iFileCount);
            respdu->uiMsgType = ENUM_MSG_TYPE_FLUSH_FILE_RESPOND;
            FileInfo *pFileInfo = NULL;
            QString strFileName;
            for(int i=0;i<iFileCount;i++){
                pFileInfo = (FileInfo*)(respdu->caMsg)+i;
                strFileName = fileInfoList[i].fileName();
                memcpy(pFileInfo->caFileName,strFileName.toStdString().c_str(),strFileName.size());
                if(fileInfoList[i].isDir()){
                    pFileInfo->iFileType = 0;
                }
                else if(fileInfoList[i].isFile()){
                    pFileInfo->iFileType = 1;
                }
                qDebug()<<fileInfoList[i].fileName()<<fileInfoList[i].size() << fileInfoList[i].filePath();

            }
            write((char*)respdu,respdu->uiPDULen);
            free(respdu);
            respdu = NULL;
        }
        else if(fileInfo.isFile()){
            respdu = mkPDU(0);
            respdu->uiMsgType = ENUM_MSG_TYPE_ENTER_FILE_RESPOND;
            strncpy(respdu->caData,ENTER_DIR_FAILURED,strlen(ENTER_DIR_FAILURED));

            write((char*)respdu,respdu->uiPDULen);
            free(respdu);
            respdu = NULL;
        }
        break;
    }
    case ENUM_MSG_TYPE_UPLOAD_FILE_REQUEST:{
        char caFileName[32] = {'\0'};
        qint64 fileSize = 0;
        sscanf(pdu->caData,"%s %11d",caFileName,&fileSize);
        char *pPath = new char[pdu->uiMsgLen];
        memcpy(pPath,pdu->caMsg,pdu->uiMsgLen);
        QString strPath = QString("%1/%2").arg(pPath).arg(caFileName);
        qDebug()<<"要传过去的路径是"<<strPath;
        delete []pPath;
        pPath = NULL;

        m_file.setFileName(strPath);
        //以只写的方式打开文件，若文件不存在，则会自动创建文件
        if(m_file.open(QIODevice::WriteOnly)){
            m_bUploadt = true;
            m_iTotal = fileSize;
            m_iRecved = 0;
        }
        break;
    }
    case ENUM_MSG_TYPE_DEL_FILE_REQUEST:{
        char caName[32] = {'\0'};
        strcpy(caName,pdu->caData);
        char *pPath = new char[pdu->uiMsgLen];
        memcpy(pPath,pdu->caMsg,pdu->uiMsgLen);
        QString strPath = QString("%1/%2").arg(pPath).arg(caName);
        qDebug()<<strPath;
        QFileInfo fileInfo(strPath);
        bool ret = false;
        if(fileInfo.isDir()){
        ret = false;
        }
        else if(fileInfo.isFile()){ //常规文件
           QDir dir;
          ret = dir.remove(strPath);
        }
        PDU *respdu = NULL;
        if(ret){
            respdu = mkPDU(strlen(DEL_FILE_OK+1));
            respdu->uiMsgType = ENUM_MSG_TYPE_DEL_FILE_RESPOND;
            memcpy(respdu->caData,DEL_FILE_OK,strlen(DEL_DIR_OK));
        }
        else{
            respdu = mkPDU(strlen(DEL_FILE_FAILURED+1));
            respdu->uiMsgType = ENUM_MSG_TYPE_DEL_FILE_RESPOND;
            memcpy(respdu->caData,DEL_FILE_FAILURED,strlen(DEL_DIR_FAILURED));
        }
        write((char*)respdu,respdu->uiPDULen);
        free(respdu);
        respdu = NULL;
        break;
    }
    case ENUM_MSG_TYPE_DOWNLOAD_FILE_REQUEST:{
        char caFileName[32] = {'\0'};
        strcpy(caFileName,pdu->caData);
        char *pPath = new char[pdu->uiMsgLen];
        memcpy(pPath,pdu->caMsg,pdu->uiMsgLen);
        QString strPath = QString("%1/%2").arg(pPath).arg(caFileName);
        qDebug()<<"要传过来的路径是"<<strPath;
        delete []pPath;
        pPath = NULL;

        QFileInfo fileInfo(strPath);
        qint64 fileSize = fileInfo.size();
        PDU *respdu = mkPDU(0);
        respdu->uiMsgType = ENUM_MSG_TPYE_DOWNLOAD_FILE_RESPOND;
        sprintf(respdu->caData,"%s %11d",caFileName,fileSize);

        write((char*)respdu,respdu->uiPDULen);
        free(respdu);
        respdu = NULL;
        qDebug()<<"the file path is"<<strPath;
        m_file.setFileName(strPath);
        m_file.open(QIODevice::ReadOnly);
        m_pTimer->start(1000);

        break;
    }
    case ENUM_MSG_TYPE_SHARE_FILE_REQUEST:
    {
        char caSendName[32] = {'\0'};
        int num = 0;
        sscanf(pdu->caData,"%s%d",caSendName,&num);
        int size = num*32;
        PDU *respdu = mkPDU(pdu->uiMsgLen-size);
        respdu->uiMsgType = ENUM_MSG_TYPE_SHARE_FILE_NOTE;
        strcpy(respdu->caData,caSendName);
        memcpy(respdu->caMsg,(char*)pdu->caMsg+size,pdu->uiMsgLen-size);

        char caRecvName[32]={'\0'};
        for(int i = 0;i<num;i++){
            memcpy(caRecvName,(char*)(pdu->caMsg)+i*32,32);
            MyTcpServer::getInstance().resend(caRecvName,respdu);
        }

        free(respdu);
        respdu = NULL;

        respdu = mkPDU(0);
        respdu->uiMsgType = ENUM_MSG_TYPE_SEARCH_USER_RESPOND;
        strcpy(respdu->caData,"share file ok");
        write((char*)respdu,respdu->uiPDULen);
        free(respdu);
        respdu = NULL;

        break;
    }
    case ENUM_MSG_TYPE_SHARE_FILE_NOTE_RESPOND:{

        QString strRecvpath = QString("./%1").arg(pdu->caData);
        QString strShareFilePath = QString("%1").arg((char*)pdu->caMsg);
        int index =  strShareFilePath.lastIndexOf('/');
        QString strFileName = strShareFilePath.right(strShareFilePath.size()-index-1);
        strRecvpath = strRecvpath+'/'+strFileName;

        QFileInfo fileInfo(strShareFilePath);
        if(fileInfo.isFile()){
            QFile::copy(strShareFilePath,strRecvpath);
        }
        else if(fileInfo.isDir()){

            copyDir(strShareFilePath,strRecvpath);
        }

        break;
    }
    case ENUM_MSG_TYPE_MOVE_FILE_REQUEST:{
        char caFileName[32] = {'\0'};
        int srcLen = 0;
        int destLen = 0;
        sscanf(pdu->caData,"%d%d%s",&srcLen,&destLen,caFileName);

        char *pSrcPath = new char[srcLen+1];
        char *pDestPath = new char[destLen+1+32];
        memset(pSrcPath,'\0',srcLen+1);
        memset(pDestPath,'\0',destLen+1+32);

        memcpy(pSrcPath,pdu->caMsg,srcLen);
        memcpy(pDestPath,(char*)(pdu->caMsg)+(srcLen+1),destLen);

        PDU *respdu = mkPDU(0);
        respdu->uiMsgType = ENUM_MSG_TYPE_MOVE_FILE_RESPOND;
        QFileInfo fileInfo(pDestPath);
        qDebug()<<"pDestPath is"<<pDestPath;
        qDebug()<<"pSrcPath:"<<pSrcPath;
        if(fileInfo.isDir()){
            strcat(pDestPath,"/");
            strcat(pDestPath,caFileName);

          bool ret = QFile::rename(pSrcPath,pDestPath);
            qDebug()<<"pDestPath";
          if(ret){
                qDebug()<<"成功";
                strcpy(respdu->caData,MOVE_FILE_OK);
          }
          else{

                strcpy(respdu->caData,COMMON_ERROR);
          }
        }
        else{
          qDebug()<<"失败";
          strcpy(respdu->caData,MOVE_FILE_FAILURED);
        }

        write((char*)respdu,respdu->uiPDULen);
        free(respdu);
        respdu = NULL;
        break;
    }
    default:
        break;
    }

    // 响应客户端
   /* if(NULL != resPdu)
    {
        qDebug() << resPdu -> uiMsgType << " " << resPdu ->caData;
        this -> write((char*)resPdu, resPdu -> uiPDULen);
        // 释放空间
        free(resPdu);
        resPdu = NULL;
    }*/
    // 释放空间
    free(pdu);
    pdu = NULL;
    }
    else{
        PDU *respdu = NULL;
        QByteArray buff = readAll();
        m_file.write(buff);
        m_iRecved += buff.size();
        if(m_iTotal == m_iRecved){
            m_file.close();
            m_bUploadt = false;

            respdu = mkPDU(0);
            respdu->uiMsgType = ENUM_MSG_TYPE_UPLOAD_FILE_RESPOND;
            strcpy(respdu->caData,UPLOAD_FILE_OK);
            write((char*)respdu,respdu->uiPDULen);
            free(respdu);
            respdu = NULL;
        }
        else if(m_iTotal < m_iRecved){
            m_file.close();
            m_bUploadt = false;

            strcpy(respdu->caData,UPLOAD_FILE_FAILURED);

            write((char*)respdu,respdu->uiPDULen);
            free(respdu);
            respdu = NULL;
        }
    }
}

void MyTcpSocket::clientOffline()
{
    qDebug();
    opedb::getInstance().handleOffline(m_strName.toStdString().c_str());
    emit offline(this);
}

void MyTcpSocket::sendFileToClient()
{
    m_pTimer->stop();
    bool flag = true;
    char *pData = new char[4096];
    qint64 ret = 0;
    while(flag){
        ret = m_file.read(pData,4096);
        if(ret>0 && ret <= 4096){
            write(pData,ret);
        }
        else if(0 == ret){
            m_file.close();
            flag = false;
        }
        else if(ret<0){
            qDebug()<<"发送文件内容给客户端过程中失败";
            m_file.close();
            flag = false;
        }
    }
    delete []pData;
    pData = NULL;
}

QString MyTcpSocket::getName()
{
    return this->m_strName;
}


// 处理注册请求并返回响应PDU
PDU* handleRegistRequest(PDU* pdu)
{
    char caName[32] = {'\0'};
    char caPwd[32] = {'\0'};
    // 拷贝读取的信息
    strncpy(caName, pdu -> caData, 32);
    strncpy(caPwd, pdu -> caData + 32, 32);
    qDebug() << pdu -> uiMsgType << " " << caName << " " << caPwd;
    bool ret = opedb::getInstance().handleRegist(caName, caPwd); // 处理请求，插入数据库

    // 响应客户端
    PDU *resPdu = mkPDU(0); // 响应消息
    resPdu -> uiMsgType = ENUM_MSG_TYPE_REGIST_RESPOND;
    if(ret)
    {
        strcpy(resPdu -> caData, REGIST_OK);
    }
    else
    {
        strcpy(resPdu -> caData, REGIST_FAILED);
    }
    // qDebug() << resPdu -> uiMsgType << " " << resPdu ->caData;

    return resPdu;
}
// 同意加好友
void MyTcpSocket::handleAddFriendAgree(PDU* pdu)
{
    char addedName[32] = {'\0'};
    char sourceName[32] = {'\0'};
    // 拷贝读取的信息
    strncpy(addedName, pdu -> caData, 32);
    strncpy(sourceName, pdu -> caData + 32, 32);

    // 将新的好友关系信息写入数据库
    opedb::getInstance().handleAddFriendAgree(addedName, sourceName);

    // 服务器需要转发给发送好友请求方其被同意的消息
    MyTcpServer::getInstance().resend(sourceName, pdu);
}

// 拒绝加好友
void MyTcpSocket::handleAddFriendReject(PDU* pdu)
{
    char sourceName[32] = {'\0'};
    // 拷贝读取的信息
    strncpy(sourceName, pdu -> caData + 32, 32);
    // 服务器需要转发给发送好友请求方其被拒绝的消息
    MyTcpServer::getInstance().resend(sourceName, pdu);
}

void MyTcpSocket::copyDir(QString strSrcDir, QString strDestDir)
{
    QDir dir;
    dir.mkdir(strSrcDir);

    dir.setPath(strSrcDir);
    QFileInfoList fileInfoList =  dir.entryInfoList();
    QString srcTmp;
    QString destTmp;
    for(int i = 0;i<fileInfoList.size();i++){
        qDebug()<<"fileName:"<<fileInfoList[i].fileName();
        if(fileInfoList[i].isFile()){

            srcTmp = strSrcDir+'/'+fileInfoList[i].fileName();
            destTmp = strDestDir+'/'+fileInfoList[i].fileName();
            QFile::copy(srcTmp,destTmp);
        }
        else if(fileInfoList[i].isDir()){

            if(QString(".")==fileInfoList[i].fileName()||
                QString("..") == fileInfoList[i].fileName()){
            continue;
            }

            srcTmp = strSrcDir+'/'+fileInfoList[i].fileName();
            destTmp = strDestDir+'/'+fileInfoList[i].fileName();
            QFile::copy(srcTmp,destTmp);
        }
   }
}
