#pragma once

#include <QObject>
#include "CommonStruct.h"
#include "ImageProcessTool.h"

class AlgorithmProcessImageResult : public QObject
{
	Q_OBJECT

public:
	AlgorithmProcessImageResult(QObject *parent = nullptr);
	AlgorithmProcessImageResult(const AlgorithmProcessImageResult& other, QObject *parent = nullptr);
	~AlgorithmProcessImageResult();

	QString _elapsedTime;
	QString _message;

	//À„∑®–≈œ¢
	QString _chRsuInfo;
	QString _chRsuInfoEx;
	double _dExpendTime;
	QString _iRsu;
	int _findPieces;
	QList<QString> _arrSizeResult;
	QList<QList<double>> _arrOmiMeasurement;
	RleStruct _innerRleStruct;
	RleStruct _midRleStruct;
	RleStruct _outRleStruct;

	void readOriginResult(s_Result originResult);

	QString toQString();

};
Q_DECLARE_METATYPE(AlgorithmProcessImageResult)