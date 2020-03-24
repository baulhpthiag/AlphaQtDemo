#pragma once

#include <QtWidgets/QWidget>
#include "ui_DataSortMainWidget.h"

class DataSortMainWidget : public QWidget
{
	Q_OBJECT

public:
	DataSortMainWidget(QWidget *parent = Q_NULLPTR);

private:
	Ui::DataSortMainWidgetClass ui;

public slots:
void openCsvButtonClicked();
void writeCsvButtonClicked();
void readCsvButtonClicked();
void sort(QList<double> *list);


};
