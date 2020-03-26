#include "frmmain.h"
#include "ui_frmmain.h"
#include "commonhelper.h"
#include "frameless_helper.h"

frmMain::frmMain(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::frmMain)
{
    ui->setupUi(this);

    progressValue = 0;
    InitStyle();

    connect(ui->colorBox, SIGNAL(currentIndexChanged(int)), this, SLOT(on_colorBox_currentIndexChanged(int)));
}

frmMain::~frmMain()
{
    delete ui;
}

void frmMain::InitStyle()
{
    mousePressed = false;

    //安装事件监听器,让标题栏识别鼠标双击
    ui->lblTitle->installEventFilter(this);

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(timerUpdate()));
    timer->start(500);

    this->setWindowFlags(Qt::FramelessWindowHint
                         | Qt::WindowSystemMenuHint
                         | Qt::WindowMinMaxButtonsHint);

    FramelessHelper *pHelper = new FramelessHelper(this);
    pHelper->activateOn(this);  //激活当前窗体
    pHelper->setTitleHeight(ui->wgtTitleBar->height());  //设置窗体的标题栏高度
}

bool frmMain::eventFilter(QObject *obj, QEvent *event)
{
    if (ui->lblTitle == obj)
    {
        if (event->type() == QEvent::MouseButtonDblClick)
        {
            QMouseEvent *mouseEvent = dynamic_cast<QMouseEvent*>(event);
            if (mouseEvent->button() == Qt::LeftButton)
            {
                this->on_btnMaxMenu_clicked();
                return true;
            }
        }

        else if (event->type() == QEvent::MouseButtonPress)
        {
            QMouseEvent *mouseEvent = dynamic_cast<QMouseEvent*>(event);

            if (mouseEvent->button() == Qt::LeftButton)
            {
                mousePressed = true;
                mousePoint = mouseEvent->globalPos() - pos();
                mouseEvent->accept();

                return true;
            }
        }

        else if (event->type() == QEvent::MouseMove)
        {
            QMouseEvent *mouseEvent = dynamic_cast<QMouseEvent*>(event);

            if (mousePressed&& this->windowState() != Qt::WindowMaximized)
            {
                if (mouseEvent->globalY() <= qApp->desktop()->availableGeometry().bottom())
                {
                    move(mouseEvent->globalPos() - mousePoint);
                    mouseEvent->accept();
                }
                else
                {
                    qApp->desktop()->cursor().setPos(
                                qApp->desktop()->cursor().pos().x(),
                                qApp->desktop()->availableGeometry().bottom()
                                );
                }

                return true;
            }
        }

        else if (event->type() == QEvent::MouseButtonRelease)
        {
            QMouseEvent *mouseEvent = dynamic_cast<QMouseEvent*>(event);

            if (mouseEvent->button() == Qt::LeftButton)
            {
                mousePressed = false;
                mouseEvent->accept();

                return true;
            }
        }
    }
    return QObject::eventFilter(obj, event);
}

void frmMain::changeEvent(QEvent *event)
{
    if(event->type() == QEvent::WindowStateChange)
    {
        if (this->windowState() == Qt::WindowMaximized)
        {
            // 设置窗口最大化不遮盖任务栏
            this->setGeometry(qApp->desktop()->availableGeometry());
            ui->btnMaxMenu->setToolTip("还原");
            ui->btnMaxMenu->setProperty("maximizeProperty", "restore");
            ui->btnMaxMenu->setStyle(QApplication::style());
        }
        else if (this->windowState() == Qt::WindowNoState)
        {
            setWindowState(Qt::WindowNoState);
            ui->btnMaxMenu->setToolTip("最大化");
            ui->btnMaxMenu->setProperty("maximizeProperty", "maximize");
            ui->btnMaxMenu->setStyle(QApplication::style());
        }
    }
}

void frmMain::on_btnCloseMenu_clicked()
{
    qApp->exit();
}

void frmMain::on_btnMaxMenu_clicked()
{
    if (isMaximized()) showNormal();
    else showMaximized();
}

void frmMain::on_btnMinMenu_clicked()
{
    showMinimized();
}

void frmMain::on_pushButton_clicked()
{
    CommonHelper::ShowMessageBoxInfo("信息1!");
}

void frmMain::on_pushButton_2_clicked()
{
    int result = CommonHelper::ShowMessageBoxQuesion("是否确定当前操作?");
    if (result == 1) {
        CommonHelper::ShowMessageBoxInfo("操作成功!");
    } else {
        CommonHelper::ShowMessageBoxInfo("当前操作已取消!");
    }
}

void frmMain::on_pushButton_3_clicked()
{
    CommonHelper::ShowMessageBoxError("未知错误 !");
}

void frmMain::on_colorBox_currentIndexChanged(int index)
{
    switch(index) {
    case 0: CommonHelper::SetStyle("default"); break;
    case 1: CommonHelper::SetStyle("navy"); break;
    case 2: CommonHelper::SetStyle("green"); break;
    case 3: CommonHelper::SetStyle("dark"); break;
    default: break;
    }
}

void frmMain::timerUpdate()
{
    if (progressValue < 100 && progressValue >= 0)
    {
        progressValue++;
        ui->progressBar->setValue(progressValue);
    }
    if (progressValue == 100){
        progressValue = 0;
    }
}
