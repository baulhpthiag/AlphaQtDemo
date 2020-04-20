#include "TestParentConfig.h"

TestParentConfig::TestParentConfig(QObject *parent)
	: QObject(parent)
{

}

TestParentConfig::TestParentConfig(const TestParentConfig & other, QObject*parent /*= nullptr*/)
{
	 _testBoolConfigNode = other._testBoolConfigNode;
	 _testIntConfigNode = other._testIntConfigNode;
	 _testIntEnumConfigNode = other._testIntEnumConfigNode;
	 _testDoubleConfigNode = other._testDoubleConfigNode;
	 _testDoubleEnumConfigNode = other._testDoubleEnumConfigNode;
	 _testStringConfigNode = other._testStringConfigNode;
	 _testStringEnumConfigNode = other._testStringEnumConfigNode;

	 _testBoolListConfigNode = other._testBoolListConfigNode;
	 _testIntListConfigNode = other._testIntListConfigNode;
	 _testIntEnumListConfigNode = other._testIntEnumListConfigNode;
	 _testDoubleListConfigNode = other._testDoubleListConfigNode;
	 _testDoubleEnumListConfigNode = other._testDoubleEnumListConfigNode;
	 _testStringListConfigNode = other._testStringListConfigNode;
	 _testStringEnumListConfigNode = other._testStringEnumListConfigNode;

	 _testChildConfig = other._testChildConfig;
}

TestParentConfig::~TestParentConfig()
{

}

BoolConfigNode& TestParentConfig::getTestBoolConfigNode()
{
	return _testBoolConfigNode;
}

void TestParentConfig::setTestBoolConfigNode(BoolConfigNode& value)
{
	_testBoolConfigNode = value;
}

DoubleConfigNode& TestParentConfig::getTestDoubleConfigNode()
{
	return _testDoubleConfigNode;
}

void TestParentConfig::setTestDoubleConfigNode(DoubleConfigNode& value)
{
	_testDoubleConfigNode = value;
}

DoubleEnumConfigNode& TestParentConfig::getTestDoubleEnumConfigNode()
{
	return _testDoubleEnumConfigNode;
}

void TestParentConfig::setTestDoubleEnumConfigNode(DoubleEnumConfigNode& value)
{
	_testDoubleEnumConfigNode = value;
}

IntConfigNode& TestParentConfig::getTestIntConfigNode()
{
	return _testIntConfigNode;
}

void TestParentConfig::setTestIntConfigNode(IntConfigNode& value)
{
	_testIntConfigNode = value;
}

IntEnumConfigNode& TestParentConfig::getTestIntEnumConfigNode()
{
	return _testIntEnumConfigNode;
}

void TestParentConfig::setTestIntEnumConfigNode(IntEnumConfigNode& value)
{
	_testIntEnumConfigNode = value;
}

StringConfigNode& TestParentConfig::getTestStringConfigNode()
{
	return _testStringConfigNode;
}

void TestParentConfig::setTestStringConfigNode(StringConfigNode& value)
{
	_testStringConfigNode = value;
}

StringEnumConfigNode& TestParentConfig::getTestStringEnumConfigNode()
{
	return _testStringEnumConfigNode;
}

void TestParentConfig::setTestStringEnumConfigNode(StringEnumConfigNode& value)
{
	_testStringEnumConfigNode = value;
}

BoolListConfigNode& TestParentConfig::getTestBoolListConfigNode()
{
	return _testBoolListConfigNode;
}

void TestParentConfig::setTestBoolListConfigNode(BoolListConfigNode& value)
{
	_testBoolListConfigNode = value;
}

DoubleListConfigNode& TestParentConfig::getTestDoubleListConfigNode()
{
	return _testDoubleListConfigNode;
}

void TestParentConfig::setTestDoubleListConfigNode(DoubleListConfigNode& value)
{
	_testDoubleListConfigNode = value;
}

DoubleEnumListConfigNode& TestParentConfig::getTestDoubleEnumListConfigNode()
{
	return _testDoubleEnumListConfigNode;
}

