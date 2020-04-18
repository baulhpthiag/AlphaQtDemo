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

void BoolListConfigNode::setNodeList(const QList<BoolConfigNode>& nodeList)
{
	_nodelist = nodeList;
}
