#include "remotedvr.h"
#include <iostream>
#include <QFile>
#include <QDir>
#include "logger/Logger.h"
using namespace QLogger;
using std::cout;
using std::endl;

bool RemoteDvr::valid = false;
QHash<qint32, VideoData*> RemoteDvr::vDataHash;
QHash<HANDLE, qint32> RemoteDvr::handle2site;
QMultiHash<qint32, QString> RemoteDvr::videoClients;
RemoteDvr* RemoteDvr::remoteDvrInstance = 0;
#ifdef __cplusplus
extern "C"{
#endif



RemoteDvr::RemoteDvr(QObject *parent) :
    QObject(parent)
{
    HHERR_CODE errCode = HHERR_FAILURE;
    quint16 cameraDataPort = 5000;
    errCode = HHNET_Startup(cameraDataPort, logonNotifyCallback, checkUserPswCallback, updateFileCallback,
                            serverMsgCmdCallback, streamWriteCheckCallback,
                            (ChannelStreamCallback)previewStreamCallback);
    if(errCode) {
        valid = false;
        QLog_Error("Server", QString("%1 %2").arg(Q_FUNC_INFO).arg("HHNET_Startup: failed!"));
        cout << "HHNET_Startup: failed!" << endl;
        return;
    }
    valid = true;
    remoteDvrInstance = this;
}

RemoteDvr::~RemoteDvr()
{
    HHNET_Cleanup();
}

void RemoteDvr::startVideoCapture(qint32 siteId, const QString &videoUrl, const QString &dvrIp)
{
    if(vDataHash.contains(siteId))
        return;//! we already capture video
    HH_SERVER_INFO stHHserverInfo;
    RECORD_FILE_HEAD 	fhead;
    VideoData *vData = 0;
    HANDLE m_hLogonServer;
    HANDLE m_hOpenChannel;
    HHERR_CODE errCode = HHERR_FAILURE;
    memset(&stHHserverInfo, 0, sizeof(HH_SERVER_INFO));
    errCode = HHNET_LogonServer(dvrIp.toLocal8Bit().data(), 5000, "admin", "admin", "admin", 0, &m_hLogonServer);
    if(errCode) {
        QLog_Error("Server", QString("%1 %2").arg(Q_FUNC_INFO).arg("HHNET_LogonServer: failed!"));
        cout << "HHNET_LogonServer: failed, code:" << errCode << endl;
        return;
    }
    //! create directory to store file
    QString fileName = videoUrl + ".mp6";
    QFileInfo fInfo(fileName);
    QString path =  fInfo.absolutePath();
    QDir vDir(path);
    if(!vDir.exists()) {
        if(!vDir.mkpath(path)) {
            cout << "Failed to create path:  " << path.toLocal8Bit().data() << endl;
            QLog_Error("Server", QString("%1 %2").arg(Q_FUNC_INFO).arg("Failed to create path: " + path));
            HHNET_LogoffServer(m_hLogonServer);//! log off server
            return;
        }
    }
    //!open channel and create video data object

    HH_CHANNEL_INFO rChInfo;
    HHOPEN_CHANNEL_INFO channelInfo;
    channelInfo.dwClientID = 1;
    channelInfo.nOpenChannel = 0;
    channelInfo.protocolType = (NET_PROTOCOL_TYPE)0;
    channelInfo.funcStreamCallback = (ChannelStreamCallback)myStreamCallBack;
    channelInfo.pCallbackContext = 0;
    errCode = HHNET_OpenChannel(dvrIp.toLocal8Bit().data(), 5000, "admin", "admin", "admin", (HHOPEN_CHANNEL_INFO*)&channelInfo, &m_hOpenChannel);
    if(errCode) {
        QLog_Error("Server", QString("%1 %2").arg(Q_FUNC_INFO).arg("HHNET_OpenChannel: failed!"));
        cout << "HHNET_OpenChannel failed, code:" << errCode << endl;
        HHNET_LogoffServer(m_hLogonServer);//! log off server
        return;
    }
    errCode = HHNET_ReadChannelInfo(m_hOpenChannel,(HH_CHANNEL_INFO*)&rChInfo);
    if(errCode) {
        QLog_Error("Server", QString("%1 %2").arg(Q_FUNC_INFO).arg("HHNET_ReadChannelInfo: failed!"));
        cout << "HHNET_ReadChannelInfo failed, code:" << errCode << endl;
        //! close channel and log out
        HHNET_CloseChannel(m_hOpenChannel);
        HHNET_LogoffServer(m_hLogonServer);
        return;
    }
    errCode = HHNET_ReadServerInfo(m_hLogonServer, &stHHserverInfo);
    if(errCode) {
        QLog_Error("Server", QString("%1 %2").arg(Q_FUNC_INFO).arg("HHNET_ReadServerInfo: failed!"));
        cout << "HHNET_ReadServerInfo failed, code:" << errCode << endl;
        //! close channel and log out
        HHNET_CloseChannel(m_hOpenChannel);
        HHNET_LogoffServer(m_hLogonServer);
        return;
    }
    if (stHHserverInfo.nMachineType == 0x04 || stHHserverInfo.nMachineType == 0x05 \
            || stHHserverInfo.nMachineType == 0x06) {
        QLog_Error("Server", QString("%1 %2").arg(Q_FUNC_INFO).arg("Device can not record"));
        cout << "Device can not record" << endl;
        //! close channel and log out
        HHNET_CloseChannel(m_hOpenChannel);
        HHNET_LogoffServer(m_hLogonServer);
        return;
    }
    fhead.magicFlag = 'VDHH';
    fhead.majorVideoType = stHHserverInfo.avInformation[0].nVideoEncodeType;
    fhead.minorVideoType = stHHserverInfo.avInformation[0].nVideoEncodeType;
    fhead.majorAudioType = (stHHserverInfo.avInformation[0].nAudioEncodeType & 0xff00) >> 8;;
    fhead.minorAudioType = stHHserverInfo.avInformation[0].nAudioEncodeType & 0xff;

    QFile *vFile = new QFile(fileName);
    if(!vFile->open(QIODevice::WriteOnly)) {
        QLog_Error("Server", QString("%1 %2").arg(Q_FUNC_INFO).arg("Can not open file: "+ vFile->fileName()));
        cout << "Can not open file: " << vFile->fileName().toLocal8Bit().data() << endl;
        delete vFile;
        //! close channel and log out
        HHNET_CloseChannel(m_hOpenChannel);
        HHNET_LogoffServer(m_hLogonServer);
        return;
    }
    vFile->write((const char*)&fhead,sizeof(fhead));
    vFile->flush();
    vData = new VideoData(siteId,m_hOpenChannel,m_hLogonServer,true,vFile);
    //connect(vData,SIGNAL(stopVideoRecording(qint32)),this,SLOT(stop(qint32)));
    vDataHash.insert(siteId,vData);
    handle2site.insert(vData->channelHandle(),siteId);
}

void RemoteDvr::stop(qint32 siteId)
{
    cout << "Stop video recording for site " << siteId << endl;
    HHERR_CODE errCode;
    if(vDataHash.contains(siteId)) {
        VideoData *vD = vDataHash.value(siteId);
        errCode = HHNET_CloseChannel(vD->channelHandle());
        if(errCode) {
            QLog_Error("Server", QString("%1 %2").arg(Q_FUNC_INFO).arg("HHNET_CloseChannel: failed!"));
            cout << "HHNET_CloseChannel failed, code:" << errCode << endl;
        }
        errCode = HHNET_LogoffServer(vD->serverHandle());
        if(errCode) {
            QLog_Error("Server", QString("%1 %2").arg(Q_FUNC_INFO).arg("HHNET_LogoffServer: failed!"));
            cout << "HHNET_LogoffServer failed, code:" << errCode << endl;
        }
        if(handle2site.contains(vD->channelHandle()))
            handle2site.remove(vD->channelHandle());
        delete vD;
        vDataHash.remove(siteId);
    }
}

void RemoteDvr::addVideoClient(qint32 siteId, const QString &ip)
{
    if(!videoClients.contains(siteId,ip)) {
        videoClients.insert(siteId, ip);
        cout << QString("Start video stream for site:%1, client:%2")
                .arg(siteId).arg(ip).toLocal8Bit().data() << endl;
    }
}

void RemoteDvr::removeVideoClient(qint32 siteId, const QString &ip)
{
    if(videoClients.contains(siteId,ip)) {
        cout << QString("Stop video stream for site:%1, client:%2")
                .arg(siteId).arg(ip).toLocal8Bit().data() << endl;
        videoClients.remove(siteId,ip);
    }
}

INT RemoteDvr::logonNotifyCallback(DWORD dwMsgID, DWORD ip, DWORD port, HANDLE hNotify, void *pPar)
{
    return 0;
}

INT RemoteDvr::checkUserPswCallback(const CHAR *pUserName, const CHAR *pPsw)
{
    cout << QString("check user:%1 and password:%2 ").arg(pUserName).arg(pPsw).toLocal8Bit().data() << endl;
    return 3;
}

INT RemoteDvr::updateFileCallback(INT nOperation, INT hsock, ULONG ip, ULONG port, INT nUpdateType, CHAR *pFileName, CHAR *pFileData, INT nFileLen)
{
    return 0;
}

INT RemoteDvr::serverMsgCmdCallback(ULONG ip, ULONG port, CHAR *pMsgHd)
{
    return 0;
}

INT RemoteDvr::streamWriteCheckCallback(INT nOperation, const CHAR *pUserName, const CHAR *pPsw, ULONG ip, ULONG port, HHOPEN_VIEWPUSH_INFO viewPushInfo, HANDLE hOpen)
{
    return 0;
}

INT RemoteDvr::previewStreamCallback(HANDLE hOpenChannel, void *pStreamData, UINT dwClientID, void *pContext, ENCODE_VIDEO_TYPE encodeVideoType)
{
    cout << "preview stream callback" << endl;
    return 0;
}

int RemoteDvr::myStreamCallBack(HANDLE hOpenChannel, void *pStreamData, UINT dwClientID, void *pContext, ENCODE_VIDEO_TYPE encodeVideoType, ULONG frameno)
{
    //cout << "stream come" << endl;
    HV_FRAME_HEAD	*pFrameHead = (HV_FRAME_HEAD *)pStreamData;

    if (FRAME_FLAG_A == pFrameHead->streamFlag)	{
        return -1;
    }
    if(handle2site.contains(hOpenChannel)) {
        qint32 siteId = handle2site.value(hOpenChannel);
        if(vDataHash.contains(siteId)) {
            VideoData *vD = vDataHash.value(siteId);
            if(vD->isFrameFirst() && (FRAME_FLAG_VI != pFrameHead->streamFlag)) {
                return 0;
            }
            else {
                vD->setFrameFirst(false);
            }
            vD->filePtr()->write((const char*)pStreamData,pFrameHead->nByteNum + sizeof(HV_FRAME_HEAD));
            vD->filePtr()->flush();
            //! emit signal to send frame to client
            QList<QString> values = videoClients.values(siteId);
            QByteArray frameData((const char*)pStreamData, pFrameHead->nByteNum + sizeof(HV_FRAME_HEAD));
            for (int i = 0; i < values.size(); ++i) {
                remoteDvrInstance->newVideoFrame(siteId,values.at(i),frameData);
                cout << "Send frame to client: " << values.at(i).toLocal8Bit().data() << endl;
            }
        }
        else {
            cout << "error in hash map" << endl;
        }
    }
    else {
        cout << "stream comes from unregistered channel" << endl;
    }
    return 0;
}

#ifdef __cplusplus
}
#endif
