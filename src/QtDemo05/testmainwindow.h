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
    void on_pushButton_clicked();

private:
    Ui::TestMainWindow *ui;
};

#endif // TESTMAINWINDOW_H
