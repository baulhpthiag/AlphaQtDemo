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

class TestChildConfig : public QObject
{
	Q_OBJECT
		Q_PROPERTY(QString nodeShowName MEMBER _nodeShowName)
		Q_PROPERTY(bool isHot MEMBER _isHot)
		Q_PROPERTY(bool isShow MEMBER _isShow)

		Q_PROPERTY(BoolConfigNode testBoolConfigNode READ getTestBoolConfigNode WRITE setTestBoolConfigNode)
		Q_PROPERTY(IntConfigNode testIntConfigNode READ getTestIntConfigNode WRITE setTestIntConfigNode)
		Q_PROPERTY(IntEnumConfigNode testIntEnumConfigNode READ getTestIntEnumConfigNode WRITE setTestIntEnumConfigNode)
		Q_PROPERTY(DoubleConfigNode testDoubleConfigNode READ getTestDoubleConfigNode WRITE setTestDoubleConfigNode)
		Q_PROPERTY(DoubleEnumConfigNode testDoubleEnumConfigNode READ getTestDoubleEnumConfigNode WRITE setTestDoubleEnumConfigNode)
		Q_PROPERTY(StringConfigNode testStringConfigNode READ getTestStringConfigNode WRITE setTestStringConfigNode)
		Q_PROPERTY(StringEnumConfigNode testStringEnumConfigNode READ getTestStringEnumConfigNode WRITE setTestStringEnumConfigNode)

		Q_PROPERTY(BoolListConfigNode testBoolListConfigNode READ getTestBoolListConfigNode WRITE setTestBoolListConfigNode)

public:
	TestChildConfig(QObject *parent=nullptr);
	TestChildConfig(const TestChildConfig& other,QObject * parent = nullptr);
	~TestChildConfig();

	TestChildConfig& operator=(const TestChildConfig& other);

	//展示名称
	QString _nodeShowName;

	//是否是热节点，将完全配置界面中的热节点显示到热配置界面
	bool _isHot;

	//是否在界面中显示
	bool _isShow;

	BoolConfigNode _testBoolConfigNode;
	IntConfigNode _testIntConfigNode;
	IntEnumConfigNode _testIntEnumConfigNode;
	DoubleConfigNode _testDoubleConfigNode;
	DoubleEnumConfigNode _testDoubleEnumConfigNode;
	StringConfigNode _testStringConfigNode;
	StringEnumConfigNode _testStringEnumConfigNode;

	BoolListConfigNode _testBoolListConfigNode;

	BoolConfigNode& getTestBoolConfigNode();
	IntConfigNode& getTestIntConfigNode();
	IntEnumConfigNode& getTestIntEnumConfigNode();
	DoubleConfigNode& getTestDoubleConfigNode();
	DoubleEnumConfigNode& getTestDoubleEnumConfigNode();
	StringConfigNode& getTestStringConfigNode();
	StringEnumConfigNode& getTestStringEnumConfigNode();

	BoolListConfigNode& getTestBoolListConfigNode();

	Q_INVOKABLE BoolConfigNode* getTestBoolConfigNodeP();
	Q_INVOKABLE IntConfigNode* getTestIntConfigNodeP();
	Q_INVOKABLE IntEnumConfigNode* getTestIntEnumConfigNodeP();
	Q_INVOKABLE DoubleConfigNode* getTestDoubleConfigNodeP();
	Q_INVOKABLE DoubleEnumConfigNode* getTestDoubleEnumConfigNodeP();
	Q_INVOKABLE StringConfigNode* getTestStringConfigNodeP();
	Q_INVOKABLE StringEnumConfigNode* getTestStringEnumConfigNodeP();
	Q_INVOKABLE BoolListConfigNode* getTestBoolListConfigNodeP();

	public slots:
	void setTestBoolConfigNode(BoolConfigNode& value);
	void setTestIntConfigNode(IntConfigNode& value);
	void setTestIntEnumConfigNode(IntEnumConfigNode& value);
	void setTestDoubleConfigNode(DoubleConfigNode& value);
	void setTestDoubleEnumConfigNode(DoubleEnumConfigNode& value);
	void setTestStringConfigNode(StringConfigNode& value);
	void setTestStringEnumConfigNode(StringEnumConfigNode& value);
	void setTestBoolListConfigNode(BoolListConfigNode& value);
};
Q_DECLARE_METATYPE(TestChildConfig)