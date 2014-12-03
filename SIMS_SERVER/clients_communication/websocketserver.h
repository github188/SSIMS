#ifndef WEBSOCKETSERVER_H
#define WEBSOCKETSERVER_H

#include <QtCore/QObject>
#include <QtCore/QList>
#include <QtCore/QByteArray>
#include <QtWebSockets/QWebSocket>
#include <QtWebSockets/QWebSocketServer>


class WebSocketServer : public QObject
{
    Q_OBJECT
public:
    explicit WebSocketServer(quint16 port, QObject *parent=0);
    ~WebSocketServer();
signals:
    void newTextMessage(const QString &message, const QString &clientIp);
public slots:
    void startServer();
    void sendTextMessage(const QString &message, const QString &clientIp);
private slots:
    void onNewConnection();
    void processTextMessage(const QString &message);
    void processBinaryMessage(QByteArray message);
    void socketDisconnected();
private:
    QWebSocketServer *webServer;
    //! clients sockets hash, ip address string is a key
    QHash<QString, QWebSocket *> clients;
    quint16 listenPort;
};

#endif // WEBSOCKETSERVER_H
