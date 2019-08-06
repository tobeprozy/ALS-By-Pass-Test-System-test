#pragma once

#include <QtWidgets/QWidget>
#include "ui_qttest.h"

class qttest : public QWidget
{
	Q_OBJECT

public:
	qttest(QWidget *parent = Q_NULLPTR);

private:
	Ui::qttestClass ui;
};
