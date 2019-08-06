
#include "qttest.h"
#include <QApplication>

int main(int argc, char* argv[])
{
	QApplication a(argc, argv);
	qttest w;
	w.setGeometry(100, 100, 200, 120);
	// 表示该界面显示在屏幕的100和100的位置
	w.show();
	
	return a.exec();
}
