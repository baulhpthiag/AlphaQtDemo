#include "TestStyleDemo.h"
#include <QApplication>
#include "StyleSheetHelper.h"

TestStyleDemo::TestStyleDemo(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);



	QString logoFilePath = qApp->applicationDirPath() + "/background.jpg";
	QImage logoImage;

	if (logoImage.load(logoFilePath))
	{
		QPixmap logoPixmap = QPixmap::fromImage(logoImage);
		int w = ui.backgroundImageLabel->width();
		int h = ui.backgroundImageLabel->height();

		QPixmap logosSpixmap = logoPixmap.scaled(w, h, Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation);  // °´±ÈÀýËõ·Å
		ui.backgroundImageLabel->setPixmap(logoPixmap);
	}
	loadStyleButtonClicked();

}

void TestStyleDemo::loadStyleButtonClicked()
{
	StyleSheetHelper::loadStyleSheet(this, qApp->applicationDirPath() + "/bluewhitestyle.css");
}
