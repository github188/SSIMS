/******************************************************************************
* 系统名称：HHNet
* 文件名称：HHNet.h
* 版本    ：V 2.0.0
* 说明	  ：网络开发包接口,本SDK为和编码器、解码器交互提供接口
			该文件包含六部分：一、宏定义；二、枚举类型定义；三、回调函数；四、接口结构类型定义；五、函数接口定义；六、数字视频服务器的配置信息结构
* 日    期: 2008年9月28日
  最近更新:	2008年9月28日
* 其他说明: 无
******************************************************************************/
#ifndef  __HHNET_H__
#define  __HHNET_H__

#define PACKED  __attribute__((packed, aligned(1)))
#define PACKED4 __attribute__((packed, aligned(4)))


/*----------------------------------------------*
  基本数据类型定义
 *----------------------------------------------*/

typedef	char				CHAR;
typedef	short				SHORT;
typedef int					INT;
typedef	long				LONG;

typedef	unsigned char		UCHAR;
typedef	unsigned short		USHORT;
typedef unsigned int		UINT;
typedef	unsigned long		ULONG;
typedef	int					BOOL;

typedef unsigned long*		HANDLE;
typedef void*				LPVOID;
typedef unsigned long*		TALKHANDLE;

typedef unsigned char       UInt8;
typedef unsigned short      UInt16;
typedef unsigned int        UInt32;

typedef unsigned char  		BYTE ;
typedef unsigned long 		DWORD;

#ifndef NULL
#define NULL  ((void *)0)
#endif

/*********************************  一、宏定义  ******************************/

//1，系统常量
#define	IN
#define	OUT
#define	MAX_PATH				256

#define MAX_VIDEO_NUM			4	//数字视频服务器最大通道数
#define MAX_AUDIO_NUM			4	//数字视频服务器音频最大通道数
#define MAX_SENSOR_NUM			4	//探头输入路数
#define MAX_RF_SENSOR_NUM		8	//无线探头最大路数
#define MAX_OUTPUT_NUM			4	//探头输出路数
#define MAX_COM_NUM				2	//串口最大个数	
#define MAX_USER_NUM			5	//用户个数
#define MAX_LOGON_NUM			10	//最大同时登录用户数
#define MAX_LINKVIEW_NUM		16	//最大同时TCP、UDP预览用户数
#define MAX_MULTIVIEW_NUM		60	//最大多播用户数
#define DVS_NAME_LEN            32	//数字视频服务器名称长度

#define CAM_TITLE_LEN_NEW		64	//31个汉字，63个字符
#define CAM_TITLE_LEN			16	//摄像机标题长度(8个汉字，16个字符)
#define USER_NAME_LEN 			16	//用户名的最大长度
#define USER_PASSWD_LEN   		16	//用户密码最大长度
	
#define DDNS_NAME_LEN			32	//注册主机名称长度
#define DDNS_PASS_LEN			16	//注册主机密码长度	
#define	DDNS_SERVER_NAME_LEN	32
#define PPPPOE_NAME_LEN			32	//拨号用户名长度
#define PPPPOE_PASSWD_LEN		16	//拨号用户名长度
#define YUNTAI_NAME_LEN			32	//云台协议名称长度
#define MAX_YUNTAI_PROTOCOL_NUM	36	//内置最大云台协议数
#define MAX_PTZ_PROTOCOL_NUM  	4	//最大云台协议数
#define	MAX_IP_NAME_LEN			128	//输入IP或名字的最大长度
#define	IP_STR_LEN				16	//IP长

#define	DOMAIN_NAME_LEN			32  //域名的长度
#define EMAIL_TITLE_LEN         32	//EMAIL头和内容长
#define DD_URL_ADDR_LEN			32	//URL地址长度
#define	DD_MAX_ADDR_NUM			32	//地址薄的地址数量
#define	DD_MAX_ALARMINFO_NUM	64	//报警记录个数最大值
#define EMP_NO_LEN				32  //工号长度

//2，云台控制
#define	YT_UP					1	//云台上
#define	YT_DOWN					2	//云台下	
#define	YT_LEFT					3	//云台左
#define	YT_RIGHT				4	//云台右
#define	YT_FOCUSADD				5	//聚焦+
#define	YT_FOCUSSUB				6	//聚焦-
#define	YT_IRISADD				7	//光圈+
#define	YT_IRISSUB				8	//光圈-
#define	YT_ZOOMADD				9	//变倍+
#define	YT_ZOOMSUB				10	//变倍-
#define	YT_AUTOOPEN				11	//自动开
#define	YT_AUTOCLOSE			12	//自动关
#define	YT_LAMPOPEN				13	//灯光开
#define	YT_LAMPCLOSE			14	//灯光关
#define	YT_BRUSHOPEN			15	//雨刮开
#define	YT_BRUSHCLOSE			16	//雨刮关
#define	YT_WATEROPEN			17	//放水开
#define	YT_WATERCLOSE			18	//放水关
#define	YT_PRESET				19	//预置 + 号
#define	YT_CALL					20	//调用 + 号
#define	YT_STOP					21	//停止
#define	YT_UP_STOP				30	//云台上-停	
#define	YT_DOWN_STOP			31	//云台下-停	
#define	YT_LEFT_STOP			32	//云台左-停
#define	YT_RIGHT_STOP			33	//云台右-停
#define	YT_FOCUSADD_STOP		34	//聚焦+ -停
#define	YT_FOCUSSUB_STOP		35	//聚焦- -停
#define	YT_IRISADD_STOP			36	//光圈+ -停
#define	YT_IRISSUB_STOP			37	//光圈- -停
#define	YT_ZOOMADD_STOP			38	//变倍+ -停
#define	YT_ZOOMSUB_STOP			39	//变倍- -停	

//3，数据帧标志
#define FRAME_FLAG_VP			0x0b	//视频的P帧
#define FRAME_FLAG_VI			0x0e	//视频的I帧
#define FRAME_FLAG_A			0x0d	//音频帧


/*********************************  二、枚举类型定义  ******************************/

//1，数字视频服务器机器类型
typedef enum	DVS_MACHINE_TYPE_
{
    HH5001C  = 0x00,  //一路CIF编码器
    HH5002H  = 0x01,  //二路HalfD1编码器
    HH5001D  = 0x02,  //一路D1编码器
    HH5004C  = 0x03,  //四路CIF编码器
    HH5104   = 0x04,  //四路解码器
    HH5108   = 0x05,  //八路解码器
    HH6104   = 0x06,  //四路解码卡

    HH5200   = 0x10,  //保留
    HH5201   = 0x11,  //IPCam一路CCD,D1编码,HH9000系列
    HH5201DI = 0X11,
    HH5201CI = 0x12,  //IPCam一路CCD,CIF编码,HH9000系列
    HH5201MI = 0x13,  //IPCam一路CMOS,HH9000系列

    HH5201C  = 0x20,  //DVS一路CIF
    HH5201D  = 0x21,  //DVS一路D1
    HH5202C  = 0x22,  //DVS两路CIF
    HH5202H  = 0x23,  //DVS两路HD1
    HH5204C  = 0x24,  //DVS四路CIF
    HH5204D  = 0x25,  //DVS四路d1

    HH5301   = 0x30,  //H.264 单路解码器(IPCam, HH52系列, HH56系列DVS)

    HH5700   = 0x35,  //HH57系列 解码器 (IPCam, HH52系列, HH56系列DVS)

    HH9800CI = 0x40,  //HH98系列 IPCam一路CCD
    HH9800MI,         //HH98系列 IPCam一路CMOS

    HH9800MIX,        //HH98系列 IPCam一路CMOS(高清)

 

    HH5801C  = 0x45,  //HH58系列 DVS 
    HH5801D, 
    HH5802C,
    HH5802H,
    HH5802D, 
    HH5804C,
    HH5804H,
    HH5804D, 

    HH7000 = 0x50,
}DVS_MACHINE_TYPE;

//2，视频编码格式									
typedef enum  _ENCODE_VIDEO_TYPE
{
	EV_TYPE_NONE		= 0xFFFF,
	EV_TYPE_PAL_D1		= 0x00,		//PAL制D1		704 * 576
	EV_TYPE_PAL_HD1		= 0x01,		//PAL制HalfD1	704 * 288
	EV_TYPE_PAL_CIF		= 0x02,		//PAL制CIF		352 * 288
	EV_TYPE_VGA			= 0x03,		//VGA			640 * 480
	EV_TYPE_HVGA		= 0x04,		//HVGA			640 * 240
	EV_TYPE_CVGA		= 0x05,		//CVGA			320 * 240
	EV_TYPE_PAL_QCIF	= 0x06,		//PAL制QCIF		176 * 144
	EV_TYPE_QVGA		= 0x07,		//QVGA			160 * 120
	EV_TYPE_NTSC_D1		= 0x08,		//N制D1			704 * 480
	EV_TYPE_NTSC_HD1	= 0x09,		//N制HalfD1		704 * 240
	EV_TYPE_NTSC_CIF	= 0x0A,		//N制CIF		352 * 240
	EV_TYPE_NTSC_QCIF	= 0x0E,		//N制QCIF		176 * 120
	//
	EV_H264_PAL_D1		= 0x10,		//H264_2,PAL制D1		704 * 576
	EV_H264_PAL_HD1		= 0x11,		//H264_2,PAL制HalfD1	704 * 288
	EV_H264_PAL_CIF		= 0x12,		//H264_2,PAL制CIF		352 * 288
	EV_H264_VGA			= 0x13,		//H264_2,VGA			640 * 480
	EV_H264_HVGA		= 0x14,		//H264_2,HVGA			640 * 240
	EV_H264_CVGA		= 0x15,		//H264_2,CVGA			320 * 240
	EV_H264_PAL_QCIF	= 0x16,		//H264_2,PAL制QCIF		176 * 144
	EV_H264_QVGA		= 0x17,		//H264_2,QVGA			160 * 120
	EV_H264_NTSC_D1		= 0x18,		//H264_2,N制D1			704 * 480
	EV_H264_NTSC_HD1	= 0x19,		//H264_2,N制HalfD1		704 * 240
	EV_H264_NTSC_CIF	= 0x1A,		//H264_2,N制CIF			352 * 240
	EV_H264_NTSC_QCIF	= 0x1E,		//H264_2,N制QCIF		176 * 120
	//
	//标准MPEG4
	EV_MPEG4_PAL_D1		= 0x20,		//PAL制D1				704 * 576
	EV_MPEG4_PAL_HD1	= 0x21,		//PAL制HalfD1			704 * 288
	EV_MPEG4_PAL_CIF	= 0x22,		//PAL制CIF				352 * 288
	EV_MPEG4_VGA		= 0x23,		//VGA					640 * 480
	EV_MPEG4_HVGA		= 0x24,		//HVGA					640 * 240
	EV_MPEG4_CVGA		= 0x25,		//CVGA					320 * 240
	EV_MPEG4_PAL_QCIF	= 0x26,		//PAL制QCIF				176 * 144
	EV_MPEG4_QVGA		= 0x27,		//QVGA					160 * 120
	EV_MPEG4_NTSC_D1	= 0x28,		//N制D1					704 * 480
	EV_MPEG4_NTSC_HD1	= 0x29,		//N制HalfD1				704 * 240
	EV_MPEG4_NTSC_CIF	= 0x2A,		//N制CIF				352 * 240
	EV_MPEG4_NTSC_QCIF	= 0x2E,		//N制QCIF				176 * 120
	//
	EA_G722_S16B16C1	= 0x0100,	//音频，G722
	EA_G711A_S16B16C1	= 0x0200,	//音频，G711A
	EA_G711MU_S16B16C1	= 0x0300,	//音频，G711MU
	EA_ADPCM_S16B16C1	= 0x0400,	//音频，ADPCM
	EA_G726_S16B16C1	= 0x0500,	//音频，G726
	EA_BUTT_S16B16C1	= 0x0600,	//音频，BUTT
	EA_MPT_S16B16C1		= 0x0700,	//音频，MPT
}ENCODE_VIDEO_TYPE;

//3，升级类型
typedef enum _UPDATE_TYPE
{
	UPDATE_KERNEL,					//升级内核
	UPDATE_YUNTAI1,					//升级云台协议1
	UPDATE_YUNTAI2,					//升级云台协议2
	UPDATE_YUNTAI3,					//升级云台协议3
	UPDATE_YUNTAI4,					//升级云台协议4
	UPDATE_YUNTAI5,					//升级云台协议5
	UPDATE_YUNTAI6,					//升级云台协议6
	UPDATE_OCX,						//升级控件
	UPDATE_WEBPAGE,					//升级页面
	UPDATE_PATHFILE,				//升级特定目录文件
}UPDATE_TYPE;

//4，网络协议类型
typedef enum _NET_PROTOCOL_TYPE
{
    NET_PROTOCOL_TCP = 0,			//TCP协议
    NET_PROTOCOL_UDP = 1,			//UDP协议
    NET_PROTOCOL_MULTI = 2			//多播协议
}NET_PROTOCOL_TYPE;

//5，连接状态
typedef enum _CONNECT_STATUS
{
	CONNECT_STATUS_NONE,			//未连接
	CONNECT_STATUS_OK,				//已经连接
}CONNECT_STATUS;

//6，转发类型
typedef enum _RELAY_TYPE
{
	RELAY_LOGON,					//转发登录设置
	RELAY_PREVIEW,					//转发视频预览数据
	RELAY_TALK,						//转发对讲
	RELAY_AUDIOBRD,					//转发语音广播
	RELAY_QUERY						//转发的查询
}RELAY_TYPE;

//7，通知应用程序窗口消息命令
typedef enum _HHMSG_NOTIFY

{
    HHMSG_CONNECT_CLOSE,             //登录连接关闭 

    HHMSG_CHANNEL_CLOSE,             //通道连接关闭 

    HHMSG_TALK_CLOSE,                //对讲连接关闭 

    HHMSG_ALARM_OUTPUT,              //报警输出                   98系列58系列之前设备用此定义 

    HHMSG_UPDATE_SEND_PERCENT,       //升级程序发送百分比 

    HHMSG_UPDATE_SAVE_PERCENT,       //升级写入发送百分比

    HHMSG_VIEWPUSH_CLOSE ,           //解码器视频输入关闭 

   	HHMSG_BROADCAST_ADD_FAILURE,     //加入语音广播组失败 

   	HHMSG_BROADCAST_CLOSE,           //语音广播中一个断开 

   	HHMSG_SENSOR_CAPTURE,            //探头触发的抓拍 

   	HHMSG_COM_DATA,                  //串口采集数据 

   	HHMSG_ALARM_LOST,                //报警消失                   98系列58系列之前设备用此定义

    HHMSG_ALARM_OUTPUT_NEW,          //报警输出(新)               98系列58系列以后设备用此定义
    HHMSG_ALARM_LOST_NEW,            //报警消失(新)               98系列58系列以后设备用此定义
    HHMSG_PICCHN_CLOSE,              //抓拍通道连接关闭 
	
	HHMSG_NETWORK_FAULT,			//网络故障(新)

}HHMSG_NOTIFY;


