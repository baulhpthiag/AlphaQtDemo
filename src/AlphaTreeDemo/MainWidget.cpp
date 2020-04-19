#include "MainWidget.h"
#include "JsonHelper.h"
#include "TestConfig.h"
#include <QApplication>
#include <QFile>
#include <QDir>
#include <QProcess>
#include "TreeWidgetHelper.h"

MainWidget::MainWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

void MainWidget::openProgramDirButtonClicked()
{
	QString path = qApp->applicationDirPath();
	path.replace("/", "\\");//将地址中的"/"替换为"\"，因为在Windows下使用的是"\"。
	QProcess::startDetached("explorer " + path);//打开上面获取的目录

}

void MainWidget::writeJsonButtonClicked()
{
	QString jsonFilePath = qApp->applicationDirPath() + "/alphaTreeDemo.json";
	QFile file(jsonFilePath);
	if (!file.exists())
	{
		file.open(QIODevice::WriteOnly);
		file.close();
	}

	BoolConfigNode boolConfigNode;
	IntConfigNode intConfigNode;
	IntEnumConfigNode intEnumConfigNode;
	DoubleConfigNode doubleConfigNode;
	DoubleEnumConfigNode doubleEnumConfigNode;
	StringConfigNode stringConfigNode;
	StringEnumConfigNode stringEnumConfigNode;

	TestConfig testConfig;
	testConfig._testBoolListConfigNode._nodelist.append(boolConfigNode);
	testConfig._testBoolListConfigNode._nodelist.append(boolConfigNode);

	testConfig._testIntListConfigNode._nodelist.append(intConfigNode);
	testConfig._testIntListConfigNode._nodelist.append(intConfigNode);

	testConfig._testIntEnumListConfigNode._nodelist.append(intEnumConfigNode);
	testConfig._testIntEnumListConfigNode._nodelist.append(intEnumConfigNode);

	testConfig._testDoubleListConfigNode._nodelist.append(doubleConfigNode);
	testConfig._testDoubleListConfigNode._nodelist.append(doubleConfigNode);

	testConfig._testDoubleEnumListConfigNode._nodelist.append(doubleEnumConfigNode);
	testConfig._testDoubleEnumListConfigNode._nodelist.append(doubleEnumConfigNode);

	testConfig._testStringListConfigNode._nodelist.append(stringConfigNode);
	testConfig._testStringListConfigNode._nodelist.append(stringConfigNode);

	testConfig._testStringEnumListConfigNode._nodelist.append(stringEnumConfigNode);
	testConfig._testStringEnumListConfigNode._nodelist.append(stringEnumConfigNode);

	JsonHelper::writeJsonFile(testConfig, jsonFilePath);
}

void MainWidget::readJsonButtonClicked()
{
	QString jsonFilePath = qApp->applicationDirPath() + "/alphaTreeDemo.json";
	TestConfig testConfig;
	JsonHelper::readJsonFile(testConfig, jsonFilePath);

	qDebug() << testConfig;

}

void MainWidget::createTreeButtonClicked()
{
	QString jsonFilePath = qApp->applicationDirPath() + "/alphaTreeDemo.json";
	JsonHelper::readJsonFile(testConfig, jsonFilePath);
	TreeWidgetHelper::loadData(testConfig, ui.treeWidget);

}

void MainWidget::saveTreeButtonClicked()
{
	QString jsonFilePath = qApp->applicationDirPath() + "/alphaTreeDemo.json";
	JsonHelper::writeJsonFile(testConfig, jsonFilePath);

}
