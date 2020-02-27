#include "Worker01.h"
#include <QDebug>
#include <QThread>

Worker01::Worker01(QObject *parent)
	: QObject(parent)
{

}

Worker01::~Worker01()
{

}



void Worker01::work()
{
	qDebug() << "work() begin";
	qDebug() << "currentThreadId :" << QThread::currentThreadId();
	qDebug() << "work() end";
	emit workFinish("work finish");
}

