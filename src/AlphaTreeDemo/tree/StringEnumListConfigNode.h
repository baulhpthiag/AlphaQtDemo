#pragma once

#include <QObject>
#include "StringEnumConfigNode.h"

class StringEnumListConfigNode : public QObject
{
	Q_OBJECT
		Q_PROPERTY(QString nodeShowName MEMBER _nodeShowName)
		Q_PROPERTY(bool isShow MEMBER _isShow)
		Q_PROPERTY(bool isHot MEMBER _isHot)
		Q_PROPERTY(QList<StringEnumConfigNode> nodeList READ getNodeList WRITE setNodeList)
public:
	StringEnumListConfigNode(QObject *parent = nullptr);
	StringEnumListConfigNode(const StringEnumListConfigNode& other,QObject*parent = nullptr);
	~StringEnumListConfigNode();
	StringEnumListConfigNode& operator = (const StringEnumListConfigNode & other);

	QString _nodeShowName;
	bool _isShow;
	bool _isHot;
	QList<StringEnumConfigNode> _nodelist;

	QList<StringEnumConfigNode>& getNodeList();
	QList<StringEnumConfigNode*> getNodeListP();
	public slots:
	void setNodeList(const QList<StringEnumConfigNode>& nodeList);


};
Q_DECLARE_METATYPE(StringEnumListConfigNode)