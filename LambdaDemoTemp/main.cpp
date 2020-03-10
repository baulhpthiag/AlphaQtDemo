#include "LambdaDemoTempWidget.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	LambdaDemoTempWidget w;
	w.show();
	return a.exec();
}
