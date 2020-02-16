/********************************************************************************
** Form generated from reading UI file 'JsonDemoWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JSONDEMOWIDGET_H
#define UI_JSONDEMOWIDGET_H

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

class Ui_JsonDemoWidgetClass
{
public:
    QGridLayout *JsonDemoWidgetClassGridLayout;
    QWidget *rootWidget;
    QVBoxLayout *rootWidgetVerticalLayout;
    QWidget *topWidget;
    QHBoxLayout *topWidgetHorizontalLayout;
    QComboBox *comboBox;
    QSpacerItem *horizontalSpacer;
    QWidget *bottomWidget;

    void setupUi(QWidget *JsonDemoWidgetClass)
    {
        if (JsonDemoWidgetClass->objectName().isEmpty())
            JsonDemoWidgetClass->setObjectName(QStringLiteral("JsonDemoWidgetClass"));
        JsonDemoWidgetClass->resize(1000, 800);
        JsonDemoWidgetClassGridLayout = new QGridLayout(JsonDemoWidgetClass);
        JsonDemoWidgetClassGridLayout->setSpacing(10);
        JsonDemoWidgetClassGridLayout->setContentsMargins(11, 11, 11, 11);
        JsonDemoWidgetClassGridLayout->setObjectName(QStringLiteral("JsonDemoWidgetClassGridLayout"));
        JsonDemoWidgetClassGridLayout->setContentsMargins(0, 0, 0, 0);
        rootWidget = new QWidget(JsonDemoWidgetClass);
        rootWidget->setObjectName(QStringLiteral("rootWidget"));
        rootWidgetVerticalLayout = new QVBoxLayout(rootWidget);
        rootWidgetVerticalLayout->setSpacing(10);
        rootWidgetVerticalLayout->setContentsMargins(11, 11, 11, 11);
        rootWidgetVerticalLayout->setObjectName(QStringLiteral("rootWidgetVerticalLayout"));
        rootWidgetVerticalLayout->setContentsMargins(0, 0, 0, 0);
        topWidget = new QWidget(rootWidget);
        topWidget->setObjectName(QStringLiteral("topWidget"));
        topWidgetHorizontalLayout = new QHBoxLayout(topWidget);
        topWidgetHorizontalLayout->setSpacing(6);
        topWidgetHorizontalLayout->setContentsMargins(11, 11, 11, 11);
        topWidgetHorizontalLayout->setObjectName(QStringLiteral("topWidgetHorizontalLayout"));
        comboBox = new QComboBox(topWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        topWidgetHorizontalLayout->addWidget(comboBox);

        horizontalSpacer = new QSpacerItem(904, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        topWidgetHorizontalLayout->addItem(horizontalSpacer);


        rootWidgetVerticalLayout->addWidget(topWidget);

        bottomWidget = new QWidget(rootWidget);
        bottomWidget->setObjectName(QStringLiteral("bottomWidget"));

        rootWidgetVerticalLayout->addWidget(bottomWidget);

        rootWidgetVerticalLayout->setStretch(0, 1);
        rootWidgetVerticalLayout->setStretch(1, 10);

        JsonDemoWidgetClassGridLayout->addWidget(rootWidget, 0, 0, 1, 1);


        retranslateUi(JsonDemoWidgetClass);
        QObject::connect(comboBox, SIGNAL(currentIndexChanged(int)), JsonDemoWidgetClass, SLOT(comboBoxCurrentIndexChanged()));

        QMetaObject::connectSlotsByName(JsonDemoWidgetClass);
    } // setupUi

    void retranslateUi(QWidget *JsonDemoWidgetClass)
    {
        JsonDemoWidgetClass->setWindowTitle(QApplication::translate("JsonDemoWidgetClass", "JsonDemoWidget", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class JsonDemoWidgetClass: public Ui_JsonDemoWidgetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JSONDEMOWIDGET_H
