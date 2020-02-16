#include "DatabaseDemo01Widget.h"
#include <Qtsql/QSqlDatabase>
#include <Qtsql/QSqlQuery>
#include <QtSql/QSql>
#include <QtSql/QSqlError>
#include <QDebug>


DatabaseDemo01Widget::DatabaseDemo01Widget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	init();
}

DatabaseDemo01Widget::~DatabaseDemo01Widget()
{

}

void DatabaseDemo01Widget::init()
{
	databaseDemo01AddProductTypeWidget = new DatabaseDemo01AddProductTypeWidget;
	databaseDemo01AddDetectLogWidget = new DatabaseDemo01AddDetectLogWidget;

	QDateTime startTime = QDateTime::currentDateTime().addMonths(-6);
	ui.startDateTimeEdit->setDateTime(startTime);
	ui.stopDateTimeEdit->setDateTime(QDateTime::currentDateTime());

	//�п�����Ӧ
	ui.productTypeTableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	ui.productTypeTableWidget->setColumnCount(3);
	ui.productTypeTableWidget->setHorizontalHeaderLabels(QStringList() << "��Ʒid" << "��Ʒ����"<<"��Ʒ��������");
	ui.productTypeTableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
	ui.productTypeTableWidget->setRowCount(0);

	//�п�����Ӧ
	ui.detectLogTableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	ui.detectLogTableWidget->setColumnCount(6);
	ui.detectLogTableWidget->setHorizontalHeaderLabels(QStringList() << "��¼id" << "okCount" <<"ngCount"<<"nullCount"<<"����"<< "��Ʒid");
	ui.detectLogTableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
	ui.detectLogTableWidget->setRowCount(0);

	updateProductTypeComboBox();
	initChartView();
}

void DatabaseDemo01Widget::updateProductTypeTableWidget()
{
	ui.productTypeTableWidget->clearContents();
	ui.productTypeTableWidget->setRowCount(productTypeList.count());

	for (int i = 0;i<productTypeList.count();i++)
	{
		ui.productTypeTableWidget->setItem(i, 0, new QTableWidgetItem(productTypeList.at(i).TypeId));
		ui.productTypeTableWidget->setItem(i, 1, new QTableWidgetItem(productTypeList.at(i).TypeName));
		ui.productTypeTableWidget->setItem(i, 2, new QTableWidgetItem(productTypeList.at(i).CreateDatetime.toString("yyyy-MM-dd hh:mm:ss")));
	}
}

void DatabaseDemo01Widget::updateProductTypeComboBox()
{
	QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
	db.setHostName("localhost");
	db.setPort(3306);
	db.setUserName("root");
	db.setPassword("root");
	db.setDatabaseName("db_test01");
	if (!db.open())
	{
		qDebug() << "opened database error";
		return;
	}
	else
	{
		qDebug() << "opened database success";
	}
	productTypeList.clear();

	QSqlQuery query;
	query.prepare("select * from  tb_product_type "); //׼��ִ��SQL��ѯ  

	if (!query.exec())
	{
		qDebug() << query.lastError();
		qDebug() << "operate fail : select * from  tb_product_type";
		return;

	}
	else
	{
		qDebug() << "operate success : insert database tb_product_type";

		productTypeList.clear();
		while (query.next())
		{
			ProductType tempProductType;
			tempProductType.TypeId = query.value(0).toString();
			tempProductType.TypeName = query.value(1).toString();
			tempProductType.CreateDatetime = query.value(2).toDateTime();
			productTypeList.append(tempProductType);
		}

		ui.productTypeComboBox->clear();
		for (int i = 0; i < productTypeList.count(); i++)
		{
			ui.productTypeComboBox->addItem(productTypeList.at(i).TypeName);
		}
	}

}

