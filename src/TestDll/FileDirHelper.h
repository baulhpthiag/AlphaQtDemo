#pragma once

#include <QObject>
#include <QFileInfoList>

class FileDirHelper : public QObject
{
	Q_OBJECT

public:
	FileDirHelper(QObject *parent);
	~FileDirHelper();
public :
	
	static QString currentDetectType;
	static QString lastDir;


	//创建目录
	static void createDir(QString dirPath);
	//获取程序根目录
	static QString getAppDirPath();
	//获取程序配置文件目录 即config目录
	static QString getConfigDirPath();
	//获取机种目录，即config/detectTypes/目录
	static QString getDetectTypesDirPath();
	//设置当前机种名称
	static void setCurrentDetectType(QString detectType);
	//获取当前机种名称
	static QString getCurrentDetectType();
	//获取当前机种目录
	static QString getCurrentDetectTypeDirPath();
	//打开程序根目录
	static void openAppDir();
	//打开程序配置目录
	static void openConfigDir();
	//打开程序机种目录
	static void openDetectTypesDir();

	//获取子目录的fileInfolist
	static QFileInfoList getChildDirList(QString dirPath);

	//获取子目录的名称列表
	static QList<QString> getChildDirNames(QString dirPath);

	//获取目录下文件路径
	static QList<QString> getChildFilePaths(QString dirPath);

	static QString selectDirDialog(QWidget * parent);

	static void setLastDir(QString dirPath);

	static QString getLastDir();

	static void createFile(QString filePath);

	static QString getMainConfigFilePath();

	static QString selectFileDialog(QWidget * parent);

	static bool deleteDirDialog(QString dirPath);

	static void deleteDir(QString dirPath);

};
