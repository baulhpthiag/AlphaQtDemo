#include "AlphaGraphicsView.h"
#include <QDebug>
#include <QWheelEvent>

AlphaGraphicsView::AlphaGraphicsView(QWidget *parent)
	: QGraphicsView(parent)
{
	ui.setupUi(this);
	graphicsScene = nullptr;
	backgroundImage = nullptr;
	connect(this, &AlphaGraphicsView::widgetICreateFinish, this, &AlphaGraphicsView::init);
	emit widgetICreateFinish();
}

AlphaGraphicsView::~AlphaGraphicsView()
{

}

void AlphaGraphicsView::init()
{
	graphicsScene = new QGraphicsScene(0, 0, width(), height());
	setScene(graphicsScene);
	setMouseTracking(true);
	setDragMode(QGraphicsView::RubberBandDrag);
	setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

}

QPointF AlphaGraphicsView::viewCoordinateToItemCoordinate(QPoint viewPoint)
{
	QPointF scenePoint = mapToScene(viewPoint);
	return backgroundImage->mapFromScene(scenePoint);
}

void AlphaGraphicsView::mouseMoveEvent(QMouseEvent *event)
{
	if (nullptr != backgroundImage)
	{
		currentPointOnImage = viewCoordinateToItemCoordinate(event->pos());
	}
	if (event->buttons() == Qt::RightButton)
	{
		qDebug() << "rightButton move";
	}
	else
	{
		qDebug() << "leftButton move";
		QGraphicsView::mouseMoveEvent(event);
	}
}

void AlphaGraphicsView::wheelEvent(QWheelEvent *event)
{
	double d = event->delta() / qreal(1000);
	if (nullptr != backgroundImage)
	{
		QPoint c = event->pos();
		if (d > 0)
		{
			backgroundImage->setScale(backgroundImage->scale() + 0.05);
		}
		else
		{
			backgroundImage->setScale(backgroundImage->scale() - 0.05);
		}

		QPointF temp = backgroundImage->mapToScene(currentPointOnImage);
		QPoint point = mapFromScene(temp);
		backgroundImage->moveBy(event->pos().x() - point.x(), event->pos().y() - point.y());
		currentPointOnImage = c;
	}
}

void AlphaGraphicsView::addImage(QString imageFilePath)
{
	QPixmap pixmap;
	bool loadResult = pixmap.load(imageFilePath, nullptr, Qt::MonoOnly);
	if (!loadResult)
	{
		qDebug() << "AlphaGraphicsView addImage:" + imageFilePath + "fail";
		return;
	}
	if (nullptr != backgroundImage)
	{
		graphicsScene->removeItem(backgroundImage);
		delete backgroundImage;
		backgroundImage = nullptr;
	}
	backgroundImage = new QGraphicsPixmapItem();
	backgroundImage->setPixmap(pixmap);
	backgroundImage->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsFocusable);
	backgroundImage->setPos(0, 0);
	QRectF imageRect = backgroundImage->boundingRect();
	double wscale = graphicsScene->width() / imageRect.width();
	double hscale = graphicsScene->height() / imageRect.height();

	if (wscale < 1 || hscale < 1)
	{
		if (wscale < hscale)
		{
			backgroundImage->setScale(wscale);
		}
		else
		{
			backgroundImage->setScale(hscale);
		}
	}

	backgroundImage->handlesChildEvents();
	backgroundImage->setSelected(true);
	graphicsScene->addItem(backgroundImage);
}

void AlphaGraphicsView::addRle(QList<int> row, QList<int> begin, QList<int> end)
{
	for (int i = 0; i < row.count(); i++)
	{
		QPointF beginPoint(begin[i], row[i]);
		QPointF endPoint(end[i], row[i]);
		//»æÖÆÏß
		QPen pen;
		pen.setColor(Qt::green);
		pen.setWidth(1);
		QGraphicsLineItem *item = new QGraphicsLineItem(beginPoint.x(), beginPoint.y(), endPoint.x(), endPoint.y());
		item->setPen(pen);
		item->setFlags(QGraphicsItem::ItemIsFocusable);
		item->setParentItem(backgroundImage);
	}

}
