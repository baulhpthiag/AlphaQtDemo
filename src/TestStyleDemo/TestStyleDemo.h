#pragma once

#include <QtWidgets/QWidget>
#include "ui_TestStyleDemo.h"

class TestStyleDemo : public QWidget
{
	Q_OBJECT

public:
	TestStyleDemo(QWidget *parent = Q_NULLPTR);

private:
	Ui::TestStyleDemoClass ui;

	public slots:
	void loadStyleButtonClicked();
};
