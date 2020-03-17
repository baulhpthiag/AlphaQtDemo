#pragma once

#include <QObject>

class JsonHelper : public QObject
{
	Q_OBJECT

public:
	JsonHelper(QObject *parent =nullptr);
	~JsonHelper();

	template<class T>
	static bool saveJson(T& t,QString filePath);

};

template<class T>
static bool JsonHelper::saveJson(T& t, QString filePath)
{
	QObject *obj = (QObject*)(&t);
	
	const QMetaObject  metaObj = obj.metaObject();

	/*int count = metaObj->propertyCount();
	int index = metaObj->propertyOffset();
	for (int i = index; i < count; ++i) {
		QMetaProperty metaproperty = metaObj->property(i);
		metaproperty
		const char *name = metaproperty.name();
		QVariant value = t->property(name);
		qDebug() << name << value;
	}*/

	return true;

}
