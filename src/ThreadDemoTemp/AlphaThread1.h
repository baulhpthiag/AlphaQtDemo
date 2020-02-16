#pragma once

#include <QThread>

class AlphaThread1 : public QThread
{
	Q_OBJECT

public:
	AlphaThread1(QObject *parent = NULL);
	~AlphaThread1();

	//属性
private:
	bool finishFlag = false;
	bool pauseFlag = false;

	//方法
private:
	void init();
protected:
	void run();

public:
	void pause();
	void finish();
	//事件

	//qt槽
public slots:
	
	//qt信号
signals:
	void workSignal(QString threadName);
	void pauseSignal(QString threadName);
	void finishSignal(QString threadName);

};
