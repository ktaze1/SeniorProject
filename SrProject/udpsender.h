#ifndef UDPSENDER_H
#define UDPSENDER_H


#include <QTimer>


QT_BEGIN_NAMESPACE
class QUdpSocket;
QT_END_NAMESPACE


class udpSender : public QObject
{
    Q_OBJECT

public:
    udpSender();

public slots:
    void startBroadcasting();
    void broadcastDatagram();

private:
    QUdpSocket *udpSocket = nullptr;
    QTimer *timer;
};

#endif // UDPSENDER_H
