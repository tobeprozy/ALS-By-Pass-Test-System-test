#pragma once

#include <QtWidgets/QWidget>
#include "ui_QT_bar.h"

class QT_bar : public QWidget
{
	Q_OBJECT

public:
	QT_bar(QWidget *parent = Q_NULLPTR);

private:
	Ui::QT_barClass ui;
};
