#include "DatabaseDemo02Widget.h"
#include <QDebug>
#include "DBUtil.h"
#include "CommonDataStruct.h"
#include "ProductTypeDao.h"
#include <QUuid>
#include "Json.h"

DatabaseDemo02Widget::DatabaseDemo02Widget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	init();
}

DatabaseDemo02Widget::~DatabaseDemo02Widget()
{

}

void DatabaseDemo02Widget::init()
{
	initUi();
	initDb();
}

void DatabaseDemo02Widget::initUi()
{
	//列宽自适应
	ui.productTypeTableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	ui.productTypeTableWidget->setColumnCount(3);
	ui.productTypeTableWidget->setHorizontalHeaderLabels(QStringList() << "产品id" << "产品名称" << "产品创建日期");
	ui.productTypeTableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
	ui.productTypeTableWidget->setRowCount(0);
}

void DatabaseDemo02Widget::initDb()
{
	DBUtil::initDb();
}

void DatabaseDemo02Widget::findButtonClicked()
{
	//ProductType productType = ProductTypeDao::findById("");
	QList<ProductType> productTypes = ProductTypeDao::findAll();

	ui.productTypeTableWidget->clearContents();
	ui.productTypeTableWidget->setRowCount(productTypes.count());

	for (int i = 0; i < productTypes.count(); i++)
	{
		ui.productTypeTableWidget->setItem(i, 0, new QTableWidgetItem(productTypes.at(i).TypeId));
		ui.productTypeTableWidget->setItem(i, 1, new QTableWidgetItem(productTypes.at(i).TypeName));
		ui.productTypeTableWidget->setItem(i, 2, new QTableWidgetItem(productTypes.at(i).CreateDatetime.toString("yyyy-MM-dd hh:mm:ss")));
	}
}

void DatabaseDemo02Widget::addButtonClicked()
{
	ProductType productType;
	productType.TypeId = QUuid::createUuid().toString();
	productType.TypeName = "ProductType"+QDateTime::currentDateTime().toString("yyyyMMddhhmmss");
	productType.CreateDatetime = QDateTime::currentDateTime();
	bool result = ProductTypeDao::insert(productType);
}

void DatabaseDemo02Widget::updateButtonClicked()
{
	QString id = ui.productTypeTableWidget->item(ui.productTypeTableWidget->currentRow(),0)->text();
	ProductType productType = ProductTypeDao::findById(id);
	productType.TypeName = productType.TypeName + "update";
	bool result = ProductTypeDao::update(productType);

}

void DatabaseDemo02Widget::deleteButtonClicked()
{
	QString id = ui.productTypeTableWidget->item(ui.productTypeTableWidget->currentRow(), 0)->text();
	bool result = ProductTypeDao::deleteById(id);
}
