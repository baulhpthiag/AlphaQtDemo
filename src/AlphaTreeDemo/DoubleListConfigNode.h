#pragma once

#include <QObject>
#include "DoubleConfigNode.h"

class DoubleListConfigNode : public QObject
{
	Q_OBJECT
		Q_PROPERTY(QString nodeShowName MEMBER _nodeShowName)
		Q_PROPERTY(bool isShow MEMBER _isShow)
		Q_PROPERTY(bool isHot MEMBER _isHot)
		Q_PROPERTY(QList<DoubleConfigNode> nodeList READ getNodeList WRITE setNodeList)

public:
	DoubleListConfigNode(QObject *parent = nullptr);
	DoubleListConfigNode(const DoubleListConfigNode & other, QObject* parent = nullptr);
	~DoubleListConfigNode();
	DoubleListConfigNode& operator=(const DoubleListConfigNode & other);

	QString _nodeShowName;
	bool _isShow;
	bool _isHot;
	QList<DoubleConfigNode> _nodelist;

	QList<DoubleConfigNode>& getNodeList();
	QList<DoubleConfigNode*> getNodeListP();

public slots:
void setNodeList(const QList<DoubleConfigNode>& nodeList);

};
Q_DECLARE_METATYPE(DoubleListConfigNode)