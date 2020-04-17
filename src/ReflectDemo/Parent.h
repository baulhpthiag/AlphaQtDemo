#pragma once

#include <QObject>
#include "Child.h"

class Parent : public QObject
{
	Q_OBJECT
		Q_PROPERTY(QString parentName MEMBER _parentName)
		Q_PROPERTY(int age MEMBER _age)
		Q_PROPERTY(Child child0 MEMBER _child0)
		Q_PROPERTY(QList<Child> children MEMBER _children)

public:
	Parent(QObject *parent=nullptr);
	~Parent();

	QString _parentName;
	int _age;
	Child _child0;
	QList<Child> _children;

};
