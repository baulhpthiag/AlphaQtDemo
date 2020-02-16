#include "ConnectionPool.h"
#include "Config.h"

#include <QDebug>
#include <QString>
#include <QThread>
#include <QCoreApplication>


class ConnectionPoolPrivate {
public:
    ConnectionPoolPrivate();


    QString hostName;
    QString databaseName;
    QString username;
    QString password;
    QString databaseType;
    int     port;

    bool    testOnBorrow;    
    QString testOnBorrowSql; 
};

ConnectionPoolPrivate::ConnectionPoolPrivate() {
    Config &config = Singleton<Config>::getInstance();


    hostName        = config.getDatabaseHost();
    databaseName    = config.getDatabaseName();
    username        = config.getDatabaseUsername();
    password        = config.getDatabasePassword();
    databaseType    = config.getDatabaseType();
    port            = config.getDatabasePort();
    testOnBorrow    = config.getDatabaseTestOnBorrow();
    testOnBorrowSql = config.getDatabaseTestOnBorrowSql();
}


ConnectionPool::ConnectionPool() : d(new ConnectionPoolPrivate) {
}

ConnectionPool::~ConnectionPool() {
    delete d;
}


QSqlDatabase ConnectionPool::openConnection(const QString &connectionName) {

    QString baseConnectionName = "conn_" + QString::number(quint64(QThread::currentThread()), 16);
    QString fullConnectionName = baseConnectionName + connectionName;

    if (QSqlDatabase::contains(fullConnectionName)) {

        QSqlDatabase existingDb = QSqlDatabase::database(fullConnectionName);

        if (d->testOnBorrow) {

            qDebug().noquote() << QString("Test connection on borrow, execute: %1, for connection %2")
                                  .arg(d->testOnBorrowSql).arg(fullConnectionName);
            QSqlQuery query(d->testOnBorrowSql, existingDb);

            if (query.lastError().type() != QSqlError::NoError && !existingDb.open()) {
                qDebug().noquote() << "Open datatabase error:" << existingDb.lastError().text();
                return QSqlDatabase();
            }
        }

        return existingDb;
    } else {

        if (qApp != nullptr) {

            QObject::connect(QThread::currentThread(), &QThread::finished, qApp, [fullConnectionName] {
                if (QSqlDatabase::contains(fullConnectionName)) {
                    QSqlDatabase::removeDatabase(fullConnectionName);
                    qDebug().noquote() << QString("Connection deleted: %1").arg(fullConnectionName);
                }
            });
        }

        return createConnection(fullConnectionName);
    }
}


QSqlDatabase ConnectionPool::createConnection(const QString &connectionName) {
    static int sn = 0;


    QSqlDatabase db = QSqlDatabase::addDatabase(d->databaseType, connectionName);
    db.setHostName(d->hostName);
    db.setDatabaseName(d->databaseName);
    db.setUserName(d->username);
    db.setPassword(d->password);

    if (d->port != 0) {
        db.setPort(d->port);
    }

    if (db.open()) {
        qDebug().noquote() << QString("Connection created: %1, sn: %2").arg(connectionName).arg(++sn);
        return db;
    } else {
        qDebug().noquote() << "Create connection error:" << db.lastError().text();
        return QSqlDatabase();
    }
}

