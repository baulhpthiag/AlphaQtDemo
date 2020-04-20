#include "DoubleEnumListConfigNode.h"

DoubleEnumListConfigNode::DoubleEnumListConfigNode(QObject *parent)
	: QObject(parent)
{
}

DoubleEnumListConfigNode::DoubleEnumListConfigNode(const DoubleEnumListConfigNode& other, QObject* parent /*= nullptr*/)
{
	this->_nodeShowName = other._nodeShowName;
	this->_isHot = other._isHot;
	this->_isShow = other._isShow;
	this->_nodelist = other._nodelist;
}

DoubleEnumListConfigNode::~DoubleEnumListConfigNode()
{
}

DoubleEnumListConfigNode& DoubleEnumListConfigNode::operator=(const DoubleEnumListConfigNode& other)
{
	this->_nodeShowName = other._nodeShowName;
	this->_isHot = other._isHot;
	this->_isShow = other._isShow;
	this->_nodelist = other._nodelist;
	return *this;
}

QList<DoubleEnumConfigNode>& DoubleEnumListConfigNode::getNodeList()
{
	return _nodelist;
}

QList<DoubleEnumConfigNode*> DoubleEnumListConfigNode::getNodeListP()
{
	QList<DoubleEnumConfigNode*> list;
	//for each (auto var in _nodelist)
	//{
	//	list.append(&var);
	//}

	for (int i=0;i<_nodelist.count();i++)
	{
		list.append(&_nodelist[i]);
	}

	return list;
}

void DoubleEnumListConfigNode::setNodeList(const QList<DoubleEnumConfigNode>& nodeList)
{
	_nodelist = nodeList;
}
