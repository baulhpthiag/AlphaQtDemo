#include "JsonDemoWidget.h"
#include <QtWidgets/QApplication>
#include "Student.h"
#include "ObjectFactory.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	//qRegisterMetaType<Student>("Student");
	//qRegisterMetaType<Student>("Student&");

	ObjectFactory fac;
	fac.registerClass<Student>();

	JsonDemoWidget w;
	w.show();
	return a.exec();
}
