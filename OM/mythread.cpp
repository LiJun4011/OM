#include "mythread.h"
#include <QDebug>
#include "opencv2/imgcodecs.hpp"
#include <opencv2/highgui.hpp>
#include "opencv2/core/types_c.h"
#include <opencv2/opencv.hpp>
#include <opencv2\imgproc\types_c.h>  
#include <opencv2/core.hpp>//opencv410
#include <opencv2/imgproc.hpp>
#include <qimage.h>
#include <qpixmap.h>
#include <qmutex.h>
#include <qtimer.h>

using namespace cv;

extern QMutex mutex1;
bool is_busy;

//白光相机
#define STREAM_URL11 "rtsp://192.168.1.88/12"   //主码流

MyThread::MyThread(QObject *parent) :
	QThread(parent)
{
	stopped = false;
	//myTimer->start();
}

void MyThread::run()
{
	VideoCapture cap(STREAM_URL11);
	cap.set(CAP_PROP_FOURCC, VideoWriter::fourcc('M', 'J', 'P', 'G'));
	if (!cap.isOpened())
	{
		//ui.textBrowser->append("Open Failed ...\n");
		return;
	}
	//ui.textBrowser->append("Open Successed ...\n");
	stopped = false;
	is_busy = false;
	Mat frame;
	myTimer = new QTimer(this);
	connect(myTimer, SIGNAL(timeout()), this, SLOT(myTimerOut()));
	//myTimer->setInterval(30);
	while (!stopped)
	{
		cap >> frame;
		if (frame.empty() || stopped)
			break;
		if (is_busy == false)
		{
			is_busy = true;
			myTimer->start(30);
			mutex1.lock();
			cvtColor(frame, frame, CV_BGR2RGB);
			QImage img = QImage((const unsigned char*)(frame.data), frame.cols, frame.rows, QImage::Format_RGB888);
			emit sndimage(&img, 0, 0);//发送图像，帧数和丢帧数，用于界面显示
			mutex1.unlock();
			//waitKey(10);
		}
	}
	cap.release();
	stopped = false;
}

void MyThread::stop()
{
	stopped = true;
}

void MyThread::setBusy(bool busy)
{
	is_busy = busy;
}

void MyThread::myTimerOut()
{
	myTimer->stop();
	is_busy = false;
}
