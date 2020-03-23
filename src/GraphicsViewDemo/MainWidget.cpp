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
	////定义文件对话框类
	//QFileDialog fileDialog ;
	////定义文件对话框标题
	//fileDialog.setWindowTitle(QStringLiteral("选中图片"));
	////设置默认文件路径
	//fileDialog.setDirectory(".");
	////设置文件过滤器
	//fileDialog.setNameFilter(tr("File(*.*)"));
	////设置可以选择多个文件,默认为只能选择一个文件QFileDialog::ExistingFiles
	//fileDialog.setFileMode(QFileDialog::ExistingFile);
	////设置视图模式
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
