// ImageProcessBasicHalcon.h : ImageProcessBasicHalcon DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CImageProcessBasicHalconApp
// �йش���ʵ�ֵ���Ϣ������� ImageProcessBasicHalcon.cpp
//

class CImageProcessBasicHalconApp : public CWinApp
{
public:
	CImageProcessBasicHalconApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
