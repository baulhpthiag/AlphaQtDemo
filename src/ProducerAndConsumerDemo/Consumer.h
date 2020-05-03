#pragma once

#include <QObject>
#include "Product.h"
class Consumer : public QObject
{
	Q_OBJECT

public:
	Consumer(QObject *parent = nullptr);
	~Consumer();

	int interval;
	bool continueFlag;
	bool consumeFlag;

	QList<Product> products;

	public slots:
	void continueConsume();
	void signalConsume(Product product);

signals:
	void signalMessageChanged(QString message);
};
