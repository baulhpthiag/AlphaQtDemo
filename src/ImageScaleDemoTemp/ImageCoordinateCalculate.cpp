#include "ImageCoordinateCalculate.h"
#include <QRect>
#include <QSize>

#include <stdlib.h>

ImageCoordinateCalculate::ImageCoordinateCalculate(QObject *parent)
	: QObject(parent)
{

}

ImageCoordinateCalculate::~ImageCoordinateCalculate()
{

}

void ImageCoordinateCalculate::init(QSize imageSize, QSize windowSize, QRect showRect, QPoint currentPositionOnImage)
{
	this->imageSize = imageSize;
	this->windowSize = windowSize;
	this->showRect = showRect;
	this->currentPositionOnImage = currentPositionOnImage;
	if (imageSize.width()/imageSize.height()>= windowSize.width()/windowSize.height() )
	{
		imageScale = windowSize.width() / qreal(showRect.width());
	}
	else
	{
		imageScale =windowSize.height() / qreal(showRect.height());
	}
	minImageScale = imageScale;
}

void ImageCoordinateCalculate::setImageSize(QSize imageSize)
{
	this->imageSize = imageSize;
}

QSize ImageCoordinateCalculate::getImageSize()
{
	return imageSize;
}

void ImageCoordinateCalculate::setWindowSize(QSize windowSize)
{
	this->windowSize = windowSize;
}

QSize ImageCoordinateCalculate::getWindowSize()
{
	return windowSize;
}

void ImageCoordinateCalculate::setShowRect(QRect showRect)
{
	this->showRect = showRect;
}

QRect ImageCoordinateCalculate::getShowRect()
{
	return showRect;
}

void ImageCoordinateCalculate::setCurrentPositionOnImage(QPoint currentPositionOnWindow)
{

}

QPoint ImageCoordinateCalculate::getCurrentPositionOnImage()
{
	return currentPositionOnImage;
}

void ImageCoordinateCalculate::setCurrentPositionOnWindow(QPoint currentPositionOnWindow)
{
	this->currentPositionOnWindow = currentPositionOnWindow;
	QPoint originPositionOnImage = showRect.topLeft();
	int dx = currentPositionOnWindow.x() / imageScale;
	int dy = currentPositionOnWindow.y() / imageScale;
	currentPositionOnImage.setX(dx + originPositionOnImage.x());
	currentPositionOnImage.setY(dy + originPositionOnImage.y());
}

QPoint ImageCoordinateCalculate::getCurrentPositionOnWindow()
{
	return currentPositionOnWindow;
}

void ImageCoordinateCalculate::setImageScale(double imageScale)
{
	if (minImageScale>imageScale)
	{
		return;
	}
	this->imageScale = imageScale;
	int width = this->windowSize.width() / imageScale;
	int height = this->windowSize.height() / imageScale;
	this->showRect.setWidth(width);
	this->showRect.setHeight(height);

}

double ImageCoordinateCalculate::getImageScale()
{
	return imageScale;
}

void ImageCoordinateCalculate::zoom(double imageScale)
{
	if (minImageScale > imageScale)
	{
		return;
	}

	this->imageScale = imageScale;
	int width = this->windowSize.width() / imageScale;
	int height = this->windowSize.height() / imageScale;
	this->showRect.setWidth(width);
	this->showRect.setHeight(height);
	
	int dx = currentPositionOnWindow.x() *showRect.width() / windowSize.width();
	int dy = currentPositionOnWindow.y() *showRect.height() / windowSize.height();

	this->showRect = QRect(currentPositionOnImage.x() - dx, currentPositionOnImage.y() - dy,this->showRect.width(),this->showRect.height());
}

void ImageCoordinateCalculate::translate(int rx, int ry)
{
	showRect.adjust(rx/this->getImageScale(), ry/ this->getImageScale(), rx/ this->getImageScale(), ry/ this->getImageScale());
	QRect rect = this->showRect;
}
