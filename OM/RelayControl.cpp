#include "RelayControl.h"
#include "qdatetime.h"
#include "QtCharts/QChart"
#include "QtCharts/qlineseries.h"
#include "QtCharts/qvalueaxis.h"
#include "QtCharts/qchartview.h"
#include "qboxlayout.h"
#include "QTimer"
#include "QTime"
#include "QList"
#include "qmath.h"
#include "QPointF"
#include "QDebug"
#include "cmyini.h"

QT_CHARTS_USE_NAMESPACE
QChart* m_chart;
QChartView* chartView;
QLineSeries* m_series1;//线1
QLineSeries* m_series2;//线2
QLineSeries* m_series3;//线3
//QList<double> dataList;//存储业务数据
int maxSize = 1000;//x轴长度
//QTimer updateTimer;
int timeId;

#pragma execution_character_set("utf-8")

RelayControl::RelayControl()
{
	ui.setupUi(this);

	m_chart = new QChart();
	chartView = new QChartView(m_chart, this);
	//    v.setRubberBand(QChartView::HorizontalRubberBand);
	chartView->setRubberBand(QChartView::RectangleRubberBand);
	//    chartView->setRubberBand();

	m_series1 = new QLineSeries;
	m_chart->addSeries(m_series1);
	m_series1->setUseOpenGL(true);//openGl 加速
	qDebug() << m_series1->useOpenGL();

	m_series2 = new QLineSeries;
	m_chart->addSeries(m_series2);
	m_series2->setUseOpenGL(true);//openGl 加速
	qDebug() << m_series2->useOpenGL();

	m_series3 = new QLineSeries;
	m_chart->addSeries(m_series3);
	m_series3->setUseOpenGL(true);//openGl 加速
	qDebug() << m_series3->useOpenGL();

	QValueAxis* axisX = new QValueAxis;
	axisX->setRange(0, maxSize);
	axisX->setLabelFormat("%g");
	axisX->setTitleText("axisX");

	QValueAxis* axisY = new QValueAxis;
	axisY->setRange(-1000, 15000);//Y轴长度
	axisY->setTitleText("axisY");

	m_chart->setAxisX(axisX, m_series1);
	m_chart->setAxisY(axisY, m_series1);
	m_chart->setAxisX(axisX, m_series2);
	m_chart->setAxisY(axisY, m_series2);
	m_chart->setAxisX(axisX, m_series3);
	m_chart->setAxisY(axisY, m_series3);
	m_chart->legend()->hide();
	m_chart->setTitle("传感器数据");

	/*timeId = startTimer(30);
	connect(this, SIGNAL(sndfloat(float, int)), this, SLOT(getdata(float, int)));*/

	sndnum = 0;
}
void RelayControl::Delay_MSec(unsigned int msec)
{
	QTime _Timer = QTime::currentTime().addMSecs(msec);

	while (QTime::currentTime() < _Timer)

		QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}
