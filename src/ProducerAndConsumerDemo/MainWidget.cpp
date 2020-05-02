#include "MainWidget.h"

MainWidget::MainWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	init();
}

void MainWidget::init()
{
	consumer = new Consumer;
	consumer->moveToThread(&consumerThread);
	connect(&consumerThread, &QThread::finished, consumer, &Consumer::deleteLater);

	producer = new Producer;
	producer->moveToThread(&producerThread);
	connect(&producerThread, &QThread::finished, producer, &Producer::deleteLater);

}

void MainWidget::startButtonClicked()
{

}

void MainWidget::stopButtonClicked()
{

}
