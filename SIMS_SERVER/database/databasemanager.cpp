#include "databasemanager.h"
#include <QtSql>
#include <iostream>
#include "logger/Logger.h"
using namespace QLogger;
using std::cout;
using std::endl;

DatabaseManager::DatabaseManager()
{
}

const QString& DatabaseManager::getLastError() const
{
    return lastError;
}

void DatabaseManager::setConnectionName(const QString &dbConnectionName)
{
    connectionName = dbConnectionName;
}

void DatabaseManager::setHostName(const QString &dbHostName)
{
    hostName = dbHostName;
}

void DatabaseManager::setDatabaseName(const QString &name)
{
    dbName = name;
}

void DatabaseManager::setUserName(const QString &dbUserName)
{
    userName = dbUserName;
}

void DatabaseManager::setPassword(const QString &dbUserPassword)
{
    userPassword = dbUserPassword;
}

void DatabaseManager::setPort(quint16 dbPort)
{
    port = dbPort;
}

bool DatabaseManager::openConnection()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL", connectionName);
    db.setHostName(hostName);
    db.setDatabaseName(dbName);
    db.setUserName(userName);
    db.setPassword(userPassword);
    if(!db.open()) {
        QLog_Error("Server", QString("%1 %2").arg(Q_FUNC_INFO).arg(db.lastError().text()));
        return false;
    }
    return true;
}

bool DatabaseManager::getSitesData(QList<QStringList> &sData)
{
    lastError = QStringLiteral("");
    QSqlDatabase db = QSqlDatabase::database(connectionName);
    QSqlQuery query(db);
    bool result = query.exec("SELECT site_id, ip, dvr_ip FROM public.\"activeSitesServerData_view\";");
    if(result) {
        while(query.next()) {
            QStringList siteData;
            siteData << query.value(0).toString();
            siteData << query.value(1).toString();
            siteData << query.value(2).toString();
            sData << siteData;
        }
        return true;
    }
    else {
        QLog_Error("Server", QString("%1 %2").arg(Q_FUNC_INFO).arg(query.lastError().text()));
        return false;
    }
}

bool DatabaseManager::regAlert(qint32 siteId, qint32 alertId, const QString &state,
                               const QString &curVideoDir, QString &vUrl, QString &dvrIp, qint32& flags)
{
    lastError = QStringLiteral("");
    QSqlDatabase db = QSqlDatabase::database(connectionName);
    QSqlQuery query(db);
    query.prepare("SELECT \"videoUrl\", \"streamPath\", \"flags\" FROM public.\"regAlert\"(?,?,?,?);");
    query.addBindValue(alertId);
    query.addBindValue(siteId);
    query.addBindValue(state);
    query.addBindValue(curVideoDir);
    if(!query.exec()) {
        QLog_Error("Server", QString("%1 %2").arg(Q_FUNC_INFO).arg(query.lastError().text()));
        cout << query.lastError().text().toLocal8Bit().data() << endl;
        return false;
    }
    else {
        if(query.first()) {
            vUrl = query.value(0).toString();
            dvrIp = query.value(1).toString();
            flags = query.value(2).toInt();
            return true;
        }
        QLog_Error("Server", QString("%1 %2").arg(Q_FUNC_INFO).arg("Could not get return values from regAlert"));
        return false;
    }
}

void DatabaseManager::closeConnection()
{
    QSqlDatabase::database(connectionName).close();
    QSqlDatabase::removeDatabase(connectionName);
}
