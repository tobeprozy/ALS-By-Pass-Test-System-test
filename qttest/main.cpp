
#include "qttest.h"
#include <QApplication>

int main(int argc, char* argv[])
{
	QApplication a(argc, argv);
	qttest w;
	w.setGeometry(100, 100, 200, 120);
	// ��ʾ�ý�����ʾ����Ļ��100��100��λ��
	w.show();
	
	return a.exec();
}
