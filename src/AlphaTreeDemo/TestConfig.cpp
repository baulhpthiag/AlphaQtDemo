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

BoolListConfigNode& TestConfig::getTestBoolListConfigNode()
{
	return _testBoolListConfigNode;
}

void TestConfig::setTestBoolListConfigNode(BoolListConfigNode& value)
{
	_testBoolListConfigNode = value;
}

DoubleListConfigNode& TestConfig::getTestDoubleListConfigNode()
{
	return _testDoubleListConfigNode;
}

void TestConfig::setTestDoubleListConfigNode(DoubleListConfigNode& value)
{
	_testDoubleListConfigNode = value;
}

DoubleEnumListConfigNode& TestConfig::getTestDoubleEnumListConfigNode()
{
	return _testDoubleEnumListConfigNode;
}

void TestConfig::setTestDoubleEnumListConfigNode(DoubleEnumListConfigNode& value)
{
	_testDoubleEnumListConfigNode = value;
}

IntListConfigNode& TestConfig::getTestIntListConfigNode()
{
	return _testIntListConfigNode;
}

void TestConfig::setTestIntListConfigNode(IntListConfigNode& value)
{
	_testIntListConfigNode = value;
}

IntEnumListConfigNode& TestConfig::getTestIntEnumListConfigNode()
{
	return _testIntEnumListConfigNode;
}

void TestConfig::setTestIntEnumListConfigNode(IntEnumListConfigNode& value)
{
	_testIntEnumListConfigNode = value;
}

StringListConfigNode& TestConfig::getTestStringListConfigNode()
{
	return _testStringListConfigNode;
}

void TestConfig::setTestStringListConfigNode(StringListConfigNode& value)
{
	_testStringListConfigNode = value;
}

StringEnumListConfigNode& TestConfig::getTestStringEnumListConfigNode()
{
	return _testStringEnumListConfigNode;
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

Q_INVOKABLE BoolListConfigNode* TestConfig::getTestBoolListConfigNodeP()
{
	return &_testBoolListConfigNode;
}

Q_INVOKABLE DoubleListConfigNode* TestConfig::getTestDoubleListConfigNodeP()
{
	return &_testDoubleListConfigNode;
}

Q_INVOKABLE DoubleEnumListConfigNode* TestConfig::getTestDoubleEnumListConfigNodeP()
{
	return &_testDoubleEnumListConfigNode;
}

Q_INVOKABLE IntListConfigNode* TestConfig::getTestIntListConfigNodeP()
{
	return &_testIntListConfigNode;
}

Q_INVOKABLE IntEnumListConfigNode* TestConfig::getTestIntEnumListConfigNodeP()
{
	return &_testIntEnumListConfigNode;
}

Q_INVOKABLE StringListConfigNode* TestConfig::getTestStringListConfigNodeP()
{
	return &_testStringListConfigNode;
}

Q_INVOKABLE StringEnumListConfigNode* TestConfig::getTestStringEnumListConfigNodeP()
{
	return &_testStringEnumListConfigNode;
}

//QDebug TestConfig::operator<<(QDebug debug, const TestConfig & config)
//{
//
//
//}

void TestConfig::setTestStringEnumListConfigNode(StringEnumListConfigNode& value)
{
	_testStringEnumListConfigNode = value;
}

