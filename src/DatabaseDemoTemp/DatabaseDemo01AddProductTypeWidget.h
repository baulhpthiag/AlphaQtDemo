#pragma once

#include <QWidget>
#include "ui_DatabaseDemo01AddProductTypeWidget.h"

class DatabaseDemo01AddProductTypeWidget : public QWidget
{
	Q_OBJECT

public:
	DatabaseDemo01AddProductTypeWidget(QWidget *parent = Q_NULLPTR);
	~DatabaseDemo01AddProductTypeWidget();

private:
	Ui::DatabaseDemo01AddProductTypeWidget ui;

	//����

	//����

	//�¼�

	//qt��
protected slots:
void confirmButtonClicked();
void cancelButtonClicked();

	//qt�ź�
};
