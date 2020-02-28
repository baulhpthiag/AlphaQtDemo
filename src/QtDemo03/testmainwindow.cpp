#include "testmainwindow.h"
#include "ui_testmainwindow.h"

TestMainWindow::TestMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TestMainWindow)
{
    ui->setupUi(this);

    //添加资源文件

//    // "D:\\alpha\\a4\\icon\\star.png"等同于"D:/alpha/a4/icon/star.png"
//    //路径里不能有汉字
//    //写死路径
//    ui->actionaction01->setIcon(QIcon("D:/alpha/a4/icon/star.png"));

    //使用资源的方式加载图片
    ui->actionaction01->setIcon(QIcon(":/icon/star.png"));



}

TestMainWindow::~TestMainWindow()
{
    delete ui;
}
