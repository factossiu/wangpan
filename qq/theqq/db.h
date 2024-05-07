#ifndef DB_H
#define DB_H

#include <QObject>
#include <Qtsql/QSqlQuery>
#include<Qtsql/QSqlRecord>
#include <iostream>
#include<Qtsql/QSqlError>
#include<Qtsql/QSqlDatabase>
class db
{
public:
    //db();
    void conndata(); //连接数据库
    bool queryuser(QString user,QString password); //查询是否有该账户
    QString geticonurl(QString url);//根据地址网上下载图片
   // QPixmap getPixmapIcon(QString url);//url为账号，通过账号获取头像地址

    QSqlDatabase db1;//连接数据库
    QSqlQuery query;   //查询操作
    QString account;   //账号
    QString passwd;    //密码
    QString iconurl;   //地址
    QString icon;      //头像
};

#endif // DB_H
