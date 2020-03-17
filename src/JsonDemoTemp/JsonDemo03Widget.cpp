#include "JsonDemo03Widget.h"
#include "Student.h"
#include "School.h"
#include "JsonHelper.h"

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
	School school;
	school.schoolName = "school1";

	/*for (int i=0;i<5;i++)
	{
		Student s;
		s.age = i;
		s.name = "student" + QString::number(i);
		s.isLearning = i % 2 == 1;
		school.students.append(s);
	}*/

	JsonHelper::saveJson(school, qApp->applicationDirPath() + "/jsonDemo.json");


}
