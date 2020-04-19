#include "DoubleListConfigNode.h"

DoubleListConfigNode::DoubleListConfigNode(QObject *parent)
	: QObject(parent)
{

}

DoubleListConfigNode::DoubleListConfigNode(const DoubleListConfigNode & other, QObject* parent /*= nullptr*/)
{
	this->_nodeShowName = other._nodeShowName;
	this->_isHot = other._isHot;
	this->_isShow = other._isShow;
	this->_nodelist = other._nodelist;
}

DoubleListConfigNode::~DoubleListConfigNode()
{

}

DoubleListConfigNode& DoubleListConfigNode::operator=(const DoubleListConfigNode & other)
{
	this->_nodeShowName = other._nodeShowName;
	this->_isHot = other._isHot;
	this->_isShow = other._isShow;
	this->_nodelist = other._nodelist;
	return *this;
}

QList<DoubleConfigNode>& DoubleListConfigNode::getNodeList()
{
	return _nodelist;
}

QList<DoubleConfigNode*> DoubleListConfigNode::getNodeListP()
{
	QList<DoubleConfigNode*> list;
	for each (auto var in _nodelist)
	{
		list.append(&var);
	}
	return list;
}

void DoubleListConfigNode::setNodeList(const QList<DoubleConfigNode>& nodeList)
{
	_nodelist = nodeList;
}
