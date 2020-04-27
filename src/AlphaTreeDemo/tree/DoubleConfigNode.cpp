#include "DoubleConfigNode.h"

DoubleConfigNode::DoubleConfigNode(QObject *parent)
	: QObject(parent)
{
	this->_nodeShowName = "unNameDoubleConfigNode";
	this->_nodeValue = 0.0;
	this->_maxValue = 1.0;
	this->_minValue = 0.0;
	this->_isHot = true;
	this->_isShow = true;
}

DoubleConfigNode::DoubleConfigNode(const DoubleConfigNode& other, QObject* parent /*= nullptr*/)
{
	this->_nodeShowName = other._nodeShowName;
	this->_nodeValue = other._nodeValue;
	this->_maxValue = other._maxValue;
	this->_minValue = other._minValue;
	this->_isHot = other._isHot;
	this->_isShow = other._isShow;
}

DoubleConfigNode::~DoubleConfigNode()
{
}

DoubleConfigNode& DoubleConfigNode::operator=(const DoubleConfigNode & other)
{
	this->_nodeShowName = other._nodeShowName;
	this->_nodeValue = other._nodeValue;
	this->_maxValue = other._maxValue;
	this->_minValue = other._minValue;
	this->_isHot = other._isHot;
	this->_isShow = other._isShow;
	return *this;
}

void DoubleConfigNode::nodeValueChanged(QString strValue)
{
	double value = strValue.toDouble();
	if (value>_maxValue || value<_minValue)
	{
		return;
	}
	_nodeValue = value;
}
