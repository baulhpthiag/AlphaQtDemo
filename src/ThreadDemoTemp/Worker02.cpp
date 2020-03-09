#include "Worker02.h"
#include <QThread>
#include <QDebug>

Worker02::Worker02(QObject *parent)
	: QObject(parent)
{
}

Worker02::~Worker02()
{
}

void Worker02::start(Producer* p)
{
	while (p->count>0)
	{
		QThread::msleep(10);
		p->count--;
		qDebug() << ">>>>    "<<QThread::currentThreadId() << "count:" + QString::number(p->count) ;
	}

	emit finish();
}
