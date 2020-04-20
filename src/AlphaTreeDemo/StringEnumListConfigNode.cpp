#include "StringEnumListConfigNode.h"

StringEnumListConfigNode::StringEnumListConfigNode(QObject *parent)
	: QObject(parent)
{
}

StringEnumListConfigNode::StringEnumListConfigNode(const StringEnumListConfigNode& other, QObject*parent /*= nullptr*/)
{
	this->_nodeShowName = other._nodeShowName;
	this->_isHot = other._isHot;
	this->_isShow = other._isShow;
	this->_nodelist = other._nodelist;
}

StringEnumListConfigNode::~StringEnumListConfigNode()
{
}

QList<StringEnumConfigNode>& StringEnumListConfigNode::getNodeList()
{
	return _nodelist;
}

QList<StringEnumConfigNode*> StringEnumListConfigNode::getNodeListP()
{
	QList<StringEnumConfigNode*> list;
	for (int i = 0; i < _nodelist.count(); i++)
	{
		list.append(&_nodelist[i]);
	}
	return list;
}

void StringEnumListConfigNode::setNodeList(const QList<StringEnumConfigNode>& nodeList)
{
	_nodelist = nodeList;
}

StringEnumListConfigNode& StringEnumListConfigNode::operator=(const StringEnumListConfigNode & other)
{
	this->_nodeShowName = other._nodeShowName;
	this->_isHot = other._isHot;
	this->_isShow = other._isShow;
	this->_nodelist = other._nodelist;
	return *this;
}
