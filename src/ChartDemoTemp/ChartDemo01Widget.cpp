#include "ChartDemo01Widget.h"

ChartDemo01Widget::ChartDemo01Widget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	init();
}

ChartDemo01Widget::~ChartDemo01Widget()
{

}

void ChartDemo01Widget::init()
{
	initThemeComboBox();
	initAnimationComboBox();
	initLegendComboBox();
	initChartView();
}

void ChartDemo01Widget::initChartView()
{
	QGridLayout *chartViewLayout = new QGridLayout();
	ui.bottomWidget->setLayout(chartViewLayout);

	QChartView * pieChartView = new QChartView(createPieChart());
	pieChartView->setRenderHint(QPainter::Antialiasing);
	chartViewLayout->addWidget(pieChartView, 1, 0);
	chartViewMap.insert("pieChartView", pieChartView);

	QChartView * areaChartView = new QChartView(createAreaChart());
	areaChartView->setRenderHint(QPainter::Antialiasing);
	chartViewLayout->addWidget(areaChartView, 1, 1);
	chartViewMap.insert("areaChartView", areaChartView);

	QChartView * barChartView = new QChartView(createBarChart());
	barChartView->setRenderHint(QPainter::Antialiasing);
	chartViewLayout->addWidget(barChartView, 1, 2);
	chartViewMap.insert("barChartView", barChartView);

	QChartView * lineChartView = new QChartView(createLineChart());
	lineChartView->setRenderHint(QPainter::Antialiasing);
	chartViewLayout->addWidget(lineChartView, 2, 0);
	chartViewMap.insert("lineChartView", lineChartView);

	QChartView * splineChartView = new QChartView(createSplineChart());
	splineChartView->setRenderHint(QPainter::Antialiasing);
	chartViewLayout->addWidget(splineChartView, 2, 1);
	chartViewMap.insert("splineChartView", splineChartView);

	QChartView * scatterChartView = new QChartView(createScatterChart());
	scatterChartView->setRenderHint(QPainter::Antialiasing);
	chartViewLayout->addWidget(scatterChartView, 2, 2);
	chartViewMap.insert("scatterChartView", scatterChartView);

}

void ChartDemo01Widget::initThemeComboBox()
{
	ui.themeComboBox->addItem("Light", QChart::ChartThemeLight);
	ui.themeComboBox->addItem("Blue Cerulean", QChart::ChartThemeBlueCerulean);
	ui.themeComboBox->addItem("Dark", QChart::ChartThemeDark);
	ui.themeComboBox->addItem("Brown Sand", QChart::ChartThemeBrownSand);
	ui.themeComboBox->addItem("Blue NCS", QChart::ChartThemeBlueNcs);
	ui.themeComboBox->addItem("High Contrast", QChart::ChartThemeHighContrast);
	ui.themeComboBox->addItem("Blue Icy", QChart::ChartThemeBlueIcy);
	ui.themeComboBox->addItem("Qt", QChart::ChartThemeQt);
}

void ChartDemo01Widget::initAnimationComboBox()
{
	ui.animationComboBox->addItem("No Animations", QChart::NoAnimation);
	ui.animationComboBox->addItem("GridAxis Animations", QChart::GridAxisAnimations);
	ui.animationComboBox->addItem("Series Animations", QChart::SeriesAnimations);
	ui.animationComboBox->addItem("All Animations", QChart::AllAnimations);
}

void ChartDemo01Widget::initLegendComboBox()
{
	ui.legendComboBox->addItem("No Legend ", 0);
	ui.legendComboBox->addItem("Legend Top", Qt::AlignTop);
	ui.legendComboBox->addItem("Legend Bottom", Qt::AlignBottom);
	ui.legendComboBox->addItem("Legend Left", Qt::AlignLeft);
	ui.legendComboBox->addItem("Legend Right", Qt::AlignRight);
}

