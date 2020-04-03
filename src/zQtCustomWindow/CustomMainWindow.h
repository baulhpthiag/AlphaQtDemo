#ifndef CUSTOMMAINWINDOW_H
#define CUSTOMMAINWINDOW_H

#include <QWidget>

#include "CustomWindow.h"

namespace Ui {
class CustomMainWindow;
}

class CustomMainWindow : public CustomWindow
{
    Q_OBJECT

public:
    explicit CustomMainWindow(QWidget *parent = 0);
    ~CustomMainWindow();

private:
    void initTitleBar();

    Ui::CustomMainWindow *ui;
};

#endif // CUSTOMMAINWINDOW_H
