#pragma once

#include <QObject>

class IntConfigNode : public QObject
{
	Q_OBJECT
		Q_PROPERTY(QString nodeShowName MEMBER _nodeShowName)
		Q_PROPERTY(int nodeValue MEMBER _nodeValue)
		Q_PROPERTY(int maxValue MEMBER _maxValue)
		Q_PROPERTY(int minValue MEMBER _minValue)
		Q_PROPERTY(bool isHot MEMBER _isHot)
		Q_PROPERTY(bool isShow MEMBER _isShow)

public:
	IntConfigNode(const IntConfigNode& other, QObject* parent = nullptr)
	{
		this->_nodeShowName = other._nodeShowName;
		this->_nodeValue = other._nodeValue;
		this->_maxValue = other._maxValue;
		this->_minValue = other._minValue;
		this->_isHot = other._isHot;
		this->_isShow = other._isShow;
	}

	IntConfigNode(QObject *parent = nullptr);
	~IntConfigNode();

	IntConfigNode& operator=(const IntConfigNode& other)
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
	int _nodeValue;

	//���ֵ
	int _maxValue;

	//��Сֵ
	int _minValue;

	//�Ƿ����Ƚڵ㣬����ȫ���ý����е��Ƚڵ���ʾ�������ý���
	bool _isHot;

	//�Ƿ��ڽ�������ʾ
	bool _isShow;

	public slots:
	void nodeValueChanged(QString strvalue);
};
Q_DECLARE_METATYPE(IntConfigNode)