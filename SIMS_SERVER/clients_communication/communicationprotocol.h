#ifndef COMMUNICATIONPROTOCOL_H
#define COMMUNICATIONPROTOCOL_H

#include <QObject>

class CommunicationProtocol : public QObject
{
    Q_OBJECT
public:
    explicit CommunicationProtocol(QObject *parent = 0);

signals:
    void newRespond(const QString &message, const QString &clientIp);
public slots:
    void onNewRequest(const QString &message, const QString &clientIp);
};

#endif // COMMUNICATIONPROTOCOL_H
