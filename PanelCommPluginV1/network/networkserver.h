#ifndef NETWORKSERVER_H
#define NETWORKSERVER_H

#include <QTcpServer>
#include <QStringList>
#include "networkclientitem.h"
#include "networksocket.h"

class NetworkServer : public QTcpServer
{
    Q_OBJECT
public:
    NetworkServer();
    ~NetworkServer();
    void setInitData(quint16 listenPort, qint32 checkCommTimeout);
    //! load sites data
    void loadSiteData(const QList<QStringList> &sData);
protected:
   void incomingConnection(int socketDescriptor);
signals:
   void error(const QString &errorDescription);
   //! new message from panel
   void newMessage(int siteId, int alertId, const QString &stateVal);
   //! panel connected
   void siteConnected(const QString &ip);
   //! panel disconnected
   void siteDisconnected(const QString &ip);
public slots:
   //! start listen for incoming connections
   bool startCommunication();
   void deleteclient(const QString &ip);
   void sendMessageToSite(int siteId, int alertId, const QString &state);

private:
    void clearSitesMap();
    void updateSiteTimeStamp(const QString &ip);
private slots:
    void onNewMessage(const QByteArray &message, const QString &ip);
    void onTimer();
private:
   QMap<qint32, NetworkClientItem*> sitesMap;//! panels map, siteId is the key
   QMap<QString, qint32> ip2idMap;//! map of sites ip to site id, ip is the key
   QHash<QString, NetworkClientItem*> unassignedConnections;
   QList<qint32> siteNumbersList;//! list of registered site numbers
   //! port to listen incoming connections
   quint16 serverListenPort;
   //! timer to check communication off
   QTimer timer;
   //! comm break time out
   qint32 lineOffTimeout;
};

#endif // NETWORKSERVER_H
