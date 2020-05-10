#pragma once

#include <QtWidgets/QWidget>
#include "ui_MainWidget.h"
#include "ImageProcessTool.h"

class MainWidget : public QWidget
{
	Q_OBJECT

public:
	MainWidget(QWidget *parent = Q_NULLPTR);

private:
	Ui::MainWidgetClass ui;

	//dll
	CImageProcessTool* _imageProcessTool;


public slots:
void loadDllButtonClicked();
void invokeDllButtonClicked();


};
