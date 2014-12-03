#ifndef NETWORKSERVER_H
#define NETWORKSERVER_H

#include <QTcpServer>
#include <QStringList>
#include "clnetsocket.h"

class ClientNetworkServer : public QTcpServer
{
    Q_OBJECT
public:
    ClientNetworkServer();
    ~ClientNetworkServer();
    void setListenPort(quint16 listenPort);
protected:
   void incomingConnection(int socketDescriptor);
signals:
   //! new message from client
   void newMessage(const QByteArray &message, const QString &ip);
   //! client connected
   void clientConnected(const QString &ip);
   //! client disconnected
   void clientDisconnected(const QString &ip);
public slots:
   //! start listen for incoming connections
   bool startCommunication();
   void deleteclient(const QString &ip);
   void sendMessToClient(const QByteArray &message, const QString &ip);
   void sendMessageToAllClients(const QByteArray &message);
   void sendMessageToAllButNotThis(const QByteArray &message, const QString &ip);
private:
    void clearClientsMap();
private:
    //! clients list
   QMap<QString, ClientNetworkSocket*> clientsMap;
   //! port to listen incoming connections
   quint16 serverListenPort;
};

#endif // NETWORKSERVER_H
