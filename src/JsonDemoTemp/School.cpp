#include "School.h"

School::School(QObject *parent)
	: QObject(parent)
{
}

School::~School()
{
}

Q_INVOKABLE QString School::getSchoolName()
{
	return s_School.schoolName;
}

Q_INVOKABLE void School::setSchoolName(QString value)
{
	s_School.schoolName = value;
}
