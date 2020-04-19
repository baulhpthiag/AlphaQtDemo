#pragma once

#include <QObject>
#include "DoubleEnumConfigNode.h"

class DoubleEnumListConfigNode : public QObject
{
	Q_OBJECT
		Q_PROPERTY(QString nodeShowName MEMBER _nodeShowName)
		Q_PROPERTY(bool isShow MEMBER _isShow)
		Q_PROPERTY(bool isHot MEMBER _isHot)
		Q_PROPERTY(QList<DoubleEnumConfigNode> nodeList READ getNodeList WRITE setNodeList)

public:
	DoubleEnumListConfigNode(QObject *parent = nullptr);
	DoubleEnumListConfigNode(const DoubleEnumListConfigNode& other, QObject* parent = nullptr);
	~DoubleEnumListConfigNode();
	DoubleEnumListConfigNode& operator=(const DoubleEnumListConfigNode& other);

	QString _nodeShowName;
	bool _isShow;
	bool _isHot;
	QList<DoubleEnumConfigNode> _nodelist;

	QList<DoubleEnumConfigNode>& getNodeList();
	QList<DoubleEnumConfigNode*> getNodeListP();
	public slots:
	void setNodeList(const QList<DoubleEnumConfigNode>& nodeList);


};
Q_DECLARE_METATYPE(DoubleEnumListConfigNode)