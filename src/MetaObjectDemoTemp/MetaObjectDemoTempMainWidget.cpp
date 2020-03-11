#include "MetaObjectDemoTempMainWidget.h"
#include <QDebug>
#include <QMetaMethod>
#include "ObjectFactory.h"

MetaObjectDemoTempMainWidget::MetaObjectDemoTempMainWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	connect(this, &MetaObjectDemoTempMainWidget::signalTextEditTextChanged, &student, &Student::setName);

	
}

void MetaObjectDemoTempMainWidget::test01ButtonClicked()
{
	Student temp;
	temp.setProperty("name", "aaa");
	qDebug() << temp.property("name").toString();
	qDebug() << temp.getName();

	const QMetaObject * obj = temp.metaObject();

	for (int i =0 ;i<obj->methodCount();i++)
	{
		QMetaMethod tempMethod = obj->method(i);
		qDebug() << "methodName :" << QString(tempMethod.name());
	}

	QString testResult;

	QMetaObject::invokeMethod(&temp, "test", Qt::DirectConnection, Q_RETURN_ARG(QString, testResult));
	qDebug() << testResult;

	//ÐÅºÅºÍ²Û
	connect(&temp, &Student::locationChange, this, &MetaObjectDemoTempMainWidget::slot1,Qt::QueuedConnection);

	temp.setProperty("location", "bbb");

	QString location = temp.getLocation();

	qDebug() << "ssss";
	for (int i = 0;i<100; i++)
	{
		qDebug() << "test01ButtonClicked " + QString::number(i);
	}


}

void MetaObjectDemoTempMainWidget::test02ButtonClicked()
{
	ObjectFactory fac;
	fac.registerClass<Student>();
	qDebug() << "begin-------------------------------" << endl;
	Student* object = qobject_cast<Student*>(fac.createObject("Student", this));
	object->setName("template factory");
	qDebug() << object->getName() << endl;

}

void MetaObjectDemoTempMainWidget::test03ButtonClicked()
{

}

void MetaObjectDemoTempMainWidget::lineEditEditingFInished()
{
	emit signalTextEditTextChanged(ui.lineEdit->text());
}

void MetaObjectDemoTempMainWidget::slot1()
{
	qDebug() << "slot1";
	for (int i = 0; i < 100; i++)
	{
		qDebug() << "slot1 " + QString::number(i);
	}
}

