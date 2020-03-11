#include "SlotAndSignalDemoTempMainWidget.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	SlotAndSignalDemoTempMainWidget w;
	w.show();
	return a.exec();
}
