#include "AlphaThread0.h"
#include "MainWidget.h"

AlphaThread0::AlphaThread0(QObject *parent)
	: QThread(parent)
{

}

AlphaThread0::~AlphaThread0()
{

}

void AlphaThread0::setName(QString name)
{
	this->name = name;
}

void AlphaThread0::run()
{
	if (NULL == threadDemo)
	{
		return;
	}
	MainWidget* ui = static_cast<MainWidget*>(threadDemo);
	while (!stopFlag)
	{
		if (!hoverFlag)
		{
			ui->appendMessage(name + " work");
		}
		else
		{
			//alpha todo ²»sleep»á±¨´í
			ui->appendMessage(name + " hover");
		}
		QThread::sleep(1);

	}
	ui->appendMessage(name + " quit");
	quit();
}

void AlphaThread0::setSource(void* source)
{
	this->threadDemo = source;
}

void AlphaThread0::hoverThread()
{
	hoverFlag = !hoverFlag;
}

void AlphaThread0::stopThread()
{
	stopFlag = true;
}
