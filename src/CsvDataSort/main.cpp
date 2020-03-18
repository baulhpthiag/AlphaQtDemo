#include "DataSortMainWidget.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	DataSortMainWidget w;
	w.show();
	return a.exec();
}
