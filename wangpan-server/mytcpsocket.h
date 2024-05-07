#ifndef MYTCPSOCKET_H
#define MYTCPSOCKET_H
#include "opedb.h"
#include <QTcpSocket>
#include "protocol.h"
#include "opedb.h"
#include <QDir>
#include <QFileInfoList>
#include <QTimer>
class MyTcpSocket : public QTcpSocket
{
    Q_OBJECT
public:
    explicit MyTcpSocket(QObject *parent = nullptr);
    QString getName();
    QString m_strName;
    void handleAddFriendAgree(PDU* pdu);
    QFile m_file;
    qint64 m_iTotal;
    qint64 m_iRecved;
    bool m_bUploadt;
    QTimer *m_pTimer;
    void handleAddFriendReject(PDU* pdu);
    void copyDir(QString strSrcDir,QString strDestDir);
signals:
    void offline(MyTcpSocket *socket);
public slots:
    void receiveMsg();
    void clientOffline();
    void sendFileToClient();
private:

};

#endif // MYTCPSOCKET_H
