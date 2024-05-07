#ifndef USER_H
#define USER_H

#include <QWidget>
class user
{
public:
    user();
    //user(QString account,QString password,QString icon);
    QString getAccount();
    QString getPassword();
    QString getIcon();
    QString getSign();
    QString getLv();
    int getGroup();
    int getId();
    void setId(int id);
    void setAccount(QString account);
    void setPassword(QString password);
    void setIcon(QString icon);
    void setSign(QString sign);
    void setLv(QString Lv);
    void setGroup(int group);
    QString account;
    QString password;
    QString icon;
    QString sign;
    QString lv;
    int group;
    int id;
};

#endif // USER_H
