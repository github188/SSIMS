#include "clientscommandprocessor.h"

ClientsCommandProcessor::ClientsCommandProcessor(quint16 sPort, QObject *parent) :
    QObject(parent), server(new WebSocketServer(sPort)), protocol(new CommunicationProtocol(this)),
    serverThread(new QThread)
{
    //! move web socket server to its thread
    server->moveToThread(serverThread);
    //! connect server signals and slots
    connect(server,SIGNAL(newTextMessage(QString,QString)),protocol,SLOT(onNewRequest(QString,QString)));
    connect(protocol,SIGNAL(newRespond(QString,QString)),server,SLOT(sendTextMessage(QString,QString)));
    //! remove server after thread finish
    connect(serverThread,SIGNAL(finished()),server,SLOT(deleteLater()));
    //! start server in new thread
    connect(serverThread,SIGNAL(started()),server,SLOT(startServer()));
    serverThread->start();
}

ClientsCommandProcessor::~ClientsCommandProcessor()
{
    //! all pointers are QObjects and will be deleted by their parent
    if(serverThread->isRunning()) {
        serverThread->quit();
        serverThread->wait();
    }
}
