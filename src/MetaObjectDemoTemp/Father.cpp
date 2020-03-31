#include "Father.h"

Father::Father(QObject *parent)
	: QObject(parent)
{
}

Father::~Father()
{
}

Q_INVOKABLE void Father::setSon(const Son& son)
{
	_son = son;
}

Q_INVOKABLE Son& Father::getSon()
{
	return _son;
}
