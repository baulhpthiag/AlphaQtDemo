#pragma once

#include <QObject>
#include "Student.h"
#include "TestStruct.h"

class School : public QObject
{
	Q_OBJECT
	

	Q_PROPERTY(int pInt MEMBER _pInt )
	Q_PROPERTY(double pDouble MEMBER _pDouble)
	Q_PROPERTY(bool pBool MEMBER _pBool)
	Q_PROPERTY(QString pString MEMBER _pString NOTIFY pStringChange)
	Q_PROPERTY(QList<QString> pStrings MEMBER _pStrings)
	Q_PROPERTY(QString schoolName READ getSchoolName WRITE setSchoolName NOTIFY pStringChange)
	Q_PROPERTY(QList<Student*> pStudents MEMBER _pStudents)
public:
	School(QObject *parent = nullptr);
	~School();
private:
	S_School s_School;

public:
	int _pInt;
	double _pDouble;
	bool _pBool;
	QString _pString;
	QList<QString> _pStrings;
	QList<Student*> _pStudents;
	
public:
	Q_INVOKABLE QString getSchoolName();
	Q_INVOKABLE void setSchoolName(QString schoolName);
	Q_INVOKABLE void setStudents(QList<QObject*> students);

signals:
	void pStringChange(QString pString);
};
