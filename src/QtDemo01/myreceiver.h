#ifndef MYRECEIVER_H
#define MYRECEIVER_H

#include <QObject>

class MyReceiver : public QObject
{
    Q_OBJECT
public:
    explicit MyReceiver(QObject *parent = nullptr);

signals:

public slots:
    //返回值void
    void MySlot01();
    void MySlot01(QString string);

};





#endif // MYRECEIVER_H
