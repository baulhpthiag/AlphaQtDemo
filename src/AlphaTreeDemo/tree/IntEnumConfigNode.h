#pragma once

#include <QObject>

class IntEnumConfigNode : public QObject
{
	Q_OBJECT
		Q_PROPERTY(QString nodeShowName MEMBER _nodeShowName)
		Q_PROPERTY(bool isShow MEMBER _isShow)
		Q_PROPERTY(bool isHot MEMBER _isHot)
		Q_PROPERTY(int enumIndex MEMBER _enumIndex)
		Q_PROPERTY(QList<int> valueEnum MEMBER _valueEnum)

public:
	IntEnumConfigNode(QObject *parent = nullptr);
	IntEnumConfigNode(const IntEnumConfigNode& other, QObject* parent = nullptr);
	~IntEnumConfigNode();
	IntEnumConfigNode& operator=(const IntEnumConfigNode & other);

	//展示名称
	QString _nodeShowName;

	//是否在界面中显示
	bool _isShow;

	//是否是热节点，将完全配置界面中的热节点显示到热配置界面
	bool _isHot;

	//节点值
	int _enumIndex;

	//枚举值
	QList<int> _valueEnum;

	public slots:
	void nodeValueIndexChanged(int index);
};

Q_DECLARE_METATYPE(IntEnumConfigNode)