//8，错误码
typedef enum _HHERR_CODE
{
	HHERR_SUCCESS,					//操作成功
	HHERR_FAILURE,					//操作失败
	HHERR_REFUSE_REQ,				//请求被拒绝
	HHERR_USER_FULL,				//登录用户已满
	HHERR_PREVIEW_FULL,				//预览用户已满
	HHERR_TASK_FULL,				//系统任务繁忙，待会尝试连接
	HHERR_CHANNEL_NOT_EXIST,		//要打开的通道不存在或已满
	HHERR_DEVICE_NAME,				//打开的设备不存在
	HHERR_IS_TALKING,				//正在对讲
	HHERR_QUEUE_FAILUE,				//队列出错
	HHERR_USER_PASSWORD,			//用户名或密码和系统不匹配
	HHERR_SHARE_SOCKET,				//socket 错误
	HHERR_RELAY_NOT_OPEN,			//转发请求的服务还未打开
	HHERR_RELAY_MULTI_PORT,			//转发多播端口错误
	HHERR_VIEWPUSH_CHANNEL_USING,	//视频输入的通道已经被占用
	HHERR_VIEWPUSH_DECODE_TYPE,		//视频输入通道的解码格式错误，0通道(4cif,2cif,cif),1通道(2cif,cif),2通道(cif),3通道(cif)
	HHERR_AUTO_LINK_FAILURE,		//转发的自动连接失败
	HHERR_NOT_LOGON,
	HHERR_IS_SETTING,
	HHERR_COMMAND_FAILURE,
	
	HHERR_INVALID_PARAMETER=100,	//输入参数无效
	HHERR_LOGON_FAILURE,			//登录失败
	HHERR_TIME_OUT,					//操作超时
	HHERR_SOCKET_ERR,				//SOCKET错误
	HHERR_NOT_LINKSERVER,			//还未连接服务器
	HHERR_BUFFER_EXTCEED_LIMIT,		//使用缓冲超过限制	
	HHERR_LOW_PRIORITY,				//操作权限不足
	HHERR_BUFFER_SMALL,				//缓冲太小
	HHERR_IS_BUSY,					//系统任务正忙
	HHERR_UPDATE_FILE,				//升级文件错误
	HHERR_UPDATE_UNMATCH,			//升级文件和机器不匹配
	HHERR_PORT_INUSE,				//端口被占用
	HHERR_RELAY_DEVICE_EXIST,		//设备名已经存在
	HHERR_CONNECT_REFUSED,			//连接时被拒绝
	HHERR_PROT_NOT_SURPPORT,		//不支持该协议

	HHERR_FILE_OPEN_ERR,            //打开文件失败
	HHERR_FILE_SEEK_ERR,            //fseek失败 
	HHERR_FILE_WRITE_ERR,           //fwrite失败 
	HHERR_FILE_READ_ERR,            //fread失败 
	HHERR_FILE_CLOSING,             //正在关闭文件 
	
}HHERR_CODE;

//9，参数操作命令
typedef enum _HHCMD_NET
{
	HHCMD_GET_ALL_PARAMETER,		//0. 得到所有编码器参数
	HHCMD_SET_DEFAULT_PARAMETER,	//1. 恢复所有编码器默认参数
	HHCMD_SET_RESTART_DVS,			//2. 重启编码器
	HHCMD_GET_SYS_CONFIG,			//3. 获取系统设置
	HHCMD_SET_SYS_CONFIG,			//4. 设置系统设置
	HHCMD_GET_TIME,					//5. 获取编码器时间
	HHCMD_SET_TIME,					//6. 设置编码器时间
	HHCMD_GET_AUDIO_CONFIG,			//7. 获取音频设置
	HHCMD_SET_AUDIO_CONFIG,			//8. 设置音频设置
	HHCMD_GET_VIDEO_CONFIG,			//9. 获取视频设置
	HHCMD_SET_VIDEO_CONFIG,			//10.设置视频设置
	HHCMD_GET_VMOTION_CONFIG,		//11.获取移动侦测设置
	HHCMD_SET_VMOTION_CONFIG,		//12.设置移动侦测设置
	HHCMD_GET_VMASK_CONFIG,			//13.获取图像屏蔽设置
	HHCMD_SET_VMASK_CONFIG,			//14.设置图像屏蔽设置
	HHCMD_GET_VLOST_CONFIG,			//15.获取视频丢失设置
	HHCMD_SET_VLOST_CONFIG,			//16.设置视频丢失设置
	HHCMD_GET_SENSOR_ALARM,			//17.获取探头报警侦测设置
	HHCMD_SET_SENSOR_ALARM,			//18.设置探头报警侦测设置
	HHCMD_GET_USER_CONFIG,			//19.获取用户设置
	HHCMD_SET_USER_CONFIG,			//20.设置用户设置
	HHCMD_GET_NET_CONFIG,			//21.获取网络设置结构
	HHCMD_SET_NET_CONFIG,			//22.设置网络设置结构
	HHCMD_GET_COM_CONFIG,			//23.获取串口设置
	HHCMD_SET_COM_CONFIG,			//24.设置串口设置
	HHCMD_GET_YUNTAI_CONFIG,		//25.获取内置云台信息
	HHCMD_SET_YUNTAI_CONFIG,		//26.设置内置云台信息
	HHCMD_GET_VIDEO_SIGNAL_CONFIG,	//27.获取视频信号参数（亮度、色度、对比度、饱和度）
	HHCMD_SET_VIDEO_SIGNAL_CONFIG,	//28.设置视频信号参数（亮度、色度、对比度、饱和度）
	HHCMD_SET_PAN_CTRL,				//29.云台控制
	HHCMD_SET_COMM_SENDDATA,		//30.透明数据传输
	HHCMD_SET_COMM_START_GETDATA,	//31.开始采集透明数据
	HHCMD_SET_COMM_STOP_GETDATA,	//32.停止采集透明数据
	HHCMD_SET_OUTPUT_CTRL,			//33.继电器控制
	HHCMD_SET_PRINT_DEBUG,			//34.调试信息开关
	HHCMD_SET_ALARM_CLEAR,			//35.清除报警
	HHCMD_GET_ALARM_INFO,			//36.获取报警状态和继电器状态
	HHCMD_SET_TW2824,				//37.设置多画面芯片参数(保留)
	HHCMD_SET_SAVE_PARAM,			//38.设置保存参数
	HHCMD_GET_USERINFO,				//39.获取当前登陆的用户信息
	HHCMD_GET_DDNS,					//40.获取DDNS
	HHCMD_SET_DDNS,					//41.设置DDNS
	HHCMD_GET_CAPTURE_PIC,			//42.前端抓拍
	HHCMD_GET_SENSOR_CAP,			//43.获取触发抓拍设置
	HHCMD_SET_SENSOR_CAP,			//44.设置触发抓拍设置
	HHCMD_GET_EXTINFO,				//45.获取扩展配置
	HHCMD_SET_EXTINFO,				//46.设置扩展配置
	HHCMD_GET_USERDATA,				//47.获取用户配置
	HHCMD_SET_USERDATA,				//48.设置用户配置
	HHCMD_GET_NTP,					//49.获取NTP配置
	HHCMD_SET_NTP,					//50.设置NTP配置
	HHCMD_GET_UPNP,					//51.获取UPNP配置
	HHCMD_SET_UPNP,					//52.设置UPNP配置
	HHCMD_GET_MAIL,					//53.获取MAIL配置
	HHCMD_SET_MAIL,					//54.设置MAIL配置
	HHCMD_GET_ALARMNAME,			//55.获取报警名配置
	HHCMD_SET_ALARMNAME,			//56.设置报警名配置
	HHCMD_GET_WFNET,				//57.获取无线网络配置
	HHCMD_SET_WFNET,				//58.设置无线网络配置
	HHCMD_GET_SEND_DEST,			//59.设置视频定向发送目标机
	HHCMD_SET_SEND_DEST,			//60.设置视频定向发送目标机
	HHCMD_GET_AUTO_RESET,			//61.取得定时重新注册
	HHCMD_SET_AUTO_RESET,			//62.设置定时重新注册
	HHCMD_GET_REC_SCHEDULE,			//63.取得录像策略
	HHCMD_SET_REC_SCHEDULE,			//64.设置录像策略
	HHCMD_GET_DISK_INFO,			//65.取得磁盘信息
	HHCMD_SET_MANAGE,				//66.设置命令和操作
	HHCMD_GET_CMOS_REG,				//67.取得CMOS参数
	HHCMD_SET_CMOS_REG,				//68.设置CMOS参数
	HHCMD_SET_SYSTEM_CMD,			//69.设置执行命令
	HHCMD_SET_KEYFRAME_REQ,			//70.设置关键帧请求
	HHCMD_GET_CONFIGENCPAR,			//71.取得视频参数
	HHCMD_SET_CONFIGENCPAR,			//72.设置视频参数
	//--------------------------
	HHCMD_GET_ALL_PARAMETER_NEW,	//73.获取所有参数
	HHCMD_FING_LOG,					//74.查找日志(查询方式:0－全部，1－按类型，2－按时间，3－按时间和类型 0xFF-关闭本次搜索)
	HHCMD_GET_LOG,					//75.读取查找到的日志	
	HHCMD_GET_SUPPORT_AV_FMT,		//76.获取设备支持的编码格式、宽高及音频格式
	HHCMD_GET_VIDEO_CONFIG_NEW,		//77.视频参数－new
	HHCMD_SET_VIDEO_CONFIG_NEW,		//78.
	HHCMD_GET_VMOTION_CONFIG_NEW,	//79.移动报警参数－new
	HHCMD_SET_VMOTION_CONFIG_NEW,	//80.
	HHCMD_GET_VLOST_CONFIG_NEW,		//81.视频丢失报警参数－new
	HHCMD_SET_VLOST_CONFIG_NEW,		//82.
	HHCMD_GET_SENSOR_ALARM_NEW,		//83.探头报警参数－new
	HHCMD_SET_SENSOR_ALARM_NEW,		//84.
	HHCMD_GET_NET_ALARM_CONFIG,		//85.网络故障报警参数－new
	HHCMD_SET_NET_ALARM_CONFIG,		//86.
	HHCMD_GET_RECORD_CONFIG,		//87.定时录像参数
	HHCMD_SET_RECORD_CONFIG,		//88.
	HHCMD_GET_SHOOT_CONFIG,			//89.定时抓拍参数
	HHCMD_SET_SHOOT_CONFIG,			//90.
	HHCMD_GET_FTP_CONFIG,			//91.FTP参数
	HHCMD_SET_FTP_CONFIG,			//92.
	HHCMD_GET_RF_ALARM_CONFIG,		//93.无线报警参数
	HHCMD_SET_RF_ALARM_CONFIG,		//94.
	HHCMD_GET_EXT_DATA_CONFIG,		//95.其它扩展参数(如平台设置其它参数)
	HHCMD_SET_EXT_DATA_CONFIG,		//96.
	HHCMD_GET_FORMAT_PROCESS,		//97.获取硬盘格式化进度
	HHCMD_GET_PING_CONFIG,			//98.PING 设置获取
	HHCMD_SET_PING_CONFIG,			//99.PING 设置设置

	//解码器命令
	DDCMD_GET_ALL_PARAMETER = 100,	//获取解码器所有设置
	DDCMD_GET_TIME,					//获取系统时间
	DDCMD_SET_TIME,					//设置系统时间
	DDCMD_GET_SYS_CONFIG,			//获取系统配置
	DDCMD_SET_SYS_CONFIG,			//设置系统配置
	DDCMD_GET_NET_CONFIG,			//获取网络配置
	DDCMD_SET_NET_CONFIG,			//设置网络配置
	DDCMD_GET_COM_CONFIG,			//获取串口配置
	DDCMD_SET_COM_CONFIG,			//设置串口配置
	DDCMD_GET_VIDEO_CONFIG,			//获取视频配置
	DDCMD_SET_VIDEO_CONFIG,			//设置视频配置
	DDCMD_GET_ALARM_OPT,			//获取报警选项
	DDCMD_SET_ALARM_OPT,			//设置报警选项
	DDCMD_GET_USER_INFO,			//获取用户设置信息
	DDCMD_SET_USER_INFO,			//设置用户设置信息
	DDCMD_GET_ALARM_RECORD,			//获取报警记录信息
	DDCMD_GET_ADRRESS_BOOK,			//获取地址薄配置
	DDCMD_SET_ADRRESS_BOOK,			//设置地址薄配置
	DDCMD_SET_COMM,					//设置发送串口数据
	DDCMD_SET_CMD,					//设置透明的命令
	DDCMD_GET_YUNTAI_INFO,			//获取云台信息
	DDCMD_GET_YUNTAI_CONFIG,		//获取云台配置
	DDCMD_SET_YUNTAI_CONFIG,		//设置云台配置
	DDCMD_GET_ONELINK_ADDR,			//获取解码器单路连接的信息
	DDCMD_SET_ONELINK_ADDR,			//设置解码器单路连接的信息
	DDCMD_GET_CYCLELINK_ADDR,		//获取解码器循环连接的信息
	DDCMD_SET_CYCLELINK_ADDR,		//设置解码器循环连接的信息
	DDCMD_GET_DDNS,					//获取DDNS
	DDCMD_SET_DDNS,					//设置DDNS

	HHCMD_GET_VPN_CONFIG = 200,
	HHCMD_SET_VPN_CONFIG,
	HHCMD_GET_3G_CONFIG,
	HHCMD_SET_3G_CONFIG,
	HHCMD_GET_GPS_CONFIG,
	HHCMD_SET_GPS_CONFIG,



	HHCMD_GET_VI_SENSOR=1000,
	HHCMD_SET_VI_SENSOR,
	HHCMD_GET_VI_SCENE,
	HHCMD_SET_VI_SCENE,
	HHCMD_GET_VI_CFG,
	HHCMD_SET_VI_CFG,
	

	//云台增加新增命令
	HHCMD_GET_DOME_PTZ_CFG,
	HHCMD_SET_DOME_PTZ_CFG,	
	HHCMD_GET_DOME_PRESET_CFG,
	HHCMD_SET_DOME_PRESET_CFG,	
	HHCMD_MAX_CONFIG,	
	//

	HHCMD_GET_EMPNO,
	HHCMD_SET_EMPNO,

}HHCMD_NET;


//10. 音视频编码格式(新)
//在98系列、58系列之后的设备都有扩展帧头
//音视频的编码信息都是通过扩展帧头EXT_FRAME_HEAD告诉播放库或解码库

//视频编码算法
typedef enum _HH_VIDEO_ENCODER_E

{

    HH_VENC_NONE  = 0x00,

    HH_VENC_H264  = 0x01,

    HH_VENC_MPEG4 = 0x02,

    HH_VENC_MJPEG = 0x03,

    HH_VENC_JPEG  = 0x04,

}HH_VIDEO_ENCODER_E;

//音频编码算法
typedef enum _HH_AUDIO_ENCODER_E

{

    HH_AENC_NONE  = 0x00,

    HH_AENC_G726  = 0x01,

    HH_AENC_G722  = 0x02,

    HH_AENC_G711  = 0x03,

    HH_AENC_ADPCM = 0x04,

    HH_AENC_MP3   = 0x05,

}HH_AUDIO_ENCODER_E;

//音频采样率
typedef enum _HH_AUDIO_SAMPLERATE_E

{

    AI_SAMPLE_RATE_NONE  = 0, 

    AI_SAMPLE_RATE_8000  = 8000,  /* 8kHz sampling rate      */

    AI_SAMPLE_RATE_11025 = 11025, /* 11.025kHz sampling rate */

    AI_SAMPLE_RATE_16000 = 16000, /* 16kHz sampling rate     */

    AI_SAMPLE_RATE_22050 = 22050, /* 22.050kHz sampling rate */

    AI_SAMPLE_RATE_24000 = 24000, /* 24kHz sampling rate     */

    AI_SAMPLE_RATE_32000 = 32000, /* 32kHz sampling rate     */

    AI_SAMPLE_RATE_44100 = 44100, /* 44.1kHz sampling rate   */

    AI_SAMPLE_RATE_48000 = 48000, /* 48kHz sampling rate     */

}HH_AUDIO_SAMPLERATE_E;

//音频编码码率(G726)
typedef enum _HH_AUDIO_BITRATE_E

{ 

    AENC_BITRATE_NONE  = 0,

    AENC_BITRATE_16000 = 16000, 

    AENC_BITRATE_24000 = 24000, 

    AENC_BITRATE_32000 = 32000, 

    AENC_BITRATE_40000 = 40000, 

}HH_AUDIO_BITRATE_E;

typedef enum _RELAY_CHECK_RET
{
	RCRET_SUCCESS = 0,
	RCRET_FAILURE = -1,
	RCRET_AUTO_LINK = 0x0101,	
}RELAY_CHECK_RET;

#ifndef HHAV_INFO_DEFINE
#define HHAV_INFO_DEFINE

//1，视频音频参数
typedef struct _HHAV_INFO
{
    //视频参数
    UINT			nVideoEncodeType;		//视频编码格式
    UINT			nVideoHeight;			//视频图像高
    UINT			nVideoWidth;			//视频图像宽
    //音频参数
    UINT			nAudioEncodeType;		//音频编码格式
    UINT			nAudioChannels;			//通道数
    UINT			nAudioBits;				//位数
    UINT			nAudioSamples;			//采样率
}HHAV_INFO,*PHHAV_INFO;

