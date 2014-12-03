#ifndef VIDEOMANAGER_H
#define VIDEOMANAGER_H

#include "remotedvr.h"
#include <QObject>
#include <QProcess>
#include <QHash>
#include <QList>

class VideoManager : public QObject
{
    Q_OBJECT
public:
    VideoManager(const QString &videoPath);
    ~VideoManager();
signals:
    void newVideoFrame(qint32 siteId, const QString &clientIp, const QByteArray &streamData);
public slots:
    void onVideoRequest(qint32 siteId, const QString &videoUrl, const QString &dvrIp);
    void onStopVideo(qint32 siteId);
    void suspendVideoStream(qint32 siteId, const QString &ip);
    void startVideoStream(qint32 siteId, const QString &ip);
    void stopVideoStream(qint32 siteId, const QString &ip);
private:
    //! directory path to store video clips
    QString videoDirectoryPath;
    //! remote dvr object
    //RemoteDvr remoteDvr;
    QHash<qint32, QList<QProcess*> > processHash;
};

#endif // VIDEOMANAGER_H
