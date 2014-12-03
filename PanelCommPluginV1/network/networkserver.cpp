#include "networkserver.h"
#include <iostream>
#include <QXmlQuery>
#include <QBuffer>
#include <QXmlResultItems>
#include <QXmlNodeModelIndex>
#include <QStringList>
#include "../SIMS_SERVER/logger/Logger.h"
using namespace QLogger;
using std::cout;
using std::endl;

NetworkServer::NetworkServer()
    :QTcpServer()
{
    connect(&timer,SIGNAL(timeout()), this, SLOT(onTimer()));
}

//! start listen for incoming connections
bool NetworkServer::startCommunication()
{
    if( !listen(QHostAddress::Any, serverListenPort)) {
        //QLog_Error("Plugin", QString(Q_FUNC_INFO) + " " + errorString());
        close();
        return false;
    }
    else {
        //! start timer
        //timer.start();
        return true;
    }
}

void NetworkServer::incomingConnection(int socketDescriptor)
{
    //! create socket and set descriptor
    NetworkSocket *netSocket = new NetworkSocket();
    QString ipAddress = QStringLiteral("");
    if( !netSocket->setSocketDescriptor(socketDescriptor, ipAddress) ) {
        delete netSocket;
        return;
    }
    //    //! for now we have socket, ip and need to find it inte loaded list
    //    if( !ip2idMap.contains(ipAddress) ) {
    //        //! no such site in a database
    //        //        QLog_Error("Plugin", QString(Q_FUNC_INFO) + " "
    //        //                   + QString("Unknown site with ip: %1 is trying to connect").arg(ipAddress));
    //        return;
    //    }
    //    //! get network item for this site
    //    qint32 siteId = ip2idMap.value(ipAddress);
    //    if( !sitesMap.contains(siteId) ) {
    //        //! no such site in a database
    //        //        QLog_Error("Plugin", QString(Q_FUNC_INFO) + " "
    //        //                   + QString("Error in mapping site ip address: %1").arg(ipAddress));
    //        return;
    //    }
    NetworkClientItem* nItem = new NetworkClientItem();//sitesMap.value(siteId);
    nItem->netSocket = netSocket;
    nItem->socketDescriptor = socketDescriptor;
    nItem->clientIpAddress = ipAddress;
    nItem->lastMessTime = QDateTime::currentDateTime();
    nItem->siteId = -1;
    //! connect signals and slots
    //! forward error
    connect(netSocket, SIGNAL(error(QString)), this, SIGNAL(error(QString)));
    //! socket disconnected
    connect(netSocket, SIGNAL(disconnected(QString)), this, SLOT(deleteclient(QString)));
    //! new message from panel
    connect(netSocket, SIGNAL(newMessage(QByteArray,QString)),
            this,SLOT(onNewMessage(QByteArray,QString)));
    //! let them know about new site
    emit siteConnected(ipAddress);
    cout << QString("Site with ip:%1 is now connected").arg(ipAddress).toLocal8Bit().data() << endl;
    unassignedConnections.insert(ipAddress, nItem);
}

void NetworkServer::clearSitesMap()
{
    //! close all clients and delete them from the list
    foreach(NetworkClientItem *ncm, sitesMap) {
        //! delete from ip2id map too
        if(ip2idMap.contains(ncm->clientIpAddress))
            ip2idMap.remove(ncm->clientIpAddress);
        delete ncm->netSocket;
        delete ncm;
    }
    sitesMap.clear();
}

void NetworkServer::updateSiteTimeStamp(const QString &ip)
{
    if(ip2idMap.contains(ip)) {
        NetworkClientItem* item = sitesMap.value(ip2idMap.value(ip));
        item->lastMessTime = QDateTime::currentDateTime();
    }
}

