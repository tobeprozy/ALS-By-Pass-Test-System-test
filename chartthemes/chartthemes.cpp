
#include "chartthemes.h"
#include "ui_themewidget.h"
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPercentBarSeries>
#include <QtCharts/QStackedBarSeries>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLineSeries>
#include <QtCharts/QSplineSeries>
#include <QtCharts/QScatterSeries>
#include <QtCharts/QAreaSeries>
#include <QtCharts/QLegend>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtCore/QRandomGenerator>
#include <QtCharts/QBarCategoryAxis>
#include <QtWidgets/QApplication>
#include <QtCharts/QValueAxis>
#include<qDebug>
#include<Qtimer>
#include<QAxObject>
#include<stdio.h>
#include <time.h>
#include <stdlib.h>





void positon_Excel(short row, short colum, short xx[6]);//将处理后的数据存入excel
short readExcel(short colum);//读取excel数据
void Arrays(int num, int label[]);//生成动态数组
int* ok; //动态数组全局变量
void systime();//读取系统时间
int Array_length;//记录label长度
int date[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };//月份的天数
int CountWeek(int year, int month, int day);//计算目前是当年的第几周
int CountDay(int year, int month, int day);//计算目前是当年的第几天

char writeweek2[20];
char writeweek3[20];
char writeweek4[20];
char writeweek1[20];//记录当前是该年第几周

char* systimeA;//系统时间存储函数.法2
char* systimeB;//系统时间存储函数
char systemBB[20];
char systemAA[20];

short m = 0;//过程标志位
int isok[6];//记录识别到的动作次数
short isok_sign[6] = { 0,1,1,1,1,0 };//随便设置了初始完成情况，前五个代表动作，最后一个代表整体完成情况
short y5 = 0;//记录第五个动作清空

//产值情况
static int total = 0;
static int oktotal = 0;
int week1[4] = {0,0,0,0};
int week2[4] = { 0,0,0,0 };
int day1[7] = { 0,0,0,0,0,0,0 };
int day2[7] = { 0,0,0,0,0,0,0 };
int month1[4] = { 0,0,0,0 };
int month2[4] = { 0,0,0,0 };

//读取excel的标志
int endsign = 1;
short daysign = 8;
short weeksign = 8;
short monthsign = 8;

//记录时间
char* dayt1, * dayt2, * dayt3, * dayt4, * dayt5, * dayt6,*  dayt7;
char dayt1s[10],  dayt2s[10], dayt3s[10], dayt4s[10], dayt5s[10], dayt6s[10], dayt7s[10];
char* weekt1, * weekt2, * weekt3, * weekt4;
char weekt1s[10], weekt2s[10], weekt3s[10], weekt4s[10];
char* montht1, * montht2, * montht3, * montht4;
char montht1s[10], montht2s[10], montht3s[10], montht4s[10];

