#include "JsonHelper.h"

JsonHelper::JsonHelper(QObject *parent)
	: QObject(parent)
{
}

JsonHelper::~JsonHelper()
{
}

void JsonHelper::objToJsonObj(QJsonObject* jsonObj, QObject *obj)
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
			jsonObj->insert(qstringKey, QJsonValue::fromVariant(val));
		}
		else if ("double" == qstringTypeName)
		{
			jsonObj->insert(qstringKey, QJsonValue::fromVariant(val));
		}
		else if ("bool" == qstringTypeName)
		{
			jsonObj->insert(qstringKey, QJsonValue::fromVariant(val));
		}
		else if ("QString" == qstringTypeName)
		{
			jsonObj->insert(qstringKey, QJsonValue::fromVariant(val));
		}
		else if (qstringTypeName.contains("QList"))
		{
			if ("QList<QString>" == qstringTypeName)
			{
				QList<QString> list = val.value<QList<QString>>();
				QJsonArray jsonArray;
				for (int i = 0; i < list.count(); i++)
				{
					jsonArray.append(list[i]);
				}
				jsonObj->insert(qstringKey, jsonArray);
			}
			else if ("QList<int>" == qstringTypeName)
			{
				QList<int> list = val.value<QList<int>>();
				QJsonArray jsonArray;
				for (int i = 0; i < list.count(); i++)
				{
					jsonArray.append(list[i]);
				}
				jsonObj->insert(qstringKey, jsonArray);
			}
			else if ("QList<double>" == qstringTypeName)
			{
				QList<double> list = val.value<QList<double>>();
				QJsonArray jsonArray;
				for (int i = 0; i < list.count(); i++)
				{
					jsonArray.append(list[i]);
				}
				jsonObj->insert(qstringKey, jsonArray);
			}
			else if ("QList<bool>" == qstringTypeName)
			{
				QList<bool> list = val.value<QList<bool>>();
				QJsonArray jsonArray;
				for (int i = 0; i < list.count(); i++)
				{
					jsonArray.append(list[i]);
				}
				jsonObj->insert(qstringKey, jsonArray);
			}
			else
			{
				QJsonArray jsonArray;
				QSequentialIterable it = val.value<QSequentialIterable>();
				for (const QVariant &v : it)
				{
					QJsonObject childJsonObj;
					QObject *childObject = qvariant_cast<QObject*>(v);
					objToJsonObj(&childJsonObj, childObject);
					jsonArray.append(childJsonObj);
				}
				jsonObj->insert(qstringKey, jsonArray);

			}


		}
		else
		{
			qDebug() << "undo type " + qstringTypeName;
		}

	}
}

void JsonHelper::jsonObjToObj(QJsonObject* jsonObj, QObject *obj)
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
		
		if (val.canConvert<int>())
		{
			QVariant v;
			v.setValue(jsonObj->value(qstringKey));
			obj->setProperty(key, v);
		}
		else if (val.canConvert<double>())
		{
			QVariant v;
			v.setValue(jsonObj->value(qstringKey));
			obj->setProperty(key, v);
		}
		else if ("bool" == qstringTypeName)
		{
			QVariant v;
			v.setValue(jsonObj->value(qstringKey));
			obj->setProperty(key, v);
		}
		else if ("QString" == qstringTypeName)
		{
			QVariant v;
			v.setValue(jsonObj->value(qstringKey));
			obj->setProperty(key, v);
		}
		else if (qstringTypeName.contains("QList"))
		{
			if ("QList<QString>" == qstringTypeName)
			{
				QList<QString> list;
				QJsonArray jsonArray = jsonObj->value(qstringKey).toArray();

				for each (auto item in jsonArray)
				{

					list.append(item.toString());
				}
				QVariant varParams;
				varParams.setValue<QList<QString>>(list);

				obj->setProperty(key, varParams);
			}
			else if ("QList<int>" == qstringTypeName)
			{

			}
			else if ("QList<double>" == qstringTypeName)
			{

			}
			else if ("QList<bool>" == qstringTypeName)
			{

			}
			else
			{
				QList<QObject*> list;
				QJsonArray jsonArray = jsonObj->value(qstringKey).toArray();


				QSequentialIterable it = val.value<QSequentialIterable>();
				int size = it.size();

				qDebug() << size;
				//for each (QJsonValueRef item in jsonArray)
				//{
				//	QVariant v=item.toVariant();
				//	QObject childObject;

				//}
				//QVariant varParams;
				//varParams.setValue<QList<QString>>(list);

				//obj->setProperty(key, varParams);

			}


		}
		else
		{
			qDebug() << "undo type " + qstringTypeName;
		}

	}

}
