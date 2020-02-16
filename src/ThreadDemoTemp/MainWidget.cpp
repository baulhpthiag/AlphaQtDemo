#include "MainWidget.h"
#include <thread>
#include <QThread>
#include "AlphaThread0.h"

MainWidget::MainWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	init(); 
}

MainWidget::~MainWidget()
{
	
}


void MainWidget::init()
{
	ui.comboBox->addItem("thread0");
	ui.comboBox->addItem("thread1");
}

void MainWidget::stdThreadAWork(MainWidget * sender)
{
	sender->ui.textBrowser->append("stdThread a work");
}

void MainWidget::stdThreadBWork(MainWidget * sender)
{
	sender->ui.textBrowser->append("stdThread b work");
}

void MainWidget::appendMessage(QString message)
{
	ui.textBrowser->append(message);
}

void MainWidget::work(QString threadName)
{
	appendMessage("�߳�"+threadName+"������");
}

void MainWidget::comboBoxCurrentIndexChanged()
{
	QString s;
}

void MainWidget::clickStartButton()
{
	//method01();
	method02();
	//bugMethod01();
	//bugMethod02();

}

void MainWidget::clickThreadAHoverButton()
{
	alphaThread1A->pause();
}

void MainWidget::clickThreadAStopButton()
{
	alphaThread1A->finish();
}

void MainWidget::bugMethod01()
{
	//alpha todo ʹ��std::thread ����bug
	ui.textBrowser->append("program start");

	std::thread threadA(&MainWidget::stdThreadAWork, this, this);
	//std::thread threadB(&QThreadDemo::threadBWork,this,this);
}



void MainWidget::method01()
{
	if (NULL != alphaThread0A)
	{
		delete alphaThread0A;
		alphaThread0A = NULL;
	}
	alphaThread0A = new AlphaThread0;
	alphaThread0A->setSource(this);
	alphaThread0A->setName("�߳�0A");
	alphaThread0A->start();
}

void MainWidget::method02()
{
	alphaThread1A = new AlphaThread1;
	alphaThread1A->setObjectName("�߳�1A");
	connect(alphaThread1A, SIGNAL(workSignal(QString)), this, SLOT(work(QString)));
	alphaThread1A->start();

	alphaThread1B = new AlphaThread1;
	alphaThread1B->setObjectName("�߳�1B");
	connect(alphaThread1B, SIGNAL(workSignal(QString)), this, SLOT(work(QString)));
	alphaThread1B->start();


}

void MainWidget::bugMethod02()
{
	//���������߳�ͬʱ�������̵߳Ŀؼ�

	//alpha todo bug
	if (NULL!=alphaThread0A)
	{
		delete alphaThread0A;
		alphaThread0A = NULL;
	}
	if (NULL != alphaThread0B)
	{
		delete alphaThread0B;
		alphaThread0B = NULL;
	}
	alphaThread0A = new AlphaThread0;
	alphaThread0A->setSource(this);
	alphaThread0A->setName("�߳�0A");

	alphaThread0B = new AlphaThread0;
	alphaThread0B->setSource(this);
	alphaThread0B->setName("�߳�0B");

	alphaThread0A->start();

	alphaThread0B->start();
}

