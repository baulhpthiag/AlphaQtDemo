#include "MetaObjectDemoTempMainWidget.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MetaObjectDemoTempMainWidget w;
	w.show();
	return a.exec();
}
