/********************************************************************************
** Form generated from reading UI file 'PointerDemoTempMainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POINTERDEMOTEMPMAINWINDOW_H
#define UI_POINTERDEMOTEMPMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PointerDemoTempMainWindowClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *PointerDemoTempMainWindowClass)
    {
        if (PointerDemoTempMainWindowClass->objectName().isEmpty())
            PointerDemoTempMainWindowClass->setObjectName(QStringLiteral("PointerDemoTempMainWindowClass"));
        PointerDemoTempMainWindowClass->resize(600, 400);
        menuBar = new QMenuBar(PointerDemoTempMainWindowClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        PointerDemoTempMainWindowClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(PointerDemoTempMainWindowClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        PointerDemoTempMainWindowClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(PointerDemoTempMainWindowClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        PointerDemoTempMainWindowClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(PointerDemoTempMainWindowClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        PointerDemoTempMainWindowClass->setStatusBar(statusBar);

        retranslateUi(PointerDemoTempMainWindowClass);

        QMetaObject::connectSlotsByName(PointerDemoTempMainWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *PointerDemoTempMainWindowClass)
    {
        PointerDemoTempMainWindowClass->setWindowTitle(QApplication::translate("PointerDemoTempMainWindowClass", "PointerDemoTempMainWindow", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class PointerDemoTempMainWindowClass: public Ui_PointerDemoTempMainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POINTERDEMOTEMPMAINWINDOW_H
