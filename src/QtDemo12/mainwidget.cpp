#include "mainwidget.h"
#include "ui_mainwidget.h"
#include "mywidget1.h"

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget)
{
    ui->setupUi(this);
}

MainWidget::~MainWidget()
{
    delete ui;
}

void MainWidget::on_pushButton_clicked()
{
    MyWidget1 * myWidget = new MyWidget1();
    myWidget->show();
}
