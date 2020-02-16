/********************************************************************************
** Form generated from reading UI file 'DatabaseDemoWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATABASEDEMOWIDGET_H
#define UI_DATABASEDEMOWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DatabaseDemoWidgetClass
{
public:
    QGridLayout *DatabaseDemoWidgetLayout;
    QWidget *rootWidget;
    QVBoxLayout *rootWidgetLayout;
    QWidget *topWidget;
    QHBoxLayout *topWidgetLayout;
    QComboBox *comboBox;
    QSpacerItem *horizontalSpacer;
    QWidget *bottomWidget;

    void setupUi(QWidget *DatabaseDemoWidgetClass)
    {
        if (DatabaseDemoWidgetClass->objectName().isEmpty())
            DatabaseDemoWidgetClass->setObjectName(QStringLiteral("DatabaseDemoWidgetClass"));
        DatabaseDemoWidgetClass->resize(1000, 800);
        DatabaseDemoWidgetLayout = new QGridLayout(DatabaseDemoWidgetClass);
        DatabaseDemoWidgetLayout->setSpacing(10);
        DatabaseDemoWidgetLayout->setContentsMargins(11, 11, 11, 11);
        DatabaseDemoWidgetLayout->setObjectName(QStringLiteral("DatabaseDemoWidgetLayout"));
        DatabaseDemoWidgetLayout->setContentsMargins(10, 10, 10, 10);
        rootWidget = new QWidget(DatabaseDemoWidgetClass);
        rootWidget->setObjectName(QStringLiteral("rootWidget"));
        rootWidgetLayout = new QVBoxLayout(rootWidget);
        rootWidgetLayout->setSpacing(10);
        rootWidgetLayout->setContentsMargins(11, 11, 11, 11);
        rootWidgetLayout->setObjectName(QStringLiteral("rootWidgetLayout"));
        rootWidgetLayout->setContentsMargins(0, 0, 0, 0);
        topWidget = new QWidget(rootWidget);
        topWidget->setObjectName(QStringLiteral("topWidget"));
        topWidgetLayout = new QHBoxLayout(topWidget);
        topWidgetLayout->setSpacing(6);
        topWidgetLayout->setContentsMargins(11, 11, 11, 11);
        topWidgetLayout->setObjectName(QStringLiteral("topWidgetLayout"));
        comboBox = new QComboBox(topWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        topWidgetLayout->addWidget(comboBox);

        horizontalSpacer = new QSpacerItem(884, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        topWidgetLayout->addItem(horizontalSpacer);


        rootWidgetLayout->addWidget(topWidget);

        bottomWidget = new QWidget(rootWidget);
        bottomWidget->setObjectName(QStringLiteral("bottomWidget"));

        rootWidgetLayout->addWidget(bottomWidget);

        rootWidgetLayout->setStretch(0, 1);
        rootWidgetLayout->setStretch(1, 10);

        DatabaseDemoWidgetLayout->addWidget(rootWidget, 0, 0, 1, 1);


        retranslateUi(DatabaseDemoWidgetClass);
        QObject::connect(comboBox, SIGNAL(currentIndexChanged(int)), DatabaseDemoWidgetClass, SLOT(comboBoxCurrentIndexChanged()));

        QMetaObject::connectSlotsByName(DatabaseDemoWidgetClass);
    } // setupUi

    void retranslateUi(QWidget *DatabaseDemoWidgetClass)
    {
        DatabaseDemoWidgetClass->setWindowTitle(QApplication::translate("DatabaseDemoWidgetClass", "DatabaseDemoWidget", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DatabaseDemoWidgetClass: public Ui_DatabaseDemoWidgetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATABASEDEMOWIDGET_H
