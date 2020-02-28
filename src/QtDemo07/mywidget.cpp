#include "mywidget.h"
#include "ui_mywidget.h"
#include <QSpinBox>
#include <QSlider>

MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);
    void (QSpinBox::* tempvalueChanged)(int) = &QSpinBox::valueChanged;

    connect(ui->spinBox,tempvalueChanged,ui->horizontalSlider,&QSlider::setValue);
    connect(ui->horizontalSlider,&QSlider::valueChanged,ui->spinBox,&QSpinBox::setValue);
}

MyWidget::~MyWidget()
{
    delete ui;
}

void MyWidget::setNum(int i)
{
    ui->spinBox->setValue(i);
}

int MyWidget::getNum()
{
    return ui->spinBox->value();

}


