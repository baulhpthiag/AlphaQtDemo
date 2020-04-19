#pragma once

#include <QObject>
#include <QDebug>
#include "BoolConfigNode.h"
#include "DoubleConfigNode.h"
#include "DoubleEnumConfigNode.h"
#include "IntConfigNode.h"
#include "IntEnumConfigNode.h"
#include "StringConfigNode.h"
#include "StringEnumConfigNode.h"

#include "BoolListConfigNode.h"
#include "IntListConfigNode.h"
#include "IntEnumListConfigNode.h"
#include "DoubleListConfigNode.h"
#include "DoubleEnumListConfigNode.h"
#include "StringListConfigNode.h"
#include "StringEnumListConfigNode.h"

class TestConfig : public QObject
{
	Q_OBJECT
		Q_PROPERTY(BoolConfigNode testBoolConfigNode READ getTestBoolConfigNode WRITE setTestBoolConfigNode)
		Q_PROPERTY(IntConfigNode testIntConfigNode READ getTestIntConfigNode WRITE setTestIntConfigNode)
		Q_PROPERTY(IntEnumConfigNode testIntEnumConfigNode READ getTestIntEnumConfigNode WRITE setTestIntEnumConfigNode)
		Q_PROPERTY(DoubleConfigNode testDoubleConfigNode READ getTestDoubleConfigNode WRITE setTestDoubleConfigNode)
		Q_PROPERTY(DoubleEnumConfigNode testDoubleEnumConfigNode READ getTestDoubleEnumConfigNode WRITE setTestDoubleEnumConfigNode)
		Q_PROPERTY(StringConfigNode testStringConfigNode READ getTestStringConfigNode WRITE setTestStringConfigNode)
		Q_PROPERTY(StringEnumConfigNode testStringEnumConfigNode READ getTestStringEnumConfigNode WRITE setTestStringEnumConfigNode)

		Q_PROPERTY(BoolListConfigNode testBoolListConfigNode READ getTestBoolListConfigNode WRITE setTestBoolListConfigNode)
		Q_PROPERTY(IntListConfigNode testIntListConfigNode READ getTestIntListConfigNode WRITE setTestIntListConfigNode)
		Q_PROPERTY(IntEnumListConfigNode testIntEnumListConfigNode READ getTestIntEnumListConfigNode WRITE setTestIntEnumListConfigNode)
		Q_PROPERTY(DoubleListConfigNode testDoubleListConfigNode READ getTestDoubleListConfigNode WRITE setTestDoubleListConfigNode)
		Q_PROPERTY(DoubleEnumListConfigNode testDoubleEnumListConfigNode READ getTestDoubleEnumListConfigNode WRITE setTestDoubleEnumListConfigNode)
		Q_PROPERTY(StringListConfigNode testStringListConfigNode READ getTestStringListConfigNode WRITE setTestStringListConfigNode)
		Q_PROPERTY(StringEnumListConfigNode testStringEnumListConfigNode READ getTestStringEnumListConfigNode WRITE setTestStringEnumListConfigNode)
public:
	TestConfig(QObject *parent = nullptr);
	~TestConfig();

	BoolConfigNode _testBoolConfigNode;
	IntConfigNode _testIntConfigNode;
	IntEnumConfigNode _testIntEnumConfigNode;
	DoubleConfigNode _testDoubleConfigNode;
	DoubleEnumConfigNode _testDoubleEnumConfigNode;
	StringConfigNode _testStringConfigNode;
	StringEnumConfigNode _testStringEnumConfigNode;

	BoolListConfigNode _testBoolListConfigNode;
	IntListConfigNode _testIntListConfigNode;
	IntEnumListConfigNode _testIntEnumListConfigNode;
	DoubleListConfigNode _testDoubleListConfigNode;
	DoubleEnumListConfigNode _testDoubleEnumListConfigNode;
	StringListConfigNode _testStringListConfigNode;
	StringEnumListConfigNode _testStringEnumListConfigNode;

	BoolConfigNode& getTestBoolConfigNode();
	IntConfigNode& getTestIntConfigNode();
	IntEnumConfigNode& getTestIntEnumConfigNode();
	DoubleConfigNode& getTestDoubleConfigNode();
	DoubleEnumConfigNode& getTestDoubleEnumConfigNode();
	StringConfigNode& getTestStringConfigNode();
	StringEnumConfigNode& getTestStringEnumConfigNode();

	BoolListConfigNode& getTestBoolListConfigNode();
	IntListConfigNode& getTestIntListConfigNode();
	IntEnumListConfigNode& getTestIntEnumListConfigNode();
	DoubleListConfigNode& getTestDoubleListConfigNode();
	DoubleEnumListConfigNode& getTestDoubleEnumListConfigNode();
	StringListConfigNode& getTestStringListConfigNode();
	StringEnumListConfigNode& getTestStringEnumListConfigNode();

	friend  QDebug operator << (QDebug debug, const TestConfig &config)
	{

		debug << "_testBoolConfigNode:"<< config._testBoolConfigNode;
		return debug;
	}

	Q_INVOKABLE BoolConfigNode* getTestBoolConfigNodeP();
	Q_INVOKABLE IntConfigNode* getTestIntConfigNodeP();
	Q_INVOKABLE IntEnumConfigNode* getTestIntEnumConfigNodeP();
	Q_INVOKABLE DoubleConfigNode* getTestDoubleConfigNodeP();
	Q_INVOKABLE DoubleEnumConfigNode* getTestDoubleEnumConfigNodeP();
	Q_INVOKABLE StringConfigNode* getTestStringConfigNodeP();
	Q_INVOKABLE StringEnumConfigNode* getTestStringEnumConfigNodeP();

	Q_INVOKABLE BoolListConfigNode* getTestBoolListConfigNodeP();
	Q_INVOKABLE IntListConfigNode* getTestIntListConfigNodeP();
	Q_INVOKABLE IntEnumListConfigNode* getTestIntEnumListConfigNodeP();
	Q_INVOKABLE DoubleListConfigNode* getTestDoubleListConfigNodeP();
	Q_INVOKABLE DoubleEnumListConfigNode* getTestDoubleEnumListConfigNodeP();
	Q_INVOKABLE StringListConfigNode* getTestStringListConfigNodeP();
	Q_INVOKABLE StringEnumListConfigNode* getTestStringEnumListConfigNodeP();


	public slots:
	void setTestBoolConfigNode(BoolConfigNode& value);
	void setTestIntConfigNode(IntConfigNode& value);
	void setTestIntEnumConfigNode(IntEnumConfigNode& value);
	void setTestDoubleConfigNode(DoubleConfigNode& value);
	void setTestDoubleEnumConfigNode(DoubleEnumConfigNode& value);
	void setTestStringConfigNode(StringConfigNode& value);
	void setTestStringEnumConfigNode(StringEnumConfigNode& value);

	void setTestBoolListConfigNode(BoolListConfigNode& value);
	void setTestIntListConfigNode(IntListConfigNode& value);
	void setTestIntEnumListConfigNode(IntEnumListConfigNode& value);
	void setTestDoubleListConfigNode(DoubleListConfigNode& value);
	void setTestDoubleEnumListConfigNode(DoubleEnumListConfigNode& value);
	void setTestStringListConfigNode(StringListConfigNode& value);
	void setTestStringEnumListConfigNode(StringEnumListConfigNode& value);

};
