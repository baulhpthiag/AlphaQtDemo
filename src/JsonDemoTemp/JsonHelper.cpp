#include "JsonHelper.h"

JsonHelper::JsonHelper(QObject *parent)
	: QObject(parent)
{
}

JsonHelper::~JsonHelper()
{
}

void JsonHelper::insertValue(QJsonObject* jsonObj, QObject *obj)
{
	const QMetaObject * metaObj = obj->metaObject();

	int count = metaObj->propertyCount();
	int index = metaObj->propertyOffset();
	for (int i = index; i < count; ++i) {
		QMetaProperty metaProperty = metaObj->property(i);
		const char *key = metaProperty.name();
		QString qstringKey = QString::fromUtf8(key);

		QVariant val = obj->property(key);
		const char * typeName = val.typeName();
		QString qstringTypeName = QString::fromUtf8(typeName);
		qDebug() << typeName;

		if ("int" == qstringTypeName)
		{
			jsonObj->insert(qstringKey, val.toInt());
		}
		else if ("double" == qstringTypeName)
		{
			jsonObj->insert(qstringKey, val.toDouble());
		}
		else if ("bool" == qstringTypeName)
		{
			jsonObj->insert(qstringKey, val.toBool());
		}
		else if ("QString" == qstringTypeName)
		{
			jsonObj->insert(qstringKey, val.toString());
		}
		else if (qstringTypeName.contains("QList"))
		{
			/*
			QList<QString> list=val.value<QList<QString>>();

			QJsonArray jsonArray;
			for (int i = 0; i < list.count(); i++)
			{
				QString item = (list[i]);
				jsonArray.append(item);
			}
			jsonObj->insert(qstringKey, jsonArray);
			*/
		}
		else
		{
			qDebug() << "undo type " + qstringTypeName;
		}

	}
}
