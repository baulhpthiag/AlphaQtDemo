#include "BoolConfigNode.h"

BoolConfigNode::BoolConfigNode(QObject *parent)
	: QObject(parent)
{
	this->_nodeShowName = "unNameBoolConfigNode";
	this->_nodeValue = false;
	this->_isHot = true;
	this->_isShow = true;
}

BoolConfigNode::~BoolConfigNode()
{

}

void BoolConfigNode::nodeValueChanged(int index)
{
	if (0 == index)
	{
		this->_nodeValue = false;
	}
	else
	{
		this->_nodeValue = true;
	}
}
