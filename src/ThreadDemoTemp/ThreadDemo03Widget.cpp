#include "ThreadDemo03Widget.h"
#include <QtConcurrent/QtConcurrent>
#include <QDebug>

ThreadDemo03Widget::ThreadDemo03Widget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

ThreadDemo03Widget::~ThreadDemo03Widget()
{

}

void ThreadDemo03Widget::test01ButtonClicked()
{
	qDebug() << ">> main thread threadId:" << QThread::currentThreadId();
	QFuture<void> future = QtConcurrent::run(
		[=]() {
		qDebug() << ">> QtConcurrent thread begin threadId:" << QThread::currentThreadId();
		for (int i = 0; i < 10; i++)
		{
			qDebug() << ">> QtConcurrent thread sleep 1 time " + QString::number(i);
			QThread::sleep(1);
		}
		qDebug() << ">> QtConcurrent thread end";

	});

	qDebug() << ">> main thread continue work";
	for (int i = 0; i < 10; i++)
	{
		qDebug() << ">> main thread sleep 1 time " + QString::number(i);
		QThread::sleep(1);
	}


}
