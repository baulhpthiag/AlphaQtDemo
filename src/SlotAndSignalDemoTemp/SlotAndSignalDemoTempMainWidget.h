#pragma once

#include <QtWidgets/QWidget>
#include "ui_SlotAndSignalDemoTempMainWidget.h"

class SlotAndSignalDemoTempMainWidget : public QWidget
{
	Q_OBJECT

public:
	SlotAndSignalDemoTempMainWidget(QWidget *parent = Q_NULLPTR);

private:
	Ui::SlotAndSignalDemoTempMainWidgetClass ui;

public slots:
	void test01ButtonClicked();
	void test02ButtonClicked();

signals:
	void sig1();


};
