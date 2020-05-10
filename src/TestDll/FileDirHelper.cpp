#include "FileDirHelper.h"
#include <QDir>
#include <QApplication>
#include <QDesktopServices>
#include <QUrl>
#include <QFileDialog>
#include <QMessageBox>

//��̬��Ա������ʼ�������򱨴�
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
	//�����ļ��Ի�����
	QFileDialog *fileDialog = new QFileDialog(parent);
	//�����ļ��Ի������
	fileDialog->setWindowTitle(QStringLiteral("ѡ���ļ�"));
	//����Ĭ���ļ�·��
	fileDialog->setDirectory(lastDir);
	//�����ļ�������
	fileDialog->setNameFilter(tr("File(*.*)"));
	//���ÿ���ѡ�����ļ�,Ĭ��Ϊֻ��ѡ��һ���ļ�QFileDialog::ExistingFiles
	fileDialog->setFileMode(QFileDialog::DirectoryOnly);
	//������ͼģʽ
	fileDialog->setViewMode(QFileDialog::Detail);
	//��ӡ����ѡ����ļ���·��
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
	QMessageBox msg;//�Ի������ø����
	msg.setWindowTitle(u8"ע��");//�Ի������
	msg.setText(u8"ȷ��ɾ��?");//�Ի�����ʾ�ı�
	msg.setIcon(QMessageBox::Information);//����ͼ������
	msg.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel );//�Ի����ϰ����İ�ť

	if (msg.exec() == QMessageBox::Ok)//ģ̬����
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
