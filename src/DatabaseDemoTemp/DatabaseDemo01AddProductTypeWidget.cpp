#include "DatabaseDemo01AddProductTypeWidget.h"
#include <QSqlQuery>
#include <QUuid>
#include <QDateTime>
#include <QDebug>
#include <QSqlError>

DatabaseDemo01AddProductTypeWidget::DatabaseDemo01AddProductTypeWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

DatabaseDemo01AddProductTypeWidget::~DatabaseDemo01AddProductTypeWidget()
{
}

void DatabaseDemo01AddProductTypeWidget::confirmButtonClicked()
{
	QString productTypeName = ui.productTypeNameLineEdit->text();
	if (productTypeName.isEmpty())
	{
		return;
	}

	QString querystring;
	QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
	db.setHostName("localhost");
	db.setPort(3306);
	db.setUserName("root");
	db.setPassword("root");
	db.setDatabaseName("db_test01");
	if (!db.open())
	{
		qDebug() << "opened database error";
		return;
	}
	else
	{
		qDebug() << "opened database success";
	}

	QSqlQuery query;
	query.prepare("INSERT INTO tb_product_type (typeid,typename,createdatetime) VALUES (?,?,?)"); //准备执行SQL查询  

	QUuid uuid = QUuid::createUuid();
	QString id = uuid.toString();
	query.addBindValue(id);

	query.addBindValue(productTypeName);

	QDateTime time = QDateTime::currentDateTime();
	QString timestr = time.toString("yyyyMMddhhmmss");
	query.addBindValue(timestr);

	query.exec();

	if (query.lastError().isValid())
	{
		qDebug() << query.lastError();
		qDebug() << "insert database tb_product_type failed.";
		return;
	}
	else
	{
		qDebug() << "insert database tb_product_type success";
	}
	
}

void DatabaseDemo01AddProductTypeWidget::cancelButtonClicked()
{

}
