/********************************************************************************
** Form generated from reading UI file 'DatabaseDemo01AddProductTypeWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATABASEDEMO01ADDPRODUCTTYPEWIDGET_H
#define UI_DATABASEDEMO01ADDPRODUCTTYPEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DatabaseDemo01AddProductTypeWidget
{
public:
    QGridLayout *DatabaseDemo01AddProductTypeWidgetGridLayout;
    QWidget *rootWidget;
    QGridLayout *gridLayout;
    QPushButton *cancelButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *confirmButton;
    QLineEdit *productTypeNameLineEdit;
    QLabel *productTypeNameLabel;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *DatabaseDemo01AddProductTypeWidget)
    {
        if (DatabaseDemo01AddProductTypeWidget->objectName().isEmpty())
            DatabaseDemo01AddProductTypeWidget->setObjectName(QStringLiteral("DatabaseDemo01AddProductTypeWidget"));
        DatabaseDemo01AddProductTypeWidget->resize(400, 300);
        DatabaseDemo01AddProductTypeWidgetGridLayout = new QGridLayout(DatabaseDemo01AddProductTypeWidget);
        DatabaseDemo01AddProductTypeWidgetGridLayout->setSpacing(5);
        DatabaseDemo01AddProductTypeWidgetGridLayout->setContentsMargins(11, 11, 11, 11);
        DatabaseDemo01AddProductTypeWidgetGridLayout->setObjectName(QStringLiteral("DatabaseDemo01AddProductTypeWidgetGridLayout"));
        DatabaseDemo01AddProductTypeWidgetGridLayout->setContentsMargins(0, 0, 0, 0);
        rootWidget = new QWidget(DatabaseDemo01AddProductTypeWidget);
        rootWidget->setObjectName(QStringLiteral("rootWidget"));
        gridLayout = new QGridLayout(rootWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        cancelButton = new QPushButton(rootWidget);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        gridLayout->addWidget(cancelButton, 1, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        confirmButton = new QPushButton(rootWidget);
        confirmButton->setObjectName(QStringLiteral("confirmButton"));

        gridLayout->addWidget(confirmButton, 1, 1, 1, 1);

        productTypeNameLineEdit = new QLineEdit(rootWidget);
        productTypeNameLineEdit->setObjectName(QStringLiteral("productTypeNameLineEdit"));

        gridLayout->addWidget(productTypeNameLineEdit, 0, 2, 1, 1);

        productTypeNameLabel = new QLabel(rootWidget);
        productTypeNameLabel->setObjectName(QStringLiteral("productTypeNameLabel"));

        gridLayout->addWidget(productTypeNameLabel, 0, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 3, 1, 1);


        DatabaseDemo01AddProductTypeWidgetGridLayout->addWidget(rootWidget, 0, 0, 1, 1);


        retranslateUi(DatabaseDemo01AddProductTypeWidget);
        QObject::connect(confirmButton, SIGNAL(clicked()), DatabaseDemo01AddProductTypeWidget, SLOT(confirmButtonClicked()));
        QObject::connect(cancelButton, SIGNAL(clicked()), DatabaseDemo01AddProductTypeWidget, SLOT(cancelButtonClicked()));

        QMetaObject::connectSlotsByName(DatabaseDemo01AddProductTypeWidget);
    } // setupUi

    void retranslateUi(QWidget *DatabaseDemo01AddProductTypeWidget)
    {
        DatabaseDemo01AddProductTypeWidget->setWindowTitle(QApplication::translate("DatabaseDemo01AddProductTypeWidget", "DatabaseDemo01AddProductTypeWidget", Q_NULLPTR));
        cancelButton->setText(QApplication::translate("DatabaseDemo01AddProductTypeWidget", "\345\217\226\346\266\210", Q_NULLPTR));
        confirmButton->setText(QApplication::translate("DatabaseDemo01AddProductTypeWidget", "\347\241\256\345\256\232", Q_NULLPTR));
        productTypeNameLabel->setText(QApplication::translate("DatabaseDemo01AddProductTypeWidget", "\344\272\247\345\223\201\347\261\273\345\236\213\345\220\215\347\247\260", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DatabaseDemo01AddProductTypeWidget: public Ui_DatabaseDemo01AddProductTypeWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATABASEDEMO01ADDPRODUCTTYPEWIDGET_H
