#ifndef CLIENTSCOMMANDPROCESSOR_H
#define CLIENTSCOMMANDPROCESSOR_H
#include "communicationprotocol.h"
#include "websocketserver.h"
#include <QThread>
#include <QObject>

class ClientsCommandProcessor : public QObject
{
    Q_OBJECT
public:
    explicit ClientsCommandProcessor(quint16 sPort, QObject *parent = 0);
    ~ClientsCommandProcessor();
signals:

public slots:
private:
    WebSocketServer *server;
    CommunicationProtocol *protocol;
    QThread *serverThread;
};

#endif // CLIENTSCOMMANDPROCESSOR_H
