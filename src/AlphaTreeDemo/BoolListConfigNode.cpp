#include "BoolListConfigNode.h"

BoolListConfigNode::BoolListConfigNode(QObject *parent)
	: QObject(parent)
{
}

BoolListConfigNode::~BoolListConfigNode()
{
}

QList<BoolConfigNode>& BoolListConfigNode::getNodeList()
{
	return _nodelist;
}

QList<BoolConfigNode*> BoolListConfigNode::getNodeListP()
{
	QList<BoolConfigNode*> list;
	for each (auto var in _nodelist)
	{
		list.append(&var);
	} 
	return list;
}

void BoolListConfigNode::setNodeList(const QList<BoolConfigNode>& nodeList)
{
	_nodelist = nodeList;
}
