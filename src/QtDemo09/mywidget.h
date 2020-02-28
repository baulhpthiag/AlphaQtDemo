#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>

namespace Ui {
class MyWidget;
}

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MyWidget(QWidget *parent = nullptr);
    ~MyWidget();
    void timerEvent(QTimerEvent * event);
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();
    void onTimeout();
private:
    Ui::MyWidget *ui;
    int num1 = 0;
    int num2 = 0;
    int num3= 0;
    int timer1 = -1;
    int timer2= -1;
    QTimer * timer3;
};

#endif // MYWIDGET_H
