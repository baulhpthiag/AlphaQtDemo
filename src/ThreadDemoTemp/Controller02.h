#pragma once

#include <QObject>
#include <QThread>
#include "Worker02.h"
#include "Producer.h"

class Controller02 : public QObject
{
	Q_OBJECT

public:
	Controller02(QObject *parent = nullptr);
	~Controller02();

	//属性
private:

	Producer * p;

	QThread threadA;
	Worker02 * workerA;
	QThread threadB;
	Worker02 * workerB;



	//方法
private:
	void init();
	void initMember();
	
	//事件


	//qt槽
public slots:
	void finish();
	void begin();

	//qt信号
signals:
	void start(Producer* p);
};
