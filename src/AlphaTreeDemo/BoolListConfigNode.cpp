#include "BoolListConfigNode.h"

BoolListConfigNode::BoolListConfigNode(QObject *parent)
	: QObject(parent)
{
}

BoolListConfigNode::~BoolListConfigNode()
{
	qDebug() << "~BoolListConfigNode " << this;
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
