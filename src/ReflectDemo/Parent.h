#pragma once

#include <QObject>
#include "Child.h"
#include <QDebug>

class Parent : public QObject
{
	Q_OBJECT
		Q_PROPERTY(QString parentName READ getParentName WRITE setParentName)
		Q_PROPERTY(int age MEMBER _age)
		//Q_PROPERTY(Child child0 MEMBER _child0)
		//Q_PROPERTY(QList<Child> children MEMBER _children)

public:
	Parent(QObject *parent=nullptr);
	Parent(const Parent& other)
	{
		qDebug() << "copy constructor this "<<	this;
		qDebug() << "copy constructor other " << &other;
		this->_parentName = other._parentName;
		this->_age = other._age;
	}

	~Parent();

	QString _parentName;
	int _age;
	Child _child0;
	QList<Child> _children;

	QString getParentName() ;
	void setParentName(const QString & name );

	Child& getChild();
	void setChild(const Child & child);



};
Q_DECLARE_METATYPE(Parent)