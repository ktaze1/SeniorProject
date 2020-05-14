#ifndef UDPSENDER_H
#define UDPSENDER_H



#include <QObject>
#include <QTcpSocket>
#include <QHostAddress>
#include <QFile>

QT_BEGIN_NAMESPACE
class QUdpSocket;
QT_END_NAMESPACE


class udpSender : public QObject
{
    Q_OBJECT

public:
    explicit udpSender(QObject *parent = nullptr);
    ~udpSender();
    QTcpSocket *client;
    void start(QString address, quint16 port, QString file);
    QString filename;

public slots:
    void ReadData();
    void Completed();

private:
    QUdpSocket *udpSocket = nullptr;
};

#endif // UDPSENDER_H
