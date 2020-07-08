#pragma once

constexpr auto DropSteelTime = 4 * 1000;	//掉钎时长
constexpr auto ClampSteelTime = 2 * 1000;	//马达夹钎时长
constexpr auto ExtendSteelTime = 3 * 1000;	//伸钎时长，单位秒;
constexpr auto ShinkSteelTime = 2 * 1000;	//普通收钎时长;
constexpr auto ShinkToZeroTime = 5 * 1000;	//收钎归零时长;
constexpr auto ReturnZeroTime = 3;			//捅钎归位次数;

constexpr auto MathineForwardTime = 2 * 1000;//整车前进时长;
constexpr auto MachineBackTime = 2 * 1000;	 //整车回退时长;

constexpr auto ZaoYanBackTime = 2 * 1000;	//凿岩后退
constexpr auto ZaoYanRotate = 5 * 1000;		//凿岩旋转时长;

constexpr auto LooseClampRail = 4 * 1000;	//夹轨与松轨指令执行时长;

constexpr auto PosAccuracy = 10;			//开孔、捅钎、堵泥水平移动到位精度

constexpr auto PressMudTime = 5 * 1000;		//挤泥时长


enum  HorizontalMove
{
	LeftMove,		//整车左移
	RightMove,		//整车右移
	Default			//未知
};

enum MachineMove
{
	Forward,		//整车前进
	Back,			//整车后退
	Unknow			//未知
};

enum StructureType
{
	KaiKong,		//开孔
	TongQian,		//捅钎
	DuNi,			//堵泥
	StructureUnknow //未知
};

enum TongQianAct
{
	DiaoQian,		//掉钎
	Clamp,			//夹紧
	ShenQian,		//伸钎
	ShouQian,		//收钎
	TongQianOper,	//捅钎
	ShinkSteelReturn,//收钎归零
	TongQianUnknow
};

enum ZaoYan
{
	ZaoYanForward,		//凿岩前进
	ZaoYanBack,			//凿岩后退
	ZaoYanUnknow		//未知
};

enum RailOper
{
	ClampRail,		//夹轨
	LooseRail,		//松轨
	RailOperUnknow  //未知
};

struct Machine
{
	RailOper m_railOper;	  //
	HorizontalMove m_horiMove;//标志水平移动的方向
	StructureType m_struType; //标志所移动的结构类型
	MachineMove m_machineMove;//标志整车前进或后退
};
