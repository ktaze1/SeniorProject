#ifndef UDPRECEIVER_H
#define UDPRECEIVER_H

#include <QWidget>

QT_BEGIN_NAMESPACE
class QLabel;
class QUdpSocket;
QT_END_NAMESPACE

class udpReceiver : public QWidget
{
    Q_OBJECT

public:
    explicit udpReceiver(QWidget *parent = nullptr);
    ~udpReceiver();


private slots:

    void processPendingDatagrams();

private:
    QLabel *statusLabel = nullptr;
    QUdpSocket *udpSocket = nullptr;
};

#endif
