#include "JaiCameraDemoMainWidget.h"
#include <QDebug>


JaiCameraDemoMainWidget::JaiCameraDemoMainWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	initWidget();
}

JaiCameraDemoMainWidget::~JaiCameraDemoMainWidget()
{
	stopButtonClicked();
	CloseFactoryAndCamera();
}

void JaiCameraDemoMainWidget::initWidget()
{
	//列宽自适应
	ui.cameraConfigTableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	ui.cameraConfigTableWidget->setColumnCount(2);
	ui.cameraConfigTableWidget->setHorizontalHeaderLabels(QStringList() << u8"参数名称"<<u8"参数值");
	ui.cameraConfigTableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
	ui.cameraConfigTableWidget->setRowCount(3);
	ui.cameraConfigTableWidget->setItem(0, 0, new QTableWidgetItem(u8"图像宽"));
	ui.cameraConfigTableWidget->setItem(1, 0, new QTableWidgetItem(u8"图像高"));
	ui.cameraConfigTableWidget->setItem(2, 0, new QTableWidgetItem(u8"增益"));

}

void JaiCameraDemoMainWidget::InitializeControls()
{
	//J_STATUS_TYPE retval;
	//NODE_HANDLE hNode;
	//int64_t int64Val;

	////- Width ------------------------------------------------

	//// Get SliderCtrl for Width
	//if (m_bEnableStreaming)
	//{
	//	// Get Width Node
	//	retval = J_Camera_GetNodeByName(m_hCam, NODE_NAME_WIDTH, &hNode);
	//	if (retval == J_ST_SUCCESS)
	//	{
	//		// Get/Set Min
	//		retval = J_Node_GetMinInt64(hNode, &int64Val);
	//		pSCtrl->SetRangeMin((int)int64Val, TRUE);

	//		// Get/Set Max
	//		retval = J_Node_GetMaxInt64(hNode, &int64Val);
	//		pSCtrl->SetRangeMax((int)int64Val, TRUE);

	//		// Get/Set Value
	//		retval = J_Node_GetValueInt64(hNode, FALSE, &int64Val);
	//		pSCtrl->SetPos((int)int64Val);

	//		SetDlgItemInt(IDC_WIDTH, (int)int64Val);

	//		retval = J_Node_GetInc(hNode, &m_iWidthInc);
	//		m_iWidthInc = max(1, m_iWidthInc);

	//		//Set frame grabber dimension, if applicable
	//		SetFramegrabberValue(m_hCam, NODE_NAME_WIDTH, int64Val, &m_sCameraId[0]);
	//	}
	//	else
	//	{
	//		ShowErrorMsg(CString("Could not get Width node!"), retval);

	//		pSCtrl->ShowWindow(SW_HIDE);
	//		GetDlgItem(IDC_LBL_WIDTH)->ShowWindow(SW_HIDE);
	//		GetDlgItem(IDC_WIDTH)->ShowWindow(SW_HIDE);
	//	}
	//}
	//else
	//{
	//	pSCtrl->ShowWindow(SW_HIDE);
	//	GetDlgItem(IDC_LBL_WIDTH)->ShowWindow(SW_HIDE);
	//	GetDlgItem(IDC_WIDTH)->ShowWindow(SW_HIDE);
	//}

	////- Height -----------------------------------------------
	//// Get SliderCtrl for Height
	//pSCtrl = (CSliderCtrl*)GetDlgItem(IDC_SLIDER_HEIGHT);

	//if (m_bEnableStreaming)
	//{
	//	// Get Height Node
	//	retval = J_Camera_GetNodeByName(m_hCam, NODE_NAME_HEIGHT, &hNode);
	//	if (retval == J_ST_SUCCESS && m_bEnableStreaming)
	//	{
	//		// Get/Set Min
	//		retval = J_Node_GetMinInt64(hNode, &int64Val);
	//		pSCtrl->SetRangeMin((int)int64Val, TRUE);

	//		// Get/Set Max
	//		retval = J_Node_GetMaxInt64(hNode, &int64Val);
	//		pSCtrl->SetRangeMax((int)int64Val, TRUE);

	//		// Get/Set Value
	//		retval = J_Node_GetValueInt64(hNode, FALSE, &int64Val);
	//		pSCtrl->SetPos((int)int64Val);

	//		SetDlgItemInt(IDC_HEIGHT, (int)int64Val);

	//		retval = J_Node_GetInc(hNode, &m_iHeightInc);
	//		m_iHeightInc = max(1, m_iHeightInc);

	//		//Set frame grabber dimension, if applicable
	//		SetFramegrabberValue(m_hCam, NODE_NAME_HEIGHT, int64Val, &m_sCameraId[0]);
	//	}
	//	else
	//	{
	//		ShowErrorMsg(CString("Could not get Height node!"), retval);

	//		pSCtrl->ShowWindow(SW_HIDE);
	//		GetDlgItem(IDC_LBL_HEIGHT)->ShowWindow(SW_HIDE);
	//		GetDlgItem(IDC_HEIGHT)->ShowWindow(SW_HIDE);
	//	}
	//}
	//else
	//{
	//	pSCtrl->ShowWindow(SW_HIDE);
	//	GetDlgItem(IDC_LBL_HEIGHT)->ShowWindow(SW_HIDE);
	//	GetDlgItem(IDC_HEIGHT)->ShowWindow(SW_HIDE);
	//}

	////- Gain -----------------------------------------------

	//// Get SliderCtrl for Gain
	//pSCtrl = (CSliderCtrl*)GetDlgItem(IDC_SLIDER_GAIN);

	//// Get Gain Node
	//retval = J_Camera_GetNodeByName(m_hCam, NODE_NAME_GAIN, &hNode);
	//if (retval == J_ST_SUCCESS)
	//{
	//	// Get/Set Min
	//	retval = J_Node_GetMinInt64(hNode, &int64Val);
	//	pSCtrl->SetRangeMin((int)int64Val, TRUE);

	//	// Get/Set Max
	//	retval = J_Node_GetMaxInt64(hNode, &int64Val);
	//	pSCtrl->SetRangeMax((int)int64Val, TRUE);

	//	// Get/Set Value
	//	retval = J_Node_GetValueInt64(hNode, FALSE, &int64Val);
	//	pSCtrl->SetPos((int)int64Val);

	//	SetDlgItemInt(IDC_GAIN, (int)int64Val);
	//}
	//else
	//{
	//	//ShowErrorMsg(CString("Could not get Gain node!"), retval);

	//	pSCtrl->ShowWindow(SW_HIDE);
	//	GetDlgItem(IDC_LBL_GAIN)->ShowWindow(SW_HIDE);
	//	GetDlgItem(IDC_GAIN)->ShowWindow(SW_HIDE);
	//}

}

