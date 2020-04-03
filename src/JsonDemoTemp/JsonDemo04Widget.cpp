#include "JsonDemo04Widget.h"
#include "Parent.h"
#include "Child.h"
#include "Car.h"
#include "Toy.h"
#include <QDebug>
#include <QJsonObject>
#include "JsonHelper.h"

JsonDemo04Widget::JsonDemo04Widget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

JsonDemo04Widget::~JsonDemo04Widget()
{
}

void JsonDemo04Widget::writeJson()
{
	Parent parent;
	parent._age = 30;
	parent._parentName = "parent1";

	Car car;
	car._brand = "qq";
	parent.setProperty("car", QVariant::fromValue(car));

	qDebug() << parent._car._brand;

	JsonHelper::writeJsonFile(parent, qApp->applicationDirPath() + "/jsonDemo04.json");





	qDebug() << "finish";

}

void JsonDemo04Widget::readJson()
{

}
