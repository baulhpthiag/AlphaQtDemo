/********************************************************************************
** Form generated from reading UI file 'MainWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWIDGET_H
#define UI_MAINWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWidgetClass
{
public:
    QPushButton *pushButton;
    QLabel *label_winx;
    QLabel *label_winy;
    QLabel *label_imgx;
    QLabel *label_imgy;
    QLabel *label_scale;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;

    void setupUi(QWidget *MainWidgetClass)
    {
        if (MainWidgetClass->objectName().isEmpty())
            MainWidgetClass->setObjectName(QStringLiteral("MainWidgetClass"));
        MainWidgetClass->resize(938, 624);
        pushButton = new QPushButton(MainWidgetClass);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(30, 30, 75, 23));
        label_winx = new QLabel(MainWidgetClass);
        label_winx->setObjectName(QStringLiteral("label_winx"));
        label_winx->setGeometry(QRect(370, 220, 54, 21));
        label_winy = new QLabel(MainWidgetClass);
        label_winy->setObjectName(QStringLiteral("label_winy"));
        label_winy->setGeometry(QRect(490, 220, 54, 20));
        label_imgx = new QLabel(MainWidgetClass);
        label_imgx->setObjectName(QStringLiteral("label_imgx"));
        label_imgx->setGeometry(QRect(370, 260, 54, 12));
        label_imgy = new QLabel(MainWidgetClass);
        label_imgy->setObjectName(QStringLiteral("label_imgy"));
        label_imgy->setGeometry(QRect(490, 260, 54, 12));
        label_scale = new QLabel(MainWidgetClass);
        label_scale->setObjectName(QStringLiteral("label_scale"));
        label_scale->setGeometry(QRect(370, 300, 54, 12));
        label = new QLabel(MainWidgetClass);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(320, 220, 31, 16));
        label_2 = new QLabel(MainWidgetClass);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(440, 220, 31, 16));
        label_3 = new QLabel(MainWidgetClass);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(320, 260, 31, 16));
        label_4 = new QLabel(MainWidgetClass);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(440, 260, 31, 16));
        label_5 = new QLabel(MainWidgetClass);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(320, 300, 31, 16));

        retranslateUi(MainWidgetClass);
        QObject::connect(pushButton, SIGNAL(clicked()), MainWidgetClass, SLOT(openImage()));

        QMetaObject::connectSlotsByName(MainWidgetClass);
    } // setupUi

    void retranslateUi(QWidget *MainWidgetClass)
    {
        MainWidgetClass->setWindowTitle(QApplication::translate("MainWidgetClass", "MainWidget", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWidgetClass", "openImage", Q_NULLPTR));
        label_winx->setText(QApplication::translate("MainWidgetClass", "TextLabel", Q_NULLPTR));
        label_winy->setText(QApplication::translate("MainWidgetClass", "TextLabel", Q_NULLPTR));
        label_imgx->setText(QApplication::translate("MainWidgetClass", "TextLabel", Q_NULLPTR));
        label_imgy->setText(QApplication::translate("MainWidgetClass", "TextLabel", Q_NULLPTR));
        label_scale->setText(QApplication::translate("MainWidgetClass", "TextLabel", Q_NULLPTR));
        label->setText(QApplication::translate("MainWidgetClass", "winx", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWidgetClass", "winy", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWidgetClass", "imgx", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWidgetClass", "imgy", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWidgetClass", "scale", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWidgetClass: public Ui_MainWidgetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWIDGET_H
