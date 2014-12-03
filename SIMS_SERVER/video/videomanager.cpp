#include "videomanager.h"
#include <QFile>
#include <QDir>
#include "logger/Logger.h"
#include <iostream>
using std::cout;
using std::endl;
using namespace QLogger;

VideoManager::VideoManager(const QString &videoPath)
    : videoDirectoryPath(videoPath)
{
    //    connect(&remoteDvr,SIGNAL(newVideoFrame(qint32,QString,QByteArray)),
    //            this,SIGNAL(newVideoFrame(qint32,QString,QByteArray)));
}

VideoManager::~VideoManager()
{
    if(processHash.count()) {
        foreach (QList<QProcess*> list, processHash) {
            foreach (QProcess * p, list) {
                p->terminate();
            }
        }
    }
}

void VideoManager::onVideoRequest(qint32 siteId, const QString &videoUrl, const QString &dvrIp)
{

    QString text;
    text = QString("Video request for site: %1, dvr ip: %2, video url: %3")
            .arg(QString::number(siteId)).arg(dvrIp).arg(videoUrl);
    cout << text.toLocal8Bit().data() << endl;
    if(processHash.contains(siteId)) {
        cout << "Ignoring video request, capture process is already running" << endl;
        return;
    }
    //! create directory to store file
    QString path =  videoUrl;
    QDir vDir(path);
    if(!vDir.exists()) {
        if(!vDir.mkpath(path)) {
            cout << "Failed to create path:  " << path.toLocal8Bit().data() << endl;
            QLog_Error("Server", QString("%1 %2").arg(Q_FUNC_INFO).arg("Failed to create path: " + path));
            return;
        }
    }
    //! get number of video paths to capture
    QStringList paths = dvrIp.split(";",QString::SkipEmptyParts);
    //! start process for each path
    QString program = "/usr/bin/avconv";
    QStringList arguments;
    qint32 i = 1;
    QList<QProcess*> procList;
    foreach (QString path, paths) {
        arguments.clear();
        arguments <<  "-rtsp_transport" << "tcp" << "-i"
                   << path << "-c" << "copy" << "-map"
                   << "0" << "-f" << "segment" << "-segment_time" << "300"
                   << "-segment_format" << "mp4"
                   << QString(videoUrl + "/camera_%1").arg(QString::number(i))+ "-%3d.mp4";
        QProcess *myProcess = new QProcess();
        connect(myProcess, SIGNAL(finished(int,QProcess::ExitStatus)),SLOT(deleteLater()));
        connect(myProcess, SIGNAL(error(QProcess::ProcessError)),SLOT(deleteLater()));
        myProcess->start(program, arguments);
        procList << myProcess;
        i++;
    }
    //! store process list in hash
    processHash.insert(siteId,procList);
}

void VideoManager::onStopVideo(qint32 siteId)
{
    cout << "Stop video for site: " << siteId << endl;
    if(processHash.contains(siteId)) {
        QList<QProcess*> procList = processHash.value(siteId);
        foreach (QProcess * p, procList) {
            p->terminate();
            //p->deleteLater();
        }
        processHash.remove(siteId);
    }
}

void VideoManager::suspendVideoStream(qint32 siteId, const QString &ip)
{
    //remoteDvr.removeVideoClient(siteId,ip);
}

void VideoManager::startVideoStream(qint32 siteId, const QString &ip)
{
    //remoteDvr.addVideoClient(siteId,ip);
}

void VideoManager::stopVideoStream(qint32 siteId, const QString &ip)
{
    onStopVideo(siteId);
}
