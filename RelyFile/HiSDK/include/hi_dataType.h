
#ifndef __HI_DATATYPE_H__
#define __HI_DATATYPE_H__

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */

	
/*----------------------------------------------*
 * 基本数据类型定义，应用层和内核代码均使用     *
 *----------------------------------------------*/

typedef unsigned char           HI_U8;
typedef unsigned char           HI_UCHAR;
typedef unsigned short          HI_U16;
typedef unsigned int            HI_U32;
typedef unsigned long           HI_ULONG;
typedef unsigned __int64        HI_U64;

typedef char                    HI_S8;
typedef short                   HI_S16;
typedef int                     HI_S32;
typedef long                    HI_LONG;
typedef long                    HI_HANDLE;
typedef __int64                 HI_S64;

typedef char                    HI_CHAR;
typedef char*                   HI_PCHAR;

typedef float                   HI_FLOAT;
typedef double                  HI_DOUBLE;
typedef void                    HI_VOID;

typedef HI_U64                  HI_PTS_TIME;


typedef unsigned long           HI_SIZE_T;
typedef unsigned long           HI_LENGTH_T;

typedef enum {
    HI_FALSE    = 0,
    HI_TRUE     = 1,
} HI_BOOL;

#define IN
#define OUT

#ifndef NULL
#define NULL                0L
#endif
#define HI_NULL             0L
#define HI_NULL_PTR         0L

#define HI_SUCCESS          0
#define HI_FAILURE          (-1)

#define SAFE_DELETE(p)  { if((p) != NULL) { delete (p);     (p) = NULL; } }
#define SAFE_DELETEA(p) { if((p) != NULL) { delete[] (p);   (p) = NULL; } }
#define SAFE_RELEASE(p) { if((p) != NULL) { (p)->Release(); (p) = NULL; } }
#define SAFE_FREE(p)    { if((p) != NULL) { free(p);        (p) = NULL; } }

#define HI_ERR_SDK_HANDLE			0x30001

#define HI_ERR_PLAYER_NULLPTR		0x30002
#define HI_ERR_DRAW_NULLPTR			0x30003
#define HI_ERR_CMD_NULLPTR			0x30004
#define HI_ERR_CMD_INVALID_ARG		0x30005

#define HI_ERR_CMD_DISCONNECT		0x30006

#define HI_ERR_PLAYER_WNDHWND		0x30008
#define HI_ERR_STATE_IS_PLAYING		0x30009
#define HI_ERR_STATE_IS_STOP		0x30010
#define HI_ERR_PLAYER_STOP			0x30011
#define HI_ERR_PLAYER_DEC			0x30012
#define HI_ERR_PLAYER_SNAP			0x30013
#define HI_ERR_PLAYER_PLAY			0x30014
#define HI_ERR_PLAYER_STOP_TALK		0x30015
#define HI_ERR_PLAYER_START_TALK	0x30016
#define HI_ERR_PLAYER_PAUSE			0x30017
#define HI_ERR_PLAYER_SETRATE		0x30018
#define HI_ERR_PLAYER_ONEBYONE		0x30019
#define HI_ERR_PLAYER_SETPOS		0x30020
#define HI_ERR_PLAYER_GETPOS		0x30021
#define HI_ERR_PLAYER_SETMUTE		0x30022
#define HI_ERR_PLAYER_GETMUTE		0x30023
#define HI_ERR_PLAYER_SETVOLUME		0x30024
#define HI_ERR_PLAYER_GETVOLUME		0x30025
#define HI_ERR_PLAYER_MEDIA_ATTR	0x30026

#define HI_ERR_CALLBACK_DRAW		0x32001
#define HI_ERR_CALLBACK_STATE		0x32002
#define HI_ERR_CALLBACK_PLAYER		0x32003

#define HI_ERR_REC_RECORDING		0x30050
#define HI_ERR_REC_START_FAIL		0x30051
#define HI_ERR_REC_STOP_FAIL		0x30052

#define HI_ERR_TALK_STARTING		0x30081
#define HI_ERR_TALK_NOSTARTING		0x30082
#define HI_ERR_TALK_START_FAIL		0x30083
#define HI_ERR_TALK_SEND_FAIL		0x30084
#define HI_ERR_TALK_STOP_FAIL		0x30085

#define HI_ERR_PLAYER_OPENFILE		0x30100
#define HI_ERR_PLAYER_CLOSEFILE		0x30100

#define HI_ERR_NET_PLAY				0x31001
#define HI_ERR_NET_STOP				0x31002

#define HI_ERR_ATTR_NOSUPPORT		0x31003

/* 字符串的长度 */
#define HI_STR_LEN 64

#define MAX_MD_NUMBER               4

//pcDvsDraw
#define DRAW_TEXT_HEIGHT            15
#define MAX_NAME_LEN                32
#define MAX_DRAW_NUM                4
#define MAX_EVENT_NUM               6
#define MAX_PEN_NUM                 7
#define MACRO_MIN_SIZE              32

/* 设备 通道号，目前仅支持一个通道*/
#define HI_CHANNEL_1    1
//#define HI_CHANNEL_2    2
//#define HI_CHANNEL_3    3
//#define HI_CHANNEL_4    4

#define HI_STREAM_1    0
#define HI_STREAM_2    1
#define HI_STREAM_3    2

/*  连接网络连接模式，目前仅支持TCP*/
#define HI_STREAM_MODE_TCP  0
//#define HI_STREAM_MODE_UDP  1

/*流数据类型，目前不支持心跳数据 */
/*次码流不支持报警数据和心跳数据 */
#define HI_STREAM_VIDEO_ONLY	0x01
#define HI_STREAM_AUDIO_ONLY	0x02
#define HI_STREAM_VIDEO_AUDIO	0x03
/*目前不支持仅传输报警数据和心跳数据 */
//#define HI_STREAM_DATA_ONLY	0x04
#define HI_STREAM_VIDEO_DATA	0x05
#define HI_STREAM_AUDIO_DATA	0x06
#define HI_STREAM_ALL			0x07

/* 开始流传输 */
typedef struct 
{
	HI_U32 u32Channel;     /*通道号 */
	HI_BOOL blFlag;        /*为真连接主码流，假连接次码流*/
	HI_U32 u32Mode;        /*网络连接模式*/
	HI_U8 u8Type;          /*流数据类型，视频，音频，其他数据*/
} HI_S_STREAM_INFO;

