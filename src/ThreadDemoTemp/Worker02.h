#pragma once

#include <QObject>
#include "Producer.h"

class Worker02 : public QObject
{
	Q_OBJECT

public:
	Worker02(QObject *parent = nullptr);
	~Worker02();

	//属性

	//方法

	//事件

	//qt槽
public slots:
void start(Producer* p);

	//qt信号
signals:
void finish();
};
