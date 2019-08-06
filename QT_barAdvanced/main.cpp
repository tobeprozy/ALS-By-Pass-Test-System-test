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
	//chart->setTitle("24 Hour Monitor Report");//设置char的标题
	QMainWindow window;
	ThemeWidget* widget = new ThemeWidget();//窗口获取
	window.setCentralWidget(widget);//将窗口居中
	window.resize(900,600);//设置窗口大小
	window.show();//窗口显示
	
	return a.exec();
}
