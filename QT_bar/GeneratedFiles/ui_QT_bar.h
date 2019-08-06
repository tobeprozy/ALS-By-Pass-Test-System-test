/********************************************************************************
** Form generated from reading UI file 'QT_bar.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QT_BAR_H
#define UI_QT_BAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QT_barClass
{
public:
    QFormLayout *formLayout;
    QPushButton *pushButton;

    void setupUi(QWidget *QT_barClass)
    {
        if (QT_barClass->objectName().isEmpty())
            QT_barClass->setObjectName(QString::fromUtf8("QT_barClass"));
        QT_barClass->resize(600, 400);
        formLayout = new QFormLayout(QT_barClass);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        pushButton = new QPushButton(QT_barClass);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        formLayout->setWidget(0, QFormLayout::LabelRole, pushButton);


        retranslateUi(QT_barClass);

        QMetaObject::connectSlotsByName(QT_barClass);
    } // setupUi

    void retranslateUi(QWidget *QT_barClass)
    {
        QT_barClass->setWindowTitle(QApplication::translate("QT_barClass", "QT_bar", nullptr));
        pushButton->setText(QApplication::translate("QT_barClass", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QT_barClass: public Ui_QT_barClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QT_BAR_H
