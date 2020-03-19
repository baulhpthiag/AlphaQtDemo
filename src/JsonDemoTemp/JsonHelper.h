#pragma once

#include <QObject>
#include <QMetaProperty>
#include <QDebug>
#include <QJsonObject>
#include <QJsonDocument>
#include <QFile>
#include <QJsonArray>

class JsonHelper : public QObject
{
	Q_OBJECT

public:
	JsonHelper(QObject *parent =nullptr);
	~JsonHelper();

	template<class T>
	static bool saveJson(T& t,QString filePath);

	template<class T>
	static bool readJson(T& t,QString filePath);


	static void insertValue(QJsonObject* jsonObj, QObject *obj);
};

template<class T>
static bool JsonHelper::saveJson(T& t, QString filePath)
{
	QJsonObject *jsonObj = new QJsonObject;
	QObject *obj = (QObject*)(&t);

	insertValue(jsonObj,obj);

	QJsonDocument jsonDoc;
	jsonDoc.setObject(*jsonObj);
	
	QFile file(filePath);
	if (!file.exists())
	{
		file.open(QIODevice::WriteOnly);
	}
	file.write(jsonDoc.toJson());
	file.close();

	return true;

}

template<class T>
bool JsonHelper::readJson(T& t,QString filePath)
{
	QFile loadFile(filePath);

	if (!loadFile.open(QIODevice::ReadOnly))
	{
		qDebug() << "could't open projects json";
		return false;
	}

	QByteArray allData = loadFile.readAll();
	loadFile.close();

	QJsonParseError json_error;
	QJsonDocument jsonDoc(QJsonDocument::fromJson(allData, &json_error));

	if (json_error.error != QJsonParseError::NoError)
	{
		qDebug() << "json error!";
		return false;
	}

	QJsonObject rootObj = jsonDoc.object();



	QObject *obj = (QObject*)(&t);

	const QMetaObject * metaObj = obj->metaObject();

	int count = metaObj->propertyCount();
	int index = metaObj->propertyOffset();
	for (int i = index; i < count; ++i) {

		QMetaProperty metaProperty = metaObj->property(i);
		const char *key = metaProperty.name();
		QString qstringKey = QString::fromUtf8(key);

		QVariant val = obj->property(key);
		const char * typeName = val.typeName();
		QString qstringTypeName = QString::fromUtf8(typeName);

		if ("int" == qstringTypeName)
		{
			obj->setProperty(key, rootObj.value(qstringKey).toInt());
		}
		else if ("double" == qstringTypeName)
		{
			obj->setProperty(key, rootObj.value(qstringKey).toDouble());
		}
		else if ("bool" == qstringTypeName)
		{
			obj->setProperty(key, rootObj.value(qstringKey).toBool());
		}
		else if ("QString" == qstringTypeName)
		{
			obj->setProperty(key, rootObj.value(qstringKey).toString());
		}
		else if (qstringTypeName.contains("QList"))
		{
			//QList<QString> list = val.value<QList<QString>>();

			//QJsonArray jsonArray;
			//for (int i = 0; i < list.count(); i++)
			//{
			//	QString item = (list[i]);
			//	jsonArray.append(item);
			//}
			//jsonObj->insert(qstringKey, jsonArray);
		}
		else
		{
			qDebug() << "undo type " + qstringTypeName;
		}

	}
	

}


