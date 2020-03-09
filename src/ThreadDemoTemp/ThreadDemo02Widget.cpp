#include "ThreadDemo02Widget.h"
#include <QDebug>
ThreadDemo02Widget::ThreadDemo02Widget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

ThreadDemo02Widget::~ThreadDemo02Widget()
{
	qDebug() << "~ThreadDemo02() begin";
	
	qDebug() << "objectName:" << this->objectName();

	qDebug() << "~ThreadDemo02() end";
}

void ThreadDemo02Widget::init()
{

}

void ThreadDemo02Widget::initMember()
{

}

void ThreadDemo02Widget::test01ButtonClicked()
{
	controller.begin();
}

void ThreadDemo02Widget::test02ButtonClicked()
{

}
