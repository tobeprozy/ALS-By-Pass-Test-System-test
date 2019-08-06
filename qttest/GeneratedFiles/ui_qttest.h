/********************************************************************************
** Form generated from reading UI file 'qttest.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTTEST_H
#define UI_QTTEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_qttestClass
{
public:

    void setupUi(QWidget *qttestClass)
    {
        if (qttestClass->objectName().isEmpty())
            qttestClass->setObjectName(QString::fromUtf8("qttestClass"));
        qttestClass->resize(600, 400);

        retranslateUi(qttestClass);

        QMetaObject::connectSlotsByName(qttestClass);
    } // setupUi

    void retranslateUi(QWidget *qttestClass)
    {
        qttestClass->setWindowTitle(QApplication::translate("qttestClass", "qttest", nullptr));
    } // retranslateUi

};

namespace Ui {
    class qttestClass: public Ui_qttestClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTTEST_H
