#include "Controller01.h"
#include <QDebug>

Controller01::Controller01(QObject *parent)
	: QObject(parent)
{
	init();
}

Controller01::~Controller01()
{
	
		thread01.quit();
		thread01.wait();
	
}

void Controller01::init()
{
	initMember();
}

void Controller01::initMember()
{
	qDebug() << "Controller's thread is :" << QThread::currentThreadId();
	qDebug() << "thread01 id is :" << thread01.currentThreadId();

	worker01 = new Worker01;
	worker01->moveToThread(&thread01);

	connect(&thread01, &QThread::finished, worker01, &QObject::deleteLater);
	connect(this, &Controller01::worker01StartWork, worker01, &Worker01::work);
	connect(worker01, &Worker01::workFinish, this, &Controller01::worker01Finish);

	thread01.start();
}

void Controller01::start()
{
	emit worker01StartWork();
}

void Controller01::worker01Finish(QString message)
{
	qDebug() << "controller receive message is :" + message;
}
