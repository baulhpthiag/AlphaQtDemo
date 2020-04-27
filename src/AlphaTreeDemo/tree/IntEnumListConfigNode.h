#pragma once

#include <QObject>
#include "IntEnumConfigNode.h"

class IntEnumListConfigNode : public QObject
{
	Q_OBJECT
		Q_PROPERTY(QString nodeShowName MEMBER _nodeShowName)
		Q_PROPERTY(bool isShow MEMBER _isShow)
		Q_PROPERTY(bool isHot MEMBER _isHot)
		Q_PROPERTY(QList<IntEnumConfigNode> nodeList READ getNodeList WRITE setNodeList)
public:
	IntEnumListConfigNode(QObject *parent=nullptr);
	IntEnumListConfigNode(const IntEnumListConfigNode& other, QObject * parent = nullptr);
	~IntEnumListConfigNode();
	IntEnumListConfigNode& operator=(const IntEnumListConfigNode& other);

	QString _nodeShowName;
	bool _isShow;
	bool _isHot;
	QList<IntEnumConfigNode> _nodelist;

	QList<IntEnumConfigNode>& getNodeList();
	QList<IntEnumConfigNode*> getNodeListP();
	public slots:
	void setNodeList(const QList<IntEnumConfigNode>& nodeList);


};
Q_DECLARE_METATYPE(IntEnumListConfigNode)