void RelayControl::Relay1Pressed()//第一路吸合
{
	QByteArray data;
	data[0] = 0xFE;
	data[1] = 0x05;
	data[2] = 0x00;
	data[3] = 0x00;
	data[4] = 0xFF;
	data[5] = 0x00;
	data[6] = 0x98;
	data[7] = 0x35;
	emit snddata(data);
}
void RelayControl::Relay1Released()
{
	QByteArray data;
	data[0] = 0xFE;
	data[1] = 0x05;
	data[2] = 0x00;
	data[3] = 0x00;
	data[4] = 0x00;
	data[5] = 0x00;
	data[6] = 0xD9;
	data[7] = 0xC5;
	emit snddata(data);
}
void RelayControl::Relay2Pressed()
{
	QByteArray data;
	data[0] = 0xFE;
	data[1] = 0x05;
	data[2] = 0x00;
	data[3] = 0x01;
	data[4] = 0xFF;
	data[5] = 0x00;
	data[6] = 0xC9;
	data[7] = 0xF5;
	emit snddata(data);
}
void RelayControl::Relay2Released()
{
	QByteArray data;
	data[0] = 0xFE;
	data[1] = 0x05;
	data[2] = 0x00;
	data[3] = 0x01;
	data[4] = 0x00;
	data[5] = 0x00;
	data[6] = 0x88;
	data[7] = 0x05;
	emit snddata(data);
}
void RelayControl::Relay3Pressed()
{
	QByteArray data;
	data[0] = 0xFE;
	data[1] = 0x05;
	data[2] = 0x00;
	data[3] = 0x02;
	data[4] = 0xFF;
	data[5] = 0x00;
	data[6] = 0x39;
	data[7] = 0xF5;
	emit snddata(data);
}
void RelayControl::Relay3Released()
{
	QByteArray data;
	data[0] = 0xFE;
	data[1] = 0x05;
	data[2] = 0x00;
	data[3] = 0x02;
	data[4] = 0x00;
	data[5] = 0x00;
	data[6] = 0x78;
	data[7] = 0x05;
	emit snddata(data);
}
void RelayControl::Relay4Pressed()
{
	QByteArray data;
	data[0] = 0xFE;
	data[1] = 0x05;
	data[2] = 0x00;
	data[3] = 0x03;
	data[4] = 0xFF;
	data[5] = 0x00;
	data[6] = 0x68;
	data[7] = 0x35;
	emit snddata(data);
}
void RelayControl::Relay4Released()
{
	QByteArray data;
	data[0] = 0xFE;
	data[1] = 0x05;
	data[2] = 0x00;
	data[3] = 0x03;
	data[4] = 0x00;
	data[5] = 0x00;
	data[6] = 0x29;
	data[7] = 0xC5;
	emit snddata(data);
}
void RelayControl::Relay5Pressed()
{
	QByteArray data;
	data[0] = 0xFE;
	data[1] = 0x05;
	data[2] = 0x00;
	data[3] = 0x04;
	data[4] = 0xFF;
	data[5] = 0x00;
	data[6] = 0xD9;
	data[7] = 0xF4;
	emit snddata(data);
}
void RelayControl::Relay5Released()
{
	QByteArray data;
	data[0] = 0xFE;
	data[1] = 0x05;
	data[2] = 0x00;
	data[3] = 0x04;
	data[4] = 0x00;
	data[5] = 0x00;
	data[6] = 0x98;
	data[7] = 0x04;
	emit snddata(data);
}
void RelayControl::Relay6Pressed()
{
	QByteArray data;
	data[0] = 0xFE;
	data[1] = 0x05;
	data[2] = 0x00;
	data[3] = 0x05;
	data[4] = 0xFF;
	data[5] = 0x00;
	data[6] = 0x88;
	data[7] = 0x34;
	emit snddata(data);
}
void RelayControl::Relay6Released()
{
	QByteArray data;
	data[0] = 0xFE;
	data[1] = 0x05;
	data[2] = 0x00;
	data[3] = 0x05;
	data[4] = 0x00;
	data[5] = 0x00;
	data[6] = 0xC9;
	data[7] = 0xC4;
	emit snddata(data);
}
void RelayControl::Relay7Pressed()
{
	QByteArray data;//16
	data[0] = 0xFE;
	data[1] = 0x05;
	data[2] = 0x00;
	data[3] = 0x0F;
	data[4] = 0xFF;
	data[5] = 0x00;
	data[6] = 0xA8;
	data[7] = 0x36;
	emit snddata(data);
}
void RelayControl::Relay7Released()
{
	QByteArray data;//16
	data[0] = 0xFE;
	data[1] = 0x05;
	data[2] = 0x00;
	data[3] = 0x0F;
	data[4] = 0x00;
	data[5] = 0x00;
	data[6] = 0xE9;
	data[7] = 0xC6;
	emit snddata(data);
}
void RelayControl::Relay8Pressed()
{
	QByteArray data;//15
	data[0] = 0xFE;
	data[1] = 0x05;
	data[2] = 0x00;
	data[3] = 0x0E;
	data[4] = 0xFF;
	data[5] = 0x00;
	data[6] = 0xF9;
	data[7] = 0xF6;
	emit snddata(data);
}
void RelayControl::Relay8Released()
{
	QByteArray data;//15
	data[0] = 0xFE;
	data[1] = 0x05;
	data[2] = 0x00;
	data[3] = 0x0E;
	data[4] = 0x00;
	data[5] = 0x00;
	data[6] = 0xB8;
	data[7] = 0x06;
	emit snddata(data);
}
void RelayControl::Relay9Pressed()
{
	QByteArray data;
	data[0] = 0xFE;
	data[1] = 0x05;
	data[2] = 0x00;
	data[3] = 0x08;
	data[4] = 0xFF;
	data[5] = 0x00;
	data[6] = 0x19;
	data[7] = 0xF7;
	emit snddata(data);
}
void RelayControl::Relay9Released()
{
	QByteArray data;
	data[0] = 0xFE;
	data[1] = 0x05;
	data[2] = 0x00;
	data[3] = 0x08;
	data[4] = 0x00;
	data[5] = 0x00;
	data[6] = 0x58;
	data[7] = 0x07;
	emit snddata(data);
}
void RelayControl::Relay10Pressed()
{
	QByteArray data;
	data[0] = 0xFE;
	data[1] = 0x05;
	data[2] = 0x00;
	data[3] = 0x09;
	data[4] = 0xFF;
	data[5] = 0x00;
	data[6] = 0x48;
	data[7] = 0x37;
	emit snddata(data);
}
void RelayControl::Relay10Released()
{
	QByteArray data;
	data[0] = 0xFE;
	data[1] = 0x05;
	data[2] = 0x00;
	data[3] = 0x09;
	data[4] = 0x00;
	data[5] = 0x00;
	data[6] = 0x09;
	data[7] = 0xC7;
	emit snddata(data);
}
void RelayControl::Relay11Pressed()
{
	QByteArray data;
	data[0] = 0xFE;
	data[1] = 0x05;
	data[2] = 0x00;
	data[3] = 0x0A;
	data[4] = 0xFF;
	data[5] = 0x00;
	data[6] = 0xB8;
	data[7] = 0x37;
	emit snddata(data);
}
void RelayControl::Relay11Released()
{
	QByteArray data;
	data[0] = 0xFE;
	data[1] = 0x05;
	data[2] = 0x00;
	data[3] = 0x0A;
	data[4] = 0x00;
	data[5] = 0x00;
	data[6] = 0xF9;
	data[7] = 0xC7;
	emit snddata(data);
}
void RelayControl::Relay12Pressed()
{
	QByteArray data;
	data[0] = 0xFE;
	data[1] = 0x05;
	data[2] = 0x00;
	data[3] = 0x0B;
	data[4] = 0xFF;
	data[5] = 0x00;
	data[6] = 0xE9;
	data[7] = 0xF7;
	emit snddata(data);
}
void RelayControl::Relay12Released()
{
	QByteArray data;
	data[0] = 0xFE;
	data[1] = 0x05;
	data[2] = 0x00;
	data[3] = 0x0B;
	data[4] = 0x00;
	data[5] = 0x00;
	data[6] = 0xA8;
	data[7] = 0x07;
	emit snddata(data);
}
void RelayControl::Relay13Pressed()
{
	QByteArray data;
	data[0] = 0xFE;
	data[1] = 0x05;
	data[2] = 0x00;
	data[3] = 0x0C;
	data[4] = 0xFF;
	data[5] = 0x00;
	data[6] = 0x58;
	data[7] = 0x36;
	emit snddata(data);
}
void RelayControl::Relay13Released()
{
	QByteArray data;
	data[0] = 0xFE;
	data[1] = 0x05;
	data[2] = 0x00;
	data[3] = 0x0C;
	data[4] = 0x00;
	data[5] = 0x00;
	data[6] = 0x19;
	data[7] = 0xC6;
	emit snddata(data);
}
void RelayControl::Relay14Pressed()
{
	QByteArray data;
	data[0] = 0xFE;
	data[1] = 0x05;
	data[2] = 0x00;
	data[3] = 0x0D;
	data[4] = 0xFF;
	data[5] = 0x00;
	data[6] = 0x09;
	data[7] = 0xF6;
	emit snddata(data);
}
void RelayControl::Relay14Released()
{
	QByteArray data;
	data[0] = 0xFE;
	data[1] = 0x05;
	data[2] = 0x00;
	data[3] = 0x0D;
	data[4] = 0x00;
	data[5] = 0x00;
	data[6] = 0x48;
	data[7] = 0x06;
	emit snddata(data);
}
void RelayControl::Relay15Pressed()
{
	QByteArray data;
	data[0] = 0xFE;
	data[1] = 0x05;
	data[2] = 0x00;
	data[3] = 0x0E;
	data[4] = 0xFF;
	data[5] = 0x00;
	data[6] = 0xF9;
	data[7] = 0xF6;
	emit snddata(data);
}
void RelayControl::Relay15Released()
{
	QByteArray data;
	data[0] = 0xFE;
	data[1] = 0x05;
	data[2] = 0x00;
	data[3] = 0x0E;
	data[4] = 0x00;
	data[5] = 0x00;
	data[6] = 0xB8;
	data[7] = 0x06;
	emit snddata(data);
}
void RelayControl::Relay16Pressed()
{
	QByteArray data;
	data[0] = 0xFE;
	data[1] = 0x05;
	data[2] = 0x00;
	data[3] = 0x0F;
	data[4] = 0xFF;
	data[5] = 0x00;
	data[6] = 0xA8;
	data[7] = 0x36;
	emit snddata(data);
	Delay_MSec(100);
	data[0] = 0xFE;
	data[1] = 0x05;
	data[2] = 0x00;
	data[3] = 0x0E;
	data[4] = 0xFF;
	data[5] = 0x00;
	data[6] = 0xF9;
	data[7] = 0xF6;
	emit snddata(data);
}
void RelayControl::Relay16Released()
{
	QByteArray data;
	data[0] = 0xFE;
	data[1] = 0x05;
	data[2] = 0x00;
	data[3] = 0x0F;
	data[4] = 0x00;
	data[5] = 0x00;
	data[6] = 0xE9;
	data[7] = 0xC6;
	emit snddata(data);
	Delay_MSec(100);
	data[0] = 0xFE;
	data[1] = 0x05;
	data[2] = 0x00;
	data[3] = 0x0E;
	data[4] = 0x00;
	data[5] = 0x00;
	data[6] = 0xB8;
	data[7] = 0x06;
	emit snddata(data);
}
void RelayControl::Relay17Pressed()
{
	QByteArray data;
	data[0] = 0xFE;
	data[1] = 0x05;
	data[2] = 0x00;
	data[3] = 0x10;
	data[4] = 0xFF;
	data[5] = 0x00;
	data[6] = 0x99;
	data[7] = 0xF0;
	emit snddata(data);
}
void RelayControl::Relay17Released()
{
	QByteArray data;
	data[0] = 0xFE;
	data[1] = 0x05;
	data[2] = 0x00;
	data[3] = 0x10;
	data[4] = 0x00;
	data[5] = 0x00;
	data[6] = 0xD8;
	data[7] = 0x00;
	emit snddata(data);
}
void RelayControl::Relay18Pressed()
{
	QByteArray data;
	data[0] = 0xFE;
	data[1] = 0x05;
	data[2] = 0x00;
	data[3] = 0x11;
	data[4] = 0xFF;
	data[5] = 0x00;
	data[6] = 0xC8;
	data[7] = 0x30;
	emit snddata(data);
}
void RelayControl::Relay18Released()
{
	QByteArray data;
	data[0] = 0xFE;
	data[1] = 0x05;
	data[2] = 0x00;
	data[3] = 0x11;
	data[4] = 0x00;
	data[5] = 0x00;
	data[6] = 0x89;
	data[7] = 0xC0;
	emit snddata(data);
}
void RelayControl::Relay19Pressed()
{
	QByteArray data;
	data[0] = 0xFE;
	data[1] = 0x05;
	data[2] = 0x00;
	data[3] = 0x12;
	data[4] = 0xFF;
	data[5] = 0x00;
	data[6] = 0x38;
	data[7] = 0x30;
	emit snddata(data);
}
void RelayControl::Relay19Released()
{
	QByteArray data;
	data[0] = 0xFE;
	data[1] = 0x05;
	data[2] = 0x00;
	data[3] = 0x12;
	data[4] = 0x00;
	data[5] = 0x00;
	data[6] = 0x79;
	data[7] = 0xC0;
	emit snddata(data);
}
void RelayControl::Relay20Pressed()
{
	QByteArray data;
	data[0] = 0xFE;
	data[1] = 0x05;
	data[2] = 0x00;
	data[3] = 0x13;
	data[4] = 0xFF;
	data[5] = 0x00;
	data[6] = 0x69;
	data[7] = 0xF0;
	emit snddata(data);
}
void RelayControl::Relay20Released()
{
	QByteArray data;
	data[0] = 0xFE;
	data[1] = 0x05;
	data[2] = 0x00;
	data[3] = 0x13;
	data[4] = 0x00;
	data[5] = 0x00;
	data[6] = 0x28;
	data[7] = 0x00;
	emit snddata(data);
}
void RelayControl::Relay21Pressed()
{
	QByteArray data;
	data[0] = 0xFE;
	data[1] = 0x05;
	data[2] = 0x00;
	data[3] = 0x14;
	data[4] = 0xFF;
	data[5] = 0x00;
	data[6] = 0xD8;
	data[7] = 0x31;
	emit snddata(data);
}
void RelayControl::Relay21Released()
{
	QByteArray data;
	data[0] = 0xFE;
	data[1] = 0x05;
	data[2] = 0x00;
	data[3] = 0x14;
	data[4] = 0x00;
	data[5] = 0x00;
	data[6] = 0x99;
	data[7] = 0xC1;
	emit snddata(data);
}
void RelayControl::Relay22Pressed()
{
	QByteArray data;
	data[0] = 0xFE;
	data[1] = 0x05;
	data[2] = 0x00;
	data[3] = 0x15;
	data[4] = 0xFF;
	data[5] = 0x00;
	data[6] = 0x89;
	data[7] = 0xF1;
	emit snddata(data);
}
void RelayControl::Relay22Released()
{
	QByteArray data;
	data[0] = 0xFE;
	data[1] = 0x05;
	data[2] = 0x00;
	data[3] = 0x15;
	data[4] = 0x00;
	data[5] = 0x00;
	data[6] = 0xC8;
	data[7] = 0x01;
	emit snddata(data);
}
void RelayControl::Relay23Pressed()
{
	QByteArray data;
	data[0] = 0xFE;
	data[1] = 0x05;
	data[2] = 0x00;
	data[3] = 0x16;
	data[4] = 0xFF;
	data[5] = 0x00;
	data[6] = 0x79;
	data[7] = 0xF1;
	emit snddata(data);
}
void RelayControl::Relay23Released()
{
	QByteArray data;
	data[0] = 0xFE;
	data[1] = 0x05;
	data[2] = 0x00;
	data[3] = 0x16;
	data[4] = 0x00;
	data[5] = 0x00;
	data[6] = 0x38;
	data[7] = 0x01;
	emit snddata(data);
}
void RelayControl::Relay24Pressed()
{
	QByteArray data;
	data[0] = 0xFE;
	data[1] = 0x05;
	data[2] = 0x00;
	data[3] = 0x17;
	data[4] = 0xFF;
	data[5] = 0x00;
	data[6] = 0x28;
	data[7] = 0x31;
	emit snddata(data);
}
void RelayControl::Relay24Released()
{
	QByteArray data;
	data[0] = 0xFE;
	data[1] = 0x05;
	data[2] = 0x00;
	data[3] = 0x17;
	data[4] = 0x00;
	data[5] = 0x00;
	data[6] = 0x69;
	data[7] = 0xC1;
	emit snddata(data);
}
void RelayControl::Relay25Pressed()
{
	QByteArray data;
	data[0] = 0xFE;
	data[1] = 0x05;
	data[2] = 0x00;
	data[3] = 0x18;
	data[4] = 0xFF;
	data[5] = 0x00;
	data[6] = 0x18;
	data[7] = 0x32;
	emit snddata(data);
}
void RelayControl::Relay25Released()
{
	QByteArray data;
	data[0] = 0xFE;
	data[1] = 0x05;
	data[2] = 0x00;
	data[3] = 0x18;
	data[4] = 0x00;
	data[5] = 0x00;
	data[6] = 0x59;
	data[7] = 0xC2;
	emit snddata(data);
}
void RelayControl::Relay26Pressed()
{
	QByteArray data;
	data[0] = 0xFE;
	data[1] = 0x05;
	data[2] = 0x00;
	data[3] = 0x19;
	data[4] = 0xFF;
	data[5] = 0x00;
	data[6] = 0x49;
	data[7] = 0xF2;
	emit snddata(data);
}
void RelayControl::Relay26Released()
{
	QByteArray data;
	data[0] = 0xFE;
	data[1] = 0x05;
	data[2] = 0x00;
	data[3] = 0x19;
	data[4] = 0x00;
	data[5] = 0x00;
	data[6] = 0x08;
	data[7] = 0x02;
	emit snddata(data);
}
void RelayControl::Relay27Pressed()
{
	QByteArray data;
	data[0] = 0xFE;
	data[1] = 0x05;
	data[2] = 0x00;
	data[3] = 0x1A;
	data[4] = 0xFF;
	data[5] = 0x00;
	data[6] = 0xB9;
	data[7] = 0xF2;
	emit snddata(data);
}
void RelayControl::Relay27Released()
{
	QByteArray data;
	data[0] = 0xFE;
	data[1] = 0x05;
	data[2] = 0x00;
	data[3] = 0x1A;
	data[4] = 0x00;
	data[5] = 0x00;
	data[6] = 0xF8;
	data[7] = 0x02;
	emit snddata(data);
}
void RelayControl::Relay28Pressed()
{
	QByteArray data;
	data[0] = 0xFE;
	data[1] = 0x05;
	data[2] = 0x00;
	data[3] = 0x1B;
	data[4] = 0xFF;
	data[5] = 0x00;
	data[6] = 0xE8;
	data[7] = 0x32;
	emit snddata(data);
}
void RelayControl::Relay28Released()
{
	QByteArray data;
	data[0] = 0xFE;
	data[1] = 0x05;
	data[2] = 0x00;
	data[3] = 0x1B;
	data[4] = 0x00;
	data[5] = 0x00;
	data[6] = 0xA9;
	data[7] = 0xC2;
	emit snddata(data);
}
void RelayControl::Relay29Pressed()
{
	QByteArray data;
	data[0] = 0xFE;
	data[1] = 0x05;
	data[2] = 0x00;
	data[3] = 0x1C;
	data[4] = 0xFF;
	data[5] = 0x00;
	data[6] = 0x59;
	data[7] = 0xF3;
	emit snddata(data);
}
void RelayControl::Relay29Released()
{
	QByteArray data;
	data[0] = 0xFE;
	data[1] = 0x05;
	data[2] = 0x00;
	data[3] = 0x1C;
	data[4] = 0x00;
	data[5] = 0x00;
	data[6] = 0x18;
	data[7] = 0x03;
	emit snddata(data);
}
void RelayControl::Relay30Pressed()
{
	QByteArray data;
	data[0] = 0xFE;
	data[1] = 0x05;
	data[2] = 0x00;
	data[3] = 0x1D;
	data[4] = 0xFF;
	data[5] = 0x00;
	data[6] = 0x08;
	data[7] = 0x33;
	emit snddata(data);
}
void RelayControl::Relay30Released()
{
	QByteArray data;
	data[0] = 0xFE;
	data[1] = 0x05;
	data[2] = 0x00;
	data[3] = 0x1D;
	data[4] = 0x00;
	data[5] = 0x00;
	data[6] = 0x49;
	data[7] = 0xC3;
	emit snddata(data);
}
void RelayControl::Relay31Pressed()
{
	QByteArray data;
	data[0] = 0xFE;
	data[1] = 0x05;
	data[2] = 0x00;
	data[3] = 0x1E;
	data[4] = 0xFF;
	data[5] = 0x00;
	data[6] = 0xF8;
	data[7] = 0x33;
	emit snddata(data);
}
void RelayControl::Relay31Released()
{
	QByteArray data;
	data[0] = 0xFE;
	data[1] = 0x05;
	data[2] = 0x00;
	data[3] = 0x1E;
	data[4] = 0x00;
	data[5] = 0x00;
	data[6] = 0xB9;
	data[7] = 0xC3;
	emit snddata(data);
}
void RelayControl::Relay32Pressed()
{
	QByteArray data;
	data[0] = 0xFE;
	data[1] = 0x05;
	data[2] = 0x00;
	data[3] = 0x1F;
	data[4] = 0xFF;
	data[5] = 0x00;
	data[6] = 0xA9;
	data[7] = 0xF3;
	emit snddata(data);
}
void RelayControl::Relay32Released()
{
	QByteArray data;
	data[0] = 0xFE;
	data[1] = 0x05;
	data[2] = 0x00;
	data[3] = 0x1F;
	data[4] = 0x00;
	data[5] = 0x00;
	data[6] = 0xE8;
	data[7] = 0x03;
	emit snddata(data);
}

