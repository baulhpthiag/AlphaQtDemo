#include "DateTimeHelper.h"

DateTimeHelper::DateTimeHelper(QObject *parent)
	: QObject(parent)
{
}

DateTimeHelper::~DateTimeHelper()
{
}

QString DateTimeHelper::elapsedTime(QDateTime stopTime, QDateTime startTime)
{
	return QDateTime::fromMSecsSinceEpoch(stopTime.toMSecsSinceEpoch() - startTime.toMSecsSinceEpoch()).toUTC().toString("hh:mm:ss zzz");
}

QString DateTimeHelper::currentTime()
{
	return QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
}
