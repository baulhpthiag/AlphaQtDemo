#include "IntListConfigNode.h"

IntListConfigNode::IntListConfigNode(QObject *parent)
	: QObject(parent)
{
}

IntListConfigNode::IntListConfigNode(const IntListConfigNode& other, QObject* parent /*= nullptr*/)
{
	this->_nodeShowName = other._nodeShowName;
	this->_isHot = other._isHot;
	this->_isShow = other._isShow;
	this->_nodelist = other._nodelist;
}

IntListConfigNode::~IntListConfigNode()
{
}

IntListConfigNode& IntListConfigNode::operator=(const IntListConfigNode& other)
{
	this->_nodeShowName = other._nodeShowName;
	this->_isHot = other._isHot;
	this->_isShow = other._isShow;
	this->_nodelist = other._nodelist;
	return *this;
}

QList<IntConfigNode>& IntListConfigNode::getNodeList()
{
	return _nodelist;
}

QList<IntConfigNode*> IntListConfigNode::getNodeListP()
{
	QList<IntConfigNode*> list;
	for each (auto var in _nodelist)
	{
		list.append(&var);
	}
	return list;
}

void IntListConfigNode::setNodeList(const QList<IntConfigNode>& nodeList)
{
	_nodelist = nodeList;
}