void RelayControl::QBAcrc16(QByteArray& ptr, unsigned int len, unsigned char CRC[2])
{
	unsigned long wcrc = 0XFFFF;//预置16位crc寄存器，初值全部为1
	unsigned char temp;//定义中间变量
	int i = 0, j = 0;//定义计数
	for (i = 0; i < len; i++)//循环计算每个数据
	{
		temp = ptr[i] & 0X00FF;//将八位数据与crc寄存器亦或
		//指针地址增加，指向下个数据
		wcrc ^= temp;//将数据存入crc寄存器
		for (j = 0; j < 8; j++)//循环计算数据的
		{
			if (wcrc & 0X0001)//判断右移出的是不是1，如果是1则与多项式进行异或。
			{
				wcrc >>= 1;//先将数据右移一位
				wcrc ^= 0XA001;//与上面的多项式进行异或
			}
			else//如果不是1，则直接移出
			{
				wcrc >>= 1;//直接移出
			}
		}
	}
	temp = wcrc;//crc的值
	CRC[0] = wcrc;//crc的低八位
	CRC[1] = wcrc >> 8;//crc的高八位
}

void RelayControl::getNiPao()
{
	unsigned char crc[2] = { 0 };
	QByteArray data;
	data[0] = 0x02;
	data[1] = 0x03;
	data[2] = 0x00;
	data[3] = 0x00;
	data[4] = 0x00;
	data[5] = 0x02;
	data[6] = 0xC4;
	data[7] = 0x38;
	QBAcrc16(data, data.size() - 2, crc);
	data[6] = crc[0];
	data[7] = crc[1];

	if ((data[data.size() - 2].operator==(crc[0])) && (data[data.size() - 1].operator==(crc[1])))
	{
		emit snddata(data);
	}
}

