#pragma once

#include <QObject>

class Controller02 : public QObject
{
	Q_OBJECT

public:
	Controller02(QObject *parent = nullptr);
	~Controller02();
};
