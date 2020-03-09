#pragma once

#include <QObject>

class Producer : public QObject
{
	Q_OBJECT

public:
	Producer(QObject *parent =nullptr);
	~Producer();

	int count;
};
