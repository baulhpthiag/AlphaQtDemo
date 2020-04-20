#include "StringListConfigNode.h"

StringListConfigNode::StringListConfigNode(QObject *parent)
	: QObject(parent)
{
}

StringListConfigNode::StringListConfigNode(const StringListConfigNode& other, QObject* parent/*= nullptr*/)
{
	this->_nodeShowName = other._nodeShowName;
	this->_isHot = other._isHot;
	this->_isShow = other._isShow;
	this->_nodelist = other._nodelist;
}

StringListConfigNode::~StringListConfigNode()
{
}

QList<StringConfigNode>& StringListConfigNode::getNodeList()
{
	return _nodelist;
}

QList<StringConfigNode*> StringListConfigNode::getNodeListP()
{
	QList<StringConfigNode*> list;
	for (int i = 0; i < _nodelist.count(); i++)
	{
		list.append(&_nodelist[i]);
	}
	return list;
}

void StringListConfigNode::setNodeList(const QList<StringConfigNode>& nodeList)
{
	_nodelist = nodeList;
}

StringListConfigNode& StringListConfigNode::operator=(const StringListConfigNode& other)
{
	this->_nodeShowName = other._nodeShowName;
	this->_isHot = other._isHot;
	this->_isShow = other._isShow;
	this->_nodelist = other._nodelist;
	return *this;
}
