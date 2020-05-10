#pragma once

#include <QObject>
//#include "QStringHelper.h"

struct RleStruct
{
	// 游程数据长度
	int _nRLELenth;
	// 游程数据Row
	QList<int> _pRLERow;
	// 游程数据ColumnBegin
	QList<int> _pRLEColumnBegin;
	// 游程数据ColumnEnd
	QList<int> _pRLEColumnEnd;
	RleStruct()
	{
		_nRLELenth = 0;
		_pRLERow.clear();
		_pRLEColumnBegin.clear();
		_pRLEColumnEnd.clear();
	}
};


struct ImageStruct 
{
	unsigned char* _lpBuf;
	int _nWidth;
	int _nHeight;
	int _nBytePerPixel;
	long _lFrameIndex;

	ImageStruct()
	{
		_lpBuf = nullptr;
		_nWidth = 0;
		_nHeight = 0;
		_nBytePerPixel = 8;
		_lFrameIndex = 0;
	};
	QString toString() 
	{
		QString str;
		//str.append("lpBuf:").append(QString::number(_lFrameIndex)).append(QStringHelper::newLine());

		return str;
	}

};
Q_DECLARE_METATYPE(ImageStruct);

class CommonStruct : public QObject
{
	Q_OBJECT

public:
	CommonStruct(QObject *parent);
	~CommonStruct();
};
