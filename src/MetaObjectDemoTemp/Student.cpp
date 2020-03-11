#include "Student.h"
#include <QDebug>

Student::Student(QObject *parent)
	: QObject(parent)
{
}

Student::~Student()
{
}

QString Student::getLocation()
{
	return _location;
}

void Student::setName(QString name)
{
	_name = name;
}

QString Student::getName()
{
	return _name;
}

Q_INVOKABLE QString Student::test()
{
	qDebug() << "Student::test()run !!! ";
	return "hello world";
}

Q_INVOKABLE QString Student::test1()
{
	qDebug() << "Student::test1()run !!! ";
	return "hello world1";
}
