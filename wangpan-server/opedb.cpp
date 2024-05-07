#include "opedb.h"
#include<QMessageBox>
#include<QSqlError>
opedb::opedb(QObject *parent)
    : QObject{parent}
{
   db = QSqlDatabase::addDatabase("QSQLITE");
   // init();
}

void opedb::init()
{
    db.setHostName("localhost");
    db.setDatabaseName("E:/school/project/wangpan-server/mysql.db");
    if(db.open()){
        QSqlQuery query;
        query.exec("select * from usrInfo");
        while(query.next()){
           QString data = QString("%1 %2 %3").arg(query.value(0).toString()).arg(query.value(1).toString()).arg(query.value(2).toString());
            qDebug()<<data;

        }
    }
    else{
        QMessageBox::critical(NULL,"打开数据库","数据库打开失败");
    }
}
opedb &opedb::getInstance(){
    static opedb instance;
    return instance;
}

bool opedb::handleRegist(const char *name, const char *pwd)
{
    // 考虑极端情况
    if(NULL == name || NULL == pwd)
    {   qDebug()<<"name | pwd is null";
        return false;
    }
    // 数据插入数据库
      QString strQuery = QString("insert into usrInfo(name, pwd) values('%1', '%2')").arg(name).arg(pwd);
    QSqlQuery query;
    query.prepare(strQuery);
    query.bindValue(":name", name);
    query.bindValue(":pwd", pwd);
    if(query.exec(strQuery)) {
        qDebug() << "Insert operation successful";
        return true;
    } else {
        if(query.lastError().type() == QSqlError::NoError) {
            qDebug() << "Insert operation successful";
            return true;
        } else if(query.lastError().text().contains("UNIQUE constraint failed")) {
            qDebug() << "Insert operation failed: Unique constraint violation";
            return false;
        } else {
            qDebug() << "Insert operation failed:" << query.lastError().text();
            return false;
        }
    }

}
bool opedb::handleLogin(const char *name, const char *pwd)
{
    if(name == nullptr || pwd == nullptr)
    {
        return false;
    }
    QSqlQuery query;
    query.prepare("select * from usrInfo where name = :name and pwd = :pwd and online = 0");
    query.bindValue(":name", name);
    query.bindValue(":pwd", pwd);

    if(query.exec() && query.next())
    {
        query.prepare("update usrInfo set online = 1 where name = :name and pwd = :pwd");
        query.bindValue(":name", name);
        query.bindValue(":pwd", pwd);

        if(query.exec())
        {
            return true;
        }
    }

    return false;
}

QStringList opedb::handleAllOnline()
{
    QString data = QString("select name from usrInfo where online = 1");

    QSqlQuery query;
    query.exec(data);
    QStringList result;
    result.clear();

    while(query.next()){
    result.append(query.value(0).toString());
    }
    return result;
}


void opedb::handleOffline(const char *name)
{
    if(name == NULL)
    {
        qDebug() << "name is NULL";
        return;
    }
    // 更新online状态为0
    QSqlQuery query;
    query.prepare("update usrInfo set online = 0 where name = :name");
    query.bindValue(":name", name);
    if(query.exec())
    {
    }
    else
    {
        qDebug() << "Failed to update online status for user " << name;
        qDebug() << "Error: " << query.lastError().text();
    }
}

