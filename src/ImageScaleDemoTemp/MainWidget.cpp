#include "MainWidget.h"
#include <QDebug>
#include <QFileDialog>
#include <QPainter>
#include <QWheelEvent>
#include <QLabel>
#include <QMouseEvent>

MainWidget::MainWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	init();
}

void MainWidget::init()
{
	resize(1000, 1000);
	setMouseTracking(true);
}

void MainWidget::paintEvent(QPaintEvent *event)
{
	QPainter painter(this);
	//设置渲染 但效率低
	painter.setRenderHint(QPainter::Antialiasing);
	painter.setRenderHint(QPainter::SmoothPixmapTransform, true);
	if (!pixmapPath.isNull())
	{
		painter.drawImage(QPointF(0, 0), showImage);
	}
	painter.drawRect(0, 0, 100, 100);

}

void MainWidget::wheelEvent(QWheelEvent *event)
{
	double currentScale = icc.getImageScale() + event->delta() / qreal(1000);
	icc.zoom(currentScale);
	cutImage();
}

void MainWidget::mouseMoveEvent(QMouseEvent *event)
{

	int rX = 0;
	int rY = 0;
 	QPoint currentPoint = event->pos();

	switch (event->buttons())
	{
	case Qt::NoButton:

		//鼠标移动，
		icc.setCurrentPositionOnWindow(currentPoint);
		break;

	case Qt::LeftButton:
		rX = currentPoint.x() - lastPoint.x();
		rY = currentPoint.y() - lastPoint.y();
		icc.translate(-rX, -rY);
		break;
	default:
		break;
	}
	cutImage();
	lastPoint = event->pos();
}



void MainWidget::cutImage()
{
	QRect rect = icc.getShowRect();
	QSize size = this->size();
	this->showImage = sourceImage.copy(rect).scaled(size,Qt::KeepAspectRatio, Qt::SmoothTransformation);
	ui.label_winx->setText(QString::number(icc.getCurrentPositionOnWindow().x()));
	ui.label_winy->setText(QString::number(icc.getCurrentPositionOnWindow().y()));
	ui.label_imgx->setText(QString::number(icc.getCurrentPositionOnImage().x()));
	ui.label_imgy->setText(QString::number(icc.getCurrentPositionOnImage().y()));
	ui.label_scale->setText(QString::number(icc.getImageScale()));
	update();
}

void MainWidget::openImage()
{
	QString path = QFileDialog::getOpenFileName(this, "open file", "d:/");
	if (!path.isNull())
	{
		pixmapPath = path;
		sourceImage.load(pixmapPath);
		if (sourceImage.size().width()/sourceImage.size().height()>= size().width()/size().height())
		{
			resize(size().width(), size().width()*sourceImage.size().height() / sourceImage.size().width());
		}

		icc.init(sourceImage.size(),size(),sourceImage.rect(),QPoint(0,0));
		cutImage();
	
	}



}





