#include "mylabel.h"
#include <QDebug>
#include <QEvent>

MyLabel::MyLabel(QWidget *parent) : QLabel(parent)
{

    this->setStyleSheet("background-color:green");
    //一个事件产生后，先经过事件拦截器，然后进入event中，然后交给指定的事件处理
    this->installEventFilter(this);


}
bool MyLabel::eventFilter(QObject * object, QEvent * event)
{
    if(event->type() == QEvent::Wheel)
    {
        qDebug()<<"MyLabel::eventFilter event->type() == QEvent::Wheel";
        return true;
    }
    return QLabel::eventFilter(object,event);
}

bool MyLabel::event(QEvent *e)
{
    //    //强制类型转换
    //    QMouseEvent * ev = static_cast<QMouseEvent *>(e);


    //在event中拦截，返回true，就不会交给特定的事件处理
    if(e->type() == QEvent::MouseButtonPress)
    {
        qDebug()<<"MyLabel::event e->type() == QEvent::MouseButtonPress";
        return true;
    }

    return QLabel::event(e);
}

void MyLabel::mousePressEvent(QMouseEvent *ev)
{

    qDebug()<<"MyLabel::mousePressEvent";
}

void MyLabel::mouseReleaseEvent(QMouseEvent *ev)
{

    qDebug()<<"MyLabel::mouseReleaseEvent";
}


