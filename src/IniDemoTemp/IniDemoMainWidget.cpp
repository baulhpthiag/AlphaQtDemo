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
	//如果文件不存在，会自动创建文件

	QString applicationDir = qApp->applicationDirPath();
	QString iniPath = applicationDir + "/testIni.ini";
	QSettings settings(iniPath, QSettings::IniFormat);

	settings.setValue("Student/Name", "tom");
	settings.setValue("Student/Age", 1);
	settings.setValue("Student/isXXX",true);
	settings.setValue("Student/high", 1.70);
	settings.setValue("School/Name", "xxxSchool");
	settings.setValue("School/Pos", "1");
	

	bool b = settings.value("Student/isXXX").toBool();
	double high = settings.value("Student/high").toDouble();


}
