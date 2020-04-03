#ifndef BASEWINDOW_H
#define BASEWINDOW_H

#include <QWidget>
#include <QMainWindow>
#include "CustomTitleBar.h"

class CustomWindow : public QWidget
{
	Q_OBJECT

public:
	CustomWindow(QWidget *parent = 0);
	~CustomWindow();

private:
	void initTitleBar();
	void paintEvent(QPaintEvent *event);
	void loadStyleSheet(const QString &sheetName);

private slots:
	void onButtonMinClicked();
	void onButtonRestoreClicked();
	void onButtonMaxClicked();
	void onButtonCloseClicked();

protected:
    CustomTitleBar* m_titleBar;
	
};

#endif // BASEWINDOW_H
