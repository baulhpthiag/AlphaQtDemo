#pragma once

#include <QtWidgets/QWidget>
#include "ui_ThreadDemoMainWidget.h"
#include <QVBoxLayout>

class ThreadDemoMainWidget : public QWidget
{
	Q_OBJECT

public:
	ThreadDemoMainWidget(QWidget *parent = Q_NULLPTR);
	~ThreadDemoMainWidget();

private:
	Ui::ThreadDemoMainWidgetClass ui;


	//属性
private:
	QVBoxLayout * bottomWidgetLayout;
	QList<QWidget *> demoWidgets;

	//方法
private:
	void init();
	void initMember();

	//事件


	//qt槽
protected slots:
	void comboBoxCurrentIndexChanged();

	//qt信号


};