void RelayControl::getNiPao2()
{
	unsigned char crc[2] = { 0 };
	QByteArray data;
	data[0] = 0x03;
	data[1] = 0x03;
	data[2] = 0x00;
	data[3] = 0x00;
	data[4] = 0x00;
	data[5] = 0x02;
	data[6] = 0xC4;
	data[7] = 0x38;
	QBAcrc16(data, data.size() - 2, crc);
	data[6] = crc[0];
	data[7] = crc[1];

	if ((data[data.size() - 2].operator==(crc[0])) && (data[data.size() - 1].operator==(crc[1])))
	{
		emit snddata(data);
	}
}

void RelayControl::setZero()
{
	unsigned char crc[2] = { 0 };
	QByteArray data;
	data[0] = 0x01;
	data[1] = 0x10;
	data[2] = 0x1A;
	data[3] = 0x00;
	data[4] = 0x00;
	data[5] = 0x01;
	data[6] = 0x02;
	data[7] = 0x00;
	data[8] = 0xBB;
	data[9] = 0x5D;
	data[10] = 0xE2;
	QBAcrc16(data, data.size() - 2, crc);
	if ((data[data.size() - 2].operator==(crc[0])) && (data[data.size() - 1].operator==(crc[1])))
	{
		emit snddata(data);
	}
}

