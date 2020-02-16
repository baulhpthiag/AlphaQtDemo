/********************************************************************************
** Form generated from reading UI file 'DatabaseDemo01AddDetectLogWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATABASEDEMO01ADDDETECTLOGWIDGET_H
#define UI_DATABASEDEMO01ADDDETECTLOGWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DatabaseDemo01AddDetectLogWidget
{
public:
    QGridLayout *DatabaseDemo01AddDetectLogWidgetGridLayout;
    QWidget *rootWidget;
    QGridLayout *gridLayout;
    QLabel *okCountLabel;
    QSpacerItem *verticalSpacer;
    QLabel *ngCountLabel;
    QLineEdit *ngCountLineEdit;
    QLineEdit *okCountLineEdit;
    QLabel *nullCountLabel;
    QLineEdit *nullCountLineEdit;
    QLabel *productTypeLabel;
    QPushButton *confirmButton;
    QComboBox *productTypeComboBox;
    QPushButton *cancelPushButton;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *DatabaseDemo01AddDetectLogWidget)
    {
        if (DatabaseDemo01AddDetectLogWidget->objectName().isEmpty())
            DatabaseDemo01AddDetectLogWidget->setObjectName(QStringLiteral("DatabaseDemo01AddDetectLogWidget"));
        DatabaseDemo01AddDetectLogWidget->resize(400, 400);
        DatabaseDemo01AddDetectLogWidgetGridLayout = new QGridLayout(DatabaseDemo01AddDetectLogWidget);
        DatabaseDemo01AddDetectLogWidgetGridLayout->setSpacing(10);
        DatabaseDemo01AddDetectLogWidgetGridLayout->setContentsMargins(11, 11, 11, 11);
        DatabaseDemo01AddDetectLogWidgetGridLayout->setObjectName(QStringLiteral("DatabaseDemo01AddDetectLogWidgetGridLayout"));
        DatabaseDemo01AddDetectLogWidgetGridLayout->setContentsMargins(0, 0, 0, 0);
        rootWidget = new QWidget(DatabaseDemo01AddDetectLogWidget);
        rootWidget->setObjectName(QStringLiteral("rootWidget"));
        gridLayout = new QGridLayout(rootWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        okCountLabel = new QLabel(rootWidget);
        okCountLabel->setObjectName(QStringLiteral("okCountLabel"));

        gridLayout->addWidget(okCountLabel, 1, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 6, 1, 1, 1);

        ngCountLabel = new QLabel(rootWidget);
        ngCountLabel->setObjectName(QStringLiteral("ngCountLabel"));

        gridLayout->addWidget(ngCountLabel, 2, 1, 1, 1);

        ngCountLineEdit = new QLineEdit(rootWidget);
        ngCountLineEdit->setObjectName(QStringLiteral("ngCountLineEdit"));

        gridLayout->addWidget(ngCountLineEdit, 2, 2, 1, 1);

        okCountLineEdit = new QLineEdit(rootWidget);
        okCountLineEdit->setObjectName(QStringLiteral("okCountLineEdit"));

        gridLayout->addWidget(okCountLineEdit, 1, 2, 1, 1);

        nullCountLabel = new QLabel(rootWidget);
        nullCountLabel->setObjectName(QStringLiteral("nullCountLabel"));

        gridLayout->addWidget(nullCountLabel, 3, 1, 1, 1);

        nullCountLineEdit = new QLineEdit(rootWidget);
        nullCountLineEdit->setObjectName(QStringLiteral("nullCountLineEdit"));

        gridLayout->addWidget(nullCountLineEdit, 3, 2, 1, 1);

        productTypeLabel = new QLabel(rootWidget);
        productTypeLabel->setObjectName(QStringLiteral("productTypeLabel"));

        gridLayout->addWidget(productTypeLabel, 4, 1, 1, 1);

        confirmButton = new QPushButton(rootWidget);
        confirmButton->setObjectName(QStringLiteral("confirmButton"));

        gridLayout->addWidget(confirmButton, 5, 1, 1, 1);

        productTypeComboBox = new QComboBox(rootWidget);
        productTypeComboBox->setObjectName(QStringLiteral("productTypeComboBox"));

        gridLayout->addWidget(productTypeComboBox, 4, 2, 1, 1);

        cancelPushButton = new QPushButton(rootWidget);
        cancelPushButton->setObjectName(QStringLiteral("cancelPushButton"));

        gridLayout->addWidget(cancelPushButton, 5, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 3, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 0, 1, 1, 1);


        DatabaseDemo01AddDetectLogWidgetGridLayout->addWidget(rootWidget, 0, 0, 1, 1);


        retranslateUi(DatabaseDemo01AddDetectLogWidget);
        QObject::connect(confirmButton, SIGNAL(clicked()), DatabaseDemo01AddDetectLogWidget, SLOT(confirmButtonClicked()));
        QObject::connect(cancelPushButton, SIGNAL(clicked()), DatabaseDemo01AddDetectLogWidget, SLOT(cancelButtonClicked()));

        QMetaObject::connectSlotsByName(DatabaseDemo01AddDetectLogWidget);
    } // setupUi

    void retranslateUi(QWidget *DatabaseDemo01AddDetectLogWidget)
    {
        DatabaseDemo01AddDetectLogWidget->setWindowTitle(QApplication::translate("DatabaseDemo01AddDetectLogWidget", "DatabaseDemo01AddDetectLogWidget", Q_NULLPTR));
        okCountLabel->setText(QApplication::translate("DatabaseDemo01AddDetectLogWidget", "okCount", Q_NULLPTR));
        ngCountLabel->setText(QApplication::translate("DatabaseDemo01AddDetectLogWidget", "NgCount", Q_NULLPTR));
        ngCountLineEdit->setText(QApplication::translate("DatabaseDemo01AddDetectLogWidget", "1", Q_NULLPTR));
        okCountLineEdit->setText(QApplication::translate("DatabaseDemo01AddDetectLogWidget", "10", Q_NULLPTR));
        nullCountLabel->setText(QApplication::translate("DatabaseDemo01AddDetectLogWidget", "NullCount", Q_NULLPTR));
        nullCountLineEdit->setText(QApplication::translate("DatabaseDemo01AddDetectLogWidget", "1", Q_NULLPTR));
        productTypeLabel->setText(QApplication::translate("DatabaseDemo01AddDetectLogWidget", "\344\272\247\345\223\201\345\236\213\345\217\267", Q_NULLPTR));
        confirmButton->setText(QApplication::translate("DatabaseDemo01AddDetectLogWidget", "\347\241\256\345\256\232", Q_NULLPTR));
        cancelPushButton->setText(QApplication::translate("DatabaseDemo01AddDetectLogWidget", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DatabaseDemo01AddDetectLogWidget: public Ui_DatabaseDemo01AddDetectLogWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATABASEDEMO01ADDDETECTLOGWIDGET_H
