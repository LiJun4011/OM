#include "OM.h"
#include <QHostAddress>
#include <opencv2/core.hpp>//opencv410
#include <opencv2/imgproc.hpp>
#include "opencv2/imgcodecs.hpp"
#include <opencv2/highgui.hpp>
#include "opencv2/core/types_c.h"
#include <opencv2/opencv.hpp>
#include <opencv2\imgproc\types_c.h>  
#include "qmutex.h"
#include "qdatetime.h"
#include <QNetworkInterface>

////白光相机
//#define STREAM_URL11 "rtsp://192.168.1.88/11"   //主码流
//#include "hi_vscp_devs_cli.h"

#pragma execution_character_set("utf-8")

using namespace cv;
Mat *matImage1 = new Mat(600, 1280, CV_8UC1);
Mat *matImage2 = new Mat(600, 1280, CV_8UC1);
Mat *matImage3 = new Mat(600, 1280, CV_8UC1);
Mat *matImage4 = new Mat(600, 1280, CV_8UC1);
Mat *matimg1 = new Mat(600, 1280, CV_8UC1);
Mat *matimg2 = new Mat(600, 1280, CV_8UC1);
Mat *matimg3 = new Mat(600, 1280, CV_8UC1);
Mat *matimg4 = new Mat(600, 1280, CV_8UC1);
QMutex mutex1;
QMutex mutex2;
QMutex mutex3;
QMutex mutex4;
int n_Camera1 = 0;
int n_Camera2 = 0;
int n_Camera3 = 0;
int n_Camera4 = 0;

OM::OM(QWidget *parent)
	: QMainWindow(parent),
	m_stopTongQian(false), m_times(0)
{
	ui.setupUi(this);

	ReadIni();

	//网络配置
	tcpsocket = NULL;
	tcpsocket = new QTcpSocket(this);
	connect(tcpsocket, &QTcpSocket::connected, [=]() {
		ui.textBrowser->append("控制板连接成功");
	});
	connect(tcpsocket, SIGNAL(readyRead()), this, SLOT(ReadNetData()));
	connect(tcpsocket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(ReadNetError(QAbstractSocket::SocketError)));
	//获取服务器的IP和端口   
	//QString strip = QString::fromStdString("192.168.1.244");
	qint16 prot = myPort.toInt();
	//主动和服务器建立连接   
	tcpsocket->connectToHost(QHostAddress(myIP), prot);

	//日志
	mylog = new Alog();
	mylog->logStartup();
	qInfo() << "软件启动";

	connect(&myRC,SIGNAL(snddata(QByteArray)), this, SLOT(contralB(QByteArray)));
	connect(this,SIGNAL(snddata(QByteArray)), this, SLOT(contralB(QByteArray)));

	n_isclose = 0;

	n_showImageNum1 = 0;
	n_showImageNum2 = 0;
	n_showImageNum3 = 0;
	n_showImageNum4 = 0;

	qImage1 = new QImage((unsigned char *)((*matimg1).data), (*matImage1).cols, (*matImage1).rows, (*matImage1).cols * sizeof(unsigned char), QImage::Format_Indexed8);
	qImage2 = new QImage((unsigned char *)((*matimg2).data), (*matImage2).cols, (*matImage2).rows, (*matImage2).cols * sizeof(unsigned char), QImage::Format_Indexed8);
	qImage3 = new QImage((unsigned char *)((*matimg3).data), (*matImage3).cols, (*matImage3).rows, (*matImage3).cols * sizeof(unsigned char), QImage::Format_Indexed8);
	qImage4 = new QImage((unsigned char *)((*matimg4).data), (*matImage4).cols, (*matImage4).rows, (*matImage4).cols * sizeof(unsigned char), QImage::Format_Indexed8);


	memset(m_pcMyCamera, 0, sizeof(m_pcMyCamera));
	_ASSERTE(_CrtCheckMemory());//用于查看内存使用溢出

	connect(this, SIGNAL(sndimage1(QImage *, unsigned int, unsigned int)), this, SLOT(showimage1(QImage *, unsigned int, unsigned int)));
	connect(this, SIGNAL(sndimage2(QImage *, unsigned int, unsigned int)), this, SLOT(showimage2(QImage *, unsigned int, unsigned int)));
	connect(this, SIGNAL(sndimage3(QImage *, unsigned int, unsigned int)), this, SLOT(showimage3(QImage *, unsigned int, unsigned int)));
	connect(this, SIGNAL(sndimage4(QImage *, unsigned int, unsigned int)), this, SLOT(showimage4(QImage *, unsigned int, unsigned int)));
	connect(&thread, SIGNAL(sndimage(QImage *, unsigned int, unsigned int)), this, SLOT(showimage1(QImage *, unsigned int, unsigned int)));

	connect(this, SIGNAL(sndfloat(float, int)), &myRC, SLOT(getdata(float, int)));

	memset(n_FrameCount, 0, sizeof(n_FrameCount));
	_ASSERTE(_CrtCheckMemory());//用于查看内存使用溢出
	frameRatetimer = new QTimer(this);
	connect(frameRatetimer, SIGNAL(timeout()), this, SLOT(setFrameRates()));
	frameRatetimer->setInterval(1000);
	frameRatetimer->start();

	WFtimer = new QTimer(this);
	connect(WFtimer, SIGNAL(timeout()), this, SLOT(WFSport()));
	WFtimer->setInterval(n_WFtime);
	//WFtimer->start();
	
	startDetect();

	myTimer = new QTimer(this);
	connect(myTimer, SIGNAL(timeout()), this, SLOT(contralC()));
	myTimer->setInterval(30);
	myTimer->start();

	//各个模组位置初始化
	dzc_WZ = 0;

	//OnOpencvStart();

	//整车移动定时器
	m_moveTimer = new QTimer(this);
	connect(m_moveTimer, SIGNAL(timeout()), this, SLOT(OnStopMove()));

	//开孔时凿岩旋转用定时器
	m_zaoYanTimer = new QTimer(this);
	connect(m_zaoYanTimer, SIGNAL(timeout()), this, SLOT(OnStopRotate()));

	//打泥定时, 开始打孔定时
	m_mainOpera = new QTimer(this);
	connect(m_mainOpera, SIGNAL(timeout()), this, SLOT(OnTimeOver()));

	//凿岩用定时器
	connect(m_zaoYanTimer, SIGNAL(timeout()), this, SLOT(OnDoZaoYan()));

	//捅钎用定时器
	m_tongQianTimer = new QTimer(this);
	connect(m_tongQianTimer, SIGNAL(timeout()), this, SLOT(OnDoTongQian()));

	//伸钎
	m_extendTimer = new QTimer(this);
	connect(m_extendTimer, SIGNAL(timeout()), this, SLOT(OnDoExtendQian()));

	//收钎
	m_shinkTimer = new QTimer(this);
	connect(m_shinkTimer, SIGNAL(timeout()), this, SLOT(OnDoShinkQian()));

	//夹轨与松轨
	m_clampAndLooseTimer = new QTimer(this);
	connect(m_clampAndLooseTimer, SIGNAL(timeout()), this, SLOT(OnDoClampAndLoose()));
}
OM::~OM()
{
	stopDetect();
	if (mylog != NULL)
	{
		delete mylog;
		mylog = NULL;
	}
	if (p != NULL)
	{
		delete p;
		p = NULL;
	}
}
void OM::Delay_MSec(unsigned int msec)
{
	QTime _Timer = QTime::currentTime().addMSecs(msec);

	while (QTime::currentTime() < _Timer)

		QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}
