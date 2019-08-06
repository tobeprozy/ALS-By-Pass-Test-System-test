#include "QT_barAdvanced.h"
#include <QtWidgets/QApplication>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include "themewidget.h"
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>

QT_CHARTS_USE_NAMESPACE

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	//QChart* chart = new QChart();
	//chart->setTitle("24 Hour Monitor Report");//����char�ı���
	QMainWindow window;
	ThemeWidget* widget = new ThemeWidget();//���ڻ�ȡ
	window.setCentralWidget(widget);//�����ھ���
	window.resize(900,600);//���ô��ڴ�С
	window.show();//������ʾ
	
	return a.exec();
}
