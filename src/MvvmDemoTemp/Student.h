#pragma once

#include <QObject>

class Student : public QObject
{
	Q_OBJECT
	Q_PROPERTY(QString name READ getName WRITE setName NOTIFY nameChange)

public:
	Student(QObject *parent =nullptr);
	~Student();
private:
	QString _name;

public:
	Q_INVOKABLE QString getName();
	Q_INVOKABLE void setName(const QString& name);
	

signals:
	void nameChange(QString name);
};
