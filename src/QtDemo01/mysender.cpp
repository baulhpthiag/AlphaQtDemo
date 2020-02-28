#include "mysender.h"
#include <QDebug>

MySender::MySender(QObject *parent) : QObject(parent)
{

}

void MySender::EmitMySignal01()
{
    qDebug() << "MySender::EmitMySignal01";
    emit this->MySignal01();
    emit this->MySignal01("one signal");
}
