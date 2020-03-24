#include "DataSortMainWidget.h"
#include <QFileDialog>
#include <QDebug>
#include <QApplication>
#include <QMessageBox>
#include <QTextCodec>

DataSortMainWidget::DataSortMainWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

void DataSortMainWidget::openCsvButtonClicked()
{
	QString fileName=QFileDialog::getOpenFileName();
	qDebug() << fileName;


	if (fileName == "")
		return;

	QDir dir = QDir::current();
	QFile file(dir.filePath(fileName));
	if (!file.open(QIODevice::ReadOnly))
		qDebug() << "OPEN FILE FAILED";
	QTextStream * out = new QTextStream(&file);//文本流

	QStringList tempOption = out->readAll().split("\n");//每行以\n区分

	QList<QList<double>> list0;

	int rowCount = tempOption.count();
	int colCount = tempOption.at(0).split(",").size();

	for (int i = 0; i < rowCount; i++)
	{
		QList<double> temp;
		list0.append(temp);
	}

	QList<QList<double>> list1;
	for (int i=0;i<colCount;i++)
	{
		QList<double> temp;
		list1.append(temp);
	}


	for (int i = 0; i < tempOption.count(); i++)
	{
		QStringList tempbar = tempOption.at(i).split(",");//一行中的单元格以，区分
		for (int j=0;j<tempbar.size();j++)
		{
			QString cell=tempbar.at(j);
			double cellD = cell.toDouble();

			list0[i].append(cellD);
			
		}
	}
	list0.pop_back();

	//for (int i=0;i<srclist.count();i++)
	//{
	//	QString line;
	//	for (int j =0;j<srclist.at(i).count();j++)
	//	{
	//		line += "x"+QString::number(i) +"y"+ QString::number(j);
	//	}
	//	qDebug() << line;
	//}

	
	for (int i=0;i<list0.count();i++ )
	{
		for (int j=0;j<list0.at(i).count();j++)
		{

			list1[j].append(list0.at(i).at(j));
		}
	}

	for (int i = 0; i < list1.count(); i++)
	{
		QList<double> * temp = &list1[i];
		qSort(temp->begin(), temp->end(), []( const double &a, const double &b) {
			return a > b; });
	}


	for (int i = 0; i < list0.count(); i++)
	{
		for (int j = 0; j < list0.at(i).count(); j++)
		{
			list0[i][j] = list1[j][i];
		
		}
	}



	ui.tableWidget->clearContents();
	ui.tableWidget->setColumnCount(list0[0].count());
	ui.tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
	ui.tableWidget->setRowCount(list0.count());


	for (int i = 0; i < list0.count(); i++)
	{
		for (int j = 0; j < list0.at(i).count(); j++)
		{
			QList<double> temp = list0.at(i);
			double d = temp.at(j);
			ui.tableWidget->setItem(i, j, new QTableWidgetItem(QString::number(d)));
		}
	}

	qDebug() << "finish";
	file.close();//操作完成后记得关闭文件




}

void DataSortMainWidget::writeCsvButtonClicked()
{




	QString path = qApp->applicationDirPath()+"/testWriteCsv.csv";
	
	QFile csvFile(path);

	QStringList lines;
	QString  line1 = QString::fromLocal8Bit("你好啊Hello测试中\r\n");

	lines << "00,1,"+ line1 +"\n" << "aaa,false,12\n" << "20,21,22";
	/*如果以ReadWrite方式打开，不会把所有数据清除，如果文件原来的长度为100字节，写操作写入了30字节，那么还剩余70字节，并且这70字节和文件打开之前保持一直*/
	if (csvFile.open(QIODevice::ReadWrite | QIODevice::Append))
	{
		for (int i = 0; i < lines.size(); i++)
		{
			/*写入每一行数据到文件*/

			csvFile.write(lines[i].toLocal8Bit());
		}

		csvFile.close();
	}

	QMessageBox::information(nullptr, u8"信息", u8"写入完成");
}

void DataSortMainWidget::sort(QList<double>* list)
{
	for (int i=0;i<list->count();i++)
	{

	}
}
