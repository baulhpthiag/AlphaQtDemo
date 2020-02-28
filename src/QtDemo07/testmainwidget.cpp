#include "testmainwidget.h"
#include "ui_testmainwidget.h"

TestMainWidget::TestMainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TestMainWidget)
{
    ui->setupUi(this);
}

TestMainWidget::~TestMainWidget()
{
    delete ui;
}

void TestMainWidget::on_pushButton_clicked()
{
    ui->myWidget->setNum(0);
}

void TestMainWidget::on_pushButton_2_clicked()
{
    int i = ui->myWidget->getNum();

    //QString str = QString::(i, 10);
     QString str = QString("%1").arg(i);
    str.append(i);
    ui->label->setText(str);

}
