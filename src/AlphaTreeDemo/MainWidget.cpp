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
	testConfig._testBoolConfigNodeList.append(boolConfigNode);
	testConfig._testBoolConfigNodeList.append(boolConfigNode);

	testConfig._testIntConfigNodeList.append(intConfigNode);
	testConfig._testIntConfigNodeList.append(intConfigNode);

	testConfig._testIntEnumConfigNodeList.append(intEnumConfigNode);
	testConfig._testIntEnumConfigNodeList.append(intEnumConfigNode);

	testConfig._testDoubleConfigNodeList.append(doubleConfigNode);
	testConfig._testDoubleConfigNodeList.append(doubleConfigNode);

	testConfig._testDoubleEnumConfigNodeList.append(doubleEnumConfigNode);
	testConfig._testDoubleEnumConfigNodeList.append(doubleEnumConfigNode);

	testConfig._testStringConfigNodeList.append(stringConfigNode);
	testConfig._testStringConfigNodeList.append(stringConfigNode);

	testConfig._testStringEnumConfigNodeList.append(stringEnumConfigNode);
	testConfig._testStringEnumConfigNodeList.append(stringEnumConfigNode);

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
