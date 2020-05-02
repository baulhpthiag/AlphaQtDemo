#include <QtCore/QCoreApplication>
#include "QDir"
#include <QDebug>

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	QDir dir("d:");
	QFileInfoList fileInfoList = dir.entryInfoList(QDir::Dirs);
	for (int i = 0; i < fileInfoList.size(); i++)
	{
		QFileInfo fileInfo = fileInfoList.at(i);
		if ("." == fileInfo.fileName() || ".." == fileInfo.fileName())
		{
			continue;
		}

		qDebug() << fileInfo.absoluteFilePath();
		qDebug() << fileInfo.absolutePath();
		qDebug() << fileInfo.baseName();
		qDebug() << fileInfo.suffix();
		qDebug() << fileInfo.fileName();
		qDebug() << fileInfo.filePath();
	}


	return a.exec();
}
