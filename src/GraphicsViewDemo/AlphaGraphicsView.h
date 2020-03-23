#pragma once

#include <QGraphicsView>
#include "ui_AlphaGraphicsView.h"
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QPointF>

class AlphaGraphicsView : public QGraphicsView
{
	Q_OBJECT

public:
	AlphaGraphicsView(QWidget *parent = Q_NULLPTR);
	~AlphaGraphicsView();

private:
	Ui::AlphaGraphicsView ui;
	
	QGraphicsScene * graphicsScene;
	QGraphicsPixmapItem * backgroundImage;
	QPointF currentPointOnImage;


private:
	QPointF viewCoordinateToItemCoordinate(QPoint viewPoint);
	void mouseMoveEvent(QMouseEvent *event);
	void wheelEvent(QWheelEvent *event);

public:
	void addImage(QString imageFilePath);
	void addRle(QList<int> row,QList<int> begin,QList<int> end);
	
public slots:
	void init();


signals:
	void widgetICreateFinish();

};