typedef struct 
{
	HI_U32 u32Channel;      /*通道号 */
	HI_U32 u32Stream;            /*0:连接主码流，1:连接次码流 2:第三码流*/
	HI_U32 u32Mode;         /*网络连接模式*/
    HI_U8 u8Type;         /*流数据类型，视频，音频，其他数据*/
} HI_S_STREAM_INFO_EXT;

#define HI_MOTION_DETECTION	0
#define HI_INPUT_ALARM	 	1
#define HI_KEEP_ALIVE		2
#define HI_AUDIO_ALARM		4

/*移动检测 */
#define HI_MOTION_AREA_MAX	4		//移动检测区域数
#define HI_MOTION_AREA_1    1		
#define HI_MOTION_AREA_2    2
#define HI_MOTION_AREA_3    3
#define HI_MOTION_AREA_4    4
typedef struct 
{
	HI_U32 u32Area;
	HI_U32 u32X;
	HI_U32 u32Y;
	HI_U32 u32Width;
	HI_U32 u32Height;
} HI_S_ALARM_MD;

/* 设备参数区 */
/* Product and Vendor */
typedef struct HI_ProductVendor
{
	HI_CHAR sProduct[32];		//product ID
	HI_CHAR	sVendor[32];		//vendor ID	
}HI_S_ProductVendor;

/* Image display mode */
#define HI_SCENE_AUTO		0
#define HI_SCENE_INDOOR		1
#define HI_SCENE_OUTDOOR	2
typedef struct HI_Display_Ext
{
	HI_BOOL blFlip;
	HI_BOOL blMirror;
	HI_S32 s32Scene;
} HI_S_Display_Ext;

/* Image normal */
typedef struct HI_Display
{
	HI_U32 u32Brightness;
	HI_U32 u32Saturation;
	HI_U32 u32Contrast;
	HI_U32 u32Hue;
} HI_S_Display;

typedef struct HI_Sharpness
{
	HI_U32 u32Sharpness;   /*  锐度  */
} HI_S_Sharpness;

typedef struct HI_Color
{
	HI_U32 u32Brightness;   /*  亮度  */
	HI_U32 u32Saturation;   /* 饱和度  */
	HI_U32 u32Contrast;     /*  对比度  */
	HI_U32 u32Hue;          /*  色度  */
	HI_U32 u32Shutter;      /* 快门 */
	HI_U32 u32Dnt;			/* 灵敏度 */
	HI_U32 u32Lumivalue;	/* 低噪度 */
} HI_S_Color;

/* Infrared turn on/off */
#define HI_INFRARED_AUTO	0
#define HI_INFRARED_ON		1
#define HI_INFRARED_OFF		2
typedef struct HI_Infrared
{
	HI_S32 s32Infrared;
} HI_S_Infrared;

/* Video compression paramter */
typedef struct HI_Video
{
	HI_U32 u32Channel;
    HI_BOOL blFlag;
	HI_U32 u32Bitrate;		//Kb
	HI_U32 u32Frame;
	HI_U32 u32Iframe;		//1-300
	HI_BOOL blCbr;			
	HI_U32 u32ImgQuality;	//1-6
} HI_S_Video;

typedef struct HI_Video_Ext
{
	HI_U32 u32Channel;      /* 通道 */
	HI_U32 u32Stream;          /* 主、次码流  */
	HI_U32 u32Bitrate;	/* 码流 */
	HI_U32 u32Frame;    /* 帧率 */
	HI_U32 u32Iframe;	/* 主帧间隔1-300 */
	HI_BOOL blCbr;	    /* 码流模式、HI_TRUE为固定码流，HI_FALSE为可变码流 */		
	HI_U32 u32ImgQuality;	/* 编码质量1-6 */
	HI_U32 u32Width;
	HI_U32 u32Height;
} HI_S_Video_Ext;

/* Image resolution */
#define HI_RESOLUTION_VGA		0
#define HI_RESOLUTION_QVGA		1
#define HI_RESOLUTION_QQVGA		2
#define HI_RESOLUTION_D1		3
#define HI_RESOLUTION_CIF		4
#define HI_RESOLUTION_QCIF		5
#define HI_RESOLUTION_720P		6
#define HI_RESOLUTION_Q720		7
#define HI_RESOLUTION_QQ720		8
#define HI_RESOLUTION_UXGA		9
#define HI_RESOLUTION_960H		10
#define HI_RESOLUTION_Q960H		11
#define HI_RESOLUTION_QQ960H	12
#define HI_RESOLUTION_1080P		13
#define HI_RESOLUTION_960P		14
#define HI_RESOLUTION_1536P		15
//20170821 3516D 4百万
#define HI_RESOLUTION_1440P			16

//20180913 3百万,5百万
#define HI_RESOLUTION_800_448P			17
#define HI_RESOLUTION_800_600P			18
#define HI_RESOLUTION_2304_1296P		19
#define HI_RESOLUTION_2560_1920P		20

typedef struct HI_Resolution
{
	HI_U32 u32Channel;
    HI_BOOL blFlag;
	HI_U32 u32Resolution;
}HI_S_Resolution;

typedef struct HI_Resolution_Ext
{
	HI_U32 u32Channel;
    HI_U32 u32Stream;
	HI_U32 u32Resolution;
}HI_S_Resolution_Ext;

/* Video input mode, PAL or NTSC  */
typedef enum HI_Frequency
{
	FREQ_50HZ_PAL = 50,
	FREQ_60HZ_NTSC = 60
} HI_E_Frequency;

/* Audio DEV WARNING Enable it after your restart IP Cam */
#define HI_AUDIO_TYPE_G711		0
#define HI_AUDIO_TYPE_G726		1
#define HI_AUDIO_TYPE_AMR		2
typedef struct HI_Audio
{
	HI_U32 u32Channel;
	HI_BOOL blFlag;
	HI_BOOL blEnable;
	HI_U32 u32Type;
} HI_S_Audio;

typedef struct HI_Audio_Ext
{
	HI_U32 u32Channel;              /* 通道 */
	HI_U32 u32Stream;                      /*0为主码流，1为次码流 2为第三码流*/
	HI_BOOL blEnable;               /* HI_TRUE:开启音频，HI_FALSE:关闭音频  */
	HI_U32 u32Type;
} HI_S_Audio_Ext;

