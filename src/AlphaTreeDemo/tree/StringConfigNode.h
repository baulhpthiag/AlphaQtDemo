#pragma once

#include <QObject>

class StringConfigNode : public QObject
{
	Q_OBJECT
		Q_PROPERTY(QString nodeShowName MEMBER _nodeShowName)
		Q_PROPERTY(bool isShow MEMBER _isShow)
		Q_PROPERTY(bool isHot MEMBER _isHot)
		Q_PROPERTY(QString nodeValue MEMBER _nodeValue)
public:
	StringConfigNode(QObject *parent = nullptr);
	StringConfigNode(const StringConfigNode& other, QObject* parent = nullptr);
	~StringConfigNode();
	StringConfigNode& operator=(const StringConfigNode & other);

	//展示名称
	QString _nodeShowName;

	//是否在界面中显示
	bool _isShow;

	//是否是热节点，将完全配置界面中的热节点显示到热配置界面
	bool _isHot;

	//节点值
	QString _nodeValue;

	public slots:
	void nodeValueChanged(QString value);
};
Q_DECLARE_METATYPE(StringConfigNode)