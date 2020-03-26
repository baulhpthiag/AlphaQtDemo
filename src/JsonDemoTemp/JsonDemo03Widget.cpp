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
	school._pInt = 1;
	school._pDouble = 1.0;
	school._pBool = true;
	school._pString = "hello world";

	for (int i=0;i<5;i++)
	{
		school._pStrings.append("test"+QString::number(i));
	}

	for (int i = 0; i < 5; i++)
	{
		Student *student = new Student;
		student->_name = "student" + QString::number(i);
		student->_age = i;
		school._pStudents.append(student);
	}

	JsonHelper::writeJsonFile(school, qApp->applicationDirPath() + "/jsonDemo.json");


}

void JsonDemo03Widget::test02ButtonClicked()
{
	School school;
	bool result = JsonHelper::readJsonFile(school,qApp->applicationDirPath() + "/jsonDemo.json");

	qDebug() << school._pString;

	for each (QString var in school._pStrings)
	{
		qDebug() << var;
	}
	int count = school._pStudents.count();
	for each (Student* var in school._pStudents)
	{
		qDebug() << var->_name;
		qDebug() << var->_age;
	}


	qDebug() << "";
	qDebug() << "finish";

}

void JsonDemo03Widget::test3ButtonClicked()
{

	QList<QObject*> list;


}

void JsonDemo03Widget::test4ButtonClicked()
{

}