void OM::showimage(QByteArray array)
{
	QString myx, myy;
}
void OM::contralB(QByteArray array)
{
	myArray.push_back(array);
}
void OM::contralC()
{
	myTimer->stop();
	vector<QByteArray> temp;
	temp = myArray;
	myArray.clear();
	vector<QByteArray>::iterator item = temp.begin();
	for (; item != temp.end(); item++)
	{
		tcpsocket->write(*item);
		Delay_MSec(200);
	}
	temp.clear();
	myTimer->start();
}
void OM::ReadNetData()
{
	//获取对方发送的内容    
	QByteArray array = tcpsocket->readAll();
	unsigned char templabel = array[4];
	
	if (templabel == 0x01)//ad数据采集
	{
		QString str;
		long addata = 0;
		unsigned char adtemp = 0;
		adtemp = array[7];
		addata = 256 * adtemp;
		adtemp = array[8];
		addata += adtemp;

		dzc_WZ = addata;
		str.append("水平位置：");
		str.append(QString::number(dzc_WZ));
		ui.textBrowser->append(str);
		ui.lineEdit_ShuiPing->setText(QString::number(dzc_WZ));
		emit sndfloat(dzc_WZ, templabel);

		//开孔3.判断开孔时水平移动到位信号
		if ( abs(dzc_WZ - m_openPorePos ) < PosAccuracy && m_machine.m_struType== StructureType::KaiKong)
		{
			if ( m_machine.m_horiMove == HorizontalMove::LeftMove )
				Relay27Released();
			else if ( m_machine.m_horiMove == HorizontalMove::RightMove )
				Relay28Released();				
			m_machine.m_horiMove = HorizontalMove::Default;

			//开孔4.整车前进
			Relay3Pressed();
			m_machine.m_machineMove = MachineMove::Forward;
			m_machine.m_struType = StructureType::KaiKong;

			m_moveTimer->start(MathineForwardTime);
		}

		//堵泥3.判断堵泥时水平移动到位
		if ( abs(dzc_WZ - m_duNiPos) < PosAccuracy && m_machine.m_struType == StructureType::DuNi)
		{
			if (m_machine.m_horiMove == HorizontalMove::LeftMove)
				Relay27Released();
			else if (m_machine.m_horiMove == HorizontalMove::RightMove)
				Relay28Released();
			m_machine.m_horiMove = HorizontalMove::Default;

			//堵泥4.整车前进
			Relay3Pressed();
			m_machine.m_machineMove = MachineMove::Forward;
			m_machine.m_struType = StructureType::DuNi;

			//堵泥5.整车定时到达指定位置
			m_moveTimer->start(MathineForwardTime);
		}

		//捅钎5.判断捅钎时水平移动到位
		if (abs(dzc_WZ - m_tongQianPos) < PosAccuracy && m_machine.m_struType == StructureType::TongQian)
		{
			if (m_machine.m_horiMove == HorizontalMove::LeftMove)
				Relay27Released();
			else if (m_machine.m_horiMove == HorizontalMove::RightMove)
				Relay28Released();

			m_machine.m_horiMove = HorizontalMove::Default;
			//捅钎6.整车前进
			Relay3Pressed();
			m_machine.m_machineMove = MachineMove::Forward;
			m_machine.m_struType = StructureType::TongQian;

			//整车定时到达指定位置
			m_moveTimer->start(MathineForwardTime);
		}
	}

	if (templabel == 0x02)//泥炮后坐力
	{
		QString str;
		unsigned char temp[4] = { 0 };
		temp[0] = array[10];
		temp[1] = array[9];
		temp[2] = array[8];
		temp[3] = array[7];
		hzl_WZ = *((float*)temp);
		str.append("泥炮后坐力：");
		str.append(QString::number(hzl_WZ));
		ui.textBrowser->append(str);
		ui.lineEdit_HouZuoLi->setText(QString::number(hzl_WZ));
		emit sndfloat(hzl_WZ, templabel);
		if (hzl_WZ >= n_tongqianWZ)
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
	}
	if (templabel == 0x03)//泥炮后坐力
	{
		QString str;
		unsigned char temp[4] = { 0 };
		temp[0] = array[10];
		temp[1] = array[9];
		temp[2] = array[8];
		temp[3] = array[7];
		hzl_WZ = *((float*)temp);
		str.append("泥炮后坐力2：");
		str.append(QString::number(hzl_WZ));
		ui.textBrowser->append(str);
		ui.lineEdit_HouZuoLi->setText(QString::number(hzl_WZ));
		emit sndfloat(hzl_WZ, templabel);
		if (hzl_WZ >= n_tongqianWZ)
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
	}

	//堵泥8.判断堵泥前进到位
	if (abs(m_niPaoPower - hzl_WZ) < 20)
	{
		//停止泥泡前进
		Relay9Released();
		//堵泥9.挤泥
		Relay11Pressed();
		m_machine.m_struType = StructureType::DuNi;
		m_mainOpera->start(PressMudTime);
	}

}
void OM::ReadNetError(QAbstractSocket::SocketError)
{
	tcpsocket->disconnectFromHost();
	ui.textBrowser->append(tr("控制板连接失败：因为 %1").arg(tcpsocket->errorString()));
}
void OM::showmyRC()
{
	myRC.show();
}
void   __stdcall ImageCallBack1(unsigned char* pData, MV_FRAME_OUT_INFO_EX* pFrameInfo, void* pUser)
{
	if (pFrameInfo)
	{
		OM *pBasicDemo = (OM*)pUser;

		// 获取相机网络流量和丢包信息
		MV_ALL_MATCH_INFO struMatchInfo = { 0 };
		MV_MATCH_INFO_NET_DETECT stMatchInfoNetDetect;
		struMatchInfo.pInfo = &stMatchInfoNetDetect;

		struMatchInfo.nType = MV_MATCH_TYPE_NET_DETECT; // 网络流量和丢包信息
		memset(&stMatchInfoNetDetect, 0, sizeof(MV_MATCH_INFO_NET_DETECT));
		_ASSERTE(_CrtCheckMemory());//用于查看内存使用溢出
		struMatchInfo.nInfoSize = sizeof(MV_MATCH_INFO_NET_DETECT);

		int nRet = pBasicDemo->m_pcMyCamera[n_Camera1]->GetAllMatchInfo(&struMatchInfo);
		if (MV_OK != nRet)
		{
			memset(&stMatchInfoNetDetect, 0, sizeof(MV_MATCH_INFO_NET_DETECT));
			_ASSERTE(_CrtCheckMemory());//用于查看内存使用溢出
		}

		//*matImage1 = Mat(pFrameInfo->nHeight, pFrameInfo->nWidth, CV_8UC1);;
		if (pData != NULL)
		{
			matImage1->data = (unsigned char *)pData;
			//imshow("adsf",*matImage1);
		}
//		vector<ST_BeltInfo> vecStBeltInfo;
//		int n_Ret = pBasicDemo->myDetect->beltdetect1(image, *matImage1, vecStBeltInfo, 1);

		mutex1.lock();
		*pBasicDemo->qImage1 = (QImage((unsigned char *)((*matImage1).data), (*matImage1).cols, (*matImage1).rows, (*matImage1).cols * sizeof(unsigned char), QImage::Format_Indexed8)).copy((*pBasicDemo->qImage1).rect());
		emit pBasicDemo->sndimage1(pBasicDemo->qImage1, 0, 0);//发送图像，帧数和丢帧数，用于界面显示
		mutex1.unlock();
	}
}
void   __stdcall ImageCallBack2(unsigned char* pData, MV_FRAME_OUT_INFO_EX* pFrameInfo, void* pUser)
{
	if (pFrameInfo)
	{
		OM *pBasicDemo = (OM*)pUser;

		// 获取相机网络流量和丢包信息
		MV_ALL_MATCH_INFO struMatchInfo = { 0 };
		MV_MATCH_INFO_NET_DETECT stMatchInfoNetDetect;
		struMatchInfo.pInfo = &stMatchInfoNetDetect;

		struMatchInfo.nType = MV_MATCH_TYPE_NET_DETECT; // 网络流量和丢包信息
		memset(&stMatchInfoNetDetect, 0, sizeof(MV_MATCH_INFO_NET_DETECT));
		_ASSERTE(_CrtCheckMemory());//用于查看内存使用溢出
		struMatchInfo.nInfoSize = sizeof(MV_MATCH_INFO_NET_DETECT);

		int nRet = pBasicDemo->m_pcMyCamera[n_Camera2]->GetAllMatchInfo(&struMatchInfo);
		if (MV_OK != nRet)
		{
			memset(&stMatchInfoNetDetect, 0, sizeof(MV_MATCH_INFO_NET_DETECT));
			_ASSERTE(_CrtCheckMemory());//用于查看内存使用溢出
		}

		//*matImage2 = Mat(pFrameInfo->nHeight, pFrameInfo->nWidth, CV_8UC1);
		if (pData != NULL)
		{
			matImage2->data = (unsigned char *)pData;
			//imshow("adsfas", *matImage2);
		}

//		vector<ST_BeltInfo> vecStBeltInfo;
//		int n_Ret = pBasicDemo->myDetect->beltdetect2(image, *matImage2, vecStBeltInfo, 1);

		mutex2.lock();
		*pBasicDemo->qImage2 = (QImage((unsigned char *)((*matImage2).data), (*matImage2).cols, (*matImage2).rows, (*matImage2).cols * sizeof(unsigned char), QImage::Format_Indexed8)).copy((*pBasicDemo->qImage2).rect());
		emit pBasicDemo->sndimage2(pBasicDemo->qImage2, 0, 0);//发送图像，帧数和丢帧数，用于界面显示
		mutex2.unlock();
	}
}
// 初始化相机，有打开相机操作
void OM::initDevice()
{
	qInfo() << "initDevice";
	m_bRetStatus = STATUS_OK;

	int nRet = OpenDevice();
	if (STATUS_OK != nRet)
	{
		m_bRetStatus = STATUS_ERROR;
		return;
	}

	m_nTriggerMode = TRIGGER_OFF;
	m_bRetStatus = STATUS_OK;
	nRet = SetTriggerMode();
	if (STATUS_OK != nRet)
	{
		m_bRetStatus = STATUS_ERROR;
		return;
	}
	if (STATUS_OK != m_bRetStatus)
	{
		return;
	}

	int is_exsit = 0;
	for (int i = 0; i < m_stDevList.nDeviceNum; i++)
	{
		if (strcmp(sz_camera1.toStdString().c_str(), (char *)(m_stDevList.pDeviceInfo[i]->SpecialInfo.stGigEInfo.chSerialNumber)) == 0)
		{
			is_exsit++;
			n_Camera1 = i;
			nRet = m_pcMyCamera[i]->RegisterImageCallBack(ImageCallBack1, this);
			nRet = m_pcMyCamera[i]->SetEnumValue("GainAuto", 0);
			nRet = m_pcMyCamera[i]->SetFloatValue("Gain", d_gain1);
			nRet = m_pcMyCamera[i]->SetEnumValue("ExposureMode", 0);
			nRet = m_pcMyCamera[i]->SetFloatValue("ExposureTime", d_exposure1);
			nRet = m_pcMyCamera[i]->SetEnumValue("AcquisitionFrameRate", 0);
			nRet = m_pcMyCamera[i]->SetFloatValue("AcquisitionFrameRate", n_realFrame1);
			nRet = m_pcMyCamera[i]->SetEnumValue("AcquisitionFrameRateEnable", 0);
			nRet = m_pcMyCamera[i]->SetBoolValue("AcquisitionFrameRateEnable", true);
			unsigned int n_width;
			unsigned int n_height;
			nRet = m_pcMyCamera[i]->GetIntValue("WidthMax", &n_width);
			nRet = m_pcMyCamera[i]->GetIntValue("HeightMax", &n_height);
			nRet = m_pcMyCamera[i]->SetEnumValue("Width", 0);
			nRet = m_pcMyCamera[i]->SetIntValue("Width", n_width);
			nRet = m_pcMyCamera[i]->SetEnumValue("Height", 0);
			nRet = m_pcMyCamera[i]->SetIntValue("Height", 600);
			nRet = m_pcMyCamera[i]->SetEnumValue("OffsetY", 0);
			nRet = m_pcMyCamera[i]->SetIntValue("OffsetY", (n_height - 600) / 2);
			qInfo() << "相机编号：" << (const char*)(sz_camera1.toStdString().c_str()) << "," << (char*)(m_stDevList.pDeviceInfo[i]->SpecialInfo.stGigEInfo.chSerialNumber) << ",n_Camera1" << n_Camera1;
		}
		if (strcmp(sz_camera2.toStdString().c_str(), (char *)(m_stDevList.pDeviceInfo[i]->SpecialInfo.stGigEInfo.chSerialNumber)) == 0)
		{
			is_exsit++;
			n_Camera2 = i;
			nRet = m_pcMyCamera[i]->RegisterImageCallBack(ImageCallBack2, this);
			nRet = m_pcMyCamera[i]->SetEnumValue("GainAuto", 0);
			nRet = m_pcMyCamera[i]->SetFloatValue("Gain", d_gain2);
			nRet = m_pcMyCamera[i]->SetEnumValue("ExposureMode", 0);
			nRet = m_pcMyCamera[i]->SetFloatValue("ExposureTime", d_exposure2);
			nRet = m_pcMyCamera[i]->SetEnumValue("AcquisitionFrameRate", 0);
			nRet = m_pcMyCamera[i]->SetFloatValue("AcquisitionFrameRate", n_realFrame2);
			nRet = m_pcMyCamera[i]->SetEnumValue("AcquisitionFrameRateEnable", 0);
			nRet = m_pcMyCamera[i]->SetBoolValue("AcquisitionFrameRateEnable", true);
			unsigned int n_width;
			unsigned int n_height;
			nRet = m_pcMyCamera[i]->GetIntValue("WidthMax", &n_width);
			nRet = m_pcMyCamera[i]->GetIntValue("HeightMax", &n_height);
			nRet = m_pcMyCamera[i]->SetEnumValue("Width", 0);
			nRet = m_pcMyCamera[i]->SetIntValue("Width", n_width);
			nRet = m_pcMyCamera[i]->SetEnumValue("Height", 0);
			nRet = m_pcMyCamera[i]->SetIntValue("Height", 600);
			nRet = m_pcMyCamera[i]->SetEnumValue("OffsetY", 0);
			nRet = m_pcMyCamera[i]->SetIntValue("OffsetY", (n_height - 600) / 2);
			qInfo() << "相机编号：" << (const char*)(sz_camera2.toStdString().c_str()) << "," << (char*)(m_stDevList.pDeviceInfo[i]->SpecialInfo.stGigEInfo.chSerialNumber) << ",n_Camera2" << n_Camera2;
		}

		if (is_exsit == 0)
		{
			if (strcmp(sz_camera1.toStdString().c_str(), "NOUSE") == 0)
			{
				n_Camera1 = i;
				sz_camera1 = ((char *)(m_stDevList.pDeviceInfo[i]->SpecialInfo.stGigEInfo.chSerialNumber));
				nRet = m_pcMyCamera[i]->RegisterImageCallBack(ImageCallBack1, this);
				nRet = m_pcMyCamera[i]->SetEnumValue("GainAuto", 0);
				nRet = m_pcMyCamera[i]->SetFloatValue("Gain", d_gain1);
				nRet = m_pcMyCamera[i]->SetEnumValue("ExposureMode", 0);
				nRet = m_pcMyCamera[i]->SetFloatValue("ExposureTime", d_exposure1);
				nRet = m_pcMyCamera[i]->SetEnumValue("AcquisitionFrameRate", 0);
				nRet = m_pcMyCamera[i]->SetFloatValue("AcquisitionFrameRate", n_realFrame1);
				nRet = m_pcMyCamera[i]->SetEnumValue("AcquisitionFrameRateEnable", 0);
				nRet = m_pcMyCamera[i]->SetBoolValue("AcquisitionFrameRateEnable", true);
				unsigned int n_width;
				unsigned int n_height;
				nRet = m_pcMyCamera[i]->GetIntValue("WidthMax", &n_width);
				nRet = m_pcMyCamera[i]->GetIntValue("HeightMax", &n_height);
				nRet = m_pcMyCamera[i]->SetEnumValue("Width", 0);
				nRet = m_pcMyCamera[i]->SetIntValue("Width", n_width);
				nRet = m_pcMyCamera[i]->SetEnumValue("Height", 0);
				nRet = m_pcMyCamera[i]->SetIntValue("Height", 600);
				nRet = m_pcMyCamera[i]->SetEnumValue("OffsetY", 0);
				nRet = m_pcMyCamera[i]->SetIntValue("OffsetY", (n_height - 600) / 2);
				qInfo() << "相机编号：" << (const char*)(sz_camera1.toStdString().c_str()) << "," << (char*)(m_stDevList.pDeviceInfo[i]->SpecialInfo.stGigEInfo.chSerialNumber) << ",n_Camera1" << n_Camera1;
				p->SetValue("camera", "Camera1", (char*)(m_stDevList.pDeviceInfo[i]->SpecialInfo.stGigEInfo.chSerialNumber));
			}
			else if (strcmp(sz_camera2.toStdString().c_str(), "NOUSE") == 0)
			{
				n_Camera2 = i;
				sz_camera2 = ((char *)(m_stDevList.pDeviceInfo[i]->SpecialInfo.stGigEInfo.chSerialNumber));
				nRet = m_pcMyCamera[i]->RegisterImageCallBack(ImageCallBack2, this);
				nRet = m_pcMyCamera[i]->SetEnumValue("GainAuto", 0);
				nRet = m_pcMyCamera[i]->SetFloatValue("Gain", d_gain2);
				nRet = m_pcMyCamera[i]->SetEnumValue("ExposureMode", 0);
				nRet = m_pcMyCamera[i]->SetFloatValue("ExposureTime", d_exposure2);
				nRet = m_pcMyCamera[i]->SetEnumValue("AcquisitionFrameRate", 0);
				nRet = m_pcMyCamera[i]->SetFloatValue("AcquisitionFrameRate", n_realFrame2);
				nRet = m_pcMyCamera[i]->SetEnumValue("AcquisitionFrameRateEnable", 0);
				nRet = m_pcMyCamera[i]->SetBoolValue("AcquisitionFrameRateEnable", true);
				unsigned int n_width;
				unsigned int n_height;
				nRet = m_pcMyCamera[i]->GetIntValue("WidthMax", &n_width);
				nRet = m_pcMyCamera[i]->GetIntValue("HeightMax", &n_height);
				nRet = m_pcMyCamera[i]->SetEnumValue("Width", 0);
				nRet = m_pcMyCamera[i]->SetIntValue("Width", n_width);
				nRet = m_pcMyCamera[i]->SetEnumValue("Height", 0);
				nRet = m_pcMyCamera[i]->SetIntValue("Height", 600);
				nRet = m_pcMyCamera[i]->SetEnumValue("OffsetY", 0);
				nRet = m_pcMyCamera[i]->SetIntValue("OffsetY", (n_height - 600) / 2);
				qInfo() << "相机编号：" << (const char*)(sz_camera2.toStdString().c_str()) << "," << (char*)(m_stDevList.pDeviceInfo[i]->SpecialInfo.stGigEInfo.chSerialNumber) << ",n_Camera1" << n_Camera1;
				p->SetValue("camera", "Camera2", (char*)(m_stDevList.pDeviceInfo[i]->SpecialInfo.stGigEInfo.chSerialNumber));
			}
		}
		is_exsit = 0;
	}
	//p->SetValue("camera", "CameraNum", QString::number(CameraNum).toStdString());
	p->WriteINI(path);
	return;
}
// 设置触发模式
Status OM::SetTriggerMode(void)
{
	qInfo() << "SetTriggerMode";
	if (false == m_bOpenDevice)
	{
		return STATUS_ERROR;
	}
	int nRet = MV_OK;
	int i = 0;

	for (i = 0; i < m_nUseNumEdit; i++)
	{
		nRet = m_pcMyCamera[i]->SetEnumValue("TriggerMode", m_nTriggerMode);
	}

	return STATUS_OK;
}
// 打开设备
Status OM::OpenDevice(void)
{
	qInfo() << "OpenDevice";
	if (true == m_bOpenDevice)
	{
		return STATUS_ERROR;
	}
	if (true == m_bCreateDevice)
	{
		return STATUS_ERROR;
	}
	// 参数检测
	if (m_nUseNumEdit <= 0)
	{
		m_nUseNumEdit = 1;
	}
	if (m_nUseNumEdit > 4)
	{
		m_nUseNumEdit = 4;
	}

	int nCanOpenDeviceNum = 0;
	int nRet = MV_OK;

	for (int i = 0, j = 0; j < m_stDevList.nDeviceNum; j++, i++)
	{
		// 由设备信息创建设备实例
		if (NULL == m_stDevList.pDeviceInfo[i])
		{
			return STATUS_ERROR;
		}
		if (NULL != m_pcMyCamera[i])
		{
			return STATUS_ERROR;
		}
		m_pcMyCamera[i] = new CMyCamera;
		m_pcMyCamera[i]->m_pBufForDriver = NULL;
		m_pcMyCamera[i]->m_pBufForSaveImage = NULL;
		m_pcMyCamera[i]->m_nBufSizeForDriver = 0;
		m_pcMyCamera[i]->m_nBufSizeForSaveImage = 0;
		/*m_pcMyCamera[i]->StopGrabbing();
		m_pcMyCamera[i]->Close();*/

		nRet = m_pcMyCamera[i]->Open(m_stDevList.pDeviceInfo[i]);//有异常

		if (MV_OK != nRet)
		{
			QString str;
			str.append("相机");
			str.append(QString::number(j + 1));
			str.append("被占用");
			qInfo() << str;
			ui.textBrowser->append(str);
			delete(m_pcMyCamera[i]);
			m_pcMyCamera[i] = NULL;
			i--;
		}
		else
		{
			QString str;
			str.append("相机");
			str.append(QString::number(j + 1));
			str.append("初始化成功");
			qInfo() << str;
			ui.textBrowser->append(str);
			nCanOpenDeviceNum++;
			if (nCanOpenDeviceNum == m_stDevList.nDeviceNum)
			{
				break;
			}
		}
	}

	//if (m_stDevList.nDeviceNum == 0)
	//{
	//	n_once = 1;
	//	nRet = DestroyDevice();     // 重新检查下是否释放内存  
	//	m_nUseNumEdit = 0;
	//	m_stDevList.nDeviceNum = 0;
	//	ui.textBrowser->append("请查看相机连接情况！");
	//	qInfo() << "请查看相机连接情况！";
	//	return STATUS_ERROR;
	//}

	if (m_stDevList.nDeviceNum != nCanOpenDeviceNum)     // 可打开设备为0
	{
		nRet = DestroyDevice();     // 重新检查下是否释放内存  
		m_nUseNumEdit = 0;
		m_stDevList.nDeviceNum = 0;
		return STATUS_ERROR;
	}
	m_nUseNumEdit = nCanOpenDeviceNum;

	m_bCreateDevice = true;
	m_bOpenDevice = true;
	m_bRetStatus = STATUS_OK;

	ui.textBrowser->append("打开相机成功");
	qInfo() << "打开相机成功";
	return STATUS_OK;
}
// 开始采集
Status OM::startGrabbing(void)
{
	qInfo() << "beltDetectstartGrabbing";
	if (false == m_bOpenDevice || true == m_bStartGrabbing)
	{
		return STATUS_ERROR;
	}
	int nRet = MV_OK;
	int i = 0;

	for (i = 0; i < m_stDevList.nDeviceNum; i++)
	{
		//nRet = m_pcMyCamera[i]->
		nRet = m_pcMyCamera[i]->StartGrabbing();
		if (MV_OK != nRet)
		{
			// return STATUS_ERROR;          // 不return。因为是多相机，防止因为一个相机的断线使其他相机无法正常运行
		}
		m_bStartGrabbing = true;
	}

	return STATUS_OK;
}
// 结束采集
Status OM::StopGrabbing(void)
{
	qInfo() << "StopGrabbing";
	int nRet = CMyCamera::EnumDevices(&m_stDevList);
	if (MV_OK != nRet)
	{
		m_bRetStatus = STATUS_ERROR;
	}
	if (false == m_bOpenDevice || false == m_bStartGrabbing)
	{
		return STATUS_ERROR;
	}
	m_bRetStatus = STATUS_OK;
	int i = 0;
	nRet = MV_OK;
	for (i = 0; i < m_stDevList.nDeviceNum; i++)
	{
		nRet = m_pcMyCamera[i]->StopGrabbing();
		if (MV_OK != nRet)
		{
			m_bRetStatus = STATUS_ERROR;
		}
	}

	m_bStartGrabbing = false;
	return m_bRetStatus;
}
// 关闭设备
Status OM::CloseDevice(void)
{
	qInfo() << "CloseDevice";
	int i = 0;
	int nRet = MV_OK;
	nRet = CMyCamera::EnumDevices(&m_stDevList);
	if (MV_OK != nRet)
	{
		m_bRetStatus = STATUS_ERROR;
	}
	if (false == m_bCreateDevice || false == m_bOpenDevice)
	{
		return STATUS_ERROR;
	}
	m_bRetStatus = STATUS_OK;
	for (i = 0; i < m_stDevList.nDeviceNum; i++)
	{
		if (m_pcMyCamera[i])
		{
			nRet = m_pcMyCamera[i]->Close();
		}
		if (MV_OK != nRet)
		{
			m_bRetStatus = STATUS_ERROR;
		}
	}
	m_bStartGrabbing = false;
	m_bOpenDevice = false;
	return m_bRetStatus;
}
// 销毁句柄
Status OM::DestroyDevice(void)
{
	qInfo() << "DestroyDevice";
	int nRet = CMyCamera::EnumDevices(&m_stDevList);
	if (MV_OK != nRet)
	{
		m_bRetStatus = STATUS_ERROR;
	}
	m_bRetStatus = STATUS_OK;
	for (int i = 0; i < m_stDevList.nDeviceNum; i++)
	{
		if (m_pcMyCamera[i] && m_pcMyCamera[i]->m_pBufForDriver)
		{
			free(m_pcMyCamera[i]->m_pBufForDriver);
			m_pcMyCamera[i]->m_pBufForDriver = NULL;
		}

		if (m_pcMyCamera[i] && m_pcMyCamera[i]->m_pBufForSaveImage)
		{
			free(m_pcMyCamera[i]->m_pBufForSaveImage);
			m_pcMyCamera[i]->m_pBufForSaveImage = NULL;
			m_pcMyCamera[i]->m_pBufForSaveImage = 0;
		}

		if (m_pcMyCamera[i])
		{
			delete(m_pcMyCamera[i]);
			m_pcMyCamera[i] = NULL;
		}
	}

	m_bCreateDevice = false;
	m_bOpenDevice = false;
	m_bStartGrabbing = false;
	return STATUS_OK;
}

