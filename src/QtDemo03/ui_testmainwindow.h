/********************************************************************************
** Form generated from reading UI file 'testmainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTMAINWINDOW_H
#define UI_TESTMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TestMainWindow
{
public:
    QAction *actionaction01;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menumenu01;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *TestMainWindow)
    {
        if (TestMainWindow->objectName().isEmpty())
            TestMainWindow->setObjectName(QStringLiteral("TestMainWindow"));
        TestMainWindow->resize(400, 300);
        actionaction01 = new QAction(TestMainWindow);
        actionaction01->setObjectName(QStringLiteral("actionaction01"));
        centralWidget = new QWidget(TestMainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        TestMainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(TestMainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 23));
        menumenu01 = new QMenu(menuBar);
        menumenu01->setObjectName(QStringLiteral("menumenu01"));
        TestMainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(TestMainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        TestMainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(TestMainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        TestMainWindow->setStatusBar(statusBar);

        menuBar->addAction(menumenu01->menuAction());
        menumenu01->addAction(actionaction01);
        mainToolBar->addAction(actionaction01);

        retranslateUi(TestMainWindow);

        QMetaObject::connectSlotsByName(TestMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *TestMainWindow)
    {
        TestMainWindow->setWindowTitle(QApplication::translate("TestMainWindow", "TestMainWindow", Q_NULLPTR));
        actionaction01->setText(QApplication::translate("TestMainWindow", "action01", Q_NULLPTR));
        menumenu01->setTitle(QApplication::translate("TestMainWindow", "menu01", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TestMainWindow: public Ui_TestMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTMAINWINDOW_H
