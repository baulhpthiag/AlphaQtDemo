#include "MainWidget.h"
#include "halconcpp/HalconCpp.h"
#include "hdevengine/HDevEngineCpp.h"
using namespace HalconCpp;
using namespace HDevEngineCpp;


MainWidget::MainWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

void MainWidget::testButtonClicked()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	HDevProgram     hDevProgram;
	HDevProcedure   testProc;
	hDevProgram.LoadProgram("vision.hdev");
	
	//hDevProgram.LoadProgram("algorithm.hdev");

	testProc.LoadProcedure(hDevProgram, "test");

	DWORD t = GetTickCount();
	HDevProcedureCall procCall = testProc.CreateCall();
	procCall.SetInputCtrlParamTuple("a", 3);

	procCall.Execute();
	HTuple b = procCall.GetOutputCtrlParamTuple("b");


}
