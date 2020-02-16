#include "DatabaseDemo01AddDetectLogWidget.h"
#include <QSqlQuery>
#include <QUuid>
#include <QDateTime>
#include <QDebug>
#include <QSqlError>

DatabaseDemo01AddDetectLogWidget::DatabaseDemo01AddDetectLogWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	init();
}

DatabaseDemo01AddDetectLogWidget::~DatabaseDemo01AddDetectLogWidget()
{
}

void DatabaseDemo01AddDetectLogWidget::init()
{
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
	productTypeList.clear();

	QSqlQuery query;
	query.prepare("select * from  tb_product_type "); //准备执行SQL查询  

	if (!query.exec())
	{
		qDebug() << query.lastError();
		qDebug() << "operate fail : select * from  tb_product_type";
		return;

	}
	else
	{
		qDebug() << "operate success : insert database tb_product_type";

		productTypeList.clear();
		while (query.next())
		{
			ProductType tempProductType;
			tempProductType.TypeId = query.value(0).toString();
			tempProductType.TypeName = query.value(1).toString();
			tempProductType.CreateDatetime = query.value(2).toDateTime();
			productTypeList.append(tempProductType);
		}

		updateProductTypeComboBox();
	}


}

void DatabaseDemo01AddDetectLogWidget::updateProductTypeComboBox()
{
	ui.productTypeComboBox->clear();
	for (int i =0;i<productTypeList.count();i++)
	{
		ui.productTypeComboBox->addItem(productTypeList.at(i).TypeName);
	}
}

void DatabaseDemo01AddDetectLogWidget::confirmButtonClicked()
{
	QUuid uuid = QUuid::createUuid();
	QString id = uuid.toString();
	int okCount = ui.okCountLineEdit->text().toInt();
	int ngCount = ui.ngCountLineEdit->text().toInt();
	int nullCount = ui.nullCountLineEdit->text().toInt();
	QDateTime time = QDateTime::currentDateTime();
	QString timestr = time.toString("yyyyMMddhhmmss");
	QString productTypeId = productTypeList.at(ui.productTypeComboBox->currentIndex()).TypeId;
	

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
	query.prepare("INSERT INTO tb_detect_log (logid ,okcount,ngcount,nullcount,createdatetime,producttypeid) VALUES (?,?,?,?,?,?)"); //准备执行SQL查询  

	query.addBindValue(id);
	query.addBindValue(okCount);
	query.addBindValue(ngCount);
	query.addBindValue(nullCount);
	query.addBindValue(timestr);
	query.addBindValue(productTypeId);

	query.exec();

	if (query.lastError().isValid())
	{
		qDebug() << query.lastError();
		qDebug() << "insert table tb_detect_log failed";
		return;
	}
	else
	{
		qDebug() << "insert table tb_detect_log success";
	}


}

void DatabaseDemo01AddDetectLogWidget::cancelButtonClicked()
{

}