//A::B,其中::表示做作用域，B属于A。
//A::B::C 等价于A.B.C
ThemeWidget::ThemeWidget(QWidget* parent) :
	QWidget(parent),
	m_listCount(3),//显示几组数据
	m_valueMax(10),
	m_valueCount(7),//表示m_valueCount=7;七列数据
	m_dataTable(generateRandomData(m_listCount, m_valueMax, m_valueCount)),
	m_ui(new Ui_ThemeWidgetForm)
{
	//generateRandomData返回一张表单，二位数组，m_dataTable=表单
	m_ui->setupUi(this);
	systime();
	short x[5];
	short isdone = 0;
	short sign = 0;
	short m = 0;
	short y5 = 0;
	short sign_r;
	for (int i = 1;; i++)
	{
		qDebug("i:%d", i);
		daysign = 8;
		sign_r = readExcel(i);
		if (endsign == 0)
		{
			break;
		}
		total = total + 1;
		qDebug("daysign:%d", daysign);
		qDebug("monthsign:%d", monthsign);
		qDebug("weeksign:%d", weeksign);
		if (sign_r == 1)
		{
			oktotal = oktotal + 1;
			if (1)
			{
				if (daysign == 7)
				{
					day1[6]++; qDebug("day1[6]++");
				}
				if (daysign == 6)
				{
					day1[5]++; qDebug("day1[5]++");
				}
				if (daysign == 5)
				{
					day1[4]++; qDebug("day1[4]++");
				}
				if (daysign == 4)
				{
					day1[3]++; qDebug("day1[3]++");
				}
				if (daysign == 3)
				{
					day1[2]++; qDebug("day1[2]++");
				}
				if (daysign == 2)
				{
					day1[1]++; qDebug("day1[1]++");
				}
				if (daysign == 1)
				{
					day1[0]++; qDebug("day1[0]++");
				}
				if (weeksign == 4)
				{
					week1[3]++; qDebug("week1[3]++");
				}
				if (weeksign == 3)
				{
					week1[2]++; qDebug("week1[2]++");
				}
				if (weeksign == 2)
				{
					week1[1]++; qDebug("week1[1]++");
				}
				if (weeksign == 1)
				{
					week1[0]++; qDebug("week1[0]++");
				}
				if (monthsign == 4)
				{
					month1[3]++; qDebug("month1[3]++");
				}
				if (monthsign == 3)
				{
					month1[2]++; qDebug("month1[2]++");
				}
				if (monthsign == 2)
				{
					month1[1]++; qDebug("month1[1]++");
				}
				if (monthsign == 1)
				{
					month1[0]++; qDebug("month1[0]++");
				}


			}

		}
		else if (sign_r == 0)
		{
			qDebug("daysign:%d", daysign);
			if (1)
			{
				if (daysign == 7)
				{
					day2[6]++; qDebug("day2[6]++");
				}
				if (daysign == 6)
				{
					day2[5]++; qDebug("day2[5]++");
				}
				if (daysign == 5)
				{
					day2[4]++; qDebug("day2[4]++");
				}
				if (daysign == 4)
				{
					day2[3]++; qDebug("day2[3]++");
				}
				if (daysign == 3)
				{
					day2[2]++; qDebug("day2[2]++");
				}
				if (daysign == 2)
				{
					day2[1]++; qDebug("day2[1]++");
				}
				if (daysign == 1)
				{
					day1[0]++; qDebug("day1[0]++");
				}

				if (weeksign == 4)
				{
					week2[3]++; qDebug("week2[3]++");
				}
				if (weeksign == 3)
				{
					week2[2]++; qDebug("week2[2]++");
				}
				if (weeksign == 2)
				{
					week2[1]++; qDebug("week2[1]++");
				}
				if (weeksign == 1)
				{
					week2[0]++; qDebug("week2[0]++");
				}
				if (monthsign == 4)
				{
					month2[3]++; qDebug("month2[3]++");
				}
				if (monthsign == 3)
				{
					month2[2]++; qDebug("month2[2]++");
				}
				if (monthsign == 2)
				{
					month2[1]++; qDebug("month2[1]++");
				}
				if (monthsign == 1)
				{
					month2[0]++; qDebug("month2[0]++");
				}
			}
		}
		
	}

		qDebug("month2[3]:%d", month2[3]);
		qDebug("week2[3]:%d", week2[3]);
		qDebug("day2[6]:%d", day2[6]);
		qDebug("endsign:%d", endsign);

	//初始化主题空间
	 populateThemeBox();
	 populateAnimationBox();
	 populateLegendBox();
	//设置定时
	 m_Timer1 = new QTimer;
	 m_Timer1->start(100);
	 connect(m_Timer1, SIGNAL(timeout()), this, SLOT(update11()));
	 m_Timer1->setTimerType(Qt::PreciseTimer);

	//create chartsn 
	int nummax = 0;
	int arraylength = 0;

	//日表
	arraylength = sizeof(day1);
	arraylength = arraylength / sizeof(int);
	nummax = compute_m(day1, arraylength);
	nummax = nummax + compute_m(day2, arraylength);
	nummax = nummax / 10;
	qDebug("nummax:%d", nummax);
	chartView = new QChartView(createBarChartday(day1, day2, nummax));//创建一个m_valueCount列的barChart
	m_ui->gridLayout->addWidget(chartView, 2, 1);  //将chartView添加到Widget的2行，0列，确定显示的位置
	m_charts << chartView;
	
	//月表
	arraylength = sizeof(month1);
	arraylength = arraylength / sizeof(int);
	nummax = compute_m(month1, arraylength);
	nummax = nummax + compute_m(month2, arraylength);;
	nummax = nummax / 10;
	qDebug("nummax:%d", nummax);
	chartView = new QChartView(createBarChartmonth(month1, month2, nummax));//创建一个m_valueCount列的barChart
	m_ui->gridLayout->addWidget(chartView, 2, 2);  //将chartView添加到Widget的2行，0列，确定显示的位置
	m_charts << chartView;

	//周表
	arraylength = sizeof(week1);
	arraylength = arraylength / sizeof(int);
	//qDebug("length_y:%d", length_y);
	nummax = compute_m(week1, arraylength);
	qDebug("max_y:%d", nummax);
	nummax = nummax + compute_m(week2, arraylength);
	qDebug("max_y:%d", nummax);
	nummax = nummax / 10;
	qDebug("nummax:%d", nummax);
	chartView = new QChartView(createBarChartweek(week1, week2, nummax));//创建一个m_valueCount列的barChart
	
	//将chartView添加到Widget的2行，0列，确定显示的位置
	m_ui->gridLayout->addWidget(chartView, 2, 3);	
	m_charts << chartView;
	
}



ThemeWidget::~ThemeWidget()
{
	delete m_ui;
}