void JaiCameraDemoMainWidget::CloseFactoryAndCamera()
{
	J_STATUS_TYPE   retval;

	if (m_hCam)
	{
		// Close camera
		retval = J_Camera_Close(m_hCam);
		if (retval != J_ST_SUCCESS)
		{
			ShowErrorMsg("Could not close the camera!", retval);
		}
		m_hCam = NULL;
		qDebug("Closed camera\n");
	}

	if (m_hFactory)
	{
		// Close factory
		retval = J_Factory_Close(m_hFactory);
		if (retval != J_ST_SUCCESS)
		{
			ShowErrorMsg("Could not close the factory!", retval);
		}
		m_hFactory = NULL;
		qDebug("Closed factory\n");
	}

}

void JaiCameraDemoMainWidget::ShowErrorMsg(QString message, J_STATUS_TYPE error)
{
	QString errorMsg;
	errorMsg+=message;

	switch (error)
	{
	case J_ST_INVALID_BUFFER_SIZE:	errorMsg += "Invalid buffer size ";	                break;
	case J_ST_INVALID_HANDLE:		errorMsg += "Invalid handle ";		                break;
	case J_ST_INVALID_ID:			errorMsg += "Invalid ID ";			                break;
	case J_ST_ACCESS_DENIED:		errorMsg += "Access denied ";		                break;
	case J_ST_NO_DATA:				errorMsg += "No data ";				                break;
	case J_ST_ERROR:				errorMsg += "Generic error ";		                break;
	case J_ST_INVALID_PARAMETER:	errorMsg += "Invalid parameter ";	                break;
	case J_ST_TIMEOUT:				errorMsg += "Timeout ";				                break;
	case J_ST_INVALID_FILENAME:		errorMsg += "Invalid file name ";	                break;
	case J_ST_INVALID_ADDRESS:		errorMsg += "Invalid address ";		                break;
	case J_ST_FILE_IO:				errorMsg += "File IO error ";		                break;
	case J_ST_GC_ERROR:				errorMsg += "GenICam error ";		                break;
	case J_ST_VALIDATION_ERROR:		errorMsg += "Settings File Validation Error ";		break;
	case J_ST_VALIDATION_WARNING:	errorMsg += "Settings File Validation Warning ";    break;
	}

	qDebug()<<errorMsg;
}

