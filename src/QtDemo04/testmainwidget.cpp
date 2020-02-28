#include "testmainwidget.h"
#include "ui_testmainwidget.h"
#include <QDialog>
#include <QMessageBox>
#include <QDebug>
#include <QColorDialog>
#include <QFileDialog>
#include <QFontDialog>

TestMainWidget::TestMainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TestMainWidget)
{
    ui->setupUi(this);
}

TestMainWidget::~TestMainWidget()
{
    delete ui;
}

void TestMainWidget::on_pushButton_clicked()
{
    //模态对话框：不可对其他窗口操作

    QDialog dialog(this);
    dialog.resize(200,200);
    //阻塞在exec，直到关闭
    dialog.exec();
}

void TestMainWidget::on_pushButton_2_clicked()
{
    //非模态对话框：可对其他窗口操作
    //    //在栈上创建的对象，释放后会一闪消失
    //    QDialog dialog(this);
    //    dialog.resize(200,200);
    //    dialog.show();

    QDialog * dialog = new QDialog(this);
    dialog->resize(200,200);

    //由于在主窗口关闭之时才会释放子窗口，为防止多次打开子窗口占用内存，设置一旦关闭就释放该子窗口
    dialog->setAttribute(Qt::WA_DeleteOnClose);
    dialog->show();
}

void TestMainWidget::on_pushButton_3_clicked()
{
    //    //消息对话框
    //    QMessageBox * messageBox = new QMessageBox(this);
    //    messageBox->setText("messageBox");
    //    messageBox->show();

    //QMessageBox::information(this,"title","question");

    if(QMessageBox::Yes==QMessageBox::question(this,"title","question",QMessageBox::Yes|QMessageBox::No,QMessageBox::No))
    {
        qDebug()<<"yes";
    }
    else
    {
        qDebug()<<"no";
    }
}

void TestMainWidget::on_pushButton_4_clicked()
{
    QColor color = QColorDialog::getColor();
    qDebug()<<"rgb"<<color.red()<<color.green()<<color.blue();
}

void TestMainWidget::on_pushButton_5_clicked()
{
//    //选择文件，过滤到只能看到txt
//    QString file = QFileDialog::getOpenFileName(this,"caption","d:\\","*.txt");
//    qDebug()<<file;

    //选择文件夹
    QString directory =QFileDialog::getExistingDirectory(this,"caption","d:/");
    qDebug()<<directory;

}

void TestMainWidget::on_pushButton_6_clicked()
{
    bool flag;
    QFont font =QFontDialog::getFont(&flag,this);
    qDebug()<< "flag" << flag;
    qDebug()<<font.toString();

}
