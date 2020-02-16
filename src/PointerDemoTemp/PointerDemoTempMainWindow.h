#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_PointerDemoTempMainWindow.h"
#include "Student.h"

class PointerDemoTempMainWindow : public QMainWindow
{
	Q_OBJECT

public:
	PointerDemoTempMainWindow(QWidget *parent = Q_NULLPTR);
	~PointerDemoTempMainWindow();

private:
	Ui::PointerDemoTempMainWindowClass ui;
	

	Student * student1;
	QSharedPointer<Student> sharedPointer1;
	QSharedPointer<Student> sharedPointer2;

	void init();
	void test01();
	void test02();
};
