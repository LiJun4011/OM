#pragma once

#include "ui_RelayControl.h"
#include <vector>

using namespace std;

class RelayControl : public QDialog
{
	Q_OBJECT

public:
	RelayControl();

private:
	Ui::RelayControl ui;
	void QBAcrc16(QByteArray &ptr, unsigned int len, unsigned char CRC[2]);
	vector<float> mydata1;
	vector<float> mydata2;
	vector<float> mydata3;
	int sndnum;

private slots:
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
	void Delay_MSec(unsigned int msec);
	void getNiPao();
	void getNiPao2();
	void setZero();
	void getTongQian();
	void getdata(float temp, int x);
	void onResetCameraClicked();
signals:
	void snddata(QByteArray array);
	void sndfloat(float temp, int x);

protected:
	void timerEvent(QTimerEvent *event) Q_DECL_OVERRIDE;
	void paintEvent(QPaintEvent * event);
};
