#pragma once

#include <QObject>
#include "BoolConfigNode.h"
#include "DoubleConfigNode.h"
#include "DoubleEnumConfigNode.h"
#include "IntConfigNode.h"
#include "IntEnumConfigNode.h"
#include "StringConfigNode.h"
#include "StringEnumConfigNode.h"

class TestConfig : public QObject
{
	Q_OBJECT
		Q_PROPERTY(BoolConfigNode& testBoolConfigNode READ getTestBoolConfigNode WRITE setTestBoolConfigNode)
		Q_PROPERTY(DoubleConfigNode& testDoubleConfigNode READ getTestDoubleConfigNode WRITE setTestDoubleConfigNode)
		Q_PROPERTY(DoubleEnumConfigNode& testDoubleEnumConfigNode READ getTestDoubleEnumConfigNode WRITE setTestDoubleEnumConfigNode)
		Q_PROPERTY(IntConfigNode& testIntConfigNode READ getTestIntConfigNode WRITE setTestIntConfigNode)
		Q_PROPERTY(IntEnumConfigNode& testIntEnumConfigNode READ getTestIntEnumConfigNode WRITE setTestIntEnumConfigNode)
		Q_PROPERTY(StringConfigNode& testStringConfigNode READ getTestStringConfigNode WRITE setTestStringConfigNode)
		Q_PROPERTY(StringEnumConfigNode& testStringEnumConfigNode READ getTestStringEnumConfigNode WRITE setTestStringEnumConfigNode)

		Q_PROPERTY(QList<BoolConfigNode>& testBoolConfigNodeList READ getTestBoolConfigNodeList WRITE setTestBoolConfigNodeList)
		Q_PROPERTY(QList<DoubleConfigNode>& testDoubleConfigNodeList READ getTestDoubleConfigNodeList WRITE setTestDoubleConfigNodeList)
		Q_PROPERTY(QList<DoubleEnumConfigNode>& testDoubleEnumConfigNodeList READ getTestDoubleEnumConfigNodeList WRITE setTestDoubleEnumConfigNodeList)
		Q_PROPERTY(QList<IntConfigNode>& testIntConfigNodeList READ getTestIntConfigNodeList WRITE setTestIntConfigNodeList)
		Q_PROPERTY(QList<IntEnumConfigNode>& testIntEnumConfigNodeList READ getTestIntEnumConfigNodeList WRITE setTestIntEnumConfigNodeList)
		Q_PROPERTY(QList<StringConfigNode>& testStringConfigNodeList READ getTestStringConfigNodeList WRITE setTestStringConfigNodeList)
		Q_PROPERTY(QList<StringEnumConfigNode>& testStringEnumConfigNodeList READ getTestStringEnumConfigNodeList WRITE setTestStringEnumConfigNodeList)
public:
	TestConfig(QObject *parent = nullptr);
	~TestConfig();

	BoolConfigNode _testBoolConfigNode;
	DoubleConfigNode _testDoubleConfigNode;
	DoubleEnumConfigNode _testDoubleEnumConfigNode;
	IntConfigNode _testIntConfigNode;
	IntEnumConfigNode _testIntEnumConfigNode;
	StringConfigNode _testStringConfigNode;
	StringEnumConfigNode _testStringEnumConfigNode;

	QList<BoolConfigNode> _testBoolConfigNodeList;
	QList<DoubleConfigNode> _testDoubleConfigNodeList;
	QList<DoubleEnumConfigNode> _testDoubleEnumConfigNodeList;
	QList<IntConfigNode> _testIntConfigNodeList;
	QList<IntEnumConfigNode> _testIntEnumConfigNodeList;
	QList<StringConfigNode> _testStringConfigNodeList;
	QList<StringEnumConfigNode> _testStringEnumConfigNodeList;

	Q_INVOKABLE BoolConfigNode& getTestBoolConfigNode();
	Q_INVOKABLE void setTestBoolConfigNode(BoolConfigNode& value);

	Q_INVOKABLE DoubleConfigNode& getTestDoubleConfigNode();
	Q_INVOKABLE void setTestDoubleConfigNode(DoubleConfigNode& value);

	Q_INVOKABLE DoubleEnumConfigNode& getTestDoubleEnumConfigNode();
	Q_INVOKABLE void setTestDoubleEnumConfigNode(DoubleEnumConfigNode& value);

	Q_INVOKABLE IntConfigNode& getTestIntConfigNode();
	Q_INVOKABLE void setTestIntConfigNode(IntConfigNode& value);

	Q_INVOKABLE IntEnumConfigNode& getTestIntEnumConfigNode();
	Q_INVOKABLE void setTestIntEnumConfigNode(IntEnumConfigNode& value);

	Q_INVOKABLE StringConfigNode& getTestStringConfigNode();
	Q_INVOKABLE void setTestStringConfigNode(StringConfigNode& value);

	Q_INVOKABLE StringEnumConfigNode& getTestStringEnumConfigNode();
	Q_INVOKABLE void setTestStringEnumConfigNode(StringEnumConfigNode& value);

	Q_INVOKABLE QList<BoolConfigNode>& getTestBoolConfigNodeList();
	Q_INVOKABLE void setTestBoolConfigNodeList(QList<BoolConfigNode>& value);

	Q_INVOKABLE QList<DoubleConfigNode>& getTestDoubleConfigNodeList();
	Q_INVOKABLE void setTestDoubleConfigNodeList(QList<DoubleConfigNode>& value);

	Q_INVOKABLE QList<DoubleEnumConfigNode>& getTestDoubleEnumConfigNodeList();
	Q_INVOKABLE void setTestDoubleEnumConfigNodeList(QList<DoubleEnumConfigNode>& value);

	Q_INVOKABLE QList<IntConfigNode>& getTestIntConfigNodeList();
	Q_INVOKABLE void setTestIntConfigNodeList(QList<IntConfigNode>& value);

	Q_INVOKABLE QList<IntEnumConfigNode>& getTestIntEnumConfigNodeList();
	Q_INVOKABLE void setTestIntEnumConfigNodeList(QList<IntEnumConfigNode>& value);

	Q_INVOKABLE QList<StringConfigNode>& getTestStringConfigNodeList();
	Q_INVOKABLE void setTestStringConfigNodeList(QList<StringConfigNode>& value);

	Q_INVOKABLE QList<StringEnumConfigNode>& getTestStringEnumConfigNodeList();
	Q_INVOKABLE void setTestStringEnumConfigNodeList(QList<StringEnumConfigNode>& value);

};
