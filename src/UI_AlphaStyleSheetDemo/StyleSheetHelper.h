#pragma once

#include <QObject>

class StyleSheetHelper : public QObject
{
	Q_OBJECT

public:
	StyleSheetHelper(QObject *parent);
	~StyleSheetHelper();

	static bool loadStyleSheet(QWidget* widget,QString styleSheetFilePath);

};
