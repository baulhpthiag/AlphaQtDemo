#include "Parent.h"

Parent::Parent(QObject *parent)
	: QObject(parent)
{
	qDebug() << "constructor this " << this;

}

Parent::~Parent()
{
	qDebug() << "destructor this " << this;
}

QString Parent::getParentName() 
{
	return _parentName;
}

void Parent::setParentName(const QString & name)
{
	_parentName = name;
}

Child& Parent::getChild() 
{
	return _child0;
}

void Parent::setChild(const Child & child)
{
	_child0 = child;
	qDebug() << "setChild child" << &child;
	qDebug() << "setChild this.child" << &_child0;
}

Child* Parent::getChildP()
{
	return &_child0;
}
