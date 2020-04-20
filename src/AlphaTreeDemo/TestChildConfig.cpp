#include "TestChildConfig.h"

TestChildConfig::TestChildConfig(QObject *parent)
	: QObject(parent)
{
}

TestChildConfig::TestChildConfig(const TestChildConfig& other, QObject * parent /*= nullptr*/)
{

	 _nodeShowName = other._nodeShowName;
	 _isHot = other._isHot;
	 _isShow = other._isShow;
	 _testBoolConfigNode = other._testBoolConfigNode;
	 _testIntConfigNode = other._testIntConfigNode;
	 _testIntEnumConfigNode = other._testIntEnumConfigNode;
	 _testDoubleConfigNode = other._testDoubleConfigNode;
	 _testDoubleEnumConfigNode = other._testDoubleEnumConfigNode;
	 _testStringConfigNode = other._testStringConfigNode;
	 _testStringEnumConfigNode = other._testStringEnumConfigNode;
	 _testBoolListConfigNode = other._testBoolListConfigNode;
}

TestChildConfig::~TestChildConfig()
{
}

TestChildConfig& TestChildConfig::operator=(const TestChildConfig& other)
{
	_nodeShowName = other._nodeShowName;
	_isHot = other._isHot;
	_isShow = other._isShow;
	_testBoolConfigNode = other._testBoolConfigNode;
	_testIntConfigNode = other._testIntConfigNode;
	_testIntEnumConfigNode = other._testIntEnumConfigNode;
	_testDoubleConfigNode = other._testDoubleConfigNode;
	_testDoubleEnumConfigNode = other._testDoubleEnumConfigNode;
	_testStringConfigNode = other._testStringConfigNode;
	_testStringEnumConfigNode = other._testStringEnumConfigNode;
	_testBoolListConfigNode = other._testBoolListConfigNode;

	return *this;
}

BoolConfigNode& TestChildConfig::getTestBoolConfigNode()
{
	return _testBoolConfigNode;
}

IntConfigNode& TestChildConfig::getTestIntConfigNode()
{
	return _testIntConfigNode;
}

IntEnumConfigNode& TestChildConfig::getTestIntEnumConfigNode()
{
	return _testIntEnumConfigNode;
}

DoubleConfigNode& TestChildConfig::getTestDoubleConfigNode()
{
	return _testDoubleConfigNode;
}

DoubleEnumConfigNode& TestChildConfig::getTestDoubleEnumConfigNode()
{
	return _testDoubleEnumConfigNode;
}

StringConfigNode& TestChildConfig::getTestStringConfigNode()
{
	return _testStringConfigNode;
}

StringEnumConfigNode& TestChildConfig::getTestStringEnumConfigNode()
{
	return _testStringEnumConfigNode;
}

BoolListConfigNode& TestChildConfig::getTestBoolListConfigNode()
{
	return _testBoolListConfigNode;
}

Q_INVOKABLE BoolConfigNode* TestChildConfig::getTestBoolConfigNodeP()
{
	return &_testBoolConfigNode;
}

Q_INVOKABLE IntConfigNode* TestChildConfig::getTestIntConfigNodeP()
{
	return &_testIntConfigNode;
}

Q_INVOKABLE IntEnumConfigNode* TestChildConfig::getTestIntEnumConfigNodeP()
{
	return &_testIntEnumConfigNode;
}

Q_INVOKABLE DoubleConfigNode* TestChildConfig::getTestDoubleConfigNodeP()
{
	return &_testDoubleConfigNode;
}

Q_INVOKABLE DoubleEnumConfigNode* TestChildConfig::getTestDoubleEnumConfigNodeP()
{
	return &_testDoubleEnumConfigNode;
}

Q_INVOKABLE StringConfigNode* TestChildConfig::getTestStringConfigNodeP()
{
	return &_testStringConfigNode;
}

Q_INVOKABLE StringEnumConfigNode* TestChildConfig::getTestStringEnumConfigNodeP()
{
	return &_testStringEnumConfigNode;
}

Q_INVOKABLE BoolListConfigNode* TestChildConfig::getTestBoolListConfigNodeP()
{
	return &_testBoolListConfigNode;
}

void TestChildConfig::setTestBoolConfigNode(BoolConfigNode& value)
{
	_testBoolConfigNode = value;
}

void TestChildConfig::setTestIntConfigNode(IntConfigNode& value)
{
	_testIntConfigNode = value;
}

void TestChildConfig::setTestIntEnumConfigNode(IntEnumConfigNode& value)
{
	_testIntEnumConfigNode = value;
}

void TestChildConfig::setTestDoubleConfigNode(DoubleConfigNode& value)
{
	_testDoubleConfigNode = value;
}

void TestChildConfig::setTestDoubleEnumConfigNode(DoubleEnumConfigNode& value)
{
	_testDoubleEnumConfigNode = value;
}

void TestChildConfig::setTestStringConfigNode(StringConfigNode& value)
{
	_testStringConfigNode = value;
}

void TestChildConfig::setTestStringEnumConfigNode(StringEnumConfigNode& value)
{
	_testStringEnumConfigNode = value;
}

void TestChildConfig::setTestBoolListConfigNode(BoolListConfigNode& value)
{
	_testBoolListConfigNode = value;
}
