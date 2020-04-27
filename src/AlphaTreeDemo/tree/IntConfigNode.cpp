#include "IntConfigNode.h"

IntConfigNode::IntConfigNode(QObject *parent)
	: QObject(parent)
{
	this->_nodeShowName = "unNameIntConfigNode";
	this->_nodeValue = 0;
	this->_maxValue = 1;
	this->_minValue = 0;
	this->_isHot = true;
	this->_isShow = true;
}

IntConfigNode::IntConfigNode(const IntConfigNode& other, QObject* parent /*= nullptr*/)
{
	this->_nodeShowName = other._nodeShowName;
	this->_nodeValue = other._nodeValue;
	this->_maxValue = other._maxValue;
	this->_minValue = other._minValue;
	this->_isHot = other._isHot;
	this->_isShow = other._isShow;
}

IntConfigNode::~IntConfigNode()
{

}

IntConfigNode& IntConfigNode::operator=(const IntConfigNode& other)
{
	this->_nodeShowName = other._nodeShowName;
	this->_nodeValue = other._nodeValue;
	this->_maxValue = other._maxValue;
	this->_minValue = other._minValue;
	this->_isHot = other._isHot;
	this->_isShow = other._isShow;
	return *this;
}

void IntConfigNode::nodeValueChanged(QString strvalue)
{
	int value = strvalue.toInt();
	if (value>_maxValue|| value<_minValue)
	{
		return;
	}
	_nodeValue = value;
}
