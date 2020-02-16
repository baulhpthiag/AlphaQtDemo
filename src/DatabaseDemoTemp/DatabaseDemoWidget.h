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

	//����
private:
	QVBoxLayout * bottomWidgetLayout = NULL;
	DatabaseDemo01Widget * databaseDemo01Widget = NULL;
	DatabaseDemo02Widget * databaseDemo02Widget = NULL;

	//����
private:
	void init();




	//�¼�

	//qt��
	protected slots :
		void comboBoxCurrentIndexChanged();
	//qt�ź�


};
