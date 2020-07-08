#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_OM.h"
#include "qtcpsocket.h"
#include "Alog.h"
#include "RelayControl.h"
#include "MyCamera.h"
#include "MvCameraDefine.h"
#include "qtimer.h"
#include "cmyini.h"
#include "windows.h"
#include "atltypes.h"
#include "windef.h"
#include "hi_sdk_api.h"
#include "mythread.h"
#include "define.h"


typedef struct hiVEDIO_INFO
{
	HI_HANDLE			lHandle;	//SDK句柄
	HI_CHAR				sHost[64];	//IPC地址
	HI_CHAR				sUser[32];	//用户名
	HI_CHAR				sPass[32];	//密码
	HI_BOOL				bTalk;		//对讲状态
	HI_BOOL				bRecord;	//录像状态
	HI_BOOL				bShowInfo;	//播放时显示码率、帧率
	HI_BOOL				bAlarmArea;	//发生移动侦测时显示红色报警框
	HI_BOOL				bEditArea;	//编译报警区域
	HI_U16				u16Port;	//端口
	HI_U32				u32Stream;	//码流
	HI_S32				s32Volume;	//音量
	HI_S32				s32Channel;	//通道
	AUDIO_MUTE_E		eMute;		//声音状态
	HI_S_ProductVendor	product;	//产品类型
	HI_S_Display		display;	//色彩
	HI_S_MD_PARAM		mdParam[MAX_MD_NUMBER];	//移动侦测区域
	HI_S_SUPPORT		pSupport;	//设备能力，包括分辨率，最大码率
}HI_VEDIO_INFO;

#define MAXSCREEN 25
#define MAXCAM 32

class OM : public QMainWindow
{
	Q_OBJECT
public:
	OM(QWidget *parent = Q_NULLPTR);
	~OM();

private:
	Ui::OMClass ui;
	RelayControl myRC;
	MyThread thread;

	int n_zaoyanWZ;
	int n_nipaoWZ;
	int n_tongqianWZ;
	int n_tongyangWZ;
	int n_errLength;
	int n_WFtime;

	QTcpSocket *tcpsocket;//通信套接字
	//日志文件指针
	Alog *mylog;
	//配置文件指针
	CMyINI *p;
	string path;
	QString myIP;
	QString myPort;
	//关闭程序
	int n_isclose;
	//相机个数
	int CameraNum;
	int m_nOnlineNumEdit;						//在线个数
	int m_nUseNumEdit;							//使用个数
	bool disabled;								//服务是否启用
	int nRet;									//相机函数的返回值
	MV_CC_DEVICE_INFO_LIST m_stDevList;         // 设备信息列表结构体变量，用来存储设备列表
												
	bool  m_bRetStatus;                         // 表示函数返回状态
	bool  m_bCreateDevice;                      // 是否创建设备

	bool  m_bShowImage;                         // 是否开始显示图像
	bool  m_bShowNYImage;                       // 是否开始显示泥炮凿岩图像
	bool  m_bShowTQImage;                       // 是否开始显示捅钎图像
	int   m_nTriggerMode;                       // 触发模式
	int   m_nTriggerSource;                     // 触发源

	int   n_once;
	QTimer *frameRatetimer;
	QTimer *WFtimer;

	Status OpenDevice(void);
	void initDevice();
	Status SetTriggerMode(void);
	Status SetExposureTime(void);
	Status SetGain(void);
	// 开始采集
	Status startGrabbing(void);
	Status StopGrabbing(void);
	Status CloseDevice(void);                       // 关闭设备
	Status DestroyDevice(void);                     // 销毁设备
	void QBAcrc16(QByteArray &ptr, unsigned int len, unsigned char CRC[2]);
	vector <QByteArray> myArray;
	QTimer *myTimer;

	volatile float dzc_WZ;//电子尺位置
	float hzl_WZ;		  //后坐力大小
	bool m_bOpencvFlag;
public:
	CMyCamera*   m_pcMyCamera[MAX_DEVICE_NUM];      // CMyCamera封装了常用接口
	bool  m_bOpenDevice;                            // 是否打开
	bool  m_bStartGrabbing;                         // 是否开始抓图
	MV_CC_DEVICE_INFO m_stDevInfo[4];
	int n_showImageNum1;
	int n_showImageNum2;
	int n_showImageNum3;
	int n_showImageNum4;

	QString sz_camera1;
	QString sz_camera2;
	QString sz_camera3;
	QString sz_camera4;
	QString cameraNY;
	QString cameraTQ;
	double d_gain1;
	double d_gain2;
	double d_gain3;
	double d_gain4;
	double d_exposure1;
	double d_exposure2;
	double d_exposure3;
	double d_exposure4;
	int n_realFrame1;
	int n_realFrame2;
	int n_realFrame3;
	int n_realFrame4;

