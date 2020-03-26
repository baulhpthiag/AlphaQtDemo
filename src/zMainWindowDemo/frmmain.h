/****************************************************************************
**
** 说明： 此Demo是基于文件的相对路径，加载相关皮肤资源，相关文件在bin\skin目录下。
**
****************************************************************************/
#ifndef FRMMAIN_H
#define FRMMAIN_H

#include <QMainWindow>

namespace Ui {
class frmMain;
}

class frmMain : public QMainWindow
{
    Q_OBJECT

public:
    explicit frmMain(QWidget *parent = 0);
    ~frmMain();

protected:
    bool eventFilter(QObject *obj, QEvent *event);
    void changeEvent(QEvent*  event);

signals:
    // 主题切换信号
    void sigCurrentStyleIndex(int index);

private slots:
    void on_btnCloseMenu_clicked();

    void on_btnMaxMenu_clicked();

    void on_btnMinMenu_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_colorBox_currentIndexChanged(int index);

    void timerUpdate();

private:
    Ui::frmMain *ui;

    QPoint mousePoint;
    bool mousePressed;

    int progressValue;

    void InitStyle();
};

#endif // FRMMAIN_H