#endif //HHAV_INFO_DEFINE

/*********************************  三、回调函数  ******************************/

//实时音视频数据流回调
typedef int  ( *ChannelStreamCallback)(HANDLE hOpenChannel,void *pStreamData,UINT dwClientID,void *pContext,ENCODE_VIDEO_TYPE encodeVideoType,ULONG frameno);

//实时对讲音频数据流回调
typedef int  ( *TalkStreamCallback)(void *pTalkData,UINT nTalkDataLen,void *pContext);

//消息通知，通知调用
typedef int  ( *MsgNotifyCallback)(DWORD dwMsgID,DWORD ip,DWORD port,HANDLE hNotify,void *pPar);

//检查用户，客户端登陆时检查
typedef int  (*CheckUserPsw)(const CHAR *pUserName,const CHAR *pPsw);

//客户端传递的消息
typedef int  (*ServerMsgReceive)(ULONG ip,ULONG port,CHAR *pMsgHead);

//升级
typedef int	 (*ServerUpdateFile)(int nOperation,int hsock,ULONG ip,ULONG port,int nUpdateType,CHAR *pFileName,CHAR *pFileData,int nFileLen);

//

//3，转发服务的用户检测回调
typedef int	 (*RelayCheckUserCallback)(RELAY_TYPE relayType,UINT dwClientIP,USHORT wClientPort,CHAR *pszUserName,CHAR *pszPassword,CHAR *pszDeviceName,UINT dwRequstChannel,INT bOnline,CHAR *pDeviceIP,UINT *pdwDevicePort,CHAR *pContext);

//4，中心服务器模式用户检测回调
typedef int	 (*CenterCheckUserCallback)(INT bOnLine,DVS_MACHINE_TYPE machineType,UINT dwDeviceID,UINT dwChannelNum,UINT ip,USHORT port,CHAR *pszDeviceName,CHAR *pszUserName,CHAR *pszPassword,LPVOID pNetPar);

//5，搜索录像NVS回调
typedef void (*SearchRecNVSCallback)(CHAR *szNvsBuffer,int nBufferLen);

//6，搜索录像文件
//typedef void (WINAPI *SearchRecFileCallback)(void *pRecFile);
typedef void  (*SearchRecFileCallback)(UINT dwClientID,void *pRecFile);

//7，库消息回掉函数
typedef int	 (*MessageNotifyCallback)(UINT wParam, UINT lParam);

//8.搜索
typedef int (*CallbackServerFind)(DVS_MACHINE_TYPE nDeviceType,char *pDeviceName,
								char *pIP,unsigned char macAddr[6],unsigned short wPortWeb,unsigned short wPortListen,char *pSubMask,
								char *pGateway,char *pMultiAddr,char *pDnsAddr,unsigned short wMultiPort,int nChannelNum,int nFindCount,unsigned long dwDeviceID);


/******************************  四、接口结构类型定义  ***************************/
//2，音视频数据帧头
typedef struct _HV_FRAME_HEAD
{
	USHORT	zeroFlag;				// 0
	UCHAR   oneFlag;				// 1
	UCHAR	streamFlag;				// 数据帧标志 FRAME_FLAG_VP，FRAME_FLAG_VI，FRAME_FLAG_A
	
	ULONG	nByteNum;				//数据帧大小
	ULONG	nTimestamp;				//时间戳
}HV_FRAME_HEAD;

//3,报警输出
typedef struct _ALARM_STATUS_OUTPUT
{
	UCHAR			year;
	UCHAR			month;
	UCHAR			day;
	UCHAR			week;
	UCHAR			hour;
	UCHAR			minute;
	UCHAR			second;
	
	UCHAR	statusSensorAlarm;
	UCHAR	statusMotionAlarm;
	UCHAR	statusViLoseAlarm;
	UCHAR	SensorAlarmRec[MAX_SENSOR_NUM];
	UCHAR	MotionAlarmRec[MAX_VIDEO_NUM];
	UCHAR	ViLoseAlarmRec[MAX_VIDEO_NUM];
	UCHAR	statusAlarmOutput;
}ALARM_STATUS_OUTPUT;

//4，报警通知信息结构
typedef struct _ALARM_MSG_NOTIFY
{
	HANDLE					hLogonServer;
	UINT					dwClientID;
	UINT					dwServerIP;
	UINT					dwServerPort;
	ALARM_STATUS_OUTPUT		alarmStatus;
}ALARM_MSG_NOTIFY;

//98系列、58系列之后的设备里用以下结构

typedef struct _ALARM_STATUS_OUTPUT_NEW
{
unsigned char year;

unsigned char month;

unsigned char day;

unsigned char week;

unsigned char hour;

unsigned char minute;

unsigned char second;

unsigned char millsecond; 

unsigned int SensorAlarm;
unsigned int MotionAlarm;
unsigned int ViLoseAlarm;
unsigned int RFSensorAlarm;
unsigned int NetAlarm;

unsigned int SensorAlarmRec[MAX_SENSOR_NUM];
unsigned int MotionAlarmRec[MAX_VIDEO_NUM];
unsigned int ViLoseAlarmRec[MAX_VIDEO_NUM];
unsigned int RFSensorAlarmRec[MAX_RF_SENSOR_NUM];
unsigned int NetAlarmRec;

unsigned int OutputStatus;

unsigned int reserved[19];
}ALARM_STATUS_OUTPUT_NEW;

 

typedef struct _ALARM_MSG_NOTIFY_NEW
{
	HANDLE hLogonServer;

	UINT dwClientID;

	UINT dwServerIP;

	UINT dwServerPort;

	ALARM_STATUS_OUTPUT_NEW alarmStatus;
}ALARM_MSG_NOTIFY_NEW;


//5，触发抓拍图像
typedef struct _SENSOR_PIC_NOTIFY
{
	HANDLE					hLogonServer;
	UINT					dwClientID;
	UINT					dwServerIP;
	UINT					dwServerPort;
	//
	ALARM_STATUS_OUTPUT		alarmStatus;
	//
	UINT					dwChannelNo;
	UINT					dwPicLen;
	LPVOID					pPicBuffer;
}SENSOR_PIC_NOTIFY;

//6，串口采集数据
//串口设置
typedef struct __COM_CONFIG
{
	UINT 				Baudrate;						//串口波特率				300---115200
	UCHAR				Databit;						//串口数据位长度			5=5位 6=6位 7=7位 8=8位	其他=8位
	UCHAR				Stopbit;						//停止位位数				1=1位 2=2位 其他=1位
	UCHAR				CheckType;						//校验						0=无  1=奇  2=偶  3=恒1  4=恒0 
	UCHAR				Flowctrl; 						//软流控/硬流控/无流控		备用
}COM_CONFIG;
//透明通讯
typedef struct __COMM_CTRL
{
	UCHAR				COMMNo;							//串口号	0 ~ 1
	UCHAR				AD[3];
	
	COM_CONFIG			COMConfig;						//串口配置
	USHORT				DataLength;						//数据长度
	UCHAR				Data[256];						//数据
	UCHAR				AE[2];
}PACKED COMM_CTRL;
typedef struct _COMM_DATA_NOTIFY
{
	HANDLE					hLogonServer;
	UINT					dwClientID;
	UINT					dwServerIP;
	UINT					dwServerPort;
	COMM_CTRL				commCtrl;
}COMM_DATA_NOTIFY;

//7，打开视频通道参数
typedef struct _HHOPEN_CHANNEL_INFO
{
	UINT					dwClientID;
	UINT					nOpenChannel;
	NET_PROTOCOL_TYPE		protocolType;
	ChannelStreamCallback	funcStreamCallback;
	void					*pCallbackContext;
}HHOPEN_CHANNEL_INFO;

//这个结构合以前的结构大小完全相同，
//并且兼容以前的结构，实现对98系列和
//58系列主从码流的获取：

typedef struct _HHOPEN_CHANNEL_INFO_EX
{
        ULONG                 dwClientID;             //回调参数	(对应回调函数里的dwClientID)
        UINT                  nOpenChannel:8;         //通道号（0 ～ 3）
        UINT                  nSubChannel:8;          //0: 打开主码流      1: 打开从码流
        UINT                  res:16;                 //备用
        NET_PROTOCOL_TYPE     protocolType;           //连接方式（TCP、UDP、多播）  
        ChannelStreamCallback funcStreamCallback;     //音视频流数据回调函数 
        void                                          *pCallbackContext;   //回调参数2(对应回调函数里的pContext) 
}HHOPEN_CHANNEL_INFO_EX;

//8，打开视频通道参数
typedef struct _HHOPEN_VIEWPUSH_INFO
{
	UINT					dwClientID;
	UINT					nViewPushChannel;
	NET_PROTOCOL_TYPE		protocolType;
	HHAV_INFO				avInformation;
	//
	UINT					nMulticastAddr;
	UINT					nMulticastPort;
	//
	UINT					nScreenCount;
	UINT					nScreenIndex;
}HHOPEN_VIEWPUSH_INFO;

//9，打开的服务器信息

typedef struct _HH_SERVER_INFO
{
	HANDLE					hServer;
	CHAR					szServerIP[MAX_IP_NAME_LEN+1];
	UINT					nServerPort;
	CHAR					szDeviceName[DVS_NAME_LEN+1];
	UINT					nDeviceID;
	//
	CHAR					szUserName[USER_NAME_LEN+1];
	CHAR					szUserPassword[USER_PASSWD_LEN+1];
	//	
	UINT					dwClientID;
	//
	CONNECT_STATUS			logonStatus;
	UINT					nVersion;
	UINT					nLogonID;
	UINT					nPriority;
	UINT					nServerChannelNum;
	UINT					nLanguageNo;
	DVS_MACHINE_TYPE		nMachineType;
	INT						bPalStandard;
	UINT					nMulticastAddr;
	UINT					nMulticastPort;
	HHAV_INFO				avInformation[MAX_VIDEO_NUM];
}HH_SERVER_INFO;

/*
typedef struct _HH_SERVER_INFO
{
	HANDLE			hServer;
	char			szServerIP[128];
	UINT			nServerPort;
	char			szDeviceName[DVS_NAME_LEN+1];
	UINT			nDeviceID;
	//
	char			szUserName[USER_NAME_LEN+1];
	char			szUserPassword[USER_PASSWD_LEN+1];
	//
	DWORD			dwClientID;
	//
	CONNECT_STATUS	logonStatus;
	UINT			nVersion;
	UINT			nLogonID;
	UINT			nPriority;
	UINT			nServerChannelNum;
	UINT			nLanguageNo;
	DVS_MACHINE_TYPE nMachineType;
	BOOL			bPalStandard;
	UINT			nMulticastAddr;
	UINT			nMulticastPort;
	HHAV_INFO		avInformation[MAX_VIDEO_NUM];
}HH_SERVER_INFO;
*/
//10，打开的通道信息
typedef struct _HH_CHANNEL_INFO
{
	HANDLE					hOpenChannel;
	CHAR					szServerIP[MAX_IP_NAME_LEN+1];
	UINT					nServerPort;
	CHAR					szDeviceName[DVS_NAME_LEN+1];
	//
	CHAR					szUserName[USER_NAME_LEN+1];
	CHAR					szUserPassword[USER_PASSWD_LEN+1];
	//
	UINT					dwClientID;
	//
	CONNECT_STATUS			openStatus;
	UINT					nVersion;
	UINT					nOpenID;
	UINT					nPriority;
	UINT					nOpenChannelNo;
	UINT					nMulticastAddr;
	UINT					nMulticastPort;
	HHAV_INFO				avInformation;
	ENCODE_VIDEO_TYPE		encodeVideoType;
	//
	NET_PROTOCOL_TYPE		protocolType;
	ChannelStreamCallback	funcStreamCallback;
	void					*pCallbackContext;
	//
	UINT					dwDeviceID;	//V4.0 add
}HH_CHANNEL_INFO;

//11，打开的解码器输入通道信息
typedef struct _HH_VIEWPUSH_INFO
{
	HANDLE				hOpenChannel;
	CHAR				szServerIP[MAX_IP_NAME_LEN+1];
	UINT				nServerPort;
	CHAR				szDeviceName[DVS_NAME_LEN+1];
	//
	CHAR				szUserName[USER_NAME_LEN+1];
	CHAR				szUserPassword[USER_PASSWD_LEN+1];
	//
	UINT				dwClientID;
	//
	CONNECT_STATUS		openStatus;
	UINT				nVersion;
	UINT				nOpenID;
	UINT				nPriority;
	UINT				nOpenChannelNo;
	UINT				nMulticastAddr;
	UINT				nMulticastPort;
	HHAV_INFO			avInformation;
	ENCODE_VIDEO_TYPE	encodeVideoType;
	NET_PROTOCOL_TYPE	protocolType;
	//
	DVS_MACHINE_TYPE	nMachineType;
	UINT				dwChannelNum;	//解码器最大路数
}HH_VIEWPUSH_INFO;

//12，对讲的信息
typedef struct _HH_TALK_INFO 
{
	HANDLE				hServer;
	CHAR				szServerIP[MAX_IP_NAME_LEN+1];
	UINT				nServerPort;
	CHAR				szDeviceName[DVS_NAME_LEN+1];
	//
	CHAR				szUserName[USER_NAME_LEN+1];
	CHAR				szUserPassword[USER_PASSWD_LEN+1];
	//
	ULONG				version;	
	ULONG				nMachineType;
	//
	CONNECT_STATUS		logonStatus;
	//audio parameter
	UINT				nAudioEncodeType;
    UINT				nAudioChannels;
    UINT				nAudioBits;
    UINT				nAudioSamples;
}HH_TALK_INFO;

//13，语音广播的用户信息
typedef struct _HH_BROADCAST_USER
{
	HANDLE	hBroadcastUser;
	CHAR	szServerIP[MAX_IP_NAME_LEN+1];
	UINT	port;
	CHAR	szDeviceName[DVS_NAME_LEN+1];	
	CHAR	szUserName[USER_NAME_LEN+1];
	CHAR	szUserPassword[USER_PASSWD_LEN+1];
	//
	INT	bConnect;
	//SOCKET	hSock;
	//PVOID	pPar;
	//add v4.2
	UINT				machineType;
	ENCODE_VIDEO_TYPE	audioType;
}HH_BROADCAST_USER;

//14，转发视频服务器
typedef struct _HH_RELAY_NVS
{
	RELAY_TYPE			relayType;
	CHAR				szServerIP[MAX_IP_NAME_LEN+1];
	USHORT				wServerPort;
	CHAR				szDeviceName[DVS_NAME_LEN+1];
	UINT				dwChannelNo;
	UINT				dwCount;
}HH_RELAY_NVS;	

//15，百分比消息通知
typedef struct _HH_PERCENT_NOTIFY
{
	HANDLE				hLogon;
	UINT				dwClientID;
	UINT				dwPercent;
}HH_PERCENT_NOTIFY;

//16，视频文件参数
typedef struct _HHFILE_INFO
{
	CHAR                szFileName[MAX_PATH];
	CHAR				szServerIP[MAX_IP_NAME_LEN+1];
	USHORT				wServerPort;
	CHAR				szUserName[USER_NAME_LEN+1];
	CHAR				szUserPassword[USER_PASSWD_LEN+1];
	INT                	bRelay     ; // 此文件是否通过转发
}HH_FILE_INFO;

//17，打开视频文件参数
typedef struct _HHOPEN_FILE_INFO
{
	UINT				dwClientID  ;
	UINT				nOpenChannel;
	NET_PROTOCOL_TYPE	protocolType;
	CHAR				szDeviceName[DVS_NAME_LEN+1];
	HH_FILE_INFO        hhFile      ;       
	CHAR                szOpenMode[5];
	UINT				dwSocketTimeOut;
	
    // 输出
	UINT				dwFileSize;         // 文件大小
	UINT				dwStartTime;        // 播放开始时间(毫秒)
	UINT				dwEndTime;          // 播放结束时间(毫秒)
	
	UINT				nVideoEncodeType;	//视频编码格式
	UINT				nAudioEncodeType;	//音频编码格式	
}HHOPEN_FILE_INFO;