	QString sz_camera1Local;
	QString sz_camera2Local;
	QString sz_camera3Local;
	QString sz_camera4Local;
	int   n_FrameCount[4];
	QImage *qImage1;
	QImage *qImage2;
	QImage *qImage3;
	QImage *qImage4;
	HI_VEDIO_INFO m_sCamInfo[MAXCAM];
private slots:
	void showimage(QByteArray array);
	void contralB(QByteArray array);
	void contralC();
	void ReadNetData();
	void ReadNetError(QAbstractSocket::SocketError);
	void showmyRC();

	void showimage1(QImage *qImage, unsigned int FrameCount, unsigned int LostFrameCout);
	void showimage2(QImage *qImage, unsigned int FrameCount, unsigned int LostFrameCout);
	void OnBnClearTextBrower();
	void setFrameRates();//设置帧率
	void WFSport();
	void WFStart();
	void WFStop();
	void Delay_MSec(unsigned int msec);
	void startDetect();	//相机连接采图
	void stopDetect();

	//继电器操作
	void Relay1Pressed();
	void Relay1Released();
	void Relay2Pressed();
	void Relay2Released();
	void Relay3Pressed();
	void Relay3Released();
	void Relay4Pressed();
	void Relay4Released();
	void Relay5Pressed();
	void Relay5Released();
	void Relay6Pressed();
	void Relay6Released();
	void Relay7Pressed();
	void Relay7Released();
	void Relay8Pressed();
	void Relay8Released();
	void Relay9Pressed();
	void Relay9Released();
	void Relay10Pressed();
	void Relay10Released();
	void Relay11Pressed();
	void Relay11Released();
	void Relay12Pressed();
	void Relay12Released();
	void Relay13Pressed();
	void Relay13Released();
	void Relay14Pressed();
	void Relay14Released();
	void Relay15Pressed();
	void Relay15Released();
	void Relay16Pressed();
	void Relay16Released();
	void Relay17Pressed();
	void Relay17Released();
	void Relay18Pressed();
	void Relay18Released();
	void Relay19Pressed();
	void Relay19Released();
	void Relay20Pressed();
	void Relay20Released();
	void Relay21Pressed();
	void Relay21Released();
	void Relay22Pressed();
	void Relay22Released();
	void Relay23Pressed();
	void Relay23Released();
	void Relay24Pressed();
	void Relay24Released();
	void Relay25Pressed();
	void Relay25Released();
	void Relay26Pressed();
	void Relay26Released();
	void Relay27Pressed();
	void Relay27Released();
	void Relay28Pressed();
	void Relay28Released();
	void Relay29Pressed();
	void Relay29Released();
	void Relay30Pressed();
	void Relay30Released();
	void Relay31Pressed();
	void Relay31Released();
	void Relay32Pressed();
	void Relay32Released();

	//相机显示切换
	void OnOpencvStart();
	void OnOpencvEnd();

	void getChanged(int i);

signals:
	void sndimage1(QImage *qImage, unsigned int FrameCount, unsigned int LostFrameCout);
	void sndimage2(QImage *qImage, unsigned int FrameCount, unsigned int LostFrameCout);
	void sndfloat(float temp, int x);
	void snddata(QByteArray array);
protected:
	void paintEvent(QPaintEvent * event);

private slots:
	//开孔
	void OpenPore();  //开孔准备
	void StartHole(); //启动开孔
	void StopHole();  //停止开孔

	//捅钎
	void DropSteel(); //落钎
	void ClipSteel(); //夹紧
	void StartSteel();//启动捅钎
	void StopSteel(); //停止捅钎

	//堵泥
	void BlockMud();  //堵泥开始
	void StopMud();   //停止堵泥

private:
	void ReadIni();    //读取配置文件

private slots:
	void OnStopMove();		//整车定时移动到时处理函数
	void OnTimeOver();		//定时到时操作:打泥定时,开始打孔定时
	void OnDoZaoYan();		//凿岩定时器处理函数
	void OnDoTongQian();	//捅钎整体操作定时器处理函数
	void OnDoExtendQian();	//伸钎
	void OnDoShinkQian();	//收钎
	void OnDoClampAndLoose();//夹轨与松轨
private:
	QTimer* m_moveTimer;	//整车移动定时器,整车前进与后退
	QTimer* m_mainOpera;	//开始打孔与开始堵泥用定时器
	QTimer* m_zaoYanTimer;	//凿岩用定时器,凿岩前进与凿岩后退
	QTimer* m_tongQianTimer;//捅钎整体操作用定时器
	QTimer* m_extendTimer;	//伸钎
	QTimer* m_shinkTimer;	//收钎
	QTimer* m_clampAndLooseTimer;//夹轨与松轨
	
	bool m_stopTongQian;//停止捅钎

	int m_openPorePos;//开孔时水平位置
	int m_duNiPos;	  //堵泥时水平位置
	int m_tongQianPos;//捅钎时水平位置
	int m_niPaoPower; //堵泥时泥泡后座力基准
	int m_times;	  //收钎次数

	TongQianAct m_tongQian;
	ZaoYan m_zaoYan;
	Machine m_machine;
};
