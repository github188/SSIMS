#ifndef DBWORKER_H
#define DBWORKER_H
#include <QtCore>
#include <QList>
#include <QSqlQueryModel>

class DatabaseManager : public QObject
{    
    Q_OBJECT
public:
    DatabaseManager();
    const QString &getLastError() const;
    void setConnectionName(const QString& connectionName);
    void setHostName(const QString& hostName);
    void setDatabaseName(const QString& dbName);
    void setUserName(const QString& userName);
    void setPassword(const QString& userPassword);
    void setPort(quint16 port);
    bool openConnection();
    bool getSitesData(QList<QStringList> &sData);
    bool regAlert(qint32 siteId, qint32 alertId, const QString &state,
                  const QString &curVideoDir, QString &vUrl, QString &dvrIp, qint32 &flags);
signals:
public slots:
    void closeConnection();
private:
    QString connectionName;
    QString hostName;
    QString dbName;
    QString userPassword;
    QString userName;
    QString lastError;
    quint16 port;
};

#endif // DBWORKER_H
