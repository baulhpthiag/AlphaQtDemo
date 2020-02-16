#pragma once

#include <QWidget>
#include "ui_ThreadDemo0.h"

class ThreadDemo0 : public QWidget
{
	Q_OBJECT

public:
	ThreadDemo0(QWidget *parent = Q_NULLPTR);
	~ThreadDemo0();

private:
	Ui::ThreadDemo0 ui;
};
