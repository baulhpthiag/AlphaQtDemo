#include "JsonDemo02Widget.h"
#include "Json.h"
#include <QDateTime>
#include <QDebug>

JsonDemo02Widget::JsonDemo02Widget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	init();
}

JsonDemo02Widget::~JsonDemo02Widget()
{
}

void JsonDemo02Widget::init()
{

}

void JsonDemo02Widget::createJsonButtonClicked()
{
	
}

void JsonDemo02Widget::readJsonButtonClicked()
{
	//参考 https://qtdebug.com/qt-json/

	Json  json(qApp->applicationDirPath() + "/testJson.json", true);

	QString userForReadName = json.getString("userForRead.userName");
	qDebug() << "userForReadName:" << userForReadName;
	int userAge = json.getInt("userForRead.userAge");
	qDebug() << "userAge:" << userAge;

	QDateTime userBirthday = QDateTime::fromString(json.getString("userForRead.birthday"),"yyyy-MM-dd hh:mm:ss");
	qDebug() << "userBirthday:" << userBirthday.toString("yyyy-MM-dd hh:mm:ss");
	bool userEnabled = json.getBool("userForRead.enabled");
	qDebug() << "userEnabled:" << userEnabled;

	QString userForReadComputerName = json.getString("userForRead.computer.computerName");
	qDebug() << "computerName" << userForReadComputerName;

	QJsonArray array = json.getJsonArray("usersForRead");
	for (int i =0;i<array.count();i++)
	{
		QJsonObject tempNode = array.at(i).toObject();
		qDebug() << json.getString("userName", "", tempNode);

	}
	


}

void JsonDemo02Widget::updateJsonButtonClicked()
{
	Json json(qApp->applicationDirPath() + "/testJson.json", true);

	QString newName = "newName"+QDateTime::currentDateTime().toString("yyyyMMddhhmmss");
	json.set("userForUpdate.userName", newName);
	

	QJsonArray array = json.getJsonArray("usersForUpdate");
	for (int i = 0; i < array.count(); i++)
	{
		QJsonObject tempNode = array.at(i).toObject();
		
		qDebug() << json.getString("userName", "", tempNode);

	}
	QJsonObject array0 = array.at(0).toObject();
	QString array0Name = "array0NameReplace" + QDateTime::currentDateTime().toString("yyyyMMddhhmmss");
	//insert 增加或更改
	array0.insert("userName", array0Name);
	
	//替换
	array.replace(0, array0);
	//array.removeAt(0);
	//json.remove("");

	array0Name = "array0NameInsert" + QDateTime::currentDateTime().toString("yyyyMMddhhmmss");
	//insert 增加或更改
	array0.insert("userName", array0Name);
	//插入
	array.insert(0, array0);

	json.set("usersForUpdate", array);

	json.save(qApp->applicationDirPath() + "/testJson.json");

}
