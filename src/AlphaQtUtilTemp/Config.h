#ifndef CONFIG_H
#define CONFIG_H

#include "Singleton.h"

class QString;
class QStringList;
class Json;


class Config {
    SINGLETON(Config)

public:

    QString getDatabaseType() const;            
    QString getDatabaseHost() const;           
    QString getDatabaseName() const;            
    QString getDatabaseUsername() const;        
    QString getDatabasePassword() const;        
    QString getDatabaseTestOnBorrowSql() const; 
    bool getDatabaseTestOnBorrow() const;       
    int  getDatabaseMaxWaitTime() const;        
    int  getDatabaseMaxConnectionCount() const; 
    int  getDatabasePort() const;               
    bool isDatabaseDebug() const;              
    QStringList getDatabaseSqlFiles() const;    


    QStringList getQssFiles() const; 

private:
    Json *json;
};

#endif // CONFIG_H
