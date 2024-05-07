#ifndef CHATROOM_H
#define CHATROOM_H
#include "index.h"
#include <QWidget>
#include <QUdpSocket>
#include "widget.h"
#include "usersql.h"
namespace Ui {
class chatRoom;
}
class chatRoom : public QWidget{
    Q_OBJECT

public:
    QVBoxLayout *layout;//用于显示用户在线的情况
    QWidget *newWidget;//用于显示用户在线的情况
    usersql *user;
    quint16 port;
    QString uName;
    QUdpSocket *udpSocket;
    enum Msgtype{Msg,UserEnter,UserLeft};//枚举 分别代表普通信息 用户进入 用户离开
    QList<QString> *usernameList;
    void sndMsg(Msgtype type);
    QString getName();
    QString getMsg();
    void userEnter(QString username);
    void userLeft(QString username,QString time);
    void ReceiveMessage();
    explicit chatRoom(QWidget *parent = nullptr);
    void updateUserTab(int i);
    ~chatRoom();

private:
    Ui::chatRoom *ui;

signals:
    void closeWidget();
public:
    void closeEvent(QCloseEvent *);
};

#endif // CHATROOM_H