void DatabaseDemo01Widget::updateChartViewWidget()
{

	//int okSum = 0;
	//int ngSum = 0;
	//int nullSum = 0;
	//for (int i=0;i<detectLogList.count();i++)
	//{
	//	DetectLog temp = detectLogList.at(i);
	//	okSum += temp.OkCount;
	//	ngSum += temp.NgCount;
	//	nullSum += temp.NullCount;
	//}
	//
	//series->clear();
	//series->append("�ϸ�����", okSum);     //��ӱ�ǩ"ˮ��:30%" �� �ٷ�ֵ30%
	//series->append("���ϸ�����", ngSum);
	//series->append("��Ƭ����", nullSum);

	//if (!initChart)
	//{
	//	series->setLabelsVisible(true);
	//	series->setUseOpenGL(true);
	//	series->slices().at(0)->setColor(QColor(13, 128, 217));   //������ɫ
	//	series->slices().at(0)->setLabelColor(QColor(13, 128, 217));

	//	series->slices().at(1)->setColor(QColor(69, 13, 217));
	//	series->slices().at(1)->setLabelColor(QColor(69, 13, 217));

	//	series->slices().at(2)->setColor(QColor(13, 217, 152));
	//	series->slices().at(2)->setLabelColor(QColor(13, 217, 152));

	//	m_chart->setTheme(QChart::ChartThemeLight);//���ð�ɫ����
	//	m_chart->setDropShadowEnabled(true);//������Ӱ

	//	m_chart->setTitleBrush(QBrush(QColor(0, 0, 255)));//���ñ���Brush
	//	m_chart->setTitleFont(QFont("΢���ź�"));//���ñ�������
	//	m_chart->setTitle("��״ͼ");


	//	//�޸�˵����ʽ
	//	m_chart->legend()->setVisible(true);
	//	m_chart->legend()->setAlignment(Qt::AlignBottom);//�ײ�����
	//	m_chart->legend()->setBackgroundVisible(true);//���ñ����Ƿ����
	//	m_chart->legend()->setAutoFillBackground(true);//���ñ����Զ����
	//	m_chart->legend()->setColor(QColor(222, 233, 251));//������ɫ
	//	m_chart->legend()->setLabelColor(QColor(0, 100, 255));//���ñ�ǩ��ɫ
	//	m_chart->legend()->setMaximumHeight(50);



	//	chartView = new QChartView(m_chart);
	//	chartView->setRenderHint(QPainter::Antialiasing);


	//	chartLayout = new QVBoxLayout(ui.chartViewWidget);
	//	chartLayout->addWidget(chartView);
	//}
	//m_chart->addSeries(series);//���ϵ�е�QChart��
	//
	//

	//update();
	QChart *chart = ui.chartViewWidget->chart(); //��ȡchart����
	chart->removeAllSeries(); //ɾ����������


	QPieSeries *series = new QPieSeries(); //������ͼ����
	//series->setHoleSize(ui->spinHoleSize->value()); //��ͼ�м���ĵĴ�С


	int okSum = 0;
	int ngSum = 0;
	int nullSum = 0;
	for (int i=0;i<detectLogList.count();i++)
	{
		DetectLog temp = detectLogList.at(i);
		okSum += temp.OkCount;
		ngSum += temp.NgCount;
		nullSum += temp.NullCount;
	}
	
	series->clear();
	series->append("�ϸ�����", okSum);     //��ӱ�ǩ"ˮ��:30%" �� �ٷ�ֵ30%
	series->append("���ϸ�����", ngSum);
	series->append("��Ƭ����", nullSum);



	series->setLabelsVisible(true); //ֻӰ�쵱ǰ��slices�����������slice֮��������
	chart->addSeries(series); //��ӱ�ͼ����
	chart->setTitle("��״ͼ");

	chart->legend()->setVisible(true); //ͼ��
	chart->legend()->setAlignment(Qt::AlignRight);//Qt::AlignRight

}

void DatabaseDemo01Widget::initChartView()
{
	QChart *chart = new QChart();
	chart->setTitle(" Piechart��ʾ");
	chart->setAnimationOptions(QChart::SeriesAnimations);
	ui.chartViewWidget->setChart(chart);
	ui.chartViewWidget->setRenderHint(QPainter::Antialiasing);

}

void DatabaseDemo01Widget::updateDetectLogTableWidget()
{
	ui.detectLogTableWidget->clearContents();
	ui.detectLogTableWidget->setRowCount(detectLogList.count());

	for (int i = 0; i < detectLogList.count(); i++)
	{
		ui.detectLogTableWidget->setItem(i, 0, new QTableWidgetItem(detectLogList.at(i).LogId));
		ui.detectLogTableWidget->setItem(i, 1, new QTableWidgetItem(QString::number(detectLogList.at(i).OkCount)));
		ui.detectLogTableWidget->setItem(i, 2, new QTableWidgetItem(QString::number(detectLogList.at(i).NgCount)));
		ui.detectLogTableWidget->setItem(i, 3, new QTableWidgetItem(QString::number(detectLogList.at(i).NullCount)));
		ui.detectLogTableWidget->setItem(i, 4, new QTableWidgetItem(detectLogList.at(i).CreateDatetime.toString("yyyy-MM-dd hh:mm:ss")));
		ui.detectLogTableWidget->setItem(i, 5, new QTableWidgetItem(detectLogList.at(i).ProductTypeId));
	}
}

