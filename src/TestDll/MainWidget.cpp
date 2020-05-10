#include "MainWidget.h"
#include <QDebug>
#include <QLibrary>
#include "AlgorithmProcessImageResult.h"
#include "FileDirHelper.h"

MainWidget::MainWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

void MainWidget::loadDllButtonClicked()
{

	QLibrary mylib("ImageProcessBasicHalcon.dll");
	if (!mylib.load())
	{
		QString error = mylib.errorString();
		QString message;
		message.append(" load dll fail").append(error);
		ui.textBrowser->append(message);
		return;
	}

	//QByteArray ba = methodName.toLocal8Bit();
	//const char *c_str2 = ba.data();

	CreateProcessTool createAlgorithmInstance = (CreateProcessTool)mylib.resolve("CreateProcessIntance");
	if (!createAlgorithmInstance)
	{
		QString message;
		message.append("link to Function fail ");
		ui.textBrowser->append(message);
		return;
	}

	_imageProcessTool = createAlgorithmInstance();
	if (nullptr == _imageProcessTool)
	{
		QString message;
		message.append("createAlgorithmInstance fail ");
		ui.textBrowser->append(message);
		return;
	}

	//destroyProcessTool = (DestroyProcessTool)mylib.resolve("DestroyProcessIntance");
	//if (!destroyProcessTool)
	//{
	//	QString message;
	//	message.append("dll:").append(dllName).append(" DestroyProcessIntance link to Function fail ");
	//	emit signalMessageChanged(message);
	//	emit signalLoadAlgorithmFinish(false);
	//	return;
	//}

	ui.textBrowser->append(u8"load dll success");
	return;

}

void MainWidget::invokeDllButtonClicked()
{
	QString filePath=FileDirHelper::selectFileDialog(this);
	if (filePath.isEmpty())
	{
		return;
	}
	AlgorithmProcessImageResult result;
	if (nullptr == _imageProcessTool)
	{
		return;
	}

	ProductPara In_ProductPara;
	In_ProductPara.fHor_O=4.08;
	In_ProductPara.fHor_M=3.08;
	In_ProductPara.fHor_I=2.8 ;
	In_ProductPara.fVer_O=4.9;
	In_ProductPara.fVer_M=3.99;
	In_ProductPara.fVer_I=3.64;

	In_ProductPara.fHor_O_Modify=0;
	In_ProductPara.fHor_M_Modify=0;
	In_ProductPara.fHor_I_Modify=0;
	In_ProductPara.fVer_O_Modify=0;
	In_ProductPara.fVer_M_Modify=0;
	In_ProductPara.fVer_I_Modify=0;

	In_ProductPara.fHor_O_Offset_UpLimit=0.03;
	In_ProductPara.fHor_O_Offset_DownLimit=0.03;
	In_ProductPara.fHor_M_Offset_UpLimit = 0.06;
	In_ProductPara.fHor_M_Offset_DownLimit=0;
	In_ProductPara.fHor_I_Offset_UpLimit = 0.06;
	In_ProductPara.fHor_I_Offset_DownLimit=0;
	In_ProductPara.fVer_O_Offset_UpLimit = 0.03;
	In_ProductPara.fVer_O_Offset_DownLimit=0.03;
	In_ProductPara.fVer_M_Offset_UpLimit = 0.06;
	In_ProductPara.fVer_M_Offset_DownLimit=0;
	In_ProductPara.fVer_I_Offset_UpLimit = 0.06;
	In_ProductPara.fVer_I_Offset_DownLimit=0;

	double fResolutionRatio = 0.005274;

	_imageProcessTool->SetDetectParaBL(In_ProductPara, fResolutionRatio);

	QByteArray cdata = filePath.toLocal8Bit();
	std::string str = ((const char *)cdata);
	CString strPath = str.c_str();
	s_Result originResult;

	try
	{
		originResult = _imageProcessTool->Process(strPath);
	}
	catch (...)
	{
		result._message = u8"算法处理图像发生异常";
	}
	result.readOriginResult(originResult);
	
	ui.textBrowser->append(result.toQString());
}
