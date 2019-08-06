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

	QBarSet* set0 = new QBarSet("ok");//声明QBarSet实例
	QBarSet* set1 = new QBarSet("ng");
	//QBarSet* set2 = new QBarSet("Axel");
	//QBarSet* set3 = new QBarSet("Mary");
	//QBarSet* set4 = new QBarSet("Samantha");

	//向QBarSet实例
	*set0 << 11 << 12 << 13 << 14 << 15 << 16<<19;//向set0里不断追加数据
	*set1 << 1 << 1 << 1 << 2 << 1 << 4<<8;
	//*set2 << 3 << 5 << 8 << 13 << 8 << 5;
	//*set3 << 5 << 6 << 7 << 3 << 4 << 5;
	//*set4 << 9 << 7 << 5 << 3 << 1 << 2;




	//将数据绘制为按类别分组的一系列垂直条，每个条形集中的每个类别一个条添加到系列中。
	QBarSeries* series = new QBarSeries();//给每一列分配区域
	series->append(set0);
	series->append(set1);
	


	//设置Char，类似于设计excel直方图的标签和导入数据
	QChart* chart = new QChart();
	chart->addSeries(series);//将serise添加到Char中
	chart->setTitle("24 hour operation situation");//char 的标题设置为
	chart->setAnimationOptions(QChart::SeriesAnimations); //动画在图表中启用


	//定义字符串列表，用于X轴标签
	QStringList categories;
	categories << "8:00~9:00" << "9:00~10:00" << "10:00~11:00" << "11:00~12:00" << "13:00~14:00" << "14:00~15:00";

	//设置X轴参数
	QBarCategoryAxis* axisX = new QBarCategoryAxis();
	axisX->append(categories);//设置X周标签
	chart->addAxis(axisX, Qt::AlignBottom); //将系列标签放到底下
	
	series->attachAxis(axisX);

	//设置Y轴参数
	QValueAxis* axisY = new QValueAxis();
	axisY->setRange(0, 15);
	chart->addAxis(axisY, Qt::AlignLeft);//放到左边
	series->attachAxis(axisY);


	//设置标签对应是可视的
	chart->legend()->setVisible(true);
	chart->legend()->setAlignment(Qt::AlignBottom);//放到底部


	QChartView* chartView = new QChartView(chart);
	chartView->setRenderHint(QPainter::Antialiasing); //在 painter 上设置给定的渲染


	QMainWindow window;  //申明应用窗口的类
	window.setCentralWidget(chartView);//将内容写入窗口
	window.resize(420, 300);//设置窗口初始大小
	window.show();//显示


	return a.exec();
}
