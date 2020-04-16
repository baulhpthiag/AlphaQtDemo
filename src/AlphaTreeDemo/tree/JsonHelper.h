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
	static bool writeJsonFile(T& t,QString filePath);

	template<class T>
	static bool readJsonFile(T& t,QString filePath);


	static bool objToJsonObj(QJsonObject* jsonObj, QObject *obj);

	static bool jsonObjToObj(QJsonObject* jsonObj, QObject *obj);
};

template<class T>
static bool JsonHelper::writeJsonFile(T& t, QString filePath)
{
	QJsonObject jsonObj;
	QObject *obj = (QObject*)(&t);

	if (!objToJsonObj(&jsonObj, obj))
	{
		return false;
	}

	QJsonDocument jsonDoc;
	jsonDoc.setObject(jsonObj);
	
	QFile file(filePath);
	if (!file.exists())
	{
		file.open(QIODevice::WriteOnly);
	}
	file.write(jsonDoc.toJson());
	file.close();

	return true;
}

template<typename T>
bool JsonHelper::readJsonFile(T& t,QString filePath)
{
	QFile file(filePath);

	if (!file.open(QIODevice::ReadOnly))
	{
		qDebug() << "JsonHelper readJsonFile could't open json "+ filePath;
		return false;
	}

	QByteArray data = file.readAll();
	file.close();

	QJsonParseError jsonParseError;
	QJsonDocument jsonDoc(QJsonDocument::fromJson(data, &jsonParseError));

	if (jsonParseError.error != QJsonParseError::NoError)
	{
		qDebug() << "JsonHelper readJsonFile json parse error " + filePath;
		return false;
	}

	QJsonObject jsonObj = jsonDoc.object();

	QObject *obj = (QObject*)(&t);

	return jsonObjToObj(&jsonObj, obj);
}