void OM::showimage1(QImage *qImage, unsigned int FrameCount, unsigned int LostFrameCout)
{
	if ((m_bShowTQImage == true))
	{
		mutex1.lock();
		ui.label_display1->setPixmap(QPixmap::fromImage(*qImage));
		ui.label_display1->setPixmap(QPixmap::fromImage(*qImage));
		//图像保存
		QTime time;
		time=QTime::currentTime();
		QString fileName;
		fileName = QString("D:\\image\\%1-%2-%3.jpg").arg(time.hour()).arg(time.minute()).arg(time.second());

		qImage->save(fileName);
		mutex1.unlock();
	}
}
void OM::showimage2(QImage *qImage, unsigned int FrameCount, unsigned int LostFrameCout)
{
	QString pos;
	if ((m_bShowNYImage == true))
	{
		mutex2.lock();
		ui.label_display1->setPixmap(QPixmap::fromImage(*qImage));
		mutex2.unlock();
	}
}
void OM::OnBnClearTextBrower()
{
	qInfo() << "OnBnClearTextBrower";
	qInfo() << "清空显示框";
	ui.textBrowser->setText("");
}
void OM::setFrameRates()
{
	qInfo() << "showFrameRates";

	n_FrameCount[0] = 0;
	n_FrameCount[1] = 0;
	n_FrameCount[2] = 0;
	n_FrameCount[3] = 0;
}

