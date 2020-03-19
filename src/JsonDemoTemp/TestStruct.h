#pragma once

#include <QObject>

struct S_School 
{
	QString schoolName;
};
class TestStruct : public QObject
{
	Q_OBJECT

public:
	TestStruct(QObject *parent);
	~TestStruct();
};
