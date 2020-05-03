#include "MainWidget.h"
#include <QtWidgets/QApplication>
#include "Product.h"
int main(int argc, char *argv[])
{
	qRegisterMetaType<Product>("Product");
	QApplication a(argc, argv);
	MainWidget w;
	w.show();
	return a.exec();
}
