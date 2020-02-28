#include "mywidget1.h"
#include "ui_mywidget1.h"
#include <QFileDialog>
#include <QFile>
#include <QTextCodec>
#include <QFileInfo>
#include <QDateTime>

MyWidget1::MyWidget1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget1)
{
    ui->setupUi(this);
}

MyWidget1::~MyWidget1()
{
    delete ui;
}

void MyWidget1::on_pushButton_clicked()
{
    QString path=QFileDialog::getOpenFileName(this,"打开文件","d:/");
    ui->lineEdit->setText(path);

    QFileInfo fileInfo(path);
    QString info ="";
    info.append("大小:"+QString::number(fileInfo.size())).append("\r");
    info.append("文件名:"+fileInfo.fileName()).append("\r");
    info.append("文件后缀:"+fileInfo.suffix()).append("\r");
    info.append("创建日期:"+fileInfo.created().toString("yyyy/MM/dd HH:mm:ss")).append("\r");
    info.append("最后修改日期:"+fileInfo.lastModified().toString("yyyy/MM/dd HH:mm:ss")).append("\r");
    ui->textBrowser->setText(info);
    //假如是gbk编码
    QTextCodec *codec = QTextCodec::codecForName("gbk");

    //QFile默认utf8格式
    QFile file(path);
    file.open(QIODevice::ReadOnly);
    QByteArray array = file.readAll();

//    QByteArray array1;
//    while(!file.atEnd())
//    {
//        array1+=file.readLine();
//    }

    //gbk转码
    QString content = codec->toUnicode(array);

    ui->textEdit->setText(content);

    file.close();

//    //写
//    file.open(QIODevice::Append);
//    file.write("写入");
//    file.close();
}
