#pragma once

#include <QObject>
#include <QDebug>

class BoolConfigNode : public QObject
{
	Q_OBJECT
		Q_PROPERTY(QString nodeShowName MEMBER _nodeShowName)
		Q_PROPERTY(bool isShow MEMBER _isShow)
		Q_PROPERTY(bool isHot MEMBER _isHot)
		Q_PROPERTY(bool nodeValue MEMBER _nodeValue)

public:
	BoolConfigNode(QObject *parent = nullptr);
	BoolConfigNode(const BoolConfigNode& other, QObject* parent = nullptr);
	~BoolConfigNode();
	BoolConfigNode& operator = (const BoolConfigNode& other);
	friend  QDebug operator << (QDebug debug, const BoolConfigNode &config)
	{
		debug << "BoolConfigNode { _nodeShowName:" << config._nodeShowName << " _nodeValue:"<< config._nodeValue<<" _isHot:"<< config._isHot<<"_isShow"<< config._isShow<<"}";
		return debug;
	}

	//展示名称
	QString _nodeShowName;

	//是否在界面中显示
	bool _isShow;

	//是否是热节点，将完全配置界面中的热节点显示到热配置界面
	bool _isHot;

	//节点值
	bool _nodeValue;

public slots:
	void nodeValueChanged(int index);

};
Q_DECLARE_METATYPE(BoolConfigNode)