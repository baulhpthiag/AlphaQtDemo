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

DoubleConfigNode::~DoubleConfigNode()
{
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
