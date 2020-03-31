#pragma once

#include <QObject>
#include <QMetaType>
#include <QVariant>


class Son : public QObject
{
	Q_OBJECT
		Q_PROPERTY(int sonAge MEMBER _sonAge)
		Q_PROPERTY(QString sonName MEMBER _sonName)
public:
	Son() = default;

	~Son();

	Son(const Son &other, QObject *parent = nullptr)
		: QObject(parent)
	{
		this->_sonName = other._sonName;
		this->_sonAge = other._sonAge;
	}

	Son& operator =(const Son &other) 
	{
		this->_sonAge = other._sonAge;
		this->_sonName = other._sonName;
		return *this;
	}

	bool operator!=(const Son& other) 
	{
		if (this->_sonAge!=other._sonAge || this->_sonName !=other._sonName)
		{
			return false;
		}
		return true;
	}

	int _sonAge;

	QString _sonName;
};

Q_DECLARE_METATYPE(Son)