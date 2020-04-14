#include "MainWidget.h"
#include "StyleSheetHelper.h"

MainWidget::MainWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	StyleSheetHelper::loadStyleSheet(this, qApp->applicationDirPath() + "/layui.css");
}
void MainWidget::listWidgetCurrentRowChanged(int index)
{
	ui.stackedWidget->setCurrentIndex(index);
}