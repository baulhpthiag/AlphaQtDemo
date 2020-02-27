#pragma once

#include <QWidget>
#include "ui_ThreadDemo01Widget.h"
#include "Controller01.h"


class ThreadDemo01Widget : public QWidget
{
	Q_OBJECT

public:
	ThreadDemo01Widget(QWidget *parent = Q_NULLPTR);
	~ThreadDemo01Widget();

private:
	Ui::ThreadDemo01Widget ui;

	//属性
private:
	Controller01 controller01;

	//方法
private:
	void init();
	void initMember();

	//事件

	//qt槽
protected slots:
	void startThreadButtonClicked();
	void finishThreadButtonClicked();
	//qt信号
};