typedef enum HI_AudioInput
{
	AUDIO_INPUT_MIC = 100,
	AUDIO_INPUT_LINE = 10
} HI_E_AudioInput;

typedef struct HI_AudioVolume
{
	HI_U32 u32AudioVolume;
} HI_S_AudioVolume;

/* OSD */
typedef struct HI_OSD
{
	HI_BOOL blEnTime;
	HI_BOOL blEnName;
	HI_CHAR sName[64];
} HI_S_OSD;

#define HI_OSD_TIME 0
#define HI_OSD_NAME 1
typedef struct HI_OSD_EX
{
	HI_U32 u32Area;		/*区域, HI_OSD_TIME--时间, HI_OSD_NAME--名称*/
	HI_U32 u32X;
	HI_U32 u32Y;
} HI_S_OSD_EX;

typedef struct HI_MD_PARAM
{
	HI_U32 u32Channel;
	HI_U32 u32Area;
	HI_BOOL blEnable;
    HI_U32 u32Sensitivity;  /* 0~75 */
	HI_U32 u32X;
	HI_U32 u32Y;
	HI_U32 u32Width;
	HI_U32 u32Height;    
}HI_S_MD_PARAM;

#define HI_NET_DEV_COVER_AREA_MAX  4
#define HI_NET_DEV_COVER_AREA_1    0
#define HI_NET_DEV_COVER_AREA_2    1
#define HI_NET_DEV_COVER_AREA_3    2
#define HI_NET_DEV_COVER_AREA_4    3

typedef struct HI_COVER_PARAM
{
	HI_U32 u32Area;            /* 遮挡区域 */
	HI_BOOL bShow;
	HI_U32 u32X;
	HI_U32 u32Y;
	HI_U32 u32Width;
	HI_U32 u32Height;    
	HI_U32 u32Color;
} HI_S_COVER_PARAM;

/* 云台控制数据类型*/
#define HI_PTZ_PRO_PELCOD	0
#define HI_PTZ_PRO_PELCOP	1
#define HI_PTZ_B110			110
#define HI_PTZ_B300			300
#define HI_PTZ_B1200		1200
#define HI_PTZ_B2400		2400
#define HI_PTZ_B4800		4800
#define HI_PTZ_B9600		9600
#define HI_PTZ_B19200		19200
#define HI_PTZ_B38400		38400
#define HI_PTZ_B57600		57600
#define HI_PTZ_STOP_1		1
#define HI_PTZ_STOP_2		2
#define HI_PTZ_DATA_5		5
#define HI_PTZ_DATA_6		6
#define HI_PTZ_DATA_7		7
#define HI_PTZ_DATA_8		8
#define HI_PTZ_PARITY_NONE	0
#define HI_PTZ_PARITY_ODD	1
#define HI_PTZ_PARITY_EVEN	2
typedef struct HI_PTZ
{
	HI_U32 u32Protocol;
	HI_U32 u32Address;
	HI_U32 u32Baud;
	HI_U32 u32DataBit;
	HI_U32 u32StopBit;
	HI_U32 u32Parity;
}HI_S_PTZ;

typedef struct HI_HTTPPORT
{
	HI_U32 u32HttpPort;
} HI_S_HTTPPORT;

typedef struct HI_ATTR_EXT
{
	HI_U32  u32Enable;
	HI_U32  u32Flag;
}HI_S_ATTR_EXT;

typedef struct HI_RELAYCTRL //是否开启继电器
{
	HI_BOOL bEnable;
} HI_S_RelayCtrl;

//2015/07/14
typedef struct HI_EXTALARM//外置报警
{
	HI_BOOL bEnable;
}HI_S_ExtAlarm;

//2016/08/18
typedef struct HI_PIRALARM
{
	HI_BOOL bEnable;	//是否启用PIR报警：0：关闭 1：启用
	HI_U32 u32Flag;		//PIR报警模式：0：常闭 1：常开
}HI_S_PirAlarm;

/* 参数定义 */
#define HI_GET_PRODUCT_VENDOR			0x1000
#define HI_CMD_DISPLAY					0x1001
#define HI_CMD_DISPLAY_EXT				0x1002
#define HI_CMD_INFRARED					0x1003
#define HI_CMD_VIDEO_PARAM				0x1004
#define HI_CMD_OSD_PARAM				0x1005
#define HI_CMD_AUDIO_PARAM				0x1006
#define HI_CMD_AUDIO_INPUT				0x1007
#define HI_CMD_RESOLUTION				0x1008
#define HI_CMD_FREQUENCY				0x1009
#define HI_CMD_PTZ_PARAM				0x1010
#define HI_CMD_MD_PARAM					0x1011
#define HI_CMD_NET_INFO					0x1012
#define HI_CMD_HTTP_PORT				0x1013
#define HI_CMD_DEVICE_INFO				0x1014
#define HI_CMD_PRODUCTID				0x1015
#define HI_CMD_USERNUM					0x1016
#define HI_CMD_SERVER_TIME				0x1017
#define HI_CMD_REBOOT					0x1018
#define HI_CMD_RESET					0x1019
#define HI_CMD_COVER_PARAM				0x1020
#define HI_CMD_OSDEX_PARAM				0x1021
#define HI_CMD_NET_EXT					0x1022
#define HI_CMD_SNAP_TIMER				0x1023
#define HI_CMD_EMAIL_PARAM				0x1024
#define HI_CMD_FTP_PARAM				0x1025
#define HI_CMD_ATTR_EXT					0x1026
#define HI_CMD_MD_TIMER					0x1027
#define HI_CMD_PLATFORM					0x1028
#define HI_CMD_DNS_PARAM				0x1029
#define HI_CMD_WIFI_PARAM				0x1030
#define HI_CMD_WIFI_SEARCH				0x1031
#define HI_CMD_VIDEO_PARAMEX			0x1032
#define HI_CMD_USER						0x1033
#define HI_CMD_SYSTEM_INFO				0x1034
#define HI_CMD_WIFI_CHECK				0x1035
#define HI_CMD_SERVER_TIME_EX			0x1036
#define HI_CMD_NET_STATE				0x1037
#define HI_CMD_NTP						0x1038
#define HI_CMD_INTERNET_IP				0x1039
#define HI_CMD_COLOR					0x1040
#define HI_CMD_SYS						0x1041
#define HI_CMD_DEVID					0x1042
#define HI_CMD_IMAGE_DEFAULT			0x1043
#define HI_CMD_OUR_DNS					0x1044
#define HI_CMD_RTSP_INFO				0x1045
#define HI_CMD_MD_ALARM					0x1046
#define HI_CMD_VIDEO_PARAM_EXT			0x1047
#define HI_CMD_AUDIO_PARAM_EXT			0x1048
#define HI_CMD_RESOLUTION_EXT			0x1049

