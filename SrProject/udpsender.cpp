#include "udpsender.h"
#include "mainwindow.h"
#include <QtNetwork>
#include <QtCore>
#include <QTimer>

udpSender::udpSender() : QObject()
{

    udpSocket = new QUdpSocket();
    timer = new QTimer();

    startBroadcasting();
    connect(timer, SIGNAL(timeout()), this, SLOT(broadcastDatagram()));
    timer->start(15);

}

void udpSender::startBroadcasting()
{
    timer->start(1000);
}

void udpSender::broadcastDatagram()
{
    //int port = MainWindow::recepientPort;
    //QByteArray datagram = QByteArray("1", 44550);
    udpSocket->writeDatagram("1", 1, QHostAddress::Broadcast, 44550);
}
