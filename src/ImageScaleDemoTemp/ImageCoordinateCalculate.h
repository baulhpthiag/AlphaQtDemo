#pragma once

#include <QObject>
#include <QRect>

class ImageCoordinateCalculate : public QObject
{
	Q_OBJECT

public:
	
	ImageCoordinateCalculate(QObject *parent = nullptr);
	~ImageCoordinateCalculate();

	void init(QSize imageSize, QSize windowSize, QRect showRect, QPoint currentPositionOnImage);

	void setImageSize(QSize imageSize);
	QSize getImageSize();

	void setWindowSize(QSize windowSize);
	QSize getWindowSize();

	void setShowRect(QRect showRect);
	QRect getShowRect();

	void setCurrentPositionOnImage(QPoint currentPositionOnWindow);
	QPoint getCurrentPositionOnImage();

	void setCurrentPositionOnWindow(QPoint currentPositionOnWindow);
	QPoint getCurrentPositionOnWindow();

	void setImageScale(double imageScale);
	double getImageScale();

	void zoom(double imageScale);

	void translate(int rx,int ry);

private:
	QSize imageSize;
	QSize windowSize;
	QRect showRect;
	double imageScale;
	double minImageScale;
	QPoint currentPositionOnImage;//当前点相对与图片的坐标
	QPoint currentPositionOnWindow;
};
