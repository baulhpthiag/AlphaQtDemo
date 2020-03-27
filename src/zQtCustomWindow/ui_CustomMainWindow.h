/********************************************************************************
** Form generated from reading UI file 'CustomMainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CUSTOMMAINWINDOW_H
#define UI_CUSTOMMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CustomMainWindow
{
public:
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QLabel *label;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *CustomMainWindow)
    {
        if (CustomMainWindow->objectName().isEmpty())
            CustomMainWindow->setObjectName(QStringLiteral("CustomMainWindow"));
        CustomMainWindow->resize(719, 540);
        verticalLayout = new QVBoxLayout(CustomMainWindow);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        label = new QLabel(CustomMainWindow);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(0, 400));
        label->setStyleSheet(QStringLiteral("border-image: url(:/pic.png);"));

        verticalLayout->addWidget(label);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton = new QPushButton(CustomMainWindow);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMinimumSize(QSize(97, 30));
        pushButton->setMaximumSize(QSize(97, 30));
        pushButton->setStyleSheet(QLatin1String("color: #4F5F6F;\n"
"background-color: #FFFFFF;\n"
"border-radius: 6px;\n"
"border: 1px solid #7F8B97;"));

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(CustomMainWindow);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(97, 30));
        pushButton_2->setMaximumSize(QSize(97, 30));
        pushButton_2->setStyleSheet(QLatin1String("color: #4F5F6F;\n"
"background-color: #FFFFFF;\n"
"border-radius: 6px;\n"
"border: 1px solid #7F8B97;"));

        horizontalLayout->addWidget(pushButton_2);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(CustomMainWindow);

        QMetaObject::connectSlotsByName(CustomMainWindow);
    } // setupUi

    void retranslateUi(QWidget *CustomMainWindow)
    {
        CustomMainWindow->setWindowTitle(QApplication::translate("CustomMainWindow", "\346\265\213\350\257\225", Q_NULLPTR));
        label->setText(QString());
        pushButton->setText(QApplication::translate("CustomMainWindow", "\347\241\256\345\256\232", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("CustomMainWindow", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CustomMainWindow: public Ui_CustomMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CUSTOMMAINWINDOW_H
