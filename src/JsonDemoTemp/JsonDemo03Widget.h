#pragma once

#include <QWidget>
#include "ui_JsonDemo03Widget.h"

class JsonDemo03Widget : public QWidget
{
	Q_OBJECT

public:
	JsonDemo03Widget(QWidget *parent = Q_NULLPTR);
	~JsonDemo03Widget();

private:
	Ui::JsonDemo03Widget ui;


	public slots:
	void test01ButtonClicked();
	void test02ButtonClicked();
};
