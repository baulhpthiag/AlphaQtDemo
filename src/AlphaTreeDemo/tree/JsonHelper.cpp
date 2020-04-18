#include "JsonHelper.h"

#include <QVariant>
#include "BoolConfigNode.h"
#include "DoubleConfigNode.h"
#include "DoubleEnumConfigNode.h"

#include "IntConfigNode.h"
#include "IntEnumConfigNode.h"
#include "StringConfigNode.h"
#include "StringEnumConfigNode.h"

JsonHelper::JsonHelper(QObject *parent)
	: QObject(parent)
{

}

JsonHelper::~JsonHelper()
{

}

bool JsonHelper::objToJsonObj(QJsonObject* jsonObj, QObject *obj)
{
	if (nullptr == jsonObj || nullptr == obj)
	{
		return false;
	}
	const QMetaObject * metaObj = obj->metaObject();

	int count = metaObj->propertyCount();
	int offset = metaObj->propertyOffset();
	for (int i = offset; i < count; ++i) {
		QMetaProperty metaProperty = metaObj->property(i);
		const char *pStrKey = metaProperty.name();
		QString strKey = QString::fromUtf8(pStrKey);

		QVariant var = obj->property(pStrKey);
		const char * pStrTypeName = var.typeName();
		QString strTypeName = QString::fromUtf8(pStrTypeName);

		if ("int" == strTypeName)
		{
			jsonObj->insert(strKey, QJsonValue::fromVariant(var));
		}
		else if ("QList<int>" == strTypeName)
		{
			QList<int> list = var.value<QList<int>>();
			QJsonArray jsonArray;
			for (int i = 0; i < list.count(); i++)
			{
				jsonArray.append(list[i]);
			}
			jsonObj->insert(strKey, jsonArray);
		}
		else if ("double" == strTypeName)
		{
			jsonObj->insert(strKey, QJsonValue::fromVariant(var));
		}
		else if ("QList<double>" == strTypeName)
		{
			QList<double> list = var.value<QList<double>>();
			QJsonArray jsonArray;
			for (int i = 0; i < list.count(); i++)
			{
				jsonArray.append(list[i]);
			}
			jsonObj->insert(strKey, jsonArray);
		}
		else if ("bool" == strTypeName)
		{
			jsonObj->insert(strKey, QJsonValue::fromVariant(var));
		}
		else if ("QList<bool>" == strTypeName)
		{
			QList<bool> list = var.value<QList<bool>>();
			QJsonArray jsonArray;
			for (int i = 0; i < list.count(); i++)
			{
				jsonArray.append(list[i]);
			}
			jsonObj->insert(strKey, jsonArray);
		}
		else if ("QString" == strTypeName)
		{
			jsonObj->insert(strKey, QJsonValue::fromVariant(var));
		}
		else if ("QList<QString>" == strTypeName)
		{
			QList<QString> list = var.value<QList<QString>>();
			QJsonArray jsonArray;
			for (int i = 0; i < list.count(); i++)
			{
				jsonArray.append(list[i]);
			}
			jsonObj->insert(strKey, jsonArray);
		}
		else if ("BoolConfigNode" == strTypeName)
		{
			BoolConfigNode tempConfigNode = var.value<BoolConfigNode>();
			QJsonObject tempJsonObj;
			objToJsonObj(&tempJsonObj, &tempConfigNode);
			jsonObj->insert(strKey, tempJsonObj);
		}
		else if ("QList<BoolConfigNode>" == strTypeName)
		{
			QList<BoolConfigNode> list = var.value<QList<BoolConfigNode>>();
			QJsonArray jsonArray;
			for (int i = 0; i < list.count(); i++)
			{
				BoolConfigNode& tempConfigNode = list[i];
				QJsonObject tempJsonObj;
				objToJsonObj(&tempJsonObj, &tempConfigNode);
				jsonArray.append(tempJsonObj);
			}
			jsonObj->insert(strKey, jsonArray);
		}
		else if ("DoubleConfigNode" == strTypeName)
		{
			DoubleConfigNode tempConfigNode = var.value<DoubleConfigNode>();
			QJsonObject tempJsonObj;
			objToJsonObj(&tempJsonObj, &tempConfigNode);
			jsonObj->insert(strKey, tempJsonObj);
		}
		else if ("QList<DoubleConfigNode>" == strTypeName)
		{
			QList<DoubleConfigNode> list = var.value<QList<DoubleConfigNode>>();
			QJsonArray jsonArray;
			for (int i = 0; i < list.count(); i++)
			{
				DoubleConfigNode tempConfigNode = list[i];
				QJsonObject tempJsonObj;
				objToJsonObj(&tempJsonObj, &tempConfigNode);
				jsonArray.append(tempJsonObj);
			}
			jsonObj->insert(strKey, jsonArray);
		}
		else if ("DoubleEnumConfigNode" == strTypeName)
		{
			DoubleEnumConfigNode tempConfigNode = var.value<DoubleEnumConfigNode>();
			QJsonObject tempJsonObj;
			objToJsonObj(&tempJsonObj, &tempConfigNode);
			jsonObj->insert(strKey, tempJsonObj);
		}
		else if ("QList<DoubleEnumConfigNode>" == strTypeName)
		{
			QList<DoubleEnumConfigNode> list = var.value<QList<DoubleEnumConfigNode>>();
			QJsonArray jsonArray;
			for (int i = 0; i < list.count(); i++)
			{
				DoubleEnumConfigNode tempConfigNode = list[i];
				QJsonObject tempJsonObj;
				objToJsonObj(&tempJsonObj, &tempConfigNode);
				jsonArray.append(tempJsonObj);
			}
			jsonObj->insert(strKey, jsonArray);
		}
		else if ("IntConfigNode" == strTypeName)
		{
			IntConfigNode tempConfigNode = var.value<IntConfigNode>();
			QJsonObject tempJsonObj;
			objToJsonObj(&tempJsonObj, &tempConfigNode);
			jsonObj->insert(strKey, tempJsonObj);
		}
		else if ("QList<IntConfigNode>" == strTypeName)
		{
			QList<IntConfigNode> list = var.value<QList<IntConfigNode>>();
			QJsonArray jsonArray;
			for (int i = 0; i < list.count(); i++)
			{
				IntConfigNode& tempConfigNode = list[i];
				QJsonObject tempJsonObj;
				objToJsonObj(&tempJsonObj, &tempConfigNode);
				jsonArray.append(tempJsonObj);
			}
			jsonObj->insert(strKey, jsonArray);
		}
		else if ("IntEnumConfigNode" == strTypeName)
		{
			IntEnumConfigNode tempConfigNode = var.value<IntEnumConfigNode>();
			QJsonObject tempJsonObj;
			objToJsonObj(&tempJsonObj, &tempConfigNode);
			jsonObj->insert(strKey, tempJsonObj);
		}
		else if ("QList<IntEnumConfigNode>" == strTypeName)
		{
			QList<IntEnumConfigNode> list = var.value<QList<IntEnumConfigNode>>();
			QJsonArray jsonArray;
			for (int i = 0; i < list.count(); i++)
			{
				IntEnumConfigNode tempConfigNode = list[i];
				QJsonObject tempJsonObj;
				objToJsonObj(&tempJsonObj, &tempConfigNode);
				jsonArray.append(tempJsonObj);
			}
			jsonObj->insert(strKey, jsonArray);
		}
		else if ("StringConfigNode" == strTypeName)
		{
			StringConfigNode tempConfigNode = var.value<StringConfigNode>();
			QJsonObject tempJsonObj;
			objToJsonObj(&tempJsonObj, &tempConfigNode);
			jsonObj->insert(strKey, tempJsonObj);
		}
		else if ("QList<StringConfigNode>" == strTypeName)
		{
			QList<StringConfigNode> list = var.value<QList<StringConfigNode>>();
			QJsonArray jsonArray;
			for (int i = 0; i < list.count(); i++)
			{
				StringConfigNode tempConfigNode = list[i];
				QJsonObject tempJsonObj;
				objToJsonObj(&tempJsonObj, &tempConfigNode);
				jsonArray.append(tempJsonObj);
			}
			jsonObj->insert(strKey, jsonArray);
		}
		else if ("StringEnumConfigNode" == strTypeName)
		{
			StringEnumConfigNode tempConfigNode = var.value<StringEnumConfigNode>();
			QJsonObject tempJsonObj;
			objToJsonObj(&tempJsonObj, &tempConfigNode);
			jsonObj->insert(strKey, tempJsonObj);
		}
		else if ("QList<StringEnumConfigNode>" == strTypeName)
		{
			QList<StringEnumConfigNode> list = var.value<QList<StringEnumConfigNode>>();
			QJsonArray jsonArray;
			for (int i = 0; i < list.count(); i++)
			{
				StringEnumConfigNode tempConfigNode = list[i];
				QJsonObject tempJsonObj;
				objToJsonObj(&tempJsonObj, &tempConfigNode);
				jsonArray.append(tempJsonObj);
			}
			jsonObj->insert(strKey, jsonArray);
		}
		else if (strTypeName.contains("QList"))
		{
			qDebug() << "JsonHelper objToJsonObj unknown type " + strTypeName;

			//QJsonArray jsonArray;
			//QSequentialIterable it = val.value<QSequentialIterable>();
			//for (const QVariant &v : it)
			//{
			//	QJsonObject childJsonObj;
			//	QObject *childObject = qvariant_cast<QObject*>(v);
			//	objToJsonObj(&childJsonObj, childObject);
			//	jsonArray.append(childJsonObj);
			//}
			//jsonObj->insert(qstringKey, jsonArray);

		}
		else if (strTypeName.contains("*"))
		{
			qDebug() << "JsonHelper objToJsonObj unknown type " + strTypeName;

			/*QJsonObject tempJsonObj;
			QString upperFirst = qstringKey.mid(0).at(0).toUpper() + qstringKey.mid(1);
			QString methodName = "get" + upperFirst;
			const QByteArray text = methodName.toLocal8Bit();

			QObject * returnValue;
			QMetaObject::invokeMethod(obj, text.data(), Qt::DirectConnection, Q_RETURN_ARG(QObject*, returnValue));

			objToJsonObj(&tempJsonObj, returnValue);
			jsonObj->insert(qstringKey, QJsonValue::fromVariant(tempJsonObj));*/
		}
		else
		{
			qDebug() << "JsonHelper objToJsonObj unknown type " + strTypeName;
		}

	}

	return true;
}