void JaiCameraDemoMainWidget::SetFramegrabberValue(CAM_HANDLE hCam, int8_t* szName, int64_t int64Val, int8_t* sCameraId)
{
	//Set frame grabber value, if applicable
	DEV_HANDLE hDev = NULL; //If a frame grabber exists, it is at the GenTL "local device layer".
	J_STATUS_TYPE retval = J_Camera_GetLocalDeviceHandle(hCam, &hDev);
	if (J_ST_SUCCESS != retval)
		return;

	if (NULL == hDev)
		return;

	NODE_HANDLE hNode;
	retval = J_Camera_GetNodeByName(hDev, szName, &hNode);
	if (J_ST_SUCCESS != retval)
		return;

	retval = J_Node_SetValueInt64(hNode, false, int64Val);
	if (J_ST_SUCCESS != retval)
		return;

	//Special handling for Active Silicon CXP boards, which also has nodes prefixed
	//with "Incoming":
	std::string strTransportName((char*)sCameraId);
	if (std::string::npos != strTransportName.find("TLActiveSilicon"))
	{
		std::string strName((char*)szName);
		if (std::string::npos != strName.find("Width")
			|| std::string::npos != strName.find("Height"))
		{
			std::string strIncoming = "Incoming" + strName;
			NODE_HANDLE hNodeIncoming;
			J_STATUS_TYPE retval = J_Camera_GetNodeByName(hDev, (int8_t*)strIncoming.c_str(), &hNodeIncoming);
			if (retval == J_ST_SUCCESS)
			{
				retval = J_Node_SetValueInt64(hNodeIncoming, false, int64Val);
			}
		}

	}//if(std::string::npos != strTransportName.find("TLActiveSilicon"))
}

void JaiCameraDemoMainWidget::SetFramegrabberPixelFormat(CAM_HANDLE hCam, int8_t* szName, int64_t jaiPixelFormat, int8_t* sCameraId)
{
	DEV_HANDLE hDev = NULL; //If a frame grabber exists, it is at the GenTL "local device layer".
	J_STATUS_TYPE retval = J_Camera_GetLocalDeviceHandle(hCam, &hDev);
	if (J_ST_SUCCESS != retval)
		return;

	if (NULL == hDev)
		return;

	int8_t szJaiPixelFormatName[512];
	uint32_t iSize = 512;
	retval = J_Image_Get_PixelFormatName(hCam, jaiPixelFormat, szJaiPixelFormatName, iSize);
	if (J_ST_SUCCESS != retval)
		return;

	NODE_HANDLE hLocalDeviceNode = 0;
	retval = J_Camera_GetNodeByName(hDev, (int8_t *)"PixelFormat", &hLocalDeviceNode);
	if (J_ST_SUCCESS != retval)
		return;

	if (0 == hLocalDeviceNode)
		return;

	//NOTE: this may fail if the camera and/or frame grabber does not use the SFNC naming convention for pixel formats!
	//Check the camera and frame grabber for details.
	retval = J_Node_SetValueString(hLocalDeviceNode, false, szJaiPixelFormatName);
	if (J_ST_SUCCESS != retval)
		return;

	//Special handling for Active Silicon CXP boards, which also has nodes prefixed
	//with "Incoming":
	std::string strTransportName((char*)sCameraId);
	if (std::string::npos != strTransportName.find("TLActiveSilicon"))
	{
		std::string strIncoming = std::string("Incoming") + std::string((char*)szName);
		NODE_HANDLE hNodeIncoming;
		J_STATUS_TYPE retval = J_Camera_GetNodeByName(hDev, (int8_t*)strIncoming.c_str(), &hNodeIncoming);
		if (retval == J_ST_SUCCESS)
		{
			//NOTE: this may fail if the camera and/or frame grabber does not use the SFNC naming convention for pixel formats!
			//Check the camera and frame grabber for details.
			retval = J_Node_SetValueString(hNodeIncoming, false, szJaiPixelFormatName);
		}
	}
}

void JaiCameraDemoMainWidget::StreamCBFunc(J_tIMAGE_INFO * pAqImageInfo)
{
	// Test of chunk data
	// Try to read one of the cunks from the test camera
	int64_t chunkDataValue = 0;
	J_STATUS_TYPE err = J_Camera_GetValueInt64(m_hCam, (int8_t*)"ChunkTimestamp", &chunkDataValue);
	if (err == J_ST_SUCCESS)
	{
		////todo 
		//WCHAR buffer[100];

		//wsprintf(buffer, _T("Chunk Timestamp=%I64u\n"), chunkDataValue);
		//OutputDebugString(buffer);
	}

	if (m_hView)
	{
		if ((pAqImageInfo->iSizeX != 0)
			&& (pAqImageInfo->iSizeY != 0)
			&& (pAqImageInfo->iPixelType != 0))
		{
			// Shows image
			J_Image_ShowImage(m_hView, pAqImageInfo);
		}
	}
}

