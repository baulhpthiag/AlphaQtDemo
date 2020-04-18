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
	QVariant var;
	Parent _parent;
	public slots:
	void varSetValueButtonClicked();
	void varGetValueButtonClicked();

	void setChildButtonClicked();
	void getChildButtonClicked();

	void bindDataButtonClicked();

};
