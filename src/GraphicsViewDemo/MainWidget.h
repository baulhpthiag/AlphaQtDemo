#pragma once

#include <QtWidgets/QWidget>
#include "ui_MainWidget.h"

class MainWidget : public QWidget
{
	Q_OBJECT

public:
	MainWidget(QWidget *parent = Q_NULLPTR);

private:
	Ui::MainWidgetClass ui;



public slots:
void openImageButtonClicked();
void genRleButtonClicked();
void drawEcllipseButtonClicked();
void drawRectButtonClicked();

};
