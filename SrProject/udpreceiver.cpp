#include "udpreceiver.h"
#include "mainwindow.h"

#include <QtWidgets>
#include <QtNetwork>
#include <QDebug>


udpReceiver::udpReceiver(QObject *parent)
    : QTcpServer(parent)
{
    listen(QHostAddress::Any, 8888);

    qDebug() << serverAddress() << serverPort() << serverError();

}


udpReceiver::~udpReceiver()
{
    delete udpSocket;
}

void udpReceiver::incomingConnection(int socketDescriptor)
{
        qDebug() << "File transfer started";

       SendThread *thread = new SendThread(socketDescriptor,this);
       connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
       thread->start();
       qDebug() << "Thread called";
}
