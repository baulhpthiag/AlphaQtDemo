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


	connect(ui.lineEdit, &QLineEdit::textChanged, &student, setName);

	//connect(ui.lineEdit, &QLineEdit::textChanged, this, [&]() {
	//	QMetaObject::invokeMethod(&student, "setName", Q_ARG(QString, ui.lineEdit->text()));
	//});

	connect(&student, &Student::nameChange, ui.label, &QLabel::setText);


	//
	int singal = ui.lineEdit->metaObject()->property("��i���ź�").notifySignalIndex();
	int slot = student.metaObject()->indexOfSlot("setName");
	QMetaObject::connect(ui.lineEdit, singal, &student, slot);


	//ui.lineEdit->metaObject()->property(i).name() == "text"�Ϳ���ֱ�ӻ������textChanged�ź���,i�п���Խ�磬���������ʧ�ܵ�


}
