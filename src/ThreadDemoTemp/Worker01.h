#pragma once

#include <QObject>

class Worker01 : public QObject
{
	Q_OBJECT

public:
	Worker01(QObject *parent = Q_NULLPTR);
	~Worker01();

	//����


	//����


	//�¼�


	//qt��
public slots:
	void work();

	//qt�ź�
signals:
	void workFinish(QString message);


};
