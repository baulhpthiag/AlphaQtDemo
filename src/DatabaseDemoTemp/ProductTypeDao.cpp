#include "ProductTypeDao.h"
#include "DBUtil.h"

ProductTypeDao::ProductTypeDao(QObject *parent)
	: QObject(parent)
{
}

ProductTypeDao::~ProductTypeDao()
{

}

ProductType ProductTypeDao::findById(QString id)
{
	QVariantMap params;
	params["typeid"] = id;
	return DBUtil::selectBean(mapToProductType, "select * from tb_product_type where typeid=:typeid",params);
}

QList<ProductType> ProductTypeDao::findAll()
{
	return DBUtil::selectBeans(mapToProductType, "select * from tb_product_type");
}

bool ProductTypeDao::insert(const ProductType productType)
{
	QVariantMap params;
	params["typeid"] = productType.TypeId;
	params["typename"] = productType.TypeName;
	params["createdatetime"] = productType.CreateDatetime.toString("yyyyMMddhhmmss");
	
	return DBUtil::insert("insert into tb_product_type (typeid,typename,createdatetime) VALUES (:typeid,:typename,:createdatetime)", params);
}

bool ProductTypeDao::update(const ProductType productType)
{
	QVariantMap params;
	params["typeid"] = productType.TypeId;
	params["typename"] = productType.TypeName;
	params["createdatetime"] = productType.CreateDatetime.toString("yyyyMMddhhmmss");

	return DBUtil::update("update tb_product_type set typename=:typename ,createdatetime = :createdatetime where typeid=:typeid", params);
}

bool ProductTypeDao::deleteById(QString id)
{
	QVariantMap params;
	params["typeid"] = id;
	return DBUtil::update("delete from tb_product_type where typeid=:typeid", params);
}

ProductType ProductTypeDao::mapToProductType(const QMap<QString, QVariant> &rowMap)
{
	ProductType productType;

	productType.TypeId = rowMap.value("typeid").toString();
	productType.TypeName = rowMap.value("typename").toString();
	productType.CreateDatetime = rowMap.value("createdatetime").toDateTime();
	return productType;
}


