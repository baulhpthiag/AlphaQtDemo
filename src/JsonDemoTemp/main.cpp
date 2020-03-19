#include "JsonDemoWidget.h"
#include <QtWidgets/QApplication>
#include "Student.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	//qRegisterMetaType<Student>("Student");
	//qRegisterMetaType<Student>("Student&");

	JsonDemoWidget w;
	w.show();
	return a.exec();
}
