#include "index.h"
#include "ui_index.h"
index::index(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::index)
{

   ui->setupUi(this);
   // setWindowFlags(Qt::WindowType::FramelessWindowHint);
    //消除边框
   setWindowFlags(Qt::CustomizeWindowHint);
   //ui->label->setMask(QRegion(ui->label->rect(),QRegion::RegionType::Ellipse));
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    /*启动数据库*/
    //user.conndata();
    user.selectAll();
    user.selectGroup();
    /*初始化分组*/
    QVBoxLayout * layout1 = new QVBoxLayout();
    //设置边距为0
    layout1->setContentsMargins(0,0,0,0);
    layout1->setSpacing(0);
     //获取分组信息，以及好友列表

    //
    for(int i = 0 ; i<user.grp->length();i++){
        QPushButton * btn = new QPushButton(QIcon(":/images/jietou.png")," "+user.grp->at(i).name);//添加箭头图标和分组名

        connect(btn,SIGNAL(clicked(bool)),this,SLOT(onButtonClicked(bool)));

        this->listbtn.append(btn);
        this->iswidget.append(true);
        btn->setFixedSize(312,38);
        QSize btnsize(36,36);
        btn->setIconSize(btnsize);
        btn->setStyleSheet("QPushButton{text-align: left;background-color: rgba(203, 203, 203,200);border-style:solid;}"
                           "QPushButton:hover{text-align: left;background-color: rgb(193, 193, 193);border-style:solid;}");


        //加入分组信息
        layout1->addWidget(btn);
        QListWidget * listwidget = new QListWidget(this);
        connect(listwidget,SIGNAL(itemDoubleClicked(QListWidgetItem*)),this,SLOT(onDoubleWidgetClicked(QListWidgetItem*)));
        this->listwidget.append(listwidget);
        listwidget->setFrameShape(QListWidget::NoFrame);
        listwidget->setGridSize(QSize(312,50));
        layout1->addWidget(listwidget);
        ui->widget_2->setLayout(layout1);
         int sum = -1;
       for(int j = 0;j<user.user1->length();j++){
            if(user.user1->at(j).group == user.grp->at(i).group1){
               sum++;
               QHBoxLayout *horLayout = new QHBoxLayout();//水平布局
               horLayout->setContentsMargins(0, 0, 0, 0);
               horLayout->setSpacing(0);
               QLabel *l1 = new QLabel();
               l1->setFixedSize(15, 32);
               QPushButton *btnicon = new QPushButton();
               btnicon->setFixedSize(32, 32);
               btnicon->setIconSize(QSize(32, 32));
               btnicon->setIcon(QIcon(user.user1->at(j).icon));
               btnicon->setStyleSheet("background:rgba(0,0,0,0);border-radius:15px;");
               /*QLabel *la2 = new QLabel(QString("%1").arg(mf.mid(1)));
               la2->setObjectName("label2");
               la2->hide();*/
               QLabel *la3 = new QLabel(QString(" %1").arg(user.user1->at(j).account));
               la3->setObjectName("lab3el3");
               //la3->setFont(Globalobserver::font2);
                horLayout->addWidget(l1);
                horLayout->addWidget(btnicon);
                horLayout->addWidget(la3);
                QWidget *widget =new QWidget(this);
                widget->setLayout(horLayout);
                widget->setStyleSheet("background:rgba(232, 255, 149,0);");
                QListWidgetItem * Listitem = new QListWidgetItem(listwidget);
                Listitem->setSizeHint(QSize(312, 50));  //每次改变Item的高度
                listwidget->setItemWidget(Listitem,widget);
                listwidget->setFixedSize(312,50*(sum+1));
                listwidget->setStyleSheet("QListWidget::Item{background-color: rgba(203, 203, 203,200);}"
                                          "QListWidget::Item:hover{background-color: rgb(193, 193, 193);}"
                                          "QListWidget::Item:selected{background-color: rgb(193, 193, 193);}"
                                          "QListWidget{outline:0px;}");
        }
    }
       //btn->setText(grouping.at(j)+"     "+QString::number(sum+1)+"/"+QString::number(sum+1));
       layout1->addWidget(listwidget);
       //listwidget->setObjectName();
    }
    layout1->addStretch();
    ui->scrollAreaWidgetContents->setLayout(layout1);
    ui->toolButton_2->setIcon(QIcon(":/images/myicon_1.png"));
    ui->toolButton_2->setText("相亲相爱一家人");
    ui->toolButton_2->setIconSize(QSize(100,100));
    ui->toolButton_2->setStyleSheet("font-size:15px;border:1px solid gray");
    ui->toolButton_2->setAutoRaise(true);
    ui->toolButton_2->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    ui->toolButton_2->installEventFilter(this);

}
void index::init(int index1){
    setUser(user.user1->at(index1).account);
    user.chageId(user.user1->at(index1).account);
    ui->label->setStyleSheet(QString("border-image:url(%1);border-radius:30px;border-width:0px;border-style:solid").arg(user.user1->at(index1).icon));
    ui->username->setText(QString("%1").arg(user.user1->at(index1).account));
    ui->sign->setText(QString("%1").arg(user.user1->at(index1).sign));

}
void index::mousePressEvent(QMouseEvent *event)
{
    /*isPressedWidget = true; // 当前鼠标按下的即是QWidget而非界面上布局的其它控件
    last = event->globalPos();*/
}

void index::mouseMoveEvent(QMouseEvent *event)
{
   /* if (isPressedWidget)
    {
        int dx = event->globalX() - last.x();
        int dy = event->globalY() - last.y();
        last = event->globalPos();
        move(x()+dx, y()+dy);
    }*/
}

void index::mouseReleaseEvent(QMouseEvent *event)
{
   /* int dx = event->globalX() - last.x();
    int dy = event->globalY() - last.y();
    move(x()+dx, y()+dy);
    isPressedWidget = false; // 鼠标松开时，置为false*/
}
void index::onDoubleWidgetClicked(QListWidgetItem * witem)
{

}
void index::onButtonClicked(bool tt){

}


bool index::eventFilter(QObject *watched, QEvent * event)
{
    if(event->type()==QEvent::MouseButtonDblClick)
    {
        QMouseEvent * e = static_cast<QMouseEvent *>(event);

        if(e->button() == Qt::LeftButton)
        {
        if(watched==ui->toolButton_2){
                QLabel *l1 = new QLabel();
                chatRoom *room = new chatRoom();
                room->show();
        }
        return true;
        }
    }

    return QWidget::eventFilter(watched, event);
}
index::~index()
{


    delete menuUser;
    delete ui;
}
QString index::getUser(){
    return this->account;
}
void index::setUser(QString account){
    this->account = account;
}

void index::on_pushButton_2_released()
{
    user.chageId1(this->account);
}

