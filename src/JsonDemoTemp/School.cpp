#include "School.h"

School::School(QObject *parent)
	: QObject(parent)
{
}

School::~School()
{
}

Q_INVOKABLE QString School::getValue6()
{
	return s_School.schoolName;
}

Q_INVOKABLE void School::setValue6(QString value)
{
	s_School.schoolName = value;
}