void JaiCameraDemoMainWidget::searchCamerasButtonClicked()
{
	J_STATUS_TYPE   retval;
	uint32_t        iSize;
	uint32_t        iNumDev;
	bool8_t         bHasChange;

	m_bEnableStreaming = false;

	// Open factory
	retval = J_Factory_Open((int8_t*)"", &m_hFactory);
	if (retval != J_ST_SUCCESS)
	{
		ShowErrorMsg("Could not open factory!", retval);
		return ;
	}
	qDebug()<<"Opening factory succeeded\n";

	//Update camera list
	retval = J_Factory_UpdateCameraList(m_hFactory, &bHasChange);
	if (retval != J_ST_SUCCESS)
	{
		ShowErrorMsg("Could not update camera list!", retval);
		return;
	}
	qDebug()<<"Updating camera list succeeded\n";

	// Get the number of Cameras
	retval = J_Factory_GetNumOfCameras(m_hFactory, &iNumDev);
	if (retval != J_ST_SUCCESS)
	{
		ShowErrorMsg("Could not get the number of cameras!", retval);
		return ;
	}

	if (iNumDev == 0)
	{
		ShowErrorMsg("Invalid number of cameras!", retval);
		return ;
	}
	qDebug()<< iNumDev <<" cameras were found\n";

	// Get camera ID
	iSize = (uint32_t)sizeof(m_sCameraId);
	retval = J_Factory_GetCameraIDByIndex(m_hFactory, 0, m_sCameraId, &iSize);
	if (retval != J_ST_SUCCESS)
	{
		ShowErrorMsg("Could not get the camera ID!", retval);
		return ;
	}
	qDebug()<<"Camera ID:"<< m_sCameraId;

	// Open camera
	retval = J_Camera_Open(m_hFactory, m_sCameraId, &m_hCam);
	if (retval != J_ST_SUCCESS)
	{
		ShowErrorMsg("Could not open the camera!", retval);
		return;
	}

	//Make sure streaming is supported!
	uint32_t numStreams = 0;
	retval = J_Camera_GetNumOfDataStreams(m_hCam, &numStreams);
	if (retval != J_ST_SUCCESS)
	{
		ShowErrorMsg("Error with J_Camera_GetNumOfDataStreams.", retval);
		return;
	}

	if (0 == numStreams)
	{
		m_bEnableStreaming = false;
	}
	else
	{
		m_bEnableStreaming = true;
	}

	if (iNumDev > 0 && 0 != m_hCam)
	{
		qDebug("Opening camera succeeded\n");
	}
	else
	{
		ShowErrorMsg("Invalid number of Devices!", iNumDev);
		return ;
	}

	QString cameraId=QString((char*)m_sCameraId);

	//列宽自适应
	ui.camerasTableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	ui.camerasTableWidget->setColumnCount(1);
	ui.camerasTableWidget->setHorizontalHeaderLabels(QStringList() << u8"相机id");
	ui.camerasTableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
	ui.camerasTableWidget->setRowCount(1);
	ui.camerasTableWidget->setItem(0, 0, new QTableWidgetItem(cameraId));

}

