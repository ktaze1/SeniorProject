#include "udpsender.h"
#include "mainwindow.h"
#include <QtNetwork>
#include <QtCore>
#include <QTimer>

udpSender::udpSender(QObject *parent) : QObject(parent)
{

    client = new QTcpSocket(this);
    client->abort();
    connect(client, SIGNAL(readyRead()), this, SLOT(ReadData()));
    connect(client, SIGNAL(disconnected()), this, SLOT(Completed()));

}

udpSender::~udpSender()
{
    client->close();
}

void udpSender::start(QString address, quint16 port, QString file)
{
        QHostAddress addr(address);
        filename = file;
        client->connectToHost(addr, port);
        qDebug() << client->socketDescriptor();
}

void udpSender::Completed()
{
    qDebug() << "File transfer complete";
}


void udpSender::ReadData()
{
    QFile file(filename);
    if(!(file.open(QIODevice::Append)))
    {
        qDebug("File cannot be opened.");
        exit(0);
    }
    QByteArray read = client->read(client->bytesAvailable());
    qDebug() << "Read    : " << read.size();
    file.write(read);
    file.close();
}
