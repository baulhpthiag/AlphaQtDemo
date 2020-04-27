#include "BoolListConfigNode.h"

BoolListConfigNode::BoolListConfigNode(QObject *parent)
	: QObject(parent)
{
}

BoolListConfigNode::BoolListConfigNode(const BoolListConfigNode & other, QObject*parent /*= nullptr*/)
{
	this->_nodeShowName = other._nodeShowName;
	this->_isShow = other._isShow;
	this->_isHot = other._isHot;
	this->_nodelist = other._nodelist;
}

BoolListConfigNode::~BoolListConfigNode()
{
	qDebug() << "~BoolListConfigNode " << this;
}

BoolListConfigNode& BoolListConfigNode::operator=(const BoolListConfigNode& other)
{
	this->_nodeShowName = other._nodeShowName;
	this->_isShow = other._isShow;
	this->_isHot = other._isHot;
	this->_nodelist = other._nodelist;
	return *this;
}

QList<BoolConfigNode>& BoolListConfigNode::getNodeList()
{
	return _nodelist;
}

QList<BoolConfigNode*> BoolListConfigNode::getNodeListP()
{
	QList<BoolConfigNode*> list;

	////???
	//for each (auto  var in _nodelist)
	//{
	//	qDebug() << "_nodeList " << &var;
	//	list.append(&var);
	//}


	for (int i=0;i<_nodelist.count();i++)
	{
		list.append(&_nodelist[i]);
	}

	return list;
}

void BoolListConfigNode::setNodeList(const QList<BoolConfigNode>& nodeList)
{
	_nodelist = nodeList;
}
