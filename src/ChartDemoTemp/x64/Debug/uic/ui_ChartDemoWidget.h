/********************************************************************************
** Form generated from reading UI file 'ChartDemoWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHARTDEMOWIDGET_H
#define UI_CHARTDEMOWIDGET_H

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

class Ui_ChartDemoWidgetClass
{
public:
    QGridLayout *ChartDemoWidgetClassGridLayout;
    QWidget *rootWidget;
    QVBoxLayout *rootWidgetVerticalLayout;
    QWidget *topWidget;
    QHBoxLayout *horizontalLayout;
    QComboBox *comboBox;
    QSpacerItem *horizontalSpacer;
    QWidget *bottomWidget;

    void setupUi(QWidget *ChartDemoWidgetClass)
    {
        if (ChartDemoWidgetClass->objectName().isEmpty())
            ChartDemoWidgetClass->setObjectName(QStringLiteral("ChartDemoWidgetClass"));
        ChartDemoWidgetClass->resize(1000, 800);
        ChartDemoWidgetClassGridLayout = new QGridLayout(ChartDemoWidgetClass);
        ChartDemoWidgetClassGridLayout->setSpacing(10);
        ChartDemoWidgetClassGridLayout->setContentsMargins(11, 11, 11, 11);
        ChartDemoWidgetClassGridLayout->setObjectName(QStringLiteral("ChartDemoWidgetClassGridLayout"));
        ChartDemoWidgetClassGridLayout->setContentsMargins(0, 0, 0, 0);
        rootWidget = new QWidget(ChartDemoWidgetClass);
        rootWidget->setObjectName(QStringLiteral("rootWidget"));
        rootWidgetVerticalLayout = new QVBoxLayout(rootWidget);
        rootWidgetVerticalLayout->setSpacing(10);
        rootWidgetVerticalLayout->setContentsMargins(11, 11, 11, 11);
        rootWidgetVerticalLayout->setObjectName(QStringLiteral("rootWidgetVerticalLayout"));
        rootWidgetVerticalLayout->setContentsMargins(0, 0, 0, 0);
        topWidget = new QWidget(rootWidget);
        topWidget->setObjectName(QStringLiteral("topWidget"));
        horizontalLayout = new QHBoxLayout(topWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        comboBox = new QComboBox(topWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        horizontalLayout->addWidget(comboBox);

        horizontalSpacer = new QSpacerItem(904, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        rootWidgetVerticalLayout->addWidget(topWidget);

        bottomWidget = new QWidget(rootWidget);
        bottomWidget->setObjectName(QStringLiteral("bottomWidget"));

        rootWidgetVerticalLayout->addWidget(bottomWidget);

        rootWidgetVerticalLayout->setStretch(0, 1);
        rootWidgetVerticalLayout->setStretch(1, 10);

        ChartDemoWidgetClassGridLayout->addWidget(rootWidget, 0, 0, 1, 1);


        retranslateUi(ChartDemoWidgetClass);
        QObject::connect(comboBox, SIGNAL(currentIndexChanged(int)), ChartDemoWidgetClass, SLOT(comboBoxCurrentIndexChanged()));

        QMetaObject::connectSlotsByName(ChartDemoWidgetClass);
    } // setupUi

    void retranslateUi(QWidget *ChartDemoWidgetClass)
    {
        ChartDemoWidgetClass->setWindowTitle(QApplication::translate("ChartDemoWidgetClass", "ChartDemoWidget", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ChartDemoWidgetClass: public Ui_ChartDemoWidgetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHARTDEMOWIDGET_H
