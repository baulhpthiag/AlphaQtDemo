#pragma once
#include <afx.h>
#include "vector"

//#define WIDTHBYTES(width,bits)    (((width * bits) + 31) / 32 * 4)	//宽度4字节对齐
#define WIDTHBYTES(width,bits)    (width*bits/8)					//宽度无需4字节对齐

//显示结果消息
#define WM_USER_SHOW_RESULT (WM_USER + 520)

//错误类型
const int RSU_OK = 0;				    //正确
const int RSU_ERROR_EXCEPTION = 1;	    //算法异常
const int RSU_ERROR_FORMAT = 2;		    //图像格式错误
const int RSU_ERROR_NOEXIST = 3;	    //文件缺失

// 2019.6 mj add
const int RSU_ERROR_FINDPOSFAIL = 4;        //定位失败
const int RSU_ERROR_MEASUREFAIL = 5;        //尺寸测量失败
const int RSU_ERROR_EXCEPTION_MEASURE = 6;	//异常(发生在尺寸测量模块)



//运行库状态
enum PROCESS_TOOL_STATUS
{
	PTS_FREE = 0,			//空闲
	PTS_READ = 1,			//读图
	PTS_PROCESS = 2,		//检测
	PTS_GRAB = 3			//采集
};
//返回结果结构体
struct s_Result
{
	int    iRsu;					  //整张图的定位结果 OK:0  NG:>0
	int    nPiecesNum;                //找到的小片个数
	int    arrResult[20];             //每个小片的尺寸检测结果NG（1）、OK（0）
	double arrOmiMeasurement[20][6];  //每个小片6项尺寸值：fHorO、fHorM、fHorI、fVerO、fVerM、fVerI

	TCHAR chRsuInfo[256];		      //算法异常描述信息
	TCHAR chRsuInfoEx[4096];	      //检测结果描述信息

	double dExpendTime;			      //耗时

	// InnerRect区域游程->传给系统，用于绘制区域
	int nRLELenth_Inner;			// 游程数据长度
	INT64* pRLERow_Inner;			// 游程数据Row
	INT64* pRLEColumnBegin_Inner;	// 游程数据ColumnBegin
	INT64* pRLEColumnEnd_Inner;		// 游程数据ColumnEnd

	// MidRect区域游程->传给系统，用于绘制区域
	int nRLELenth_Mid;				// 游程数据长度
	INT64* pRLERow_Mid;				// 游程数据Row
	INT64* pRLEColumnBegin_Mid;		// 游程数据ColumnBegin
	INT64* pRLEColumnEnd_Mid;		// 游程数据ColumnEnd

	// OutRect区域游程->传给系统，用于绘制区域
	int nRLELenth_Out;				// 游程数据长度
	INT64* pRLERow_Out;				// 游程数据Row
	INT64* pRLEColumnBegin_Out;		// 游程数据ColumnBegin
	INT64* pRLEColumnEnd_Out;		// 游程数据ColumnEnd

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
	//2019.4 每个小片丝印宽高、镜面外框宽高
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
//产品参数结构-传入用，单位mm
struct ProductPara
{
	// 2019.3.15 各项尺寸的标准值	
	// 丝印外宽、丝印角宽、丝印内宽
	// 丝印外长、丝印角长、丝印内长
	float fHor_O; 
	float fHor_M;
	float fHor_I;
	float fVer_O;
	float fVer_M;
	float fVer_I;

	//2019.6 尺寸修正值
	float fHor_O_Modify;
	float fHor_M_Modify;
	float fHor_I_Modify;
	float fVer_O_Modify;
	float fVer_M_Modify;
	float fVer_I_Modify;

	//2019.6 尺寸偏差上下限,都为正数
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
	// 生成位图信息头，用于C++显示
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
	// 获取状态
	PROCESS_TOOL_STATUS GetStatus() { return m_status; }
public:
	// 读取图像
	virtual s_Result ReadImageData(CString strPath, BYTE* pBuf, int& iWidth, int& iHeight, int& iBitCount) = 0;

	// 图像处理
	virtual s_Result Process(CString strPath) = 0;
	virtual s_Result Process(BYTE *pBuf, int iWidth, int iHeight, int iBitCount) = 0;
	
	//// 图像显示
	//virtual void BindWindowWnd(HWND hMainWnd, HWND hWnd, int iWndWidth, int iWndHeight) = 0;
	virtual s_Result ShowResult() = 0;

	// 检测参数设置
	virtual void SetDetectParaBL (ProductPara In_ProductPara, double fResolutionRatio) = 0;

protected:
	int m_iImageWidth, m_iImageHeight;	//图像大小
	int m_iWndWidth, m_iWndHeight;		//窗口大小
	PROCESS_TOOL_STATUS m_status;		//状态
};

//创建|销毁实例，接口声明
CImageProcessTool* CreateProcessIntance();
void DestroyProcessIntance();

//调用接口
typedef CImageProcessTool* (*CreateProcessTool)();
typedef void(*DestroyProcessTool)();
