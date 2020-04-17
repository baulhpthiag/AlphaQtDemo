#pragma once

#include <QObject>

class Child : public QObject
{
	Q_OBJECT
		Q_PROPERTY(QString childName MEMBER _childName)
		Q_PROPERTY(int childAge MEMBER _childAge)
public:
	Child(QObject *parent = nullptr);
	~Child();

	QString _childName;
	int _childAge;


};
