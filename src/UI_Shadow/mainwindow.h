#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include "ui_mainwindow.h"

class CustomShadow;
class MainWindow : public QWidget
{
	Q_OBJECT
	Q_PROPERTY(int paintheight READ paintheight WRITE setPaintheight)

public:
	MainWindow(QWidget *parent = 0);
	~MainWindow();

public:
	int paintheight() const { return m_paintHeight; };
	void setPaintheight(int hegiht) { m_paintHeight = hegiht; update(); };

private:
	void paintEvent(QPaintEvent*);// »æÖÆÊÂ¼þ

private:
	Ui::MainWindow ui;
	CustomShadow* m_customWindow;
	int m_paintHeight;
};

#endif // MAINWINDOW_H
