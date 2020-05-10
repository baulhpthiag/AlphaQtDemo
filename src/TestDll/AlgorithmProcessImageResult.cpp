#include "AlgorithmProcessImageResult.h"
#include "QStringHelper.h"
#include "DateTimeHelper.h"

AlgorithmProcessImageResult::AlgorithmProcessImageResult(QObject *parent)
	: QObject(parent)
{
	 _elapsedTime = "";
	 _message = "";

	 _iRsu = "";
	 _findPieces =0;
	 _arrSizeResult.clear();
	 _arrOmiMeasurement.clear();
	 _chRsuInfo = "";
	 _chRsuInfoEx = "";
	 _dExpendTime = 0;
}

AlgorithmProcessImageResult::AlgorithmProcessImageResult(const AlgorithmProcessImageResult& other, QObject *parent /*= nullptr*/)
{
	_elapsedTime = other._elapsedTime;
	_message = other._message;

	_iRsu = other._iRsu;
	_findPieces = other._findPieces;
	_arrSizeResult = other._arrSizeResult;
	_arrOmiMeasurement = other._arrOmiMeasurement;
	_innerRleStruct = other._innerRleStruct;
	_midRleStruct = other._midRleStruct;
	_outRleStruct = other._outRleStruct;
	_chRsuInfo = other._chRsuInfo;
	_chRsuInfoEx = other._chRsuInfoEx;
	_dExpendTime = other._dExpendTime;
}

AlgorithmProcessImageResult::~AlgorithmProcessImageResult()
{
}

void AlgorithmProcessImageResult::readOriginResult(s_Result originResult)
{
	_iRsu = originResult.iRsu == 0 ? "ok" : "ng";
	if (originResult.iRsu != 0)
	{
		return;
	}
	_findPieces = originResult.nPiecesNum;

	//todo
	for (int i =0;i<_findPieces;i++)
	{
		QString temp = originResult.arrResult[i] == 0 ? "ok" : "ng";
		_arrSizeResult.append(temp);
	}

	for (int i=0;i<_findPieces; i++)
	{
		QList<double> temp;
		for (int j = 0; j < sizeof(originResult.arrOmiMeasurement[i])/sizeof(originResult.arrOmiMeasurement[i][0]); j++)
		{
			double d = originResult.arrOmiMeasurement[i][j];
			if (0 != d)
			{
				temp.append(d);
			}
			else
			{
				break;
			}
		}
		_arrOmiMeasurement.append(temp);
	}

	if (_findPieces >0)
	{
		_innerRleStruct._nRLELenth = originResult.nRLELenth_Inner;
		for (int i = 0; i < originResult.nRLELenth_Inner; i++)
		{
			_innerRleStruct._pRLERow.append(originResult.pRLERow_Inner[i]);
			_innerRleStruct._pRLEColumnBegin.append(originResult.pRLEColumnBegin_Inner[i]);
			_innerRleStruct._pRLEColumnEnd.append(originResult.pRLEColumnEnd_Inner[i]);
		}

		_midRleStruct._nRLELenth = originResult.nRLELenth_Mid;
		for (int i = 0; i < originResult.nRLELenth_Mid; i++)
		{
			_midRleStruct._pRLERow.append(originResult.pRLERow_Mid[i]);
			_midRleStruct._pRLEColumnBegin.append(originResult.pRLEColumnBegin_Mid[i]);
			_midRleStruct._pRLEColumnEnd.append(originResult.pRLEColumnEnd_Mid[i]);
		}

		_outRleStruct._nRLELenth = originResult.nRLELenth_Out;
		for (int i = 0; i < originResult.nRLELenth_Out; i++)
		{
			_outRleStruct._pRLERow.append(originResult.pRLERow_Out[i]);
			_outRleStruct._pRLEColumnBegin.append(originResult.pRLEColumnBegin_Out[i]);
			_outRleStruct._pRLEColumnEnd.append(originResult.pRLEColumnEnd_Out[i]);
		}
	}
	


	_chRsuInfo = (LPSTR)(&(originResult.chRsuInfoEx));
	_chRsuInfoEx= (LPSTR)(&(originResult.chRsuInfoEx));
	_dExpendTime = originResult.dExpendTime;
}

QString AlgorithmProcessImageResult::toQString()
{
	QString result;
	result.append(DateTimeHelper::currentTime());
	result.append(QStringHelper::newLine()).append("dExpendTime:").append(QString::number(_dExpendTime));
	result.append(QStringHelper::newLine()).append("iRsu:").append(_iRsu);
	result.append(QStringHelper::twoSpace()).append("findPieces:").append(QString::number(_findPieces));
	for (int i =0;i<_findPieces;i++)
	{
		result.append(QStringHelper::newLine()).append("piece").append(QString::number(i)).append(" sizeResult:").append(_arrSizeResult[i]);
		result.append(QStringHelper::newLine());
		QList<double> omiMeasurement = _arrOmiMeasurement[i];
		for (int j =0;j<omiMeasurement.count();j++)
		{
			result.append(QString::number(omiMeasurement[j],'f',3)).append(" ");
		}
		//for (int j = 0; j < omiMeasurement.count(); j++)
		//{
		//	result.append(QStringHelper::newLineSpace()).append("omiMeasurement").append(QString::number(j)).append(":").append(QString::number(omiMeasurement[j]));
		//}
	}
	if (!_chRsuInfo.isEmpty())
	{
		result.append(QStringHelper::newLine()).append("chRsuInfo:").append(_chRsuInfo);
	}
	if (!_chRsuInfoEx.isEmpty())
	{
		result.append(QStringHelper::newLine()).append("chRsuInfoEx:").append(_chRsuInfoEx);
	}

	int lineCount = _innerRleStruct._nRLELenth+ _midRleStruct._nRLELenth+_outRleStruct._nRLELenth;

	//result.append(QStringHelper::newLine()).append("lineCount:").append(QString::number(lineCount));
	//result.append("elapsedTime:").append(_elapsedTime);
	//if (!_message.isEmpty())
	//{
	//	result.append(QStringHelper::newLine()).append("message:").append(_message);
	//}

	return result;
}
