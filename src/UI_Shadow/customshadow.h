#ifndef CUSTOMSHADOW_H
#define CUSTOMSHADOW_H

#include <QtWidgets/QWidget>
#include "ui_customshadow.h"

class CustomShadow : public QWidget
{
	Q_OBJECT

public:
	CustomShadow(QWidget *parent = 0);
	~CustomShadow(){};

private:
	Ui::CustomShadowClass ui;
	bool eventFilter(QObject *watched, QEvent *event);
};

#endif // CUSTOMSHADOW_H
