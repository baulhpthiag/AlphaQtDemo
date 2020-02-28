#ifndef TESTMAINWINDOW_H
#define TESTMAINWINDOW_H

#include <QWidget>

namespace Ui {
class TestMainWindow;
}

class TestMainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit TestMainWindow(QWidget *parent = nullptr);
    ~TestMainWindow();

private slots:
    void on_pushButton_2_clicked();

    void on_checkBox_stateChanged(int arg1);

    void on_checkBox_2_stateChanged(int arg1);

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_7_clicked();

private:
    Ui::TestMainWindow *ui;
};

#endif // TESTMAINWINDOW_H
