#pragma once

#include <QWidget>
#include "ui_ThreadDemo03Widget.h"

class ThreadDemo03Widget : public QWidget
{
	Q_OBJECT

public:
	ThreadDemo03Widget(QWidget *parent = Q_NULLPTR);
	~ThreadDemo03Widget();

private:
	Ui::ThreadDemo03Widget ui;

	//����

	//����

	//�¼�

	//qt��
public slots:
	void test01ButtonClicked();
	//qt�ź�


};
