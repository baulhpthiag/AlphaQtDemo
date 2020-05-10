#pragma once
#include <afx.h>
#include "vector"

//#define WIDTHBYTES(width,bits)    (((width * bits) + 31) / 32 * 4)	//���4�ֽڶ���
#define WIDTHBYTES(width,bits)    (width*bits/8)					//�������4�ֽڶ���

//��ʾ�����Ϣ
#define WM_USER_SHOW_RESULT (WM_USER + 520)

//��������
const int RSU_OK = 0;				    //��ȷ
const int RSU_ERROR_EXCEPTION = 1;	    //�㷨�쳣
const int RSU_ERROR_FORMAT = 2;		    //ͼ���ʽ����
const int RSU_ERROR_NOEXIST = 3;	    //�ļ�ȱʧ

// 2019.6 mj add
const int RSU_ERROR_FINDPOSFAIL = 4;        //��λʧ��
const int RSU_ERROR_MEASUREFAIL = 5;        //�ߴ����ʧ��
const int RSU_ERROR_EXCEPTION_MEASURE = 6;	//�쳣(�����ڳߴ����ģ��)



//���п�״̬
enum PROCESS_TOOL_STATUS
{
	PTS_FREE = 0,			//����
	PTS_READ = 1,			//��ͼ
	PTS_PROCESS = 2,		//���
	PTS_GRAB = 3			//�ɼ�
};
//���ؽ���ṹ��
struct s_Result
{
	int    iRsu;					  //����ͼ�Ķ�λ��� OK:0  NG:>0
	int    nPiecesNum;                //�ҵ���СƬ����
	int    arrResult[20];             //ÿ��СƬ�ĳߴ�����NG��1����OK��0��
	double arrOmiMeasurement[20][6];  //ÿ��СƬ6��ߴ�ֵ��fHorO��fHorM��fHorI��fVerO��fVerM��fVerI

	TCHAR chRsuInfo[256];		      //�㷨�쳣������Ϣ
	TCHAR chRsuInfoEx[4096];	      //�����������Ϣ

	double dExpendTime;			      //��ʱ

	// InnerRect�����γ�->����ϵͳ�����ڻ�������
	int nRLELenth_Inner;			// �γ����ݳ���
	INT64* pRLERow_Inner;			// �γ�����Row
	INT64* pRLEColumnBegin_Inner;	// �γ�����ColumnBegin
	INT64* pRLEColumnEnd_Inner;		// �γ�����ColumnEnd

	// MidRect�����γ�->����ϵͳ�����ڻ�������
	int nRLELenth_Mid;				// �γ����ݳ���
	INT64* pRLERow_Mid;				// �γ�����Row
	INT64* pRLEColumnBegin_Mid;		// �γ�����ColumnBegin
	INT64* pRLEColumnEnd_Mid;		// �γ�����ColumnEnd

	// OutRect�����γ�->����ϵͳ�����ڻ�������
	int nRLELenth_Out;				// �γ����ݳ���
	INT64* pRLERow_Out;				// �γ�����Row
	INT64* pRLEColumnBegin_Out;		// �γ�����ColumnBegin
	INT64* pRLEColumnEnd_Out;		// �γ�����ColumnEnd

	s_Result()
	{
		iRsu = 0;
		dExpendTime = 0;
		chRsuInfo[0] = 0;
		chRsuInfoEx[0] = 0;
        
		nRLELenth_Inner = 0;
		nRLELenth_Mid = 0;
		nRLELenth_Out = 0;

		for (int i=0; i<20; i++)
		{
			//arrLocResult[i] = 0;
			arrResult[i] = 0;
			for (int j=0; j<6; j++)
			{
				arrOmiMeasurement[i][j] = 0;
			}
		}
	}
};

struct PiecePara
{
	//2019.4 ÿ��СƬ˿ӡ��ߡ����������
	float fPrintWidth;   //2019.6->mm
	float fPrintHeight;
	float fGlassWidth;
	float fGlassHeight;
};
struct DetectPiecePara
{
	float fPrintWidth;   //pixel
	float fPrintHeight;
	float fGlassWidth;
	float fGlassHeight;
};
//��Ʒ�����ṹ-�����ã���λmm
struct ProductPara
{
	// 2019.3.15 ����ߴ�ı�׼ֵ	
	// ˿ӡ���˿ӡ�ǿ�˿ӡ�ڿ�
	// ˿ӡ�ⳤ��˿ӡ�ǳ���˿ӡ�ڳ�
	float fHor_O; 
	float fHor_M;
	float fHor_I;
	float fVer_O;
	float fVer_M;
	float fVer_I;

