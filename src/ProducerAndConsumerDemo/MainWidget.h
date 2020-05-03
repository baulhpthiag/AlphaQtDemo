#pragma once

#include <QtWidgets/QWidget>
#include "ui_MainWidget.h"
#include <QThread>
#include "Consumer.h"
#include "Producer.h"
#include "Product.h"

class MainWidget : public QWidget
{
	Q_OBJECT

public:
	MainWidget(QWidget *parent = Q_NULLPTR);
	~MainWidget();
private:
	Ui::MainWidgetClass ui;

	Consumer * consumer;
	Producer * producer;

	QThread consumerThread;
	QThread producerThread;

	bool producerState;

	void init();

	public slots:

	void startButtonClicked();
	void stopButtonClicked();
	void producerMessageChanged(QString message);
	void consumerMessageChanged(QString message);

	void addProduct(Product product);

signals:
	void signalContinueProduce();
	void signalContinueConsume();
	void signalProducerChangeState(bool b);

};