//18，启动搜索符合条件的NVS
typedef struct _HH_SEARCH_REC_NVS
{
	UINT				dwClientID  ;
	// 存储录像文件的条件
	CHAR                Date[11];// 条件1 录像日期 yyyy-mm-dd
    UCHAR               recType ;// 条件2 录像类型: 0-所有，1-报警，2-手动，3-定时
	
	//SearchRecNVSCallback	funcSearchRecNvsCallback;	
}HH_SEARCH_REC_NVS;

// 19，启动搜索符合条件的录像文件
typedef struct _HH_SEARCH_REC_FILE
{
	UINT				dwClientID  ;
	
	// 存储录像文件的条件
    CHAR                szDir[MAX_PATH]; // 条件1: " Datae\\Ip-NVS\\Camera\\"
	CHAR				szTime1[6];      // 条件2 时间段1 hh:mm
	CHAR				szTime2[6];      // 条件2 时间段2 hh:mm
    UCHAR               recType ;	     // 条件3 录像类型: 0-所有，1-报警，2-手动，3-定时
	
	SearchRecFileCallback	funcSearchRecFileCallback;
}HH_SEARCH_REC_FILE;

//20，转发查询
typedef struct _RELAY_QUERY_INFO
{
	UINT		dwSize;
	UINT		dwServerLogonNum;
	UINT		dwServerPreviewNum;
	UINT		dwServerTalkNum;
	UINT		dwServerBrdNum;
	UINT		dwClientLogonNum;
	UINT		dwClientPreviewNum;
	UINT		dwClientTalkNum;
	UINT		dwClientBrdNum;
	CHAR		reserve[16];
}RELAY_QUERY_INFO;

typedef INT  (*StreamWriteCheck)(int nOperation,const CHAR *pUserName,const CHAR *pPsw,ULONG ip,ULONG port,HHOPEN_VIEWPUSH_INFO viewPushInfo,HANDLE hOpen);

/********************************  五、函数接口定义  *****************************/

//启动服务
HHERR_CODE		HHNET_Startup(unsigned short nBasePort, MsgNotifyCallback msgCallback,CheckUserPsw checkUserPswCallback,ServerUpdateFile updateCallback,ServerMsgReceive msgCmdCallback,StreamWriteCheck streamWriteCheckCallback,ChannelStreamCallback funcChannelCallback);
//关闭服务
HHERR_CODE		HHNET_Cleanup();

//登录服务器
HHERR_CODE		HHNET_LogonServer(IN  CHAR *pServerIP,IN  UINT nServerPort,IN  CHAR *pDeviceName,IN	 CHAR *pUserName,IN	 CHAR *pUserPassword,IN UINT dwClientID,OUT  HANDLE *hLogonServer);
//注销服务器
HHERR_CODE		HHNET_LogoffServer(IN  HANDLE hServer);
//读取登录服务器信息
HHERR_CODE		HHNET_ReadServerInfo(IN  HANDLE hServer,OUT  HH_SERVER_INFO *serverInfo);

//程序升级
HHERR_CODE		HHNET_Update(IN HANDLE hServer,IN UPDATE_TYPE nUpdateType,IN CHAR *pFilePathName);


//读取登录服务器配置信息
HHERR_CODE		HHNET_GetServerConfig(IN  HANDLE hServer,IN  HHCMD_NET nConfigCommand,OUT  CHAR *pConfigBuf,IN OUT  UINT *nConfigBufSize,IN  OUT  UINT *dwAppend);
//设置登录服务器配置信息
HHERR_CODE		HHNET_SetServerConfig(IN  HANDLE hServer,IN  HHCMD_NET nConfigCommand,IN   CHAR *pConfigBuf,IN  UINT nConfigBufSize,IN  UINT dwAppend);


//打开视频通道
HHERR_CODE		HHNET_OpenChannel(IN  CHAR *pServerIP,IN  UINT nServerPort,IN  CHAR *pDeviceName,IN  CHAR *pUserName,IN  CHAR *pUserPassword,IN  HHOPEN_CHANNEL_INFO *pOpenInfo,OUT  HANDLE *hOpenChannel);
//关闭视频通道
HHERR_CODE		HHNET_CloseChannel(IN  HANDLE hOpenChannel);

//读取打开视频通道信息
HHERR_CODE		HHNET_ReadChannelInfo(IN  HANDLE hOpenChannel,OUT  HH_CHANNEL_INFO *channelInfo);


//请求打开对讲
HHERR_CODE		HHNET_TalkRequsest(IN  char *pServerIP,IN  UINT nServerPort,IN  char *pDeviceName,IN	 char *pUserName,IN	 char *pUserPassword,IN TalkStreamCallback funcTalkCallback,IN void *pContext, OUT  TALKHANDLE *hTalkback);
//结束对讲
HHERR_CODE		HHNET_TalkStop();

//读取打开对讲信息
HHERR_CODE		HHNET_TalkReadInfo(HH_TALK_INFO *talkInfo);
//发送对讲数据
HHERR_CODE		HHNET_TalkSend(IN  TALKHANDLE hTalkback, IN char *pTalkData,IN UINT nDataLen);


//搜索网上设备
/*HHERR_CODE		HHNET_SearchAllServer(UINT nTimeWait,
														  void( *CallbackServerFind)(DVS_MACHINE_TYPE nDeviceType,CHAR *pDeviceName,
														  CHAR *pIP,UCHAR macAddr[6],USHORT wPortWeb,USHORT wPortListen,CHAR *pSubMask,
														  CHAR *pGateway,CHAR *pMultiAddr,CHAR *pDnsAddr,USHORT wMultiPort,int nChannelNum));
*/
HHERR_CODE	 HHNET_SearchAllServer(UINT dwTimeWait,CallbackServerFind serFindCallback);

//设置视频服务器网络配置
HHERR_CODE		HHNET_ConfigServer(UCHAR macAddr[6],CHAR *pUserName,CHAR *pUserPassword,
													   CHAR *pIP,CHAR *pDeviceName,CHAR *pSubMask,CHAR *pGateway,CHAR *pMultiAddr,
													   CHAR *pDnsAddr,USHORT wPortWeb,USHORT wPortListen,USHORT wPortMulti);


void HHNET_UpdatePercentNotify(int hsock,ULONG nPercent);


/************************  六、数字视频服务器的配置信息结构  **********************/

//------------------------------(I)编码器参数设置结构-----------------------------//
//1，日期时间结构
typedef  struct  _DVS_DATE
{
	UCHAR		year;									//年
	UCHAR		month;									//月
	UCHAR		day;									//日
	UCHAR		week;									//周
	UCHAR		hour;									//小时
	UCHAR		minute;									//分钟
	UCHAR		second;									//秒
}PACKED DVS_DATE;

//2，时间段结构：定义一天的起始时间和结束时间
typedef struct _TIME_SEGMENT
{
	UCHAR 		bDetectOpen;							//检测开关
	UCHAR        nBgnHour ;								//开始时
	UCHAR        nBgnMinute ;							//开始分
	UCHAR        nEndHour ;								//结束时
	UCHAR        nEndMinute ;							//结束分
}PACKED TIME_SEGMENT;

//3，音频设置
typedef struct _AUDIO_CONFIG
{
	UCHAR		Open:1;									//音频是否打开
	UCHAR		MicOrLine:1;							//音频输入模式：麦克或线输入
	UCHAR		resver:6;
	UCHAR		Type;
	UCHAR		AD[2];
				//压缩格式
	UINT		Bitrate ;								//码率
	UINT		SampleBitrate ;
}PACKED AUDIO_CONFIG;

//4，视频设置
typedef struct _VIDEO_CONFIG
{	
	UINT		KeyInterval;							//I 帧间隔
	UINT		Bitrate ;								//码率
	UCHAR		Qulity;									//质量1--31
	UCHAR		AD[3];	
	
	float		FrameRate ;								//帧率
	UCHAR		BitflowType; 							//码流类型 		   0:VBR,1:CBR
	
	UCHAR		DateOSD; 								// 0:不叠加日期,   1:叠加日期 
	UCHAR		TimeOSD; 								// 0:不叠加时间,   1:叠加时间 
	UCHAR		WeekOSD; 								// 0:不叠加星期,   1:叠加星期 
	UCHAR		TitleOSD;								// 0:不叠加标题,   1:叠加标题 
	UCHAR		BitrateOSD;								// 0:不叠加码率,   1:叠加码率 	
	CHAR    	Title[CAM_TITLE_LEN+ 1];				// 标题字符        16个字符  8个汉字
	
	UCHAR 		Brightness;								//亮度
	UCHAR 		Hue;									//色调
	UCHAR 		Saturation;								//饱和度
	UCHAR 		Contrast;								//对比度
	UCHAR 		Protocol;								//协议
	UCHAR 		YTAddr;									//解码器地址
	UCHAR 		AE[3];
}PACKED VIDEO_CONFIG;

//5，移动侦测设置
typedef struct _VIDEO_MOTION_CONFIG
{
	UCHAR 		DetectLevel;							//移动检测灵敏度
	UCHAR 		DetectOpen;								//移动检测开关
	USHORT 		AutoClearTime;							//移动报警自动清除时间	
	UCHAR 		Output;									//移动报警联动输出				 0---3	
	UCHAR 		Record;									//移动报警联动录像				 0---3	
	UCHAR 		DetectTest;								//移动报警检测测试开关
	UCHAR 		AD[1];
	UINT 		DetectArea[18];							//移动检测区域	
	TIME_SEGMENT	tSchTable[8] ;						//移动检测时间表1				 0: 每天
}PACKED VIDEO_MOTION_CONFIG;

//6，图像屏蔽设置
typedef struct _VIDEOMASK_CONFIG 
{
	UCHAR 		MaskOpen;								//视频屏蔽开关		0:关         1：开
	UCHAR		AD[3];
	UINT 		MaskArea[18];							//视频屏蔽区域	
}PACKED VIDEOMASK_CONFIG;

//7，视频丢失设置
typedef struct _VIDEOLOSE_CONFIG
{
	UCHAR		DetectOpen;								//视频丢失检测
	UCHAR 		Output;									//视频丢失报警联动输出			 0---3		
	UCHAR 		Record;									//视频丢失联动录像				 0---3	
	UCHAR		AD[1];
	USHORT		AutoClearTime;							//视频丢失报警自动清除时间
}PACKED VIDEOLOSE_CONFIG;

//8，探头报警侦测设置
typedef struct _SENSOR_CONFIG 
{
	UCHAR		SensorType;								//0:常开探头	1:常闭探头
	UCHAR 		DetectOpen;								//检测开关
	USHORT 		AutoClearTime;							//探头报警自动清除时间	
	UCHAR 		Output;									//探头报警联动输出				 0---3	
	UCHAR 		Record;									//探头报警联动录像				 0---3	
	TIME_SEGMENT	tSchTable[8] ;						//探头检测时间表1				 0: 每天
}PACKED SENSOR_CONFIG;

//9，用户设置
typedef struct _USER_CONFIG
{
	UINT 		Level;									//权限
	CHAR 		Name[USER_NAME_LEN + 1];				//用户名
	CHAR 		Password[USER_PASSWD_LEN + 1];			//用户密码
	CHAR 		AD[2];
} PACKED USER_CONFIG;

//10，网络设置结构
typedef struct _NET_CONFIG
{	
	UINT             	IPAddr ;						//IP地址
	UINT             	SubNetMask ;					//掩码
	UINT             	GateWay ;						//网关

   	USHORT             	ComPortNo;						//设置接收客户端命令端口号        UDP	
   	USHORT             	WebPortNo;						//Webserver端口     			  TCP
	UINT             	MultiCastIPAddr ;				//多播IP地址
   	USHORT             	MultiCastPortNo;				//UDP传输起始端口<多播传输>
	
	UCHAR			   	RT8139MAC[6];      				//人工设置网卡的MAC地址		5---0有效
   	UCHAR             	DHCP;							//DHCP 开关					0	关		1:开
   	
	UCHAR             	PppoeOpen;						//PPPOE 开关     	
	CHAR				PppoeName[PPPPOE_NAME_LEN+1];	//拨号用户名
	CHAR				PppoePass[PPPPOE_PASSWD_LEN+1]; //拨号密码	
	UINT             	PppoeTimes;   					//在线时间
	UINT             	PppoeIPAddr ;					//PPPOEIP地址		报警回传IP	
	
	UINT				DdnsOpen;						//DDNS开关
	CHAR				DdnsName[DDNS_NAME_LEN+1];		//注册主机名称
	CHAR				DdnsPass[DDNS_PASS_LEN+1];		//注册主机密码	
	
	CHAR				DdnsIP[DDNS_SERVER_NAME_LEN+1];	//DDNS服务器
	CHAR				AAD[1];
	USHORT				DdnsPortNo;						//DDNS服务器端口
	USHORT				DdnsMapWebPort;					//本地WEB映射端口
	USHORT				DdnsMapDataPort;				//本地数据映射端口
	CHAR				ABD[2];

	UINT				DNSHostIP;						//DNS的IP

	INT					ConnectCenter;					//是否主动连接中心
	CHAR				ConnectCenterIP[DDNS_SERVER_NAME_LEN+1];//中心IP
	CHAR				ACD[1];
	USHORT				ConnectCenterPort;						//中心端口

	USHORT				appFunction;					//实现功能定义,以bit位表示:0-PPPOE,1-NTP,2-UPNP,3-WF,4-MAIL,5-定向发送
	UCHAR				tcpSendInterval;
	UCHAR				udpSendInterval;
	USHORT				PacketMTU;

	UCHAR				CaptureMode;					//抓拍模式
	UCHAR				CapturePort[MAX_SENSOR_NUM];	//抓拍通道(0-3bit: 分别表示1 ~ 4号通道  1:开  0: 关)
	CHAR				AED[1];
	union
	{
	  UINT       DdnsIP2;						
 	  UINT       DNSHostIP2;						
	};						//DDNS 2的IP,非网络字节次序
	USHORT				DdnsPortNo2;					//DDNS 2的端口

	CHAR				sysByname[DVS_NAME_LEN+1];		//域名
	UCHAR				domainSetState;					//0－成功；1－名字存在，修改新域名；2－正在申请；3－失败
}PACKED NET_CONFIG;


/**************************************************************************
2011.5.22苗瑞加入3G参数的数据结构
***************************************************************************/
typedef struct _3G_NET_CONFIG_S
{
	unsigned char      nSize;
	unsigned char       n3gOpen;					//3g 开关
	unsigned char       n3gType;					//3g 类型 0 evdo 1 wcdma 2 td
	unsigned char       n3gSecType;				    //3g 验证类型  0 自动选择 1 pap 2 chap
	unsigned char       n3gParam;		            //标记要用哪些参数 
	char        		sz3gUsr[32];				//3g 拨号用户名			
	char        		sz3gPsw[32];				//3g 拨号密码
	char        		sz3gApn[32];				//3g apn 
	char        		sz3gTelNum[16];           	//3g 拨号号码
	char        		sz3gLocalIp[16];
	char        		sz3gRemoteIp[16];
	char        		sz3gPara1[16];
	char        		sz3gPara2[16];
	unsigned char       res[16]; 
}PACKED T3G_NET_CONFIG_S;//200字节


typedef struct _HH_3G_INFO_S
{
	unsigned char 	  moduleExits;   // 1 module exits else 0
	unsigned char     moduleStatus;  // 1 ok else 0
	unsigned char     simExits;      // 1 umi exits  else 0
	unsigned char     sigal;         // 
	unsigned char     serviceStatus; // srv status 
	// 0 no srv status
	// 1 a restrict srv status
	// 2 a good srv
	// 3 a restrict district srv
	// 4 sleep status
	unsigned char     roamStatus;    // 0 not roam 1 roam
	unsigned char     networkType ;  // 0 not service
	// 1 AMPS
	// 2 CDMA
	// 3 GSM/GPRS
	// 4 HDR
	// 5 WCDMA
	// 6 GPS
	// 7 GSM/WCDMA
	// 8 CDMA/HDR HYBIRD
	unsigned char     refresh      ;
	unsigned char     initModule   ;
	unsigned char     initDail	   ;
	unsigned char	  c3gstatus	   ;// 3G状态
	unsigned char     res          ;// 拨号失败次数,可以不使用
	char      softWareVer[128];   // software version
	char      hardWareVer[128];   // hardware version
	char      moduleType[32] ;   // module type
}PACKED HH_3G_INFO_S, *PHH_3G_INFO_S;

