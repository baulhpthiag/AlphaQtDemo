#include "LoadDllWidget.h"
#include <QDebug>
#include <QLibrary>

LoadDllWidget::LoadDllWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

void LoadDllWidget::pushButtonClicked()
{
	qDebug() << "aaa";

	QLibrary mylib("ImageProcessBasicHalcon.dll");

	if (mylib.load())
	{
		qDebug() << "";
		//QByteArray ba = _createAlgorithmInstanceMethodName.toLocal8Bit();
		//const char *c_str2 = ba.data();

		//CreateProcessTool createAlgorithmInstance = (CreateProcessTool)mylib.resolve(c_str2);
		//if (createAlgorithmInstance)
		//{
		//	imageProcessTool = createAlgorithmInstance();
		//	if (nullptr == imageProcessTool)
		//	{
		//		qDebug() << "dll: " << _dllName << " createAlgorithmInstance fail";
		//	}
		//}
		//else
		//{
		//	qDebug() << "dll: " << _dllName << " link to Function fail " + _createAlgorithmInstanceMethodName;
		//}
	}
	else
	{
		QString error = mylib.errorString();
		qDebug() << "dll:"  << " load fail";
		return;
	}



}