	//2019.6 �ߴ�����ֵ
	float fHor_O_Modify;
	float fHor_M_Modify;
	float fHor_I_Modify;
	float fVer_O_Modify;
	float fVer_M_Modify;
	float fVer_I_Modify;

	//2019.6 �ߴ�ƫ��������,��Ϊ����
	float fHor_O_Offset_UpLimit;
    float fHor_O_Offset_DownLimit;
	float fHor_M_Offset_UpLimit;
    float fHor_M_Offset_DownLimit;
	float fHor_I_Offset_UpLimit;
    float fHor_I_Offset_DownLimit;
	float fVer_O_Offset_UpLimit;
    float fVer_O_Offset_DownLimit;
	float fVer_M_Offset_UpLimit;
    float fVer_M_Offset_DownLimit;
	float fVer_I_Offset_UpLimit;
    float fVer_I_Offset_DownLimit;
};


class CImageProcessTool
{
public:
	CImageProcessTool() 
	{
		m_status = PTS_FREE;
	}
	virtual ~CImageProcessTool(){}
public:
	// ����λͼ��Ϣͷ������C++��ʾ
	void GenBmpInfoHeader(BITMAPINFO *pBmpInfo, int iWidth, int iHeight, int iBitCount)
	{
		pBmpInfo->bmiHeader.biBitCount = iBitCount;
		pBmpInfo->bmiHeader.biClrImportant = 0;
		pBmpInfo->bmiHeader.biClrUsed = 0;
		pBmpInfo->bmiHeader.biCompression = 0;
		pBmpInfo->bmiHeader.biPlanes = 1;
		pBmpInfo->bmiHeader.biSize = sizeof(tagBITMAPINFOHEADER);
		pBmpInfo->bmiHeader.biSizeImage = WIDTHBYTES(iWidth, iBitCount);
		pBmpInfo->bmiHeader.biXPelsPerMeter = 0;
		pBmpInfo->bmiHeader.biYPelsPerMeter = 0;
		pBmpInfo->bmiHeader.biWidth = iWidth;
		pBmpInfo->bmiHeader.biHeight = -iHeight;
		if (8 == iBitCount)
		{
			for (int i = 0; i < 256; i++)
			{
				pBmpInfo->bmiColors[i].rgbBlue = i;
				pBmpInfo->bmiColors[i].rgbGreen = i;
				pBmpInfo->bmiColors[i].rgbRed = i;
				pBmpInfo->bmiColors[i].rgbReserved = i;
			}
		}
	}
	// ��ȡ״̬
	PROCESS_TOOL_STATUS GetStatus() { return m_status; }
public:
	// ��ȡͼ��
	virtual s_Result ReadImageData(CString strPath, BYTE* pBuf, int& iWidth, int& iHeight, int& iBitCount) = 0;

	// ͼ����
	virtual s_Result Process(CString strPath) = 0;
	virtual s_Result Process(BYTE *pBuf, int iWidth, int iHeight, int iBitCount) = 0;
	
	//// ͼ����ʾ
	//virtual void BindWindowWnd(HWND hMainWnd, HWND hWnd, int iWndWidth, int iWndHeight) = 0;
	virtual s_Result ShowResult() = 0;

	// ����������
	virtual void SetDetectParaBL (ProductPara In_ProductPara, double fResolutionRatio) = 0;

protected:
	int m_iImageWidth, m_iImageHeight;	//ͼ���С
	int m_iWndWidth, m_iWndHeight;		//���ڴ�С
	PROCESS_TOOL_STATUS m_status;		//״̬
};

//����|����ʵ�����ӿ�����
CImageProcessTool* CreateProcessIntance();
void DestroyProcessIntance();

//���ýӿ�
typedef CImageProcessTool* (*CreateProcessTool)();
typedef void(*DestroyProcessTool)();
