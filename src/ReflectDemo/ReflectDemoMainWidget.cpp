#include "ReflectDemoMainWidget.h"
#include <QDebug>

ReflectDemoMainWidget::ReflectDemoMainWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

void ReflectDemoMainWidget::varSetValueButtonClicked()
{
	qDebug() << "- - - in variant set";
	Parent parent;
	parent._parentName = "abc";
	parent._age = 1;
	qDebug() << &parent;

	var.setValue<Parent>(parent);
	qDebug() << "- - - out variant set";


}

void ReflectDemoMainWidget::varGetValueButtonClicked()
{
	qDebug() << "- - - in variant get";

	Parent& p0=var.value<Parent>();
	qDebug() << &p0;

	////观察 注释下面代码或者不注释的时候的现象
	//Parent p1 = var.value<Parent>();
	//qDebug() << &p1;
	qDebug() << "- - - out variant get";

}

void ReflectDemoMainWidget::setChildButtonClicked()
{

	Child child;
	child._childAge = 1;
	child._childName = "abc";
	_parent.setChild(child);
	qDebug() << "- - - out set child";
}

void ReflectDemoMainWidget::getChildButtonClicked()
{
	qDebug() << "- - - in get child";
	Child& child = _parent.getChild();
	qDebug() << "getChild " << &child;

}