int nal_temp = 0;
void OM::WFSport()
{
	nal_temp++;
	if (nal_temp % 2 == 0)
	{
		Relay18Released();
		Delay_MSec(200);
		Relay17Pressed();
	}
	else
	{
		Relay17Released();
		Delay_MSec(200);
		Relay18Pressed();
	}
}
void OM::WFStart()
{
	WFtimer->start();
}
void OM::WFStop()
{
	WFtimer->stop();
	Relay18Released();
	Delay_MSec(200);
	Relay17Released();
}
void OM::startDetect()
{
	qInfo() << "相机启动";
	ui.textBrowser->append("相机启动");
	
	//加载配置文件
	p = new CMyINI();
	path.append((qApp->applicationDirPath()).toStdString());
	path.append("/config/camera.ini");
	nRet = p->ReadINI(path);
	CameraNum = (QString::fromStdString(p->GetValue("camera", "CameraNum"))).toInt();
	sz_camera1 = QString::fromStdString((p->GetValue("camera", "Camera1")).c_str());
	sz_camera2 = QString::fromStdString((p->GetValue("camera", "Camera2")).c_str());
	cameraNY = QString::fromStdString((p->GetValue("camera", "CameraNY")).c_str());
	cameraTQ = QString::fromStdString((p->GetValue("camera", "CameraTQ")).c_str());
	d_exposure1 = (QString::fromStdString(p->GetValue("camera", "exposure1"))).toDouble();
	d_exposure2 = (QString::fromStdString(p->GetValue("camera", "exposure2"))).toDouble();
	d_gain1 = (QString::fromStdString(p->GetValue("camera", "gain1"))).toDouble();
	d_gain2 = (QString::fromStdString(p->GetValue("camera", "gain2"))).toDouble();
	n_realFrame1 = (QString::fromStdString(p->GetValue("camera", "frame1"))).toInt();
	n_realFrame2 = (QString::fromStdString(p->GetValue("camera", "frame2"))).toInt();

	if ((sz_camera1 == "NOUSE") || (sz_camera2 == "NOUSE"))
	{
		CameraNum = -1;
	}

	qInfo() << "配置了" << CameraNum << "相机";
	int nRet = 0;
	n_once = 0;
	
	int n_IPnum = 0;
	//获取本地MAC
	QList<QNetworkInterface> nets = QNetworkInterface::allInterfaces();// 获取所有网络接口列表
	int nCnt = nets.count();
	QString strMacAddr = "";
	for (int i = 0; i < nCnt; i++)
	{
		// 如果此网络接口被激活并且正在运行并且不是回环地址，则就是我们需要找的Mac地址
		if (/*nets[i].flags().testFlag(QNetworkInterface::IsUp) && nets[i].flags().testFlag(QNetworkInterface::IsRunning)&&*/ 
			!nets[i].flags().testFlag(QNetworkInterface::IsLoopBack))
		{
			strMacAddr = nets[i].hardwareAddress();
			qInfo() << strMacAddr;
			ui.textBrowser->append(strMacAddr);
			n_IPnum++;
		}
	}

	qInfo() << "初始化相机列表";
	memset(&m_stDevList, 0, sizeof(m_stDevList));
	_ASSERTE(_CrtCheckMemory());//用于查看内存使用溢出
	nRet = CMyCamera::EnumDevices(&m_stDevList);
	while (m_stDevList.nDeviceNum != CameraNum)//初始化相机列表
	{
		if (n_isclose == 1)
		{
			return;
		}
		if (n_once < 10)
		{
			nRet = CMyCamera::EnumDevices(&m_stDevList);
			CameraNum = m_stDevList.nDeviceNum;
			QString str;
			str.append("有");
			str.append(QString::number(m_stDevList.nDeviceNum));
			str.append("个相机在线");
			qInfo() << str;
			ui.textBrowser->append(str);
			QCoreApplication::processEvents();
		}
		else
		{
			if (m_stDevList.nDeviceNum != CameraNum)
			{
				QString str;
				str.append("有");
				str.append(QString::number(m_stDevList.nDeviceNum));
				str.append("个相机在线,");
				str.append("但是配置了");
				str.append(QString::number(CameraNum));
				str.append("个相机，请重新配置");
				qInfo() << str;
				ui.textBrowser->append(str);
			}
			ui.textBrowser->append("相机加载不成功，请重新开启检测");
			qInfo() << "相机加载不成功，请重新开启检测";

			break;
		}
		n_once++;
	}
	m_nOnlineNumEdit = m_stDevList.nDeviceNum;
	m_nUseNumEdit = m_stDevList.nDeviceNum;

	int n_initCameraNum = 100;
	int n_initNUm = 0;
	do
	{
		n_initNUm++;
		if (n_isclose == 1)
		{
			return;
		}
		Delay_MSec(1000);
		initDevice();		//打开相机
		if (m_bRetStatus == STATUS_ERROR)
		{
			qInfo() << "有相机被占用，打开相机失败";
			ui.textBrowser->append("有相机被占用，打开相机失败");
			nRet = CloseDevice();
			if (STATUS_OK != nRet)
			{
				ui.textBrowser->append("关闭设备失败");
				qInfo() << "关闭设备失败";
				m_bRetStatus = STATUS_ERROR;
			}
			nRet = DestroyDevice();
			if (STATUS_OK != nRet)
			{
				ui.textBrowser->append("销毁设备失败");
				qInfo() << "销毁设备失败";
				m_bRetStatus = STATUS_ERROR;
			}
			ui.textBrowser->append("请耐心等待相机恢复");
			qInfo() << "请耐心等待相机恢复";
			QString str;
			str.append("重新初始化相机,第");
			str.append(QString::number(n_initNUm));
			str.append("次");
			ui.textBrowser->append(str);
			qInfo() << str;
			QCoreApplication::processEvents();
		}
		else
		{
			break;
		}
	} while (n_initCameraNum--);

	if (n_initCameraNum <= 0)
	{
		return;
	}

	nRet = startGrabbing();
	if (STATUS_OK != nRet)
	{
		ui.textBrowser->append("抓图失败");
		qInfo() << "抓图失败";
		m_bRetStatus = STATUS_ERROR;
		Delay_MSec(1000);
		stopDetect();
		Delay_MSec(1000);
		startDetect();
	}
	if (strcmp(cameraNY.toStdString().c_str(), sz_camera1.toStdString().c_str()) == 0)
	{
		m_bShowNYImage = true;
		m_bShowTQImage = false;
		ui.pushButton_3->setEnabled(false);
		ui.pushButton_11->setEnabled(true);
	}
	else
	{
		m_bShowNYImage = false;
		m_bShowTQImage = true;
		ui.pushButton_3->setEnabled(true);
		ui.pushButton_11->setEnabled(false);
	}
	m_bShowImage = true;
	qInfo() << "开启显示图像";
	m_bRetStatus = STATUS_OK;
	qInfo() << "开始采集图像";
	qInfo() << "已开启检测";
}
void OM::stopDetect()
{
	m_bShowImage = false;
	ui.textBrowser->append("开始关闭检测");
	qInfo() << "stopDetect";
	int nRet = CMyCamera::EnumDevices(&m_stDevList);
	if (MV_OK != nRet)
	{
		m_bRetStatus = STATUS_ERROR;
	}
	m_nOnlineNumEdit = m_stDevList.nDeviceNum;
	m_nUseNumEdit = m_stDevList.nDeviceNum;

	nRet = StopGrabbing();
	if (STATUS_OK != nRet)
	{
		m_bRetStatus = STATUS_ERROR;
	}
	else
	{
		ui.textBrowser->append("停止抓图");
	}

	if (m_bOpenDevice == true)
	{
		nRet = CloseDevice();
		if (STATUS_OK != nRet)
		{
			m_bRetStatus = STATUS_ERROR;
		}
		else
		{
			ui.textBrowser->append("关闭设备");
			qInfo() << "关闭设备";
		}
		nRet = DestroyDevice();
		if (STATUS_OK != nRet)
		{
			m_bRetStatus = STATUS_ERROR;
		}
		else
		{
			ui.textBrowser->append("销毁设备");
			qInfo() << "销毁设备";
		}
	}
	ui.textBrowser->append("停止显示图像");
	qInfo() << "停止显示图像";

	sz_camera1.clear();
	sz_camera2.clear();

	qInfo() << "已停止检测";
}
void OM::QBAcrc16(QByteArray &ptr, unsigned int len, unsigned char CRC[2])
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

