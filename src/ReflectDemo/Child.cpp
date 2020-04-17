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
