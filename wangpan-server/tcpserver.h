#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class TcpServer; }
QT_END_NAMESPACE

class TcpServer : public QWidget
{
    Q_OBJECT

public:
    TcpServer(QWidget *parent = nullptr);
    ~TcpServer();
    void loadConfig();
    QString m_strIP;
     quint16 m_usPort;
private:
    Ui::TcpServer *ui;
};
#endif // TCPSERVER_H