void DatabaseDemo01Widget::initDatabaseButtonClicked()
{
	QString querystring;
	QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
	db.setHostName("localhost");
	db.setPort(3306);
	db.setUserName("root");
	db.setPassword("root");
	//db.setDatabaseName("test_db");
	if (!db.open())
	{
		qDebug() << "opened database error";
		return;
	}
	else
	{
		qDebug() << "opened database success";
	}
	
	//�������ݿ�	
	querystring = "CREATE DATABASE IF NOT EXISTS db_test01 default character set = 'utf8'";
	db.exec(querystring);

	if (db.lastError().isValid())
	{
		qDebug() << db.lastError();
		qDebug() << "Create database db_test01 failed.";
		return;
	}
	else
	{
		qDebug() << "Create database db_test01 successfully.";
	}

	db.setDatabaseName("db_test01");
	//���µ���һ��open()�������"QSqlQuery::exec: database not open"  
	db.open();

	//������tb_detect_log

	querystring =
	"create table if not exists tb_detect_log\
		(\
			logid                varchar(38) not null,\
			okcount              int,\
			ngcount              int,\
			nullcount            int,\
			createdatetime       datetime,\
			producttypeid        varchar(38),\
			primary key(logid)\
    )";
	db.exec(querystring);

	if (db.lastError().isValid())
	{
		qDebug() << db.lastError();
		qDebug() << "Create table tb_detect_log failed.";
		return;
	}
	else
	{
		qDebug() << "Create database  tb_detect_log successfully.";
	}

	//������tb_product_type
	querystring =
		"create table if not exists tb_product_type\
		(\
			typeid               varchar(38) not null,\
			typename             varchar(100),\
			createdatetime       datetime,\
			primary key(typeid)\
    )";
	db.exec(querystring);

	if (db.lastError().isValid())
	{
		qDebug() << db.lastError();
		qDebug() << "Create database tb_product_type failed.";
		return;
	}
	else
	{
		qDebug() << "Create database tb_product_type successfully.";
	}

	 
}

void DatabaseDemo01Widget::addProductTypeButtonClicked()
{
	databaseDemo01AddProductTypeWidget->show();
}

void DatabaseDemo01Widget::findProductTypeButtonClicked()
{
	QSqlQuery query;
	query.prepare("select * from  tb_product_type "); //׼��ִ��SQL��ѯ  
	
	if (!query.exec())
	{
		qDebug() << query.lastError();
		qDebug() << "operate fail : select * from  tb_product_type";
		return;

	}
	else
	{
		qDebug() << "operate success : insert database tb_product_type";

		productTypeList.clear();
		while (query.next())
		{
			ProductType tempProductType;
			tempProductType.TypeId = query.value(0).toString();
			tempProductType.TypeName = query.value(1).toString();
			tempProductType.CreateDatetime = query.value(2).toDateTime();
			productTypeList.append(tempProductType);
		}
		updateProductTypeTableWidget();

	}




}

void DatabaseDemo01Widget::addDetectLogButtonClicked()
{
	databaseDemo01AddDetectLogWidget->show();
}

void DatabaseDemo01Widget::findDetectLogButtonClicked()
{
	QDateTime startDateTime=ui.startDateTimeEdit->dateTime();
	QDateTime stopDateTime = ui.stopDateTimeEdit->dateTime();

	QSqlQuery query;
	query.prepare("select * from  tb_detect_log where createdatetime > ? and createdatetime <? "); //׼��ִ��SQL��ѯ  
	query.addBindValue(startDateTime);
	query.addBindValue(stopDateTime);


	if (!query.exec())
	{
		qDebug() << query.lastError();
		qDebug() << "operate fail : select * from  tb_product_type";
		return;

	}
	else
	{
		qDebug() << "operate success : insert database tb_product_type";

		detectLogList.clear();
		while (query.next())
		{
			DetectLog tempDetectLog;
			tempDetectLog.LogId = query.value(0).toString();
			tempDetectLog.OkCount = query.value(1).toInt();
			tempDetectLog.NgCount = query.value(2).toInt();
			tempDetectLog.NullCount = query.value(3).toInt();
			tempDetectLog.CreateDatetime = query.value(4).toDateTime();
			tempDetectLog.ProductTypeId = query.value(5).toString();

			detectLogList.append(tempDetectLog);
		}
		updateDetectLogTableWidget();
		updateChartViewWidget();
	}



}
