/********************************************************************************
** Form generated from reading UI file 'ThreadDemo0.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_THREADDEMO0_H
#define UI_THREADDEMO0_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ThreadDemo0
{
public:

    void setupUi(QWidget *ThreadDemo0)
    {
        if (ThreadDemo0->objectName().isEmpty())
            ThreadDemo0->setObjectName(QStringLiteral("ThreadDemo0"));
        ThreadDemo0->resize(400, 300);

        retranslateUi(ThreadDemo0);

        QMetaObject::connectSlotsByName(ThreadDemo0);
    } // setupUi

    void retranslateUi(QWidget *ThreadDemo0)
    {
        ThreadDemo0->setWindowTitle(QApplication::translate("ThreadDemo0", "ThreadDemo0", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ThreadDemo0: public Ui_ThreadDemo0 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_THREADDEMO0_H
