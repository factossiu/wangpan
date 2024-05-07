#ifndef OPEDB_H
#define OPEDB_H

#include <QObject>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QStringList>
class opedb : public QObject
{
    Q_OBJECT
public:
    explicit opedb(QObject *parent = nullptr);
    void init();
    static opedb& getInstance();
    ~opedb();
    bool handleRegist(const char *name,const char * pwd);
    bool handleLogin(const char *name,const char * pwd);
    QStringList handleAllOnline();
    void handleOffline(const char *name);
    int handleSearchUser(const char *name);
    int handleAddFriend(const char *perName,const char * name);
    bool handleAddFriendAgree(const char *addedName, const char *sourceName);
    int getIdByUserName(const char *name);
    QStringList handleFlushFriend(const char *name);
    bool handleDelFriend(const char*myName,const char *friendName);
signals:
private:

    QSqlDatabase db;
};

#endif // OPEDB_H
