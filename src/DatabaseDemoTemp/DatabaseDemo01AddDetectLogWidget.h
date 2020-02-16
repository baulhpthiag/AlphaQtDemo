#pragma once

#include <QWidget>
#include "ui_DatabaseDemo01AddDetectLogWidget.h"
#include <QList>
#include "CommonDataStruct.h"

class DatabaseDemo01AddDetectLogWidget : public QWidget
{
	Q_OBJECT

public:
	DatabaseDemo01AddDetectLogWidget(QWidget *parent = Q_NULLPTR);
	~DatabaseDemo01AddDetectLogWidget();

private:
	Ui::DatabaseDemo01AddDetectLogWidget ui;

	//属性
private:
	QList<ProductType> productTypeList;
	//方法
private:
	void init();
	void updateProductTypeComboBox();
	//事件

	//qt槽
protected slots:
void confirmButtonClicked();
void cancelButtonClicked();

	//qt信号
};
