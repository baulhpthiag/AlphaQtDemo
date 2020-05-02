#pragma once

#include <QObject>

class Producer : public QObject
{
	Q_OBJECT

public:
	Producer(QObject *parent = nullptr);
	~Producer();
	bool runFlag;
	int product;
public slots:
void produce();
void changeState(bool b);

signals:
void signalProduceProduct(int i);
void signalSendMessage(QString message);
};