#define HI_NVR_CMD_NET_EXT					0x1050
#define HI_NVR_CMD_RTSP_INFO				0x1051
#define HI_NVR_CMD_USER						0x1052
#define HI_NVR_CMD_CHANNEL_INFO				0x1053
#define HI_NVR_CMD_CHANNEL_STATE			0x1054
#define HI_NVR_CMD_SEARCH					0x1055
#define HI_NVR_CMD_RECORD_INFO				0x1056
#define HI_NVR_CMD_RECORD_SYS				0x1057
#define HI_NVR_CMD_TIME						0x1058
#define HI_NVR_CMD_RESET					0x1059
#define HI_NVR_CMD_REBOOT					0x1060
#define HI_NVR_CMD_RECORD_STATE				0x1061
#define HI_NVR_CMD_DISK_INFO				0x1062
#define HI_NVR_CMD_DISK_FORMAT				0x1063
#define HI_NVR_CMD_RECORD_STATE_EX			0x1064
#define HI_NET_NVR_CMD_DISPLAY_CFG				0x1065

#define HI_CMD_AUDIO_VOLUME_IN				0x1070
#define HI_CMD_AUDIO_VOLUME_OUT				0x1071
#define HI_CMD_QUANTUM_TIME					0x1072
#define HI_NET_DEV_CMD_UID				    0x1083  
//2015/03/07
#define HI_CMD_RELAYCTRL					0x1084	//继电器控制
//2015/06/17
#define HI_CMD_EXT_ALARM					0x1085
//2016/08/18
#define HI_CMD_PIR_ALARM					0x1086	//PIR 报警
//2014/04/14
#define HI_NET_DEV_CMD_COVER_ATTR			0x1095


#define HI_CMD_BUT							0x1099

/* 云台控制定义 */
#define HI_CTRL_PTZ_STOP		0x3000
#define HI_CTRL_PTZ_UP			0x3001
#define HI_CTRL_PTZ_DOWN		0x3002
#define HI_CTRL_PTZ_LEFT		0x3003
#define HI_CTRL_PTZ_RIGHT		0x3004
#define HI_CTRL_PTZ_ZOOMIN		0x3005
#define HI_CTRL_PTZ_ZOOMOUT		0x3006
#define HI_CTRL_PTZ_FOCUSIN			0x3007
#define HI_CTRL_PTZ_FOCUSOUT		0x3008
#define HI_CTRL_PTZ_APERTUREIN		0x3009
#define HI_CTRL_PTZ_APERTUREOUT		0x3010
#define HI_CTRL_PTZ_UPLEFT      0x3011
#define HI_CTRL_PTZ_UPRIGHT     0x3012
#define HI_CTRL_PTZ_DOWNLEFT    0x3013
#define HI_CTRL_PTZ_DOWNRIGHT   0x3014

#define HI_CTRL_PTZ_GOTO_PRESET	0x3015
#define HI_CTRL_PTZ_SET_PRESET	0x3016
#define HI_CTRL_PTZ_CLE_PRESET	0x3017

#define HI_CTRL_PTZ_LIGHT_ON	0x3021
#define HI_CTRL_PTZ_LIGHT_OFF	0x3022
#define HI_CTRL_PTZ_WIPER_ON	0x3023
#define HI_CTRL_PTZ_WIPER_OFF	0x3024
#define HI_CTRL_PTZ_AUTO_ON		0x3025
#define HI_CTRL_PTZ_AUTO_OFF	0x3026
#define HI_CTRL_PTZ_HOME		0x3027
#define HI_CTRL_PTZ_CRUISE_V	0x3028
#define HI_CTRL_PTZ_CRUISE_H	0x3029

#define HI_CTRL_PTZ_GSPEED		0x3050
#define HI_CTRL_PTZ_SSPEED		0x3051

#define HI_CTRL_PTZ_SPEED_MAX	0x3F
#define HI_CTRL_PTZ_SPEED_MIN	0x00
#define HI_CTRL_PTZ_PRESET_MAX	255
#define HI_CTRL_PTZ_PRESET_MIN	0
#define HI_CTRL_PTZ_FT_BUF_LEN	64

#define HI_SNAP_BUF_LEN_MIN		1024


typedef struct hiDRAW_INFO_S
{
	HI_CHAR szDrawName[MAX_NAME_LEN];       /*draw name*/
	RECT rcDrawPos;                         /*position of draw*/
	HI_S32 s32EnableValue;                  /*value of enable*/ //1表示可绘制
	HI_S32 s32FlashType;                    /*flash type*/
	HI_S32 s32FlashRate;                    /*flash rate*/
	HI_S32 s32FlashDuration;                /*flash duration*///刷新持续时间
	HI_S32 s32DrawFlag;                     /*graph type*/  //值 为  GRAPH_TEXT,GRAPH_PIC
	HI_S32 u32IDBitmapRes;                  /*bitmap ID*/
	HI_VOID* pDrawContant;                  /*contant of draw*/  //指向DRAW_TEXT_S结构体
}DRAW_INFO_S;

typedef enum hiFILE_FORMAT_E
{
	FILE_FORMAT_YUV = 0,              /*YUV*/
    FILE_FORMAT_NUDE_STREAM,          /*stream*/
	FILE_FORMAT_ASF,                  /*ASF*/
	FILE_FORMAT_MP4,                  /*MP4*/
	FILE_FORMAT_AVI,                  /*AVI*/
	FILE_FORMAT_RAW,
	FILE_FORMAT_BUTT
} FILE_FORMAT_E;

typedef enum hiMEDIA_TYPE_E
{
	MEDIA_VIDEO_AUDIO = 0,            /*video and audio*/
	MEDIA_VIDEO,                      /*video*/
	MEDIA_AUDIO,                      /*audio*/
	MEDIA_ALARM,                      /*alarm*/
	MEDIA_SYSTERM,
	MEDIA_BUTT
} MEDIA_TYPE_E;

