#pragma once

#include <QObject>

class Consumer : public QObject
{
	Q_OBJECT

public:
	Consumer(QObject *parent = nullptr);
	~Consumer();

	QList<int> products;

	public slots:
	void addProduct(int product);

	void process();

signals:
	void signalSendMessage(QString message);
};