void JaiCameraDemoMainWidget::startButtonClicked()
{
	J_STATUS_TYPE   retval;
	int64_t int64Val;

	SIZE	ViewSize;
	POINT	TopLeft;

	if (!m_bEnableStreaming)
	{
		ShowErrorMsg("Streaming not enabled on this device.", 0);
		return;
	}

	// Get Width from the camera
	retval = J_Camera_GetValueInt64(m_hCam, NODE_NAME_WIDTH, &int64Val);
	if (retval != J_ST_SUCCESS)
	{
		ShowErrorMsg("Could not get Width!", retval);
		return;
	}
	ViewSize.cx = (LONG)int64Val;     // Set window size cx

									  //Set frame grabber dimension, if applicable
	SetFramegrabberValue(m_hCam, NODE_NAME_WIDTH, int64Val, &m_sCameraId[0]);

	// Get Height from the camera
	retval = J_Camera_GetValueInt64(m_hCam, NODE_NAME_HEIGHT, &int64Val);
	if (retval != J_ST_SUCCESS)
	{
		ShowErrorMsg("Could not get Height!", retval);
		return;
	}
	ViewSize.cy = (LONG)int64Val;     // Set window size cy

									  //Set frame grabber dimension, if applicable
	SetFramegrabberValue(m_hCam, NODE_NAME_HEIGHT, int64Val, &m_sCameraId[0]);

	// Set window position
	TopLeft.x = 100;
	TopLeft.y = 50;

	//Set frame grabber dimension, if applicable
	SetFramegrabberValue(m_hCam, NODE_NAME_HEIGHT, int64Val, &m_sCameraId[0]);

	// Get the pixelformat from the camera
	int64_t pixelFormat = 0;
	uint64_t jaiPixelFormat = 0;
	retval = J_Camera_GetValueInt64(m_hCam, NODE_NAME_PIXELFORMAT, &pixelFormat);
	if (retval != J_ST_SUCCESS)
	{
		ShowErrorMsg("Unable to get PixelFormat value!", retval);
		return;
	}
	J_Image_Get_PixelFormat(m_hCam, pixelFormat, &jaiPixelFormat);

	//Set frame grabber pixel format, if applicable
	SetFramegrabberPixelFormat(m_hCam, NODE_NAME_PIXELFORMAT, pixelFormat, &m_sCameraId[0]);

	// Calculate number of bits (not bytes) per pixel using macro
	int bpp = J_BitsPerPixel(jaiPixelFormat);

	// Open view window
	QString str = "Image View Window";
	LPCWSTR strVariable2 = (const wchar_t*)str.utf16();
	retval = J_Image_OpenViewWindow(strVariable2, &TopLeft, &ViewSize, &m_hView);
	//retval = J_Image_OpenViewWindow(_T("Image View Window"), &TopLeft, &ViewSize, &m_hView);
	if (retval != J_ST_SUCCESS) {
		ShowErrorMsg("Could not open view window!", retval);
		return;
	}
	qDebug("Opening view window succeeded\n");

	int64_t payloadSize = 0;
	retval = J_Camera_GetValueInt64(m_hCam, NODE_NAME_PAYLOADSIZE, &payloadSize);
	if (retval != J_ST_SUCCESS)
	{
		ShowErrorMsg("Unable to get PayloadSize value!", retval);
		return;
	}

	void *vfptr = &StreamCBFunc;

	J_IMG_CALLBACK_FUNCTION *cbfptr = reinterpret_cast<J_IMG_CALLBACK_FUNCTION*>(&vfptr);

	retval = J_Image_OpenStream(m_hCam,
		0,
		reinterpret_cast<J_IMG_CALLBACK_OBJECT>(this),
		*cbfptr,
		&m_hThread,
		(uint32_t)payloadSize);

	// Open stream


	//retval = J_Image_OpenStream(m_hCam,
	//	0,
	//	reinterpret_cast<J_IMG_CALLBACK_OBJECT>(this),
	//	reinterpret_cast<J_IMG_CALLBACK_FUNCTION>(&JaiCameraDemoMainWidget::StreamCBFunc),
	//	&m_hThread,
	//	(uint32_t)payloadSize);
	
	if (retval != J_ST_SUCCESS) {
		ShowErrorMsg("Could not open stream!", retval);
		return;
	}
	qDebug("Opening stream succeeded\n");

	// Start Acquisition
	retval = J_Camera_ExecuteCommand(m_hCam, NODE_NAME_ACQSTART);
	if (retval != J_ST_SUCCESS)
	{
		ShowErrorMsg("Could not Start Acquisition!", retval);
		return;
	}

}

void JaiCameraDemoMainWidget::stopButtonClicked()
{
	J_STATUS_TYPE retval;

	if (!m_bEnableStreaming)
	{
		return;
	}

	// Stop Acquisition
	if (m_hCam) {
		retval = J_Camera_ExecuteCommand(m_hCam, NODE_NAME_ACQSTOP);
		if (retval != J_ST_SUCCESS)
		{
			ShowErrorMsg("Could not Stop Acquisition!", retval);
		}
	}

	if (m_hThread)
	{
		// Close stream
		retval = J_Image_CloseStream(m_hThread);
		if (retval != J_ST_SUCCESS)
		{
			ShowErrorMsg("Could not close Stream!", retval);
		}
		m_hThread = NULL;
		qDebug("Closed stream\n");
	}

	if (m_hView)
	{
		// Close view window
		retval = J_Image_CloseViewWindow(m_hView);
		if (retval != J_ST_SUCCESS)
		{
			ShowErrorMsg("Could not close View Window!", retval);
		}
		m_hView = NULL;
		qDebug("Closed view window\n");
	}



}
