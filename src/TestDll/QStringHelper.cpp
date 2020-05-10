#include "QStringHelper.h"
#include <QTextCodec>

QStringHelper::QStringHelper(QObject *parent)
	: QObject(parent)
{
}

QStringHelper::~QStringHelper()
{
}

bool QStringHelper::strListContainStr(QList<QString> list, QString str)
{
	bool find = false;
	for (int i = 0; i < list.count(); i++)
	{
		if (str == list[i])
		{
			find = true;
			break;
		}
	}
	return find;
}

char * QStringHelper::qstringToCharp(QString str)
{
	QTextCodec *code = QTextCodec::codecForName("gbk");
	std::string convert = code->fromUnicode(str).data();
	const char * constChar = convert.c_str();
	char *result = new char[strlen(constChar) + 1];
	strcpy(result, constChar);
	return result;
}

std::string QStringHelper::qstringToStdStr(const QString qstr)
{
	QByteArray cdata = qstr.toLocal8Bit();
	return std::string((const char *)cdata);
}



QString QStringHelper::newLine()
{
	return "\n";
}

QString QStringHelper::twoSpace()
{
	return "  ";
}

QString QStringHelper::newLineSpace()
{
	return newLine() + twoSpace();
}

