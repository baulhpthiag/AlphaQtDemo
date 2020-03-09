#pragma once

#include <QWidget>
#include "ui_ThreadDemo02Widget.h"
#include "Controller02.h"

class ThreadDemo02Widget : public QWidget
{
	Q_OBJECT

public:
	ThreadDemo02Widget(QWidget *parent = Q_NULLPTR);
	~ThreadDemo02Widget();

private:
	Ui::ThreadDemo02Widget ui;

	//属性
private:
	Controller02 controller;

	//方法
private:
	void init();
	void initMember();

	//事件

	//qt槽
	public slots:
	void test01ButtonClicked();
	void test02ButtonClicked();

	//qt信号

};
