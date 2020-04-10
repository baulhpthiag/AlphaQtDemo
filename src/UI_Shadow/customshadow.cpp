#include "customshadow.h"
#include "shadow.h"
#include <QPainter>
#include <QStyleOption>

CustomShadow::CustomShadow(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	ui.pushButton->installEventFilter(this);
	ui.widget->installEventFilter(this);
	//Ä£ºýÐ§¹û
	auto blurEffect = new QGraphicsBlurEffect(ui.lineEdit);
	blurEffect->setBlurRadius(2);
	ui.lineEdit->setGraphicsEffect(blurEffect);
}

bool CustomShadow::eventFilter(QObject *obj, QEvent *event)
{
	if (obj == ui.pushButton) {
		if (event->type() == QEvent::Enter)
		{
			Shadow* bodyShadow = new Shadow(ui.pushButton);
			ui.pushButton->setGraphicsEffect(bodyShadow);
			return true;
		}
		else if (event->type() == QEvent::Leave)
		{
			ui.pushButton->setGraphicsEffect(nullptr);
			return true;
		}
		else {
			return false;
		}
	}
	else if (obj == ui.widget) {
		if (event->type() == QEvent::Enter)
		{
			Shadow* bodyShadow = new Shadow(ui.widget);
			ui.widget->setGraphicsEffect(bodyShadow);
			return true;
		}
		else if (event->type() == QEvent::Leave)
		{
			ui.widget->setGraphicsEffect(nullptr);
			return true;
		}
		else {
			return false;
		}
	}
	else {
		// pass the event on to the parent class
		return __super::eventFilter(obj, event);
	}
}
