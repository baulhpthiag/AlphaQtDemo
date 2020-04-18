#pragma once

#include <QObject>
#include <QDebug>

class BoolConfigNode : public QObject
{
	Q_OBJECT
		Q_PROPERTY(QString nodeShowName MEMBER _nodeShowName)
		Q_PROPERTY(bool nodeValue MEMBER _nodeValue)
		Q_PROPERTY(bool isHot MEMBER _isHot)
		Q_PROPERTY(bool isShow MEMBER _isShow)

public:
	BoolConfigNode(QObject *parent = nullptr);

	BoolConfigNode(const BoolConfigNode& other, QObject* parent = nullptr)
	{
		this->_nodeShowName = other._nodeShowName;
		this->_nodeValue = other._nodeValue;
		this->_isHot = other._isHot;
		this->_isShow = other._isShow;
	}

	~BoolConfigNode();

	BoolConfigNode& operator= (const BoolConfigNode& other)
	{
		this->_nodeShowName = other._nodeShowName;
		this->_nodeValue = other._nodeValue;
		this->_isHot = other._isHot;
		this->_isShow = other._isShow;
		return *this;
	}
	friend  QDebug operator << (QDebug debug, const BoolConfigNode &config)
	{

		debug << "BoolConfigNode { _nodeShowName:" << config._nodeShowName << " _nodeValue:"<< config._nodeValue<<" _isHot:"<< config._isHot<<"_isShow"<< config._isShow<<"}";
		return debug;
	}

	//չʾ����
	QString _nodeShowName;

	//�ڵ�ֵ
	bool _nodeValue;

	//�Ƿ����Ƚڵ㣬����ȫ���ý����е��Ƚڵ���ʾ�������ý���
	bool _isHot;

	//�Ƿ��ڽ�������ʾ
	bool _isShow;

public slots:
	void nodeValueChanged(int index);

};
Q_DECLARE_METATYPE(BoolConfigNode)