void systime()
{
	QDateTime time1 = QDateTime::currentDateTime();//获取系统现在的时间
	QString BeforeDay1 = time1.addDays(0).toString("yyyy/MM/dd");//获取前一天时间
	QString BeforeDay2 = time1.addDays(-1).toString("yyyy/MM/dd");//获取前一天时间
	QString BeforeDay3 = time1.addDays(-2).toString("yyyy/MM/dd");//获取前一天时间
	QString BeforeDay4 = time1.addDays(-3).toString("yyyy/MM/dd");//获取前一天时间
	QString BeforeDay5 = time1.addDays(-4).toString("yyyy/MM/dd");//获取前一天时间
	QString BeforeDay6 = time1.addDays(-5).toString("yyyy/MM/dd");//获取前一天时间
	QString BeforeDay7 = time1.addDays(-6).toString("yyyy/MM/dd");//获取前一天时间

	QByteArray ba1 = BeforeDay1.toLatin1();
	dayt1 = ba1.data();
	QByteArray ba2 = BeforeDay2.toLatin1();
	dayt2 = ba2.data();
	QByteArray ba3 = BeforeDay3.toLatin1();
	dayt3 = ba3.data();
	QByteArray ba4 = BeforeDay4.toLatin1();
	dayt4 = ba4.data();
	QByteArray ba5 = BeforeDay5.toLatin1();
	dayt5 = ba5.data();
	QByteArray ba6 = BeforeDay6.toLatin1();
	dayt6 = ba6.data();
	QByteArray ba7 = BeforeDay7.toLatin1();
	dayt7 = ba7.data();
	strcpy(dayt7s, dayt7);
	strcpy(dayt6s, dayt6);
	strcpy(dayt5s, dayt5);
	strcpy(dayt4s, dayt4);
	strcpy(dayt3s, dayt3);
	strcpy(dayt2s, dayt2);
	strcpy(dayt1s, dayt1);

	QDateTime time3 = QDateTime::currentDateTime();//获取系统现在的时间
	QString BeforeMonth1 = time3.addDays(0).toString("yyyy/MM");//获取前一天时间
	QString BeforeMonth2 = time3.addDays(-1).toString("yyyy/MM");//获取前一天时间
	QString BeforeMonth3 = time3.addDays(-2).toString("yyyy/MM");//获取前一天时间
	QString BeforeMonth4 = time3.addDays(-3).toString("yyyy/MM");//获取前一天时间

	QByteArray ca1 = BeforeMonth1.toLatin1();
	montht1 = ca1.data();
	QByteArray ca2 = BeforeMonth1.toLatin1();
	montht2 = ca1.data();
	QByteArray ca3 = BeforeMonth1.toLatin1();
	montht3 = ca3.data();
	QByteArray ca4 = BeforeMonth1.toLatin1();
	montht4 = ca4.data();

	strcpy(montht4s, montht4);
	strcpy(montht3s, montht3);
	strcpy(montht2s, montht2);
	strcpy(montht1s, montht1);


	QDateTime time2 = QDateTime::currentDateTime();//获取系统现在的时间
	//QString str = time.toString("MM-dd"); //设置显示格式
	QString Today1 = time2.addDays(0).toString("yyyy/MM/dd/hh:mm:ss");//获取前一天时间
	QString Today2 = time2.addDays(0).toString("yyyy/MM/dd");//获取前一天时间
	

	QByteArray ba8 = Today1.toLatin1();
	systimeA = ba8.data();
	QByteArray ba9 = Today2.toLatin1();
	systimeB = ba9.data();

	strcpy(systemBB, systimeB);
	strcpy(systemAA, systimeA);

	time_t t;
	struct tm* lt;
	time(&t);
	lt = localtime(&t);
	char time11[6][10] = { 0 };
	itoa(lt->tm_year + 1900, time11[0], 10);
	itoa(lt->tm_mon + 1, time11[1], 10);


	char strtime[3][10];
	itoa(lt->tm_year + 1900, strtime[0], 10);
	itoa(lt->tm_mon + 1, strtime[1], 10);
	itoa(lt->tm_mday, strtime[2], 10);
	int year11 = atoi(strtime[0]);
	int month11 = atoi(strtime[1]);
	int day11 = atoi(strtime[2]);


	int week = CountWeek(year11, month11, day11);
	qDebug("week;%d", week);
	qDebug("year11;%d", year11);
	qDebug("month11;%d", month11);
	qDebug("day11;%d", day11);
	int tempw = (year11 % 100) * 100 + week;

	itoa(tempw, writeweek1, 10);
	itoa(tempw - 1, writeweek2, 10);
	itoa(tempw - 2, writeweek3, 10);
	itoa(tempw - 3, writeweek4, 10);

}
void ThemeWidget::update11()
{
	

	int label[] = {4,2,0};
	systime();

	Array_length = sizeof(label) / sizeof(label[0]);
	Arrays(Array_length, label);

	if (label != NULL)
	{
		//1234动作匹配次数
		if (Array_length <= 3)//长度小于3，表明可以识别正确
		{
			//qDebug("Array_length:%d", Array_length);
			for (int i = 0; i < Array_length; i++)
			{
				qDebug("isok0:%d", isok[0]);
				qDebug("isok1:%d", isok[1]);
				qDebug("isok2:%d", isok[2]);
				qDebug("isok3:%d", isok[3]);
				qDebug("isok4:%d", isok[4]);
				switch (ok[i])
				{
				case 0:isok[0] = isok[0] + 1; continue;
				case 1:isok[1] = isok[1] + 1; continue;
				case 2:isok[2] = isok[2] + 1; continue;
				case 3:isok[3] = isok[3] + 1; continue;
				case 4:isok[4] = isok[4] + 1; continue;
				}
			

			}

			if (m == 1)
			{
				//xx[0] = 0;
				y5 = 0;
				m = 0;
			}

		//	qDebug("Array_length <= 3");
			if (isok[0] > 10)//第一个动作
			{
				qDebug("isok[0] > 5");
				y5 = 0;
				if(isok[4]>10)//第五个动作
				{
					y5 = y5 + 1;
					if (y5 == 1)
					{
						qDebug("y5 == 1");
						if (isok[0] > 10)
						{
							qDebug("Action1 is OK");
							printf("Action1 is OK");
							isok_sign[0] = 1;	
							m_ui->Labelok1->setText("OK");
							m_ui->Labelok1->setStyleSheet("background: rgb(0,255,0)");
						
						}
						else
						{
							printf("Action1 is NG");
							isok_sign[0] = 0; 
							m_ui->Labelok1->setText("NG");
							m_ui->Labelok1->setStyleSheet("background: rgb(255,0,0)");
						}

						if (isok[1] > 10)
						{
							printf("Action2 is OK");
							isok_sign[1] = 1;	
							m_ui->Labelok2->setText("OK");
							m_ui->Labelok2->setStyleSheet("background: rgb(0,255,0)");
						}
						else
						{
							printf("Action12 is NG");
							isok_sign[1] = 0;
							m_ui->Labelok2->setText("NG");
							m_ui->Labelok2->setStyleSheet("background: rgb(255,0,0)");
						}
						if (isok[2] > 10)
						{
							printf("Action3 is OK");
							isok_sign[2] = 1;	
							m_ui->Labelok3->setText("OK");
							m_ui->Labelok3->setStyleSheet("background: rgb(0,255,0)");
						}
						else
						{
							printf("Action3 is NG");
							isok_sign[2] = 0; 
							m_ui->Labelok3->setText("NG");
							m_ui->Labelok3->setStyleSheet("background: rgb(255,0,0)");
						}
						if (isok[3] > 10)
						{
							printf("Action4 is OK");
							isok_sign[3] = 1;	
							m_ui->Labelok4->setText("OK");
							m_ui->Labelok4->setStyleSheet("background: rgb(0,255,0)");
						}
						else
						{
							printf("Action4 is NG");
							isok_sign[3] = 0; 
							m_ui->Labelok4->setText("NG");
							m_ui->Labelok4->setStyleSheet("background: rgb(255,0,0)");
						}
						if (isok[4] > 5)
						{
							printf("Action5 is OK");
							isok_sign[4] = 1;	
							m_ui->Labelok5->setText("OK");
							m_ui->Labelok5->setStyleSheet("background: rgb(0,255,0)");
						}
						else
						{
							printf("Action5 is NG");
							isok_sign[4] = 0; 
							m_ui->Labelok5->setText("NG");
							m_ui->Labelok5->setStyleSheet("background: rgb(255,0,0)");
						}
						m = 1;
						total++;
						if(isok[0]>10 && isok[1] > 10 && isok[2] > 10 && isok[3] > 10 && isok[4] > 10)
						{	
							printf("ALL is OK");
							isok_sign[5] = 1;	
							m_ui->Labelokng_color->setText("OK");
							m_ui->Labelokng_color->setStyleSheet("background: rgb(0,255,0)");
							oktotal++;
							day1[6]++;
							week1[3]++;
							month1[3]++;
						}
						else
						{
							printf("something is NG");
							isok_sign[5] = 0; 
							m_ui->Labelokng_color->setText("NG");
							m_ui->Labelokng_color->setStyleSheet("background: rgb(255,0,0)");
							day2[6]++;
							week2[3]++;
							month2[3]++;

						}
						positon_Excel(1, 1, isok_sign);
						
						for (int i = 0; i < 5; i++)
						{
							isok[i] = 0;
						}
				}
					
				}
				
			}
		
		}

		
	}


	if (1)
	{
		QDateTime time_r = QDateTime::currentDateTime();
		QString time_str_r = time_r.toString("yyyy-MM-dd hh:mm:ss dddd");
		m_ui->time_label->setText(time_str_r);
	}

	//实时显示图表
	if (2)
	{
		//total++;
		//oktotal++;
	
		int x[6] = { 1,1,1,1,1 };
		double temp;
		
		m_ui->Labelokdown1->setText("input:" + QString::number(total) + "psc");
		m_ui->Labelokdown2->setText("Ouput:" + QString::number(oktotal) + "psc");
		temp = total - oktotal;
		m_ui->Labelokdown3->setText("NG QTY:" + QString::number(temp) + "psc");
		temp = (double)oktotal / total * 100;
		m_ui->Labelokdown5->setText("Total Yield:" + QString::number(temp, 'f', 2) + "%");
		temp = 100- temp;
		m_ui->Labelokdown4->setText("NG Yield:" + QString::number(temp, 'f', 2) + "%");
		m_ui->gridLayout->SetFixedSize;

		int nummax = 0;
		int arraylength = 0;

		//日表
		arraylength = sizeof(day1);
		arraylength = arraylength / sizeof(int);
		nummax = compute_m(day1, arraylength);
		nummax = nummax + compute_m(day2, arraylength);
		nummax = nummax / 10;
		chartView = new QChartView(createBarChartday(day1, day2, nummax *10+30));//创建一个m_valueCount列的barChart
		QChart::ChartTheme theme = static_cast<QChart::ChartTheme>(
			m_ui->themeComboBox->itemData(m_ui->themeComboBox->currentIndex()).toInt());
		chartView->chart()->setTheme(theme);
		m_ui->gridLayout->addWidget(chartView, 2, 1);
		m_charts << chartView;
		
		//月表
		arraylength = sizeof(month1);
		arraylength = arraylength / sizeof(int);
		nummax = compute_m(month1, arraylength);
		nummax = nummax + compute_m(month2, arraylength);
		nummax = nummax / 10;
		chartView = new QChartView(createBarChartmonth(month1, month2, nummax * 10 + 30));//创建一个m_valueCount列的barChart

		chartView->chart()->setTheme(theme);
		m_ui->gridLayout->addWidget(chartView, 2, 2);
		m_charts << chartView;

		//周表
		arraylength = sizeof(week1);
		arraylength = arraylength / sizeof(int);
		nummax = compute_m(week1, arraylength);
		nummax = nummax + compute_m(week2, arraylength);
		nummax = nummax / 10;

		chartView = new QChartView(createBarChartweek(week1, week2, nummax * 10 + 30));//创建一个m_valueCount列的barChart
		//保持主题
		chartView->chart()->setTheme(theme);
		m_ui->gridLayout->addWidget(chartView, 2, 3);
		m_charts << chartView;
		
		updateUI();//触发主题事件
	}
		qApp->processEvents();

}

