#include "myreceiver.h"
#include <QDebug>
MyReceiver::MyReceiver(QObject *parent) : QObject(parent)
{

}
void MyReceiver::MySlot01()
{
    qDebug()<<"myreceiver::mySlot01()";
}
void MyReceiver::MySlot01(QString string)
{
    //QString转char*
    qDebug()<<"myreceiver::mySlot01(string) string = "<<string.toUtf8().data();
}
