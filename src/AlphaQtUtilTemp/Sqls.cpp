#include "Sqls.h"
#include "Config.h"

#include <QFile>
#include <QDebug>
#include <QXmlInputSource>
#include <QXmlAttributes>
#include <QXmlParseException>
#include <QXmlDefaultHandler>


static const char * const SQL_ID                 = "id";
static const char * const SQL_INCLUDED_DEFINE_ID = "defineId";
static const char * const SQL_TAGNAME_SQL        = "sql";
static const char * const SQL_TAGNAME_SQLS       = "sqls";
static const char * const SQL_TAGNAME_DEFINE     = "define";
static const char * const SQL_TAGNAME_INCLUDE    = "include";
static const char * const SQL_NAMESPACE          = "namespace";


class SqlsPrivate : public QXmlDefaultHandler {
public:
    SqlsPrivate(Sqls *context);
    static QString buildKey(const QString &sqlNamespace, const QString &id);

protected:
    bool startElement(const QString &namespaceURI,
                      const QString &localName,
                      const QString &qName,
                      const QXmlAttributes &attributes);
    bool endElement(const QString &namespaceURI, const QString &localName, const QString &qName);
    bool characters(const QString &str);
    bool fatalError(const QXmlParseException &exception);

private:
    QHash<QString, QString> defines;
    QString sqlNamespace;
    QString currentText;
    QString currentSqlId;
    QString currentDefineId;
    QString currentIncludedDefineId;

    Sqls *context;
};

SqlsPrivate::SqlsPrivate(Sqls *context) : context(context) {
    QStringList sqlFiles = Config::instance().getDatabaseSqlFiles();

    foreach (QString fileName, sqlFiles) {
        qDebug() << QString("Loading SQL file: %1").arg(fileName);

        QFile file(fileName);
        QXmlInputSource inputSource(&file);
        QXmlSimpleReader reader;
        reader.setContentHandler(this);
        reader.setErrorHandler(this);
        reader.parse(inputSource);

        defines.clear();
    }
}

QString SqlsPrivate::buildKey(const QString &sqlNamespace, const QString &id) {
    return sqlNamespace + "::" + id;
}

bool SqlsPrivate::startElement(const QString &namespaceURI,
                               const QString &localName,
                               const QString &qName,
                               const QXmlAttributes &attributes) {
    Q_UNUSED(namespaceURI)
    Q_UNUSED(localName)


    if (SQL_TAGNAME_SQL == qName) {
        currentSqlId = attributes.value(SQL_ID);
        currentText = "";
    } else if (SQL_TAGNAME_INCLUDE == qName) {
        currentIncludedDefineId = attributes.value(SQL_INCLUDED_DEFINE_ID);
    } else if (SQL_TAGNAME_DEFINE == qName) {
        currentDefineId = attributes.value(SQL_ID);
        currentText = "";
    } else if (SQL_TAGNAME_SQLS == qName) {
        sqlNamespace = attributes.value(SQL_NAMESPACE);
    }

    return true;
}

bool SqlsPrivate::endElement(const QString &namespaceURI, const QString &localName, const QString &qName) {
    Q_UNUSED(namespaceURI)
    Q_UNUSED(localName)


    if (SQL_TAGNAME_SQL == qName) {

        context->sqls.insert(buildKey(sqlNamespace, currentSqlId), currentText.simplified());
        currentText = "";
    } else if (SQL_TAGNAME_INCLUDE == qName) {
        QString defKey = buildKey(sqlNamespace, currentIncludedDefineId);
        QString def    = defines.value(defKey);

        if (!def.isEmpty()) {
            currentText += def;
        } else {
            qDebug() << "Cannot find define: " << defKey;
        }
    } else if (SQL_TAGNAME_DEFINE == qName) {
        defines.insert(buildKey(sqlNamespace, currentDefineId), currentText.simplified());
    }

    return true;
}

bool SqlsPrivate::characters(const QString &str) {
    currentText += str;
    return true;
}

bool SqlsPrivate::fatalError(const QXmlParseException &exception) {
    qDebug() << QString("Parse error at line %1, column %2, message: %3")
                .arg(exception.lineNumber())
                .arg(exception.columnNumber())
                .arg(exception.message());
    return false;
}


Sqls::Sqls() {
    SqlsPrivate(this); 
}

Sqls::~Sqls() {
}

QString Sqls::getSql(const QString &sqlNamespace, const QString &sqlId) {
    QString sql = sqls.value(SqlsPrivate::buildKey(sqlNamespace, sqlId));

    if (sql.isEmpty()) {
        qDebug() << QString("Cannot find SQL for %1::%2").arg(sqlNamespace).arg(sqlId);
    }

    return sql;
}
