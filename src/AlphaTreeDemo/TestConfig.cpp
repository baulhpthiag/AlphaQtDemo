#include "TestConfig.h"

TestConfig::TestConfig(QObject *parent)
	: QObject(parent)
{

}

TestConfig::~TestConfig()
{

}

Q_INVOKABLE BoolConfigNode& TestConfig::getTestBoolConfigNode()
{
	return _testBoolConfigNode;
}

Q_INVOKABLE void TestConfig::setTestBoolConfigNode(BoolConfigNode& value)
{
	_testBoolConfigNode = value;
}

Q_INVOKABLE DoubleConfigNode& TestConfig::getTestDoubleConfigNode()
{
	return _testDoubleConfigNode;
}

Q_INVOKABLE void TestConfig::setTestDoubleConfigNode(DoubleConfigNode& value)
{
	_testDoubleConfigNode = value;
}

Q_INVOKABLE DoubleEnumConfigNode& TestConfig::getTestDoubleEnumConfigNode()
{
	return _testDoubleEnumConfigNode;
}

Q_INVOKABLE void TestConfig::setTestDoubleEnumConfigNode(DoubleEnumConfigNode& value)
{
	_testDoubleEnumConfigNode = value;
}

Q_INVOKABLE IntConfigNode& TestConfig::getTestIntConfigNode()
{
	return _testIntConfigNode;
}

Q_INVOKABLE void TestConfig::setTestIntConfigNode(IntConfigNode& value)
{
	_testIntConfigNode = value;
}

Q_INVOKABLE IntEnumConfigNode& TestConfig::getTestIntEnumConfigNode()
{
	return _testIntEnumConfigNode;
}

Q_INVOKABLE void TestConfig::setTestIntEnumConfigNode(IntEnumConfigNode& value)
{
	_testIntEnumConfigNode = value;
}

Q_INVOKABLE StringConfigNode& TestConfig::getTestStringConfigNode()
{
	return _testStringConfigNode;
}

Q_INVOKABLE void TestConfig::setTestStringConfigNode(StringConfigNode& value)
{
	_testStringConfigNode = value;
}

Q_INVOKABLE StringEnumConfigNode& TestConfig::getTestStringEnumConfigNode()
{
	return _testStringEnumConfigNode;
}

Q_INVOKABLE void TestConfig::setTestStringEnumConfigNode(StringEnumConfigNode& value)
{
	_testStringEnumConfigNode = value;
}

Q_INVOKABLE QList<BoolConfigNode>& TestConfig::getTestBoolConfigNodeList()
{
	return _testBoolConfigNodeList;
}

Q_INVOKABLE void TestConfig::setTestBoolConfigNodeList(QList<BoolConfigNode>& value)
{
	_testBoolConfigNodeList = value;
}

Q_INVOKABLE QList<DoubleConfigNode>& TestConfig::getTestDoubleConfigNodeList()
{
	return _testDoubleConfigNodeList;
}

Q_INVOKABLE void TestConfig::setTestDoubleConfigNodeList(QList<DoubleConfigNode>& value)
{
	_testDoubleConfigNodeList = value;
}

Q_INVOKABLE QList<DoubleEnumConfigNode>& TestConfig::getTestDoubleEnumConfigNodeList()
{
	return _testDoubleEnumConfigNodeList;
}

Q_INVOKABLE void TestConfig::setTestDoubleEnumConfigNodeList(QList<DoubleEnumConfigNode>& value)
{
	_testDoubleEnumConfigNodeList = value;
}

Q_INVOKABLE QList<IntConfigNode>& TestConfig::getTestIntConfigNodeList()
{
	return _testIntConfigNodeList;
}

Q_INVOKABLE void TestConfig::setTestIntConfigNodeList(QList<IntConfigNode>& value)
{
	_testIntConfigNodeList = value;
}

Q_INVOKABLE QList<IntEnumConfigNode>& TestConfig::getTestIntEnumConfigNodeList()
{
	return _testIntEnumConfigNodeList;
}

Q_INVOKABLE void TestConfig::setTestIntEnumConfigNodeList(QList<IntEnumConfigNode>& value)
{
	_testIntEnumConfigNodeList = value;
}

Q_INVOKABLE QList<StringConfigNode>& TestConfig::getTestStringConfigNodeList()
{
	return _testStringConfigNodeList;
}

Q_INVOKABLE void TestConfig::setTestStringConfigNodeList(QList<StringConfigNode>& value)
{
	_testStringConfigNodeList = value;
}

Q_INVOKABLE QList<StringEnumConfigNode>& TestConfig::getTestStringEnumConfigNodeList()
{
	return _testStringEnumConfigNodeList;
}

Q_INVOKABLE void TestConfig::setTestStringEnumConfigNodeList(QList<StringEnumConfigNode>& value)
{
	_testStringEnumConfigNodeList = value;
}

