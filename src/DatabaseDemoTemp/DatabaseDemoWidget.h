#pragma once


#include <QtWidgets/QWidget>
#include "ui_DatabaseDemoWidget.h"
#include <QtWidgets/QVBoxLayout>
#include "DatabaseDemo01Widget.h"
#include "DatabaseDemo02Widget.h"

class DatabaseDemoWidget : public QWidget
{
	Q_OBJECT

public:
	DatabaseDemoWidget(QWidget *parent = Q_NULLPTR);

private:
	Ui::DatabaseDemoWidgetClass ui;

	//属性
private:
	QVBoxLayout * bottomWidgetLayout = NULL;
	DatabaseDemo01Widget * databaseDemo01Widget = NULL;
	DatabaseDemo02Widget * databaseDemo02Widget = NULL;

	//方法
private:
	void init();




	//事件

	//qt槽
	protected slots :
		void comboBoxCurrentIndexChanged();
	//qt信号


};
