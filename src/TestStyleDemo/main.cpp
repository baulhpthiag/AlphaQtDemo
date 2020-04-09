#include "TestStyleDemo.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	TestStyleDemo w;
	w.show();
	return a.exec();
}