void OM::Relay1Pressed()//第一路吸合
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
void OM::Relay1Released()
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
void OM::Relay2Pressed()
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
void OM::Relay2Released()
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
void OM::Relay3Pressed()
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
void OM::Relay3Released()
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
void OM::Relay4Pressed()
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
void OM::Relay4Released()
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
void OM::Relay5Pressed()
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
void OM::Relay5Released()
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
void OM::Relay6Pressed()
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
void OM::Relay6Released()
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
void OM::Relay7Pressed()
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
void OM::Relay7Released()
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
void OM::Relay8Pressed()
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
void OM::Relay8Released()
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
void OM::Relay9Pressed()
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
void OM::Relay9Released()
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
void OM::Relay10Pressed()
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
void OM::Relay10Released()
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
void OM::Relay11Pressed()
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
void OM::Relay11Released()
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
void OM::Relay12Pressed()
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
void OM::Relay12Released()
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
void OM::Relay13Pressed()
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
void OM::Relay13Released()
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
void OM::Relay14Pressed()
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
void OM::Relay14Released()
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
void OM::Relay15Pressed()
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
void OM::Relay15Released()
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
void OM::Relay16Pressed()
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
void OM::Relay16Released()
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
void OM::Relay17Pressed()
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
void OM::Relay17Released()
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
void OM::Relay18Pressed()
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
void OM::Relay18Released()
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
void OM::Relay19Pressed()
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
void OM::Relay19Released()
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
void OM::Relay20Pressed()
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
void OM::Relay20Released()
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
void OM::Relay21Pressed()
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
void OM::Relay21Released()
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
void OM::Relay22Pressed()
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
void OM::Relay22Released()
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
void OM::Relay23Pressed()
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
void OM::Relay23Released()
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
void OM::Relay24Pressed()
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
void OM::Relay24Released()
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
void OM::Relay25Pressed()
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
void OM::Relay25Released()
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
void OM::Relay26Pressed()
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
void OM::Relay26Released()
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
void OM::Relay27Pressed()
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
void OM::Relay27Released()
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
void OM::Relay28Pressed()
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
void OM::Relay28Released()
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
void OM::Relay29Pressed()
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
void OM::Relay29Released()
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
void OM::Relay30Pressed()
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
void OM::Relay30Released()
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
void OM::Relay31Pressed()
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
void OM::Relay31Released()
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
void OM::Relay32Pressed()
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
void OM::Relay32Released()
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

