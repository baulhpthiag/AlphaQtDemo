#include "ReflectDemoMainWidget.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	ReflectDemoMainWidget w;
	w.show();
	return a.exec();
}
