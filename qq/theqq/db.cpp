#include "db.h"

/*db::db()
{
    qDebug()<<"asfd";
}*/
void db::conndata(){
    //ui->setupUi(this);
    QSqlDatabase db1 = QSqlDatabase::addDatabase("QODBC");

    db1.setHostName("127.0.0.1"); //连接本地主机

    db1.setPort(3306);

    db1.setDatabaseName("mysql1"); //odbc驱动程序中所设置的数据源的名字

    db1.setUserName("root");

    db1.setPassword("root");
   // db.open();
    if(db1.open()){
        qDebug()<<"jaiusf";
    }

}
QString db::geticonurl(QString url){

}
bool db::queryuser(QString user, QString password)
{

}
