/********************************************************************************
** Form generated from reading UI file 'chartthemes.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHARTTHEMES_H
#define UI_CHARTTHEMES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_chartthemesClass
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QDateTimeEdit *dateTimeEdit;

    void setupUi(QWidget *chartthemesClass)
    {
        if (chartthemesClass->objectName().isEmpty())
            chartthemesClass->setObjectName(QString::fromUtf8("chartthemesClass"));
        chartthemesClass->resize(600, 400);
        horizontalLayoutWidget = new QWidget(chartthemesClass);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(430, 310, 160, 80));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        dateTimeEdit = new QDateTimeEdit(horizontalLayoutWidget);
        dateTimeEdit->setObjectName(QString::fromUtf8("dateTimeEdit"));

        horizontalLayout->addWidget(dateTimeEdit);


        retranslateUi(chartthemesClass);
        QObject::connect(chartthemesClass, SIGNAL(customContextMenuRequested(QPoint)), chartthemesClass, SLOT(show()));

        QMetaObject::connectSlotsByName(chartthemesClass);
    } // setupUi

    void retranslateUi(QWidget *chartthemesClass)
    {
        chartthemesClass->setWindowTitle(QApplication::translate("chartthemesClass", "chartthemes", nullptr));
    } // retranslateUi

};

namespace Ui {
    class chartthemesClass: public Ui_chartthemesClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHARTTHEMES_H
