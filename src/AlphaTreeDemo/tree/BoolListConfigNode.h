#pragma once

#include <QObject>
#include "BoolConfigNode.h"

class BoolListConfigNode : public QObject
{
	Q_OBJECT
		Q_PROPERTY(QString nodeShowName MEMBER _nodeShowName)
		Q_PROPERTY(bool isShow MEMBER _isShow)
		Q_PROPERTY(bool isHot MEMBER _isHot)
		Q_PROPERTY(QList<BoolConfigNode> nodeList READ getNodeList WRITE setNodeList)
public:
	BoolListConfigNode(QObject *parent = nullptr);
	BoolListConfigNode(const BoolListConfigNode & other, QObject*parent = nullptr);
	~BoolListConfigNode();
	BoolListConfigNode& operator =(const BoolListConfigNode& other);

	QString _nodeShowName;
	bool _isShow;
	bool _isHot;
	QList<BoolConfigNode> _nodelist;

	QList<BoolConfigNode>& getNodeList();
	QList<BoolConfigNode*> getNodeListP();
	public slots:
	void setNodeList(const QList<BoolConfigNode>& nodeList);

};
Q_DECLARE_METATYPE(BoolListConfigNode)