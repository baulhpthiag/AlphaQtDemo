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

	//����
private:
	QList<ProductType> productTypeList;
	//����
private:
	void init();
	void updateProductTypeComboBox();
	//�¼�

	//qt��
protected slots:
void confirmButtonClicked();
void cancelButtonClicked();

	//qt�ź�
};
