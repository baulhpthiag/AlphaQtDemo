#include "ThreadDemoMainWidget.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	ThreadDemoMainWidget w;
	w.show();
	return a.exec();
}
