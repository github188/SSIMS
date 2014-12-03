#ifndef REMOTEDVR_H
#define REMOTEDVR_H

#include <QFile>
#include <QObject>
#include <QHash>
#include "videodata.h"

typedef struct _RECORD_FILE_HEAD
{
    unsigned long	magicFlag;  		/*  ÎÄ¼þÍ·HHDV */
    unsigned char	majorVideoType; 	/*  Ö÷ÂëÁ÷ÊÓÆµ±àÂëËã·¨ Ò»°ãÉèÎª0¾Í¿ÉÒÔÁË */
    unsigned char	minorVideoType; 	/* ´ÎÂëÁ÷ÊÓÆµ±àÂëËã·¨ Ò»°ãÉèÎª0¾Í¿ÉÒÔÁË */
    unsigned char	majorAudioType; 	/* Ö÷ÂëÁ÷ÒôÆµ±àÂëËã·¨ Ò»°ãÉèÎª0¾Í¿ÉÒÔÁË */
    unsigned char	minorAudioType; 	/* ´ÎÂëÁ÷ÒôÆµ±àÂëËã·¨ Ò»°ãÉèÎª0¾Í¿ÉÒÔÁË */
    unsigned char	reserved[8];
}RECORD_FILE_HEAD;

class RemoteDvr : public QObject
{
    Q_OBJECT
public:
    //! initialization flag
    static bool valid;
    static QHash<qint32, VideoData*> vDataHash;
    static QHash<HANDLE, qint32> handle2site;
    static QMultiHash<qint32, QString> videoClients;
    static RemoteDvr *remoteDvrInstance;

    explicit RemoteDvr(QObject *parent = 0);
    ~RemoteDvr();
    //! callbacks for HHNET_Startup
    static INT  logonNotifyCallback(DWORD dwMsgID,DWORD ip,DWORD port,HANDLE hNotify,void *pPar);
    static INT  checkUserPswCallback(const CHAR *pUserName,const CHAR *pPsw);
    static INT	updateFileCallback(INT nOperation,INT hsock,ULONG ip,ULONG port,INT nUpdateType,CHAR *pFileName,CHAR *pFileData,INT nFileLen);
    static INT  serverMsgCmdCallback(ULONG ip,ULONG port,CHAR *pMsgHd);
    static INT  streamWriteCheckCallback(INT nOperation,const CHAR *pUserName,const CHAR *pPsw,ULONG ip,ULONG port,HHOPEN_VIEWPUSH_INFO viewPushInfo,HANDLE hOpen);
    static INT  previewStreamCallback(HANDLE hOpenChannel,void *pStreamData,UINT dwClientID,void *pContext,ENCODE_VIDEO_TYPE encodeVideoType);
    //! callbacks for stream write
    static int myStreamCallBack(HANDLE hOpenChannel,void *pStreamData,UINT dwClientID,void *pContext,ENCODE_VIDEO_TYPE encodeVideoType,ULONG frameno);
signals:
    void newVideoFrame(qint32 siteId, const QString &clientIp, const QByteArray &streamData);
public slots:
    void startVideoCapture(qint32 siteId, const QString &videoUrl, const QString &dvrIp);
    void stop(qint32 siteId);
    void addVideoClient(qint32 siteId, const QString &ip);
    void removeVideoClient(qint32 siteId, const QString &ip);
private:

};

#endif // REMOTEDVR_H
