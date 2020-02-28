#ifndef MYLABEL_H
#define MYLABEL_H

#include <QWidget>
#include <QLabel>

class MyLabel : public QLabel
{
    Q_OBJECT
public:
    explicit MyLabel(QWidget *parent = nullptr);
    bool event(QEvent *e);
    void mousePressEvent(QMouseEvent *ev);
    void mouseReleaseEvent(QMouseEvent *ev);
    bool eventFilter(QObject *,QEvent *);
signals:

public slots:
};

#endif // MYLABEL_H
