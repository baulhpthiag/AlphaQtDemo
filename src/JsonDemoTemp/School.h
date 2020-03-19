#pragma once

#include <QObject>
#include "Student.h"
#include "TestStruct.h"

class School : public QObject
{
	Q_OBJECT
	

	Q_PROPERTY(QString schoolName MEMBER _schoolName NOTIFY schoolNameChange)
	Q_PROPERTY(QString value1 MEMBER _value1 )
	Q_PROPERTY(int value2 MEMBER _value2 )
	Q_PROPERTY(bool value3 MEMBER _value3)
	Q_PROPERTY(double value4 MEMBER _value4)
	Q_PROPERTY(QList<QString> value5 MEMBER _value5)
		
	Q_PROPERTY(QString value6 READ getValue6 WRITE setValue6 NOTIFY schoolNameChange)

	Q_PROPERTY(QList<Student*> students MEMBER _students)
public:
	School(QObject *parent = nullptr);
	~School();
private:
	S_School s_School;

public:

	QString _schoolName;
	QString _value1;
	int _value2;
	bool _value3;
	double _value4;
	QList<QString> _value5;
	
	QList<Student*> _students;
	
public:
	Q_INVOKABLE QString getValue6();
	Q_INVOKABLE void setValue6(QString value);

signals:
	void schoolNameChange(QString schoolName);
};
