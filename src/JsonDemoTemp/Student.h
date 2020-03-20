#pragma once

#include <QMetaType>
#include <QObject>


//Q_DECLARE_METATYPE(Student);
class Student : public QObject
{
	Q_OBJECT

	Q_PROPERTY(QString name MEMBER _name)
	Q_PROPERTY(QString age MEMBER _age)

public:
	 Student(QObject *parent=nullptr);
	~Student();


public:
	QString _name;
	int _age;

};
