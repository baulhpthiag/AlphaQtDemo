#include "StyleSheetHelper.h"
#include <QFile>
#include <QWidget>

StyleSheetHelper::StyleSheetHelper(QObject *parent)
	: QObject(parent)
{
}

StyleSheetHelper::~StyleSheetHelper()
{
}

bool StyleSheetHelper::loadStyleSheet(QWidget* widget, QString styleSheetFilePath)
{
	QFile file(styleSheetFilePath);
	file.open(QFile::ReadOnly);
	if (!file.isOpen())
	{
		return false;
	}
	QString styleSheet = widget->styleSheet();
	styleSheet += QLatin1String(file.readAll());
	widget->setStyleSheet(styleSheet);
	return true;

}