void ThemeWidget::populateThemeBox()//设置ThemeBox()下拉菜单的内容和效果
{
	// add items to theme combobox
	m_ui->themeComboBox->addItem("Blue Cerulean", QChart::ChartThemeBlueCerulean);
	m_ui->themeComboBox->addItem("Light", QChart::ChartThemeLight);
	m_ui->themeComboBox->addItem("Dark", QChart::ChartThemeDark);
	m_ui->themeComboBox->addItem("Brown Sand", QChart::ChartThemeBrownSand);
	m_ui->themeComboBox->addItem("Blue NCS", QChart::ChartThemeBlueNcs);
	m_ui->themeComboBox->addItem("High Contrast", QChart::ChartThemeHighContrast);
	m_ui->themeComboBox->addItem("Blue Icy", QChart::ChartThemeBlueIcy);
	m_ui->themeComboBox->addItem("Qt", QChart::ChartThemeQt);
}

void ThemeWidget::populateAnimationBox()//设置AnimationBox()下拉菜单的内容和效果
{
	// add items to animation combobox
	m_ui->animatedComboBox->addItem("No Animations", QChart::NoAnimation);
	m_ui->animatedComboBox->addItem("GridAxis Animations", QChart::GridAxisAnimations);
	m_ui->animatedComboBox->addItem("Series Animations", QChart::SeriesAnimations);
	m_ui->animatedComboBox->addItem("All Animations", QChart::AllAnimations);
}

