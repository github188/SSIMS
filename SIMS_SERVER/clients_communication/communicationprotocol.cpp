#include "communicationprotocol.h"

CommunicationProtocol::CommunicationProtocol(QObject *parent) :
    QObject(parent)
{
}

void CommunicationProtocol::onNewRequest(const QString &message, const QString &clientIp)
{

}