QChart * ChartDemo01Widget::createPieChart()
{
	QChart *chart = new QChart();
	chart->setTitle(" Piechart演示");

	//设置动画效果
	chart->setAnimationOptions(QChart::SeriesAnimations);
	chartMap.insert("pieChart", chart);

	QPieSeries *series = new QPieSeries(chart);
	series->clear();
	series->append("a", qrand() % 10);
	series->append("b", qrand() % 10);
	series->append("c", qrand() % 10);
	series->setLabelsVisible(true);
	chart->addSeries(series);

	//设置legend
	chart->legend()->setBackgroundVisible(true);
	chart->legend()->setBrush(QBrush(QColor(128, 128, 128, 128)));
	chart->legend()->setPen(QPen(QColor(192, 192, 192, 192)));
	//设置legend字体
	QFont font = chart->legend()->font();
	font.setBold(!font.bold());
	chart->legend()->setFont(font);


	return chart;
}

QChart * ChartDemo01Widget::createAreaChart()
{
	QChart *chart = new QChart();
	chart->setTitle("Areachart演示");
	chart->setAnimationOptions(QChart::SeriesAnimations);
	chartMap.insert("areaChart", chart);

	QLineSeries *lowerSeries = 0;
	for (int j = 0; j < 3; j++)
	{
		lowerSeries = new QLineSeries(chart);
		lowerSeries->clear();
		QLineSeries *upperSeries = new QLineSeries(chart);
		upperSeries->clear();

		for (int i = 0; i < 5; i++)
		{
			if (lowerSeries->count() > 0)
			{
				const QVector<QPointF>& points = lowerSeries->pointsVector();
				upperSeries->append(QPointF(i, points[i].y() + qrand() % 5));
			}
			else
			{
				upperSeries->append(QPointF(i, qrand() % 5));
			}

		}
		QAreaSeries *area = new QAreaSeries(upperSeries, lowerSeries);
		area->setName("area实例");

		chart->addSeries(area);
		lowerSeries = upperSeries;
	}

	//设置坐标轴
	chart->createDefaultAxes();
	//设置x坐标轴范围
	chart->axisX()->setRange(0, 20);
	//设置y坐标轴范围
	chart->axisY()->setRange(0, 10);
	return chart;
}

QChart * ChartDemo01Widget::createBarChart()
{
	QChart *chart = new QChart();
	chart->setTitle("BarChart演示");
	chart->setAnimationOptions(QChart::SeriesAnimations);
	chartMap.insert("barChart", chart);

	QStackedBarSeries *series = new QStackedBarSeries(chart);

	for (int i = 0; i < 3; i++)
	{
		QBarSet *set = new QBarSet("Bar set " + QString::number(i));
		for (int j = 0; j < 5; j++)
		{
			set->append(qrand() % 10);
		}
		series->append(set);
	}
	chart->addSeries(series);
	chart->createDefaultAxes();

	return chart;
}

QChart * ChartDemo01Widget::createLineChart()
{
	QChart *chart = new QChart();
	chart->setTitle("linechart演示");
	chart->setAnimationOptions(QChart::SeriesAnimations);
	chartMap.insert("lineChart", chart);

	for (int i = 0; i < 3; i++)
	{
		QLineSeries *series = new QLineSeries(chart);

		for (int j = 0; j < 10; j++)
		{
			series->append(QPointF(j, qrand() % 100));
		}
		chart->addSeries(series);

	}
	chart->createDefaultAxes();
	return chart;
}

QChart * ChartDemo01Widget::createSplineChart()
{
	// spine chart
	QChart *chart = new QChart();
	chart->setTitle("splinechart演示");
	chart->setAnimationOptions(QChart::SeriesAnimations);
	chartMap.insert("splineChart", chart);

	for (int i = 0; i < 3; i++)
	{
		QSplineSeries *series = new QSplineSeries(chart);
		series->setName("spline" + QString::number(i));
		for (int j = 0; j < 10; j++)
		{
			series->append(QPointF(j, qrand() % 30));
		}
		chart->addSeries(series);
	}

	chart->createDefaultAxes();
	return chart;
}

