#include "frmmessagebox.h"
#include "ui_frmmessagebox.h"
#include "commonhelper.h"

frmMessageBox::frmMessageBox(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::frmMessageBox)
{
    ui->setupUi(this);

    this->mousePressed = false;
    //设置窗体标题栏隐藏
    this->setWindowFlags(Qt::FramelessWindowHint);
    //设置窗体关闭时自动释放内存
    this->setAttribute(Qt::WA_DeleteOnClose);
    //关联关闭按钮
    connect(ui->btnCloseMenu, SIGNAL(clicked()), this, SLOT(close()));
    connect(ui->btnCancel, SIGNAL(clicked()), this, SLOT(close()));
    //窗体居中显示
    CommonHelper::FormInCenter(this);

    ui->lblTitle->installEventFilter(this);
}

frmMessageBox::~frmMessageBox()
{
    delete ui;
}

void frmMessageBox::SetMessage(const QString &msg, int type)
{
    if (type == 0) {
        ui->labIcoMain->setStyleSheet("border-image: url(:/skin/image/info.png);");
        ui->btnCancel->setVisible(false);
        ui->lblTitle->setText("提示");
    } else if (type == 1) {
        ui->labIcoMain->setStyleSheet("border-image: url(:/skin/image/question.png);");
        ui->lblTitle->setText("询问");
    } else if (type == 2) {
        ui->labIcoMain->setStyleSheet("border-image: url(:/skin/image/error.png);");
        ui->btnCancel->setVisible(false);
        ui->lblTitle->setText("错误");
    }

    ui->labInfo->setText(msg);
}

bool frmMessageBox::eventFilter(QObject *obj, QEvent *event)
{
    if (ui->lblTitle == obj)
    {
        if (event->type() == QEvent::MouseButtonPress)
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

void frmMessageBox::on_btnOk_clicked()
{
    done(1);
    this->close();
}
