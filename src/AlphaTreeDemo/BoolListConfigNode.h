#pragma once

#include <QObject>
#include "BoolConfigNode.h"

class BoolListConfigNode : public QObject
{
	Q_OBJECT
		Q_PROPERTY(QString nodeShowName MEMBER _nodeShowName)
		Q_PROPERTY(bool isShow MEMBER _isShow)
		Q_PROPERTY(bool isHot MEMBER _isHot)
		Q_PROPERTY(QList<BoolConfigNode> nodeList READ getNodeList WRITE setNodeList)
public:
	BoolListConfigNode(QObject *parent = nullptr);
	BoolListConfigNode(const BoolListConfigNode & other, QObject*parent = nullptr)
	{
		this->_nodeShowName = other._nodeShowName;
		this->_isShow = other._isShow;
		this->_isHot = other._isHot;
		this->_nodelist = other._nodelist;
	}

	~BoolListConfigNode();

	BoolListConfigNode& operator=(const BoolListConfigNode& other) 
	{
		this->_nodeShowName = other._nodeShowName;
		this->_isShow = other._isShow;
		this->_isHot = other._isHot;
		this->_nodelist = other._nodelist;
		return *this;
	}

	QString _nodeShowName;
	bool _isShow;
	bool _isHot;
	QList<BoolConfigNode> _nodelist;

	QList<BoolConfigNode>& getNodeList();

	public slots:
	void setNodeList(const QList<BoolConfigNode>& nodeList);

};
Q_DECLARE_METATYPE(BoolListConfigNode)