// 3G拨号限制模式   0-不限制 1-每天限制时间  2-每月限制时间  3-既限制每天的时间，也限制每月的时间
typedef enum T3G_TIME_CTRL_MODE
{
	NO_LIMITED    = 0x00,
	DAY_LIMITED   = 0x01,
	MONTH_LIMITED = 0x02,
	ALL_LIMITED   = 0x03,
}T3G_TIME_CTRL_MODE;// 限制模式


/**************************************************************************
2011.11.3苗瑞加入视频参数定义的数据结构
***************************************************************************/
//视频输入的色彩调节和相关设置，类型定义
typedef enum _VIDEO_IN_SENSOR_E
{
	//色彩
	VCT_BRIGHTNESS	=	0X00000001,//亮度
	VCT_HUE			=	0X00000002,//色度
	VCT_CONTRAST	=	0X00000004,//对比度
	VCT_SATURATION	=	0X00000008,//饱和度
	VCT_SHARPNESS	=	0X00000010,//锐度
	VCT_RED			=	0X00000020,//红色
	VCT_GREEN		=	0X00000040,//绿色
	VCT_BLUE		=	0X00000080,//蓝色
	VCT_GAMMA		=	0X00000100,//Gamma

	//白平衡
	VCT_AUTOAWB		=	0X00000200,//自动白平衡
	VCT_AWBRED		=	0X00000400,//白平衡 红
	VCT_AWBGREEN	=	0X00000800,//白平衡 绿
	VCT_AWBBLUE		=	0X00001000,//白平衡 蓝

	//增益
	VCT_AUTOAGC		=	0X00002000,//自动增益
	VCT_AGCLEVEL	=	0X00004000,//增益值

	//背光补偿
	VCT_AUTOBLC		=	0X00008000,//自动补偿
	VCT_BLCLEVEL	=	0X00010000,//补偿值
	
	//曝光
	VCT_AUTOEXPOSURE=	0X00020000,//自动曝光 
	VCT_EXPOSURETIME=	0X00040000,//手动曝光时间 
	
	//快门
	VCT_SHUTTERFIRST=	0X00080000,//快门、曝光优先
	VCT_AUTOSHUTTER	=	0X00100000,//自动快门
	VCT_SHUTTERSPEED=	0X00200000,//快门速度
	VCT_SLOWSHUTTER	=	0X00400000,//慢快门
	VCT_SLOWSHUTTERLEVEL=0X00800000,//慢快门速度

	VCT_AUTOAWBMODE =	0X01000000,//1080p Hispeed自动白平衡模式

	VCT_SENSOR_ALL	=	0xFFFFFFFF,//设置所以参数
}VIDEO_IN_SENSOR_E;

//视频输入场景设置，类型定义
typedef enum _VIDEO_IN_SCENE_E
{
	//光圈
	VCT_AUTOIRIS	=	0X00000001,//自动光圈
	VCT_IRISLEVEL	=	0X00000002,//光圈电平

	//聚焦
	VCT_AUTOFOCUS	=	0X00000004,//自动聚焦
	VCT_FOCUSLEVEL	=	0X00000008,//焦距

	//变倍
	VCT_ZOOMSPEED	=	0X00000010,//变倍速度
	VCT_AUTOPTZSPEED=	0X00000020,//景深比例变速

	//电平控制
	VCT_AUTOALC		=	0X00000040,//自动电平控制
	VCT_ALCLEVEL	=	0X00000080, //电平控制值
	
	//彩转黑
	VCT_CTB			=	0X00000100,//彩转黑

	//场景
	VCT_SCENE		=	0X00000200,//场景
	VCT_MIRROR		=	0X00000400,//镜向
	VCT_FLIP		=	0X00000800,//翻转
	VCT_AUTOFLIP	=	0X00001000,//自动翻转
	VCT_PWDFREQ1	=	0X00002000,//照明频率1
	VCT_PWDFREQ2	=	0X00004000,//照明频率2

	//红外
	VCT_IREXIST		=	0X00008000,//是否有红外
	VCT_IRCFMODE	=	0X00010000,//IRCF模式
	VCT_IRLIGHTTYPE	=	0X00020000,//红外灯类型
	//
	VCT_WDR 		=	0X00040000,//是否有宽动态
	VCT_WDRLEVEL	=	0X00080000,//宽动态的值
	VCT_LOWILLUM	=	0X00100000,//低照度
	VCT_IMAGEMODE	=	0X00200000,//图像模式
	//
	VCT_VI_SIZE     =   0X00400000,//视频输入尺寸
	VCT_CTBLEVEL	=	0X00800000,//彩转黑阀值，当彩转黑为自动时有效
	VCT_MINFOCUSLEN =   0X01000000,//设置最小聚焦距离
	VCT_IRLEVEL		=   0X02000000,//夜间启动点		
	VCT_LENSCORRECTION =0X04000000,//镜头校正		
	VCT_SMARTNR     = 	0x08000000,//智能降噪 0 ~ 255  0为关
	VCT_3DNR   	    =	0X10000000,//3D降噪		
	VCT_3DNRLEVEL	= 	0x20000000,//3D降噪值

	VCT_SCENE_ALL	=	0xFFFFFFFF,//设置所以参数
}VIDEO_IN_SCENE_E;

//视频输入的色彩调节和相关设置 size=64+32=96
typedef struct _VIDEO_IN_SENSOR_S
{
	VIDEO_IN_SENSOR_E	eValidSupport;	/*有效支持的参数，该参数设置时候无效
											在获取的时候有效，用以判断设备是否支持该参数
										*/

	VIDEO_IN_SENSOR_E	eValidSetting;	/*设置有效的参数，该参数获取时候无效
											在设置的时候有效，用以指定具体设置的参数
										*/

	//色彩
	UInt8		byBrightness;		/*亮度;			0 ~ 255*/
	UInt8		byBrightnessDefault;/*亮度缺省值;	*/
	UInt8		byBrightnessStep;	/*亮度调节步长;	*/

	UInt8		byHue;				/*色度;			0 ~ 255*/
	UInt8		byHueDefault;		/*色度缺省值;	*/
	UInt8		byHueStep;			/*色度调节步长;	*/
	
	UInt8		byContrast;			/*对比度;	0 ~ 255*/
	UInt8		byContrastDefault;	/*对比度缺省值;	0 ~ 255*/
	UInt8		byContrastStep;		/*对比度调节步长;	0 ~ 255*/

	UInt8		bySaturation;		/*饱和度;	0 ~ 255*/
	UInt8		bySaturationDefault;/*饱和度缺省值;*/
	UInt8		bySaturationStep;	/*饱和度调节步长;*/

	UInt8		bySharpness;		/*锐度;		0 ~ 255*/
	UInt8		bySharpnessDefault;	/*锐度缺省值;*/
	UInt8		bySharpnessStep;	/*锐度调节步长;*/

	UInt8		byRed;				/*红色;		0 ~ 255*/
	UInt8		byRedDefault;		/*红色缺省值;*/
	UInt8		byRedStep;			/*红色调节步长;*/

	UInt8		byGreen;			/*绿色;		0 ~ 255*/
	UInt8		byGreenDefault;		/*绿色缺省值;*/
	UInt8		byGreenStep;		/*绿色调节步长;*/

	UInt8		byBlue;				/*蓝色;		0 ~ 255*/
	UInt8		byBlueDefault;		/*蓝色缺省值;*/
	UInt8		byBlueStep;			/*蓝色调节步长;*/

	UInt8		byGamma;			/*gamma;	0 ~ 255*/
	UInt8		byGammaDefault;		/*gamma缺省值;*/
	UInt8		byGammaStep;		/*gamma调节步长;*/


	//白平衡
	UInt8		byAutoAwb;			/*自动白平衡;	0自动, 1 手动*/
	
	UInt8		byAwbRed;			/*白平衡 红;	0 ~ 255*/
	UInt8		byAwbRedDefault;	/*白平衡 红缺省值;*/
	UInt8		byAwbRedStep;		/*白平衡 红调节步长;*/

	UInt8		byAwbGreen;			/*白平衡 绿;	0 ~ 255*/
	UInt8		byAwbGreenDefault;	/*白平衡 绿缺省值;*/
	UInt8		byAwbGreenStep;		/*白平衡 绿调节步长;*/

	UInt8		byAwBblue;			/*白平衡 蓝;	0 ~ 255*/
	UInt8		byAwBblueDefault;	/*白平衡 蓝缺省值;*/
	UInt8		byAwBblueStep;		/*白平衡 蓝调节步长;*/

	//2011.6.20 高清高速球   1080P   byAgcLevel --> 最大增益值
	//						  720P   byAgcLevel --> AGC
	//							     byAutoAgc  --> 最大增益值
 	//增益
	UInt8		byAutoAgc;			/*自动增益;		0自动, 1 手动*/
	UInt8		byAgcLevel;			/*增益值;		0 ~ 255*/
	UInt8		byAgcLevelDefault;	/*增益值缺省值;*/
	UInt8		byAgcLevelStep;		/*增益值调节步长;*/


	//背光补偿
	UInt8		byAutoBlc;			/*自动补偿;		0自动, 1 手动*/
	UInt8		byBlcLevel;			/*补偿值;		0 ~ 255*/
	UInt8		byBlcLevelDefault;	/*补偿值缺省值;*/
	UInt8		byBlcLevelStep;		/*补偿值调节步长;*/
	

	//曝光
	UInt8		byAutoExposure;		/*0自动 1 手动*/
	UInt16		wExpoSuretime;		/*手动曝光时间	F1.6=16
													F2.2=22
													F3.2=32
													F4.4=44
													F6.4=64
													F8.8=88
													F12.0=120
													F17.0=170
													F24.0=240
													F34.0=340
									*/


	//快门
	UInt8		byShutterFirst;		/*快门、曝光优先;	0快门优先, 1 曝光优先*/
	UInt8		byAutoShutter;		/*自动快门;		0自动, 1 固定*/
	UInt16		wShutterSpeed;		/*快门速度;		1		= 1
													1/2		= 2
													1/4		= 4
													1/8		= 8
													1/16	= 16
													1/25	= 25
													1/50	= 50
													1/100	= 100
													1/150	= 150
													1/200	= 200
													1/250	= 250
													1/300	= 300
													1/400	= 400
													1/1000	= 1000
													1/2000	= 2000
													1/4000	= 4000
													1/10000	= 10000
										*/
	UInt8		bySlowShutter;				/*慢快门;		0关,   1 开*/

	UInt8		bySlowShutterLevel;			/*慢快门速度;	0 ~ 255*/
	UInt8		bySlowShutterLevelDefault;	/*慢快门速度缺省值;*/
	UInt8		bySlowShutterLevelStep;		/*慢快门速度调节步长;*/

	UInt8		byAwbAutoMode;	//自动白平衡模式,仅当白平衡为自动时有效
	UInt8		byRes[31];
}VIDEO_IN_SENSOR_S,*LPVIDEO_IN_SENSOR_S;

//视频输入场景相关设置 size=32+64=96
typedef struct _VIDEO_IN_SCENE_S
{
	VIDEO_IN_SCENE_E	eValidSupport;/*有效支持的参数，该参数设置时候无效
											在获取的时候有效，用以判断设备是否支持该参数
										*/

	VIDEO_IN_SCENE_E	eValidSetting;/*设置有效的参数，该参数获取时候无效
											在设置的时候有效，用以指定具体设置的参数
										*/


	//光圈
	UInt8		byAutoIris;			/*自动光圈;		0自动, 1 手动*/

	UInt8		byIrisLevel;		/*光圈电平;			0 ~ 255*/
	UInt8		byIrisLevelDefault;	/*光圈电平缺省值;*/
	UInt8		byIrisLevelStep;	/*光圈电平调节步长;*/


	//聚焦
	UInt8		byAutoFocus;		/*自动聚焦;		0自动, 1 手动*/

	UInt8		byFocusLevel;		/*焦距;				0 ～ 255*/
	UInt8		byFocusLevelDefault;/*焦距缺省值;*/
	UInt8		byFocusLevelStep;	/*焦距调节步长;*/


	//变倍
	UInt8		byZoomSpeed;		/*变倍速度;		0 高速,  1 正常速度*/
	UInt8		byAutoPtzSpeed;		/*景深比例变速; 0关,   1 开*/


	//电平控制
	UInt8		byAutoAlc;			/*自动电平控制;	AutoALC	0自动 1 手动*/

	UInt8		byAlcLevel;			/*电平值;			ALC Level	0 ~ 255*/
	UInt8		byAlcLevelDefault;	/*电平缺省值;		ALC Level	*/
	UInt8		byAlcLevelStep;		/*电平值调节步长;	ALC Level	*/


	//彩转黑
	UInt8		byCtb;				/*彩转黑;		0关,   1 开*/


	//场景
	UInt8		byScene;			/*场景;			0 ~ 255*/
	UInt8		byMirror;			/*镜向;			0关,   1 开*/
	UInt8		byFlip;				/*翻转;			0关,   1 开*/
	UInt8		byAutoFlip;			/*自动翻转;		0关,  1 开*/
	UInt8		byPwdFreq1;			/*照明频率1;	0 60HZ,	1 50HZ*/
	UInt8		byPwdFreq2;			/*照明频率2;	0 60HZ,	1 50HZ,	2 户外*/


	//红外
	UInt8		byIRExist;			/*是否有红外	0无,   1 有*/
	UInt8		byIRCFMode;			/*IRcf模式;		0 OUT=>IN, 1 IN=>OUT*/
	UInt8		byIRLightType;		/*红外灯类型;	0 正常光,  1 850mm,   2 950mm*/
	UInt8		byWDR;				/*宽动态		0无,   1 有*/
	UInt8		byWDRLevel;			/*宽动态		0 ~ 255*/
	UInt8		byLowIllumination;	/*低照度		1默认AF
													2低照度AF优化开启
													3低照度点光源AF优化开启
									*/
	UInt8		byImageMode;		/*图像模式		0 模式 1，  1 模式 2 */

	UInt16      u16ViWidth;         /*视频输入 宽度*/
	UInt16		u16ViHeight;        /*视频输入 高度*/
	UInt8		byCtbLevel;			/*彩转黑阀值，自动彩转黑时有效*/
	UInt8		byMinFocusLen;		/*设置最小聚焦距离*/			  
	UInt8		byIRLevel;			/*夜间启动点 */		          
	UInt8 		byLensCorrection; 	/*镜头校正	0: 关	1：开  */ 
	UInt8       bySmartNR;			//智能降噪  0 ~ 255 0: 关 
	UInt8       bySmartNRDefault;	//智能降噪  默认值 
	UInt8 		by3DNR; 			/*3D 降噪   0: 关	1：开  */  
	UInt8       by3DNRLevel;		//3D降噪值 2011.6.15 miaor
	UInt8		byRes[48];			//2011.6.20 CYG
}VIDEO_IN_SCENE_S,*LPVIDEO_IN_SCENE_S;

//视频输入的所有色彩调节和场景设置
//大小196(sizeof(VIDEO_IN_CFG_S))
typedef struct _VIDEO_IN_CFG_S
{
	UInt32				dwSize;		    /*结构大小*/
	VIDEO_IN_SENSOR_S	struViSensor;	/*视频输入设置*/
	VIDEO_IN_SCENE_S	struViScene;	/*视频输入场景相关设置*/
}VIDEO_IN_CFG_S,*LPVIDEO_IN_CFG_S;

typedef struct _TIME_SEGMENT_NEW 
{
	UINT 		bDetectOpen;				//检测开关
	UCHAR        nBgnHour ;					//开始时
	UCHAR        nBgnMinute ;				//开始分
	UCHAR        nEndHour ;					//结束时
	UCHAR        nEndMinute ;				//结束分
}TIME_SEGMENT_NEW;

