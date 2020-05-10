#include "FileDirHelper.h"
#include <QDir>
#include <QApplication>
#include <QDesktopServices>
#include <QUrl>
#include <QFileDialog>
#include <QMessageBox>

//静态成员变量初始化，否则报错
QString FileDirHelper::currentDetectType = "";
QString FileDirHelper::lastDir = "";


FileDirHelper::FileDirHelper(QObject *parent)
	: QObject(parent)
{
}

FileDirHelper::~FileDirHelper()
{
}

void FileDirHelper::createDir(QString dirPath)
{
	QDir dir;
	if (!dir.exists(dirPath))
	{
		dir.mkdir(dirPath);
	}
}

QString FileDirHelper::getAppDirPath()
{
	return qApp->applicationDirPath();
}

QString FileDirHelper::getConfigDirPath()
{
	return getAppDirPath() + "/config/";
}

QString FileDirHelper::getDetectTypesDirPath()
{
	return getConfigDirPath() + "detectTypes/";
}

void FileDirHelper::setCurrentDetectType(QString detectType)
{
	currentDetectType = detectType;
}

QString FileDirHelper::getCurrentDetectType()
{
	return currentDetectType;
}

QString FileDirHelper::getCurrentDetectTypeDirPath()
{
	return getDetectTypesDirPath() + currentDetectType + "/";
}

void FileDirHelper::openAppDir()
{
	QString filePath = "file:///" + getAppDirPath();
	QDesktopServices::openUrl(QUrl::fromLocalFile(filePath));
}

void FileDirHelper::openConfigDir()
{
	QString filePath = "file:///" + getConfigDirPath();
	QDesktopServices::openUrl(QUrl::fromLocalFile(filePath));
}

void FileDirHelper::openDetectTypesDir()
{
	QString filePath = "file:///" + getDetectTypesDirPath();
	QDesktopServices::openUrl(QUrl::fromLocalFile(filePath));
}

QFileInfoList FileDirHelper::getChildDirList(QString dirPath)
{
	QFileInfoList _temp;
	QDir dir(dirPath);
	QFileInfoList fileInfoList = dir.entryInfoList(QDir::Dirs);
	for (int i = 0; i < fileInfoList.size(); i++)
	{
		QFileInfo fileInfo = fileInfoList.at(i);
		if ("." == fileInfo.fileName() || ".." == fileInfo.fileName())
		{
			continue;
		}
		_temp.append(fileInfo);
	}
	return _temp;
}

QList<QString> FileDirHelper::getChildDirNames(QString dirPath)
{
	QList<QString> temp;
	temp.clear();
	QDir dir(dirPath);
	QFileInfoList fileInfoList = dir.entryInfoList(QDir::Dirs);
	for (int i = 0; i < fileInfoList.size(); i++)
	{
		QFileInfo fileInfo = fileInfoList.at(i);
		if ("." == fileInfo.fileName() || ".." == fileInfo.fileName())
		{
			continue;
		}
		temp.append(fileInfo.fileName());
	}

	return temp;
}

QList<QString> FileDirHelper::getChildFilePaths(QString dirPath)
{
	QList<QString> temp;
	temp.clear();
	QDir dir(dirPath);
	QFileInfoList fileInfoList = dir.entryInfoList(QDir::Files);
	for (int i = 0; i < fileInfoList.size(); i++)
	{
		QFileInfo fileInfo = fileInfoList.at(i);
		if ("." == fileInfo.fileName() || ".." == fileInfo.fileName())
		{
			continue;
		}
		temp.append(fileInfo.absoluteFilePath());
	}

	return temp;
}

QString FileDirHelper::selectDirDialog(QWidget * parent)
{
	//定义文件对话框类
	QFileDialog *fileDialog = new QFileDialog(parent);
	//定义文件对话框标题
	fileDialog->setWindowTitle(QStringLiteral("选中文件"));
	//设置默认文件路径
	fileDialog->setDirectory(lastDir);
	//设置文件过滤器
	fileDialog->setNameFilter(tr("File(*.*)"));
	//设置可以选择多个文件,默认为只能选择一个文件QFileDialog::ExistingFiles
	fileDialog->setFileMode(QFileDialog::DirectoryOnly);
	//设置视图模式
	fileDialog->setViewMode(QFileDialog::Detail);
	//打印所有选择的文件的路径
	QStringList fileNames;
	if (fileDialog->exec()) {
		fileNames = fileDialog->selectedFiles();
	}
	if (fileNames.count()== 0)
	{
		return lastDir;
	}
	if (fileNames[0].isEmpty())
	{
		return lastDir;
	}
	lastDir = fileNames[0];
	return lastDir;
}

void FileDirHelper::setLastDir(QString dirPath)
{
	lastDir = dirPath;
}

QString FileDirHelper::getLastDir()
{
	return lastDir;
}

void FileDirHelper::createFile(QString filePath)
{
	QFile file(filePath);
	if (!file.exists())
	{
		file.open(QIODevice::WriteOnly);
		file.close();
	}
}

QString FileDirHelper::getMainConfigFilePath()
{
	return getConfigDirPath() + "mainConfig.json";
}

QString FileDirHelper::selectFileDialog(QWidget * parent)
{
	QString fileName = QFileDialog::getOpenFileName(parent, tr("open file"), lastDir, tr("Image Files(*.jpg *.png *.bmp *.pgm *.pbm);;All(*.*)"));
	QFileInfo file(fileName);
	QString path = file.absoluteDir().path();
	lastDir = path;
	return fileName;
}

bool FileDirHelper::deleteDirDialog(QString dirPath)
{
	QMessageBox msg;//对话框设置父组件
	msg.setWindowTitle(u8"注意");//对话框标题
	msg.setText(u8"确认删除?");//对话框提示文本
	msg.setIcon(QMessageBox::Information);//设置图标类型
	msg.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel );//对话框上包含的按钮

	if (msg.exec() == QMessageBox::Ok)//模态调用
	{
		deleteDir(dirPath);
		return true;
	}
	return true;
}

void FileDirHelper::deleteDir(QString dirPath)
{
	if (dirPath.isEmpty()) {
		return;
	}
	QDir dir(dirPath);
	if (!dir.exists()) {
		return;
	}
	dir.setFilter(QDir::AllEntries | QDir::NoDotAndDotDot);
	QFileInfoList fileList = dir.entryInfoList();
	foreach(QFileInfo file, fileList) {
		if (file.isFile())
		{
			file.dir().remove(file.fileName());
		}
		else
		{
			deleteDir(file.absoluteFilePath());
		}
	}
	
	dir.rmpath(dir.absolutePath());
}