void OM::OnOpencvStart()
{
	m_bShowNYImage = true;
	m_bShowTQImage = false;
	ui.pushButton_3->setEnabled(false);
	ui.pushButton_11->setEnabled(true);
}
void OM::OnOpencvEnd()
{
	m_bShowNYImage = false;
	m_bShowTQImage = true;
	ui.pushButton_3->setEnabled(true);
	ui.pushButton_11->setEnabled(false);
}
void OM::getChanged(int i)
{
	if ((i == 0) || (i == 1) || (i == 3))
	{
		if (strcmp(cameraNY.toStdString().c_str(), sz_camera1.toStdString().c_str()) == 0)
		{
			m_bShowNYImage = true;
			m_bShowTQImage = false;
			ui.pushButton_3->setEnabled(false);
			ui.pushButton_11->setEnabled(true);
		}
		else
		{
			m_bShowNYImage = false;
			m_bShowTQImage = true;
			ui.pushButton_3->setEnabled(true);
			ui.pushButton_11->setEnabled(false);
		}
	}
	else
	{
		if (strcmp(cameraTQ.toStdString().c_str(), sz_camera2.toStdString().c_str()) == 0)
		{
			m_bShowNYImage = false;
			m_bShowTQImage = true;
			ui.pushButton_3->setEnabled(true);
			ui.pushButton_11->setEnabled(false);
		}
		else
		{
			m_bShowNYImage = true;
			m_bShowTQImage = false;
			ui.pushButton_3->setEnabled(false);
			ui.pushButton_11->setEnabled(true);
		}
	}
}

