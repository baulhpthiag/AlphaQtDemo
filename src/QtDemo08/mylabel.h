﻿#ifndef MYLABEL_H
#define MYLABEL_H

#include <QLabel>

class MyLabel : public QLabel
{
    Q_OBJECT
public:
    explicit MyLabel(QWidget *parent = nullptr);

    void enterEvent(QEvent *event);
    void leaveEvent(QEvent *event);

    void mousePressEvent(QMouseEvent *ev) ;
    void mouseMoveEvent(QMouseEvent *ev) ;
    void mouseReleaseEvent(QMouseEvent *ev) ;
    void wheelEvent(QWheelEvent *event);
     void moveEvent(QMoveEvent *event);
signals:

public slots:
};

#endif // MYLABEL_H