void ThemeWidget::populateLegendBox()//设置LegendBox下拉菜单的内容和效果
{
	// add items to legend combobox
	m_ui->legendComboBox->addItem("No Legend ", 0);
	m_ui->legendComboBox->addItem("Legend Top", Qt::AlignTop);
	m_ui->legendComboBox->addItem("Legend Bottom", Qt::AlignBottom);
	m_ui->legendComboBox->addItem("Legend Left", Qt::AlignLeft);
	m_ui->legendComboBox->addItem("Legend Right", Qt::AlignRight);
}
int ThemeWidget::compute_m(int arr[], int len) 
{
	int max=arr[0];//这句话影响很大
	for (int i = 0; i < len; i++) {

		if (max < arr[i]) {
			max = arr[i];
		}
	}
	return max;

}

//生成随机数
DataTable ThemeWidget::generateRandomData(int listCount, int valueMax, int valueCount) const
{
	DataTable dataTable;

	// generate random data
	for (int i(0); i < listCount; i++) {
		DataList dataList;
		qreal yValue(0);
		for (int j(0); j < valueCount; j++) {
			yValue = yValue + QRandomGenerator::global()->bounded(valueMax / (qreal)valueCount);
			QPointF value((j + QRandomGenerator::global()->generateDouble()) * ((qreal)m_valueMax / (qreal)valueCount),
				yValue);
			QString label = "Slice " + QString::number(i) + ":" + QString::number(j);//生成字符串
			dataList << Data(value, label);
		}
		dataTable << dataList;
	}
	return dataTable;
}

QChart* ThemeWidget::createBarChartday(int x1[], int x2[],int max) const //创建BarChart函数
{
//Q_UNUSED(valueCount);
	QChart* chart = new QChart();
	chart->setTitle("Report for last seven day");
	//int x1[] = { 25,30,25,29,30,26 };
	//int x2[] = { 2,3,2,2,3,2};
	QStackedBarSeries* series = new QStackedBarSeries(chart);
	if(1){
		QBarSet* set = new QBarSet("OK");
		*set << x1[0] << x1[1] << x1[2] << x1[3] << x1[4] << x1[5] << x1[6];
		series->append(set);
		}

		QBarSet* set = new QBarSet("NG");
		*set << x2[0] << x2[1] << x2[2] << x2[3] << x2[4] << x2[5]<< x2[6];
		series->append(set);
		chart->addSeries(series);
    	//定义字符串列表，用于X轴标签
		//chart->createDefaultAxes();//设置XY轴为默认值
	
		QDateTime time = QDateTime::currentDateTime();//获取系统现在的时间
		//QString str = time.toString("MM-dd"); //设置显示格式
		QString BeforeDay1 = time.addDays(0).toString("MM-dd");//获取前一天时间
		QString BeforeDay2 = time.addDays(-1).toString("MM-dd");//获取前一天时间
		QString BeforeDay3 = time.addDays(-2).toString("MM-dd");//获取前一天时间
		QString BeforeDay4 = time.addDays(-3).toString("MM-dd");//获取前一天时间
		QString BeforeDay5 = time.addDays(-4).toString("MM-dd");//获取前一天时间
		QString BeforeDay6= time.addDays(-5).toString("MM-dd");//获取前一天时间
		QString BeforeDay7 = time.addDays(-6).toString("MM-dd");//获取前一天时间

		QStringList categories;
		categories << BeforeDay7 << BeforeDay6 << BeforeDay5<< BeforeDay4<< BeforeDay3<< BeforeDay2<< BeforeDay2 << BeforeDay1;
		//设置X轴参数
		QBarCategoryAxis* axisX = new QBarCategoryAxis();
		axisX->append(categories);//设置X轴标签
		Q_ASSERT(axisX);
		chart->addAxis(axisX, Qt::AlignBottom); //将系列标签放到底下
		series->attachAxis(axisX);

		QValueAxis* axisY = new QValueAxis();
		axisY->setRange(0, max);
		chart->addAxis(axisY, Qt::AlignLeft);//放到左边
		series->attachAxis(axisY);

	return chart;
}

QChart* ThemeWidget::createBarChartmonth(int x1[], int x2[], int max) const //创建BarChart函数
{
	//Q_UNUSED(valueCount);
	QChart* chart = new QChart();
	chart->setTitle("Report for last four month");
	QStackedBarSeries* series = new QStackedBarSeries(chart);
	if (1) {		
		QBarSet* set = new QBarSet("OK");
		*set << x1[0] << x1[1] << x1[2] << x1[3];
		series->append(set);
	}
	QBarSet* set = new QBarSet("NG");
	*set << x2[0] << x2[1] << x2[2] << x2[3] ;
	series->append(set);
	chart->addSeries(series);

	time_t t;
	struct tm* lt;
	time(&t);
	lt = localtime(&t);
	char strtime[3][10];

	itoa(lt->tm_mon + 1, strtime[1], 10);

	int month11 = atoi(strtime[1]);

	//定义字符串列表，用于X轴标签
	//chart->createDefaultAxes();//设置XY轴为默认值
	QStringList categories;
	categories << QString::number(month11 - 3) + QString::fromLocal8Bit("月") << QString::number(month11 - 2) + QString::fromLocal8Bit("月") << QString::number(month11 - 1) + QString::fromLocal8Bit("月") << QString::number(month11) + QString::fromLocal8Bit("月");
	//设置X轴参数
	QBarCategoryAxis* axisX = new QBarCategoryAxis();
	axisX->append(categories);//设置X轴标签
	Q_ASSERT(axisX);
	chart->addAxis(axisX, Qt::AlignBottom); //将系列标签放到底下
	series->attachAxis(axisX);
	
	QValueAxis* axisY = new QValueAxis();
	axisY->setRange(0,  max);
	chart->addAxis(axisY, Qt::AlignLeft);//放到左边
	series->attachAxis(axisY);

	return chart;
}

