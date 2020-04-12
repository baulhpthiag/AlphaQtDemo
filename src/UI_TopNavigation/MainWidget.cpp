#include "MainWidget.h"
#include "StyleSheetHelper.h"

MainWidget::MainWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	StyleSheetHelper::loadStyleSheet(this, qApp->applicationDirPath() + "/topNavigation.css");
}
