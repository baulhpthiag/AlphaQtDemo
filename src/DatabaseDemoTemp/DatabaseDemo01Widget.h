#pragma once

#ifdef WIN32  
#pragma execution_character_set("utf-8")  
#endif

#include <QWidget>
#include "ui_DatabaseDemo01Widget.h"
#include "DatabaseDemo01AddProductTypeWidget.h"
#include "DatabaseDemo01AddDetectLogWidget.h"
#include <QList>
#include "CommonDataStruct.h"
#include <QtCharts>


class DatabaseDemo01Widget : public QWidget
{
	Q_OBJECT

public:
	DatabaseDemo01Widget(QWidget *parent = Q_NULLPTR);
	~DatabaseDemo01Widget();

private:
	Ui::DatabaseDemo01Widget ui;

	//属性
private:
	DatabaseDemo01AddProductTypeWidget * databaseDemo01AddProductTypeWidget;
	DatabaseDemo01AddDetectLogWidget * databaseDemo01AddDetectLogWidget;
	QList<ProductType> productTypeList;
	QList<DetectLog> detectLogList;
	

	bool initChart = false;
	//方法
private:
	void init();
	void updateDetectLogTableWidget();
	void updateProductTypeTableWidget();
	void updateProductTypeComboBox();
	void updateChartViewWidget();
	void initChartView();

	//事件

	//qt槽
protected slots:
	void initDatabaseButtonClicked();

	void addProductTypeButtonClicked();
	void findProductTypeButtonClicked();

	void addDetectLogButtonClicked();
	void findDetectLogButtonClicked();



	//qt信号
};
