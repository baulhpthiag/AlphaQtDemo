#include "IntEnumConfigNode.h"

IntEnumConfigNode::IntEnumConfigNode(QObject *parent)
	: QObject(parent)
{
	this->_nodeShowName = "unNameIntEnumConfigNode";
	this->_enumIndex = 0;
	this->_valueEnum.clear();
	this->_valueEnum.append(0);
	this->_isHot = true;
	this->_isShow = true;
}

IntEnumConfigNode::~IntEnumConfigNode()
{
}

void IntEnumConfigNode::nodeValueIndexChanged(int index)
{
	_enumIndex = index;
}
