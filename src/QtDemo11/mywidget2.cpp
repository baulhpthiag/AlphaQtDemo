#include "mywidget2.h"
#include "ui_mywidget2.h"
#include <QPixmap>
#include <QPainter>
#include <QImage>
#include <QRgb>
#include <QPicture>

MyWidget2::MyWidget2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget2)
{
    ui->setupUi(this);
    //QPixMap
    //QBitMap,QPixMap的子类，色深为1，
    //QImage，可以设置图像的像素
    //QPicture，可以重现QPainter的命令



}

MyWidget2::~MyWidget2()
{
    delete ui;
}

void MyWidget2::on_pushButton_clicked()
{
    QPixmap  pixmap(300,300) ;
    QPainter  painter(&pixmap);
    pixmap.fill(QColor(0,255,0));
    painter.drawEllipse(100,100,100,100);
    pixmap.save("d:/pix.jpg");

}

void MyWidget2::on_pushButton_2_clicked()
{
    QImage image(300,300,QImage::Format_RGB32);
    image.fill(QColor(0,222,0));

    QPainter painter(&image);
    painter.drawEllipse(100,100,100,100);
    image.save("d:/img.jpg");


}

void MyWidget2::on_pushButton_3_clicked()
{
//    QImage image;
//    image.load(":/res/1.jpg");
    QImage image(300,300,QImage::Format_RGB32);
    QPainter painter(&image);

    image.fill(QColor(0,0,0));

    for (int i=0;i<20;i++) {
        for (int j=0;j<20;j++) {
            image.setPixel(i,j,qRgb(255,0,0));
        }

    }

    image.save("d:/image1.jpg");

}

void MyWidget2::on_pushButton_4_clicked()
{
    QPicture picture;
    QPainter painter;
    painter.begin(&picture);

    painter.drawEllipse(100,100,100,100);

    painter.end();
    picture.save("d:/picture.mao");


}

void MyWidget2::on_pushButton_5_clicked()
{
    flag = true;
     QPainter painter;

    mypicture.load("d:/picture.mao");

    update();



}

void MyWidget2::paintEvent(QPaintEvent *event)
{
    if(flag)
    {
        QPainter painter(this);
        painter.drawPicture(0,0,mypicture);
    }


}
