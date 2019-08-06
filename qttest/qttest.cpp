#include "qttest.h"
#include <QtWidgets>
qttest::qttest(QWidget* parent)
	: QWidget()
{
	setMinimumSize(200, 120);
	//setMaximumSize(200, 120);

	QPushButton* quit = new QPushButton("Quit", this);
	QLineEdit* edit = new QLineEdit("",this);
	edit->setGeometry(50, 40, 75, 30);

	quit->setGeometry(62, 40, 75, 30); 
	quit->setFont(QFont("Times", 18, QFont::Bold));
	/*
	 *QFont::QFont(const QString &family, int pointSize = -1, int weight = -1, bool italic = false)
	 */
	connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));
}


