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


	static void objToJsonObj(QJsonObject* jsonObj, QObject *obj);

	static void jsonObjToObj(QJsonObject* jsonObj, QObject *obj);
};

template<class T>
static bool JsonHelper::writeJsonFile(T& t, QString filePath)
{
	QJsonObject jsonObj;
	QObject *obj = (QObject*)(&t);

	objToJsonObj(&jsonObj,obj);

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

	jsonObjToObj(&rootObj, obj);

}


