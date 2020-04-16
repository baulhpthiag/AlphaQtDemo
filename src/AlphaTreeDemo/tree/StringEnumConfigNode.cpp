#include "StringEnumConfigNode.h"

StringEnumConfigNode::StringEnumConfigNode(QObject *parent)
	: QObject(parent)
{
	this->_nodeShowName = "unNameStringEnumConfigNode";
	this->_enumIndex = 0;
	this->_valueEnum.clear();
	this->_valueEnum.append("null value");
	this->_isHot = true;
	this->_isShow = true;
}

StringEnumConfigNode::~StringEnumConfigNode()
{
}

void StringEnumConfigNode::nodeValueIndexChanged(int index)
{
	_enumIndex = index;
}
