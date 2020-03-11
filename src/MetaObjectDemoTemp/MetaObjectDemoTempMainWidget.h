#pragma once

#include <QtWidgets/QWidget>
#include "ui_MetaObjectDemoTempMainWidget.h"
#include "Student.h"

class MetaObjectDemoTempMainWidget : public QWidget
{
	Q_OBJECT

public:
	MetaObjectDemoTempMainWidget(QWidget *parent = Q_NULLPTR);

private:
	Ui::MetaObjectDemoTempMainWidgetClass ui;
	Student student;

public slots:
	void test01ButtonClicked();
	void test02ButtonClicked();
	void test03ButtonClicked();
	void lineEditEditingFInished();
	void slot1();

signals:
	void signalTextEditTextChanged(QString text);
	

};
