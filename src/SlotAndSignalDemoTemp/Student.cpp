#include "Student.h"
#include <QDebug>

Student::Student(QObject *parent)
	: QObject(parent)
{

}

Student::~Student()
{

}

void Student::slot1()
{
	for (int i = 0; i < 100; i++)
	{
		qDebug() << "student slot" + QString::number(i);
	}
}
