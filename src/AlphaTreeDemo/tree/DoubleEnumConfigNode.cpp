#include "DoubleEnumConfigNode.h"

DoubleEnumConfigNode::DoubleEnumConfigNode(QObject *parent)
	: QObject(parent)
{
	this->_nodeShowName = "unNameDoubleEnumConfigNode";
	this->_enumIndex = 0;
	this->_valueEnum.clear();
	this->_valueEnum.append(0.0);
	this->_isHot = true;
	this->_isShow = true;
}

DoubleEnumConfigNode::~DoubleEnumConfigNode()
{

}

void DoubleEnumConfigNode::nodeValueIndexChanged(int index)
{
	_enumIndex = index;
}

