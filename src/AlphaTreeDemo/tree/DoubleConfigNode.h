#pragma once

#include <QObject>


class DoubleConfigNode : public QObject
{
	Q_OBJECT
		Q_PROPERTY(QString nodeShowName MEMBER _nodeShowName)
		Q_PROPERTY(bool isShow MEMBER _isShow)
		Q_PROPERTY(bool isHot MEMBER _isHot)
		Q_PROPERTY(double nodeValue MEMBER _nodeValue)
		Q_PROPERTY(double maxValue MEMBER _maxValue)
		Q_PROPERTY(double minValue MEMBER _minValue)

public:
	DoubleConfigNode(QObject *parent = nullptr);
	DoubleConfigNode(const DoubleConfigNode& other, QObject* parent = nullptr);
	~DoubleConfigNode();
	DoubleConfigNode& operator=(const DoubleConfigNode & other);

	//展示名称
	QString _nodeShowName;

	//是否在界面中显示
	bool _isShow;

	//是否是热节点，将完全配置界面中的热节点显示到热配置界面
	bool _isHot;

	//节点值
	double _nodeValue;

	//最大值
	double _maxValue;

	//最小值
	double _minValue;

	public slots:
	void nodeValueChanged(QString strValue);
};

Q_DECLARE_METATYPE(DoubleConfigNode)