#include "videodata.h"
#include <iostream>
using std::cout;
using std::endl;

VideoData::VideoData(qint32 sId, HANDLE chHandle, HANDLE servHandle, bool fFirst, QFile *f) :
    siteId(sId), openChannelHandle(chHandle), logonServerHandle(servHandle), frameFirst(fFirst), videoFile(f)
{
    //! 2 mins
    stopTimer.setInterval(120000);
    stopTimer.setSingleShot(true);
    connect(&stopTimer,SIGNAL(timeout()),this,SLOT(onTimer()));
    stopTimer.start();
}

VideoData::~VideoData()
{
    videoFile->flush();
    videoFile->close();
    delete videoFile;
}

HANDLE VideoData::channelHandle() const
{
    return openChannelHandle;
}

HANDLE VideoData::serverHandle() const
{
    return logonServerHandle;
}

bool VideoData::isFrameFirst() const
{
    return frameFirst;
}

void VideoData::setFrameFirst(bool val)
{
    frameFirst = val;
}

QFile *VideoData::filePtr() const
{
    return videoFile;
}

void VideoData::onTimer()
{
    //cout << "Stop video for site:" << siteId << ", by timer" << endl;
    emit stopVideoRecording(siteId);
}
