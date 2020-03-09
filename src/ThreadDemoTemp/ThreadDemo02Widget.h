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

	//����
private:
	Controller02 controller;

	//����
private:
	void init();
	void initMember();

	//�¼�

	//qt��
	public slots:
	void test01ButtonClicked();
	void test02ButtonClicked();

	//qt�ź�

};
