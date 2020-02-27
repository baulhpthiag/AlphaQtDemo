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


	//����
private:
	QVBoxLayout * bottomWidgetLayout;
	QList<QWidget *> demoWidgets;

	//����
private:
	void init();
	void initMember();

	//�¼�


	//qt��
protected slots:
	void comboBoxCurrentIndexChanged();

	//qt�ź�


};
