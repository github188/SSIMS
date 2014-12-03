#ifndef NETWORKCLIENTITEM_H
#define NETWORKCLIENTITEM_H

#include "clnetsocket.h"
#include <QtCore>

struct ClientNetworkItem
{
      ClientNetworkSocket *netSocket;
      QString clientIpAddress;
};

#endif // NETWORKCLIENTITEM_H