void OM::paintEvent(QPaintEvent * event)
{
	int xx = this->geometry().width();
	int yy = this->geometry().height();

	ui.toolBox->setGeometry(QRect(xx - 161 - 10, 10,161, yy - 110));
	ui.label_display1->setGeometry(QRect(10, 10, xx - 161 - 30, yy - 141 - 30));
	
	ui.label_4->setGeometry(QRect(xx - 161 - 10, yy - 10 - 20 - 10 - 20, 71, 20));
	ui.lineEdit_HouZuoLi->setGeometry(QRect(xx - 71 - 10, yy - 10 - 20 - 10 - 20, 71, 20));

	ui.label_9->setGeometry(QRect(xx - 161 - 10, yy - 10 - 20, 71, 20));
	ui.lineEdit_ShuiPing->setGeometry(QRect(xx - 71 - 10, yy - 10 - 20, 71, 20));

	ui.pushButton_3->setGeometry(QRect(xx - 161 - 10, yy - 90, 71, 23));
	ui.pushButton_11->setGeometry(QRect(xx - 71 - 10, yy - 90, 71, 23));
	ui.pushButton_10->setGeometry(QRect(xx - 161 - 10 - 10 - 141, yy - 10 - 141, 141, 141));
	
	ui.textBrowser->setGeometry(QRect(10, yy - 141 - 10, xx - 161 - 10 - 10 - 141 - 10 - 10, 141));
}

void OM::ReadIni()
{
	//配置文件
	CMyINI* pini = new CMyINI();
	string path;
	path.append((qApp->applicationDirPath()).toStdString());
	path.append("/config/config.ini");
	int nRet = pini->ReadINI(path);
	nRet = pini->ReadINI(path);
	if (nRet != 0)
	{
		myIP = QString::fromStdString(pini->GetValue("IP", "IP"));
		myPort = QString::fromStdString((pini->GetValue("IP", "PORT")));
		n_nipaoWZ = atoi((pini->GetValue("WZ", "n_nipaoWZ")).c_str());
		n_zaoyanWZ = atoi((pini->GetValue("WZ", "n_zaoyanWZ")).c_str());
		n_tongqianWZ = atoi((pini->GetValue("WZ", "n_tongqianWZ")).c_str());
		n_tongyangWZ = atoi((pini->GetValue("WZ", "n_tongqianWZ")).c_str());
		n_errLength = atoi((pini->GetValue("WZ", "n_errLength")).c_str());
		n_WFtime = atoi((pini->GetValue("WF", "n_WFtime")).c_str());
		m_openPorePos = atoi((pini->GetValue("WZ", "n_kaiKongPos")).c_str());
		m_duNiPos = atoi((pini->GetValue("WZ", "n_duNiPos")).c_str());
		m_niPaoPower = atoi((pini->GetValue("WZ", "n_niPaoPower")).c_str());
	}
	if (pini != NULL)
	{
		delete pini;
		pini = NULL;
	}
}

void OM::OpenPore()
{
	//1.大电机开
	Relay1Pressed();
	//2.保压开
	Relay13Pressed();
	//3.水平移动,判断到位
	m_machine.m_struType = StructureType::KaiKong;
	if (dzc_WZ >= m_openPorePos)
	{
		Relay27Pressed();//水平左移
		m_machine.m_horiMove = HorizontalMove::LeftMove;
	}
	else
	{
		m_machine.m_horiMove = HorizontalMove::RightMove;
		Relay28Pressed();//水平右移
	}

	/*
	//------临时代码
	//确保松轨
	Relay32Released();
	//开孔4.整车前进
	Relay3Pressed();
	m_machine.m_machineMove = MachineMove::Forward;
	m_machine.m_struType = StructureType::KaiKong;

	m_moveTimer->start(MathineForwardTime);//30s
	//------临时代码
	*/
}

void OM::StartHole()
{
	//开孔7.凿岩前进
	Relay5Pressed();
	//m_zaoYanTimer->start(ZaoYanRotate);//延时10s
	//m_zaoYan = ZaoYan::ZaoYanForward;
	//开孔8.开始凿岩:凿岩旋转
	Relay4Pressed();
	//m_mainOpera->start(30000);
	//m_machine.m_struType = StructureType::KaiKong;
}

void OM::StopHole()
{ 
	//开孔9.停止凿岩前进
	Relay5Released();
	//开孔10.凿岩后退
	Relay6Pressed();
	m_zaoYanTimer->start(ZaoYanBackTime);
	m_zaoYan = ZaoYan::ZaoYanBack;
	
}

void OM::DropSteel()
{
	//捅钎1.落钎
	Relay14Pressed();
	m_tongQianTimer->start(DropSteelTime);
	m_tongQian = TongQianAct::DiaoQian;
}

void OM::ClipSteel()
{
	//捅钎2.马达夹钎
	Relay22Pressed();
	m_tongQianTimer->start(ClampSteelTime);
	m_tongQian = TongQianAct::Clamp;
}

void OM::StartSteel()
{
	//捅钎3.大电机开
	Relay1Pressed();
	//捅钎4.保压开
	Relay13Pressed();
	//捅钎5.水平移动
	m_machine.m_struType = StructureType::TongQian;
	if (dzc_WZ >= m_openPorePos)
	{
		//水平左移
		Relay27Pressed();
		m_machine.m_horiMove = HorizontalMove::LeftMove;
	}
	else
	{
		m_machine.m_horiMove = HorizontalMove::RightMove;
		//水平右移
		Relay28Pressed();
	}
}

void OM::StopSteel()
{
	m_stopTongQian = true;
}

void OM::BlockMud()
{
	//堵泥1.大电机开
	Relay1Pressed();
	//堵泥2.保压开
	Relay13Pressed();
	//堵泥3.水平移动
	m_machine.m_struType = StructureType::DuNi;
	if (dzc_WZ >= m_duNiPos)
	{
		Relay27Pressed();//水平左移
		m_machine.m_horiMove = HorizontalMove::LeftMove;
	}
	else
	{
		Relay28Pressed();//水平右移
		m_machine.m_horiMove = HorizontalMove::RightMove;
	}
}

void OM::StopMud()
{
	//堵泥11.松轨
	Relay32Released();
	m_clampAndLooseTimer->start(LooseClampRail);
	m_machine.m_railOper = RailOper::LooseRail;
}

