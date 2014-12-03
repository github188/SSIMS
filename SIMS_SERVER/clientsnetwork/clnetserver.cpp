#include "clnetserver.h"
#include <iostream>
#include <QBuffer>
#include <QStringList>
#include "logger/Logger.h"
using namespace QLogger;
using std::cout;
using std::endl;

ClientNetworkServer::ClientNetworkServer()
    :QTcpServer()
{
}

//! start listen for incoming connections
bool ClientNetworkServer::startCommunication()
{
    if( !listen(QHostAddress::Any, serverListenPort)) {
        QLog_Error("Server", QString(Q_FUNC_INFO) + " " + errorString());
        close();
        return false;
    }
    else {
        return true;
    }
}

void ClientNetworkServer::incomingConnection(int socketDescriptor)
{
    //! create socket and set descriptor
    ClientNetworkSocket *netSocket = new ClientNetworkSocket();
    QString ipAddress = QStringLiteral("");
    if( !netSocket->setSocketDescriptor(socketDescriptor, ipAddress) )
        return;
    //! add client to list
    clientsMap.insert(ipAddress, netSocket);
    //! connect signals and slots
    //! socket disconnected
    connect(netSocket, SIGNAL(disconnected(QString)), this, SLOT(deleteclient(QString)));
    //! new message from client
    connect(netSocket,SIGNAL(newMessage(QByteArray,QString)),this,SIGNAL(newMessage(QByteArray,QString)));
    //! let them know about new client
    emit clientConnected(ipAddress);
    cout << QString("Network(%1)::client %2 connected").arg(serverListenPort).arg(ipAddress).toLocal8Bit().data()<< endl;
}

void ClientNetworkServer::sendMessToClient(const QByteArray &message, const QString &ip)
{
    if(clientsMap.contains(ip)) {
        clientsMap.value(ip)->writeData(message);
    }
}

void ClientNetworkServer::sendMessageToAllClients(const QByteArray &message)
{
    foreach (ClientNetworkSocket* socket, clientsMap)
        socket->writeData(message);
}

void ClientNetworkServer::sendMessageToAllButNotThis(const QByteArray &message, const QString &ip)
{
    foreach (ClientNetworkSocket* socket, clientsMap) {
        if(clientsMap.key(socket) != ip)
            socket->writeData(message);
    }
}

void ClientNetworkServer::clearClientsMap()
{
    //! close all clients and delete them from the list
    foreach (ClientNetworkSocket* socket, clientsMap)
        delete socket;
    clientsMap.clear();
}

//! delete disconnected client from a list
void ClientNetworkServer::deleteclient(const QString &ip)
{
    QString out = QString("Network(%1)::client %2 disconnected").arg(serverListenPort).arg(ip);
    cout << out.toLocal8Bit().data() << endl;
    if(clientsMap.contains(ip)) {
        delete clientsMap.value(ip);
        clientsMap.remove(ip);
    }
}

ClientNetworkServer::~ClientNetworkServer()
{
    //! close server socket to discard new connections
    if( isListening() )
        close();
    clearClientsMap();
}

void ClientNetworkServer::setListenPort(quint16 listenPort)
{
    serverListenPort = listenPort;
}