int opedb::handleSearchUser(const char *name)
{
    if(NULL == name)
    {
        return -1;
    }
    QString strQuery = QString("select online from usrInfo where name = \'%1\' ").arg(name);
    QSqlQuery query;

    query.exec(strQuery);
    if(query.next())
    {
        return query.value(0).toInt(); // 存在并在线返回1，存在不在线返回0
    }
    else
    {
        return -1; // 不存在该用户
    }
}
// 0对方存在不在线，1对方存在在线，2不存在，3已是好友，4请求错误
int opedb::handleAddFriend(const char *addedName, const char *sourceName)
{
    if(NULL == addedName || NULL == sourceName)
    {
        return 4; // 请求错误
    }
    QString strQuery = QString("select * from friend "
                               "where (id = (select id from usrInfo where name = \'%1\') and "
                               "friendId = (select id from usrInfo where name = \'%2\')) or "  // 好友是双向的，数据库只存了单向，注意是or关系
                               "(id = (select id from usrInfo where name = \'%3\') and "
                               "friendId = (select id from usrInfo where name = \'%4\'))")
                           .arg(sourceName).arg(addedName).arg(addedName).arg(sourceName);
    //qDebug() << strQuery;
    QSqlQuery query;
    query.exec(strQuery);
    if(query.next())
    {
        return 3; // 双方已经是好友
    }
    else // 不是好友
    {// 查询对方，存在并在线返回1，存在不在线返回0，不存在该用户返回2
        if(NULL == addedName)
        {
            return 2;
        }

        QString strQuery = QString("select online from usrInfo where name = \'%1\' ").arg(addedName);
        QSqlQuery query;

        query.exec(strQuery);
        if(query.next())
        {
           int a = query.value(0).toInt();
            return a; // 存在并在线返回1，存在不在线返回0
        }
        else
        {
            return 2; // 不存在该用户
        }
    }
}
int opedb::getIdByUserName(const char *name)
{
    if(NULL == name)
    {
        return -1;
    }
    QString strQuery = QString("select id from usrInfo where name = \'%1\' ").arg(name);
    QSqlQuery query;

    query.exec(strQuery);
    if(query.next())
    {
        return query.value(0).toInt();
    }
    else
    {
        return -1; // 不存在该用户
    }
}

QStringList opedb::handleFlushFriend(const char *name)
{
    QStringList strFriendList;
    strFriendList.clear();
    if(NULL==name){
        return strFriendList;
    }
    QString data = QString(""
    "select name from usrInfo where online = 1 "
    " and id = (select id from friend where "
    "friendId = (select id from usrInfo "
    "where name = \'%1\'))").arg(name);
    QSqlQuery query;
    query.exec(data);
    while(query.next()){
        strFriendList.append(query.value(0).toString());
        qDebug()<<query.value(0).toString();
    }
    return strFriendList;

    query.clear();
    data = QString(""
                   "select name from usrInfo where online = 1 "
                   " and id = (select friendId from friend where "
                   "id = (select id from usrInfo "
                   "where name = \'%1\'))").arg(name);
    query.exec(data);
    while(query.next()){
        strFriendList.append(query.value(0).toString());
        qDebug()<<query.value(0).toString();
    }

}

bool opedb::handleDelFriend(const char *deletedName, const char *sourceName)
{
    if(deletedName == NULL || sourceName == NULL)
    {
        return false;
    }

    // 先查出来deletedName和sourceName对应的id
    int iDelId = -1;
    int iSouId = -1;
    QString strQuery = QString("select id from usrInfo where name in (\'%1\', \'%2\') ").arg(deletedName).arg(sourceName);
    QSqlQuery query;

    query.exec(strQuery);
    if(query.next())
    {
        iDelId = query.value(0).toInt();
    }
    if(query.next())
    {
        iSouId = query.value(0).toInt();
    }

    // 删除好友信息表中两个id之间的好友关系
    strQuery = QString("delete from friend where id in (\'%1\', \'%2\') and friendId in (\'%3\', \'%4\') ")
                   .arg(iDelId).arg(iSouId).arg(iDelId).arg(iSouId);

    qDebug() << strQuery;
    return query.exec(strQuery);
}
bool opedb::handleAddFriendAgree(const char *addedName, const char *sourceName)
{
    if(NULL == addedName || NULL == sourceName)
    {
        qDebug() << "handleAddFriendAgree: name is NULL";
        return false;
    }

    int sourceUserId = -1, addedUserId = -1;
    // 查找用户对应id
    addedUserId = getIdByUserName(addedName);
    sourceUserId = getIdByUserName(sourceName);

    QString strQuery = QString("insert into friend values(%1, %2) ").arg(sourceUserId).arg(addedUserId);
    QSqlQuery query;
    QString strQuery1 = QString("insert into friend values(%1, %2) ").arg(addedUserId).arg(sourceUserId);
    return query.exec(strQuery)&&query.exec(strQuery1) ;
}

opedb::~opedb(){

}
