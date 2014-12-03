#include <QCoreApplication>
#include "panelcommpluginmanager.h"
#include "database/databasemanager.h"
#include <QSettings>
#include "messagedispatcher.h"
#include "clientsnetwork/clnetserver.h"
#include "video/videomanager.h"
//#include "clients_communication/clientscommandprocessor.h"
#include "logger/Logger.h"
#include <iostream>
using std::cout;
using std:: endl;

using namespace QLogger;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QLoggerManager *logManager = QLoggerManager::getInstance();
    logManager->addDestination(QDir::currentPath() + "/logs/SecureT.log", "Server", QLogger::TraceLevel);
    QLog_Trace("Server", "Application Started");

    QCoreApplication::setOrganizationName(" SecureT");
    QCoreApplication::setApplicationName(" Server ");
    QCoreApplication::setApplicationVersion(APP_VERSION);
    cout << a.organizationName().toLocal8Bit().data() <<
            a.applicationName().toLocal8Bit().data() <<
            a.applicationVersion().toLocal8Bit().data() <<
            " build: " << BUILDDATE << " " << BUILDTIME << endl;

    QSettings settings;
    QString hostName = settings.value("databasehost","localhost").toString();
    settings.setValue("databasehost", hostName);
    QString databaseName = settings.value("databasename","securet").toString();
    settings.setValue("databasename",databaseName);
    QString password = settings.value("password","securet").toString();
    settings.setValue("password",password);
    QString userName = settings.value("username","securet_admin").toString();
    settings.setValue("username",userName);
    quint16 databasePort = settings.value("databaseport",5432).toUInt();
    settings.setValue("databaseport",databasePort);
    //! settings for clients network
    quint16 clientsNetworkPort = settings.value("clientsNetworkPort",5001).toUInt();
    settings.setValue("clientsNetworkPort",clientsNetworkPort);
    //! settings for site plugin
    quint16 sitesPort = settings.value("sitesPort",4001).toUInt();
    settings.setValue("sitesPort",sitesPort);
    //! settings for video module
    QString videoPath = settings.value("videoPath", QDir::currentPath()).toString();
    settings.setValue("videoPath", videoPath);

    //! video module
    //VideoManager videoManager(videoPath);

    //! database manager
    DatabaseManager dbManager;
    dbManager.setConnectionName(QCoreApplication::applicationName());
    dbManager.setDatabaseName(databaseName);
    dbManager.setHostName(hostName);
    dbManager.setPort(databasePort);
    dbManager.setPassword(password);
    dbManager.setUserName(userName);
    if(!dbManager.openConnection())
        return -1;

    //! clients network server
    ClientNetworkServer clientsNetwork;
    clientsNetwork.setListenPort(clientsNetworkPort);
    if( !clientsNetwork.startCommunication() )
        return -1;

    //! client command processor
    //ClientsCommandProcessor commandProcessor(clientsNetworkPort + 1);

    //! Message dispatcher
    MessageDispatcher messageDispatcher(&dbManager, videoPath);

    //! panel communication plugin manager
    PanelCommPluginManager panelCommManager(&dbManager, sitesPort);

    //! processing message from client
    QObject::connect(&clientsNetwork,SIGNAL(newMessage(QByteArray,QString)),
                     &messageDispatcher,SLOT(onNewMessageFromClient(QByteArray,QString)));
    //! processing message from site
    QObject::connect(&panelCommManager,SIGNAL(newMessage(int,int,QString)),
                     &messageDispatcher,SLOT(onNewMessageFromSite(int,int,QString)));
    //! set site temp
    QObject::connect(&messageDispatcher,SIGNAL(setSiteTemperature(int,int,int)),
                     &panelCommManager,SLOT(onSetSiteTemperature(int,int,int)));
    //! site open door
    QObject::connect(&messageDispatcher,SIGNAL(siteOpenDoor(int)),
            &panelCommManager,SLOT(onSiteOpenDoor(int)));
    //! site siren state
    QObject::connect(&messageDispatcher,SIGNAL(siteSetSirenState(int,bool)),
                     &panelCommManager,SLOT(onSiteSetSirenState(int,bool)));
    //! site AC state
    QObject::connect(&messageDispatcher,SIGNAL(siteSetACPowerState(int,int,bool)),
                     &panelCommManager,SLOT(onSiteSetACPowerState(int,int,bool)));
    //! site power state
    QObject::connect(&messageDispatcher,SIGNAL(siteSetPowerState(int,int,bool)),
                     &panelCommManager,SLOT(onSiteSetPowerState(int,int,bool)));
    //! query site tempr
    QObject::connect(&messageDispatcher,SIGNAL(siteGetTempr(int)),
                     &panelCommManager,SLOT(onSiteGetTempr(int)));
    //! send message to all clients
    QObject::connect(&messageDispatcher,SIGNAL(sendToAllClients(QByteArray)),
                     &clientsNetwork, SLOT(sendMessageToAllClients(QByteArray)));
    //! send message to client with ip
    QObject::connect(&messageDispatcher,SIGNAL(sendMessToClient(QByteArray,QString)),
                     &clientsNetwork, SLOT(sendMessToClient(QByteArray,QString)));
//    //! video request from alert
//    QObject::connect(&messageDispatcher,SIGNAL(videoRequired(qint32,QString,QString)),
//                     &videoManager,SLOT(onVideoRequest(qint32,QString,QString)));
//    //! stop video stream and recording from client
//    QObject::connect(&messageDispatcher,SIGNAL(stopClientVideoStream(qint32,QString)),
//                     &videoManager,SLOT(stopVideoStream(qint32,QString)));
    //! suspend video stream for client
    //QObject::connect(&messageDispatcher,SIGNAL(suspendClientVideoStream(qint32,QString)),
     //                &videoManager,SLOT(suspendVideoStream(qint32,QString)));
    //! start video stream for client
   // QObject::connect(&messageDispatcher,SIGNAL(startClientVideoStream(qint32,QString)),
     //                &videoManager,SLOT(startVideoStream(qint32, QString)));
    //! new video frame for gui client
   // QObject::connect(&videoManager,SIGNAL(newVideoFrame(qint32,QString,QByteArray)),
    //                 &messageDispatcher,SLOT(onNewVideoFrame(qint32,QString,QByteArray)));
    if( !panelCommManager.loadPlugins() )
        return -1;

    //messageDispatcher.onNewMessageFromSite(2,3,"On");

//    //! test new video
//    videoManager.onVideoRequest(2,"//home//anton//Desktop//2",
//                                "rtsp://mumbob1tp.dyndns.org:554;rtsp://mumbob1tp.dyndns.org:555");



//        QTimer timer;
//        timer.setSingleShot(true);
//        timer.setInterval(50000);
//        QObject::connect(&timer, SIGNAL(timeout()), &a, SLOT(quit()));
//        timer.start();

    int result = a.exec();
    QLog_Trace("Server", QString("Application exit with code:%1").arg(result));
    logManager->closeLogger();
    return result;
}
