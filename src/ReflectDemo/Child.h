#pragma once

#include <QObject>
#include <QDebug>

class Child : public QObject
{
	Q_OBJECT
		Q_PROPERTY(QString childName MEMBER _childName)
		Q_PROPERTY(int childAge MEMBER _childAge)
public:
	Child(QObject *parent = nullptr);
	~Child();

	Child& operator=(const Child & other)
	{
		this->_childName = other._childName;
		this->_childAge = other._childAge;
		return *this;
	}

	QString _childName;
	int _childAge;


};
