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

	//展示名称
	QString _nodeShowName;

	//节点值
	int _nodeValue;

	//最大值
	int _maxValue;

	//最小值
	int _minValue;

	//是否是热节点，将完全配置界面中的热节点显示到热配置界面
	bool _isHot;

	//是否在界面中显示
	bool _isShow;

	public slots:
	void nodeValueChanged(QString strvalue);
};
Q_DECLARE_METATYPE(IntConfigNode)