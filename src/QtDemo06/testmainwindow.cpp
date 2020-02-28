#include "testmainwindow.h"
#include "ui_testmainwindow.h"
#include <QDebug>
#include <QListWidget>
#include <QListWidgetItem>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QMovie>

TestMainWindow::TestMainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TestMainWindow)
{
    ui->setupUi(this);

    //设置静态图片
    QPixmap * pixMap = new QPixmap(":/icon/timg.jpg");
    pixMap->scaled(ui->labelPixMap->size(), Qt::KeepAspectRatio);
    ui->labelPixMap->setScaledContents(true);
    ui->labelPixMap->setPixmap(*pixMap);

    //设置动态图片

    QMovie * movie = new QMovie(":/icon/1.gif");

    movie->setScaledSize(ui->movieLabel->size());
    ui->movieLabel->setScaledContents(true);
    ui->movieLabel->setMovie(movie);
    movie->start();

}

TestMainWindow::~TestMainWindow()
{
    delete ui;
}

void TestMainWindow::on_pushButton_2_clicked()
{
    QListWidgetItem * item = new QListWidgetItem("3");
    ui->listWidget->addItem(item);
}

void TestMainWindow::on_checkBox_stateChanged(int arg1)
{
    qDebug()<<arg1;
}

void TestMainWindow::on_checkBox_2_stateChanged(int arg1)
{
    qDebug()<<arg1;

}

void TestMainWindow::on_pushButton_3_clicked()
{
    QTreeWidgetItem * item = new QTreeWidgetItem(QStringList()<<"a");
    ui->treeWidget->addTopLevelItem(item);
     QTreeWidgetItem * child = new QTreeWidgetItem(QStringList()<<"a1");
    item->addChild(child);
}

void TestMainWindow::on_pushButton_4_clicked()
{
    ui->tableWidget->setColumnCount(3);
    //更改表头
    ui->tableWidget->setHorizontalHeaderLabels(QStringList()<<"1"<<"2"<<"3");

    ui->tableWidget->setItem(1,1,new QTableWidgetItem("1-1"));
    ui->tableWidget->setItem(0,0,new QTableWidgetItem("0-0"));
}

void TestMainWindow::on_pushButton_7_clicked()
{

    ui->stackedWidget->setCurrentIndex(0);
}
