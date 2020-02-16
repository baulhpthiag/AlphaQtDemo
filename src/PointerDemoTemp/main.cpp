#include "PointerDemoTempMainWindow.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	PointerDemoTempMainWindow w;
	w.show();
	return a.exec();
}
