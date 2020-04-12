#include "MainWidget.h"
#include "StyleSheetHelper.h"
#include <QApplication>

MainWidget::MainWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	reloadStyleSheet();
}

void MainWidget::reloadStyleSheet()
{
	StyleSheetHelper::loadStyleSheet(this, qApp->applicationDirPath() + "/alphaStyleSheetGray.css");
}