QChart* ThemeWidget::createBarChartweek(int x1[], int x2[],int max) const //创建BarChart函数
{
	//Q_UNUSED(valueCount);
	QChart* chart = new QChart();
	chart->setTitle("Report for last five week");
	QStackedBarSeries* series = new QStackedBarSeries(chart);
	if (1) {
		QBarSet* set = new QBarSet("OK");
		*set << x1[0] << x1[1] << x1[2] << x1[3] << x1[4] ;
		series->append(set);
	}
	QBarSet* set = new QBarSet("NG");
	*set << x2[0] << x2[1] << x2[2] << x2[3] << x2[4];
	series->append(set);
	chart->addSeries(series);
	//定义字符串列表，用于X轴标签
	//chart->createDefaultAxes();//设置XY轴为默认值
	
	time_t t;
	struct tm* lt;
	time(&t);
	lt = localtime(&t);
	char strtime[3][10];
	itoa(lt->tm_year + 1900, strtime[0], 10);
	itoa(lt->tm_mon + 1, strtime[1], 10);
	itoa(lt->tm_mday, strtime[2], 10);
	int year11 = atoi(strtime[0]);
	int month11 = atoi(strtime[1]);
	int day11 = atoi(strtime[2]);
	int week = CountWeek(year11, month11, day11);
	
	//定义字符串列表，用于X轴标签
	//chart->createDefaultAxes();//设置XY轴为默认值
	QStringList categories;
	categories << "w" + QString::number(year11 % 100) + QString::number(week - 3) << "w" + QString::number(year11 % 100) + QString::number(week - 2) << "w" + QString::number(year11 % 100) + QString::number(week - 1) << "w" + QString::number(year11 % 100) + QString::number(week);
	//设置X轴参数
	QBarCategoryAxis* axisX = new QBarCategoryAxis();
	axisX->append(categories);//设置X轴标签
	Q_ASSERT(axisX);
	chart->addAxis(axisX, Qt::AlignBottom); //将系列标签放到底下
	series->attachAxis(axisX);
	
	QValueAxis* axisY = new QValueAxis();
	axisY->setRange(0,  max);
	chart->addAxis(axisY, Qt::AlignLeft);//放到左边
	series->attachAxis(axisY);

	return chart;
}


