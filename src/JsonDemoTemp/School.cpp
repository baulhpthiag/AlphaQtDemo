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

Q_INVOKABLE void School::setStudents(QList<QObject*> students)
{
	for each(QObject* item in students)
	{
		Student* s = qobject_cast<Student*>(item);
		_pStudents.append(s);
	}
}
