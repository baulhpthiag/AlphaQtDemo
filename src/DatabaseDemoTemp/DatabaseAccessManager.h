#pragma once

#include <QObject>

class DatabaseAccessManager : public QObject
{
	Q_OBJECT

public:
	DatabaseAccessManager(QObject *parent);
	~DatabaseAccessManager();
};
