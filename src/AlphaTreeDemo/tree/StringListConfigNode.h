#pragma once

#include <QObject>
#include "StringConfigNode.h"

class StringListConfigNode : public QObject
{
	Q_OBJECT
		Q_PROPERTY(QString nodeShowName MEMBER _nodeShowName)
		Q_PROPERTY(bool isShow MEMBER _isShow)
		Q_PROPERTY(bool isHot MEMBER _isHot)
		Q_PROPERTY(QList<StringConfigNode> nodeList READ getNodeList WRITE setNodeList)
public:
	StringListConfigNode(QObject *parent = nullptr);
	StringListConfigNode(const StringListConfigNode& other,QObject* parent= nullptr);
	~StringListConfigNode();
	StringListConfigNode& operator = (const StringListConfigNode& other);

	QString _nodeShowName;
	bool _isShow;
	bool _isHot;
	QList<StringConfigNode> _nodelist;

	QList<StringConfigNode>& getNodeList();
	QList<StringConfigNode*> getNodeListP();
	public slots:
	void setNodeList(const QList<StringConfigNode>& nodeList);

};
Q_DECLARE_METATYPE(StringListConfigNode)