#ifndef WIDGET_H
#define WIDGET_H


#include <QWidget>

class MyWidget : public QWidget
{
    //可以使用信号和槽
    Q_OBJECT

public:
    MyWidget(QWidget *parent = 0);
    ~MyWidget();
    void Method01();
    void Slot01();
    void Method02();
    void Slot02();
    void Method03();
    void Method04();
};








#endif // WIDGET_H
