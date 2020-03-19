#pragma once

#include <afx.h>
#include <tchar.h>
#include <QtWidgets/QWidget>
#include "ui_JaiCameraDemoMainWidget.h"
#include <Jai_Factory.h>


#define NODE_NAME_WIDTH         (int8_t*)"Width"
#define NODE_NAME_HEIGHT        (int8_t*)"Height"
#define NODE_NAME_PIXELFORMAT   (int8_t*)"PixelFormat"
#define NODE_NAME_GAIN          (int8_t*)"GainRaw"
#define NODE_NAME_PAYLOADSIZE   (int8_t*)"PayloadSize"
#define NODE_NAME_ACQSTART      (int8_t*)"AcquisitionStart"
#define NODE_NAME_ACQSTOP       (int8_t*)"AcquisitionStop"




class JaiCameraDemoMainWidget : public QWidget
{
	Q_OBJECT

public:
	JaiCameraDemoMainWidget(QWidget *parent = Q_NULLPTR);
	~JaiCameraDemoMainWidget();

private:
	Ui::JaiCameraDemoMainWidgetClass ui;

	// Ù–‘
	FACTORY_HANDLE  m_hFactory;     // Factory Handle
	CAM_HANDLE      m_hCam;         // Camera Handle
	VIEW_HANDLE     m_hView;
	THRD_HANDLE     m_hThread;
	int8_t          m_sCameraId[J_CAMERA_ID_SIZE];    // Camera ID
	int64_t			m_iWidthInc;
	int64_t			m_iHeightInc;
	bool			m_bEnableStreaming;

	//∑Ω∑®
	void initWidget();
	void InitializeControls();
	void CloseFactoryAndCamera();
	void ShowErrorMsg(QString message, J_STATUS_TYPE error);
	void SetFramegrabberValue(CAM_HANDLE hCam, int8_t* szName, int64_t int64Val, int8_t* sCameraId);
	void SetFramegrabberPixelFormat(CAM_HANDLE hCam, int8_t* szName, int64_t jaiPixelFormat, int8_t* sCameraId);
	static void StreamCBFunc(J_tIMAGE_INFO * pAqImageInfo);

	public slots:
	void searchCamerasButtonClicked();
	void startButtonClicked();
	void stopButtonClicked();

};
