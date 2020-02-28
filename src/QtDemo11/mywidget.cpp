#include "mywidget.h"
#include "ui_mywidget.h"
#include <QDebug>
#include <QPainter>
#include "mywidget1.h"
#include <QMessageBox>
#include "mywidget2.h"

MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);

}

MyWidget::~MyWidget()
{
    delete ui;
}

void MyWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    //pen 设置边框线
    QPen pen(QColor(255,0,0));
    pen.setWidth(5);
    pen.setStyle(Qt::DotLine);
    painter.setPen(pen);

    //brush 设置填充内容
    QBrush brush(QColor(0,0,255));
    brush.setStyle(Qt::RadialGradientPattern);
    painter.setBrush(brush);



    painter.drawLine(QPoint(0,0),QPoint(50,50));
    painter.drawEllipse(QPoint(50,100),50,50);
    painter.drawRect(100,100,100,100);
    painter.drawText(QPoint(100,250),"text");


    //设置渲染 但效率低
    painter.setRenderHint(QPainter::Antialiasing);

    painter.drawRect(200,200,50,50);
    //从上个位置移动
    painter.translate(100,0);
    painter.save();
    painter.drawRect(200,200,50,50);
    //还原到原位置
    painter.restore();
    painter.drawRect(200,200,50,50);




}

void MyWidget::on_pushButton_clicked()
{
    MyWidget1 * myWidget1 = new MyWidget1();
    myWidget1->show();
}

void MyWidget::on_pushButton_2_clicked()
{
    MyWidget2 * myWidget2 = new MyWidget2();
    myWidget2->show();
}
