#include "IniDemoMainWidget.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	IniDemoMainWidget w;
	w.show();
	return a.exec();
}
