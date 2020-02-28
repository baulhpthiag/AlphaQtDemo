#include "mywidget1.h"
#include "ui_mywidget1.h"
#include <QPainter>

MyWidget1::MyWidget1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget1)
{
    ui->setupUi(this);
    x = 100;
}

MyWidget1::~MyWidget1()
{
    delete ui;
}

void MyWidget1::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    x ++;
    //绘制图片
    painter.drawPixmap(x,100,200,200,QPixmap(":/res/1.jpg"));
}

void MyWidget1::on_pushButton_clicked()
{
    update();
}
