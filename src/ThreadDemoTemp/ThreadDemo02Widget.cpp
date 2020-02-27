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