typedef struct _T3G_TIME_CTRL_S			// 20101125 结构调整,实现字节对齐
{
	BYTE		t3gtimectrlopen;			// 3G拨号限时是否开启 0-关闭  1-开启
	BYTE		t3gdaylimitedend;			// 标志位-每天限时拨号     0-未到  1-已到
	BYTE		t3gmonthlimitedend;			// 标志位-每月限时拨号   0-未到  1-已到
	BYTE		t3gdaylimited;				// 限制每天拨号时长   0-不限制
	T3G_TIME_CTRL_MODE	t3gtimectrlmode;	// 3G时间限制模式
	DWORD		t3gdialusedtime;			// 已经拨号时间
	DWORD		t3gmonthlimited;			// 限制每月拨号时长   0-不限制
	BYTE		t3openlimitedmonth;			// 初次设定限时的月份
	BYTE		t3openlimitedday;			// 初次设定限时的号数
	BYTE		revers[2];					// 字节对齐
	TIME_SEGMENT_NEW	t3gtimesegment[4];	// 定义每天4个可设定时间段
}PACKED T3G_TIME_CTRL_S;					// 50个字节 = 1+4+4+1+1+1+4+1+1+4*(4+4)



typedef struct _T3Ginfo_S
{
	T3G_NET_CONFIG_S  t_3ginfo;
	T3G_TIME_CTRL_S   t_3gTime;
	HH_3G_INFO_S	  t_3ginfo1;
}T3Ginfo_S;


//12，调试信息开关
typedef struct _DEBUG_CONFIG
{
	UCHAR				Status;							//0：关		1: 开
}DEBUG_CONFIG;

//13，输出继电器控制
typedef struct __OUTPUT_CTRL
{
	UCHAR				ChannelNo;						//继电器号	0 ~ MAX_OUTPUT_NUM - 1
	UCHAR				Status;							//0：关		1: 开	
}OUTPUT_CTRL;


//14，云台控制
typedef struct __PAN_CTRL
{
	UCHAR				ChannelNo;						//通道号	0 ~ PORTNUM - 1
	UCHAR				COMMNo;							//串口号	0 ~ 1
	UCHAR				PanType;						//云台协议序号 0 ~ YUNTAI_PROTOCOL_NUM - 1
	UCHAR				PanCmd;							//云台控制命令
	UCHAR				Data1;							//数据1		（预置、调用号）
	UCHAR				Data2;							//数据2		（备用）
}PAN_CTRL;

//16，视频信号参数
typedef struct __VIDEO_SIGNAL_CONFIG
{
	UCHAR				ChannelNo;						//通道号	0 ~ PORTNUM - 1
	UCHAR 				ChannelNum;						//通道数<NVS总的通道数，因为单路、四路的参数默认值是不同的>
	UCHAR 				Brightness;						//亮度
	UCHAR 				Hue;							//色调
	UCHAR 				Saturation;						//饱和度
	UCHAR 				Contrast;						//对比度
}VIDEO_SIGNAL_CONFIG;

//17，TW2824参数
typedef struct _TW2824_CTRL
{
	UCHAR				Page;							//页
	UCHAR 				RegNo;							//寄存器
	UCHAR 				Data;							//数据
	UCHAR				AD[1];
	UINT				nReserved[8];					//保留
}TW2824_CTRL;

//18，报警信息
typedef  struct  _ALARM_INFO
{
	UCHAR	SensorAlarm[MAX_SENSOR_NUM];				//探头报警
	UCHAR	SensorAlarmOut[MAX_SENSOR_NUM];				//探头报警输出
	UCHAR	MotionAlarm[MAX_VIDEO_NUM];					//视频移动
	UCHAR	MotionAlarmOut[MAX_VIDEO_NUM];				//视频移动报警输出
	UCHAR	ViLoseAlarm[MAX_VIDEO_NUM];					//视频丢失
	UCHAR	ViLoseAlarmOut[MAX_VIDEO_NUM];				//视频丢失报警输出
} ALARM_INFO;

//19，云台信息
typedef struct _YUNTAI_INFO
{
	CHAR 		Name[YUNTAI_NAME_LEN + 1];				//云台名称
	CHAR 		AD[3];
	COM_CONFIG	ComSet;									//通讯协议<波特率...>
}PACKED YUNTAI_INFO;

//20，配置信息
typedef struct _DVS_CONFIG
{
   	CHAR               	sysName[DVS_NAME_LEN + 1];		//名字
	UCHAR				sysInputNum;					//路数
	UCHAR				sysType;						//机器型号	0:CIF  1:HD1  2:D1  
	UCHAR				sysVideoFormat;					//编码格式	
    UCHAR				sysLanguage;					//语言
    UCHAR				sysStandard;					//制式		0:PAL  1:NTSC
    UCHAR				AD[2];
	UINT      			sysID;  						//每台机器有个ID号  	
	UINT      			sysVer;  						//软件版本  		
}PACKED DVS_CONFIG;

//21，登录的用户用户信息
typedef struct _USER_DETAIL
{
	INT					bLogon;							//TRUE-登陆用户,FALSE-预览用户
	UINT 				Level;							//权限
	CHAR 				Name[USER_NAME_LEN+1];			//用户名
	CHAR 				Password[USER_PASSWD_LEN+1];	//用户密码
	NET_PROTOCOL_TYPE	protocolType;					//协议
	UINT				clientIP;						//IP
	UINT				clientPort;						//端口
}PACKED4 USER_DETAIL;
typedef struct _USER_INFO
{
	UINT				dwLogonNum;
	UINT				dwPreviewNum;
	USER_DETAIL			userDetail[MAX_LOGON_NUM+MAX_LINKVIEW_NUM+MAX_MULTIVIEW_NUM];
}PACKED4 USER_INFO;

//22，DDNS设置
typedef struct _DDNS_SET
{
	INT					bDdnsStart;
	CHAR				szDdnsIP[DDNS_SERVER_NAME_LEN+1];
	UINT				dwDdnsPort;
	CHAR				szDdnsName[DVS_NAME_LEN+1];
	UINT				dwMapWebPort;
	UINT				dwMapDataPort;
}PACKED4 DDNS_SET;

//23，所有参数信息
typedef struct _DVS_Parameter 
{
   	CHAR               	sysName[DVS_NAME_LEN + 1];		//名字
	UCHAR				sysInputNum;					//路数
	UCHAR				sysType;						//机器型号	0:CIF  1:HD1  2:D1  
	UCHAR				sysVideoFormat;					//编码格式	
    UCHAR				sysLanguage;					//语言
    UCHAR				sysStandard;					//制式		0:PAL  1:NTSC
    UCHAR				AD[2];
	UINT      			sysID;  						//每台机器有个ID号  	
	UINT      			sysVer;  						//软件版本  			
	VIDEO_CONFIG		sysVideo[MAX_VIDEO_NUM];		//视频
	VIDEO_MOTION_CONFIG	sysVideoMotion[MAX_VIDEO_NUM];	//视频移动
	VIDEOMASK_CONFIG	sysVideoMask[MAX_VIDEO_NUM];	//视频屏蔽
	VIDEOLOSE_CONFIG	sysVideoLose[MAX_VIDEO_NUM];	//视频丢失
	AUDIO_CONFIG		sysAudio[MAX_AUDIO_NUM];		//音频
	NET_CONFIG			sysNet;							//网络设置
	COM_CONFIG			sysCom[MAX_COM_NUM];			//串口
	SENSOR_CONFIG		sysSensor[MAX_SENSOR_NUM];		//侦测
	USER_CONFIG			sysUser[MAX_USER_NUM];			//用户
	UCHAR				YunTaiProtocolNum;				//云头协议数
	UCHAR				AFD[3];
	YUNTAI_INFO 		YunTaiInfo[MAX_YUNTAI_PROTOCOL_NUM];//协议信息
} PACKED DVS_Parameter ;

typedef struct _NTP_CONFIG
{
	UINT			ntpOpen;					//NTP开关
	UINT			ntpTimeZone;				//时区
	CHAR			ntpHost[DOMAIN_NAME_LEN];	//NTP Server
}NTP_CONFIG;
typedef struct _UPNP_CONFIG
{
	USHORT			upnpOpen;					//UPNP开关
	UCHAR			upnpEthNo;					//UPNP网卡 0－有线，1－无线
	UCHAR			upnpMode;					//UPNP模式 0－指定，1－自动
	USHORT			upnpPortWeb;				//UPNP WEB端口
	USHORT			upnpPortData;				//UPNP DATA端口
	UINT			upnpHost;					//UPNP主机
	USHORT			upnpStatusWeb;				//UPNP WEB状态
	USHORT			upnpStatusData;				//UPNP DATA状态
}UPNP_CONFIG;
typedef struct _MAIL_CONFIG
{
	CHAR			smtpServer[DOMAIN_NAME_LEN];	//发送服务器
	CHAR			pop3Server[DOMAIN_NAME_LEN];	//接收服务器
	CHAR			fromMailAddr[DOMAIN_NAME_LEN];	//邮件发送地址
	CHAR			toMailAddr[DOMAIN_NAME_LEN];	//邮件接收地址
	CHAR			ccMailAddr[DOMAIN_NAME_LEN];	//邮件抄送地址
	CHAR			smtpUser[DOMAIN_NAME_LEN];		//SMTP 用户名
	CHAR			smtpPassword[DOMAIN_NAME_LEN];  //SMTP 用户密码
	CHAR			pop3User[DOMAIN_NAME_LEN];		//POP3 用户名
	CHAR			pop3Password[DOMAIN_NAME_LEN];	//POP3 用户密码
		
	UINT			motionMailOpen;					//视频移动触发MAIL开关
	UINT			motionMail[MAX_VIDEO_NUM];		//视频移动触发抓拍发送MAIL开关
	UINT			sensorMailOpen;					//探头报警触发MAIL开关
	UINT			sensorMail[MAX_SENSOR_NUM];		//探头报警触发抓拍发送MAIL开关
	UINT			viloseMailOpen;		

	UINT			timeMailOpen;					//定时发送(/分)
	UINT			timeVideoMail[MAX_VIDEO_NUM];	//视频定时抓拍发送MAIL开关
	
	CHAR			subjectMail[EMAIL_TITLE_LEN];	//邮件头
	CHAR			textMail[EMAIL_TITLE_LEN];		//邮件内容
		
	UINT			sendMailCount;					//状态: 发送的email记数	
	UINT			sendNow;						//立即发送
	USHORT			smtpPort;						//SMTP 端口
	USHORT			popPort;						//POP3 端口
	USHORT			protocolType;					//SSL
	CHAR			res[6];
}MAIL_CONFIG;

typedef enum _WF_AUTH_TYPE		//主认证加密类型
{
	WF_AUTH_NONE	= 0x00,
	WF_AUTH_WEP		= 0x01,
	WF_AUTH_WPA		= 0x02,
	WF_AUTH_WPA2	= 0x03,
	WF_AUTH_WPAWPA2	= 0x04,
}WF_AUTH_TYPE;


typedef enum _WF_ENC_TYPE		//辅助认证加密
{
	WF_ENC_NONE		= 0x00,		//WEP  开放系统
	WF_ENC_WEP		= 0x01,		//WEP  共享密匙
	WF_ENC_TKIP		= 0x02,		//WEP  自动选择
	WF_ENC_AES		= 0x03,
}WF_ENC_TYPE;

typedef struct _WF_NET_CONFIG
{
	UINT			dwSize;							//大小
	USHORT			wfOpen;							//是否打开无线
	USHORT			dhcpOpen;						//DHCP开关
	//
	UINT			ipAddress;						//IP地址
	UINT			subMask;						//子网掩码
	UINT			gateWay;						//网关
	UINT			dnsIP1;							//DNS服务器1 IP
	UINT			dnsIP2;							//DNS服务器2 IP
	UCHAR			macAddress[6];
	//
	UCHAR			ssidLen;						//SSID名称长度
	UCHAR			pswLen;							//密码长度

	CHAR			ssidName[34];					//SSID名称
	CHAR			pswText[34];					//密码
	UINT			channel;						//通道
	UCHAR			wfAuthType;						//主认证加密类型
	UCHAR			wfEncType;						//辅助认证加密
	CHAR			reserve[10];
}WF_NET_CONFIG;
//
typedef struct _ALARM_INOUT_NAME
{
	CHAR			alarmInName[MAX_SENSOR_NUM][CAM_TITLE_LEN+2];	//探头名
	CHAR			alarmOutName[MAX_OUTPUT_NUM][CAM_TITLE_LEN+2];	//报警输出名
}ALARM_INOUT_NAME;
//视频定向发送设置
typedef struct _SEND_DEST
{	
	UINT			dwSet[MAX_VIDEO_NUM];			//发送开关
	UINT			dwStreamSend[MAX_VIDEO_NUM];	//发送开关
	UINT			dwStreamDestIP[MAX_VIDEO_NUM];	//目的IP,网络字节顺序
	UINT			dwStreamDestPort[MAX_VIDEO_NUM];//目的端口
	CHAR			res[16];
}SEND_DEST;
//自动重新注册
typedef struct _AUTO_RESET_TIME
{
	UCHAR			open;				//bit 1:hour,bit 2:day,bit 3:week	
	UCHAR			second;
	UCHAR			minute;
	UCHAR			hour;
	UCHAR			week;				//0 星期日，1 星期一，2 星期二 

	UCHAR			res[3];
}AUTO_RESET_TIME;

//29，录像参数
//在HH52系列中使用
//在HH58、HH98系列中不再使用

typedef struct _CH_RECORD_CONFIG		//sizeof() = 84
{
	USHORT 			KeepTime;			//某个通道的录像文件保存天数
	USHORT     		reserve;
	TIME_SEGMENT	tSchTable1[8] ;		//某个通道的定时录像时间段1 (40)
	TIME_SEGMENT	tSchTable2[8] ;		//某个通道的定时录像时间段2 (40)
}CH_RECORD_CONFIG;
typedef struct _RECORD_CONFIG			//sizeof() = 360
{
	UCHAR		 PackageTime;	  		//文件打包时间
	UCHAR 		 OverWrite;        		//auto overwrite 
	UCHAR     	 reserve[22];
	CH_RECORD_CONFIG ChRecordCfg[MAX_VIDEO_NUM];//通道的录像参数(336)
}RECORD_CONFIG;

//30，磁盘信息
//在HH58、HH98系列中下面结构加了4个字节
typedef struct _DISK_INFO
{
	UINT	DiskNum;					//磁盘个数
	UCHAR	DiskType[8];				//磁盘类型
	UINT	TotalSize[8];				//磁盘总空间大小
	UINT	FreeSize[8];				//磁盘剩余空间
	UCHAR	Reserved[8];				//BYTE	Reserved[4];	2008.9.23
}DISK_INFO;

//31，磁盘操作
typedef struct _DISK_MANAGE
{
	UCHAR	Cmd;
	UCHAR	Data;
	UCHAR	Reserved[126];
}DISK_MANAGE;

//32，磁盘格式化进度
typedef struct _DISK_FORMAT_PROCESS
{
	UINT	DiskType;					//磁盘类型
	UINT	Status;						//格式化状态
	UINT	Process;					//进度()
	UINT	Reserved[5];
}DISK_FORMAT_PROCESS;

//24，扩展信息结构
typedef struct _EXTINFO_CONFIG
{
	UINT			nSize;						//结构大小

	//ntp
	NTP_CONFIG		ntpConfig;

	//upnp
	UPNP_CONFIG		upnpConfig;
	
	//MAIL
	MAIL_CONFIG		mailConfig;

	//ALARM IN/OUT NAME
	ALARM_INOUT_NAME alarmInOutName;

	//WF NETWORK
	WF_NET_CONFIG	wfConfig;

	//SEND DEST
	SEND_DEST		sendDest;

	//AUTO RESET
	AUTO_RESET_TIME autoResetTime;

	//RECORD CONFIG
	RECORD_CONFIG	recordConfig;

	//DISK INFO
	DISK_INFO		diskInfo;
	
	CHAR			reserve[28];	//diskInfo + 4, here - 4
}PACKED EXTINFO_CONFIG;//1328

//34，用户数据
typedef struct __USERDATA_CONFIG
{
	int		nDataLen;
	char	userData[252];
}USERDATA_CONFIG;



//=================================================================================
//在HH5800系列及之后系列都用以下结构
//=================================================================================

//========================================================================
//扩展帧头
//========================================================================
#define	HH_EXT_HEAD_FLAG	0x06070809
#define	HH_EXT_TAIL_FLAG	0x0a0b0c0d

