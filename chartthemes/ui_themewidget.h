/********************************************************************************
** Form generated from reading UI file 'themewidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_THEMEWIDGET_H
#define UI_THEMEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include <QtWidgets>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QApplication>
#include <QtWidgets/QVBoxLayout>
#include<QTextCodec>
#include<QDebug>

QT_BEGIN_NAMESPACE


class Ui_ThemeWidgetForm
{
public:
	
	QGridLayout* gridLayout;
	QHBoxLayout* horizontalLayout;
	QLabel* themeLabel;
	QComboBox* themeComboBox;
	QLabel* animatedLabel;
	QComboBox* animatedComboBox;
	QLabel* legendLabel;
	QComboBox* legendComboBox;
	QCheckBox* antialiasCheckBox;
	QSpacerItem* horizontalSpacer;
	QVBoxLayout* QVLayout;
	QLineEdit* System_name;
	QFont ft;//设置字体
	QHBoxLayout* horizontalLayout3;//第三行
	QLabel* alsName;
	QLineEdit* alsName2;
	QHBoxLayout* horizontalLayoutname;
	QPushButton* name_enter;
	QPushButton* name_quit;
	QLabel* time_label;
	QDateTime time;
	QString time_str;
	QVBoxLayout* QVLayoutok1; QVBoxLayout* QVLayoutok2; QVBoxLayout* QVLayoutok3; QVBoxLayout* QVLayoutok4; QVBoxLayout* QVLayoutok5;
	QPushButton* Labelok1;	QPushButton* Labelok2;	QPushButton* Labelok3;	QPushButton* Labelok4;	QPushButton* Labelok5;
	QLabel* Labelokdown1; QLabel* Labelokdown2; QLabel* Labelokdown3; QLabel* Labelokdown4; QLabel* Labelokdown5;
	QHBoxLayout* QHLayoutsign;
	QPushButton* Labelokng_color;
	QPushButton* call_sign;

	void setupUi(QWidget* ThemeWidgetForm)
	{
		
		if (ThemeWidgetForm->objectName().isEmpty())
			ThemeWidgetForm->setObjectName(QString::fromUtf8("ThemeWidgetForm"));
		ThemeWidgetForm->resize(900, 600);//初始化窗口完成

		gridLayout = new QGridLayout(ThemeWidgetForm);//定义QGridLayout
		gridLayout->setObjectName(QString::fromUtf8("gridLayout"));//对QGridLayout命名
	
		horizontalLayout = new QHBoxLayout();//定义一个水平布置
		horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));//定义该水平布置名称
	
		QVLayout = new QVBoxLayout(ThemeWidgetForm);//定义垂直布置
		System_name = new QLineEdit("ALS Test By Pass Monitor System");//定义LineEdit，并命名为...

	//	System_name->setStyleSheet("color:red");//文本颜色
		System_name->setStyleSheet("background-color: rgb(5,94,133);border-style:outset");//设置System_name的背景色
		System_name->setAlignment(Qt::AlignCenter);//设置System_name居中
		System_name->setMaximumHeight(80);
		System_name->setMinimumHeight(80);//设置System_name的背景色

	
		ft.setPointSize(26);//设置字体大小
		System_name->setFont(ft);//设置System_name字体大小
		

		horizontalLayout3 = new QHBoxLayout();
		alsName = new QLabel("Model:");
		alsName2 = new QLineEdit();
		alsName2->setGeometry(60,100,100,20);

	    horizontalLayoutname = new QHBoxLayout();
		horizontalLayoutname->addWidget(alsName);
		horizontalLayoutname->addWidget(alsName2, 0, Qt::AlignLeft);

		name_enter = new QPushButton(QString::fromLocal8Bit("锁定"));
		name_quit = new QPushButton(QString::fromLocal8Bit("解锁"));
		horizontalLayoutname->addWidget(name_enter);
		horizontalLayoutname->addWidget(name_quit);

		time_label = new QLabel();
		time = QDateTime::currentDateTime();
		time_str= time.toString("yyyy-MM-dd hh:mm:ss dddd");
		//time_label->setText(QTime::currentTime().toString());//只显示时分秒
		time_label->setText(time_str);
		horizontalLayoutname->addWidget(time_label,2, Qt::AlignRight);
		
		
			QVLayoutok1 = new QVBoxLayout(ThemeWidgetForm);
			Labelok1 = new QPushButton(QString::fromLocal8Bit("OK"));
			Labelok1->setStyleSheet("background: rgb(0,255,0)");
			Labelok1->setMaximumSize(60,60);
			Labelok1->setMinimumSize(60, 60);
			QLabel* Labelok1up1 = new QLabel(QString::fromLocal8Bit("Get Panel"));
			
			static int i1 = 2500;
			i1++;
			qDebug("%d", i1);
			QString s1 = QString::number(i1);//数字转字符串
			 Labelokdown1 = new QLabel();
			Labelokdown1 -> setText("input:" + s1 + "psc");
			ft.setPointSize(16);
			Labelok1->setFont(ft);
			ft.setPointSize(14);
			Labelok1up1->setFont(ft);
			ft.setPointSize(12);
			Labelokdown1->setFont(ft);
			QVLayoutok1->addWidget(Labelok1up1, 0, Qt::AlignHCenter);
			QVLayoutok1->addWidget(Labelok1, 0, Qt::AlignHCenter);
			QVLayoutok1->addWidget(Labelokdown1, 0, Qt::AlignHCenter);

			QVLayoutok2 = new QVBoxLayout(ThemeWidgetForm);
			Labelok2 = new QPushButton(QString::fromLocal8Bit("OK"));
			Labelok2->setStyleSheet("background: rgb(0,255,0)");
			Labelok2->setMaximumSize(60, 60);
			Labelok2->setMinimumSize(60, 60);
			QLabel* Labelok1up2 = new QLabel(QString::fromLocal8Bit("Scan Code"));

			int i2 = 2480;
			QString s2 = QString::number(i2);//数字转字符串
			Labelokdown2 = new QLabel("Ouput:" + s2 + "psc");

			ft.setPointSize(16);
			Labelok2->setFont(ft);
			ft.setPointSize(14);
			Labelok1up2->setFont(ft);
			ft.setPointSize(12);
			Labelokdown2->setFont(ft);
			QVLayoutok2->addWidget(Labelok1up2, 0, Qt::AlignHCenter);
			QVLayoutok2->addWidget(Labelok2, 0, Qt::AlignHCenter);
			QVLayoutok2->addWidget(Labelokdown2, 0, Qt::AlignHCenter);

			QVLayoutok3 = new QVBoxLayout(ThemeWidgetForm);
			Labelok3 = new QPushButton(QString::fromLocal8Bit("OK"));
			Labelok3->setStyleSheet("background: rgb(0,255,0)");
			Labelok3->setMaximumSize(60, 60);
			Labelok3->setMinimumSize(60, 60);
			QLabel* Labelok1up3 = new QLabel(QString::fromLocal8Bit("Put the Fixture"));

			double i3 = (i1-i2)/ i1;
			QString s3 = QString::number(i3);//数字转字符串
			Labelokdown3 = new QLabel("NG QTY:" + s3 + "pcs");

			ft.setPointSize(16);
			Labelok3->setFont(ft);
			ft.setPointSize(14);
			Labelok1up3->setFont(ft);
			ft.setPointSize(12);
			Labelokdown3->setFont(ft);
			QVLayoutok3->addWidget(Labelok1up3, 0, Qt::AlignHCenter);
			QVLayoutok3->addWidget(Labelok3, 0, Qt::AlignHCenter);
			QVLayoutok3->addWidget(Labelokdown3, 0, Qt::AlignHCenter);


			QVLayoutok4 = new QVBoxLayout(ThemeWidgetForm);
			Labelok4 = new QPushButton(QString::fromLocal8Bit("OK"));
			Labelok4->setStyleSheet("background: rgb(0,255,0)");
			Labelok4->setMaximumSize(60, 60);
			Labelok4->setMinimumSize(60, 60);
			QLabel* Labelok1up4 = new QLabel(QString::fromLocal8Bit("Start test"));

			double i4 = i3/i2;
			QString s4 = QString::number(i4);//数字转字符串
			Labelokdown4= new QLabel("NG Yield:" + s4 + "%");

			ft.setPointSize(16);
			Labelok4->setFont(ft);
			ft.setPointSize(14);
			Labelok1up4->setFont(ft);
			ft.setPointSize(12);
			Labelokdown4->setFont(ft);
			QVLayoutok4->addWidget(Labelok1up4,0, Qt::AlignHCenter);
			QVLayoutok4->addWidget(Labelok4, 0, Qt::AlignHCenter);
			QVLayoutok4->addWidget(Labelokdown4, 0, Qt::AlignHCenter);

			QVLayoutok5 = new QVBoxLayout(ThemeWidgetForm);
			Labelok5 = new QPushButton(QString::fromLocal8Bit("OK"));
			Labelok5->setStyleSheet("background: rgb(0,255,0)");
			Labelok5->setMaximumSize(60, 60);
			Labelok5->setMinimumSize(60, 60);
			QLabel* Labelok1up5 = new QLabel(QString::fromLocal8Bit("Put panel"));

			double i5 = i2 / i1;
			QString s5 = QString::number(i5);//数字转字符串
			Labelokdown5 = new QLabel("Total Yield:" + s5 + "%");
			ft.setPointSize(16);
			Labelok5->setFont(ft);
			ft.setPointSize(14);
			Labelok1up5->setFont(ft);
			ft.setPointSize(12);
			Labelokdown5->setFont(ft);
			QVLayoutok5->addWidget(Labelok1up5, 0, Qt::AlignHCenter);
			QVLayoutok5->addWidget(Labelok5, 0, Qt::AlignHCenter);
			QVLayoutok5->addWidget(Labelokdown5, 0, Qt::AlignHCenter);


			horizontalLayout3->addLayout(QVLayoutok1);
			horizontalLayout3->addLayout(QVLayoutok2);
			horizontalLayout3->addLayout(QVLayoutok3);
			horizontalLayout3->addLayout(QVLayoutok4);
			horizontalLayout3->addLayout(QVLayoutok5);
			
		    QHBoxLayout* QHLayoutsign = new QHBoxLayout(ThemeWidgetForm);
			
			Labelokng_color = new QPushButton(QString::fromLocal8Bit("OK"));
			Labelokng_color->setStyleSheet("background: rgb(0,255,0)");
			
			Labelokng_color->setMaximumSize(60, 60);
			Labelokng_color->setMinimumSize(60, 60);

			QLabel* Labelokng = new QLabel(QString::fromLocal8Bit("Red/Green:"));
			ft.setPointSize(16);
			Labelokng_color->setFont(ft);
			ft.setPointSize(14);
			Labelokng->setFont(ft);

			QHLayoutsign->addStretch(1);
			QHLayoutsign->addWidget(Labelokng);
			QHLayoutsign->addWidget(Labelokng_color );
			QHLayoutsign->addStretch(1);

			QPushButton* call_sign = new QPushButton(QString::fromLocal8Bit("警报"));
			call_sign->setStyleSheet("background: rgb(255,0,0)");

		    //警报设计
			call_sign->setMaximumSize(60, 60);
			call_sign->setMinimumSize(60, 60);

			QLabel* Alarm = new QLabel(QString::fromLocal8Bit("Alarm:"));
			ft.setPointSize(12);
			call_sign->setFont(ft);
			ft.setPointSize(14);
			Alarm->setFont(ft);
			QHLayoutsign->addWidget(Alarm);
			QHLayoutsign->addWidget(call_sign);
			QHLayoutsign->addStretch(1);
			
	
			themeLabel = new QLabel(ThemeWidgetForm);
			themeLabel->setObjectName(QString::fromUtf8("themeLabel"));
			horizontalLayout->addWidget(themeLabel, 0, Qt::AlignLeft);

			themeComboBox = new QComboBox(ThemeWidgetForm);
			themeComboBox->setObjectName(QString::fromUtf8("themeComboBox"));
			horizontalLayout->addWidget(themeComboBox, 0, Qt::AlignLeft);

			animatedLabel = new QLabel(ThemeWidgetForm);
			animatedLabel->setObjectName(QString::fromUtf8("animatedLabel"));
			horizontalLayout->addWidget(animatedLabel, 0, Qt::AlignLeft);

			animatedComboBox = new QComboBox(ThemeWidgetForm);
			animatedComboBox->setObjectName(QString::fromUtf8("animatedComboBox"));
			horizontalLayout->addWidget(animatedComboBox, 0, Qt::AlignLeft);

			legendLabel = new QLabel(ThemeWidgetForm);
			legendLabel->setObjectName(QString::fromUtf8("legendLabel"));
			horizontalLayout->addWidget(legendLabel, 0, Qt::AlignLeft);

			legendComboBox = new QComboBox(ThemeWidgetForm);
			legendComboBox->setObjectName(QString::fromUtf8("legendComboBox"));
			horizontalLayout->addWidget(legendComboBox, 0, Qt::AlignLeft);

			antialiasCheckBox = new QCheckBox(ThemeWidgetForm);
			antialiasCheckBox->setObjectName(QString::fromUtf8("antialiasCheckBox"));
			antialiasCheckBox->setChecked(false);
			horizontalLayout->addWidget(antialiasCheckBox, 0, Qt::AlignLeft);
	
			
			QVLayout->addWidget(System_name);
			horizontalLayout->addStretch(1);
			QVLayout->addLayout(horizontalLayout, Qt::AlignRight);
			QVLayout->addLayout(horizontalLayoutname);
			QVLayout->addLayout(horizontalLayout3); 
			QVLayout->addLayout(QHLayoutsign);

			gridLayout->addLayout(QVLayout, 0, 0, 2, 4);

			retranslateUi(ThemeWidgetForm);
			listconnect(ThemeWidgetForm);

} 
void listconnect(QWidget* ThemeWidgetForm)
	{
		
	QObject::connect(themeComboBox, SIGNAL(currentIndexChanged(int)), ThemeWidgetForm, SLOT(updateUI()));
	QObject::connect(antialiasCheckBox, SIGNAL(toggled(bool)), ThemeWidgetForm, SLOT(updateUI()));
	QObject::connect(legendComboBox, SIGNAL(currentIndexChanged(int)), ThemeWidgetForm, SLOT(updateUI()));
	QObject::connect(animatedComboBox, SIGNAL(currentIndexChanged(int)), ThemeWidgetForm, SLOT(updateUI()));
	QObject::connect(name_enter, SIGNAL(clicked()), ThemeWidgetForm, SLOT(editlock()));
	QObject::connect(name_quit, SIGNAL(clicked()), ThemeWidgetForm, SLOT(editunlock()));
    //setReadOnly(false)
	//qDebug("nihao%d",bb++);
	QMetaObject::connectSlotsByName(ThemeWidgetForm);
	}
void retranslateUi(QWidget* ThemeWidgetForm)
{
	themeLabel->setText(QApplication::translate("ThemeWidgetForm", "Theme:", nullptr));
	animatedLabel->setText(QApplication::translate("ThemeWidgetForm", "Animation:", nullptr));
	legendLabel->setText(QApplication::translate("ThemeWidgetForm", "Legend:", nullptr));
	antialiasCheckBox->setText(QApplication::translate("ThemeWidgetForm", "Anti-aliasing", nullptr));
	Q_UNUSED(ThemeWidgetForm);
} // retranslateUi
};



namespace Ui {
	class ThemeWidgetForm : public Ui_ThemeWidgetForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_THEMEWIDGET_H
