#pragma once

#include <QObject>

class DoubleEnumConfigNode : public QObject
{
	Q_OBJECT
		Q_PROPERTY(QString nodeShowName MEMBER _nodeShowName)
		Q_PROPERTY(int enumIndex MEMBER _enumIndex)
		Q_PROPERTY(QList<double> valueEnum MEMBER _valueEnum)
		Q_PROPERTY(bool isHot MEMBER _isHot)
		Q_PROPERTY(bool isShow MEMBER _isShow)

public:
	DoubleEnumConfigNode(const DoubleEnumConfigNode& other, QObject * parent = nullptr)
	{
		this->_nodeShowName = other._nodeShowName;
		this->_enumIndex = other._enumIndex;
		this->_valueEnum = other._valueEnum;
		this->_isHot = other._isHot;
		this->_isShow = other._isShow;
	}
	DoubleEnumConfigNode(QObject *parent = nullptr);
	~DoubleEnumConfigNode();

	DoubleEnumConfigNode& operator=(const DoubleEnumConfigNode& other)
	{
		this->_nodeShowName = other._nodeShowName;
		this->_enumIndex = other._enumIndex;
		this->_valueEnum = other._valueEnum;
		this->_isHot = other._isHot;
		this->_isShow = other._isShow;
		return *this;
	}

	//展示名称
	QString _nodeShowName;

	//枚举索引
	int _enumIndex;

	//枚举值
	QList<double> _valueEnum;

	//是否是热节点，将完全配置界面中的热节点显示到热配置界面
	bool _isHot;

	//是否在界面中显示
	bool _isShow;

public slots:
	void nodeValueIndexChanged(int index);
};

Q_DECLARE_METATYPE(DoubleEnumConfigNode)