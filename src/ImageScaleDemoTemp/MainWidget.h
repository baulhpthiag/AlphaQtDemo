#pragma once

#include <QtWidgets/QWidget>
#include "ui_MainWidget.h"
#include <QPoint>
#include <QMouseEvent>
#include <ImageCoordinateCalculate.h>



class MainWidget : public QWidget
{
	Q_OBJECT

public:
	MainWidget(QWidget *parent = Q_NULLPTR);
	void init();

	void paintEvent(QPaintEvent *event);
	void wheelEvent(QWheelEvent *event);
	void mouseMoveEvent(QMouseEvent *event);


	public slots:
	void openImage();

	void cutImage();


private:
	Ui::MainWidgetClass ui;
	QString pixmapPath;//图片路径


	QPoint lastPoint;//上个点
	QImage showImage;
	QImage sourceImage;//
	ImageCoordinateCalculate icc;

};
