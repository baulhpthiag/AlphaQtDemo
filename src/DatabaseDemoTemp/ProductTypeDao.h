#pragma once

#include <QObject>
#include "CommonDataStruct.h"
#include <QVariant>


template <typename T> class QList;
template <typename KT, typename VT> class QMap;

////alpha todo 
//template<typename T>
//T mapTo<T>(const QMap<QString, QVariant>& rowMap)
//{
//	T t;
//	QObject obj = static_cast<QObject>(t);
//
//	const QMetaObject *metaobject = obj.metaObject();
//	int count = metaobject->propertyCount();
//	int index = metaobject->propertyOffset();
//	for (int i = index; i < count; ++i) {
//		QMetaProperty metaproperty = metaobject->property(i);
//		const char *name = metaproperty.name();
//		QVariant value = t->property(name);
//		qDebug() << name << value;
//	}
//
//	return NULL;
//}

class ProductTypeDao : public QObject
{
	Q_OBJECT

public:
	ProductTypeDao(QObject *parent);
	~ProductTypeDao();

	static ProductType findById(QString id);
	static QList<ProductType> findAll();
	static bool insert(const ProductType productType);
	static bool update(const ProductType productType);
	static bool deleteById(QString id);

private:
	static ProductType mapToProductType(const QMap<QString, QVariant> &rowMap);

};

