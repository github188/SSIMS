#ifndef NETWORKSOCKET_H
#define NETWORKSOCKET_H

#include <QTcpSocket>
#include <QHostAddress>
#include <QHostInfo>

class NetworkSocket : public QObject
{
Q_OBJECT
public:
    NetworkSocket();
    bool setSocketDescriptor(qint32 socketdescriptor, QString &socketIP);

   ~NetworkSocket();
signals:
    void newMessage(const QByteArray &message, const QString &ip);
    void connected();
    void disconnected(const QString &ip);
    void error(const QString& errortxt);
public slots:
    void readData();
    void writeData(const QByteArray& data);
private slots:
    void onDisconnected();
private:
    QTcpSocket *tcpSocket;
    QByteArray buffer;//! incomming buffer
};

#endif // NETWORKSOCKET_H
