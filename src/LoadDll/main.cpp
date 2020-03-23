#include "LoadDllWidget.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	LoadDllWidget w;
	w.show();
	return a.exec();
}