QChart * ChartDemo01Widget::createScatterChart()
{
	QChart *chart = new QChart();
	chart->setTitle("scatterchart演示");
	chart->setAnimationOptions(QChart::SeriesAnimations);
	chartMap.insert("scatterChart", chart);

	for (int i = 0; i < 3; i++)
	{
		QScatterSeries *series = new QScatterSeries(chart);
		series->setName("scatter" + QString::number(i));
		for (int j = 0; j < 10; j++)
		{
			series->append(QPointF(j, qrand() % 30));
		}
		chart->addSeries(series);
	}

	chart->createDefaultAxes();
	return chart;
}

void ChartDemo01Widget::updatePieChartButtonClicked()
{
	QChart *chart = chartMap.value("pieChart");

	chart->removeAllSeries();
	QPieSeries *series = new QPieSeries();
	series->clear();
	series->append("a", qrand() % 10);
	series->append("b", qrand() % 10);
	series->append("c", qrand() % 10);

	series->setLabelsVisible(true);
	chart->addSeries(series);

}

void ChartDemo01Widget::themeComboBoxCurrentIndexChanged()
{
	QChart::ChartTheme theme = (QChart::ChartTheme) ui.themeComboBox->itemData(ui.themeComboBox->currentIndex()).toInt();
	for each (QString key in chartViewMap.keys())
	{
		QChartView * chartView=chartViewMap.value(key);
		chartView->chart()->setTheme(theme);
		QPalette pal = window()->palette();
		if (theme == QChart::ChartThemeLight) {
			pal.setColor(QPalette::Window, QRgb(0xf0f0f0));
			pal.setColor(QPalette::WindowText, QRgb(0x404044));
		}
		else if (theme == QChart::ChartThemeDark) {
			pal.setColor(QPalette::Window, QRgb(0x121218));
			pal.setColor(QPalette::WindowText, QRgb(0xd6d6d6));
		}
		else if (theme == QChart::ChartThemeBlueCerulean) {
			pal.setColor(QPalette::Window, QRgb(0x40434a));
			pal.setColor(QPalette::WindowText, QRgb(0xd6d6d6));
		}
		else if (theme == QChart::ChartThemeBrownSand) {
			pal.setColor(QPalette::Window, QRgb(0x9e8965));
			pal.setColor(QPalette::WindowText, QRgb(0x404044));
		}
		else if (theme == QChart::ChartThemeBlueNcs) {
			pal.setColor(QPalette::Window, QRgb(0x018bba));
			pal.setColor(QPalette::WindowText, QRgb(0x404044));
		}
		else if (theme == QChart::ChartThemeHighContrast) {
			pal.setColor(QPalette::Window, QRgb(0xffab03));
			pal.setColor(QPalette::WindowText, QRgb(0x181818));
		}
		else if (theme == QChart::ChartThemeBlueIcy) {
			pal.setColor(QPalette::Window, QRgb(0xcee7f0));
			pal.setColor(QPalette::WindowText, QRgb(0x404044));
		}
		else {
			pal.setColor(QPalette::Window, QRgb(0xf0f0f0));
			pal.setColor(QPalette::WindowText, QRgb(0x404044));
		}
		window()->setPalette(pal);

	}

}

void ChartDemo01Widget::animationComboBoxCurrentIndexChanged()
{
	QChart::AnimationOptions options(ui.animationComboBox->itemData(ui.animationComboBox->currentIndex()).toInt());
	for each (QString key in chartViewMap.keys())
	{
		QChartView * chartView = chartViewMap.value(key);
		chartView->chart()->setAnimationOptions(options);
	}

}

void ChartDemo01Widget::legendComboBoxCurrentIndexChanged()
{
	Qt::Alignment alignment(ui.legendComboBox->itemData(ui.legendComboBox->currentIndex()).toInt());

	if (!alignment) {
		for each (QString key in chartViewMap.keys())
		{
			QChartView * chartView = chartViewMap.value(key);
			chartView->chart()->legend()->hide();
		}
		
	}
	else {
	
		for each (QString key in chartViewMap.keys())
		{
			QChartView * chartView = chartViewMap.value(key);
			chartView->chart()->legend()->setAlignment(alignment);
			chartView->chart()->legend()->show();
		}
	}
}
