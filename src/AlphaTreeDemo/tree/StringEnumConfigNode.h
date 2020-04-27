#pragma once

#include <QObject>

class StringEnumConfigNode : public QObject
{
	Q_OBJECT
		Q_PROPERTY(QString nodeShowName MEMBER _nodeShowName)
		Q_PROPERTY(bool isShow MEMBER _isShow)
		Q_PROPERTY(bool isHot MEMBER _isHot)
		Q_PROPERTY(int enumIndex MEMBER _enumIndex)
		Q_PROPERTY(QList<QString> valueEnum MEMBER _valueEnum)

public:
	StringEnumConfigNode(QObject *parent = nullptr);
	StringEnumConfigNode(const StringEnumConfigNode& other, QObject* parent = nullptr);
	~StringEnumConfigNode();
	StringEnumConfigNode& operator=(const StringEnumConfigNode& other);

	//չʾ����
	QString _nodeShowName;

	//�Ƿ��ڽ�������ʾ
	bool _isShow;

	//�Ƿ����Ƚڵ㣬����ȫ���ý����е��Ƚڵ���ʾ�������ý���
	bool _isHot;

	//�ڵ�ֵ
	int _enumIndex;

	//ö��ֵ
	QList<QString> _valueEnum;

	public slots:
	void nodeValueIndexChanged(int index);
};
Q_DECLARE_METATYPE(StringEnumConfigNode)