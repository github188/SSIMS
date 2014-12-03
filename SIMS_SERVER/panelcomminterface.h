#ifndef PANELCOMMINTERFACE_H
#define PANELCOMMINTERFACE_H

#include <QtPlugin>

QT_BEGIN_NAMESPACE
class QString;
class QStringList;
QT_END_NAMESPACE

class IPanelCommInterface
{
public:
    virtual ~IPanelCommInterface() {}
    //! load sites data
    virtual void loadSitesData(const QList<QStringList> &sData) = 0;
    //! start listen incoming connections
    virtual void start(int port, int timeout) = 0;
    //! stop communications and delete all connections
    virtual void stop() = 0;
    //! open door command
    virtual void performOpenDoorCommand(int siteId) = 0;
    //! set temperature command
    virtual void performSetTempCommand(int siteId, int acNumber, int siteTemp) = 0;
    //! set siren state command
    virtual void performSetSirenStateCommand(int siteId, bool enable) = 0;
    //! set AC power state command
    virtual void performSetACPowerStateCommand(int siteId, int acNumber, bool enabled) = 0;
    //! set power state command
    virtual void performSetPowerStateCommand(int siteId, int powerNumber, bool enabled) = 0;
    //! query site tempr
    virtual void performQueryTemprCommand(int siteId) = 0;
    //! get pointer on qobject
    virtual QObject* qObjectPtr() = 0;
};

#define IPanelCommInterface_iid "SecureT.IPanelCommInterface/1.0"
Q_DECLARE_INTERFACE(IPanelCommInterface,IPanelCommInterface_iid)
#endif // PANELCOMMINTERFACE_H
