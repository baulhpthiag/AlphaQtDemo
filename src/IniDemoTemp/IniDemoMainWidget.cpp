#include "IniDemoMainWidget.h"
#include <QSettings>

IniDemoMainWidget::IniDemoMainWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

IniDemoMainWidget::~IniDemoMainWidget()
{
}

void IniDemoMainWidget::test01ButtonClicked()
{
	QString applicationDir = qApp->applicationDirPath();
	QString iniPath = applicationDir + "/testIni.ini";
	QSettings settings(iniPath, QSettings::IniFormat);

	settings.setValue("Student/Name", "tom");
	settings.setValue("Student/Age", 1);

	settings.setValue("School/Name", "xxxSchool");
	settings.setValue("School/Pos", "1");



}
