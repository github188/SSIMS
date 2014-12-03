#ifndef VIDEODATA_H
#define VIDEODATA_H

#include <QObject>
#include <QFile>
#include <QTimer>
#if defined (__cplusplus)
extern "C" {
#endif

#include "camera_sdk/include/HHNet.h"


#if defined (__cplusplus)
}
#endif

class VideoData : public QObject
{
    Q_OBJECT
public:
    explicit VideoData(qint32 sId, HANDLE chHandle, HANDLE servHandle, bool fFirst, QFile *f);
    ~VideoData();
    HANDLE channelHandle() const;
    HANDLE serverHandle() const;
    bool isFrameFirst() const;
    void setFrameFirst(bool val);
    QFile *filePtr() const;
signals:
    void stopVideoRecording(qint32 siteId);
private slots:
    void onTimer();
private:
    qint32 siteId;
    HANDLE openChannelHandle;
    HANDLE logonServerHandle;
    bool frameFirst;
    QFile *videoFile;
    QTimer stopTimer;
};

#endif // VIDEODATA_H
