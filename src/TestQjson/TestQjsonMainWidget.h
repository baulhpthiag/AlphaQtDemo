#pragma once

#include <QtWidgets/QWidget>
#include "ui_TestQjsonMainWidget.h"

class TestQjsonMainWidget : public QWidget
{
	Q_OBJECT

public:
	TestQjsonMainWidget(QWidget *parent = Q_NULLPTR);

private:
	Ui::TestQjsonMainWidgetClass ui;


	public slots:
	void test01ButtonClicked();
	void test02ButtonClicked();
};
