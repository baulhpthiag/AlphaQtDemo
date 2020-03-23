#pragma once

#include <QtWidgets/QWidget>
#include "ui_LoadDllWidget.h"

class LoadDllWidget : public QWidget
{
	Q_OBJECT

public:
	LoadDllWidget(QWidget *parent = Q_NULLPTR);

private:
	Ui::LoadDllWidgetClass ui;

	public slots:
	void pushButtonClicked();
};
