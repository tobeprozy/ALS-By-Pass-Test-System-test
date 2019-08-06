/********************************************************************************
** Form generated from reading UI file 'themewidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_THEMEWIDGET_H
#define UI_THEMEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_themewidgetClass
{
public:

    void setupUi(QWidget *themewidgetClass)
    {
        if (themewidgetClass->objectName().isEmpty())
            themewidgetClass->setObjectName(QString::fromUtf8("themewidgetClass"));
        themewidgetClass->resize(600, 400);

        retranslateUi(themewidgetClass);

        QMetaObject::connectSlotsByName(themewidgetClass);
    } // setupUi

    void retranslateUi(QWidget *themewidgetClass)
    {
        themewidgetClass->setWindowTitle(QApplication::translate("themewidgetClass", "themewidget", nullptr));
    } // retranslateUi

};

namespace Ui {
    class themewidgetClass: public Ui_themewidgetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_THEMEWIDGET_H
