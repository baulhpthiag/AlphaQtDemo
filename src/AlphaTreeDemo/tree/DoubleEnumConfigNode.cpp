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

DoubleEnumConfigNode::DoubleEnumConfigNode(const DoubleEnumConfigNode& other, QObject * parent /*= nullptr*/)
{
	this->_nodeShowName = other._nodeShowName;
	this->_enumIndex = other._enumIndex;
	this->_valueEnum = other._valueEnum;
	this->_isHot = other._isHot;
	this->_isShow = other._isShow;
}

DoubleEnumConfigNode::~DoubleEnumConfigNode()
{

}

DoubleEnumConfigNode& DoubleEnumConfigNode::operator=(const DoubleEnumConfigNode& other)
{
	this->_nodeShowName = other._nodeShowName;
	this->_enumIndex = other._enumIndex;
	this->_valueEnum = other._valueEnum;
	this->_isHot = other._isHot;
	this->_isShow = other._isShow;
	return *this;
}

void DoubleEnumConfigNode::nodeValueIndexChanged(int index)
{
	_enumIndex = index;
}

