#pragma once

#include <QtWidgets/QWidget>
#include "ui_MainWidget.h"
#include "TestParentConfig.h"

class MainWidget : public QWidget
{
	Q_OBJECT

public:
	MainWidget(QWidget *parent = Q_NULLPTR);

private:
	Ui::MainWidgetClass ui;

	TestParentConfig testConfig;

	public slots:
	void openProgramDirButtonClicked();
	void writeJsonButtonClicked();
	void readJsonButtonClicked();
	void createTreeButtonClicked();
	void saveTreeButtonClicked();

};