void TestParentConfig::setTestDoubleEnumListConfigNode(DoubleEnumListConfigNode& value)
{
	_testDoubleEnumListConfigNode = value;
}

IntListConfigNode& TestParentConfig::getTestIntListConfigNode()
{
	return _testIntListConfigNode;
}

void TestParentConfig::setTestIntListConfigNode(IntListConfigNode& value)
{
	_testIntListConfigNode = value;
}

IntEnumListConfigNode& TestParentConfig::getTestIntEnumListConfigNode()
{
	return _testIntEnumListConfigNode;
}

void TestParentConfig::setTestIntEnumListConfigNode(IntEnumListConfigNode& value)
{
	_testIntEnumListConfigNode = value;
}

StringListConfigNode& TestParentConfig::getTestStringListConfigNode()
{
	return _testStringListConfigNode;
}

void TestParentConfig::setTestStringListConfigNode(StringListConfigNode& value)
{
	_testStringListConfigNode = value;
}

StringEnumListConfigNode& TestParentConfig::getTestStringEnumListConfigNode()
{
	return _testStringEnumListConfigNode;
}

TestChildConfig& TestParentConfig::getTestChildConfig()
{
	return _testChildConfig;
}

Q_INVOKABLE BoolConfigNode* TestParentConfig::getTestBoolConfigNodeP()
{
	return &_testBoolConfigNode;
}

Q_INVOKABLE DoubleConfigNode* TestParentConfig::getTestDoubleConfigNodeP()
{
	return &_testDoubleConfigNode;
}

Q_INVOKABLE DoubleEnumConfigNode* TestParentConfig::getTestDoubleEnumConfigNodeP()
{
	return &_testDoubleEnumConfigNode;
}

Q_INVOKABLE IntConfigNode* TestParentConfig::getTestIntConfigNodeP()
{
	return &_testIntConfigNode;
}

Q_INVOKABLE IntEnumConfigNode* TestParentConfig::getTestIntEnumConfigNodeP()
{
	return &_testIntEnumConfigNode;
}

Q_INVOKABLE StringConfigNode* TestParentConfig::getTestStringConfigNodeP()
{
	return &_testStringConfigNode;
}

Q_INVOKABLE StringEnumConfigNode* TestParentConfig::getTestStringEnumConfigNodeP()
{
	return &_testStringEnumConfigNode;
}

Q_INVOKABLE BoolListConfigNode* TestParentConfig::getTestBoolListConfigNodeP()
{
	return &_testBoolListConfigNode;
}

Q_INVOKABLE DoubleListConfigNode* TestParentConfig::getTestDoubleListConfigNodeP()
{
	return &_testDoubleListConfigNode;
}

Q_INVOKABLE DoubleEnumListConfigNode* TestParentConfig::getTestDoubleEnumListConfigNodeP()
{
	return &_testDoubleEnumListConfigNode;
}

Q_INVOKABLE IntListConfigNode* TestParentConfig::getTestIntListConfigNodeP()
{
	return &_testIntListConfigNode;
}

Q_INVOKABLE IntEnumListConfigNode* TestParentConfig::getTestIntEnumListConfigNodeP()
{
	return &_testIntEnumListConfigNode;
}

Q_INVOKABLE StringListConfigNode* TestParentConfig::getTestStringListConfigNodeP()
{
	return &_testStringListConfigNode;
}

Q_INVOKABLE StringEnumListConfigNode* TestParentConfig::getTestStringEnumListConfigNodeP()
{
	return &_testStringEnumListConfigNode;
}

Q_INVOKABLE TestChildConfig* TestParentConfig::getTestChildConfigP()
{
	return &_testChildConfig;
}

//QDebug TestConfig::operator<<(QDebug debug, const TestConfig & config)
//{
//
//
//}

void TestParentConfig::setTestStringEnumListConfigNode(StringEnumListConfigNode& value)
{
	_testStringEnumListConfigNode = value;
}

void TestParentConfig::setTestChildConfig(TestChildConfig& value)
{
	_testChildConfig = value;
}

