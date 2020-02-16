/********************************************************************************
** Form generated from reading UI file 'JsonDemo01Widget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JSONDEMO01WIDGET_H
#define UI_JSONDEMO01WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_JsonDemo01Widget
{
public:

    void setupUi(QWidget *JsonDemo01Widget)
    {
        if (JsonDemo01Widget->objectName().isEmpty())
            JsonDemo01Widget->setObjectName(QStringLiteral("JsonDemo01Widget"));
        JsonDemo01Widget->resize(400, 300);

        retranslateUi(JsonDemo01Widget);

        QMetaObject::connectSlotsByName(JsonDemo01Widget);
    } // setupUi

    void retranslateUi(QWidget *JsonDemo01Widget)
    {
        JsonDemo01Widget->setWindowTitle(QApplication::translate("JsonDemo01Widget", "JsonDemo01Widget", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class JsonDemo01Widget: public Ui_JsonDemo01Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JSONDEMO01WIDGET_H
