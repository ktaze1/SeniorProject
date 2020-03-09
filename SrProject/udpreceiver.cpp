#include "udpreceiver.h"
#include "mainwindow.h"

#include <QtWidgets>
#include <QtNetwork>
#include <QDebug>


udpReceiver::udpReceiver(QWidget *parent)
    : QWidget(parent)
{


    udpSocket = new QUdpSocket(this);
    udpSocket->bind(44550, QUdpSocket::ShareAddress); //change port

    connect(udpSocket, SIGNAL(readyRead()),
            this, SLOT(processPendingDatagrams()));
}


udpReceiver::~udpReceiver()
{
    delete udpSocket;
}

void udpReceiver::processPendingDatagrams()
{
    QByteArray datagram;
//! [2]
    while (udpSocket->hasPendingDatagrams()) {
        datagram.resize(int(udpSocket->pendingDatagramSize()));
        udpSocket->readDatagram(datagram.data(), datagram.size());

        qDebug() << datagram.constData();

        //Use Data
//        statusLabel->setText(tr("Received datagram: \"%1\"")
//                             .arg(datagram.constData()));
    }
//! [2]
}
