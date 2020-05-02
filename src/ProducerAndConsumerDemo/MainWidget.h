#pragma once

#include <QtWidgets/QWidget>
#include "ui_MainWidget.h"
#include <QThread>
#include "Consumer.h"
#include "Producer.h"

class MainWidget : public QWidget
{
	Q_OBJECT

public:
	MainWidget(QWidget *parent = Q_NULLPTR);

private:
	Ui::MainWidgetClass ui;

	Consumer * consumer;
	Producer * producer;

	QThread consumerThread;
	QThread producerThread;

	void init();

	public slots:

	void startButtonClicked();
	void stopButtonClicked();
};
