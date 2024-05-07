#include "mytcpserver.h"

void MyTcpServer::deleteSocket(MyTcpSocket *tcpSocket)
{
    QList<MyTcpSocket*>::iterator iter = m_tcpSocketList.begin();
    for(;iter!=m_tcpSocketList.end();iter++){
        if(tcpSocket == *iter){
            (*iter)->deleteLater();
            *iter = NULL;
            m_tcpSocketList.erase(iter);
            qDebug()<<"删除socket成功";
            break;
        }
    }
    for(int i = 0;i<m_tcpSocketList.size();i++){
        QString tmp = m_tcpSocketList.at(i)->getName();
        qDebug()<<tmp;
    }
}

MyTcpServer::MyTcpServer(QObject *parent)
    : QTcpServer{parent}
{

}

MyTcpServer &MyTcpServer::getInstance()
{
    static MyTcpServer instance;
    return instance;
}

void MyTcpServer::incomingConnection(qintptr socketDescriptor)
{
    qDebug()<<"有客户端正在连接";

    MyTcpSocket *pTcpSocket = new MyTcpSocket;
    pTcpSocket->setSocketDescriptor(socketDescriptor);
    m_tcpSocketList.append(pTcpSocket);
    connect(pTcpSocket,SIGNAL(offline(MyTcpSocket*)),this,SLOT(deleteSocket(MyTcpSocket*)));
}

void MyTcpServer::resend(const char *perName, PDU *pdu)
{
    if(perName ==NULL || pdu == NULL){
        return;
    }
    QString strName = perName;
    for(int i = 0;i<m_tcpSocketList.size();i++){
        if(strName == m_tcpSocketList.at(i)->getName()){
            m_tcpSocketList.at(i)->write((char*)pdu,pdu->uiPDULen);
            break;
        }
    }
}
