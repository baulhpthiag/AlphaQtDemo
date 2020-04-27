#include "BoolConfigNode.h"

BoolConfigNode::BoolConfigNode(QObject *parent)
	: QObject(parent)
{
	this->_nodeShowName = "unNameBoolConfigNode";
	this->_nodeValue = false;
	this->_isHot = true;
	this->_isShow = true;
}

BoolConfigNode::BoolConfigNode(const BoolConfigNode& other, QObject* parent /*= nullptr*/)
{
	this->_nodeShowName = other._nodeShowName;
	this->_nodeValue = other._nodeValue;
	this->_isHot = other._isHot;
	this->_isShow = other._isShow;
}

BoolConfigNode::~BoolConfigNode()
{

}

BoolConfigNode& BoolConfigNode::operator =(const BoolConfigNode& other)
{
	this->_nodeShowName = other._nodeShowName;
	this->_nodeValue = other._nodeValue;
	this->_isHot = other._isHot;
	this->_isShow = other._isShow;
	return *this;
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
