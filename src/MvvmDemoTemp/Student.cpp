#include "Student.h"

Student::Student(QObject *parent)
	: QObject(parent)
{
}

Student::~Student()
{
}

QString Student::getName()
{
	return _name;
}

void Student::setName(const QString& name)
{
	_name = name;
	emit nameChange(name);
}