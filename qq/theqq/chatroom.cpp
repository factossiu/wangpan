#include "chatroom.h"
#include "ui_chatroom.h"
#include<QIODevice>
#include<QMessageBox>
#include<QDataStream>
#include<QDateTime>
#include<QTableWidgetItem>
#include "index.h"
chatRoom::chatRoom(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::chatRoom)
{
    ui->setupUi(this);
    user = new usersql();
    user->selectAll();
    usernameList = new QList<QString>();
    for(int i = 0 ;i<user->user1->length();i++){
        if(user->user1->at(i).id == 1){
            usernameList->append(user->user1->at(i).account);

        }
    }
    usernameList->append("李老八");
   uName =   user->findByid(1);
    this->port = 9999;
    this->udpSocket = new QUdpSocket(this);

    udpSocket->bind(port,QUdpSocket::ShareAddress | QUdpSocket::ReuseAddressHint);

    connect(udpSocket,&QUdpSocket::readyRead,this,&chatRoom::ReceiveMessage);
    //连接发送按钮

    connect(ui->pushButton_3,&QPushButton::clicked,[=](){
        sndMsg(Msg);
    });
    layout = new QVBoxLayout();
    newWidget = new QWidget();
    layout->setContentsMargins(0,0,0,0);
    layout->setSpacing(0);
    for(int i = 0 ;i<usernameList->length() ;i++){
        updateUserTab(i);
    }

}

chatRoom::~chatRoom()
{
    delete layout;
    delete newWidget;
    delete usernameList;
    delete ui;

    //delete chatRoom;
}
QString chatRoom::getName(){
    return uName;

}
QString chatRoom::getMsg(){
    QString msg = ui->lineEdit_2->text();
    ui->lineEdit_2->clear();
    ui->lineEdit_2->setFocus();//设置光标
    return msg;
}
void chatRoom::userEnter(QString username){
    /*QWidget *widget = ui->tabWidget->findChild<QWidget *>(username, Qt::FindChildOptions(Qt::FindChildOption::FindChildrenRecursively));
    bool IsEmpty = (widget == nullptr);


    if(IsEmpty){
        QTableWidgetItem *tabel = new QTableWidgetItem(username);
        QWidget *newWidget = new QWidget; // 创建一个新的 QWidget
        ui->tabWidget->insertTab(0,newWidget, username); // 在索引位置0插入新的小部件，并设置选项卡标题为"Tab Title"

        ui->textBrowser->setTextColor(QColor(Qt::gray));
        ui->label_2->setText(QString("在线人数：%1").arg(ui->tabWidget->count()));
        sndMsg(UserEnter);
    }*/
}
void chatRoom::userLeft(QString username, QString time){
    /*QWidget *widget = ui->tabWidget->findChild<QWidget *>(username, Qt::FindChildOptions(Qt::FindChildOption::FindChildrenRecursively));
    bool IsEmpty = (widget == nullptr);
    if(!IsEmpty){

        ui->tabWidget->removeTab(row);
        ui->textBrowser->append(username+"用户于"+"离开");
        ui->label_2->setText(QString("在线人数：%1").arg(ui->tabWidget->count()));
    }*/
}
void chatRoom::ReceiveMessage(){
    qint64 size = udpSocket->pendingDatagramSize(); /**/
    int mysize = static_cast<int>(size);
    QByteArray *array = new QByteArray(mysize,0);
    udpSocket->readDatagram((*array).data(),size); /**/
    QDataStream stream(array,QIODevice::ReadOnly);
    int mytype;
    QString name,msg;
    QString time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    stream>>mytype;
    switch(mytype){
    case Msg:
        stream>>name>>msg;
        ui->textBrowser->setTextColor(QColor(Qt::blue));
        ui->textBrowser->append("["+name+"]"+time);
        ui->textBrowser->append(msg);
        break;
    case UserLeft:
        break;
    case UserEnter:
        break;
    }

}
void chatRoom::sndMsg(chatRoom::Msgtype type){
    QByteArray array; //创建数组
    //创建流
    QDataStream stream(&array,QIODevice::WriteOnly);
    stream<<type<<this->getName();//流入 类型和用户姓名
    switch(type){
    case Msg:
        if(this->ui->lineEdit_2->text() == ""){
            QMessageBox::warning(this,"警告","发送的内容不能为空");
            return;
        }
        stream<<this->getMsg();//流入 普通聊天信息
        break;
    case UserEnter:
        break;
    case UserLeft:
        break;
    }
    udpSocket->writeDatagram(array.data(),array.size(),QHostAddress::Broadcast,this->port); /**/
}
void chatRoom::closeEvent(QCloseEvent *){
    emit this->closeWidget();
}
void chatRoom::updateUserTab(int i){
    QLabel *label = new QLabel();
    label->setText(usernameList->at(i));
    layout->addWidget(label);
    newWidget->setLayout(layout);
    ui->scrollAreaWidgetContents->setLayout(layout);
    //调整
    ui->scrollArea->widget()->adjustSize();
}