bool JsonHelper::jsonObjToObj(QJsonObject* jsonObj, QObject *obj)
{
	if (nullptr == jsonObj || nullptr == obj)
	{
		return false;
	}
	const QMetaObject * metaObj = obj->metaObject();

	int count = metaObj->propertyCount();
	int offset = metaObj->propertyOffset();
	for (int i = offset; i < count; ++i) {

		QMetaProperty metaProperty = metaObj->property(i);
		const char *pStrKey = metaProperty.name();
		QString strKey = QString::fromUtf8(pStrKey);

		QVariant var = obj->property(pStrKey);
		const char * pStrTypeName = var.typeName();
		QString strTypeName = QString::fromUtf8(pStrTypeName);



		if ("int" == strTypeName)
		{
			QVariant tempVar;
			tempVar.setValue(jsonObj->value(strKey));
			obj->setProperty(pStrKey, tempVar);
		}
		else if ("QList<int>" == strTypeName)
		{
			QList<int> list;
			QJsonArray jsonArray = jsonObj->value(strKey).toArray();

			for each (auto item in jsonArray)
			{
				list.append(item.toInt());
			}
			QVariant tempVar;
			tempVar.setValue<QList<int>>(list);

			obj->setProperty(pStrKey, tempVar);
		}
		else if ("double" == strTypeName)
		{
			QVariant tempVar;
			tempVar.setValue(jsonObj->value(strKey));
			obj->setProperty(pStrKey, tempVar);
		}
		else if ("QList<double>" == strTypeName)
		{
			QList<double> list;
			QJsonArray jsonArray = jsonObj->value(strKey).toArray();

			for each (auto item in jsonArray)
			{
				list.append(item.toDouble());
			}
			QVariant tempVar;
			tempVar.setValue<QList<double>>(list);

			obj->setProperty(pStrKey, tempVar);
		}
		else if ("bool" == strTypeName)
		{
			QVariant tempVar;
			tempVar.setValue(jsonObj->value(strKey));
			obj->setProperty(pStrKey, tempVar);
		}
		else if ("QList<bool>" == strTypeName)
		{
			QList<bool> list;
			QJsonArray jsonArray = jsonObj->value(strKey).toArray();

			for each (auto item in jsonArray)
			{
				list.append(item.toBool());
			}
			QVariant tempVar;
			tempVar.setValue<QList<bool>>(list);

			obj->setProperty(pStrKey, tempVar);
		}
		else if ("QString" == strTypeName)
		{
			QVariant tempVar;
			tempVar.setValue(jsonObj->value(strKey));
			obj->setProperty(pStrKey, tempVar);
		}
		else if ("QList<QString>" == strTypeName)
		{
			QList<QString> list;
			QJsonArray jsonArray = jsonObj->value(strKey).toArray();

			for each (auto item in jsonArray)
			{
				list.append(item.toString());
			}
			QVariant tempVar;
			tempVar.setValue<QList<QString>>(list);

			obj->setProperty(pStrKey, tempVar);
		}
		//自定义数据类型
		else if ("BoolConfigNode" == strTypeName)
		{
			BoolConfigNode tempConfigNode;
			QJsonObject tempJsonObj = jsonObj->value(strKey).toObject();
			jsonObjToObj(&tempJsonObj, &tempConfigNode);

			QVariant tempVar;
			tempVar.setValue<BoolConfigNode>(tempConfigNode);
			obj->setProperty(pStrKey, tempVar);

		}
		else if ("QList<BoolConfigNode>" == strTypeName)
		{
			QList<BoolConfigNode> list;
			QJsonArray jsonArray = jsonObj->value(strKey).toArray();

			for each (auto item in jsonArray)
			{
				BoolConfigNode tempConfigNode;
				QJsonObject tempJsonObj = item.toObject();
				jsonObjToObj(&tempJsonObj, &tempConfigNode);
				list.append(tempConfigNode);
			}

			QVariant tempVar;
			tempVar.setValue<QList<BoolConfigNode>>(list);
			obj->setProperty(pStrKey, tempVar);
		}

		else if ("DoubleConfigNode" == strTypeName)
		{
			DoubleConfigNode tempConfigNode;
			QJsonObject tempJsonObj = jsonObj->value(strKey).toObject();
			jsonObjToObj(&tempJsonObj, &tempConfigNode);

			QVariant tempVar;
			tempVar.setValue<DoubleConfigNode>(tempConfigNode);
			obj->setProperty(pStrKey, tempVar);
		}
		else if ("QList<DoubleConfigNode>" == strTypeName)
		{
			QList<DoubleConfigNode> list;
			QJsonArray jsonArray = jsonObj->value(strKey).toArray();

			for each (auto item in jsonArray)
			{
				DoubleConfigNode tempConfigNode;
				QJsonObject tempJsonObj = item.toObject();
				jsonObjToObj(&tempJsonObj, &tempConfigNode);
				list.append(tempConfigNode);
			}

			QVariant tempVar;
			tempVar.setValue<QList<DoubleConfigNode>>(list);
			obj->setProperty(pStrKey, tempVar);
		}

		else if ("DoubleEnumConfigNode" == strTypeName)
		{
			DoubleEnumConfigNode tempConfigNode;
			QJsonObject tempJsonObj = jsonObj->value(strKey).toObject();
			jsonObjToObj(&tempJsonObj, &tempConfigNode);

			QVariant tempVar;
			tempVar.setValue<DoubleEnumConfigNode>(tempConfigNode);
			obj->setProperty(pStrKey, tempVar);
		}
		else if ("QList<DoubleEnumConfigNode>" == strTypeName)
		{
			QList<DoubleEnumConfigNode> list;
			QJsonArray jsonArray = jsonObj->value(strKey).toArray();

			for each (auto item in jsonArray)
			{
				DoubleEnumConfigNode tempConfigNode;
				QJsonObject tempJsonObj = item.toObject();
				jsonObjToObj(&tempJsonObj, &tempConfigNode);
				list.append(tempConfigNode);
			}

			QVariant tempVar;
			tempVar.setValue<QList<DoubleEnumConfigNode>>(list);
			obj->setProperty(pStrKey, tempVar);
		}

		else if ("IntConfigNode" == strTypeName)
		{
			IntConfigNode tempConfigNode;
			QJsonObject tempJsonObj = jsonObj->value(strKey).toObject();
			jsonObjToObj(&tempJsonObj, &tempConfigNode);

			QVariant tempVar;
			tempVar.setValue<IntConfigNode>(tempConfigNode);
			obj->setProperty(pStrKey, tempVar);
		}
		else if ("QList<IntConfigNode>" == strTypeName)
		{
			QList<IntConfigNode> list;
			QJsonArray jsonArray = jsonObj->value(strKey).toArray();

			for each (auto item in jsonArray)
			{
				IntConfigNode tempConfigNode;
				QJsonObject tempJsonObj = item.toObject();
				jsonObjToObj(&tempJsonObj, &tempConfigNode);
				list.append(tempConfigNode);
			}

			QVariant tempVar;
			tempVar.setValue<QList<IntConfigNode>>(list);
			obj->setProperty(pStrKey, tempVar);
		}

		else if ("IntEnumConfigNode" == strTypeName)
		{
			IntEnumConfigNode tempConfigNode;
			QJsonObject tempJsonObj = jsonObj->value(strKey).toObject();
			jsonObjToObj(&tempJsonObj, &tempConfigNode);

			QVariant tempVar;
			tempVar.setValue<IntEnumConfigNode>(tempConfigNode);
			obj->setProperty(pStrKey, tempVar);
		}
		else if ("QList<IntEnumConfigNode>" == strTypeName)
		{
			QList<IntEnumConfigNode> list;
			QJsonArray jsonArray = jsonObj->value(strKey).toArray();

			for each (auto item in jsonArray)
			{
				IntEnumConfigNode tempConfigNode;
				QJsonObject tempJsonObj = item.toObject();
				jsonObjToObj(&tempJsonObj, &tempConfigNode);
				list.append(tempConfigNode);
			}

			QVariant tempVar;
			tempVar.setValue<QList<IntEnumConfigNode>>(list);
			obj->setProperty(pStrKey, tempVar);
		}

		else if ("StringConfigNode" == strTypeName)
		{
			StringConfigNode tempConfigNode;
			QJsonObject tempJsonObj = jsonObj->value(strKey).toObject();
			jsonObjToObj(&tempJsonObj, &tempConfigNode);

			QVariant tempVar;
			tempVar.setValue<StringConfigNode>(tempConfigNode);
			obj->setProperty(pStrKey, tempVar);
		}
		else if ("QList<StringConfigNode>" == strTypeName)
		{
			QList<StringConfigNode> list;
			QJsonArray jsonArray = jsonObj->value(strKey).toArray();

			for each (auto item in jsonArray)
			{
				StringConfigNode tempConfigNode;
				QJsonObject tempJsonObj = item.toObject();
				jsonObjToObj(&tempJsonObj, &tempConfigNode);
				list.append(tempConfigNode);
			}

			QVariant tempVar;
			tempVar.setValue<QList<StringConfigNode>>(list);
			obj->setProperty(pStrKey, tempVar);
		}

		else if ("StringEnumConfigNode" == strTypeName)
		{
			StringEnumConfigNode tempConfigNode;
			QJsonObject tempJsonObj = jsonObj->value(strKey).toObject();
			jsonObjToObj(&tempJsonObj, &tempConfigNode);

			QVariant tempVar;
			tempVar.setValue<StringEnumConfigNode>(tempConfigNode);
			obj->setProperty(pStrKey, tempVar);
		}
		else if ("QList<StringEnumConfigNode>" == strTypeName)
		{
			QList<StringEnumConfigNode> list;
			QJsonArray jsonArray = jsonObj->value(strKey).toArray();

			for each (auto item in jsonArray)
			{
				StringEnumConfigNode tempConfigNode;
				QJsonObject tempJsonObj = item.toObject();
				jsonObjToObj(&tempJsonObj, &tempConfigNode);
				list.append(tempConfigNode);
			}

			QVariant tempVar;
			tempVar.setValue<QList<StringEnumConfigNode>>(list);
			obj->setProperty(pStrKey, tempVar);
		}

		else if (strTypeName.contains("QList"))
		{

			//qDebug() << "jsonHelper jsonObjToObj unknown type " + strTypeName;
			//int beginIndex = strTypeName.indexOf("<");
			//int endIndex = strTypeName.indexOf("*");
			//QString typeName = strTypeName.mid(beginIndex + 1, endIndex - beginIndex - 1);
			//QList<QObject*> list;
			//QJsonArray jsonArray = jsonObj->value(strKey).toArray();


			//for each (QJsonValue item in jsonArray)
			//{
			//	QJsonObject childJsonObj = item.toObject();
			//	ObjectFactory fac;
			//	QObject* childObj = fac.createObject(typeName.toUtf8(), nullptr);
			//	jsonObjToObj(&childJsonObj, childObj);
			//	list.append(childObj);


			//}
			//QString methodName = "set" + strKey.mid(1);
			//const QByteArray text = methodName.toLocal8Bit();
			//QMetaObject::invokeMethod(obj, text.data(), Qt::DirectConnection, Q_ARG(QList<QObject*>, list));

			//QVariant varParams;
			//varParams.setValue<QList<QObject*>>(list);
			//obj->setProperty(key, varParams);

		}
		else if (strTypeName.contains("*"))
		{
			qDebug() << "jsonHelper jsonObjToObj unknown type " + strTypeName;
			//int endIndex = strTypeName.indexOf("*");
			//QString typeName = strTypeName.mid(0, endIndex - 1);
			//ObjectFactory fac;
			//QObject* tempObj = fac.createObject(typeName.toUtf8(), nullptr);
			//QJsonObject jsonObj;
			//jsonObjToObj(&jsonObj, tempObj);

			//QString upperFirst = strKey.mid(0).at(0).toUpper() + strKey.mid(1);
			//QString methodName = "set" + upperFirst;
			//const QByteArray text = methodName.toLocal8Bit();
			//QMetaObject::invokeMethod(obj, text.data(), Qt::DirectConnection, Q_ARG(QObject*, tempObj));

		}
		else
		{
			qDebug() << "jsonHelper jsonObjToObj unknown type " + strTypeName;
		}
	}
	return true;
}
