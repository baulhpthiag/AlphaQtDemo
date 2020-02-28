#include "testmainwidget.h"
#include "ui_testmainwidget.h"

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
