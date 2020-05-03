#pragma once

#include <QObject>

class Product : public QObject
{
	Q_OBJECT

public:
	Product(QObject *parent = nullptr);
	Product(const Product & other, QObject*parent = nullptr);
	~Product();

	QString _productId;
	int _data;
	int* _bigData;
	QString toString();

};
Q_DECLARE_METATYPE(Product)