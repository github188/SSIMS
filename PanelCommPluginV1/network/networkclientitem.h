#ifndef NETWORKCLIENTITEM_H
#define NETWORKCLIENTITEM_H

#include "networksocket.h"
#include <QtCore>

struct NetworkClientItem
{
      NetworkSocket *netSocket;
      qint32 socketDescriptor;
      QString clientIpAddress;
      qint32 siteId;
      QDateTime lastMessTime;
};

#endif // NETWORKCLIENTITEM_H
