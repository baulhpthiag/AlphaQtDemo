/********************************************************************************
** Form generated from reading UI file 'DatabaseDemo01Widget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATABASEDEMO01WIDGET_H
#define UI_DATABASEDEMO01WIDGET_H

#include <QtCharts>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DatabaseDemo01Widget
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *rootWidget;
    QGridLayout *rootWidgetLayout;
    QTabWidget *tabWidget;
    QWidget *tab1;
    QVBoxLayout *tab1VerticalLayout;
    QWidget *tab1TopWidget;
    QGridLayout *gridLayout;
    QComboBox *productTypeComboBox;
    QPushButton *addDetectLogButton;
    QPushButton *findProductTypeButton;
    QDateTimeEdit *stopDateTimeEdit;
    QDateTimeEdit *startDateTimeEdit;
    QPushButton *addProductTypeButton;
    QPushButton *initDatabaseButton;
    QPushButton *findDetectLogButton;
    QSpacerItem *horizontalSpacer;
    QWidget *tab1BottomWidget;
    QHBoxLayout *horizontalLayout_2;
    QWidget *leftWidget;
    QVBoxLayout *verticalLayout_2;
    QTableWidget *productTypeTableWidget;
    QTableWidget *detectLogTableWidget;
    QWidget *rightWidget;
    QGridLayout *gridLayout_2;
    QChartView *chartViewWidget;
    QWidget *tab2;

    void setupUi(QWidget *DatabaseDemo01Widget)
    {
        if (DatabaseDemo01Widget->objectName().isEmpty())
            DatabaseDemo01Widget->setObjectName(QStringLiteral("DatabaseDemo01Widget"));
        DatabaseDemo01Widget->resize(1000, 800);
        DatabaseDemo01Widget->setStyleSheet(QStringLiteral(""));
        verticalLayout = new QVBoxLayout(DatabaseDemo01Widget);
        verticalLayout->setSpacing(10);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        rootWidget = new QWidget(DatabaseDemo01Widget);
        rootWidget->setObjectName(QStringLiteral("rootWidget"));
        rootWidget->setStyleSheet(QStringLiteral(""));
        rootWidgetLayout = new QGridLayout(rootWidget);
        rootWidgetLayout->setSpacing(10);
        rootWidgetLayout->setContentsMargins(11, 11, 11, 11);
        rootWidgetLayout->setObjectName(QStringLiteral("rootWidgetLayout"));
        rootWidgetLayout->setContentsMargins(0, 0, 0, 0);
        tabWidget = new QTabWidget(rootWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab1 = new QWidget();
        tab1->setObjectName(QStringLiteral("tab1"));
        tab1VerticalLayout = new QVBoxLayout(tab1);
        tab1VerticalLayout->setSpacing(10);
        tab1VerticalLayout->setContentsMargins(11, 11, 11, 11);
        tab1VerticalLayout->setObjectName(QStringLiteral("tab1VerticalLayout"));
        tab1VerticalLayout->setContentsMargins(0, 0, 0, 0);
        tab1TopWidget = new QWidget(tab1);
        tab1TopWidget->setObjectName(QStringLiteral("tab1TopWidget"));
        gridLayout = new QGridLayout(tab1TopWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        productTypeComboBox = new QComboBox(tab1TopWidget);
        productTypeComboBox->setObjectName(QStringLiteral("productTypeComboBox"));

        gridLayout->addWidget(productTypeComboBox, 2, 3, 1, 1);

        addDetectLogButton = new QPushButton(tab1TopWidget);
        addDetectLogButton->setObjectName(QStringLiteral("addDetectLogButton"));

        gridLayout->addWidget(addDetectLogButton, 2, 0, 1, 1);

        findProductTypeButton = new QPushButton(tab1TopWidget);
        findProductTypeButton->setObjectName(QStringLiteral("findProductTypeButton"));

        gridLayout->addWidget(findProductTypeButton, 1, 1, 1, 1);

        stopDateTimeEdit = new QDateTimeEdit(tab1TopWidget);
        stopDateTimeEdit->setObjectName(QStringLiteral("stopDateTimeEdit"));

        gridLayout->addWidget(stopDateTimeEdit, 2, 2, 1, 1);

        startDateTimeEdit = new QDateTimeEdit(tab1TopWidget);
        startDateTimeEdit->setObjectName(QStringLiteral("startDateTimeEdit"));

        gridLayout->addWidget(startDateTimeEdit, 2, 1, 1, 1);

        addProductTypeButton = new QPushButton(tab1TopWidget);
        addProductTypeButton->setObjectName(QStringLiteral("addProductTypeButton"));

        gridLayout->addWidget(addProductTypeButton, 1, 0, 1, 1);

        initDatabaseButton = new QPushButton(tab1TopWidget);
        initDatabaseButton->setObjectName(QStringLiteral("initDatabaseButton"));

        gridLayout->addWidget(initDatabaseButton, 0, 0, 1, 1);

        findDetectLogButton = new QPushButton(tab1TopWidget);
        findDetectLogButton->setObjectName(QStringLiteral("findDetectLogButton"));

        gridLayout->addWidget(findDetectLogButton, 2, 4, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 5, 1, 1);


        tab1VerticalLayout->addWidget(tab1TopWidget);

        tab1BottomWidget = new QWidget(tab1);
        tab1BottomWidget->setObjectName(QStringLiteral("tab1BottomWidget"));
        horizontalLayout_2 = new QHBoxLayout(tab1BottomWidget);
        horizontalLayout_2->setSpacing(10);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        leftWidget = new QWidget(tab1BottomWidget);
        leftWidget->setObjectName(QStringLiteral("leftWidget"));
        verticalLayout_2 = new QVBoxLayout(leftWidget);
        verticalLayout_2->setSpacing(10);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        productTypeTableWidget = new QTableWidget(leftWidget);
        productTypeTableWidget->setObjectName(QStringLiteral("productTypeTableWidget"));

        verticalLayout_2->addWidget(productTypeTableWidget);

        detectLogTableWidget = new QTableWidget(leftWidget);
        detectLogTableWidget->setObjectName(QStringLiteral("detectLogTableWidget"));

        verticalLayout_2->addWidget(detectLogTableWidget);


        horizontalLayout_2->addWidget(leftWidget);

        rightWidget = new QWidget(tab1BottomWidget);
        rightWidget->setObjectName(QStringLiteral("rightWidget"));
        gridLayout_2 = new QGridLayout(rightWidget);
        gridLayout_2->setSpacing(10);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        chartViewWidget = new QChartView(rightWidget);
        chartViewWidget->setObjectName(QStringLiteral("chartViewWidget"));

        gridLayout_2->addWidget(chartViewWidget, 0, 0, 1, 1);


        horizontalLayout_2->addWidget(rightWidget);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 1);

        tab1VerticalLayout->addWidget(tab1BottomWidget);

        tab1VerticalLayout->setStretch(0, 1);
        tab1VerticalLayout->setStretch(1, 5);
        tabWidget->addTab(tab1, QString());
        tab2 = new QWidget();
        tab2->setObjectName(QStringLiteral("tab2"));
        tabWidget->addTab(tab2, QString());

        rootWidgetLayout->addWidget(tabWidget, 0, 0, 1, 1);


        verticalLayout->addWidget(rootWidget);


        retranslateUi(DatabaseDemo01Widget);
        QObject::connect(initDatabaseButton, SIGNAL(clicked()), DatabaseDemo01Widget, SLOT(initDatabaseButtonClicked()));
        QObject::connect(addProductTypeButton, SIGNAL(clicked()), DatabaseDemo01Widget, SLOT(addProductTypeButtonClicked()));
        QObject::connect(findProductTypeButton, SIGNAL(clicked()), DatabaseDemo01Widget, SLOT(findProductTypeButtonClicked()));
        QObject::connect(addDetectLogButton, SIGNAL(clicked()), DatabaseDemo01Widget, SLOT(addDetectLogButtonClicked()));
        QObject::connect(findDetectLogButton, SIGNAL(clicked()), DatabaseDemo01Widget, SLOT(findDetectLogButtonClicked()));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(DatabaseDemo01Widget);
    } // setupUi

    void retranslateUi(QWidget *DatabaseDemo01Widget)
    {
        DatabaseDemo01Widget->setWindowTitle(QApplication::translate("DatabaseDemo01Widget", "DatabaseDemo01Widget", Q_NULLPTR));
        addDetectLogButton->setText(QApplication::translate("DatabaseDemo01Widget", "\346\226\260\345\242\236\346\243\200\346\265\213\350\256\260\345\275\225", Q_NULLPTR));
        findProductTypeButton->setText(QApplication::translate("DatabaseDemo01Widget", "\346\237\245\350\257\242\344\272\247\345\223\201\345\236\213\345\217\267", Q_NULLPTR));
        addProductTypeButton->setText(QApplication::translate("DatabaseDemo01Widget", "\346\226\260\345\242\236\344\272\247\345\223\201\345\236\213\345\217\267", Q_NULLPTR));
        initDatabaseButton->setText(QApplication::translate("DatabaseDemo01Widget", "\345\210\235\345\247\213\345\214\226\346\225\260\346\215\256\345\272\223", Q_NULLPTR));
        findDetectLogButton->setText(QApplication::translate("DatabaseDemo01Widget", "\346\237\245\350\257\242\346\243\200\346\265\213\350\256\260\345\275\225", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab1), QApplication::translate("DatabaseDemo01Widget", "Tab 1", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab2), QApplication::translate("DatabaseDemo01Widget", "Tab 2", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DatabaseDemo01Widget: public Ui_DatabaseDemo01Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATABASEDEMO01WIDGET_H
