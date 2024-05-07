#ifndef MYTCPSERVER_H
#define MYTCPSERVER_H

#include <QTcpServer>
#include<QList>
#include "mytcpsocket.h"
class MyTcpServer : public QTcpServer
{

    Q_OBJECT
public slots:
    void deleteSocket(MyTcpSocket* tcpSocket);
public:
    explicit MyTcpServer(QObject *parent = nullptr);
    static MyTcpServer &getInstance();
    void incomingConnection(qintptr socketDescriptor);
    QList<MyTcpSocket*> m_tcpSocketList;
    void resend(const char *perName,PDU *pdu);
};

#endif // MYTCPSERVER_H
