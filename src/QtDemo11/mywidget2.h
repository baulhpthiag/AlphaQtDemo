#ifndef MYWIDGET2_H
#define MYWIDGET2_H

#include <QWidget>
#include <QPicture>

namespace Ui {
class MyWidget2;
}

class MyWidget2 : public QWidget
{
    Q_OBJECT

public:
    explicit MyWidget2(QWidget *parent = nullptr);
    ~MyWidget2();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

        void paintEvent(QPaintEvent *event);

private:
    Ui::MyWidget2 *ui;
    QPicture   mypicture;
    bool flag =false;
};

#endif // MYWIDGET2_H
