#pragma once
#include <QThread>
#include <Qtimer.h>

class MyThread : public QThread
{
	Q_OBJECT
public:
	explicit MyThread(QObject *parent = 0);
	void stop();

protected:
	void run();

private:
	volatile bool stopped;
	volatile bool is_busy;
	QTimer *myTimer;

signals:
	void sndimage(QImage *qImage, unsigned int FrameCount, unsigned int LostFrameCout);

private slots:
	void setBusy(bool busy);
	void myTimerOut();
};
