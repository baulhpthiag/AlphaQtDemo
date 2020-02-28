#include "mywidget.h"
#include "ui_mywidget.h"
#include <QTimer>


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

void MyWidget::timerEvent(QTimerEvent *event)
{
    if(event->timerId()==timer1)
    {
        ui->label->setText(QString::number(num1++));
    }
    else if(event->timerId() ==timer2)
    {
        ui->label2->setText(QString::number(num2++));
    }

}

void MyWidget::on_pushButton_clicked()
{
    timer1 = startTimer(100);

    timer2 = startTimer(500);

    timer3 = new QTimer(this);

    connect(timer3,&QTimer::timeout,this,&MyWidget::onTimeout);
    timer3->start(1000);
}


void MyWidget::on_pushButton_2_clicked()
{
    if(timer1!=-1){
        killTimer(timer1);
        num1 = 0;
        timer1 = -1;
        ui->label->setText("label");
    }

    if(timer2!=-1){
        killTimer(timer2);
        num2 = 0;
        timer2 = -1;
        ui->label2->setText("label2");
    }
    if(timer3!=nullptr){
        disconnect(timer3,&QTimer::timeout,this,&MyWidget::onTimeout);
        killTimer(timer3->timerId());
        num3 =0;
        timer3 = nullptr;
        ui->label3->setText("label3");

    }

}

void MyWidget::onTimeout()
{
    ui->label3->setText(QString::number(num3++));
}
