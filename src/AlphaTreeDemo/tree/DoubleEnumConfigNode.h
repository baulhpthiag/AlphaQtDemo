#pragma once

#include <QObject>

class DoubleEnumConfigNode : public QObject
{
	Q_OBJECT
		Q_PROPERTY(QString nodeShowName MEMBER _nodeShowName)
		Q_PROPERTY(bool isShow MEMBER _isShow)
		Q_PROPERTY(bool isHot MEMBER _isHot)
		Q_PROPERTY(int enumIndex MEMBER _enumIndex)
		Q_PROPERTY(QList<double> valueEnum MEMBER _valueEnum)

public:
	DoubleEnumConfigNode(QObject *parent = nullptr);
	DoubleEnumConfigNode(const DoubleEnumConfigNode& other, QObject * parent = nullptr);
	~DoubleEnumConfigNode();
	DoubleEnumConfigNode& operator=(const DoubleEnumConfigNode& other);

	//展示名称
	QString _nodeShowName;

	//是否在界面中显示
	bool _isShow;

	//是否是热节点，将完全配置界面中的热节点显示到热配置界面
	bool _isHot;

	//枚举索引
	int _enumIndex;

	//枚举值
	QList<double> _valueEnum;

public slots:
	void nodeValueIndexChanged(int index);
};

Q_DECLARE_METATYPE(DoubleEnumConfigNode)