#include "JsonDemoWidget.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	JsonDemoWidget w;
	w.show();
	return a.exec();
}
