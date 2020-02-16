#pragma once

#include <QtWidgets/QWidget>
#include "ui_ChartDemoWidget.h"
#include <QVBoxLayout>
#include "ChartDemo01Widget.h"
#include "ChartDemo02Widget.h"

class ChartDemoWidget : public QWidget
{
	Q_OBJECT

public:
	ChartDemoWidget(QWidget *parent = Q_NULLPTR);

private:
	Ui::ChartDemoWidgetClass ui;

private:
	QVBoxLayout * bottomWidgetLayout = NULL;
	QList<QWidget *> demoWidgets;
	ChartDemo01Widget * chartDemo01Widget = NULL;
	ChartDemo02Widget * chartDemo02Widget = NULL;

private:
	void init();


protected slots:
	void comboBoxCurrentIndexChanged();


};
