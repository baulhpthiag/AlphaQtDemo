#ifndef MYSENDER_H
#define MYSENDER_H

#include <QObject>

class MySender : public QObject
{
    Q_OBJECT
public:
    explicit MySender(QObject *parent = nullptr);

    void EmitMySignal01();
signals:
    //自定义信号
    //返回值void，可以有参数，可以重载，只需声明，不需实现，

    void MySignal01();
    void MySignal01(QString string);


public slots:
};



#endif // MYSENDER_H
