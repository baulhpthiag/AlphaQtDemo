#pragma once
#ifdef WIN32  
#pragma execution_character_set("utf-8")  
#endif

#include <QWidget>
#include "ui_DatabaseDemo02Widget.h"

class DatabaseDemo02Widget : public QWidget
{
	Q_OBJECT

public:
	DatabaseDemo02Widget(QWidget *parent = Q_NULLPTR);
	~DatabaseDemo02Widget();

private:
	Ui::DatabaseDemo02Widget ui;


	//属性

	//方法
private:
	void init();
	void initUi();
	void initDb();
	//事件

	//qt槽
protected slots:
	void findButtonClicked();
	void addButtonClicked();
	void updateButtonClicked();
	void deleteButtonClicked();



	//qt信号
};
