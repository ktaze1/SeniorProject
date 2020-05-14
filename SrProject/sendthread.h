#ifndef SENDTHREAD_H
#define SENDTHREAD_H
#include <QThread>
#include <QFile>
#include <QTcpSocket>

class SendThread : public QThread
{
public:
    SendThread(int socketdescriptor,QObject *parent);
    void run();

private:
    int socketDescriptor;
};

#endif // SENDTHREAD_H
