#include "Student.h"
#include <QDebug>

Student::Student(QObject *parent)
	: QObject(parent)
{
	qDebug() << this << "create";
}

Student::~Student()
{
	qDebug() << this << name + " destroy";
}
