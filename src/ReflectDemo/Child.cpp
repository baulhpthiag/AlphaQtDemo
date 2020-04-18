#include "Child.h"

Child::Child(QObject *parent)
	: QObject(parent)
{
	qDebug() << "Child constructor this;" << this;
}

Child::~Child()
{
	qDebug() << "Child destructor this;" << this;

}

void Child::setChildName(const QString & childName)
{
	qDebug() << "Child setChildName " << childName;

	_childName = childName;
	emit signalChildNameChanged(_childName);
}
