#pragma once

#include <QObject>
#include <QDateTime>

class DateTimeHelper : public QObject
{
	Q_OBJECT

public:
	DateTimeHelper(QObject *parent);
	~DateTimeHelper();

	static QString elapsedTime(QDateTime stopTime, QDateTime startTime);
	static QString currentTime();
};