void RelayControl::getTongQian()//水平电子尺
{
	unsigned char crc[2] = { 0 };

	QByteArray data;
	data[0] = 0x01;
	data[1] = 0x03;
	data[2] = 0x00;
	data[3] = 0x40;
	data[4] = 0x00;
	data[5] = 0x02;
	data[6] = 0xC5;
	data[7] = 0xDF;
	QBAcrc16(data, data.size() - 2, crc);
	data[6] = crc[0];
	data[7] = crc[1];
	if ((data[data.size() - 2].operator==(crc[0])) && (data[data.size() - 1].operator==(crc[1])))
	{
		emit snddata(data);
	}
}

void RelayControl::timerEvent(QTimerEvent* event)
{
	if (sndnum == 10)
	{
		getNiPao();
	}
	if (sndnum == 20)
	{
		getNiPao2();
	}
	if (sndnum == 30)
	{

		getTongQian();
		sndnum = 0;
	}

	if (event->timerId() == timeId)
	{
		sndnum++;
		int size1 = mydata1.size();
		qDebug() << "size1-->" << size1;
		int size2 = mydata2.size();
		qDebug() << "size2-->" << size2;
		int size3 = mydata3.size();
		qDebug() << "size2-->" << size3;
		if (isVisible())
		{
			{//线1
				float temp = 0;
				QVector<QPointF> oldPoints = m_series1->pointsVector();//Returns the points in the series as a vector
				QVector<QPointF> points;
				//size = 32
				if (oldPoints.count() < maxSize)
				{
					for (int i = 0; i < oldPoints.count(); ++i)
					{
						points.append(QPointF(i, oldPoints.at(i).y()));//替换数据用
					}
				}
				else
				{
					for (int i = size1; i < oldPoints.count(); ++i)
					{
						points.append(QPointF(i - size1, oldPoints.at(i).y()));//替换数据用
					}
				}

				qint64 sizePoints = points.count();
				int x = 0;
				for (int k = 0; k < size1; ++k)
				{
					if (mydata1.size() > 0)
					{
						temp = *(mydata1.begin());
						mydata1.erase(mydata1.begin());
					}
					else
					{
						temp = 0;
					}
					points.append(QPointF(k + sizePoints, temp));
				}
				m_series1->replace(points);
			}

			{//线2
				float temp = 0;
				QVector<QPointF> oldPoints = m_series2->pointsVector();//Returns the points in the series as a vector
				QVector<QPointF> points;
				if (oldPoints.count() < maxSize)
				{
					for (int i = 0; i < oldPoints.count(); ++i)
					{
						points.append(QPointF(i, oldPoints.at(i).y()));//替换数据用
					}
				}
				else
				{
					for (int i = size2; i < oldPoints.count(); ++i)
					{
						points.append(QPointF(i - size2, oldPoints.at(i).y()));//替换数据用
					}
				}

				qint64 sizePoints = points.count();
				int x = 0;
				for (int k = 0; k < size2; ++k)
				{
					if (mydata2.size() > 0)
					{
						temp = *(mydata2.begin());
						mydata2.erase(mydata2.begin());
					}
					else
					{
						temp = 0;
					}
					points.append(QPointF(k + sizePoints, temp));
				}
				m_series2->replace(points);
			}

			{//线3
				float temp = 0;
				QVector<QPointF> oldPoints = m_series3->pointsVector();//Returns the points in the series as a vector
				QVector<QPointF> points;
				if (oldPoints.count() < maxSize)
				{
					for (int i = 0; i < oldPoints.count(); ++i)
					{
						points.append(QPointF(i, oldPoints.at(i).y()));//替换数据用
					}
				}
				else
				{
					for (int i = size3; i < oldPoints.count(); ++i)
					{
						points.append(QPointF(i - size3, oldPoints.at(i).y()));//替换数据用
					}
				}

				qint64 sizePoints = points.count();
				int x = 0;
				for (int k = 0; k < size3; ++k)
				{
					if (mydata3.size() > 0)
					{
						temp = *(mydata3.begin());
						mydata3.erase(mydata3.begin());
					}
					else
					{
						temp = 0;
					}
					points.append(QPointF(k + sizePoints, temp));
				}
				m_series3->replace(points);
			}
		}
	}
}

void RelayControl::paintEvent(QPaintEvent* event)
{
	int xx = this->geometry().width();
	int yy = this->geometry().height();
	chartView->setGeometry(QRect(5, 200, xx - 10, yy - 220));
}

void RelayControl::getdata(float temp, int x)
{
	if (x == 0x01)
	{
		mydata1.push_back(temp);
	}
	if (x == 0x02)
	{
		mydata2.push_back(temp);
	}
	if (x == 0x03)
	{
		mydata3.push_back(temp);
	}
}

void RelayControl::onResetCameraClicked()
{
	//配置文件
	CMyINI* pini = new CMyINI();
	string path;
	path.append((qApp->applicationDirPath()).toStdString());
	path.append("/config/camera.ini");
	int nRet = pini->ReadINI(path);
	if (nRet != 0)
	{
		pini->SetValue("camera", "Camera1", "NOUSE");
		pini->SetValue("camera", "Camera2", "NOUSE");
	}
	pini->WriteINI(path);
}
