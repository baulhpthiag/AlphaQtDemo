#include "Producer.h"
#include <QThread>

Producer::Producer(QObject *parent)
	: QObject(parent)
{
	product = 0;
}

Producer::~Producer()
{
}

void Producer::produce()
{
	while (true)
	{
		if (runFlag)
		{
			QThread::msleep(100);
			emit signalSendMessage(u8"producer生产了一个product:"+QString::number(product));
			emit signalProduceProduct(product);
			product++;
		}

	}
}

void Producer::changeState(bool b)
{
	runFlag = b;
}
