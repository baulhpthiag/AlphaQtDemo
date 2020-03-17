#pragma once

#include <QObject>

class Student : public QObject
{
	Q_OBJECT

public:
	Student(QObject *parent = nullptr);
	~Student();


public:
	QString name;
	int age;
	bool isLearning;


};