void NetworkServer::onNewMessage(const QByteArray &message, const QString &ip)
{
    //! processing of xml message goes here
    QXmlQuery query;
    QByteArray temp(message);
    QBuffer buf(&temp);
    buf.open( QIODevice::ReadOnly );
    query.bindVariable("file",&buf);
    QString text("declare namespace xsi = \"http://www.w3.org/2001/XMLSchema-instance\";\n"
                 "declare namespace gen = \"http://www.easypsim.com/generic\";\n"
                 "doc($file)//gen:MsgList/Msg/@%1/string()");
    QString queryStr = text.arg("Id");
    query.setQuery(queryStr);
    QString id;
    if( !query.evaluateTo(&id) ) {
        cout << "Xml file is incorrect." << endl;
        return;
    }
    id.remove("\n");
    queryStr = text.arg("State");
    query.setQuery(queryStr);
    QString state;
    if (!query.evaluateTo(&state) ) {
        cout << "Xml file is incorrect." << endl;
        return;
    }
    state.remove("\n");
    queryStr = text.arg("Time");
    query.setQuery(queryStr);
    QString time;
    if (!query.evaluateTo(&time) ) {
        cout << "Xml file is incorrect." << endl;
        return;
    }
    time.remove("\n");
    qint32 siteId=0;
    qint32 alertId=0;
    siteId = id.mid(id.indexOf(".")+1,id.indexOf(".Alert") - id.indexOf(".")-1).toInt();
    alertId = id.mid(id.indexOf("Alert.")+6,id.length()-id.indexOf("Alert.")+6).toInt();
    //    if(ip2idMap.contains(ip)) {
    //        qint32 ID = ip2idMap.value(ip);
    //        if(sitesMap.contains( ID )) {
    //            if(ID != siteId) {
    //                //                QLog_Error("Plugin", QString(Q_FUNC_INFO) + " "
    //                //                           + QString("Configuration of site#%1 is incorrect: socket IP:%2, map IP:%3")
    //                //                           .arg(ID).arg(ip).arg(sitesMap.value(siteId)->clientIpAddress));
    //                cout << QString("Configuration of site#%1 is incorrect").arg(ID).toLocal8Bit().data() << endl;
    //            }
    //            QString outStr = QString("Message from site|ip: %1|%2 { site: %3, alert: %4, state: %5, time: %6 }")
    //                    .arg(ID).arg(ip).arg(siteId)
    //                    .arg(QString::number(alertId))
    //                    .arg(state).arg(time);
    //            cout << outStr.toLocal8Bit().data() << endl;
    //            //! update last message time
    //            updateSiteTimeStamp(ip);
    //            emit newMessage(ID,alertId,state);
    //        }
    //        else {
    //            QString errorText = QString("Message from ip: %1 have wrong site number: %2").arg(ip).arg(siteId);
    //            cout << errorText.toLocal8Bit().data() << endl;
    //            //QLog_Error("Plugin", QString(Q_FUNC_INFO) + " " + errorText);
    //        }
    //    }
    //    else {
    //        QString errorString = QString("Message comes from unregistered ip:%1").arg(ip);
    //        cout << errorString.toLocal8Bit().data() << endl;
    //        //QLog_Error("Plugin", QString(Q_FUNC_INFO) + " " + errorString);
    //    }
    //! if this connection is not assigned to site number
    if(!ip2idMap.contains(ip)) {
        if(unassignedConnections.contains(ip)) {
            NetworkClientItem *item = unassignedConnections.value(ip);
            //! check the site number
            if(!siteNumbersList.contains(siteId)) {
                cout << "Ignoring message from unregistered site " << siteId << endl;
                //! close connection
                unassignedConnections.remove(ip);
                disconnect(item->netSocket,SIGNAL(disconnected(QString)), this, SLOT(deleteclient(QString)));
                delete item->netSocket;
                delete item;
                cout << "Disconnect from site with ip " << ip.toLocal8Bit().data() << endl;
                return;
            }
            //! assign connection to site number
            cout << QString("Assign connection with ip: %1, to site # %2").arg(ip).arg(QString::number(siteId))
                    .toLocal8Bit().data() << endl;
            item->siteId = siteId;
            ip2idMap.insert(ip,siteId);
            sitesMap.insert(siteId,item);
            unassignedConnections.remove(ip);
        }
        else {
            cout << "Wrong connection logic!" << endl;
            return;
        }
    }
    updateSiteTimeStamp(ip);
    QString outStr = QString("Message from site|ip: %1|%2 { site: %3, alert: %4, state: %5, time: %6 }")
            .arg(siteId).arg(ip).arg(siteId)
            .arg(alertId,2,10,QLatin1Char('0'))
            .arg(state).arg(time);
    cout << outStr.toLocal8Bit().data() << endl;
    cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
    cout << message.data() << endl;
    cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
    emit newMessage(siteId, alertId, state);
}

