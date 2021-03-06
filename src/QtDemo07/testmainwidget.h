﻿#ifndef TESTMAINWIDGET_H
#define TESTMAINWIDGET_H

#include <QWidget>

namespace Ui {
class TestMainWidget;
}

class TestMainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TestMainWidget(QWidget *parent = nullptr);
    ~TestMainWidget();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::TestMainWidget *ui;
};

#endif // TESTMAINWIDGET_H
