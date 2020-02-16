/********************************************************************************
** Form generated from reading UI file 'DatabaseDemo02Widget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATABASEDEMO02WIDGET_H
#define UI_DATABASEDEMO02WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DatabaseDemo02Widget
{
public:
    QGridLayout *DatabaseDemo02WidgetGridLayout;
    QWidget *rootWidget;
    QVBoxLayout *rootWidgetVerticalLayout;
    QWidget *topWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *findButton;
    QPushButton *addButton;
    QPushButton *updateButton;
    QPushButton *deleteButton;
    QSpacerItem *horizontalSpacer;
    QWidget *bottomWidget;
    QGridLayout *gridLayout;
    QTableWidget *productTypeTableWidget;

    void setupUi(QWidget *DatabaseDemo02Widget)
    {
        if (DatabaseDemo02Widget->objectName().isEmpty())
            DatabaseDemo02Widget->setObjectName(QStringLiteral("DatabaseDemo02Widget"));
        DatabaseDemo02Widget->resize(1000, 800);
        DatabaseDemo02WidgetGridLayout = new QGridLayout(DatabaseDemo02Widget);
        DatabaseDemo02WidgetGridLayout->setSpacing(10);
        DatabaseDemo02WidgetGridLayout->setContentsMargins(11, 11, 11, 11);
        DatabaseDemo02WidgetGridLayout->setObjectName(QStringLiteral("DatabaseDemo02WidgetGridLayout"));
        DatabaseDemo02WidgetGridLayout->setContentsMargins(0, 0, 0, 0);
        rootWidget = new QWidget(DatabaseDemo02Widget);
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
        findButton = new QPushButton(topWidget);
        findButton->setObjectName(QStringLiteral("findButton"));

        horizontalLayout->addWidget(findButton);

        addButton = new QPushButton(topWidget);
        addButton->setObjectName(QStringLiteral("addButton"));

        horizontalLayout->addWidget(addButton);

        updateButton = new QPushButton(topWidget);
        updateButton->setObjectName(QStringLiteral("updateButton"));

        horizontalLayout->addWidget(updateButton);

        deleteButton = new QPushButton(topWidget);
        deleteButton->setObjectName(QStringLiteral("deleteButton"));

        horizontalLayout->addWidget(deleteButton);

        horizontalSpacer = new QSpacerItem(736, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        rootWidgetVerticalLayout->addWidget(topWidget);

        bottomWidget = new QWidget(rootWidget);
        bottomWidget->setObjectName(QStringLiteral("bottomWidget"));
        gridLayout = new QGridLayout(bottomWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        productTypeTableWidget = new QTableWidget(bottomWidget);
        productTypeTableWidget->setObjectName(QStringLiteral("productTypeTableWidget"));

        gridLayout->addWidget(productTypeTableWidget, 0, 0, 1, 1);


        rootWidgetVerticalLayout->addWidget(bottomWidget);

        rootWidgetVerticalLayout->setStretch(0, 1);
        rootWidgetVerticalLayout->setStretch(1, 10);

        DatabaseDemo02WidgetGridLayout->addWidget(rootWidget, 0, 0, 1, 1);


        retranslateUi(DatabaseDemo02Widget);
        QObject::connect(findButton, SIGNAL(clicked()), DatabaseDemo02Widget, SLOT(findButtonClicked()));
        QObject::connect(addButton, SIGNAL(clicked()), DatabaseDemo02Widget, SLOT(addButtonClicked()));
        QObject::connect(updateButton, SIGNAL(clicked()), DatabaseDemo02Widget, SLOT(updateButtonClicked()));
        QObject::connect(deleteButton, SIGNAL(clicked()), DatabaseDemo02Widget, SLOT(deleteButtonClicked()));

        QMetaObject::connectSlotsByName(DatabaseDemo02Widget);
    } // setupUi

    void retranslateUi(QWidget *DatabaseDemo02Widget)
    {
        DatabaseDemo02Widget->setWindowTitle(QApplication::translate("DatabaseDemo02Widget", "DatabaseDemo02Widget", Q_NULLPTR));
        findButton->setText(QApplication::translate("DatabaseDemo02Widget", "\346\237\245\350\257\242", Q_NULLPTR));
        addButton->setText(QApplication::translate("DatabaseDemo02Widget", "\346\226\260\345\242\236", Q_NULLPTR));
        updateButton->setText(QApplication::translate("DatabaseDemo02Widget", "\346\233\264\346\224\271", Q_NULLPTR));
        deleteButton->setText(QApplication::translate("DatabaseDemo02Widget", "\345\210\240\351\231\244", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DatabaseDemo02Widget: public Ui_DatabaseDemo02Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATABASEDEMO02WIDGET_H