QChart* ThemeWidget::createBarChart(int valueCount) const //创建BarChart函数
{
	Q_UNUSED(valueCount);
	QChart* chart = new QChart();
	chart->setTitle("Bar chart");

	QStackedBarSeries* series = new QStackedBarSeries(chart);
	for (int i(0); i < m_dataTable.count(); i++) {
		QBarSet* set = new QBarSet("Bar set " + QString::number(i));
		for (const Data& data : m_dataTable[i])
		{
			*set << data.first.y();
		
		}series->append(set);
	}


	chart->addSeries(series);
	chart->createDefaultAxes();

	chart->axes(Qt::Vertical).first()->setRange(0, m_valueMax * 3);//设置Y轴最大最小值
	// Add space to label to add space between labels and axis
	QValueAxis* axisY = qobject_cast<QValueAxis*>(chart->axes(Qt::Vertical).first());
	Q_ASSERT(axisY);
	axisY->setLabelFormat("%.1f  ");

	return chart;
}
QChart* ThemeWidget::createSplineChart() const//创建SplineChart()函数
{
	QChart* chart = new QChart();
	chart->setTitle("Spline chart");
	QString name("Series ");
	int nameIndex = 0;
	for (const DataList& list : m_dataTable) {
		QSplineSeries* series = new QSplineSeries(chart);
		for (const Data& data : list)
			series->append(data.first);
		series->setName(name + QString::number(nameIndex));
		nameIndex++;
		chart->addSeries(series);
	}

	chart->createDefaultAxes();
	chart->axes(Qt::Horizontal).first()->setRange(0, m_valueMax);
	chart->axes(Qt::Vertical).first()->setRange(0, m_valueCount);

	// Add space to label to add space between labels and axis
	QValueAxis* axisY = qobject_cast<QValueAxis*>(chart->axes(Qt::Vertical).first());
	Q_ASSERT(axisY);
	axisY->setLabelFormat("%.1f  ");
	return chart;
}
void ThemeWidget::editlock() //锁定
{	
	m_ui->alsName2->setEnabled(false);
	qDebug("nihaoaooa");
}
void ThemeWidget::editunlock() //锁定
{
	m_ui->alsName2->setEnabled(true);
	
	qDebug("nihaoaooa");
}
void ThemeWidget::updateUI()  //更新UI界面函数
{
	QChart::ChartTheme theme = static_cast<QChart::ChartTheme>(
		m_ui->themeComboBox->itemData(m_ui->themeComboBox->currentIndex()).toInt());
	const auto charts = m_charts;
	if (!m_charts.isEmpty() && m_charts.at(0)->chart()->theme() != theme) {
		for (QChartView* chartView : charts) {
			chartView->chart()->setTheme(theme);
		}

		// Set palette colors based on selected theme
		QPalette pal = window()->palette();
		if (theme == QChart::ChartThemeLight) {
			pal.setColor(QPalette::Window, QRgb(0xf0f0f0));
			pal.setColor(QPalette::WindowText, QRgb(0x404044));
		}
		else if (theme == QChart::ChartThemeDark) {
			pal.setColor(QPalette::Window, QRgb(0x121218));
			pal.setColor(QPalette::WindowText, QRgb(0xd6d6d6));
		}
		else if (theme == QChart::ChartThemeBlueCerulean) {
			pal.setColor(QPalette::Window, QRgb(0x40434a));
			pal.setColor(QPalette::WindowText, QRgb(0xd6d6d6));
		}
		else if (theme == QChart::ChartThemeBrownSand) {
			pal.setColor(QPalette::Window, QRgb(0x9e8965));
			pal.setColor(QPalette::WindowText, QRgb(0x404044));
		}
		else if (theme == QChart::ChartThemeBlueNcs) {
			pal.setColor(QPalette::Window, QRgb(0x018bba));
			pal.setColor(QPalette::WindowText, QRgb(0x404044));
		}
		else if (theme == QChart::ChartThemeHighContrast) {
			pal.setColor(QPalette::Window, QRgb(0xffab03));
			pal.setColor(QPalette::WindowText, QRgb(0x181818));
		}
		else if (theme == QChart::ChartThemeBlueIcy) {
			pal.setColor(QPalette::Window, QRgb(0xcee7f0));
			pal.setColor(QPalette::WindowText, QRgb(0x404044));
		}
		else {
			pal.setColor(QPalette::Window, QRgb(0xf0f0f0));
			pal.setColor(QPalette::WindowText, QRgb(0x404044));
		}
		window()->setPalette(pal);
	}

	// Update antialiasing
	bool checked = m_ui->antialiasCheckBox->isChecked();
	for (QChartView* chart : charts)
		chart->setRenderHint(QPainter::Antialiasing, checked);

	// Update animation options
	QChart::AnimationOptions options(
		m_ui->animatedComboBox->itemData(m_ui->animatedComboBox->currentIndex()).toInt());
	if (!m_charts.isEmpty() && m_charts.at(0)->chart()->animationOptions() != options) {
		for (QChartView* chartView : charts)
			chartView->chart()->setAnimationOptions(options);
	}

	// Update legend alignment
	Qt::Alignment alignment(
		m_ui->legendComboBox->itemData(m_ui->legendComboBox->currentIndex()).toInt());

	if (!alignment) {
		for (QChartView* chartView : charts)
			chartView->chart()->legend()->hide();
	}
	else {
		for (QChartView* chartView : charts) {
			chartView->chart()->legend()->setAlignment(alignment);
			chartView->chart()->legend()->show();
		}
	}
	//![10]
}
short ThemeWidget::Test(QString rowcolum)
{
	QAxObject* excel = NULL;    //本例中，excel设定为Excel文件的操作对象
	QAxObject* workbooks = NULL;
	QAxObject* workbook = NULL;  //Excel操作对象
	excel = new QAxObject("Excel.Application");
	excel->dynamicCall("SetVisible(bool)", false); //true 表示操作文件时可见，false表示为不可见
	workbooks = excel->querySubObject("WorkBooks");
	//按文件路径打开文件
	workbook = workbooks->querySubObject("Open(QString&)", QDir::currentPath() + "/ALS By Pass.xls");
	// 获取打开的excel文件中所有的工作sheet
	QAxObject* worksheets = workbook->querySubObject("WorkSheets");
	//Excel文件中表的个数:
	int iWorkSheet = worksheets->property("Count").toInt();
	
	// 获取第n个工作表 querySubObject("Item(int)", n);
	QAxObject* worksheet = worksheets->querySubObject("Item(int)", 1);//本例获取第一个，最后参数填1

	//获取该sheet的数据范围（可以理解为有数据的矩形区域
	QAxObject* usedrange = worksheet->querySubObject("UsedRange");

	//获取行数
	QAxObject* rows = usedrange->querySubObject("Rows");
	int iRows = rows->property("Count").toInt();
	//————————————获取列数—————————
	QAxObject* columns = usedrange->querySubObject("Columns");
	int iColumns = columns->property("Count").toInt();
	//——————————————读出数据—————————————
	//获取第i行第j列的数据
	//假如是第6行，第6列 对应表中F列6行，即F6
	//QAxObject* range1 = worksheet->querySubObject("Range(QString)", "F6");
	QAxObject* range1 = worksheet->querySubObject("Range(QString)", rowcolum);
	QString strRowCol = "";
	strRowCol = range1->property("Value").toString();
	qDebug() << "A1:" + strRowCol;

	//close，不然系统进程里会出现n个EXCEL.EXE进程
	workbook->dynamicCall("Close()");
	excel->dynamicCall("Quit()");
	const char* str = strRowCol.toStdString().data();
	if (excel)
	{
		delete excel;
		excel = NULL;
	}

	if (QString::compare("OK", strRowCol)== 0)
	{
		return 1;
	}
	else if (QString::compare("NG", strRowCol) == 0)
	{
		return 0;
	}
	else
		return 2;
}
//按行列，读取excel函数
short readExcel(short colum)
{
	char str1[20];
	char str_d[20]={0};
	char day_temp[12]={0};

	char strw[20] = { 0 };

	char month_temp[7] = {0};
	char str_m[20];

	int cc;
	short signcc;
	FILE* fp = NULL;
	FILE* fp2 = NULL;
	FILE* fp3 = NULL;
	fp = fopen("ALS By Pass.xls", "r");
	fp2 = fopen("ALS By Pass.xls", "r");
	fp3 = fopen("ALS By Pass.xls", "r");
	short count = 0;
	daysign = 8;
	if (fp != NULL)
	{
		for(int i=0;i<colum;i++)
		{
			signcc = 2;

		    for(int j=1;j<10;j++)
		    {
				fscanf(fp2, "%s", str1);


				if (j == 1 && str1[0] == '2'&& str1[5] <='9'&& str1[5] >= '0')
				{
					strcpy(str_m, str1);
					
				}

				if (j == 3 && str1[0] == '1' || str1[0] == '2')
				{
					strcpy(strw, str1);

				}

		    }
			for (int m=0;m<7;m++)
			{
				month_temp[m] = str_m[m];
			}
			for (int n = 0; n < 10; n++)
			{
				day_temp[n] = str_m[n];
			}
			if (strcmp(dayt7s, day_temp) == 0)
			{
				daysign = 1;
			}
			else if (strcmp(dayt6s, day_temp) == 0)
			{
				daysign = 2;
			}
			else if (strcmp(dayt5s, day_temp) == 0)
			{
				daysign = 3;
			}
			else if (strcmp(dayt4s, day_temp) == 0)
			{
				daysign = 4;
			}
			else if (strcmp(dayt3s, day_temp) == 0)
			{
				daysign = 5;
			}
			else if (strcmp(dayt2s, day_temp) == 0)
			{
				daysign = 6;
			}
			else if (strcmp(dayt1s, day_temp) == 0)
			{
				daysign = 7;
			}
			else
				daysign = 8;

			//qDebug("writeweek1:%s",writeweek1);
			 if (strcmp(writeweek1, strw) == 0)
			{
				weeksign = 4;
			}
			else if (strcmp(writeweek2, strw) == 0)
			{
				 weeksign = 3;
			}
			else if (strcmp(writeweek3, strw) == 0)
			{
				 weeksign = 2;
			}
			else if (strcmp(writeweek4, strw) == 0)
			{
				 weeksign = 1;
			}
			else
				 weeksign = 8;

			// qDebug("weeksign:%d", weeksign);
			 if (strcmp(montht1s, month_temp) == 0)
			 {
				 monthsign = 4;
			 }
			 else if (strcmp(montht2s, month_temp) == 0)
			 {
				 monthsign = 3;
			 }
			 else if (strcmp(montht3s, month_temp) == 0)
			 {
				 monthsign = 2;
			 }
			 else if (strcmp(montht4s, month_temp) == 0)
			 {
				 monthsign = 1;
			 }
			 else
				 monthsign = 8;

			 //qDebug("monthsign:%d", monthsign);
			while (1)
			{
				cc = fgetc(fp);
			
				if (cc == EOF)
				{
					endsign = 0;
					break;
				}
				else
				{
					endsign = 123;
				}
		
				if (cc == 'N' || cc == 'O')
				{
					count++;
					if(count==1)
					{
						if (cc == 'N')
							signcc = 0;
						if (cc == 'O')
							signcc = 1;
					}
					if (count == 6)
					{
						count = 0; break;
					}					
				}
			}
			
		}

	}
	if (signcc == 1)
	{
		return 1;
	}
	else if (signcc == 0)
	{
		return 0;
	}
	else
	{
		return 2;
	}
}
//存取数据
void positon_Excel(short row, short colum, short xx[6])
{
	FILE* fpo=NULL;
	fpo = fopen("ALS By Pass.xls", "a+");

	if (fpo != NULL)
	{
		for (int i = 1; i < row; i++)
		{
			//fputs("\t", fp);
			fprintf(fpo, "\n");//移动到第row行
			//printf("移动到第i行\n");
		}
		for (int i = 1; i < colum; i++)
		{
			fprintf(fpo, "\t");//移动到第colum列
			//printf("移动到第i列\n");
		}
		fprintf(fpo, "%s\t", systemAA);
		fprintf(fpo, "%s\t", systemBB);
	//	fprintf(fpo, "%s\t", systemCC);
		fprintf(fpo, "%s\t", writeweek1);

		switch (xx[5])//xx[5]存整体是否成功
		{
		case 1:	fprintf(fpo, "%s\t", "OK"); fprintf(fpo, "\t"); break;//存入数据str
		case 0:	fprintf(fpo, "%s\t", "NG"); fprintf(fpo, "\t"); break;
		}

		for (int i = 0; i < 5; i++)
		{
			switch (xx[i])
			{
			case 1:	fprintf(fpo, "%s\t", "OK"); continue;//存入数据str
			case 0:	fprintf(fpo, "%s\t", "NG"); continue;
			}
		}
		fprintf(fpo, "\n");

	}

	fclose(fpo);

}
//动态数组
void Arrays(int num, int label[])
{
	ok = (int*)malloc(sizeof(int) * num);//定义动态数组
	int i = 0;
	printf("length=%d\n", num);
	for (i = 0; i < num; i++)
	{
		ok[i] = label[i];
		printf(" p1[%d]=%d\n", i, ok[i]);
	}
}
//返回系统时间
int CountDay(int year, int month, int day)
{
	int x = day;
	int IsLeapYear = (!(year % 4) && (year % 100) || !(year % 400)) ? 1 : 0;
	if (IsLeapYear == 1) date[1] = 29;
	for (int i = 0; i < month - 1; i++)
	{
		x += date[i];
	}
	return x;
}
int CountWeek(int year, int month, int day)
{
	int x;
	if (CountDay(year, month,day) % 7 == 0) x = CountDay(year, month, day) / 7;
	else x = CountDay(year, month, day) / 7 + 1;
	return x;
}