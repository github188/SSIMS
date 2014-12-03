#include "panelcommpluginv1.h"
#include <iostream>
#include "../SIMS_SERVER/logger/Logger.h"
using namespace QLogger;
using std::cout;
using std:: endl;


PanelCommPluginV1::PanelCommPluginV1(): netServer(0), netThread(0)
{
    netServer = new NetworkServer();
    netThread = new QThread(this);
}

PanelCommPluginV1::~PanelCommPluginV1()
{
    if(netThread->isRunning()) {
        netThread->quit();
        netThread->wait();
    }
    //! netThread will be deleted by its parent - plugin
    //! netServer will be deleted later when thread finished
}

void PanelCommPluginV1::loadSitesData(const QList<QStringList> &sData)
{
    netServer->loadSiteData(sData);
}

void PanelCommPluginV1::start(int port, int timeout)
{
    cout << "start communication with panels, port: " << port << endl;
    netServer->setInitData(port, timeout);
    //! moving net server to it thread
    netServer->moveToThread(netThread);
    //! connect thread start with network start
    connect(netThread, SIGNAL(started()), netServer, SLOT(startCommunication()));
    //! error in network connection
    connect(netServer, SIGNAL(error(QString)), this, SIGNAL(error(QString)));
    //! new message from panel
    connect(netServer, SIGNAL(newMessage(int,int,QString)), this, SIGNAL(newMessage(int,int,QString)));
    //! send message to panel
    connect(this,SIGNAL(sendMessage(int,int,QString)),netServer,SLOT(sendMessageToSite(int,int,QString)));
    //! connect thread finish signal with delete netserver slot
    connect(netThread, SIGNAL(finished()), netServer, SLOT(deleteLater()));
    //! start thread
    netThread->start();
}

void PanelCommPluginV1::stop()
{
    cout << "stop communication with panels" << endl;
    if(netThread->isRunning()) {
        netThread->quit();
        cout << "waiting for thread to be finished" << endl;
        netThread->wait();
        cout << "network thread finished" << endl;
    }
}

void PanelCommPluginV1::performOpenDoorCommand(int siteId)
{
    cout << "perform open door command" << endl;
    int alert = 9;
    QString state = QStringLiteral("Open");
    emit sendMessage(siteId, alert, state);
}

void PanelCommPluginV1::performSetTempCommand(int siteId, int acNumber, int siteTemp)
{
    cout << "perform set temp command" << endl;
    if(siteTemp > 32 || siteTemp < 16) {
        cout << "Temperature is out of range [16..32], temperature:" << siteTemp << endl;
        return;
    }
    if(acNumber < 1 || acNumber > 2) {
        cout << "A/C number is out of range [1..2], number:" << acNumber << endl;
        return;
    }
    int alert = 13;
    QString state;
    if(acNumber == 1) state = QString("Ac1_T.(%1)").arg(QString::number(siteTemp));
    if(acNumber == 2) state = QString("Ac2_T.(%1)").arg(QString::number(siteTemp));
    emit sendMessage(siteId, alert, state);
}

void PanelCommPluginV1::performSetSirenStateCommand(int siteId, bool enable)
{
    cout << "perform set siren command" << endl;
    int alert = 11;
    QString state="Off";
    if(enable)
        state = "On";
    emit sendMessage(siteId,alert,state);
}

void PanelCommPluginV1::performSetACPowerStateCommand(int siteId, int acNumber, bool enabled)
{
    cout << "perform set ac command" << endl;
    if(acNumber < 1 || acNumber > 2) {
        cout << "A/C number is out of range [1..2], number:" << acNumber << endl;
        return;
    }
    int alert = 13;
    QString state;
    if(acNumber == 1) state = QString("Ac1_");
    if(acNumber == 2) state = QString("Ac2_");
    if(enabled) {
        state += "On";
    }
    else {
        state += "Off";
    }
    emit sendMessage(siteId,alert,state);
}

void PanelCommPluginV1::performSetPowerStateCommand(int siteId, int powerNumber, bool enabled)
{
    cout << "perform power command" << endl;
    if(powerNumber < 1 || powerNumber > 4) {
        cout << "Power number is out of range [1..4], number:" << powerNumber << endl;
        return;
    }
    int alert = 15;
    QString state = QString("P%1_").arg(QString::number(powerNumber));
    if(enabled) {
        state += "On";
    }
    else {
        state += "Off";
    }
    emit sendMessage(siteId,alert,state);
}

void PanelCommPluginV1::performQueryTemprCommand(int siteId)
{
    cout << "perform query tempr" << endl;
    qint32 alert = 8;
    QString state = "Wt";
    emit sendMessage(siteId,alert,state);
}

QObject *PanelCommPluginV1::qObjectPtr()
{
    return this;
}
