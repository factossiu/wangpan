#ifndef USERSQL_H
#define USERSQL_H
#include "user.h"
#include <QObject>
#include <QWidget>
#include<Qtsql/QSqlDatabase>
#include <Qtsql/QSqlRecord>
#include <Qtsql/QSqlQuery>
#include <QList>
#include "group.h"
class usersql: public QWidget
{
    Q_OBJECT
public:
    int i = 1;
    usersql();
    QSqlDatabase db;
    void conndata();
    QList<user> *user1 = new QList<user>();
    QList<group> *grp = new QList<group>();
    ~usersql();
    void selectAll();
    void selectGroup();
    QString findByid(int id);
    void chageId(QString account);
    void chageId1(QString account);
private:
     //QSqlDatabase dbconn;//连接数据库
     //QSqlQuery query;   //查询操作
    /* QString account;   //账号
     QString passwd;    //密码
     QString iconurl;   //地址
     QString icon;*/
};

#endif // USERSQL_H