void OM::OnStopMove()
{
	if (m_machine.m_struType==StructureType::KaiKong)
	{
		if (m_machine.m_machineMove == MachineMove::Forward)
		{
			m_moveTimer->stop();
			//开孔5.停止移动
			Relay3Released();
			//开孔6.夹轨
			Relay31Pressed();
			m_machine.m_railOper = RailOper::ClampRail;
			m_clampAndLooseTimer->start(LooseClampRail);
		}
		else if (m_machine.m_machineMove == MachineMove::Back)
		{
			//整车回退停止,开孔操作结束
			Relay2Released();

			m_machine.m_struType == StructureType::StructureUnknow;
			m_machine.m_machineMove = MachineMove::Unknow;
			m_machine.m_horiMove = HorizontalMove::Default;
			m_machine.m_railOper = RailOper::RailOperUnknow;
		}
	}
	if (m_machine.m_struType == StructureType::DuNi)
	{
		if (m_machine.m_machineMove == MachineMove::Forward)
		{
			m_moveTimer->stop();
			//堵泥6.夹轨
			Relay31Pressed();
			m_clampAndLooseTimer->start(LooseClampRail);
			m_machine.m_railOper = RailOper::ClampRail;			
		}
		else if (m_machine.m_machineMove == MachineMove::Back)
		{
			m_moveTimer->stop();
			//开孔13.停止整车移动
			Relay2Released();
			//整车退回,堵泥结束
			m_machine.m_struType == StructureType::StructureUnknow;
			m_machine.m_machineMove = MachineMove::Unknow;
			m_machine.m_horiMove = HorizontalMove::Default;
			m_machine.m_railOper = RailOper::RailOperUnknow;
		}
	}
	else if (m_machine.m_struType == StructureType::TongQian)
	{
		if (m_machine.m_machineMove == MachineMove::Forward)
		{
			//停止移动
			Relay3Released();
			//捅钎7.夹轨
			Relay31Pressed();
			m_clampAndLooseTimer->start(LooseClampRail);
			m_machine.m_railOper = RailOper::ClampRail;
		}
		else if (m_machine.m_machineMove == MachineMove::Back)
		{
			//捅钎13.回退停止,捅钎结束
			Relay2Released();

			m_machine.m_struType == StructureType::StructureUnknow;
			m_machine.m_machineMove = MachineMove::Unknow;
			m_machine.m_horiMove = HorizontalMove::Default;
			m_machine.m_railOper = RailOper::RailOperUnknow;
		}
		m_moveTimer->stop();
		m_machine.m_machineMove == MachineMove::Unknow;
	}	
}

void OM::OnTimeOver()
{
	if (m_machine.m_struType == StructureType::DuNi)
	{
		m_mainOpera->stop();
		//堵泥10.停止挤泥
		Relay11Released();
	}
	if (m_machine.m_struType == StructureType::KaiKong)
	{
		//停止凿岩旋转
		Relay4Released();
		//关闭定时器
		m_mainOpera->stop();
	}
	//if (m_machine.m_struType == StructureType::TongQian)
	//{
	//	//关闭定时器
	//	m_mainOpera->stop();
	//	//捅钎7.夹轨


	//}
	//m_machine.m_struType == StructureType::StructureUnknow;
}

void OM::OnDoZaoYan()
{
	if (m_zaoYan == ZaoYan::ZaoYanForward) 
	{
		m_zaoYanTimer->stop();
		//停止凿岩前进
		Relay5Released();
	}
	else if (m_zaoYan == ZaoYan::ZaoYanBack)
	{
		m_zaoYanTimer->stop();
		//开孔11.停止凿岩后退
		Relay6Released();
		//开孔12.停止凿岩旋转
		Relay4Released();
		//开孔13.松开夹轨
		Relay32Pressed();
		m_clampAndLooseTimer->start(LooseClampRail);
		m_machine.m_struType = StructureType::KaiKong;
		m_machine.m_railOper = RailOper::LooseRail;
	}

	m_zaoYan == ZaoYan::ZaoYanUnknow;
}

void OM::OnDoTongQian()
{
	if (m_tongQian == TongQianAct::DiaoQian)
	{
		//掉钎1.停止掉钎
		Relay14Released();
	}
	if (m_tongQian == TongQianAct::Clamp)
	{
		//捅钎2.马达夹钎停止,夹钎到位
		Relay22Released();
	}
	m_tongQianTimer->stop();
	m_tongQian = TongQianAct::TongQianUnknow;
}

void OM::OnDoExtendQian()
{
	m_extendTimer->stop();
	//停止马达捅钎
	Relay20Released();
	//捅钎9.马达收钎
	Relay19Pressed();
	
	if (m_times == 3 || m_stopTongQian)
	{
		m_tongQian = TongQianAct::ShinkSteelReturn;
		m_times = 0;
		m_shinkTimer->start(ShinkToZeroTime);
	}
	else
	{
		m_times++;
		m_tongQian = TongQianAct::ShouQian;
		m_shinkTimer->start(ShinkSteelTime);
	}
}

void OM::OnDoShinkQian()
{
	//停止收钎
	m_tongQian = TongQianAct::TongQianUnknow;

	Relay19Released();
	m_shinkTimer->stop();

	if (!m_stopTongQian)
	{
		//捅钎8.马达捅钎
		Relay20Pressed();
		m_extendTimer->start(ExtendSteelTime);
		m_tongQian = TongQianAct::ShenQian;
	}
	else
	{
		m_stopTongQian = false;
		//捅钎10.捅钎完成,松开夹轨
		Relay32Pressed();
		m_clampAndLooseTimer->start(LooseClampRail);
		m_machine.m_railOper = RailOper::LooseRail;
	}
}

void OM::OnDoClampAndLoose()
{
	if (m_machine.m_struType == StructureType::KaiKong)
	{
		if (m_machine.m_railOper== RailOper::ClampRail)
		{
			m_clampAndLooseTimer->stop();
			//停止夹轨
			Relay31Released();
		}
		else if (m_machine.m_railOper == RailOper::LooseRail)
		{
			m_clampAndLooseTimer->stop();
			//停止松轨
			Relay32Released();
			//开孔14.关闭大电机
			Relay1Released();
			//开孔15.关闭保压
			Relay13Released();
			//开孔16.整车退回
			Relay2Pressed();
			//开启定时器,到时停止后退
			m_moveTimer->start(MachineBackTime);

			m_machine.m_struType = StructureType::KaiKong;
			m_machine.m_machineMove = MachineMove::Back;
			m_machine.m_railOper = RailOper::RailOperUnknow;
		}
	}

	if (m_machine.m_struType==StructureType::DuNi)
	{
		if (m_machine.m_railOper == RailOper::ClampRail)
		{
			m_clampAndLooseTimer->stop();
			//堵泥7.泥泡前进
			Relay9Pressed();
			//堵泥8.判断泥泡到位:根据泥泡后座力	
		}
		else if (m_machine.m_railOper == RailOper::LooseRail)
		{
			m_clampAndLooseTimer->stop();
			//堵泥12.关闭大电机
			Relay1Released();
			//堵泥13.关闭保压
			Relay13Released();
			//堵泥14.整车后退
			Relay2Pressed();
			m_moveTimer->start(10 * 1000);
			m_machine.m_struType = StructureType::DuNi;
			m_machine.m_machineMove = MachineMove::Back;
		}
	}

	if (m_machine.m_struType == StructureType::TongQian)
	{
		if (m_machine.m_railOper == RailOper::ClampRail)
		{
			m_clampAndLooseTimer->stop();
			//停止夹轨
			Relay31Released();

			m_tongQian = TongQianAct::TongQianOper;
			//捅钎8.马达捅钎
			Relay20Pressed();
			m_extendTimer->start(ExtendSteelTime);
		}
		else if (m_machine.m_railOper == RailOper::LooseRail)
		{

			m_clampAndLooseTimer->stop();
			//停止松轨
			Relay32Released();
			//捅钎11.大电机关
			Relay10Released();
			//捅钎12.保压关
			Relay13Released();

			//捅钎13.整车回退
			Relay2Pressed();
			m_moveTimer->start(MachineBackTime);
			m_machine.m_struType = StructureType::TongQian;
			m_machine.m_machineMove = MachineMove::Back;
		}
	}

	m_machine.m_railOper = RailOper::RailOperUnknow;
}
