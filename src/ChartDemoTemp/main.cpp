#include "ChartDemoWidget.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	ChartDemoWidget w;
	w.show();
	return a.exec();
}
