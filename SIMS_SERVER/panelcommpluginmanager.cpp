#include "panelcommpluginmanager.h"
#include <QCoreApplication>
#include <iostream>
#include "logger/Logger.h"
using namespace QLogger;
using std::cout;
using std:: endl;

PanelCommPluginManager::PanelCommPluginManager(DatabaseManager *manager, quint16 p)
    : iPlugins(), currentPlugin(nullptr), dbMan(manager), networkPort(p)
{
}

PanelCommPluginManager::~PanelCommPluginManager()
{
    QHash<QString,IPanelCommInterface*>::const_iterator i = iPlugins.constBegin();
    while ( i != iPlugins.constEnd()) {
        i.value()->stop();
        delete i.value();
        ++i;
    }
    iPlugins.clear();
}

bool PanelCommPluginManager::loadPlugins()
{
    QDir pluginsDir(  qApp->applicationDirPath() );
    pluginsDir.cd( "panel_comm_plugins" );
    QString pluginFileName = QStringLiteral("libPanelCommPluginV1.so");
    qint32 pluginTimeout = 15000;
    IPanelCommInterface *iPlugin = 0;
    QPluginLoader pluginLoader;
    QObject *plugin = 0;
    pluginLoader.setFileName( pluginsDir.absoluteFilePath( pluginFileName ) );
    plugin = pluginLoader.instance();
    if ( plugin ) {
        iPlugin = qobject_cast<IPanelCommInterface*>(plugin);
        if ( iPlugin ) {
            //! load sites data
            QList<QStringList> sitesData;
            if(!dbMan->getSitesData(sitesData)) {
                QLog_Error("Server", QString(Q_FUNC_INFO) + " Could not load sites data from database");
                return false;
            }
            iPlugin->loadSitesData(sitesData);
            //! forward new message level up to message manager
            connect(iPlugin->qObjectPtr(),SIGNAL(newMessage(int,int,QString)),this,SIGNAL(newMessage(int,int,QString)));
            //! init and start communication
            iPlugin->start(networkPort, pluginTimeout);
            //! add plugin to plugins list
            iPlugins.insert(pluginFileName,iPlugin);
            currentPlugin = iPlugin;
        }
        else {
            QLog_Error("Server", QString(Q_FUNC_INFO) + QString("Could not get plugin interface: %1").arg(pluginFileName));
            return false;
        }
    }
    else {
        QLog_Error("Server", QString(Q_FUNC_INFO) + QString(" Could not load plugin: %1").arg(pluginFileName));
        return false;
    }
    return true;
}

void PanelCommPluginManager::onSetSiteTemperature(int siteId, int acNumber, int siteTemperature)
{
    currentPlugin->performSetTempCommand(siteId,acNumber, siteTemperature);
}

void PanelCommPluginManager::onSiteOpenDoor(int siteId)
{
    currentPlugin->performOpenDoorCommand(siteId);
}

void PanelCommPluginManager::onSiteSetSirenState(int siteId, bool enable)
{
    currentPlugin->performSetSirenStateCommand(siteId,enable);
}

void PanelCommPluginManager::onSiteSetACPowerState(int siteId, int acNumber, bool enable)
{
    currentPlugin->performSetACPowerStateCommand(siteId, acNumber, enable);
}

void PanelCommPluginManager::onSiteSetPowerState(int siteId, int powerNumber, bool enable)
{
    currentPlugin->performSetPowerStateCommand(siteId, powerNumber,enable);
}

void PanelCommPluginManager::onSiteGetTempr(int siteId)
{
    currentPlugin->performQueryTemprCommand(siteId);
}
