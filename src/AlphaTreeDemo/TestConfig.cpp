#include "TestConfig.h"

TestConfig::TestConfig(QObject *parent)
	: QObject(parent)
{

}

TestConfig::~TestConfig()
{

}

BoolConfigNode& TestConfig::getTestBoolConfigNode()
{
	return _testBoolConfigNode;
}

void TestConfig::setTestBoolConfigNode(BoolConfigNode& value)
{
	_testBoolConfigNode = value;
}

DoubleConfigNode& TestConfig::getTestDoubleConfigNode()
{
	return _testDoubleConfigNode;
}

void TestConfig::setTestDoubleConfigNode(DoubleConfigNode& value)
{
	_testDoubleConfigNode = value;
}

DoubleEnumConfigNode& TestConfig::getTestDoubleEnumConfigNode()
{
	return _testDoubleEnumConfigNode;
}

void TestConfig::setTestDoubleEnumConfigNode(DoubleEnumConfigNode& value)
{
	_testDoubleEnumConfigNode = value;
}

IntConfigNode& TestConfig::getTestIntConfigNode()
{
	return _testIntConfigNode;
}

void TestConfig::setTestIntConfigNode(IntConfigNode& value)
{
	_testIntConfigNode = value;
}

IntEnumConfigNode& TestConfig::getTestIntEnumConfigNode()
{
	return _testIntEnumConfigNode;
}

void TestConfig::setTestIntEnumConfigNode(IntEnumConfigNode& value)
{
	_testIntEnumConfigNode = value;
}

StringConfigNode& TestConfig::getTestStringConfigNode()
{
	return _testStringConfigNode;
}

void TestConfig::setTestStringConfigNode(StringConfigNode& value)
{
	_testStringConfigNode = value;
}

StringEnumConfigNode& TestConfig::getTestStringEnumConfigNode()
{
	return _testStringEnumConfigNode;
}

void TestConfig::setTestStringEnumConfigNode(StringEnumConfigNode& value)
{
	_testStringEnumConfigNode = value;
}

QList<BoolConfigNode>& TestConfig::getTestBoolConfigNodeList()
{
	return _testBoolConfigNodeList;
}

void TestConfig::setTestBoolConfigNodeList(QList<BoolConfigNode>& value)
{
	_testBoolConfigNodeList = value;
}

QList<DoubleConfigNode>& TestConfig::getTestDoubleConfigNodeList()
{
	return _testDoubleConfigNodeList;
}

void TestConfig::setTestDoubleConfigNodeList(QList<DoubleConfigNode>& value)
{
	_testDoubleConfigNodeList = value;
}

QList<DoubleEnumConfigNode>& TestConfig::getTestDoubleEnumConfigNodeList()
{
	return _testDoubleEnumConfigNodeList;
}

void TestConfig::setTestDoubleEnumConfigNodeList(QList<DoubleEnumConfigNode>& value)
{
	_testDoubleEnumConfigNodeList = value;
}

QList<IntConfigNode>& TestConfig::getTestIntConfigNodeList()
{
	return _testIntConfigNodeList;
}

void TestConfig::setTestIntConfigNodeList(QList<IntConfigNode>& value)
{
	_testIntConfigNodeList = value;
}

QList<IntEnumConfigNode>& TestConfig::getTestIntEnumConfigNodeList()
{
	return _testIntEnumConfigNodeList;
}

void TestConfig::setTestIntEnumConfigNodeList(QList<IntEnumConfigNode>& value)
{
	_testIntEnumConfigNodeList = value;
}

QList<StringConfigNode>& TestConfig::getTestStringConfigNodeList()
{
	return _testStringConfigNodeList;
}

void TestConfig::setTestStringConfigNodeList(QList<StringConfigNode>& value)
{
	_testStringConfigNodeList = value;
}

QList<StringEnumConfigNode>& TestConfig::getTestStringEnumConfigNodeList()
{
	return _testStringEnumConfigNodeList;
}

Q_INVOKABLE BoolConfigNode* TestConfig::getTestBoolConfigNodeP()
{
	return &_testBoolConfigNode;
}

Q_INVOKABLE DoubleConfigNode* TestConfig::getTestDoubleConfigNodeP()
{
	return &_testDoubleConfigNode;
}

Q_INVOKABLE DoubleEnumConfigNode* TestConfig::getTestDoubleEnumConfigNodeP()
{
	return &_testDoubleEnumConfigNode;
}

Q_INVOKABLE IntConfigNode* TestConfig::getTestIntConfigNodeP()
{
	return &_testIntConfigNode;
}

Q_INVOKABLE IntEnumConfigNode* TestConfig::getTestIntEnumConfigNodeP()
{
	return &_testIntEnumConfigNode;
}

Q_INVOKABLE StringConfigNode* TestConfig::getTestStringConfigNodeP()
{
	return &_testStringConfigNode;
}

Q_INVOKABLE StringEnumConfigNode* TestConfig::getTestStringEnumConfigNodeP()
{
	return &_testStringEnumConfigNode;
}

Q_INVOKABLE QList<BoolConfigNode>* TestConfig::getTestBoolConfigNodeListP()
{
	return &_testBoolConfigNodeList;
}

Q_INVOKABLE QList<DoubleConfigNode>* TestConfig::getTestDoubleConfigNodeListP()
{
	return &_testDoubleConfigNodeList;
}

Q_INVOKABLE QList<DoubleEnumConfigNode>* TestConfig::getTestDoubleEnumConfigNodeListP()
{
	return &_testDoubleEnumConfigNodeList;
}

Q_INVOKABLE QList<IntConfigNode>* TestConfig::getTestIntConfigNodeListP()
{
	return &_testIntConfigNodeList;
}

Q_INVOKABLE QList<IntEnumConfigNode>* TestConfig::getTestIntEnumConfigNodeListP()
{
	return &_testIntEnumConfigNodeList;
}

Q_INVOKABLE QList<StringConfigNode>* TestConfig::getTestStringConfigNodeListP()
{
	return &_testStringConfigNodeList;
}

Q_INVOKABLE QList<StringEnumConfigNode>* TestConfig::getTestStringEnumConfigNodeListP()
{
	return &_testStringEnumConfigNodeList;
}

//QDebug TestConfig::operator<<(QDebug debug, const TestConfig & config)
//{
//
//
//}

void TestConfig::setTestStringEnumConfigNodeList(QList<StringEnumConfigNode>& value)
{
	_testStringEnumConfigNodeList = value;
}

