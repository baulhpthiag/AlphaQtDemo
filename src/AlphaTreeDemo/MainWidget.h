#pragma once

#include <QtWidgets/QWidget>
#include "ui_MainWidget.h"
#include "TestConfig.h"

class MainWidget : public QWidget
{
	Q_OBJECT

public:
	MainWidget(QWidget *parent = Q_NULLPTR);

private:
	Ui::MainWidgetClass ui;

	TestConfig testConfig;

	public slots:
	void writeJsonButtonClicked();
	void readJsonButtonClicked();
	void creatTreeButtonClicked();
	void saveTreeButtonClicked();

};
