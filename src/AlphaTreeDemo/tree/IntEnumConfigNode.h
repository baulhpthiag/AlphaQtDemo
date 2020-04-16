#pragma once

#include <QObject>

class IntEnumConfigNode : public QObject
{
	Q_OBJECT
		Q_PROPERTY(QString nodeShowName MEMBER _nodeShowName)
		Q_PROPERTY(int enumIndex MEMBER _enumIndex)
		Q_PROPERTY(QList<int> valueEnum MEMBER _valueEnum)
		Q_PROPERTY(bool isHot MEMBER _isHot)
		Q_PROPERTY(bool isShow MEMBER _isShow)

public:
	IntEnumConfigNode(const IntEnumConfigNode& other, QObject* parent = nullptr)
	{
		this->_nodeShowName = other._nodeShowName;
		this->_enumIndex = other._enumIndex;
		this->_valueEnum = other._valueEnum;
		this->_isHot = other._isHot;
		this->_isShow = other._isShow;
	}

	IntEnumConfigNode(QObject *parent = nullptr);
	~IntEnumConfigNode();


	IntEnumConfigNode& operator=(const IntEnumConfigNode & other)
	{
		this->_nodeShowName = other._nodeShowName;
		this->_enumIndex = other._enumIndex;
		this->_valueEnum = other._valueEnum;
		this->_isHot = other._isHot;
		this->_isShow = other._isShow;
		return *this;
	}

	//չʾ����
	QString _nodeShowName;

	//�ڵ�ֵ
	int _enumIndex;

	//ö��ֵ
	QList<int> _valueEnum;

	//�Ƿ����Ƚڵ㣬����ȫ���ý����е��Ƚڵ���ʾ�������ý���
	bool _isHot;

	//�Ƿ��ڽ�������ʾ
	bool _isShow;

	public slots:
	void nodeValueIndexChanged(int index);
};

Q_DECLARE_METATYPE(IntEnumConfigNode)