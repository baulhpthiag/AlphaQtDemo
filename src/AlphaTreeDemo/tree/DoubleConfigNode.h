#pragma once

#include <QObject>


class DoubleConfigNode : public QObject
{
	Q_OBJECT
		Q_PROPERTY(QString nodeShowName MEMBER _nodeShowName)
		Q_PROPERTY(double nodeValue MEMBER _nodeValue)
		Q_PROPERTY(double maxValue MEMBER _maxValue)
		Q_PROPERTY(double minValue MEMBER _minValue)
		Q_PROPERTY(bool isHot MEMBER _isHot)
		Q_PROPERTY(bool isShow MEMBER _isShow)

public:
	DoubleConfigNode(const DoubleConfigNode& other, QObject* parent = nullptr)
	{
		this->_nodeShowName = other._nodeShowName;
		this->_nodeValue = other._nodeValue;
		this->_maxValue = other._maxValue;
		this->_minValue = other._minValue;
		this->_isHot = other._isHot;
		this->_isShow = other._isShow;
	}
	DoubleConfigNode(QObject *parent = nullptr);
	~DoubleConfigNode();

	DoubleConfigNode& operator=(const DoubleConfigNode & other)
	{
		this->_nodeShowName = other._nodeShowName;
		this->_nodeValue = other._nodeValue;
		this->_maxValue = other._maxValue;
		this->_minValue = other._minValue;
		this->_isHot = other._isHot;
		this->_isShow = other._isShow;
		return *this;
	}

	//չʾ����
	QString _nodeShowName;

	//�ڵ�ֵ
	double _nodeValue;

	//���ֵ
	double _maxValue;

	//��Сֵ
	double _minValue;

	//�Ƿ����Ƚڵ㣬����ȫ���ý����е��Ƚڵ���ʾ�������ý���
	bool _isHot;

	//�Ƿ��ڽ�������ʾ
	bool _isShow;

};

Q_DECLARE_METATYPE(DoubleConfigNode)