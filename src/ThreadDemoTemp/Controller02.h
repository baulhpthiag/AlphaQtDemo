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

	//����
private:

	Producer * p;

	QThread threadA;
	Worker02 * workerA;
	QThread threadB;
	Worker02 * workerB;



	//����
private:
	void init();
	void initMember();
	
	//�¼�


	//qt��
public slots:
	void finish();
	void begin();

	//qt�ź�
signals:
	void start(Producer* p);
};
