#include "Controller02.h"

Controller02::Controller02(QObject *parent)
	: QObject(parent)
{
	init();
}

Controller02::~Controller02()
{
	if (NULL != p)
	{
		delete p;
		p = NULL;
	}
	threadA.quit();
	threadA.wait();
	threadB.quit();
	threadB.wait();

}

void Controller02::init()
{
	initMember();
}

void Controller02::initMember()
{
	p = NULL;
	workerA = new Worker02();
	workerA->moveToThread(&threadA);

	connect(&threadA,&QThread::finished,workerA,&Worker02::deleteLater);
	connect(this, &Controller02::start, workerA, &Worker02::start);
	connect(workerA, &Worker02::finish, this, &Controller02::finish);

	workerB = new Worker02();
	workerB->moveToThread(&threadB);

	connect(&threadB, &QThread::finished, workerB, &Worker02::deleteLater);
	connect(this, &Controller02::start, workerB, &Worker02::start);
	connect(workerB, &Worker02::finish, this, &Controller02::finish);

	threadA.start();
	threadB.start();
}

void Controller02::finish()
{

}

void Controller02::begin()
{
	if (NULL != p)
	{
		delete p;
	}
	p = new Producer;
	p->count = 100;
	emit start(p);

}
