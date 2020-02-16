#include "AlphaThread1.h"

AlphaThread1::AlphaThread1(QObject *parent)
	: QThread(parent)
{
}

AlphaThread1::~AlphaThread1()
{
}

void AlphaThread1::init()
{
	
}

void AlphaThread1::run()
{
	while (!finishFlag)
	{
		if (!pauseFlag)
		{
			emit workSignal(this->objectName());
		}
		else
		{
			emit pauseSignal(this->objectName());
		}

		QThread::sleep(1);
	}
	emit finishSignal(this->objectName());
	quit();

}

void AlphaThread1::pause()
{
	pauseFlag = !pauseFlag;
}

void AlphaThread1::finish()
{
	finishFlag = true;
}
