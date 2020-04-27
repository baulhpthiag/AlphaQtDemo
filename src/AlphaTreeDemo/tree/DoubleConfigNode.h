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

	//չʾ����
	QString _nodeShowName;

	//�Ƿ��ڽ�������ʾ
	bool _isShow;

	//�Ƿ����Ƚڵ㣬����ȫ���ý����е��Ƚڵ���ʾ�������ý���
	bool _isHot;

	//�ڵ�ֵ
	double _nodeValue;

	//���ֵ
	double _maxValue;

	//��Сֵ
	double _minValue;

	public slots:
	void nodeValueChanged(QString strValue);
};

Q_DECLARE_METATYPE(DoubleConfigNode)