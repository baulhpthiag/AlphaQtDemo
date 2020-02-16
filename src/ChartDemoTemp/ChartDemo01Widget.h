#pragma once

#ifdef WIN32  
#pragma execution_character_set("utf-8")  
#endif

#include <QWidget>
#include "ui_ChartDemo01Widget.h"
#include <QtCharts>

class ChartDemo01Widget : public QWidget
{
	Q_OBJECT

public:
	ChartDemo01Widget(QWidget *parent = Q_NULLPTR);
	~ChartDemo01Widget();

private:
	Ui::ChartDemo01Widget ui;

private:
	QMap<QString, QChart *> chartMap;
	QMap<QString, QChartView *>chartViewMap;

private:
	void init();
	void initChartView();
	void initThemeComboBox();
	void initAnimationComboBox();
	void initLegendComboBox();
	QChart * createPieChart();
	QChart * createAreaChart();
	QChart * createBarChart();
	QChart * createLineChart();
	QChart * createSplineChart();
	QChart * createScatterChart();


	protected slots:
	void updatePieChartButtonClicked();
	void themeComboBoxCurrentIndexChanged();
	void animationComboBoxCurrentIndexChanged();
	void legendComboBoxCurrentIndexChanged();



};
