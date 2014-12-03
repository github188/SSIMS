#ifndef PANELCOMMPLUGINV1_H
#define PANELCOMMPLUGINV1_H

#include "../SIMS_SERVER/panelcomminterface.h"
#include "panelcommpluginv1_global.h"
#include <QThread>
#include "network/networkserver.h"

class PANELCOMMPLUGINV1SHARED_EXPORT PanelCommPluginV1 : public QObject, public IPanelCommInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "SecureT.PanelCommPlugin/1.0" FILE "panelcommpluginv1.json")
    Q_INTERFACES(IPanelCommInterface)
public:
    PanelCommPluginV1();
    ~PanelCommPluginV1();
    //! load sites data
    void loadSitesData(const QList<QStringList> &sData);
    //! start listen incoming connections
    void start(int port, int timeout);
    //! stop communications and delete all connections
    void stop();
    //! open door command
    void performOpenDoorCommand(int siteId);
    //! set temperature command
    void performSetTempCommand(int siteId, int acNumber, int siteTemp);
    //! set siren state command
    void performSetSirenStateCommand(int siteId, bool enable);
    //! set AC power state command
    void performSetACPowerStateCommand(int siteId, int acNumber, bool enabled);
    //! set power state command
    void performSetPowerStateCommand(int siteId, int powerNumber, bool enabled);
    //! query site tempr
    void performQueryTemprCommand(int siteId);
    //! get pointer on qobject
    QObject* qObjectPtr();
signals:
    //! new message from panel
    void newMessage(int siteId, int alertId, const QString stateVal);
    //! error in plugin
    void error(const QString &errorDescription);
    //! send message to panel
    void sendMessage(int siteId, int alertId, const QString &state);
private:
    NetworkServer* netServer;
    //! network thread
    QThread* netThread;
};

#endif // PANELCOMMPLUGINV1_H
