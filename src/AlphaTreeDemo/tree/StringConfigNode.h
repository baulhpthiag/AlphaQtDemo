#pragma once

#include <QObject>

class StringConfigNode : public QObject
{
	Q_OBJECT
		Q_PROPERTY(QString nodeShowName MEMBER _nodeShowName)
		Q_PROPERTY(bool isShow MEMBER _isShow)
		Q_PROPERTY(bool isHot MEMBER _isHot)
		Q_PROPERTY(QString nodeValue MEMBER _nodeValue)
public:
	StringConfigNode(QObject *parent = nullptr);
	StringConfigNode(const StringConfigNode& other, QObject* parent = nullptr);
	~StringConfigNode();
	StringConfigNode& operator=(const StringConfigNode & other);

	//չʾ����
	QString _nodeShowName;

	//�Ƿ��ڽ�������ʾ
	bool _isShow;

	//�Ƿ����Ƚڵ㣬����ȫ���ý����е��Ƚڵ���ʾ�������ý���
	bool _isHot;

	//�ڵ�ֵ
	QString _nodeValue;

	public slots:
	void nodeValueChanged(QString value);
};
Q_DECLARE_METATYPE(StringConfigNode)