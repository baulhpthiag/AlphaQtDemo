#pragma once

#include <QWidget>
#include "ui_ThreadDemo02Widget.h"

class ThreadDemo02Widget : public QWidget
{
	Q_OBJECT

public:
	ThreadDemo02Widget(QWidget *parent = Q_NULLPTR);
	~ThreadDemo02Widget();

private:
	Ui::ThreadDemo02Widget ui;
};
