#pragma once

#include <QtWidgets/QWidget>
#include "ui_JsonDemoWidget.h"
#include <QVBoxLayout>
#include "JsonDemo01Widget.h"
#include "JsonDemo02Widget.h"

class JsonDemoWidget : public QWidget
{
	Q_OBJECT

public:
	JsonDemoWidget(QWidget *parent = Q_NULLPTR);

private:
	Ui::JsonDemoWidgetClass ui;

private:
	QVBoxLayout * bottomWidgetLayout = NULL;
	QList<QWidget *> demoWidgets;
	JsonDemo01Widget * jsonDemo01Widget = NULL;
	JsonDemo02Widget * jsonDemo02Widget = NULL;

private:
	void init();


protected slots:
	void comboBoxCurrentIndexChanged();

};
