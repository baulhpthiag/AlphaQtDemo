#pragma once

#include <QWidget>
#include "ui_IniDemoMainWidget.h"

class IniDemoMainWidget : public QWidget
{
	Q_OBJECT

public:
	IniDemoMainWidget(QWidget *parent = Q_NULLPTR);
	~IniDemoMainWidget();

private:
	Ui::IniDemoMainWidget ui;

public slots:
void test01ButtonClicked();


};
