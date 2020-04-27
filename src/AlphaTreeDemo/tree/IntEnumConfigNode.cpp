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

IntEnumConfigNode::IntEnumConfigNode(const IntEnumConfigNode& other, QObject* parent /*= nullptr*/)
{
	this->_nodeShowName = other._nodeShowName;
	this->_enumIndex = other._enumIndex;
	this->_valueEnum = other._valueEnum;
	this->_isHot = other._isHot;
	this->_isShow = other._isShow;
}

IntEnumConfigNode::~IntEnumConfigNode()
{
}

IntEnumConfigNode& IntEnumConfigNode::operator=(const IntEnumConfigNode & other)
{
	this->_nodeShowName = other._nodeShowName;
	this->_enumIndex = other._enumIndex;
	this->_valueEnum = other._valueEnum;
	this->_isHot = other._isHot;
	this->_isShow = other._isShow;
	return *this;
}

void IntEnumConfigNode::nodeValueIndexChanged(int index)
{
	//¼ì²é
	_enumIndex = index;
}
