#include "widget.h"
#include "./ui_widget.h"
#include<QMovie>
#include"usersql.h"
#include<QListWidget>
#include<QMessageBox>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget),label(new QLabel)
{
    /*启动数据库*/
    u.conndata();
    u.selectAll();

    //实例化新引入的ui
    //index = new Ui::index;

    //去掉边框
    setWindowFlags(Qt::WindowType::FramelessWindowHint);
    label->setGeometry(500,250,200,50);
    //背景透明
    setAttribute(Qt::WA_TranslucentBackground);
    ui->setupUi(this);

    //给laptop设置动画
    QMovie * movie = new QMovie(this);
    movie->setFileName(":/images/blue70-2.gif");
    movie->start();
    ui->labtop->setMovie(movie);

    //ui->comboBox->lineEdit()->setPlaceholderText("QQ号码/邮箱/手机");
    //把头像设置为圆形
    //ui->lab->setMask(QRegion(ui->lab->rect(),QRegion::RegionType::Ellipse));

    /*托盘设计*/
    //初始化系统托盘
    systemtrayicon = new QSystemTrayIcon(this);
    QIcon icon = QIcon(":/images/1.jpg");
    //添加图标
    systemtrayicon->setIcon(icon);
    //当鼠标悬浮，显示文字
    systemtrayicon->setToolTip(QString("Fdog").toUtf8());
    //显示图标
    systemtrayicon->show();
    //对托盘添加右击操作
    menu = new QMenu(this);
    m_pShowAction = new QAction("打开主界面");
    m_pCloseAction = new QAction("退出");
    menu->addAction(m_pShowAction);
    menu->addSeparator();
    menu->addAction(m_pCloseAction);
    systemtrayicon->setContextMenu(menu);
    connect(m_pShowAction,SIGNAL(triggered(bool)),this,SLOT(showwidget()));
    connect(m_pCloseAction,SIGNAL(triggered(bool)),this,SLOT(closewidget()));

    //初始化列表

    ui->btnLogin->setShortcut(Qt::Key_Return);//对应键盘上面大的回车键
    Widget::listShow();
}
void Widget::mousePressEvent(QMouseEvent *event)
{
    isPressedWidget = true; // 当前鼠标按下的即是QWidget而非界面上布局的其它控件
    last = event->globalPos();
}

void Widget::mouseMoveEvent(QMouseEvent *event)
{
    if (isPressedWidget)
    {
        int dx = event->globalX() - last.x();
        int dy = event->globalY() - last.y();
        last = event->globalPos();
        move(x()+dx, y()+dy);
    }
}

void Widget::mouseReleaseEvent(QMouseEvent *event)
{
    int dx = event->globalX() - last.x();
    int dy = event->globalY() - last.y();
    move(x()+dx, y()+dy);
    isPressedWidget = false; // 鼠标松开时，置为false
}

Widget::~Widget()
{
    delete ui;

}

void Widget::listShow(){
    /*调用数据库*/
  /*  usersql u;
    u.conndata();
    u.selectAll();
    u.user1;

    qDebug()<<":"<<u.user1->at(0).account;*/

    QListWidget * m_AccountList;
    m_AccountList = new QListWidget(this);
    ui->comboBox->setModel(m_AccountList->model());
    ui->comboBox->setView(m_AccountList);


    for(int i = 0 ;i<u.user1->length();i++){
        QHBoxLayout *horlayout = new QHBoxLayout();
        QLabel *icon = new QLabel();
        icon->setFixedSize(34,34);
        QLabel *account = new QLabel();
        QString account1 = u.user1->at(i).account;
        QString url = u.user1->at(i).icon;
        icon->setStyleSheet(QString("border-image:url(%1);border-radius:17px").arg(url));
        account->setText(QString("%1").arg(account1));
        QPushButton *b1 = new QPushButton();
        b1->setIcon(QIcon(":/images/delete.png"));
        b1->setStyleSheet("background:rgba(200,200,200,0);border-style:solid;");
        horlayout->addWidget(icon);
        horlayout->addWidget(account);
        horlayout->addWidget(b1);
        //connect(b1,SIGNAL(clicked()),this,SLOT(deleteaccount(int)));

        QWidget *widget = new QWidget();
        widget->setLayout(horlayout);
        QListWidgetItem *Listitem = new QListWidgetItem(m_AccountList);
        Listitem->setSizeHint(widget->sizeHint());
        m_AccountList->addItem(Listitem);
        m_AccountList->setItemWidget(Listitem,widget);
    }

}
void Widget::on_btnLogin_clicked()
{
    /*usersql u;
    u.conndata();
    u.selectAll();
    u.user1;*/

    QString user = ui->account->text();
    QString pwd = ui->password->text();
    for(int i = 0;i<u.user1->length();i++){
        if(user == "" && pwd == ""){
            qDebug()<<"为空";
            label->setText("输入为空，无法登录");
            this->window()->close();
            label->show();
        }
        if(user == u.user1->at(i).account){
            if(pwd == u.user1->at(i).password){
                qDebug()<<"密码正确"+user+"登录成功";
                this->window()->close();
                //引入ui文件类
                index *index1 = new index();
                index1->init(i);//对登入的账号进行初始化
                index1->show();
            }
            else{qDebug()<<"pwd is error";}
        }
    }

 /*   if(user == "123" && pwd == ""){
        qDebug()<<"密码正确"+user+"登录成功";
        this->window()->close();
        //引入ui文件类
        index *index1 = new index();
        index1->show();
    }
    if(user == "" && pwd == ""){
        qDebug()<<"为空";
        label->setText("输入为空，无法登录");
        this->window()->close();
        label->show();
    }*/
}
void Widget::showwidget()
{
    this->showNormal();
}

void Widget::closewidget()
{
    this->close();
}
void Widget::deleteaccount(int i) //传进来的是标记数字
{
    //QMessageBox::information(NULL, "提示", "是否要删除本次该账号信息",QMessageBox::Yes|QMessageBox::No);
    QMessageBox *message =
        new QMessageBox(QMessageBox::Question,tr("提示"), tr("是否要删除该账号信息"), QMessageBox::Yes
    | QMessageBox::No,this);
    int result = message->exec();
    //infoListsign  0 1 2 3  0 1 2 3  0 1 2  1 2 3
    //这里有一个需要注意的点，当初给每个按钮标记的数字是不会变的，但是当我们删除列表中的一个item之后，列表中的其他item会自动排序
    //所以无法单靠当初标记的数字来进行简单删除，我们可以借助一个vector，将标记的数字存放，而正在要删除的值是标记数字的下标
    //如果单靠标记的数字来判断，比如我要删除第一行，就是0，这时它的下标也是0，这没有问题，但是第二次就会出问题，我要删除第二行，当我点击删除
    //其实传回的值应该是1，但是列表自动排序之后，原来的1变成了0，原来的2变了1.
    switch(result)
    {
    case QMessageBox::Yes:
     /*直接从数据库中删除*/


    case QMessageBox::No:
        //什么也不做
    break;
    }
}

void Widget::on_comboBox_currentIndexChanged(int index)
{
    //ui->checkBox_2->setChecked(false);
    ui->password->setText("");
    ui->account->setText(u.user1->at(index).account);
    if(u.user1->at(index).password!="")
    {
    ui->password->setText(u.user1->at(index).password);
    ui->checkBox_2->setChecked(true);
    }
    QString icon1 = u.user1->at(index).icon;
    ui->lab->setStyleSheet(QString("border-image: url(%1);border-width:0px;border-style:solid;border-color: rgb(255, 255, 255);border-radius:33px;").arg(icon1));
}

