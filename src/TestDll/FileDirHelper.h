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


	//����Ŀ¼
	static void createDir(QString dirPath);
	//��ȡ�����Ŀ¼
	static QString getAppDirPath();
	//��ȡ���������ļ�Ŀ¼ ��configĿ¼
	static QString getConfigDirPath();
	//��ȡ����Ŀ¼����config/detectTypes/Ŀ¼
	static QString getDetectTypesDirPath();
	//���õ�ǰ��������
	static void setCurrentDetectType(QString detectType);
	//��ȡ��ǰ��������
	static QString getCurrentDetectType();
	//��ȡ��ǰ����Ŀ¼
	static QString getCurrentDetectTypeDirPath();
	//�򿪳����Ŀ¼
	static void openAppDir();
	//�򿪳�������Ŀ¼
	static void openConfigDir();
	//�򿪳������Ŀ¼
	static void openDetectTypesDir();

	//��ȡ��Ŀ¼��fileInfolist
	static QFileInfoList getChildDirList(QString dirPath);

	//��ȡ��Ŀ¼�������б�
	static QList<QString> getChildDirNames(QString dirPath);

	//��ȡĿ¼���ļ�·��
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
