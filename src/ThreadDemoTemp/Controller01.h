#pragma once

#include <QObject>
#include <QThread>
#include "Worker01.h"

class Controller01 : public QObject
{
	Q_OBJECT

public:
	Controller01(QObject *parent = nullptr);
	~Controller01();

	//
private:
	QThread thread01;
	Worker01 * worker01;

	//方法
private:
	void init();
	void initMember();

public:
	void start();

	//事件

	//qt槽
protected slots:
	void worker01Finish(QString message);

	//qt信号
signals:
	void worker01StartWork();

};
