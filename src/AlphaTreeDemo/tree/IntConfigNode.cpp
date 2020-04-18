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

IntConfigNode::~IntConfigNode()
{

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
