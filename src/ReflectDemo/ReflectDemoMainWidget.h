#pragma once

#include <QtWidgets/QWidget>
#include "ui_ReflectDemoMainWidget.h"
#include "Parent.h"
#include <QVariant>

class ReflectDemoMainWidget : public QWidget
{
	Q_OBJECT

public:
	ReflectDemoMainWidget(QWidget *parent = Q_NULLPTR);

private:
	Ui::ReflectDemoMainWidgetClass ui;
	Parent p;
	QVariant var;

	public slots:
	void varSetValueButton();
	void varGetValueButton();

	

};
