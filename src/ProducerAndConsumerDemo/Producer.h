#pragma once

#include <QObject>
#include "Product.h"

class Producer : public QObject
{
	Q_OBJECT

public:
	Producer(QObject *parent = nullptr);
	~Producer();
	bool continueFlag;
	bool produceFlag;
	int data;
	int interval;

public slots:
void continueProduce();

signals:
void signalProduceProduct(Product product);
void signalMessageChanged(QString message);
};
