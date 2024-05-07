#ifndef INDEX_H
#define INDEX_H
#include<QPoint>
#include<QMouseEvent>
#include <QWidget>
#include"usersql.h"
#include<QVBoxLayout>
#include<QPushButton>
#include<QListWidget>
#include"chatroom.h"
namespace Ui {
class index;
}

class index : public QWidget
{
    Q_OBJECT

public:

    void init(int index);//用于初始化头像
    QString getUser();
    void setUser(QString account);

    explicit index(QWidget *parent = nullptr);
    //连接数据库
    ~index();

private:
    QString account;
    Ui::index *ui;
    usersql user;
    bool isPressedWidget;
    QPoint last;
    QList<QPushButton *> listbtn;   //分组名
    QList<QListWidget *> listwidget; //分组列表
    QList<bool> iswidget; //判断是否展开
     //保存当前登录的用户名；
    //QList<Chat *> listchat;     //保存聊天窗口
    QMenu *menuUser;
    bool doubleClidked = false;
    void mousePressEvent(QMouseEvent *event);//鼠标点击
    void mouseMoveEvent(QMouseEvent *event);//鼠标移动
    void mouseReleaseEvent(QMouseEvent *event);//鼠标释放
   // void mouseDoubleClickEvent(QMouseEvent *event);//鼠标双击
    bool eventFilter(QObject *watched, QEvent *event); //重写事件过滤器实现双击事件
signals:
    void doubleClicked();
private slots:
    void onButtonClicked(bool tt);
    void onDoubleWidgetClicked(QListWidgetItem* item);
    void on_pushButton_2_released();
};

#endif // INDEX_H
