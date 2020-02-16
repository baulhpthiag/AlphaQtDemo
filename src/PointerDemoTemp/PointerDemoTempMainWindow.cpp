#include "PointerDemoTempMainWindow.h"
#include <QDebug>

PointerDemoTempMainWindow::PointerDemoTempMainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	init();
}

PointerDemoTempMainWindow::~PointerDemoTempMainWindow()
{
	delete student1;
	
}

void PointerDemoTempMainWindow::init()
{
	test01();
}

void PointerDemoTempMainWindow::test01()
{
	student1 = new Student;
	student1->name = "student1";
	qDebug() << "------";

	Student *student2 = new Student;
	student2->name = "student2";
	QSharedPointer<Student> ptr(student2);
	sharedPointer1 = ptr;
	qDebug() << "------";

}

void PointerDemoTempMainWindow::test02()
{
	Student *student2 = new Student;
	student2->name = "student2";
	QSharedPointer<Student> ptr(student2);
	sharedPointer1 = ptr;
	qDebug() << "------";
	delete student2;
	student2 = nullptr;

	qDebug() << "------";
}

void PointerDemoTempMainWindow::test03()
{
	Student studentC;
	studentC.name = "student3";
	QSharedPointer<Student> ptr2(&studentC);
	sharedPointer2 = ptr2;
}
