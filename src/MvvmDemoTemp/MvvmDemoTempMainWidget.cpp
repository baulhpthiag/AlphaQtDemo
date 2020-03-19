#include "MvvmDemoTempMainWidget.h"
#include <QMetaMethod>
#include <QMetaObject>

MvvmDemoTempMainWidget::MvvmDemoTempMainWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	init();
}

void MvvmDemoTempMainWidget::init()
{

	ui.lineEdit->setProperty("binding", "name");


	const QMetaObject * obj = student.metaObject();
	QMetaMethod setName;
	for (int i = 0; i < obj->methodCount(); i++)
	{
		QMetaMethod tempMethod = obj->method(i);
		if ("setName" == QString(tempMethod.name()))
		{
			setName = tempMethod;
		}
	}

	const QMetaObject * lineobj = ui.lineEdit->metaObject();
	QMetaMethod textChanged;
	for (int i = 0; i < lineobj->methodCount(); i++)
	{
		QMetaMethod tempMethod = lineobj->method(i);
		if ("textChanged" == QString(tempMethod.name()))
		{
			textChanged = tempMethod;
		}
	}
	
	////槽和信号要同时使用反射获得
	//connect(ui.lineEdit, &QLineEdit::textChanged, &student, setName);
	connect(ui.lineEdit, textChanged, &student, setName);

	//connect(ui.lineEdit, &QLineEdit::textChanged, this, [&]() {
	//	QMetaObject::invokeMethod(&student, "setName", Q_ARG(QString, ui.lineEdit->text()));
	//});

	connect(&student, &Student::nameChange, ui.label, &QLabel::setText);

	////
	//int singal = ui.lineEdit->metaObject()->property("第i个信号").notifySignalIndex();
	//int slot = student.metaObject()->indexOfSlot("setName");
	//QMetaObject::connect(ui.lineEdit, singal, &student, slot);


	//ui.lineEdit->metaObject()->property(i).name() == "text"就可以直接获得他的textChanged信号了,i有可能越界，不检查会断言失败的


}
