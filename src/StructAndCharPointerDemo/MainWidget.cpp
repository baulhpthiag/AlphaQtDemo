#include "MainWidget.h"

MainWidget::MainWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

s_Result MainWidget::getStruct()
{
	const char * temp = "abc";
	s_Result m;
	char * c = new char[strlen(temp) + 1];
	strcpy(c, temp);
	m.chRsuInfo = c;
	return m;
}

void MainWidget::pushButtonClicked()
{
	s_Result m = getStruct();
}
