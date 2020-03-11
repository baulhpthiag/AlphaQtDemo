#include "MvvmDemoTempMainWidget.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MvvmDemoTempMainWidget w;
	w.show();
	return a.exec();
}
