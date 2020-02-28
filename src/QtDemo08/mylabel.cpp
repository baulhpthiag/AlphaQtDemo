#include "mylabel.h"
#include <QDebug>
#include <QPoint>
#include<QMouseEvent>

MyLabel::MyLabel(QWidget *parent) : QLabel(parent)
{
    this->setStyleSheet("background-color:rgb(38,119,175)");
    //设置鼠标追踪之后，鼠标移动事件就不需要鼠标按下，否则，鼠标移动事件需要先按下才能触发
    setMouseTracking(true);
}

void MyLabel::enterEvent(QEvent *event)
{
    qDebug()<<"enter";
}

void MyLabel::leaveEvent(QEvent *event)
{
    qDebug()<<"leave";
}

void MyLabel::mousePressEvent(QMouseEvent *ev)
{
    qDebug()<<"press";
}

void MyLabel::mouseMoveEvent(QMouseEvent *ev)
{
    QPoint p_ab = ev->globalPos();
    QPoint p_re = ev->pos();
    QString str = QString("%1 , %2").arg(p_ab.x()).arg(p_ab.y());
    QString str1 = QString("%1 , %2").arg(p_re.x()).arg(p_re.y());
    qDebug()<<"mouseMove"<<str <<str1;
}

void MyLabel::mouseReleaseEvent(QMouseEvent *ev)
{
    qDebug()<<"mouseRelease";
}

void MyLabel::wheelEvent(QWheelEvent *event)
{
    qDebug()<<"wheelEvent";
}

void MyLabel::moveEvent(QMoveEvent *event)
{
    qDebug()<<"moveEvent";
}
