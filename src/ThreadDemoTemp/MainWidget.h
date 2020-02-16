#pragma once
#pragma execution_character_set("utf-8")

#include <QWidget>
#include "ui_MainWidget.h"
#include "AlphaThread0.h"
#include "AlphaThread1.h"

class MainWidget : public QWidget
{
	Q_OBJECT

public:
	MainWidget(QWidget *parent = Q_NULLPTR);
	~MainWidget();

private:
	Ui::MainWidget ui;

	//����
private:
	AlphaThread0 *alphaThread0A = NULL;
	AlphaThread0 *alphaThread0B = NULL;

	AlphaThread1 *alphaThread1A = NULL;
	AlphaThread1 *alphaThread1B = NULL;


	//����
private:
	void init();

public:

	void method01();
	void method02();

	void bugMethod01();
	void bugMethod02();

	void stdThreadAWork(MainWidget * sender);
	void stdThreadBWork(MainWidget * sender);
	void appendMessage(QString message);



	//�¼�

	//qt��
	public slots:
	void comboBoxCurrentIndexChanged();
	void clickStartButton();
	void clickThreadAHoverButton();
	void clickThreadAStopButton();
	void work(QString threadName);

	//qt�ź�
signals:

};
