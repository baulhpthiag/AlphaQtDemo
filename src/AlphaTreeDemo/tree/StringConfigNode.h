#pragma once

#include <QObject>

class StringConfigNode : public QObject
{
	Q_OBJECT
		Q_PROPERTY(QString nodeShowName MEMBER _nodeShowName)
		Q_PROPERTY(QString nodeValue MEMBER _nodeValue)
		Q_PROPERTY(bool isHot MEMBER _isHot)
		Q_PROPERTY(bool isShow MEMBER _isShow)
public:


	StringConfigNode(QObject *parent = nullptr);
	~StringConfigNode();

	StringConfigNode(const StringConfigNode& other, QObject* parent = nullptr)
	{
		this->_nodeShowName = other._nodeShowName;
		this->_nodeValue = other._nodeValue;
		this->_isHot = other._isHot;
		this->_isShow = other._isShow;
	}

	StringConfigNode& operator=(const StringConfigNode & other)
	{
		this->_nodeShowName = other._nodeShowName;
		this->_nodeValue = other._nodeValue;
		this->_isHot = other._isHot;
		this->_isShow = other._isShow;
		return *this;
	}

	//展示名称
	QString _nodeShowName;

	//节点值
	QString _nodeValue;

	//是否是热节点，将完全配置界面中的热节点显示到热配置界面
	bool _isHot;

	//是否在界面中显示
	bool _isShow;

	public slots:
	void nodeValueChanged(QString value);
};
Q_DECLARE_METATYPE(StringConfigNode)