#pragma once

#include <QWidget>
#include "ui_JsonDemo01Widget.h"

class JsonDemo01Widget : public QWidget
{
	Q_OBJECT

public:
	JsonDemo01Widget(QWidget *parent = Q_NULLPTR);
	~JsonDemo01Widget();

private:
	Ui::JsonDemo01Widget ui;
};
