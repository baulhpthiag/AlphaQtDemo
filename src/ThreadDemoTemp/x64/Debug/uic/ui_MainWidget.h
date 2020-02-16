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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWidget
{
public:
    QGridLayout *mainWidgetLayout;
    QWidget *rootWidget;
    QVBoxLayout *rootWidgetLayout;
    QWidget *topWidget;
    QHBoxLayout *topWidgetLayout;
    QComboBox *comboBox;
    QPushButton *startButton;
    QPushButton *threadAHoverButton;
    QPushButton *threadAStopButton;
    QSpacerItem *horizontalSpacer;
    QWidget *bottomWidget;
    QGridLayout *bottomWidgetLayout;
    QTextBrowser *textBrowser;

    void setupUi(QWidget *MainWidget)
    {
        if (MainWidget->objectName().isEmpty())
            MainWidget->setObjectName(QStringLiteral("MainWidget"));
        MainWidget->resize(1000, 800);
        mainWidgetLayout = new QGridLayout(MainWidget);
        mainWidgetLayout->setSpacing(0);
        mainWidgetLayout->setContentsMargins(11, 11, 11, 11);
        mainWidgetLayout->setObjectName(QStringLiteral("mainWidgetLayout"));
        mainWidgetLayout->setContentsMargins(0, 0, 0, 0);
        rootWidget = new QWidget(MainWidget);
        rootWidget->setObjectName(QStringLiteral("rootWidget"));
        rootWidgetLayout = new QVBoxLayout(rootWidget);
        rootWidgetLayout->setSpacing(10);
        rootWidgetLayout->setContentsMargins(11, 11, 11, 11);
        rootWidgetLayout->setObjectName(QStringLiteral("rootWidgetLayout"));
        rootWidgetLayout->setContentsMargins(0, 0, 0, 0);
        topWidget = new QWidget(rootWidget);
        topWidget->setObjectName(QStringLiteral("topWidget"));
        topWidgetLayout = new QHBoxLayout(topWidget);
        topWidgetLayout->setSpacing(10);
        topWidgetLayout->setContentsMargins(11, 11, 11, 11);
        topWidgetLayout->setObjectName(QStringLiteral("topWidgetLayout"));
        topWidgetLayout->setContentsMargins(10, 10, 10, 10);
        comboBox = new QComboBox(topWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        topWidgetLayout->addWidget(comboBox);

        startButton = new QPushButton(topWidget);
        startButton->setObjectName(QStringLiteral("startButton"));

        topWidgetLayout->addWidget(startButton);

        threadAHoverButton = new QPushButton(topWidget);
        threadAHoverButton->setObjectName(QStringLiteral("threadAHoverButton"));

        topWidgetLayout->addWidget(threadAHoverButton);

        threadAStopButton = new QPushButton(topWidget);
        threadAStopButton->setObjectName(QStringLiteral("threadAStopButton"));

        topWidgetLayout->addWidget(threadAStopButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        topWidgetLayout->addItem(horizontalSpacer);


        rootWidgetLayout->addWidget(topWidget);

        bottomWidget = new QWidget(rootWidget);
        bottomWidget->setObjectName(QStringLiteral("bottomWidget"));
        bottomWidget->setStyleSheet(QLatin1String("background-color:black;\n"
"color:rgb(154, 209, 26)"));
        bottomWidgetLayout = new QGridLayout(bottomWidget);
        bottomWidgetLayout->setSpacing(10);
        bottomWidgetLayout->setContentsMargins(11, 11, 11, 11);
        bottomWidgetLayout->setObjectName(QStringLiteral("bottomWidgetLayout"));
        bottomWidgetLayout->setContentsMargins(0, 0, 0, 0);
        textBrowser = new QTextBrowser(bottomWidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));

        bottomWidgetLayout->addWidget(textBrowser, 0, 0, 1, 1);


        rootWidgetLayout->addWidget(bottomWidget);

        rootWidgetLayout->setStretch(0, 1);
        rootWidgetLayout->setStretch(1, 10);

        mainWidgetLayout->addWidget(rootWidget, 0, 0, 1, 1);


        retranslateUi(MainWidget);
        QObject::connect(startButton, SIGNAL(clicked()), MainWidget, SLOT(clickStartButton()));
        QObject::connect(threadAHoverButton, SIGNAL(clicked()), MainWidget, SLOT(clickThreadAHoverButton()));
        QObject::connect(threadAStopButton, SIGNAL(clicked()), MainWidget, SLOT(clickThreadAStopButton()));
        QObject::connect(comboBox, SIGNAL(currentIndexChanged(int)), MainWidget, SLOT(comboBoxCurrentIndexChanged()));

        QMetaObject::connectSlotsByName(MainWidget);
    } // setupUi

    void retranslateUi(QWidget *MainWidget)
    {
        MainWidget->setWindowTitle(QApplication::translate("MainWidget", "MainWidget", Q_NULLPTR));
        startButton->setText(QApplication::translate("MainWidget", "\345\220\257\345\212\250", Q_NULLPTR));
        threadAHoverButton->setText(QApplication::translate("MainWidget", "\347\272\277\347\250\213A Hover", Q_NULLPTR));
        threadAStopButton->setText(QApplication::translate("MainWidget", "\347\272\277\347\250\213A stop", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWidget: public Ui_MainWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWIDGET_H
