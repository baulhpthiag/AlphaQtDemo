/********************************************************************************
** Form generated from reading UI file 'JsonDemo02Widget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JSONDEMO02WIDGET_H
#define UI_JSONDEMO02WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_JsonDemo02Widget
{
public:
    QGridLayout *JsonDemo02WidgetGridLayout;
    QWidget *rootWidget;
    QVBoxLayout *rootWidgetVerticalLayout;
    QWidget *topWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *createJsonButton;
    QPushButton *readJsonButton;
    QPushButton *updateJsonButton;
    QSpacerItem *horizontalSpacer;
    QWidget *bottomWidget;

    void setupUi(QWidget *JsonDemo02Widget)
    {
        if (JsonDemo02Widget->objectName().isEmpty())
            JsonDemo02Widget->setObjectName(QStringLiteral("JsonDemo02Widget"));
        JsonDemo02Widget->resize(1000, 800);
        JsonDemo02WidgetGridLayout = new QGridLayout(JsonDemo02Widget);
        JsonDemo02WidgetGridLayout->setSpacing(10);
        JsonDemo02WidgetGridLayout->setContentsMargins(11, 11, 11, 11);
        JsonDemo02WidgetGridLayout->setObjectName(QStringLiteral("JsonDemo02WidgetGridLayout"));
        JsonDemo02WidgetGridLayout->setContentsMargins(0, 0, 0, 0);
        rootWidget = new QWidget(JsonDemo02Widget);
        rootWidget->setObjectName(QStringLiteral("rootWidget"));
        rootWidget->setStyleSheet(QStringLiteral(""));
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
        createJsonButton = new QPushButton(topWidget);
        createJsonButton->setObjectName(QStringLiteral("createJsonButton"));

        horizontalLayout->addWidget(createJsonButton);

        readJsonButton = new QPushButton(topWidget);
        readJsonButton->setObjectName(QStringLiteral("readJsonButton"));

        horizontalLayout->addWidget(readJsonButton);

        updateJsonButton = new QPushButton(topWidget);
        updateJsonButton->setObjectName(QStringLiteral("updateJsonButton"));

        horizontalLayout->addWidget(updateJsonButton);

        horizontalSpacer = new QSpacerItem(817, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        rootWidgetVerticalLayout->addWidget(topWidget);

        bottomWidget = new QWidget(rootWidget);
        bottomWidget->setObjectName(QStringLiteral("bottomWidget"));

        rootWidgetVerticalLayout->addWidget(bottomWidget);

        rootWidgetVerticalLayout->setStretch(0, 1);
        rootWidgetVerticalLayout->setStretch(1, 10);

        JsonDemo02WidgetGridLayout->addWidget(rootWidget, 0, 0, 1, 1);


        retranslateUi(JsonDemo02Widget);
        QObject::connect(readJsonButton, SIGNAL(clicked()), JsonDemo02Widget, SLOT(readJsonButtonClicked()));
        QObject::connect(updateJsonButton, SIGNAL(clicked()), JsonDemo02Widget, SLOT(updateJsonButtonClicked()));
        QObject::connect(createJsonButton, SIGNAL(clicked()), JsonDemo02Widget, SLOT(createJsonButtonClicked()));

        QMetaObject::connectSlotsByName(JsonDemo02Widget);
    } // setupUi

    void retranslateUi(QWidget *JsonDemo02Widget)
    {
        JsonDemo02Widget->setWindowTitle(QApplication::translate("JsonDemo02Widget", "JsonDemo02Widget", Q_NULLPTR));
        createJsonButton->setText(QApplication::translate("JsonDemo02Widget", "\345\210\233\345\273\272Json\346\226\207\344\273\266", Q_NULLPTR));
        readJsonButton->setText(QApplication::translate("JsonDemo02Widget", "\350\257\273\345\217\226Json", Q_NULLPTR));
        updateJsonButton->setText(QApplication::translate("JsonDemo02Widget", "\344\277\256\346\224\271Json", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class JsonDemo02Widget: public Ui_JsonDemo02Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JSONDEMO02WIDGET_H