/*state of play*/
typedef enum hiPLAY_STATE_E
{
	PLAY_STATE_PAUSE = 0,             /*pause*/
	PLAY_STATE_PLAY,                  /*play with audio and video*/
	PLAY_STATE_AUDIO,                 /*play with audio*/
	PLAY_STATE_VIDEO,                 /*play with video*/
	PLAY_STATE_STOP,                  /*stop*/
	PLAY_STATE_BUTT
} PLAY_STATE_E;

/*state of record*/
typedef enum hiREC_STATE_E
{
	REC_STATE_RUN  = 0,               /*record*/
	REC_STATE_STOP,                   /*stop record*/
	REC_STATE_BUTT
} REC_STATE_E;


/*talk state enum*/
typedef enum hiTALK_STATE_E
{
	TALK_STATE_RUN = 0,               /*open talk*/
	TALK_STATE_STOP,                  /*close talk*/
	TALK_STATE_BUTT
} TALK_STATE_E;

typedef enum hiSTATE_ID_E
{
	STATE_ID_PLAY = 0,                /*state of live of playback*/
	STATE_ID_REC,                     /*state of record*/
	STATE_ID_TALK,                    /*state of talk*/

	// 服务器状态
	STATE_ID_SERVER_USERNUM,
	STATE_ID_BUTT                     /*reserve*/
} STATE_ID_E;


typedef enum hiPBCTRL_TYPE_E
{
	PB_CTRL_PLAY = 0,		//播放
	PB_CTRL_STOP,
	PB_CTRL_PAUSE,			//暂停
	PB_CTRL_RATE,			//速度
	PB_CTRL_FRAME,			//单帧
	PB_CTRL_SETPOS,			//设置播放位置
	PB_CTRL_GETPOS,			//获取播放位置
	PB_CTRL_MUTE,			//静音
	PB_CTRL_VOLUME,			//音量
	PB_CTRL_GETTIME
}PBCTRL_TYPE_E;

typedef enum hiAUDIO_MUTE_E
{
	AUDIO_MUTE_ON = 0,                /*mute on*/
	AUDIO_MUTE_OFF,                   /*mute off*/
	AUDIO_MUTE_BUTT
}AUDIO_MUTE_E;


/*definition of event type*/
typedef enum hiEVENT_TYPE_E
{
	EVENT_LIVE_STOP = 0,              /*state of live is stop*/
	EVENT_LIVE_PAUSE,                 /*state of live is pause*/
	EVENT_LIVE_PLAY,                  /*state of live is play*/
	
	EVENT_TALK_STOP,                  /*state of talk is stop*/
	EVENT_TALK_PLAY,                  /*state of talk is play*/
	EVENT_TALK_ABNORM,                /*abnormal, should reconnect*/
	
	EVENT_REC_STOP,                   /*state of record is stop*/
	EVENT_REC_PLAY,                   /*state of record is start*/
	EVENT_REC_SIZE,
	EVENT_REC_ABNORM,                 /*abnormal of record*/
	
	EVENT_PLAYBACK_READ,
	EVENT_PLAYBACK_PLAY,              /*state of playback is play*/
	EVENT_PLAYBACK_PAUSE,             /*state of playback is pause*/
	EVENT_PLAYBACK_STOP,              /*state of playback is stop*/
	
	EVENT_NET_CONNECTING,             /*connecting*/
	EVENT_NET_CONNECTED,              /*connected*/
	EVENT_NET_DISCONNECT,             /*disconnect*/
	EVENT_NET_ABNORMAL,
	EVENT_NET_RECONNECT,              /*net abnormal, send this event*/
	EVENT_NET_CONNECTFAIL,            /*net connect fail*/
	EVENT_NET_WRONGUSER,              /*invalid user info*/
	
	EVENT_HARD_ERR,
	EVENT_BUTT
} EVENT_TYPE_E;

typedef enum hiMD_TYPE_E
{
	DATA_MOTION_DETECTION = 0,
	DATA_INPUT_ALARM,
	DATA_KEEP_ALIVE,
	DATA_DEC_STATE,
	DATA_ALADIO_ALARM,
	DATA_PIR_ALARM,
	DATA_BUTT
}MD_TYPE_E;

/*audio type*/
typedef enum hiAUDIO_DIRECT_E
{
	AUDIO_OUT = 0,                    /*audio output*/
	AUDIO_IN,                         /*audio collect*/
	AUDIO_BUTT
} AUDIO_DIRECT_E;

//frame image info
typedef struct hiFRAME_INFO_S
{
	HI_U8* pY;
	HI_U8* pU;
	HI_U8* pV;
	long nWidth;
	long nHeight;
	long nType;     //data type:YUV420
	long nYPich;
	long nUVPich;
	HI_U64 u64Pts;
}
FRAME_INFO_S;

typedef struct hiYUV_INFO_S
{
    FRAME_INFO_S YUVInfo;
    HI_S32 nDataLen;
    HI_U8 *pData;
}HI_YUV_INFO_S;

typedef enum hiGRAPH_TYPE_E
{
	GRAPH_CIRCLE = 0x01,              /*draw circle*/
	GRAPH_RECTANGLE,                  /*draw rectangle*/
	GRAPH_LINE,                       /*draw line*/
	GRAPH_PIC,                        /*draw picture*/
	GRAPH_TEXT,                       /*draw text*/
	GRAPH_DEF,
	GRAPH_BUTT
} GRAPH_TYPE_E;


typedef enum hi_FLASHTYPE_E
{
	FLASH_WITH_RATE = 0x01,           /*event draw with rate*/
	FLASH_WITHOUT_RATE,               /*event draw withrate*/
	FLASH_WITH_DURATION,              /*event draw with time limit*/
	FLASH_WITHOUT_DURATION,           /*event draw withtime limit*/
	FLASH_BUTT
} FLASH_TYPE_E;


typedef enum hiSTATE_TYPE_E
{
	DRAW_STATE = 0x01,                /*common draw*/
	EVENT_STATE,                      /*event draw*/
	NO_DRAW_STATE,                    /*clear common draw data*/
	NO_EVENT_STATE,                   /*clear event draw data*/
	BUTTT_STATE
} STATE_TYPE_E;

typedef struct hiDRAW_GRAPH_S
{
	DWORD dwPenColor;                       /*color of draw pen*/
	DWORD dwBrushColor;                     /*fill color*/
	HI_U32 u32BrushStyle;                   /*fill stype*/
	HI_U32 u32Reserve;                      /*reserve*/
} DRAW_GRAPH_S;

