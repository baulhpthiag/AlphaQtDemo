#include "JaiCameraDemoMainWidget.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	JaiCameraDemoMainWidget w;
	w.show();
	return a.exec();
}
