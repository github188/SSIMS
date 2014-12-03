#ifndef PANELCOMMPLUGINMANAGER_H
#define PANELCOMMPLUGINMANAGER_H

#include <QObject>
#include "panelcomminterface.h"
#include <QDir>
#include <QPluginLoader>
#include "database/databasemanager.h"

class PanelCommPluginManager : public QObject
{
    Q_OBJECT
public:
    explicit PanelCommPluginManager(DatabaseManager *manager, quint16 p);
    ~PanelCommPluginManager();
    //! загрузка плагинов
    bool loadPlugins();
signals:
    //! new message from panel
    void newMessage(int siteId, int alertId, const QString stateVal);
public slots:
    //! set site temperature
    void onSetSiteTemperature(int siteId, int acNumber, int siteTemperature);
    //! site - open door
    void onSiteOpenDoor(int siteId);
    //! site set siren state
    void onSiteSetSirenState(int siteId, bool enable);
    //! site set A/C power state
    void onSiteSetACPowerState(int siteId, int acNumber, bool enable);
    //! set site power state
    void onSiteSetPowerState(int siteId, int powerNumber, bool enable);
    //! site get tempr
    void onSiteGetTempr(int siteId);
private:
     QHash<QString,IPanelCommInterface*> iPlugins;
     IPanelCommInterface *currentPlugin;
     DatabaseManager *dbMan;
     //! port to listen for incomming connections from sites
     quint16 networkPort;
};

#endif // PANELCOMMPLUGINMANAGER_H