typedef struct hiMD_ATTR_S
{
	HI_CHAR szMdName[MAX_NAME_LEN];         /*name of MD*/
	HI_U32 u32Number;                       /*number of MD*/
	RECT rcMdArea;                          /*size of MD*/
	HI_U32 u32Threshold;                    /*value of threshold*/
	HI_U32 u32SensitiValue;                 /*value of sensity*/
	HI_S32 s32EnableValue;                  /*value of enable*/
} MD_ATTR_S;

typedef enum hiSNAP_FILE_FORMT_E
{
	SNAP_JPEG = 0,                    /*JPET*/
	SNAP_BMP,                         /*BMP*/
	SNAP_BUTT
} SNAP_FILE_FORMAT_E;


typedef struct tagHI_SUPPORT
{
	HI_U32 u32Operation;  //操作属性，如夜视效果白平衡等等
	HI_U32 u32Reslution;  //主码流支持分辨率
	HI_U32 u32Reslution1;  //次码流支持分辨率
	HI_U32 u32FrameMax;    //最大帧数
	HI_U32 u32BitRateMin;  //主码流最小码率
	HI_U32 u32BitRateMax;  //主码流最大码率
	HI_U32 u32BitRateMin1;   //次码流最小码率
	HI_U32 u32BitRateMax1;   //次码流最大码率
	HI_U32 u32PtzContrl;
}HI_S_SUPPORT;


#define SUPPORTATTR_NIGHTVISION_SET_FLAG		(0x000000001<<1)
#define SUPPORTATTR_NIGHTVISION_GET_FLAG		(0x000000001<<2)
#define SUPPORTATTR_WHITEBALANCE_FLAG			(0x000000001<<3)
#define SUPPORTATTR_FLIP_FLAG					(0x000000001<<4)
#define SUPPORTATTR_MIRROR_FLAG					(0x000000001<<5)
#define SUPPORTATTR_BRIGHTNESS_FLAG				(0x000000001<<6)
#define SUPPORTATTR_SATURATION_FLAG				(0x000000001<<7)
#define SUPPORTATTR_CONTRAST_FLAG				(0x000000001<<8)
#define SUPPORTATTR_HUE_FLAG					(0x000000001<<9)
#define SUPPORTATTR_SUBSTREAM_FLAG				(0x000000001<<10)
#define SUPPORTATTR_POWERFREQ_FLAG				(0x000000001<<11)


#define SYSINFO_MAX_STRINGLENGTH (40)		// 系统信息长度
#define SYSINFO_MAX_VERLENGTH (64)

typedef struct tagHI_NETINFO
{   
	HI_CHAR aszServerIP[SYSINFO_MAX_STRINGLENGTH];       /*IP地址*/
	HI_CHAR aszNetMask[SYSINFO_MAX_STRINGLENGTH];        /*子网掩码*/
	HI_CHAR aszGateWay[SYSINFO_MAX_STRINGLENGTH];        /*网关*/
	HI_CHAR aszMacAddr[SYSINFO_MAX_STRINGLENGTH];        /*MAC 地址*/
	HI_CHAR aszFDNSIP[SYSINFO_MAX_STRINGLENGTH];         /*first DNSIP*/
	HI_CHAR aszSDNSIP[SYSINFO_MAX_STRINGLENGTH];         /*DNSIP*/
	HI_S32  s32DhcpFlag;                                 /*DHCP*/
	HI_S32  s32DnsDynFlag;                               /*DNS 动态分配标识*/
}HI_S_NETINFO, *PHI_S_NETINFO;

// 设备信息
typedef struct tagHI_DEVICE_INFO
{   
    HI_CHAR aszServerSerialNumber[SYSINFO_MAX_STRINGLENGTH + 1];	/*设备序列号*/
	//HI_CHAR aszServerHardVersion[SYSINFO_MAX_VERLENGTH + 1];		/*硬件版本*/
    HI_CHAR aszServerSoftVersion[SYSINFO_MAX_VERLENGTH + 1];		/*软件版本*/
    HI_CHAR aszServerName[SYSINFO_MAX_STRINGLENGTH + 1];			/*服务器名称*/
    HI_CHAR aszServerModel[SYSINFO_MAX_STRINGLENGTH + 1];			/*型号*/
    HI_CHAR aszStartDate[SYSINFO_MAX_STRINGLENGTH + 1];				/*系统启动日期时间*/
	//HI_CHAR aszTimes[SYSINFO_MAX_STRINGLENGTH + 1];				/*系统已启动时长,单位:分钟.uptime*/
	//HI_CHAR aszServerInterface[48 + 1];							/*接口类型和数量*/ //？？？fengjf
	HI_S32 s32ConnectState;											/*网络连接状态*/
}HI_DEVICE_INFO, *PHI_DEVICE_INFO;


//video encoding format
typedef enum tagPLAYERSDK_VIDEO_FORMAT_E
{
	PLAYERSDK_VENC_FORMAT_H261 = 0,       // H261
        PLAYERSDK_VENC_FORMAT_H263,           // H263
        PLAYERSDK_VENC_FORMAT_MPEG2,          // MPEG2
        PLAYERSDK_VENC_FORMAT_MPEG4,          // MPEG4
        PLAYERSDK_VENC_FORMAT_H264,           // H264
        PLAYERSDK_VENC_FORMAT_MJPEG,          // MJPEG
	PLAYERSDK_VENC_FORMAT_H265,           // H265
        PLAYERSDK_VENC_FORMAT_BUTT            // reserve
}PLAYERSDK_VIDEO_FORMAT_E;//, VIDEOSDK_FORMAT_E;
//audio encoding format
typedef enum tagPLAYERSDK_AUDIO_FORMAT_E
{
	PLAYERSDK_AUDIO_CODEC_FORMAT_G711A = 1,      //G.711 A
        PLAYERSDK_AUDIO_CODEC_FORMAT_G711U,          //G.711 U
        PLAYERSDK_AUDIO_CODEC_FORMAT_ADPCM,          //ADPCM
        PLAYERSDK_AUDIO_CODEC_FORMAT_G726,           //G.726
        PLAYERSDK_AUDIO_CODEC_FORMAT_AMR,            //AMR
        PLAYERSDK_AUDIO_CODEC_FORMAT_AMRDTX,         //AMR encoder formant and VAD1 enable
        PLAYERSDK_AUDIO_CODEC_FORMAT_AAC,            //aac
        PLAYERSDK_AUDIO_CODEC_FORMAT_WAV,            //wav
        PLAYERSDK_AUDIO_CODEC_FORMAT_MP3,            //MP3
        PLAYERSDK_AUDIO_CODEC_FORMAT_BUTT
}PLAYERSDK_AUDIO_FORMAT_E;//, AUDIO_FORMAT_E;
// 结构定义

