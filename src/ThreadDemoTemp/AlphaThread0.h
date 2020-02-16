#pragma once

#include <QThread>

class AlphaThread0 : public QThread
{
	Q_OBJECT

public:
	AlphaThread0(QObject *parent=NULL);
	~AlphaThread0();

	//����
private:
	QString name;
	void * threadDemo;

	bool stopFlag = false;
	bool hoverFlag = false;

	//����
protected:

	void run();

public:
	void setName(QString name);

	void setSource(void* source);
	void hoverThread();
	void stopThread();

	//�¼�


	//qt��

	//qt�ź�
};
