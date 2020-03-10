#pragma once

#include <QtWidgets/QWidget>
#include "ui_LambdaDemoTempWidget.h"

class LambdaDemoTempWidget : public QWidget
{
	Q_OBJECT

public:
	LambdaDemoTempWidget(QWidget *parent = Q_NULLPTR);

private:
	Ui::LambdaDemoTempWidgetClass ui;


	//属性

	//方法

	//事件

	//qt槽
public slots:
	void test01ButtonClicked();
	//qt信号

};
