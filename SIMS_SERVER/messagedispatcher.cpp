#include "messagedispatcher.h"
#include "logger/Logger.h"
#include <iostream>
using std::cout;
using std::endl;
using namespace QLogger;


MessageDispatcher::MessageDispatcher(DatabaseManager *manager, const QString &curVidDir)
    : dbMan(manager), currentVideoDirectory(curVidDir)
{
}

void MessageDispatcher::onNewMessageFromSite(int siteId, int alertId, const QString stateVal)
{
    qint32 flags = 0;
    QString dvrIp = QStringLiteral("");
    QString videoUrl = QStringLiteral("");
    if( !dbMan->regAlert(siteId, alertId, stateVal,currentVideoDirectory, videoUrl, dvrIp, flags) ) {
        QLog_Error("Server", QString(Q_FUNC_INFO)
                   + QString(" Could not reg alert#%1, site#%2, state: %3")
                   .arg(QString::number(siteId)).arg(QString::number(alertId)).arg(stateVal));
        return;
    }
    //cout << "flags: " << flags << endl;
    //! check if notification of clients required
    if(flags & 0x00000001)
        notifyClientsForAlertsListUpdate();

    //! check if open door command required
    if(flags & 0x00000002)
        emit siteOpenDoor(siteId);

    //! check if video capture required
    if(flags & 0x00000004)
        emit videoRequired(siteId, videoUrl, dvrIp);

    //! send message to clients
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_0);
    switch (alertId) {
    //! open door state
    case 9:
        out << (qint32)(SR_OpenDoor); out << (qint32)siteId; out << stateVal;
        emit sendToAllClients(block);
        return;
        //! site tempr
    case 8:
        out << (qint32)(SR_CurTempr); out << (qint32)siteId; out << stateVal.toInt();
        emit sendToAllClients(block);
        return;
        //    //! siren state
        //    case:
        //        out << (qint32)(SR_SirenState); out << (qint32)siteId;
        //        break;
        //! power 1,2,3,4 state
    case 15:
        if (stateVal.length() < 5) return;
        out << (qint32)(SR_PowerState); out << (qint32)siteId;
        out << (qint32)(stateVal.mid(1,1).toInt());
        (stateVal.mid(3,2)==QStringLiteral("On")) ? out << true : out << false;
        emit sendToAllClients(block);
        return;
        //    //! ac 1,2 state
        //    case: break;
    default:return;
    }
}

void MessageDispatcher::onNewMessageFromClient(const QByteArray &message, const QString &ip)
{
    cout << "New message comes from client: " <<  ip.toLocal8Bit().data() <<endl;
    QDataStream data(message);
    data.setVersion(QDataStream::Qt_5_0);
    qint32 header;
    if(!checkMessageSize(4, message)) return;
    data >> header;
    qint32 siteId = 0;
    qint32 siteTemp = 0;
    bool flag = false;
    qint32 number = 0;
    switch(header) {
    case CL_AlertsListUpdate: notifyClientsForAlertsListUpdate(); return;
    case CL_VideoRequired:
        if(!checkMessageSize(8, message)) return;
        data >> siteId; emit startClientVideoStream(siteId,ip); return;
    case CL_StopVideo:
        if(!checkMessageSize(8, message)) return;
        data >> siteId; emit stopClientVideoStream(siteId,ip); return;
    case CL_SuspendVideo:
        if(!checkMessageSize(8, message)) return;
        data >> siteId; emit suspendClientVideoStream(siteId, ip); return;
    case CL_OpenDoor:
        if(!checkMessageSize(8, message)) return;
        data >> siteId; emit siteOpenDoor(siteId); return;
    case CL_SetTempr:
        if(!checkMessageSize(16, message)) return;
        data >> siteId; data >> number; data >> siteTemp; emit setSiteTemperature(siteId, number, siteTemp); return;
    case CL_SetSiren:
        if(!checkMessageSize(9, message)) return;
        data >> siteId; data >> flag; emit siteSetSirenState(siteId, flag); return;
    case CL_SetPower:
        if(!checkMessageSize(13, message)) return;
        data >> siteId; data >> number; data >> flag; emit siteSetPowerState(siteId, number, flag); return;
    case CL_SetAC:
        if(!checkMessageSize(13, message)) return;
        data >> siteId; data >> number; data >> flag; emit siteSetACPowerState(siteId, number, flag); return;
    case CL_GetTemp:
        if(!checkMessageSize(8, message)) return;
        data >> siteId; emit siteGetTempr(siteId);
        return;
    default: cout << QString("Unrecognized header:%1 in message from client:%2")
                     .arg(QString::number(header)).arg(ip).toLocal8Bit().data() << endl;
        return;
    }
}

void MessageDispatcher::onNewVideoFrame(qint32 siteId, const QString &clientIp, const QByteArray &streamData)
{
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_0);
    out << (qint32)(SR_VideoStream);//! header
    out << streamData;
    emit sendMessToClient(block,clientIp);
}

void MessageDispatcher::notifyClientsForAlertsListUpdate()
{
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_0);
    out << (qint32)(SR_AlertsListUpdate);//! header
    emit sendToAllClients(block);
}

bool MessageDispatcher::checkMessageSize(qint32 expectedSize, const QByteArray &message)
{
    qint32 size = message.size();
    if(size < expectedSize) {
        cout << "Message is incorrect, size " << size
             << ", expected to be more or equal than " << expectedSize<< endl;
        return false;
    }
    return true;
}
