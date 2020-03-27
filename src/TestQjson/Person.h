#pragma once

#include <QObject>
#include <QDate>

class Person : public QObject
{
	Q_OBJECT

		Q_PROPERTY(QString name READ name WRITE setName)
		Q_PROPERTY(int phoneNumber READ phoneNumber WRITE setPhoneNumber)
		Q_PROPERTY(Gender gender READ gender WRITE setGender)
		Q_PROPERTY(QDate brithday READ brithday WRITE setBrithday)
		Q_ENUMS(Gender)

public:
	Person(QObject* parent = 0);
	~Person();

	QString name() const;
	void setName(const QString& name);

	int phoneNumber() const;
	void setPhoneNumber(const int phoneNumber);

	enum Gender { Male, Female };
	void setGender(Gender gender);
	Gender gender() const;

	QDate brithday() const;
	void setBrithday(const QDate& dob);

private:
	QString m_name;
	int m_phoneNumber;
	Gender m_gender;
	QDate m_dob;
};