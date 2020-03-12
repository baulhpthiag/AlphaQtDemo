#include "SlotAndSignalDemoTempMainWidget.h"
#include "Student.h"
#include <QDebug>
#include <QtConcurrent/QtConcurrent>
#include <QThread>

SlotAndSignalDemoTempMainWidget::SlotAndSignalDemoTempMainWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

void SlotAndSignalDemoTempMainWidget::test01ButtonClicked()
{

		//Qt::AutoConnection	信号槽在同一线程，同Qt::DirectConnection.不在同一线程，同Qt::QueuedConnection.
		//Qt::DirectConnection	发射完信号后立即执行槽，只有槽函数执行完成返回后，发射信号后面的代码才可以执行
		//Qt::QueuedConnection	接收部件所在的线程的事件循环返回后再执行槽，无论槽执行与否，发射信号处后面的代码都会立即执行
		//Qt::BlockingQueuedConnection	类似于Qt::QueuedConnection, 只能用在信号和槽在不同线程的情况下
		//Qt::UniqueConnection	类似Qt::AutoConnection, 但是两个对象间相同的信号与槽只能有唯一关联。在Qt4.6中引入。i.e.在一组对象中，如果相同的信号已经链接到相同的槽函数，再次连接将返回失败。
		//Qt::AutoCompactConnection	类似Qt::AutoConnection, Qt3中的默认类型，在Qt5中已移除



	Student s1;
	connect(this, &SlotAndSignalDemoTempMainWidget::sig1, &s1, &Student::slot1);
	////
	//connect(this, &SlotAndSignalDemoTempMainWidget::sig1, &s1, &Student::slot1, Qt::AutoConnection);

	//发送信号后，stu先执行，完全执行完毕，在执行本方法中emit后面的代码
	connect(this, &SlotAndSignalDemoTempMainWidget::sig1, &s1, &Student::slot1, Qt::DirectConnection);

	//connect(this, &SlotAndSignalDemoTempMainWidget::sig1, &s1, &Student::slot1, Qt::QueuedConnection);

	//connect(this, &SlotAndSignalDemoTempMainWidget::sig1, &s1, &Student::slot1, Qt::BlockingQueuedConnection);
	//connect(this, &SlotAndSignalDemoTempMainWidget::sig1, &s1, &Student::slot1, Qt::UniqueConnection);

	emit sig1();
	for (int i = 0; i < 100; i++)
	{
		qDebug() << "SlotAndSignalDemoTempMainWidget " + QString::number(i);
	}


}

void SlotAndSignalDemoTempMainWidget::test02ButtonClicked()
{
	Student s1;
	connect(this, &SlotAndSignalDemoTempMainWidget::sig1, &s1, &Student::slot1);

	QFuture<void> future = QtConcurrent::run([=, &s1]()
	{
		for (int i; i < 1000; i++)
		{
			QThread::sleep(1);
			qDebug() << QString::number(i);
		};
	});

	emit sig1();
	for (int i = 0; i < 100; i++)
	{
		qDebug() << "SlotAndSignalDemoTempMainWidget " + QString::number(i);
	}


}
