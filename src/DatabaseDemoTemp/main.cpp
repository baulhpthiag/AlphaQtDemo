#include "DatabaseDemoWidget.h"
#include <QtWidgets/QApplication>
#include <QTextCodec>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	DatabaseDemoWidget w;
	w.show();
	return a.exec();
}
