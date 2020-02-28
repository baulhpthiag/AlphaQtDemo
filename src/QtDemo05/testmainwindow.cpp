#include "testmainwindow.h"
#include "ui_testmainwindow.h"

TestMainWindow::TestMainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TestMainWindow)
{
    ui->setupUi(this);
}

TestMainWindow::~TestMainWindow()
{
    delete ui;
}

void TestMainWindow::on_pushButton_clicked()
{

}
