#include "StringConfigNode.h"

StringConfigNode::StringConfigNode(QObject *parent)
	: QObject(parent)
{
	this->_nodeShowName = "unNameStringConfigNode";
	this->_nodeValue = "null value";
	this->_isHot = true;
	this->_isShow = true;
}

StringConfigNode::~StringConfigNode()
{
}

void StringConfigNode::nodeValueChanged(QString value)
{
	_nodeValue = value;
}
