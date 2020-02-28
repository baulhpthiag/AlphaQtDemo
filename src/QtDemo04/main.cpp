#include "testmainwidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TestMainWidget w;
    w.show();

    return a.exec();
}
