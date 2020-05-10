#pragma once

//#include "DataStruct.h"
#include <QObject>


class QStringHelper : public QObject
{
	Q_OBJECT

public:
	QStringHelper(QObject *parent);
	~QStringHelper();

	static bool strListContainStr(QList<QString> list,QString str);

	static char* qstringToCharp(QString str);
	
	static std::string qstringToStdStr(const QString qstr);

	//inline static CString  qstringToCString(QString qstr)
	//{
	//	std::string str = qstringToStdStr(qstr);
	//	return  str.c_str();
	//}

	//换行符
	static QString newLine();

	//缩进
	static QString twoSpace();

	//换行缩进
	static QString newLineSpace();

};
