#pragma once

#include <QtWidgets/QWidget>
#include "ui_JsonDemoWidget.h"
#include <QVBoxLayout>
#include "JsonDemo01Widget.h"
#include "JsonDemo02Widget.h"
#include "JsonDemo03Widget.h"

class JsonDemoWidget : public QWidget
{
	Q_OBJECT

public:
	JsonDemoWidget(QWidget *parent = Q_NULLPTR);

private:
	Ui::JsonDemoWidgetClass ui;

private:
	QVBoxLayout * bottomWidgetLayout;
	QList<QWidget *> demoWidgets;
	JsonDemo01Widget * jsonDemo01Widget;
	JsonDemo02Widget * jsonDemo02Widget;
	JsonDemo03Widget * jsonDemo03Widget;

private:
	void init();


protected slots:
	void comboBoxCurrentIndexChanged();

};
