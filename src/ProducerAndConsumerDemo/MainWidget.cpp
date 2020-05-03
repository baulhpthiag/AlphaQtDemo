#include "MainWidget.h"
#include <QDebug>

MainWidget::MainWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	init();
	producerState = true;

}
MainWidget::~MainWidget()
{
	producer->continueFlag = false;
	consumer->continueFlag = false;

	producerThread.quit();
	producerThread.wait();
	consumerThread.quit();
	consumerThread.wait();
}

void MainWidget::init()
{
	consumer = new Consumer;
	consumer->moveToThread(&consumerThread);
	connect(&consumerThread, &QThread::finished, consumer, &Consumer::deleteLater);

	producer = new Producer;
	producer->moveToThread(&producerThread);
	connect(&producerThread, &QThread::finished, producer, &Producer::deleteLater);

	//connect(producer, &Producer::signalProduceProduct, this, &MainWidget::addProduct);
	connect(producer, &Producer::signalProduceProduct, consumer, &Consumer::signalConsume);


	connect(producer, &Producer::signalMessageChanged, this, &MainWidget::producerMessageChanged);
	connect(consumer, &Consumer::signalMessageChanged, this, &MainWidget::consumerMessageChanged);

	connect(this, &MainWidget::signalContinueProduce, producer, &Producer::continueProduce);
	connect(this, &MainWidget::signalContinueConsume, consumer, &Consumer::continueConsume);


	producerThread.start();
	consumerThread.start();

	producer->continueFlag = true;
	emit signalContinueProduce();

	//consumer->continueFlag = true;
	//emit signalContinueConsume();
}

void MainWidget::startButtonClicked()
{
	producer->produceFlag = true;
}

void MainWidget::stopButtonClicked()
{
	producer->produceFlag = false;
}

void MainWidget::producerMessageChanged(QString message)
{
	ui.producerTextBrowser->append(message);
}

void MainWidget::consumerMessageChanged(QString message)
{
	ui.consumerTextBrowser->append(message);
}

void MainWidget::addProduct(Product product)
{
	consumer->products.append(product);
}
