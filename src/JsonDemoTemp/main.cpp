#include "JsonDemoWidget.h"
#include <QtWidgets/QApplication>
#include "Student.h"
#include "ObjectFactory.h"
#include "Car.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	//qRegisterMetaType<Student>("Student");
	//qRegisterMetaType<Student>("Student&");

	qRegisterMetaType<Car>("Car");
	ObjectFactory fac;
	fac.registerClass<Student>();

	JsonDemoWidget w;
	w.show();
	return a.exec();
}
