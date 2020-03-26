/****************************************************************************
**
** 此文件用于实现跨平台自定义窗体移动、缩放，由于该类使用纯Qt实现，所以支持跨平台
**
** 接口说明：
** FramelessHelperPrivate
** 存储界面对应的数据集合，以及是否可移动、可缩放属性
**
** CursorPosCalculator
** 计算鼠标是否位于左、上、右、下、左上角、左下角、右上角、右下角
**
** WidgetData
** 更新鼠标样式、移动窗体、缩放窗体
**
** FramelessHelper
** 激活窗体、移除窗体、设置窗体移动、窗体缩放、橡皮筋移动、橡皮筋缩放、边框的宽度、标题栏高度等
**
****************************************************************************/
#ifndef FRAMELESS_HELPER_H
#define FRAMELESS_HELPER_H

#include <QObject>

class QWidget;
class FramelessHelperPrivate;

class FramelessHelper : public QObject
{
    Q_OBJECT

public:
    explicit FramelessHelper(QObject *parent = 0);
    ~FramelessHelper();
    // 激活窗体
    void activateOn(QWidget *topLevelWidget);
    // 移除窗体
    void removeFrom(QWidget *topLevelWidget);
    // 设置窗体移动
    void setWidgetMovable(bool movable);
    // 设置窗体缩放
    void setWidgetResizable(bool resizable);
    // 设置橡皮筋移动
    void setRubberBandOnMove(bool movable);
    // 设置橡皮筋缩放
    void setRubberBandOnResize(bool resizable);
    // 设置边框的宽度
    void setBorderWidth(uint width);
    // 设置标题栏高度
    void setTitleHeight(uint height);
    bool widgetResizable();
    bool widgetMovable();
    bool rubberBandOnMove();
    bool rubberBandOnResisze();
    uint borderWidth();
    uint titleHeight();

protected:
    // 事件过滤，进行移动、缩放等
    virtual bool eventFilter(QObject *obj, QEvent *event);

private:
    FramelessHelperPrivate *d;
};

#endif //FRAMELESS_HELPER_H
