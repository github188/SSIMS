#ifndef NETWORKSOCKET_H
#define NETWORKSOCKET_H

#include <QTcpSocket>
#include <QHostAddress>
#include <QHostInfo>

class ClientNetworkSocket : public QObject
{
Q_OBJECT
public:
    ClientNetworkSocket();
    bool setSocketDescriptor(qint32 socketdescriptor, QString &socketIP);
    ~ClientNetworkSocket();
signals:
    void newMessage(const QByteArray &message, const QString &ip);
    void connected();
    void disconnected(const QString &ip);
public slots:
    void readData();
    void writeData(const QByteArray& data);
private slots:
    void onDisconnected();
private:
    QTcpSocket *tcpSocket;
    qint32 blockSize;//! size of incoming data block
};

#endif // NETWORKSOCKET_H
