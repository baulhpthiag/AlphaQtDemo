/********************************************************************************
** Form generated from reading UI file 'ChartDemo02Widget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHARTDEMO02WIDGET_H
#define UI_CHARTDEMO02WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChartDemo02Widget
{
public:
    QGridLayout *ChartDemo02WidgetGridLayout;
    QWidget *rootWidget;
    QVBoxLayout *verticalLayout;
    QWidget *topWidget;
    QPushButton *pushButton;
    QWidget *bottomWidget;

    void setupUi(QWidget *ChartDemo02Widget)
    {
        if (ChartDemo02Widget->objectName().isEmpty())
            ChartDemo02Widget->setObjectName(QStringLiteral("ChartDemo02Widget"));
        ChartDemo02Widget->resize(1000, 800);
        ChartDemo02WidgetGridLayout = new QGridLayout(ChartDemo02Widget);
        ChartDemo02WidgetGridLayout->setSpacing(10);
        ChartDemo02WidgetGridLayout->setContentsMargins(11, 11, 11, 11);
        ChartDemo02WidgetGridLayout->setObjectName(QStringLiteral("ChartDemo02WidgetGridLayout"));
        ChartDemo02WidgetGridLayout->setContentsMargins(0, 0, 0, 0);
        rootWidget = new QWidget(ChartDemo02Widget);
        rootWidget->setObjectName(QStringLiteral("rootWidget"));
        verticalLayout = new QVBoxLayout(rootWidget);
        verticalLayout->setSpacing(10);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        topWidget = new QWidget(rootWidget);
        topWidget->setObjectName(QStringLiteral("topWidget"));
        pushButton = new QPushButton(topWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(30, 30, 75, 23));

        verticalLayout->addWidget(topWidget);

        bottomWidget = new QWidget(rootWidget);
        bottomWidget->setObjectName(QStringLiteral("bottomWidget"));

        verticalLayout->addWidget(bottomWidget);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 10);

        ChartDemo02WidgetGridLayout->addWidget(rootWidget, 0, 0, 1, 1);


        retranslateUi(ChartDemo02Widget);

        QMetaObject::connectSlotsByName(ChartDemo02Widget);
    } // setupUi

    void retranslateUi(QWidget *ChartDemo02Widget)
    {
        ChartDemo02Widget->setWindowTitle(QApplication::translate("ChartDemo02Widget", "ChartDemo02Widget", Q_NULLPTR));
        pushButton->setText(QApplication::translate("ChartDemo02Widget", "PushButton", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ChartDemo02Widget: public Ui_ChartDemo02Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHARTDEMO02WIDGET_H
