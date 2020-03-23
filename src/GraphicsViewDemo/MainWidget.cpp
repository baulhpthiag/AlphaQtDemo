#include "MainWidget.h"
#include <QFileDialog>
MainWidget::MainWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

void MainWidget::openImageButtonClicked()
{
	//QString imageFilePath;
	////�����ļ��Ի�����
	//QFileDialog fileDialog ;
	////�����ļ��Ի������
	//fileDialog.setWindowTitle(QStringLiteral("ѡ��ͼƬ"));
	////����Ĭ���ļ�·��
	//fileDialog.setDirectory(".");
	////�����ļ�������
	//fileDialog.setNameFilter(tr("File(*.*)"));
	////���ÿ���ѡ�����ļ�,Ĭ��Ϊֻ��ѡ��һ���ļ�QFileDialog::ExistingFiles
	//fileDialog.setFileMode(QFileDialog::ExistingFile);
	////������ͼģʽ
	//fileDialog.setViewMode(QFileDialog::Detail);
	//QStringList fileNames;
	//if (fileDialog.exec()) {
	//	fileNames = fileDialog.selectedFiles();
	//	if (fileNames.count()>0)
	//	{
	//		imageFilePath = fileNames[0];
	//	}
	//}

	QString imageFilePath = QFileDialog::getOpenFileName(this, "", "");
	if (imageFilePath.isEmpty())
	{
		return;
	}
	ui.graphicsView->addImage(imageFilePath);
}

void MainWidget::genRleButtonClicked()
{
	QList<int> row;
	QList<int> begin;
	QList<int> end;
	for (int i = 0; i < 100; i++)
	{
		row.append(i);
		begin.append(qrand() % 100);
		end.append(qrand() % 100);
	}

	ui.graphicsView->addRle(row, begin, end);

}

void MainWidget::drawEcllipseButtonClicked()
{

}

void MainWidget::drawRectButtonClicked()
{

}
