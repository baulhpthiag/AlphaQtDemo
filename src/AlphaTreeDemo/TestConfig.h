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

class TestConfig : public QObject
{
	Q_OBJECT
		Q_PROPERTY(BoolConfigNode testBoolConfigNode READ getTestBoolConfigNode WRITE setTestBoolConfigNode)
		Q_PROPERTY(DoubleConfigNode testDoubleConfigNode READ getTestDoubleConfigNode WRITE setTestDoubleConfigNode)
		Q_PROPERTY(DoubleEnumConfigNode testDoubleEnumConfigNode READ getTestDoubleEnumConfigNode WRITE setTestDoubleEnumConfigNode)
		Q_PROPERTY(IntConfigNode testIntConfigNode READ getTestIntConfigNode WRITE setTestIntConfigNode)
		Q_PROPERTY(IntEnumConfigNode testIntEnumConfigNode READ getTestIntEnumConfigNode WRITE setTestIntEnumConfigNode)
		Q_PROPERTY(StringConfigNode testStringConfigNode READ getTestStringConfigNode WRITE setTestStringConfigNode)
		Q_PROPERTY(StringEnumConfigNode testStringEnumConfigNode READ getTestStringEnumConfigNode WRITE setTestStringEnumConfigNode)

		Q_PROPERTY(QList<BoolConfigNode> testBoolConfigNodeList READ getTestBoolConfigNodeList WRITE setTestBoolConfigNodeList)
		Q_PROPERTY(QList<DoubleConfigNode> testDoubleConfigNodeList READ getTestDoubleConfigNodeList WRITE setTestDoubleConfigNodeList)
		Q_PROPERTY(QList<DoubleEnumConfigNode> testDoubleEnumConfigNodeList READ getTestDoubleEnumConfigNodeList WRITE setTestDoubleEnumConfigNodeList)
		Q_PROPERTY(QList<IntConfigNode> testIntConfigNodeList READ getTestIntConfigNodeList WRITE setTestIntConfigNodeList)
		Q_PROPERTY(QList<IntEnumConfigNode> testIntEnumConfigNodeList READ getTestIntEnumConfigNodeList WRITE setTestIntEnumConfigNodeList)
		Q_PROPERTY(QList<StringConfigNode> testStringConfigNodeList READ getTestStringConfigNodeList WRITE setTestStringConfigNodeList)
		Q_PROPERTY(QList<StringEnumConfigNode> testStringEnumConfigNodeList READ getTestStringEnumConfigNodeList WRITE setTestStringEnumConfigNodeList)
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

	BoolConfigNode& getTestBoolConfigNode();
	DoubleConfigNode& getTestDoubleConfigNode();
	DoubleEnumConfigNode& getTestDoubleEnumConfigNode();
	IntConfigNode& getTestIntConfigNode();
	IntEnumConfigNode& getTestIntEnumConfigNode();
	StringConfigNode& getTestStringConfigNode();
	StringEnumConfigNode& getTestStringEnumConfigNode();
	QList<BoolConfigNode>& getTestBoolConfigNodeList();
	QList<DoubleConfigNode>& getTestDoubleConfigNodeList();
	QList<DoubleEnumConfigNode>& getTestDoubleEnumConfigNodeList();
	QList<IntConfigNode>& getTestIntConfigNodeList();
	QList<IntEnumConfigNode>& getTestIntEnumConfigNodeList();
	QList<StringConfigNode>& getTestStringConfigNodeList();
	QList<StringEnumConfigNode>& getTestStringEnumConfigNodeList();

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
	Q_INVOKABLE QList<BoolConfigNode>* getTestBoolConfigNodeListP();
	Q_INVOKABLE QList<IntConfigNode>* getTestIntConfigNodeListP();
	Q_INVOKABLE QList<IntEnumConfigNode>* getTestIntEnumConfigNodeListP();
	Q_INVOKABLE QList<DoubleConfigNode>* getTestDoubleConfigNodeListP();
	Q_INVOKABLE QList<DoubleEnumConfigNode>* getTestDoubleEnumConfigNodeListP();
	Q_INVOKABLE QList<StringConfigNode>* getTestStringConfigNodeListP();
	Q_INVOKABLE QList<StringEnumConfigNode>* getTestStringEnumConfigNodeListP();


	public slots:
	void setTestBoolConfigNode(BoolConfigNode& value);
	void setTestDoubleConfigNode(DoubleConfigNode& value);
	void setTestDoubleEnumConfigNode(DoubleEnumConfigNode& value);
	void setTestIntConfigNode(IntConfigNode& value);
	void setTestIntEnumConfigNode(IntEnumConfigNode& value);
	void setTestStringConfigNode(StringConfigNode& value);
	void setTestStringEnumConfigNode(StringEnumConfigNode& value);
	void setTestBoolConfigNodeList(QList<BoolConfigNode>& value);
	void setTestDoubleConfigNodeList(QList<DoubleConfigNode>& value);
	void setTestDoubleEnumConfigNodeList(QList<DoubleEnumConfigNode>& value);
	void setTestIntConfigNodeList(QList<IntConfigNode>& value);
	void setTestIntEnumConfigNodeList(QList<IntEnumConfigNode>& value);
	void setTestStringConfigNodeList(QList<StringConfigNode>& value);
	void setTestStringEnumConfigNodeList(QList<StringEnumConfigNode>& value);

};
