#include "MainWidget.h"
#include "StyleSheetHelper.h"
#include <QApplication>

MainWidget::MainWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	StyleSheetHelper::loadStyleSheet(this, qApp->applicationDirPath() + "/alphaStyleSheetGray.css");
	
}


