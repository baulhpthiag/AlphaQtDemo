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

	//չʾ����
	QString _nodeShowName;

	//�Ƿ��ڽ�������ʾ
	bool _isShow;

	//�Ƿ����Ƚڵ㣬����ȫ���ý����е��Ƚڵ���ʾ�������ý���
	bool _isHot;

	//ö������
	int _enumIndex;

	//ö��ֵ
	QList<double> _valueEnum;

public slots:
	void nodeValueIndexChanged(int index);
};

Q_DECLARE_METATYPE(DoubleEnumConfigNode)