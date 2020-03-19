#include "mywidget.h"
#include <QPushButton>
#include <QDebug>
#include "mysender.h"
#include "myreceiver.h"
#include <QLabel>
//注释 ctrl + /
//自动对齐 ctrl + i


MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
{
    Method01();
    Method02();
    Method03();
    Method04();
}

MyWidget::~MyWidget()
{

}

void MyWidget::Method01()
{
//创建一个控件，绑定信号和槽

    //    //这种方式创建QPushButton失败
    //    QPushButton qPushButton;
    //    qPushButton.show();

    //    //这种方式创建QPushButton成功
    //    QPushButton * pushButton01 = new QPushButton;
    //    //show方式会让按钮在新的窗口中出现
    //    pushButton01->show();

    //这种方式创建QPushButton成功，
    QPushButton * pushButton02 = new QPushButton;
    //setParent方法，让按钮在当前窗口中出现，且按钮被加入的父对象的children列表里，父对象释放时，会先释放children表里的对象
    pushButton02->setParent(this);
    //设置button文本
    pushButton02->setText("TestButton02");
    //设置button位置
    pushButton02->move(100,100);
    //重置button大小
    pushButton02->resize(100,100);
    //绑定信号和槽,1，发送者，2信号，3接收者，4槽,即处理函数
    connect(pushButton02,&QPushButton::clicked,this,&MyWidget::Slot01);

    //设置窗口标题
    setWindowTitle("TestWindow");
    //设置固定窗口大小
    setFixedSize(500,400);
    //重置窗口大小
    resize(500,400);

    //在控制台打印信息
    qDebug()<< "mywidget::method01::qdebug";

    //qt的窗口坐标系，原点在左上角

}

void MyWidget::Slot01()
{
    qDebug()<< "mywidget::Slot01::qdebug";
}

void MyWidget::Method02()
{

    QPushButton *qPushButton03 = new QPushButton();
    qPushButton03->setParent(this);
    qPushButton03->move(100,200);
    qPushButton03->setText(QString::fromLocal8Bit("自定义信号和槽"));
    connect(qPushButton03,&QPushButton::clicked,this,&MyWidget::Slot02);

//    //断开连接
//    disconnect(qPushButton03,&QPushButton::clicked,this,&MyWidget::Slot02);
}

void MyWidget::Slot02()
{
//自定义信号和槽

    MySender * mysender = new MySender;
    mysender->setParent(this);

    MyReceiver * myReceiver = new MyReceiver;
    myReceiver->setParent(this);

    //发生重载时，采用函数指针传递
    void(MySender::*tempMySignal01)() = &MySender::MySignal01;
    void(MyReceiver::*tempMySlot01)() = &MyReceiver::MySlot01;

    void(MySender::*tempMySignal01overload)(QString) = &MySender::MySignal01;
    void(MyReceiver::*tempMySlot01overload)(QString) = &MyReceiver::MySlot01;

    //连接
    connect(mysender ,tempMySignal01,myReceiver,tempMySlot01);
    connect(mysender ,tempMySignal01overload,myReceiver,tempMySlot01overload);

    //触发该信号
    mysender->EmitMySignal01();


}

void MyWidget::Method03()
{
//信号连接信号


    QPushButton * qPushButton04 = new QPushButton();
    qPushButton04->setParent(this);
    qPushButton04->move(100,300);
    qPushButton04->setText(QString::fromLocal8Bit("信号连接信号"));



    MySender * mysender = new MySender;
    mysender->setParent(this);

    MyReceiver * myReceiver = new MyReceiver;
    myReceiver->setParent(this);

    //发生重载时，采用函数指针传递
	void(MySender::*tempMySignal01)() = &MySender::MySignal01;
	void(MyReceiver::*tempMySlot01)() = &MyReceiver::MySlot01;


    connect(qPushButton04,&QPushButton::clicked,mysender,tempMySignal01);
    //连接
    connect(mysender ,tempMySignal01,myReceiver,tempMySlot01);

}

void MyWidget::Method04()
{
    QLabel * label = new QLabel;
    label->setText("qlabel");
    label->setParent(this);

}







