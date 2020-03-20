#include "JsonDemo03Widget.h"
#include "Student.h"
#include "School.h"
#include "JsonHelper.h"
#include "ObjectFactory.h"

JsonDemo03Widget::JsonDemo03Widget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

JsonDemo03Widget::~JsonDemo03Widget()
{

}

void JsonDemo03Widget::test01ButtonClicked()
{
	//ObjectFactory fac;
	//fac.registerClass<Student>();

	School school;
	school._schoolName = "school1";
	school._value1 = "value1";
	school._value2 = 1;
	school._value3 = true;
	school._value4 = 1.0;

	for (int i=0;i<5;i++)
	{
		school._value5.append("test"+QString::number(i));
	}

	for (int i = 0; i < 5; i++)
	{
		Student *student = new Student;
		student->_name = "student" + QString::number(i);
		student->_age = i;
		school._students.append(student);
	}

	JsonHelper::saveJson(school, qApp->applicationDirPath() + "/jsonDemo.json");


}

void JsonDemo03Widget::test02ButtonClicked()
{
	School school;
	bool result = JsonHelper::readJson(school,qApp->applicationDirPath() + "/jsonDemo.json");

	qDebug() << school._schoolName;

	school.setProperty("value6", "aaa");
	QString aaa = school.getValue6();

	qDebug() << "";
	qDebug() << "finish";

}
