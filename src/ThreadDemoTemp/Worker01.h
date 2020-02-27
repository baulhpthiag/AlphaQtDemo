#pragma once

#include <QObject>

class Worker01 : public QObject
{
	Q_OBJECT

public:
	Worker01(QObject *parent = Q_NULLPTR);
	~Worker01();

	//属性


	//方法


	//事件


	//qt槽
public slots:
	void work();

	//qt信号
signals:
	void workFinish(QString message);


};
