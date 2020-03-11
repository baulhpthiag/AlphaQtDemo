#pragma once

#include <QObject>

class Student : public QObject
{
	Q_OBJECT

	Q_PROPERTY(QString name READ getName WRITE setName NOTIFY nameChange)
	Q_PROPERTY(QString location MEMBER _location NOTIFY locationChange)

private:
	QString _name;
	QString _location;
public:
	Student(QObject *parent = nullptr);
	~Student();

	QString getLocation();
	Q_INVOKABLE void setName(QString name);
	Q_INVOKABLE QString getName();
	Q_INVOKABLE QString test();
	Q_INVOKABLE QString test1();

signals:
	void nameChange();
	void locationChange();





};
