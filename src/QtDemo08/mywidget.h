#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>

class MyWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MyWidget(QWidget *parent = nullptr);

    void enterEvent(QEvent *event);
    void leaveEvent(QEvent *event);
signals:

public slots:
};

#endif // MYWIDGET_H
