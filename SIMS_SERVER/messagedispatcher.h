#ifndef MESSAGEDISPATCHER_H
#define MESSAGEDISPATCHER_H

#include <QObject>
#include "database/databasemanager.h"

class MessageDispatcher : public QObject
{
    Q_OBJECT
public:
    enum ClientMessageTypes {
        CL_AlertsListUpdate = 100,//! alert list update from client, notify other clients
        SR_AlertsListUpdate,//! server notify clients to update alerts list
        CL_VideoRequired,//! client need video stream
        SR_VideoStream, //! vide stream
        CL_OpenDoor,
        SR_OpenDoor,
        CL_SetTempr,
        SR_CurTempr,
        CL_SetSiren,
        SR_SirenState,
        CL_SetPower,
        SR_PowerState,
        CL_SetAC,
        SR_ACState,
        CL_StopVideo,//! stop video stream
        CL_GetTemp,
        CL_SuspendVideo
    };
    MessageDispatcher(DatabaseManager *manager, const QString &curVidDir);
signals:
    //! signal for video module to begin load video stream and save it on the url
    void videoRequired(qint32 siteId, const QString &videoUrl, const QString &dvrIp);
    //! signal to stop video stream of site for client
    void stopClientVideoStream(qint32 siteId, const QString &ip);
    //! signal to suspend video stream of site for client
    void suspendClientVideoStream(qint32 siteId, const QString &ip);
    //! signal to start video stream of site for client
    void startClientVideoStream(qint32 siteId, const QString &ip);
    //! signal for client network to send the message to all clients
    void sendToAllClients(const QByteArray &data);
    //! signal for client network to send the message to client with ip
    void sendMessToClient(const QByteArray &message, const QString &ip);
    //! signal for panel plugin to set site temperature
    void setSiteTemperature(int siteId, int acNumber, int siteTemperature);
    //! signal for panel plugin to open site door
    void siteOpenDoor(int siteId);
    //! site set siren state
    void siteSetSirenState(int siteId, bool enable);
    //! site set A/C power state
    void siteSetACPowerState(int siteId, int acNumber,bool enable);
    //! set site power state
    void siteSetPowerState(int siteId, int powerNumber, bool enable);
    //! query temp
    void siteGetTempr(int siteId);
public slots:
    //! process incoming message from site
    void onNewMessageFromSite(int siteId, int alertId, const QString stateVal);
    //! process incoming message from client
    void onNewMessageFromClient(const QByteArray &message, const QString &ip);
    //! new video frame for gui client
    void onNewVideoFrame(qint32 siteId, const QString &clientIp, const QByteArray &streamData);
private:
    //! notify clients to update their alert lists
    void notifyClientsForAlertsListUpdate();
    //! check client message size
    bool checkMessageSize(qint32 expectedSize, const QByteArray &message);
private:
    //! db manager
    DatabaseManager *dbMan;
    //! current video directory
    QString currentVideoDirectory;
};

#endif // MESSAGEDISPATCHER_H
