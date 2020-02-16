#include "ChartDemo02Widget.h"

ChartDemo02Widget::ChartDemo02Widget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	init();
}

ChartDemo02Widget::~ChartDemo02Widget()
{
}

void ChartDemo02Widget::init()
{
	initChartView();
}

void ChartDemo02Widget::initChartView()
{
	QGridLayout *chartViewLayout = new QGridLayout();
	ui.bottomWidget->setLayout(chartViewLayout);

	QChart * chart = createLineChart();

	QChartView * lineChartView = new QChartView(chart);
	lineChartView->setRenderHint(QPainter::Antialiasing);
	chartViewLayout->addWidget(lineChartView, 1, 0);
	chartViewMap.insert("lineChartView", lineChartView);
}

QChart * ChartDemo02Widget::createLineChart()
{
	QChart *chart = new QChart();
	chart->setTitle("linechartÑÝÊ¾");
	chart->setAnimationOptions(QChart::SeriesAnimations);
	chartMap.insert("lineChart", chart);

	QDateTimeAxis *axisX = new QDateTimeAxis;
	axisX->setTickCount(20);
	axisX->setFormat("yyyyMMdd");
	axisX->setTitleText("Date");
	chart->addAxis(axisX, Qt::AlignBottom);


	QValueAxis *axisY = new QValueAxis;
	axisY->setLabelFormat("%i");
	axisY->setTitleText("Sunspots count");
	chart->addAxis(axisY, Qt::AlignLeft);
	

	for (int i = 0; i < 3; i++)
	{
		QLineSeries *series = new QLineSeries(chart);

		for (int j = 0; j < 10; j++)
		{
			QDateTime momentInTime = QDateTime::currentDateTime().addDays(j);
			series->append(QPointF(momentInTime.toMSecsSinceEpoch(), qrand() % 100));
		}
		chart->addSeries(series);
		series->attachAxis(axisX);
		series->attachAxis(axisY);
	}


	//chart->createDefaultAxes();
	return chart;

}
