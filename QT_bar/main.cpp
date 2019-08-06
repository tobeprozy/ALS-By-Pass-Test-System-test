#include "QT_bar.h"
#include <QtWidgets/QApplication>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>

QT_CHARTS_USE_NAMESPACE

int main(int argc, char* argv[])
{
	QApplication a(argc, argv);

	QBarSet* set0 = new QBarSet("ok");//����QBarSetʵ��
	QBarSet* set1 = new QBarSet("ng");
	//QBarSet* set2 = new QBarSet("Axel");
	//QBarSet* set3 = new QBarSet("Mary");
	//QBarSet* set4 = new QBarSet("Samantha");

	//��QBarSetʵ��
	*set0 << 11 << 12 << 13 << 14 << 15 << 16<<19;//��set0�ﲻ��׷������
	*set1 << 1 << 1 << 1 << 2 << 1 << 4<<8;
	//*set2 << 3 << 5 << 8 << 13 << 8 << 5;
	//*set3 << 5 << 6 << 7 << 3 << 4 << 5;
	//*set4 << 9 << 7 << 5 << 3 << 1 << 2;




	//�����ݻ���Ϊ���������һϵ�д�ֱ����ÿ�����μ��е�ÿ�����һ������ӵ�ϵ���С�
	QBarSeries* series = new QBarSeries();//��ÿһ�з�������
	series->append(set0);
	series->append(set1);
	


	//����Char�����������excelֱ��ͼ�ı�ǩ�͵�������
	QChart* chart = new QChart();
	chart->addSeries(series);//��serise��ӵ�Char��
	chart->setTitle("24 hour operation situation");//char �ı�������Ϊ
	chart->setAnimationOptions(QChart::SeriesAnimations); //������ͼ��������


	//�����ַ����б�����X���ǩ
	QStringList categories;
	categories << "8:00~9:00" << "9:00~10:00" << "10:00~11:00" << "11:00~12:00" << "13:00~14:00" << "14:00~15:00";

	//����X�����
	QBarCategoryAxis* axisX = new QBarCategoryAxis();
	axisX->append(categories);//����X�ܱ�ǩ
	chart->addAxis(axisX, Qt::AlignBottom); //��ϵ�б�ǩ�ŵ�����
	
	series->attachAxis(axisX);

	//����Y�����
	QValueAxis* axisY = new QValueAxis();
	axisY->setRange(0, 15);
	chart->addAxis(axisY, Qt::AlignLeft);//�ŵ����
	series->attachAxis(axisY);


	//���ñ�ǩ��Ӧ�ǿ��ӵ�
	chart->legend()->setVisible(true);
	chart->legend()->setAlignment(Qt::AlignBottom);//�ŵ��ײ�


	QChartView* chartView = new QChartView(chart);
	chartView->setRenderHint(QPainter::Antialiasing); //�� painter �����ø�������Ⱦ


	QMainWindow window;  //����Ӧ�ô��ڵ���
	window.setCentralWidget(chartView);//������д�봰��
	window.resize(420, 300);//���ô��ڳ�ʼ��С
	window.show();//��ʾ


	return a.exec();
}
