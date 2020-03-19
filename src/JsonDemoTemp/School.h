#pragma once

#include <QObject>
#include "Student.h"

class School : public QObject
{
	Q_OBJECT
	
public:
	School(QObject *parent = nullptr);
	~School();

	QString schoolName;
	QList<Student> students;
};
