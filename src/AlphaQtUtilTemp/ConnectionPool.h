#ifndef CONNECTIONPOOL_H
#define CONNECTIONPOOL_H

#include <QString>
#include <QtSql>

#include "Singleton.h"

class QSqlDatabase;
class ConnectionPoolPrivate;

class ConnectionPool {
    SINGLETON(ConnectionPool)

public:

    QSqlDatabase openConnection(const QString &connectionName = QString());

private:
    QSqlDatabase createConnection(const QString &connectionName); 
    ConnectionPoolPrivate *d;
};

#endif // CONNECTIONPOOL_H
