#pragma once

#include <QThread>

class AlphaThread1 : public QThread
{
	Q_OBJECT

public:
	AlphaThread1(QObject *parent = NULL);
	~AlphaThread1();

	//����
private:
	bool finishFlag = false;
	bool pauseFlag = false;

	//����
private:
	void init();
protected:
	void run();

public:
	void pause();
	void finish();
	//�¼�

	//qt��
public slots:
	
	//qt�ź�
signals:
	void workSignal(QString threadName);
	void pauseSignal(QString threadName);
	void finishSignal(QString threadName);

};
