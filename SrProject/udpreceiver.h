#ifndef UDPRECEIVER_H
#define UDPRECEIVER_H

#include <QWidget>
#include <QDebug>
#include <QTcpServer>

#include "sendthread.h"

QT_BEGIN_NAMESPACE
class QLabel;
class QUdpSocket;
QT_END_NAMESPACE

class udpReceiver : public QTcpServer
{
    Q_OBJECT

public:
    explicit udpReceiver(QObject *parent = nullptr);
    void serverListener();
    ~udpReceiver();


protected slots:

    void incomingConnection(int socketDescriptor);

private:
    QLabel *statusLabel = nullptr;
    QUdpSocket *udpSocket = nullptr;
};

#endif
