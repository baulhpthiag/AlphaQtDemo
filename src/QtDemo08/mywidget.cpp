#include "mywidget.h"
#include <QDebug>

MyWidget::MyWidget(QWidget *parent) : QWidget(parent)
{
    this->setStyleSheet("background-color:black");

    //this->setStyleSheet("background-color:rgb(255, 23, 116)");


}

void MyWidget::enterEvent(QEvent *event)
{
    qDebug()<< "enter";
}

void MyWidget::leaveEvent(QEvent *event)
{
    qDebug()<<"leave";
}
