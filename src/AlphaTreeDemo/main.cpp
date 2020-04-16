#include "MainWidget.h"
#include <QtWidgets/QApplication>
#include "BoolConfigNode.h"
#include "DoubleConfigNode.h"
#include "DoubleEnumConfigNode.h"
#include "IntConfigNode.h"
#include "IntEnumConfigNode.h"
#include "StringConfigNode.h"
#include "StringEnumConfigNode.h"

int main(int argc, char *argv[])
{
	qRegisterMetaType<BoolConfigNode>();
	qRegisterMetaType<DoubleConfigNode>();
	qRegisterMetaType<DoubleEnumConfigNode>();
	qRegisterMetaType<IntConfigNode>();
	qRegisterMetaType<IntEnumConfigNode>();
	qRegisterMetaType<StringConfigNode>();
	qRegisterMetaType<StringEnumConfigNode>();

	QApplication a(argc, argv);
	MainWidget w;
	w.show();
	return a.exec();
}
