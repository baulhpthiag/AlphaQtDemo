#pragma once

#include <QWidget>
#include "ui_JsonDemo02Widget.h"

class JsonDemo02Widget : public QWidget
{
	Q_OBJECT

public:
	JsonDemo02Widget(QWidget *parent = Q_NULLPTR);
	~JsonDemo02Widget();

private:
	Ui::JsonDemo02Widget ui;

private:
	void init();

	protected slots:
	void createJsonButtonClicked();
	void readJsonButtonClicked();
	void updateJsonButtonClicked();

};