void NetworkServer::onTimer()
{
    QDateTime currentDt = QDateTime::currentDateTime();
    foreach (NetworkClientItem* item, sitesMap) {
        if( item->lastMessTime.msecsTo(currentDt) >= lineOffTimeout) {
            cout << "Communication timeout, site#" << item->siteId << endl;
        }
    }
}

//! delete disconnected client from a list
void NetworkServer::deleteclient(const QString &ip)
{
    QString out = QString("Network(%1)::client %2 disconnected").arg(serverListenPort).arg(ip);
    cout << out.toLocal8Bit().data() << endl;
    if(ip2idMap.contains(ip)) {
        qint32 id = ip2idMap.value(ip);
        ip2idMap.remove(ip);
        if(sitesMap.contains(id)) {
            NetworkClientItem *ncm = sitesMap.value(id);
            delete ncm->netSocket;
            delete ncm;
            sitesMap.remove(id);
        }
        emit siteDisconnected(ip);
    }
}

void NetworkServer::sendMessageToSite(int siteId, int alertId, const QString &state)
{
    QString message = QString("<?xml version=\"1.0\" encoding=\"UTF-8\"?> \
                              <gen:MsgList xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" \
            xmlns:gen=\"http://www.easypsim.com/generic\"> \
            <Msg xsi:type=\"gen:ProcessState\" Id=\"Site.%1.Alert.%2\" State=\"%3\" Time=\"%4\"/> \
            </gen:MsgList> #")
            .arg(QString::number(siteId)).arg(alertId,2,10,QChar('0'))
            .arg(state).arg(QDateTime::currentDateTime().toString("yyyy.MM.dd hh:mm:ss"));
            if(sitesMap.contains(siteId)) {
            cout << "Send message to site: " << siteId << endl;
            cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
            cout << message.toLocal8Bit().data() << endl;
            cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
            NetworkClientItem *nItem = sitesMap.value(siteId);
            nItem->netSocket->writeData(message.toUtf8());
}
}

NetworkServer::~NetworkServer()
{
    timer.stop();
    //! close server socket to discard new connections
    if( isListening() )
        close();
    clearSitesMap();
}

void NetworkServer::setInitData(quint16 listenPort, qint32 checkCommTimeout)
{
    serverListenPort = listenPort;
    lineOffTimeout = checkCommTimeout;
    timer.setInterval(lineOffTimeout);
}

void NetworkServer::loadSiteData(const QList<QStringList> &sData)
{
    //    if(sitesMap.size())
    //        clearSitesMap();
    //    for(qint32 i=0; i<sData.count(); ++i) {
    //        NetworkClientItem *item = new NetworkClientItem();
    //        qint32 siteId = sData.at(i).at(0).toInt();
    //        item->siteId = siteId;
    //        item->clientIpAddress = sData.at(i).at(1);
    //        item->lastMessTime = QDateTime::currentDateTime();
    //        sitesMap.insert(siteId,item);
    //        //        //! add item to ip2id map
    //        //        ip2idMap.insert(item->clientIpAddress,siteId);
    //    }
    for(qint32 i=0; i<sData.count(); ++i) {
        qint32 siteId = sData.at(i).at(0).toInt();
        siteNumbersList << siteId;
    }
}


