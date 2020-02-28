#include "mywidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyWidget w;
    //以新的对话框的方式打开
    w.show();
    //exec方法执行，程序处于循环状态
    return a.exec();
}
