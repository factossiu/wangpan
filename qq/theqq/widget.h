#ifndef WIDGET_H
#define WIDGET_H
#include "index.h"
#include <QWidget>
#include<QLabel>
#include<QPoint>
#include<QMouseEvent>
#include<QSystemTrayIcon>
#include<QMenu>
#include"user.h"
#include"usersql.h"
#include "index.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
class index;
class Usersql;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_btnLogin_clicked();
    void showwidget();
    void closewidget();
    void deleteaccount(int i);
    void on_comboBox_currentIndexChanged(int index);
private:

    Ui::Widget *ui;
    QLabel *label;
    bool isPressedWidget;
    QPoint last;
    void mousePressEvent(QMouseEvent *event);//鼠标点击
    void mouseMoveEvent(QMouseEvent *event);//鼠标移动
    void mouseReleaseEvent(QMouseEvent *event);//鼠标释放
    void listShow();
    QSystemTrayIcon  * systemtrayicon;  //系统托盘
    QMenu * menu;
    QAction *m_pShowAction;
    QAction *m_pCloseAction;
    usersql u;
};
#endif // WIDGET_H
