#pragma once
#ifdef WIN32  
#pragma execution_character_set("utf-8")  
#endif

#include <QWidget>
#include "ui_ChartDemo02Widget.h"
#include <QtCharts>

class ChartDemo02Widget : public QWidget
{
	Q_OBJECT

public:
	ChartDemo02Widget(QWidget *parent = Q_NULLPTR);
	~ChartDemo02Widget();

private:
	Ui::ChartDemo02Widget ui;
private:
	QMap<QString, QChart *> chartMap;
	QMap<QString, QChartView *>chartViewMap;
private:
	void init();
	void initChartView();
	QChart * createLineChart();
protected slots:
	

};
