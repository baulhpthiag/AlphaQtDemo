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

StringEnumConfigNode::StringEnumConfigNode(const StringEnumConfigNode& other, QObject* parent /*= nullptr*/)
{
	this->_nodeShowName = other._nodeShowName;
	this->_enumIndex = other._enumIndex;
	this->_valueEnum = other._valueEnum;
	this->_isHot = other._isHot;
	this->_isShow = other._isShow;
}

StringEnumConfigNode& StringEnumConfigNode::operator=(const StringEnumConfigNode& other)
{
	this->_nodeShowName = other._nodeShowName;
	this->_enumIndex = other._enumIndex;
	this->_valueEnum = other._valueEnum;
	this->_isHot = other._isHot;
	this->_isShow = other._isShow;
	return *this;
}

StringEnumConfigNode::~StringEnumConfigNode()
{
}

void StringEnumConfigNode::nodeValueIndexChanged(int index)
{
	_enumIndex = index;
}
