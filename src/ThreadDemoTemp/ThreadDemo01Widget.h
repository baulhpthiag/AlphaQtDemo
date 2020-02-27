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

	//����
private:
	Controller01 controller01;

	//����
private:
	void init();
	void initMember();

	//�¼�

	//qt��
protected slots:
	void startThreadButtonClicked();
	void finishThreadButtonClicked();
	//qt�ź�
};
