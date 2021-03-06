#include "IntEnumListConfigNode.h"

IntEnumListConfigNode::IntEnumListConfigNode(QObject *parent)
	: QObject(parent)
{
}

IntEnumListConfigNode::IntEnumListConfigNode(const IntEnumListConfigNode& other, QObject * parent /*= nullptr*/)
{
	this->_nodeShowName = other._nodeShowName;
	this->_isHot = other._isHot;
	this->_isShow = other._isShow;
	this->_nodelist = other._nodelist;
}

IntEnumListConfigNode::~IntEnumListConfigNode()
{
}

QList<IntEnumConfigNode>& IntEnumListConfigNode::getNodeList()
{
	return _nodelist;
}

QList<IntEnumConfigNode*> IntEnumListConfigNode::getNodeListP()
{
	QList<IntEnumConfigNode*> list;
	for (int i = 0; i < _nodelist.count(); i++)
	{
		list.append(&_nodelist[i]);
	}
	return list;
}

void IntEnumListConfigNode::setNodeList(const QList<IntEnumConfigNode>& nodeList)
{
	_nodelist = nodeList;
}

IntEnumListConfigNode& IntEnumListConfigNode::operator=(const IntEnumListConfigNode& other)
{
	this->_nodeShowName = other._nodeShowName;
	this->_isHot = other._isHot;
	this->_isShow = other._isShow;
	this->_nodelist = other._nodelist;
	return *this;
}
