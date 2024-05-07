#include "usersql.h"
#include<QSqlError>
usersql::usersql()
{
   // user1 = nullptr;

   // usersql::selectAll();
}
usersql::~usersql(){
    delete user1;
}
void usersql::selectAll(){

    QSqlQuery query("select * from user");
    //query = QSqlQuery::QSqlQuery(db);
    QSqlRecord rec;

    while(query.next()){
        rec = query.record();
        int index1 = rec.indexOf("account");
        QString account = query.value(index1).toString();
       // qDebug() << "account:"<<account;
        int index2 = rec.indexOf("password");
        QString password = query.value(index2).toString();
        int index3 = rec.indexOf("icon");
        QString icon = query.value(index3).toString();
        int index4 = rec.indexOf("sign");
        QString sign = query.value(index4).toString();
        int index5 =rec.indexOf("lv");
        QString lv = query.value(index5).toString();
        int index6 = rec.indexOf("group");
        int group = query.value(index6).toInt();
        int index7 = rec.indexOf("id");
        int id= query.value(index7).toInt();
        user newUser;
        newUser.setAccount(account);
        newUser.setPassword(password);
        newUser.setIcon(icon);
        newUser.setSign(sign);
        newUser.setLv(lv);
        newUser.setGroup(group);
        newUser.setId(id);
        user1->append(newUser);
    }
}
void usersql::conndata(){

    db = QSqlDatabase::addDatabase("QMYSQL");

    db.setHostName("127.0.0.1"); // 连接本地主机
    db.setPort(3306); // 确保这是您的 MySQL 服务器端口
   // db.setDatabaseName("mysql"); // ODBC 数据源名称
    db.setUserName("root");
    db.setPassword("root");

    if (!db.open()) {
        qDebug() << "Database error:" << db.lastError().text();
        // 在这里处理错误，可能包括退出应用程序或显示错误信息
} else {
        qDebug() << "Database opened successfully";
        // 在这里执行您的 SQL 查询等操作
}
    /*if(db.open()){
        qDebug()<<"success";
    }*/

}
QString usersql::findByid(int id){
    QString sql = QString("select * from user where id = :id");
    QSqlQuery query(sql);
    QString account;
    query.prepare(sql);
    query.bindValue(":id",id);
    if(query.exec()){
        if(query.next()){
            account = query.value(0).toString();
        }else{
            qDebug()<<"查询为空";
        }

    }
    else{
        qDebug()<<"查询失败";
    }
    return account;
}
void usersql::chageId(QString account){
    QString updateQuery = QString("update user set id = :Id  where account = :account");
    QSqlQuery query(updateQuery);
    query.prepare(updateQuery);
    query.bindValue(":account",account);
    query.bindValue(":Id",this->i);
    if(query.exec()){
    }
    else{
        qDebug()<<query.lastError().text();
    }
    (this->i)++;
}
void usersql::chageId1(QString account){
    QString updateQuery = QString("update user set id = 0 where account = :account");
    QSqlQuery query(updateQuery);
    query.prepare(updateQuery);
    query.bindValue(":account",account);
    if(query.exec()){
        qDebug()<<"id = 0 炒作成功";
    }
    else{
        qDebug()<<query.lastError().text();
    }
}
void usersql::selectGroup(){
    QSqlQuery query1("select * from grp");
    QSqlRecord rec;

    while(query1.next()){
        rec = query1.record();
        int index1 = rec.indexOf("id");
        int group1 = query1.value(index1).toInt();
        int index2 = rec.indexOf("name");
        QString name = query1.value(index2).toString();
        group newGroup;
        newGroup.setGroup(group1);
        newGroup.setName(name);
        grp->append(newGroup);
    }
}
