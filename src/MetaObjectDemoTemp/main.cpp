#include "MetaObjectDemoTempMainWidget.h"
#include <QtWidgets/QApplication>
#include <QMetaType>
#include "Son.h"
#include "Father.h"

int main(int argc, char *argv[])
{
	qRegisterMetaType<Son>("Son");
	//qRegisterMetaType<Father>("Father");

	QApplication a(argc, argv);
	MetaObjectDemoTempMainWidget w;
	w.show();
	return a.exec();
}
