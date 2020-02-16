/********************************************************************************
** Form generated from reading UI file 'ChartDemo01Widget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHARTDEMO01WIDGET_H
#define UI_CHARTDEMO01WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChartDemo01Widget
{
public:
    QGridLayout *gridLayout;
    QWidget *rootWidget;
    QVBoxLayout *verticalLayout;
    QWidget *topWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *updatePieChartButton;
    QSpacerItem *horizontalSpacer;
    QComboBox *themeComboBox;
    QComboBox *animationComboBox;
    QComboBox *legendComboBox;
    QWidget *bottomWidget;

    void setupUi(QWidget *ChartDemo01Widget)
    {
        if (ChartDemo01Widget->objectName().isEmpty())
            ChartDemo01Widget->setObjectName(QStringLiteral("ChartDemo01Widget"));
        ChartDemo01Widget->resize(1000, 800);
        gridLayout = new QGridLayout(ChartDemo01Widget);
        gridLayout->setSpacing(10);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        rootWidget = new QWidget(ChartDemo01Widget);
        rootWidget->setObjectName(QStringLiteral("rootWidget"));
        rootWidget->setStyleSheet(QStringLiteral(""));
        verticalLayout = new QVBoxLayout(rootWidget);
        verticalLayout->setSpacing(10);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        topWidget = new QWidget(rootWidget);
        topWidget->setObjectName(QStringLiteral("topWidget"));
        horizontalLayout = new QHBoxLayout(topWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        updatePieChartButton = new QPushButton(topWidget);
        updatePieChartButton->setObjectName(QStringLiteral("updatePieChartButton"));

        horizontalLayout->addWidget(updatePieChartButton);

        horizontalSpacer = new QSpacerItem(898, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        themeComboBox = new QComboBox(topWidget);
        themeComboBox->setObjectName(QStringLiteral("themeComboBox"));

        horizontalLayout->addWidget(themeComboBox);

        animationComboBox = new QComboBox(topWidget);
        animationComboBox->setObjectName(QStringLiteral("animationComboBox"));

        horizontalLayout->addWidget(animationComboBox);

        legendComboBox = new QComboBox(topWidget);
        legendComboBox->setObjectName(QStringLiteral("legendComboBox"));

        horizontalLayout->addWidget(legendComboBox);


        verticalLayout->addWidget(topWidget);

        bottomWidget = new QWidget(rootWidget);
        bottomWidget->setObjectName(QStringLiteral("bottomWidget"));

        verticalLayout->addWidget(bottomWidget);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 10);

        gridLayout->addWidget(rootWidget, 0, 0, 1, 1);


        retranslateUi(ChartDemo01Widget);
        QObject::connect(updatePieChartButton, SIGNAL(clicked()), ChartDemo01Widget, SLOT(updatePieChartButtonClicked()));
        QObject::connect(themeComboBox, SIGNAL(currentIndexChanged(int)), ChartDemo01Widget, SLOT(themeComboBoxCurrentIndexChanged()));
        QObject::connect(animationComboBox, SIGNAL(currentIndexChanged(int)), ChartDemo01Widget, SLOT(animationComboBoxCurrentIndexChanged()));
        QObject::connect(legendComboBox, SIGNAL(currentIndexChanged(int)), ChartDemo01Widget, SLOT(legendComboBoxCurrentIndexChanged()));

        QMetaObject::connectSlotsByName(ChartDemo01Widget);
    } // setupUi

    void retranslateUi(QWidget *ChartDemo01Widget)
    {
        ChartDemo01Widget->setWindowTitle(QApplication::translate("ChartDemo01Widget", "ChartDemo01Widget", Q_NULLPTR));
        updatePieChartButton->setText(QApplication::translate("ChartDemo01Widget", "\346\233\264\346\224\271pie\346\225\260\346\215\256", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ChartDemo01Widget: public Ui_ChartDemo01Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHARTDEMO01WIDGET_H
