#include "frmmain.h"
#include <QApplication>
#include "commonhelper.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    CommonHelper::SetUTF8Code();
    CommonHelper::SetStyle("default");
    CommonHelper::SetChinese();

    frmMain w;
    w.show();

    return a.exec();
}
