#ifndef MYWIDGET1_H
#define MYWIDGET1_H

#include <QWidget>

namespace Ui {
class MyWidget1;
}

class MyWidget1 : public QWidget
{
    Q_OBJECT

public:
    explicit MyWidget1(QWidget *parent = nullptr);
    ~MyWidget1();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MyWidget1 *ui;
};

#endif // MYWIDGET1_H
