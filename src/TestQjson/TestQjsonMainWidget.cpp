#include "TestQjsonMainWidget.h"
#include "QObjectHelper.h"
#include "Person.h"
#include "Serializer.h"

TestQjsonMainWidget::TestQjsonMainWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

void TestQjsonMainWidget::test01ButtonClicked()
{
	Person person;
	person.setName("Flavio");
	person.setPhoneNumber(123456);
	person.setGender(Person::Male);
	//person.setDob(QDate(1982, 7, 12));

	QVariantMap variant = QObjectHelper::qobject2qvariant(&person);
	QJson::Serializer serializer;
	qDebug() << serializer.serialize(variant);

}

void TestQjsonMainWidget::test02ButtonClicked()
{

}
