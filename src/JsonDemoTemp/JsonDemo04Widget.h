#pragma once

#include <QWidget>
#include "ui_JsonDemo04Widget.h"

class JsonDemo04Widget : public QWidget
{
	Q_OBJECT

public:
	JsonDemo04Widget(QWidget *parent = Q_NULLPTR);
	~JsonDemo04Widget();

private:
	Ui::JsonDemo04Widget ui;
};