//视频参数
typedef struct _EXT_FRAME_VIDEO
{
	unsigned short	nVideoEncodeType;	//视频编码算法
	unsigned short	nVideoWidth;		//视频图像宽
	unsigned short	nVideoHeight;		//视频图像高
	unsigned char   nPal;               //制式
	unsigned char   bTwoFeild;			//是否是两场编码(如果是两场编码，PC端需要做deinterlace)
	unsigned char   nFrameRate;			//帧率
	unsigned char   szReserve[7];		//20090305 CYG(2)

} EXT_FRAME_VIDEO;

//音频参数
typedef struct _EXT_FRAME_AUDIO
{
	unsigned short	nAudioEncodeType;	//音频编码算法
	unsigned short	nAudioChannels;		//通道数
	unsigned short	nAudioBits;			//位数
	unsigned char   szReserve[2];
	unsigned long	nAudioSamples;		//采样率 	
	unsigned long	nAudioBitrate;		//音频编码码率
} EXT_FRAME_AUDIO;

typedef union _EXT_FRAME_TYPE
{
	EXT_FRAME_VIDEO	szFrameVideo;
	EXT_FRAME_AUDIO	szFrameAudio;
} EXT_FRAME_TYPE;

typedef struct _EXT_FRAME_HEAD
{
    unsigned long	nStartFlag;			//扩展帧头起始标识
    unsigned short	nVer;				//版本
    unsigned short	nLength;			//扩展帧头长度
	EXT_FRAME_TYPE	szFrameInfo;		
	unsigned long   nTimestamp;			//以毫秒为单位的时间戳
	unsigned long	nEndFlag;			//扩展帧头起始标识
}EXT_FRAME_HEAD;




typedef  struct  _DVS_TIME
{
	UCHAR		year ;
	UCHAR		month ;
	UCHAR		day ;
	UCHAR		week ;
	UCHAR		hour   ;
	UCHAR		minute ;
	UCHAR		second ;
	UCHAR		millisecond;							
} DVS_TIME, *PDVS_TIME;



//=======================================
//报警联动操作
//=======================================
typedef struct _ALARM_LINKAGE 
{
	UINT 		Output;						//报警联动输出				     bit.0---bit.3	
	UINT 		AutoClearTime;		        //报警自动清除时间	

	UINT 		Record_PC;					//PC端报警联动录像通道			 bit.0---bit.3
	UINT 		Record_Dev;					//设备端报警联动录像通道		 bit.0---bit.3
	UINT		RecordSvaeMode;				//bit0 本地存储  bit1 ftp上传  bit2 email
	UINT		RecordTime;					//报警录像时间(秒)

	UINT		ShootSaveMode;				//bit0 本地存储  bit1 ftp上传  bit2 email
	UINT		ShootChns;					//抓拍通道(bit.0 ~ bit.3)
	UINT		ShootNum;					//连续抓拍张数()
	float		ShootInterval;				//连续抓拍时间间隔(秒)  0: 连续抓拍

	UINT		EMail;						//发送email
	UINT		Reserved;					//备用
} ALARM_LINKAGE;

//=======================================
//视频参数(新)
//=======================================
typedef struct _HH_OSD_CTRL_ST
{
	UINT		Show;						//0: 关  1: 开
	USHORT		X;							//x，y：显示的位置，该位置的范围为0-704，0-576，与图像的分辨率无关，x必须为4的倍数；
	USHORT		Y;
} HH_OSD_CTRL_ST ;

typedef struct _HH_VENC_CTRL_ST
{
	UINT       Open;						//是否开启编码（从码流）
	UINT		EncType;					//编码算法
	UINT		EncFormat;					//编码格式(D1, HD1, CIF)
	UINT		Width;						//宽度
	UINT		Height;						//高度
	
	UINT		KeyInterval;			    //I 帧间隔
	UINT		Bitrate ;					//码率
	float		FrameRate ;					//帧率float
	UINT		BitflowType; 			    //码流类型(0:VBR, 1:CBR)
	UINT		Qulity;						//质量0--5
	UINT       Reserved[8];
} HH_VENC_CTRL_ST ;

//=======================================
//抓拍图片参数
//=======================================
typedef struct _PICTURE_CONFIG				//sizeof() = 148
{
	UINT		dwSize;						//本结构长度

	UINT     	EncType;					//抓图格式(.jpg, bmp) 
	UINT     	EncFormat;					//图片其它参数(24位， 32位) 
	UINT     	Width;
	UINT     	Height;

	UCHAR     	reseved[44];
}PICTURE_CONFIG;

//视频宽高
typedef struct _VIDEO_SIZE
{
	USHORT		Width;						//宽
	USHORT		Height;						//高
}VIDEO_SIZE;

//设备支持的编码格式和宽高
typedef struct _SUPPORT_AV_FMT
{
	UINT		dwSize;						//本结构长度
	
	UINT		MainVideoFmt[8];			//主码流编码格式
	UINT		MinVideoFmt[8];				//从码流编码格式
	UINT		PictureFmt[8];				//图片编码格式

	VIDEO_SIZE  MainVideoSize[8];			//主码流 宽、高	
	VIDEO_SIZE  MinVideoSize[8];			//从码流 宽、高	
	VIDEO_SIZE  PictureSize[8];				//图片 宽、高	

	UINT		AudioFmt[8];				//音频编码格式
	UINT		AudioSampleRate[8];			//音频采样率
	UINT		AudioBitrate[8];			//音频码率
	UINT		AuidoAEC;					//是否支持回声抵消

	UCHAR     	reserve[32];	
}SUPPORT_AV_FMT;
#define YTENG_VERSION	1

//视频设置
typedef struct _VIDEO_CONFIG_NEW
{
	UInt32			dwSize;					//本结构长度

	HH_VENC_CTRL_ST stMainVEncCtrl;			//主码流控制
	HH_VENC_CTRL_ST stMinVEncCtrl;			//从码流控制
	PICTURE_CONFIG	stPictureCfg;			//抓拍图片参数

	HH_OSD_CTRL_ST	stDateOSD; 				// 0:不叠加日期,   1:叠加日期
	HH_OSD_CTRL_ST	stTimeOSD; 				// 0:不叠加时间,   1:叠加时间
	HH_OSD_CTRL_ST	stWeekOSD; 				// 0:不叠加星期,   1:叠加星期 
	HH_OSD_CTRL_ST	stTitleOSD;				// 0:不叠加标题,   1:叠加标题 
	HH_OSD_CTRL_ST	stBitrateOSD;			// 0:不叠加码率,   1:叠加码率 	

	char    	Title[CAM_TITLE_LEN_NEW];	//标题字符(64个字符  31个汉字)

    UInt8 		Brightness;				    //亮度
	UInt8 		Hue;						//色调
	UInt8 		Saturation;				    //饱和度
	UInt8 		Contrast;					//对比度

	UInt16 		Protocol;					//协议编号(0 ~ MAX_PAN_PROTOCOL_NUM - 1)
	UInt16 		YTAddr;						//解码器地址
	//george.sun 20090113
	UInt8		mtClear;
	UInt8		mtRed;
	UInt8		mtBlue;
	UInt8		mtGamma;

	UInt8       nOsdPrefer;   //OSD时间显示 0 则为 year-month-day
							  //            1 为   month-day-year 
							  //            2 为   day-month-year 		
	UInt8       nOsdColor;	  //osd 字体颜色
	UInt8       nScene;       //百万ccd 场景澹(0-9)
	UInt8       nOSDClientNum;// 是否显示用户连接数
	UInt8       Reserved[24];
} PACKED VIDEO_CONFIG_NEW;


typedef struct _AREA_RECT
{
	USHORT		X;							//X坐标	
	USHORT		Y;							//Y坐标
	USHORT		W;							//宽度
	USHORT		H;							//高度
} AREA_RECT;

//=======================================
//移动侦测设置(新)
//=======================================
typedef struct _VIDEOMOTION_CONFIG_NEW
{
	UINT			dwSize;						//本结构长度

	UINT 			DetectLevel;			    //移动检测灵敏度
	UINT 			DetectOpen;				    //移动检测开关

	AREA_RECT		DetectArea[9];				//移动检测区域			

	TIME_SEGMENT_NEW  tSchTable1[8] ;		    //移动检测时间表1				 0: 每天
	TIME_SEGMENT_NEW  tSchTable2[8] ;		    //移动检测时间表1				 0: 每天

	ALARM_LINKAGE	stAlarmLink;				//报警联动

	UCHAR			reseved[128];
}VIDEOMOTION_CONFIG_NEW ;

//=======================================
//图像屏蔽设置(新) 长度＝老结构，可以用老命令
//=======================================
typedef struct _VIDEOMASK_CONFIG_NEW
{
	UCHAR 			MaskOpen;					//视频屏蔽开关		0:关         1：开
	UCHAR			AA[3];
	AREA_RECT		MaskArea[9];				//视频屏蔽区域		
}VIDEOMASK_CONFIG_NEW;

//=======================================
//视频丢失设置(新)
//=======================================
typedef struct _VIDEOLOSE_CONFIG_NEW
{
	UINT			dwSize;						//本结构长度

	UINT			DetectOpen;					//视频丢失检测

	ALARM_LINKAGE	stAlarmLink;				//报警联动

	UCHAR			reseved[32];
} VIDEOLOSE_CONFIG_NEW;

//=======================================
//探头报警侦测设置(新)
//=======================================
typedef struct _SENSOR_CONFIG_NEW 
{
	UINT			dwSize;						//本结构长度

	UINT			SensorType;					//0:常开探头	1:常闭探头
	UINT 			DetectOpen;				    //检测开关

	TIME_SEGMENT_NEW  tSchTable1[8] ;		    //探头检测时间1				     0: 每天
	TIME_SEGMENT_NEW  tSchTable2[8] ;		    //探头检测时间1				     0: 每天

	ALARM_LINKAGE	stAlarmLink;				//报警联动

	UCHAR			reseved[32];
}SENSOR_CONFIG_NEW;

//=======================================
//无线探头报警
//=======================================
typedef struct _RF_ALARM_CONFIG
{
	UINT			dwSize;						//本结构长度

	UINT			SensorType;					//0:常开探头	1:常闭探头
	UINT 			DetectOpen;				    //检测开关

	TIME_SEGMENT_NEW  tSchTable1[8] ;		    //探头检测时间1				     0: 每天
	TIME_SEGMENT_NEW  tSchTable2[8] ;		    //探头检测时间1				     0: 每天

	ALARM_LINKAGE	stAlarmLink;				//报警联动

	UCHAR			reseved[32];
}RF_ALARM_CONFIG;


//=======================================
//网络断线报警设置
//=======================================
typedef struct _NET_ALARM_CONFIG 
{
	UINT			dwSize;						//本结构长度

	UINT 			DetectOpen;				    //检测开关
	
	ALARM_LINKAGE	stAlarmLink;				//报警联动

	USHORT			reseved[32];
} NET_ALARM_CONFIG;

//=======================================
// FTP 服务器参数
//=======================================
typedef struct __FTP_CONFIG
{
    char			ftpURL[64];
    char			ftpPath[64];
    UINT			ftpPort;
    char			ftpUser[32];
    char			ftpPsw[32];

    char			ftpURL2[64];
    char			ftpPath2[64];
    UINT			ftpPort2;
    char			ftpUser2[32];
    char			ftpPsw2[32];

    char			res[32];
}FTP_CONFIG;

//=======================================
//流媒体服务
//=======================================
typedef struct _MEDIA_SERVER
{
	UCHAR				bRtspOpen;
	UCHAR				bMmsOpen;
	USHORT				rtspPort;
	USHORT				mmsPort;
	USHORT				res;
}MEDIA_SERVER;

//suncz 20090602
typedef struct _GPS_INFO
{
	UCHAR		bGpsOpen;
	UCHAR		gpsStatus;
	USHORT		serverPort;
	UINT		serverIP;
	UCHAR		bGpsOSD;
	UCHAR		gpsPlatform;
	UCHAR		phoneNum[11];
	UCHAR       reportTime;	//ljm 2009-09-25 
	UCHAR		res[2];
	//BYTE		res[3];
}GPS_INFO;
//24.0 扩展信息结构(修改定义， 大小和原结构相同， 所以命令也相同)
typedef struct _EXTINFO_CONFIG_NEW
{
	UINT				nSize;						//结构大小(1328)

	NTP_CONFIG			ntpConfig;					//ntp
	
	UPNP_CONFIG			upnpConfig;					//upnp
		
	MAIL_CONFIG			mailConfig;					//MAIL
	
	ALARM_INOUT_NAME	alarmInOutName;				//ALARM IN/OUT NAME
	
	WF_NET_CONFIG		wfConfig;					//WF NETWORK
	
	SEND_DEST			sendDest;					//SEND DEST
	
	AUTO_RESET_TIME		autoResetTime;				//AUTO RESET 

	FTP_CONFIG			ftpCfg;						//FTP 服务器配置

	MEDIA_SERVER		mediaServer;				//流媒体服务

	GPS_INFO			gpsInfo;					//GPS 信息,

	UCHAR               reportWanIp;            	//ljm 20090721 用于上报公网IP地址
	UCHAR               reportIpInterval;          	//ljm 20090724
	char				reserve[14];				//cz 20090602 //ljm 20090724

	//char				reserve[16];  
	//char				reserve[40];  
}EXTINFO_CONFIG_NEW;

//=======================================
//无线探头
//=======================================
typedef struct _RF_KEY_CONFIG
{
	unsigned char		rf_close;
	unsigned char		rf_help_key;
	unsigned char		rf_alarm_noset;
	unsigned char		rf_disconnect_vidio;

	unsigned char		rf_res[32];
}RF_KEY_CONFIG;

//=======================================
//定时录像
//=======================================
typedef struct _CH_TIMER_RECORD_CONFIG		//sizeof() = 140
{
	USHORT					KeepTime;								//保留天数(天)
	USHORT					RecordSvaeMode;							//bit0 本地存储  bit1 ftp上传  bit2 email
	UINT					reserve[2];

	TIME_SEGMENT_NEW		tSchTable1[8] ;							//某个通道的定时录像时间段1 (64)
	TIME_SEGMENT_NEW		tSchTable2[8] ;							//某个通道的定时录像时间段2 (64)
}CH_TIMER_RECORD_CONFIG;	

typedef struct _TIMER_RECORD_CONFIG			//sizeof() = 592
{
	USHORT					PackageTime;	  						//打包时间(分钟)
	USHORT 					OverWrite;        						//自动覆盖
	USHORT     				MainVEnc;								//录像采用 0: 从码流  1: 主码流
	USHORT     				CheckDisk;								//系统启动时进行磁盘扫描
	USHORT     				reserve[28];

	CH_TIMER_RECORD_CONFIG	ChRecordCfg[MAX_VIDEO_NUM];				//通道的录像参数(140 * 4 = 560)
}TIMER_RECORD_CONFIG;


//=======================================
//定时抓拍
//=======================================
typedef struct _CH_TIMER_SHOOT_CONFIG		//sizeof() = 140
{
	USHORT 					KeepTime;								//保留天数(天)
	USHORT					ShootSaveMode;							//bit0 本地存储  bit1 ftp上传  bit2 email

	UINT					ShootNum;								//连续抓拍张数()
	float					ShootInterval;							//连续抓拍时间间隔(秒)  0: 连续抓拍

	TIME_SEGMENT_NEW		tSchTable1[8] ;							//某个通道的定时抓拍时间段1 (40)
	TIME_SEGMENT_NEW		tSchTable2[8] ;							//某个通道的定时抓拍时间段2 (40)
}CH_TIMER_SHOOT_CONFIG;

typedef struct _TIMER_SHOOT_CONFIG			//sizeof() = 592
{
	UCHAR 					OverWrite;								//自动覆盖
	UCHAR     				reserve[31];

	CH_TIMER_SHOOT_CONFIG	ChShootCfg[MAX_VIDEO_NUM];				//通道的录像参数(92 * 4 = 368)
}TIMER_SHOOT_CONFIG;

