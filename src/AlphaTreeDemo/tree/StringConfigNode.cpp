#include "StringConfigNode.h"

StringConfigNode::StringConfigNode(QObject *parent)
	: QObject(parent)
{
	this->_nodeShowName = "unNameStringConfigNode";
	this->_nodeValue = "null value";
	this->_isHot = true;
	this->_isShow = true;
}

StringConfigNode::StringConfigNode(const StringConfigNode& other, QObject* parent /*= nullptr*/)
{
	this->_nodeShowName = other._nodeShowName;
	this->_nodeValue = other._nodeValue;
	this->_isHot = other._isHot;
	this->_isShow = other._isShow;
}

StringConfigNode& StringConfigNode::operator=(const StringConfigNode & other)
{
	this->_nodeShowName = other._nodeShowName;
	this->_nodeValue = other._nodeValue;
	this->_isHot = other._isHot;
	this->_isShow = other._isShow;
	return *this;
}

StringConfigNode::~StringConfigNode()
{
}

void StringConfigNode::nodeValueChanged(QString value)
{
	_nodeValue = value;
}
