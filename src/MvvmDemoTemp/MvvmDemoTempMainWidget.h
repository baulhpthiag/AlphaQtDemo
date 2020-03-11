#pragma once

#include <QtWidgets/QWidget>
#include "ui_MvvmDemoTempMainWidget.h"
#include "Student.h"

class MvvmDemoTempMainWidget : public QWidget
{
	Q_OBJECT

public:
	MvvmDemoTempMainWidget(QWidget *parent = Q_NULLPTR);

private:
	Ui::MvvmDemoTempMainWidgetClass ui;
	Student student;
	
	void init();




};
