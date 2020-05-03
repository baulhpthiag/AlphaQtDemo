#include "Product.h"

Product::Product(QObject *parent)
	: QObject(parent)
{
	_bigData = new int[4096 * 4096];
}

Product::Product(const Product & other, QObject*parent /*= nullptr*/)
{
	_productId = other._productId;
	_data = other._data;
	int *temp = new int[4096 * 4096];
	memcpy(temp, other._bigData, 4096 * 4096);
	_bigData = temp;

}

Product::~Product()
{
	if (nullptr != _bigData)
	{
		delete[] _bigData;
		_bigData = nullptr;
	}
}

QString Product::toString()
{
	QString str;
	str.append("\n\t").append("productId:").append(_productId)
		.append("\n\t").append("data:").append(QString::number(_data))
		.append("\n");
	return str;
}