//=======================================
//其它扩展参数(如平台设置其它参数)
//=======================================
typedef struct __EXT_DATA_CONFIG
{
	UINT		nSize;					//结构大小
	UINT		nType;	
       UINT		nDataLen;
    char		szData[512];
}EXT_DATA_CONFIG;

//=======================================
//日志查询
//=======================================
typedef struct _FIND_LOG_S
{
	UINT		nSize;					//结构大小
	UINT		nSelectMode;			//查询方式:0－全部，1－按类型，2－按时间，3－按时间和类型
	UINT		nType;					//报警类型
    DVS_TIME	stStartTime;
	DVS_TIME	stEndTime;
}FIND_LOG_S;

typedef struct _LOG_ITEM_S
{
	UINT		nSize;					//结构大小
	UINT		nAlarmType;				//报警类型
	UINT       nChn;					//通道号、断线报警的IP地址
	DVS_TIME	tAlarmTime;	
	char		szNote[12];
}LOG_ITEM_S;

//=======================================
//设备所有参数（sizeof = 10248）
//=======================================
typedef struct _DVS_Parameter_New
{
	UINT					dwSize;						//本结构长度

    char                    sysName[DVS_NAME_LEN + 4];

	UCHAR					sysInputNum;		        //路数
	UCHAR					sysType;			        //机器型号	0:CIF  1:HD1  2:D1  
	UCHAR					sysVideoFormat;		        //编码格式	0:D1,1:HD1,2:CIF,3:VGA 4:HVGA 5:CVGA 6:QCIF 7:QVGA
    UCHAR					sysLanguage;		        //语言

    UINT					sysStandard;		        //制式		0:PAL  1:NTSC

    UINT      				sysID;  	                //每台机器有个ID
	UINT      				sysVer;  	                //软件版本  

	VIDEO_CONFIG_NEW	    sysVideo[MAX_VIDEO_NUM];	
	VIDEOMOTION_CONFIG_NEW	sysVideoMotion[MAX_VIDEO_NUM];
	VIDEOMASK_CONFIG_NEW    sysVideoMask[MAX_VIDEO_NUM];	
	VIDEOLOSE_CONFIG_NEW    sysVideoLose[MAX_VIDEO_NUM];	
	AUDIO_CONFIG		    sysAudio[MAX_AUDIO_NUM];
	NET_CONFIG			    sysNet;
	COM_CONFIG			    sysCom[MAX_COM_NUM];
	SENSOR_CONFIG_NEW	    sysSensor[MAX_SENSOR_NUM];
	USER_CONFIG			    sysUser[MAX_USER_NUM];

    EXTINFO_CONFIG_NEW		sysExtConfig;				//扩展参数

	DISK_INFO				DiskInfo;					//存储设备信息

	TIMER_RECORD_CONFIG		TimerRecordCfg;
	TIMER_SHOOT_CONFIG		TimerShootCfg;				//定时抓拍参数

	RF_ALARM_CONFIG			rfAlarmCfg[MAX_RF_SENSOR_NUM];	//无线探头报警
	NET_ALARM_CONFIG		netAlarmCfg;					//网络断线报警

	USERDATA_CONFIG			userData;					//用户数据

	UINT					YunTaiProtocolNum;
	YUNTAI_INFO 			YunTaiInfo[MAX_PTZ_PROTOCOL_NUM];	

	UCHAR					reserved[256];				//备用

} DVS_Parameter_New;

//备用1
typedef struct _CONFIG_ENCPAR
{ 
    UINT u32PicWidth;   
    UINT u32PicHeight;     
    UINT u32CapSel; 
    UINT u32StaticParam; 
    UINT u32TargetBitrate; 
    UINT u32TargetFramerate; 
    UINT u32Gop;             
    UINT u32MaxQP;        
    UINT u32PreferFrameRate; 
    UINT u32Strategy; 
    UINT u32VencMode;        
    UINT u32BaseQP;         
    UINT u32MaxBitRate;   
}CONFIG_ENCPAR; 

//备用2
typedef struct _PING_CONFIG
{
	BOOL	bPingOpen;
	BOOL	bDisconnectReboot;
	BOOL	bDisconnectAlarm;
	UINT	dwPingNum;
	UINT    dwPingPeriod;
	char	szPingServer[64];
}PING_CONFIG;

//设置关键帧
typedef struct _HHCMD_SET_KEYFRAME_REQ_INFO    //add by come 20090924
{
	unsigned int 				    nOpenChannel:8; 			//通道号（0 ～ 3）
	unsigned int					nSubChannel:8;				//0: 打开主码流 	 1: 打开从码流
	unsigned int                    nRes:16;
}PACKED HHCMD_SET_KEYFRAME_REQ_INFO;


//------------------------------(II)解码器参数设置结构----------------------------//
//1，系统时间
typedef  struct  _DD_NVD_DATE
{
	UCHAR		year;									//年
	UCHAR		month;									//月
	UCHAR		day;									//日
	UCHAR		week;									//周
	UCHAR		hour;									//小时
	UCHAR		minute;									//分
	UCHAR		second;									//秒
}DD_NVD_DATE, *PDD_NVD_DATE;

//2，系统配置
typedef struct _DD_SYSTEM_PARAM 
{
   	CHAR               	Name[DVS_NAME_LEN + 1];			//名字
	UCHAR				Type;							//机器型号	0:CIF  1:HD1  2:D1  
    UCHAR				Language;						//语言
    UCHAR				Standard;						//制式		0:PAL  1:NTSC
	UINT      			ID;  	        				//每台机器有个ID号  	
	UINT      			RS485Addr;       				//RS485地址  		
	UINT      			RS485Func;       				//RS485功能  			
	UINT      			RS485Baud;       				//RS485波特率  			
	UINT      			Version;         				//软件版本  
	UCHAR      			RemoteID;         				//遥控ID号  	
	UCHAR				Audio;							//监听开关	
	UCHAR				TimeOn;							//时间显示开关				
	UCHAR				DispMode;						//显示模式(1单画面、4四画面)
	UCHAR				ImageQulity;					//解码图像质量
	UCHAR				Reserve[31];					//备用
}PACKED DD_SYSTEM_PARAM;

//3，网络参数
typedef struct _DD_NET_CONFIG
{
	UINT             	IPAddr ;						//IP地址
	UINT             	SubNetMask ;					//掩码
	UINT             	GateWay ;						//网关

   	USHORT             	ComPortNo;						//设置接收客户端命令端口号        UDP	
   	USHORT             	WebPortNo;						//Webserver端口     			  TCP
	UINT             	MultiCastIPAddr ;				//多播IP地址
   	USHORT             	MultiCastPortNo;				//UDP传输起始端口<多播传输>
	
	UCHAR			   	RT8139MAC[6];      				//人工设置网卡的MAC地址		5---0有效
   	UCHAR             	DHCP;							//DHCP 开关					0	关		1:开
	UCHAR				AD[1];
	
   	USHORT             	PppoeOpen;						//PPPOE 开关         	
	UINT             	PppoeIPAddr ;					//PPPOEIP地址 （报警回传IP）
	CHAR				PppoeName[PPPPOE_NAME_LEN+1];	//拨号用户名
	CHAR				PppoePass[PPPPOE_PASSWD_LEN+1];	//拨号密码		
	CHAR				ADD[2];	
	UINT				DdnsOpen;						//DDNS开关
	CHAR				DdnsName[DDNS_NAME_LEN+1];		//注册主机名称
	CHAR				DdnsPass[DDNS_PASS_LEN+1];		//注册主机密码	

	
	CHAR				DdnsIP[DDNS_SERVER_NAME_LEN+1];	//DDNS服务器
	CHAR				ASD[1];
	
	USHORT				DdnsPortNo;						//DDNS服务器端口
	USHORT				DdnsMapWebPort;					//本地WEB映射端口
	USHORT				DdnsMapDataPort;				//本地数据映射端口
	CHAR				ASDD[2];

	UINT				DNSHostIP;						//DNS的IP
	INT					ConnectCenter;					//是否主动连接中心
	CHAR				ConnectCenterIP[DDNS_SERVER_NAME_LEN+1];//中心IP
	CHAR				AAD[1];
	
	USHORT				ConnectCenterPort;				//中心端口

	USHORT				appFunction;					//fix me
	UCHAR				tcpSendInterval;
	UCHAR				udpSendInterval;
	USHORT				PacketMTU;

	UCHAR				CaptureMode;					//抓拍模式
	UCHAR				CapturePort[MAX_SENSOR_NUM];	//抓拍通道(0-3bit: 分别表示1 ~ 4号通道  1:开  0: 关)

	UINT				DdnsIP2;						//DDNS 2的IP,非网络字节次序
	USHORT				DdnsPortNo2;					//DDNS 2的端口

	CHAR				sysByname[DVS_NAME_LEN+1];		//域名
	UCHAR				NetReserve[1];					//保留
} PACKED DD_NET_CONFIG ;

//4，串口设置
typedef struct __DD_COM_PARAM
{
	UINT 				Baudrate;						//串口波特率				300---115200
	UCHAR				Databit;						//串口数据位长度			5=5位 6=6位 7=7位 8=8位	其他=8位
	UCHAR				Stopbit;						//停止位位数				1=1位 2=2位 其他=1位
	UCHAR				CheckType;						//校验						0=无  1=奇  2=偶  3=恒1  4=恒0 
	UCHAR				Flowctrl; 						//软流控/硬流控/无流控		备用
}PACKED DD_COM_CONFIG;

//5，图像参数
typedef struct _DD_IMAGE_PARAM
{
	UCHAR 	Bright;										// 亮度
	UCHAR 	Shades;										// 色度
	UCHAR 	Contrast;									// 对比度
	UCHAR 	Saturate;									// 饱和度
	UCHAR 	MenuBright;									// 菜单亮度
}PACKED DD_IMAGE_CONFIG;

//6，报警联动
typedef struct __DD_ALARMOUT_PARAM
{
	UCHAR 				Open;							//联动开关<0: 关  1: 开>
	UCHAR				SensorAlarm[4];					//探头报警联动	.0 ~ 3 1--4号探头	0,1位: 分别表示继电器1 2的状态  <0: 关  1: 开>
	UCHAR				MotionAlarm[4];					//视频移动联动	.0 ~ 3 1--4号探头	0,1位: 分别表示继电器1 2的状态  <0: 关  1: 开>
	UCHAR				ViLoseAlarm[4];					//视频丢失联动	.0 ~ 3 1--4号探头	0,1位: 分别表示继电器1 2的状态  <0: 关  1: 开>
	UCHAR				Reserve[8];						//备用	
}PACKED DD_ALARMOUT_CONFIG;


//7，用户设置
typedef struct _DD_USER_CONFIG
{
	UINT 		Level;									//权限
	CHAR 		Name[17];								//用户名
	CHAR 		Password[17];							//用户密码
	CHAR 		AD[2];
}PACKED DD_USER_CONFIG;


//8，报警信息条目
typedef struct __DD_ALARM_ITEM
{
	UINT 				IPAddr;							//IP
	CHAR				URL[DD_URL_ADDR_LEN + 1];		//URL地址
	CHAR				AVD[3];
	UINT				ComPortNo;						//通讯端口
	DD_NVD_DATE			AlarmTime;						//报警时间
	UCHAR				SensorAlarm;					//探头报警联动	.0 ~ 3 1--4号探头	<0: 无报警  1: 有报警>
	UCHAR				MotionAlarm;					//视频移动联动	.0 ~ 3 1--4号视频	<0: 无报警  1: 有报警>
	UCHAR				ViLoseAlarm;					//视频丢失联动	.0 ~ 3 1--4号视频	<0: 无报警  1: 有报警>
	UCHAR				Reserve[8];						//保留
	CHAR				AD[2];
}PACKED DD_ALARM_ITEM;


//9，报警信息记录
typedef struct __DD_ALARM_INFO
{
	USHORT				Count;							//报警记录个数
	CHAR				AD[2];
	DD_ALARM_ITEM		Alarms[DD_MAX_ALARMINFO_NUM];	//报警记录内容
}PACKED DD_ALARM_INFO;


//10，地址薄
typedef struct __DD_ADDRBOOK_PARAM
{
	CHAR				Name[DDNS_NAME_LEN + 1];		//名称
	CHAR				URL[DD_URL_ADDR_LEN + 1];		//URL地址
	USHORT             	ComPortNo;						//通讯端口
	UCHAR				ChannelNo;						//通道号
	UCHAR				Protocol;						//0: TCP  1:多播   2:UDP
	UCHAR				DNSOpen;						//0: 关   1:开
	UCHAR				AD;
	USHORT				StayTime;						//停留时间	5--3600秒
	UCHAR				AutoLink;						//自动连接	0:关  1:开
	UCHAR				AudioOpen;						//声音打开	0:关  1:开	
	UCHAR				TalkOpen;						//对讲打开	0:关  1:开
	CHAR				UserName[USER_NAME_LEN + 1];	//用户名
	CHAR				UserPass[USER_PASSWD_LEN + 1];	//用户密码	
	UCHAR				Reserve[8];						//保留	
	UCHAR				AD2;
}PACKED DD_ADDRBOOK_CONFIG;


//11，透明通讯
typedef struct __DD_COMM_CTRL
{
	UCHAR				COMMNo;							//串口号	0 ~ 1
	UCHAR				ADG[3];
	COM_CONFIG			COMConfig;						//串口配置
	USHORT				DataLength;						//数据长度
	UCHAR				Data[256];						//数据
	UCHAR				AD[2];
}PACKED DD_COMM_CTRL;


//12，其它控制命令结构
typedef struct __DD_DEVICE_CTRL
{
	UCHAR				CMD;							//命令
	UCHAR 				Data1;							//数据1
	UCHAR 				Data2;							//数据2
	UCHAR				AD[1];
	UINT				nReserved[8];					//保留
}PACKED DD_DEVICE_CTRL;


//13，云台信息
typedef struct _DD_PROTOCOL_INFO
{
	CHAR 		Name[YUNTAI_NAME_LEN + 1];				//云台名称
	UCHAR		Exist;									//是否可用
	UCHAR		nReserved[8];							//保留
}PACKED DD_PROTOCOL_INFO;

//14，云台设置

typedef struct _DD_YUNTAI_SET
{
	CHAR 		Name[YUNTAI_NAME_LEN + 1];				//云台名称
	UCHAR 		YTAddr;									//解码器地址
	UCHAR		AD[2];
	COM_CONFIG	ComSet;									//通讯协议<波特率...>
	
	UCHAR		nReserved[8];							//保留
}PACKED DD_YUNTAI_SET;


//15，系统所有参数(所有配置参数，网络传输用)

typedef struct _DD_NVD_CONFIG 
{
	DD_SYSTEM_PARAM 		sysParam;					//系统配置
	DD_NET_CONFIG			sysNet;						//网络设置
	DD_COM_CONFIG			sysCom[MAX_COM_NUM];		//串口设置
	DD_IMAGE_CONFIG			sysImage;					//图像参数
	UCHAR					ADD[3];
	DD_USER_CONFIG			sysUser[MAX_USER_NUM];		//用户
	DD_ALARMOUT_CONFIG		sysAlarmOut;				//报警输出
		
	DD_PROTOCOL_INFO 		YunTaiInfo[MAX_VIDEO_NUM];	//云台信息
	UCHAR					AD[2];
	DD_YUNTAI_SET 			YunTaiSet[MAX_VIDEO_NUM];	//云台协议设置		
} PACKED DD_NVD_CONFIG ;


//16，扩展信息结构
typedef struct _DD_EXTINFO_CONFIG
{
	UINT			nSize;						//结构大小

	//ntp
	NTP_CONFIG		ntpConfig;

	//upnp
	UPNP_CONFIG		upnpConfig;
	
	//MAIL
	MAIL_CONFIG		mailConfig;

	//ALARM IN/OUT NAME
	ALARM_INOUT_NAME alarmInOutName;

	//WF NETWORK
	WF_NET_CONFIG	wfConfig;

	//SEND DEST
	SEND_DEST		sendDest;
	
	CHAR			reserve[480];
}DD_EXTINFO_CONFIG;

#endif

typedef struct _EMP_NO
{	
	int			ShowType[MAX_VIDEO_NUM];
	char		EmpNo[MAX_VIDEO_NUM][32];
	
} PACKED EMP_NO;


