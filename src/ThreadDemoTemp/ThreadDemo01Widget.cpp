#include "ThreadDemo01Widget.h"
#include <QDebug>

ThreadDemo01Widget::ThreadDemo01Widget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	init();
}

ThreadDemo01Widget::~ThreadDemo01Widget()
{
	qDebug() << "~ThreadDemo01() begin";

	qDebug() << "objectName:" << this->objectName();

	qDebug() << "~ThreadDemo01() end";
}

void ThreadDemo01Widget::init()
{
	initMember();
}

void ThreadDemo01Widget::initMember()
{

}

void ThreadDemo01Widget::startThreadButtonClicked()
{
	controller01.start();
}

void ThreadDemo01Widget::finishThreadButtonClicked()
{
	
}
