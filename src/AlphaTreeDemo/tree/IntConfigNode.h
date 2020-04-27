#pragma once

#include <QObject>

class IntConfigNode : public QObject
{
	Q_OBJECT
		Q_PROPERTY(QString nodeShowName MEMBER _nodeShowName)
		Q_PROPERTY(bool isShow MEMBER _isShow)
		Q_PROPERTY(bool isHot MEMBER _isHot)
		Q_PROPERTY(int nodeValue MEMBER _nodeValue)
		Q_PROPERTY(int maxValue MEMBER _maxValue)
		Q_PROPERTY(int minValue MEMBER _minValue)

public:
	IntConfigNode(QObject *parent = nullptr);
	IntConfigNode(const IntConfigNode& other, QObject* parent = nullptr);
	~IntConfigNode();
	IntConfigNode& operator=(const IntConfigNode& other);

	//չʾ����
	QString _nodeShowName;

	//�Ƿ��ڽ�������ʾ
	bool _isShow;

	//�Ƿ����Ƚڵ㣬����ȫ���ý����е��Ƚڵ���ʾ�������ý���
	bool _isHot;

	//�ڵ�ֵ
	int _nodeValue;

	//���ֵ
	int _maxValue;

	//��Сֵ
	int _minValue;

	public slots:
	void nodeValueChanged(QString strvalue);
};
Q_DECLARE_METATYPE(IntConfigNode)