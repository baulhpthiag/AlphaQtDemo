#include "Producer.h"
#include <QThread>
#include <QDebug>
#include <QUuid>

Producer::Producer(QObject *parent)
	: QObject(parent)
{
	data = 0;
	continueFlag = false;
	produceFlag = false;
	interval = 2;
}

Producer::~Producer()
{
}

void Producer::continueProduce()
{
	while (continueFlag)
	{
		if (produceFlag)
		{
			QThread::sleep(interval);
			Product product;
			product._productId = QUuid::createUuid().toString();
			product._data = data;
			emit signalMessageChanged(u8"producer生产了一个product:"+product.toString());
			emit signalProduceProduct(product);
			data++;
		}

	}
}


