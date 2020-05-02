#include "Consumer.h"
#include "QThread"

Consumer::Consumer(QObject *parent)
	: QObject(parent)
{
}

Consumer::~Consumer()
{
}

void Consumer::addProduct(int product)
{
	if (products.count() > 10)
	{
		return;
	}
	products.append(product);
	emit signalSendMessage(u8"�����߽��յ�һ��product:" + QString::number(product) + " ��ǰproducts����:" + QString::number(products.count()));
}

void Consumer::process()
{
	while (true)
	{
		if (products.count() > 0)
		{
			int front = products.first();
			products.pop_front();
			emit signalSendMessage(u8"��ʼ����product:" + QString::number(front));
			QThread::msleep(100);
			emit signalSendMessage(u8"��������product:" + QString::number(front));
		}

	}
}
