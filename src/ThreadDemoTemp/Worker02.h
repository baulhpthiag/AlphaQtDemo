#pragma once

#include <QObject>
#include "Producer.h"

class Worker02 : public QObject
{
	Q_OBJECT

public:
	Worker02(QObject *parent = nullptr);
	~Worker02();

	//����

	//����

	//�¼�

	//qt��
public slots:
void start(Producer* p);

	//qt�ź�
signals:
void finish();
};
