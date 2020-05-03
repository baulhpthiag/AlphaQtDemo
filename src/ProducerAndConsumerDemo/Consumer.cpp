#include "Consumer.h"
#include "QThread"
#include <QDebug>

Consumer::Consumer(QObject *parent)
	: QObject(parent)
{
	continueFlag = false;
	consumeFlag = false;
	interval = 5;
}

Consumer::~Consumer()
{
}

void Consumer::continueConsume()
{
	while (continueFlag)
	{
		if (products.count() > 0)
		{
			emit signalMessageChanged(u8"��ǰproduct����:" + QString::number(products.count()));
			Product front = products.first();
			products.pop_front();
			signalConsume(front);
		}

	}
}

void Consumer::signalConsume(Product product)
{
	emit signalMessageChanged(u8"��ʼ����product:" + product.toString());
	QThread::sleep(interval);
	emit signalMessageChanged(u8"��������product:" + product.toString());
}
