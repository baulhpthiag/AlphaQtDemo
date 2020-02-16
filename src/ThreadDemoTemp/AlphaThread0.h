#pragma once

#include <QThread>

class AlphaThread0 : public QThread
{
	Q_OBJECT

public:
	AlphaThread0(QObject *parent=NULL);
	~AlphaThread0();

	//属性
private:
	QString name;
	void * threadDemo;

	bool stopFlag = false;
	bool hoverFlag = false;

	//方法
protected:

	void run();

public:
	void setName(QString name);

	void setSource(void* source);
	void hoverThread();
	void stopThread();

	//事件


	//qt槽

	//qt信号
};
