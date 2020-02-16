#pragma once

#include <QObject>
#include <QDateTime>

struct ProductType 
{
	QString TypeId;
	QString TypeName;
	QDateTime CreateDatetime;
};

struct DetectLog
{
	QString LogId;
	int OkCount;
	int NgCount;
	int NullCount;
	QDateTime CreateDatetime;
	QString ProductTypeId;

};



class CommonDataStruct : public QObject
{
	Q_OBJECT

public:
	CommonDataStruct(QObject *parent);
	~CommonDataStruct();
};