typedef enum hiPLAYER_DISPLAYMODE_E
{
	PLAYER_DPY_D3D = 0,
	PLAYER_DPY_DDRAW,
}PLAYER_DISPLAYMODE_E;

// video attr
typedef struct tagPLAYERSDK_ATTR_VIDEO_STREAM_S
{
	PLAYERSDK_VIDEO_FORMAT_E eVEncode;  //Video encode format
	long lHeight;        //video height
	long lWidth;         //video width
	long lBitRate;       //video bit rate
	long lFrameRate;     //video frame rate
}PLAYERSDK_ATTR_VIDEO_STREAM_S;
//audio attr
typedef struct tagPLAYERSDK_ATTR_AUDIO_S
{
	PLAYERSDK_AUDIO_FORMAT_E eAEncode;  //audio encode format
	long lSamplesPerSec;         //audio's samples per second
	long lBitsPerSample;         //bits per sample
	long lBitRate;               //audio's bit rate
	long lBlockAlign;            //if block align
	long lChannels;              //audio's channels
	long lFrameFlag;             //audio's frame flag
	long length;                 //audio's size
	void *pReserved;
}PLAYERSDK_ATTR_AUDIO_S;
//frame image info

typedef struct hiSTREAM_ATTR_S
{
	PLAYERSDK_ATTR_VIDEO_STREAM_S struVAttr;
	PLAYERSDK_ATTR_AUDIO_S        struAAttr;
} STREAM_ATTR_S;

/*typedef struct hiLOGIN_INFO
{
	HI_U32  u32Handle;
	HI_CHAR psHost[32];
	HI_CHAR psUsername[24]; 
	HI_CHAR psPassword[24];
	HI_U16 u16Port;
	HI_U32 u32Timeout;
	HI_U32 u32Interval;
}LOGIN_INFO_S, *PLOGIN_INFO_S;*/

typedef struct hiSERVERTIME_INFO_S
{
	HI_CHAR sTime[32];
} HI_S_SERVERTIME;

//media attr type
typedef enum hiMEDIAATTR_TYPE_E
{
	ATTR_VIDEO_STREAM = 0,     //video stream attr
	ATTR_VIDEO_OUTPUT = 1,     //video out attr
	ATTR_AUDIO_STREAM = 2,     //audio stream attr
	ATTR_AUDIO_ENCODE = 3,     //audio encoding attr
	BUTT_ATTR_TYPE
}MEDIAATTR_TYPE_E;

typedef struct HI_SNAPTIMER
{
	HI_U32 u32Interval;
	HI_U32 u32Operation;
	HI_U32 u32Enable;
}HI_S_SNAPTIMER;

typedef struct HI_EMAIL_PARAM
{
	HI_CHAR sServer[32];
	HI_U32  u32Port;
	HI_U32  u32Ssl;
	HI_U32  u32LoginType;
	HI_CHAR sUser[24];
	HI_CHAR sPass[24];
	HI_CHAR sFrom[32];
	HI_CHAR sTo[32];
	HI_CHAR sSubject[32];
	HI_CHAR sText[128];
}HI_S_EMAIL_PARAM;

typedef struct HI_FTP_PARAM
{
	HI_CHAR sServer[32];
	HI_U32  u32Port;
	HI_U32  u32Mode;
	HI_CHAR sUser[24];
	HI_CHAR sPass[24];
}HI_S_FTP_PARAM;

typedef struct HI_PLATFORM
{
	HI_CHAR sServer[32];
	HI_U32  u32Port;
	HI_U32  u32Enable;
	HI_U32  u32Devid;
	HI_U32  u32MediaType;
	HI_U32  u32AlarmFlag;
}HI_S_PLATFORM;

typedef struct HI_DNS_PARAM
{
	HI_CHAR sServiceType[32];
	HI_CHAR sUser[24];
	HI_CHAR sPass[24];
	HI_CHAR sDomain[32];
	HI_U32  u32Enable;
}HI_S_DNS_PARAM;

typedef struct HI_OUR_DNS
{
	HI_CHAR sServer[32];
	HI_CHAR sUsername[32];
	HI_CHAR sPassword[32];
	HI_U32  u32Enable;
	HI_U32	u32Port;
	HI_CHAR sDomain[32];
}HI_S_OUR_DNS;

typedef struct HI_MD_TIMER
{
	HI_U32  u32Etm;
	HI_CHAR sWorkday[16];
	HI_CHAR sWeekend[16];
	HI_CHAR sWeek[7][16];
}HI_S_MD_TIMER;

typedef struct HI_NET_EXT
{
	HI_S_NETINFO  sNetInfo;
	HI_S_HTTPPORT sHttpPort;
}HI_S_NET_EXT;

typedef struct HI_WIFI_PARAM
{
	HI_CHAR sSsID[32];
	HI_CHAR sKey[32];
	HI_U32 u32Enable;
	HI_U32 u32Auth;
	HI_U32 u32Enc;
	HI_U32 u32Mode;
}HI_S_WIFI_PARAM;

#define WIFI_NET_INFRA	0
#define WIFI_NET_ADHOC	1

#define WIFI_AUTH_NONE	0
#define WIFI_AUTH_WEP	1
#define WIFI_AUTH_WPA	2
#define WIFI_AUTH_WPA2	3

#define WIFI_ENC_TKIP	0
#define WIFI_ENC_AES	1

typedef struct HI_WFPT
{
	HI_CHAR sEssID[32];
	HI_S32 s32Chn;
	HI_S32 s32Rssi;
	HI_U32 u32Enc;
	HI_U32 u32Auth;
	HI_U32 u32Net;
}HI_S_WFPT;

#define MAX_WFPT 64
typedef struct HI_WIFI_INFO
{
	HI_S32 s32Num;
	HI_S_WFPT sWfPt[MAX_WFPT];
}HI_S_WIFI_INFO;

typedef struct HI_RTSPINFO
{
	HI_U32 u32RtspPort;
	HI_U32 u32AuthFlag;
} HI_S_RTSPINFO;

