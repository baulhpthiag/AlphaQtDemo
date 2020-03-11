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
