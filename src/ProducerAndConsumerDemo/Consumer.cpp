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
	emit signalSendMessage(u8"消费者接收到一个product:" + QString::number(product) + " 当前products数量:" + QString::number(products.count()));
}

void Consumer::process()
{
	while (true)
	{
		if (products.count() > 0)
		{
			int front = products.first();
			products.pop_front();
			emit signalSendMessage(u8"开始处理product:" + QString::number(front));
			QThread::msleep(100);
			emit signalSendMessage(u8"结束处理product:" + QString::number(front));
		}

	}
}