typedef struct HI_USER
{
	HI_CHAR sUsername[32];
	HI_CHAR sPassword[32];
} HI_S_USER;

typedef struct HI_USERINFO
{
	HI_S_USER sUser[3];
} HI_S_USERINFO;

typedef struct HI_CHN_INFO
{
	HI_U32 u32Enable;
	HI_CHAR sHost[24];
	HI_BOOL bStream;
	HI_U32 u32Port;
	HI_U32 u32Chn;
	HI_CHAR sUsername[32];
	HI_CHAR sPassword[32];
}HI_S_CHN_INFO;

typedef struct hiNVR_CHN
{
	HI_CHAR sName[32];
	HI_S_CHN_INFO sChnInfo;
}HI_S_NVR_CHN;

typedef struct HI_CHN_STATE
{
	HI_U32 u32State;
	HI_U32 u32linkNum;
}HI_S_CHN_STATE;

typedef struct HI_DEVINFO
{
	HI_CHAR sHost[32];
	HI_U32 u32Port;
}HI_S_DEVINFO;

#define MAX_SEARCH_NUM 64
typedef struct HI_SEARCH_INFO
{
	HI_U32 u32Num;
	HI_S_DEVINFO sDevInfo[MAX_SEARCH_NUM];
}HI_S_SEARCH_INFO;

typedef struct HI_RECORD_INFO
{
	HI_BOOL bStream;
	HI_U32 u32SetupAlarm;
	HI_U32 u32InputAlarm;
	HI_U32 u32MdAlarm;
	HI_CHAR sRecInfo[7][48+1];
}HI_S_RECORD_INFO;

typedef struct HI_RECORD_SYS
{
	HI_U32 u32RecLen;
	HI_U32 u32AlarmLen;
	HI_U32 u32Cover;
	HI_U32 u32PlanRecFlag;
	HI_U32 u32PreRec;
	HI_U32 u32RecType;
	HI_U32 u32DiskRemain;
}HI_S_RECORD_SYS;


#define MAX_LOOP_CHN 36
typedef struct HI_LOOP_INFO
{
	HI_U32 u32LoopTime;
	HI_S_CHN_INFO  sChnInfo[MAX_LOOP_CHN];
}HI_S_LOOP_INFO;

typedef struct HI_TIME
{
	HI_U32  u32Year;
	HI_U32  u32Month;
	HI_U32  u32Day;
	HI_U32  u32Hour;
	HI_U32  u32Minute;
	HI_U32  u32Second;
}HI_S_TIME;


typedef struct HI_DEC_CHN_INFO
{
	HI_S_CHN_INFO  sChnInfo;
	HI_U32 u32DecState;
	HI_S_TIME sStartTime;
	HI_S_TIME sStopTime;
	HI_CHAR sFileName[128];
}HI_S_DEC_CHN_INFO;

typedef struct HI_REC_STATE
{
	HI_U32 u32link;
	HI_U32 u32Record;
}HI_S_REC_STATE;

typedef struct HiDISK
{
	HI_U32 u32Total;
	HI_U32 u32Free;
}HI_S_DISK;

#define MAX_DISK_NUM 20
typedef struct HI_DISK_INFO
{
	HI_S32 s32Num;
	HI_S_DISK sDisk[MAX_DISK_NUM];
}HI_S_DISK_INFO;

typedef struct HI_DISK_FORMAT
{
	HI_S32 s32DiskNum;
}HI_DISK_FORMAT;




typedef enum{
	PICTURE_NUM_1 = 1,
	PICTURE_NUM_4 = 4,
	PICTURE_NUM_9 = 9,
	PICTURE_NUM_BUTT
}PICTURE_NUM_E;

typedef enum{  
	DISPLAY_TYPE_VGA = 0,
	DISPLAY_TYPE_CVBS = 2,  
	DISPLAY_TYPE_BUTT
}DISPLAY_TYPE_E;

typedef enum{  
	DISPLAY_MODE_PAL = 25,
	DISPLAY_MODE_NTSC= 30,  
	DISPLAY_MODE_BUTT
}DISPLAY_MODE_E;

typedef enum{
	VIDEO_MODE_PAL           = 0,
	VIDEO_MODE_NTSC          = 1,
		
	VIDEO_MODE_1280x1024_60  = 9,
	VIDEO_MODE_1366x768_60   = 10,
	VIDEO_MODE_BUTT
}VIDEO_MODE_E;/*CVBS[0-1],VGA[9-10]*/

typedef enum{
	DISPLAY_FLAG_AUTO = 0,
	DISPLAY_FLAG_FIXED = 1,
	DISPLAY_FLAG_BUTT
}DISPLAY_FLAG_E;


typedef struct hiDISPLAY_CFG
{
	VIDEO_MODE_E	eVideoMode;
	PICTURE_NUM_E	ePictureNum;
    DISPLAY_TYPE_E	eDpyType;
    DISPLAY_MODE_E	eDpyMode;
    DISPLAY_FLAG_E	eDpyFlag;
} HI_S_DISPLAY_CFG;

typedef struct hiDEVID
{
	HI_CHAR sDevID[32];
}HI_S_DEVID;

typedef struct hiIMAGE
{
	HI_U32 u32Brightness;   //亮度
	HI_U32 u32Saturation;   //饱和度
	HI_U32 u32Contrast;     //对比度
	HI_U32 u32Hue;          //色度
	HI_U32 u32Shutter;		//快门
	HI_U32 u32Dnt;			//色彩灵敏度
	HI_U32 u32Lumivalue;	//低照度
	HI_U32 u32Sensor;		//类型 1--9d131，2--2643 
	HI_BOOL bFlip;			//上下翻转
	HI_BOOL bMirror;		//左右翻转
	HI_BOOL bNight;			//夜视模式
	HI_BOOL bWdr;			//宽动态开关
	HI_BOOL bLumiswitch;	//低照度开关
} HI_S_IMAGE;


#define HI_QT_TYPE_ALARM 0
#define HI_QT_TYPE_PLAN  1
#define HI_QT_TYPE_SNAP  2
typedef struct HI_QUANTUM_TIME
{
	HI_U32 u32QtType;			//HI_QT_TYPE_ALARM, HI_QT_TYPE_PLAN
	HI_CHAR sDayData[7][48+1];	//P, N
}HI_S_QUANTUM_TIME;


#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif /* __HI_TYPE_H__ */