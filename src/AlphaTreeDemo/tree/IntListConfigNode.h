#pragma once

#include <QObject>
#include "IntConfigNode.h"

class IntListConfigNode : public QObject
{
	Q_OBJECT
		Q_PROPERTY(QString nodeShowName MEMBER _nodeShowName)
		Q_PROPERTY(bool isShow MEMBER _isShow)
		Q_PROPERTY(bool isHot MEMBER _isHot)
		Q_PROPERTY(QList<IntConfigNode> nodeList READ getNodeList WRITE setNodeList)
public:
	IntListConfigNode(QObject *parent = nullptr);
	IntListConfigNode(const IntListConfigNode& other, QObject* parent = nullptr);
	~IntListConfigNode();
	IntListConfigNode& operator=(const IntListConfigNode& other);

	QString _nodeShowName;
	bool _isShow;
	bool _isHot;
	QList<IntConfigNode> _nodelist;

	QList<IntConfigNode>& getNodeList();
	QList<IntConfigNode*> getNodeListP();

	public slots:
	void setNodeList(const QList<IntConfigNode>& nodeList);

};
Q_DECLARE_METATYPE(IntListConfigNode)