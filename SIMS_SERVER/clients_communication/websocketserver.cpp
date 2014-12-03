#include "websocketserver.h"
#include "logger/Logger.h"
#include <iostream>
using std::cout;
using std:: endl;

using namespace QLogger;

WebSocketServer::WebSocketServer(quint16 port, QObject *parent) : QObject(parent), listenPort(port)
{

}

WebSocketServer::~WebSocketServer()
{
    webServer->close();
    webServer->deleteLater();
    qDeleteAll(clients);
}

void WebSocketServer::startServer()
{
    webServer = new QWebSocketServer(QStringLiteral("Web Server"), QWebSocketServer::NonSecureMode);
    if (webServer->listen(QHostAddress::Any, listenPort)) {
        connect(webServer, SIGNAL(newConnection()), this, SLOT(onNewConnection()));
        cout << "WebSocket server start listen on port " << listenPort << endl;
    }
    else {
        QLog_Error("Server", QString(Q_FUNC_INFO) + QString(" Error listen on port %1: %2")
                   .arg(listenPort).arg(webServer->errorString()));
    }
}

void WebSocketServer::sendTextMessage(const QString &message, const QString &clientIp)
{
    if(clients.contains(clientIp))
        clients.value(clientIp)->sendTextMessage(message);
}

void WebSocketServer::onNewConnection()
{
    QWebSocket *pSocket = webServer->nextPendingConnection();
    if(!pSocket) return;

    connect(pSocket, SIGNAL(textMessageReceived(QString)), this, SLOT(processTextMessage(QString)));
    connect(pSocket, SIGNAL(binaryMessageReceived(QByteArray)), this, SLOT(processBinaryMessage(QByteArray)));
    connect(pSocket, SIGNAL(disconnected()), this, SLOT(socketDisconnected()));

    QString ip = pSocket->peerAddress().toString();
    clients.insert(ip,pSocket);

    cout << "WebSocket client connected, ip:" << ip.toLocal8Bit().data() << endl;
}

void WebSocketServer::processTextMessage(const QString &message)
{
    QWebSocket *pClient = qobject_cast<QWebSocket *>(sender());
    if (pClient) {
        QString ip = pClient->peerAddress().toString();
        pClient->sendTextMessage(message);
        cout << "New text message from websocket client with ip " << ip.toLocal8Bit().data() << endl;
    }
    emit newTextMessage(message, pClient->peerAddress().toString());
}

void WebSocketServer::processBinaryMessage(QByteArray message)
{
    Q_UNUSED(message);
    //QWebSocket *pClient = qobject_cast<QWebSocket *>(sender());

}

void WebSocketServer::socketDisconnected()
{
    QWebSocket *pClient = qobject_cast<QWebSocket *>(sender());
    if (pClient) {
        QString ip = pClient->peerAddress().toString();
        if(clients.contains(ip))
            clients.remove(ip);
        pClient->deleteLater();
    }
}
