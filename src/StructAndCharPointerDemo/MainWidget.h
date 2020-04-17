#pragma once

#include <QtWidgets/QWidget>
#include "ui_MainWidget.h"
struct s_Result
{
	char* chRsuInfo;

	s_Result()
	{
		chRsuInfo = nullptr;
	}

	s_Result(const s_Result &other)
	{
		chRsuInfo = new char[strlen(other.chRsuInfo) + 1];
		strcpy(chRsuInfo, other.chRsuInfo);
	}

	s_Result& operator=(const s_Result &s)
	{
		if (this != &s)
		{
			if (chRsuInfo != nullptr)
			{
				delete[] chRsuInfo;
			}
			chRsuInfo = new char[strlen(s.chRsuInfo) + 1];//pstr;  
			strcpy(chRsuInfo, s.chRsuInfo);
		}
		return *this;
	}

	~s_Result()
	{
		if (chRsuInfo != nullptr)
		{
			delete[] chRsuInfo;
			chRsuInfo = nullptr;
		}
	}

};

class MainWidget : public QWidget
{
	Q_OBJECT

public:
	MainWidget(QWidget *parent = Q_NULLPTR);

private:
	Ui::MainWidgetClass ui;

	s_Result getStruct();

public slots:
void pushButtonClicked();


};
