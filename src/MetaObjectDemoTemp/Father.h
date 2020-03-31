#pragma once

#include <QObject>
#include "Son.h"

class Father : public QObject
{
	Q_OBJECT
		Q_PROPERTY(int fatherAge MEMBER _fatherAge)
		Q_PROPERTY(QString fatherName MEMBER _fatherName)
		//Q_PROPERTY(Son son MEMBER _son)
		Q_PROPERTY(Son son READ  getSon WRITE setSon)

public:
	Father(QObject *parent = nullptr);
	~Father();

	int _fatherAge;
	QString _fatherName;
	Son _son;

	Q_INVOKABLE void setSon(const Son& son);
	Q_INVOKABLE Son& getSon();
};
