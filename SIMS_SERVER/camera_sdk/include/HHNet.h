/******************************************************************************
* ϵͳ���ƣ�HHNet
* �ļ����ƣ�HHNet.h
* �汾    ��V 2.0.0
* ˵��	  �����翪�����ӿ�,��SDKΪ�ͱ������������������ṩ�ӿ�
			���ļ����������֣�һ���궨�壻����ö�����Ͷ��壻�����ص��������ġ��ӿڽṹ���Ͷ��壻�塢�����ӿڶ��壻����������Ƶ��������������Ϣ�ṹ
* ��    ��: 2008��9��28��
  �������:	2008��9��28��
* ����˵��: ��
******************************************************************************/
#ifndef  __HHNET_H__
#define  __HHNET_H__

#define PACKED  __attribute__((packed, aligned(1)))
#define PACKED4 __attribute__((packed, aligned(4)))


/*----------------------------------------------*
  �����������Ͷ���
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

/*********************************  һ���궨��  ******************************/

//1��ϵͳ����
#define	IN
#define	OUT
#define	MAX_PATH				256

#define MAX_VIDEO_NUM			4	//������Ƶ���������ͨ����
#define MAX_AUDIO_NUM			4	//������Ƶ��������Ƶ���ͨ����
#define MAX_SENSOR_NUM			4	//̽ͷ����·��
#define MAX_RF_SENSOR_NUM		8	//����̽ͷ���·��
#define MAX_OUTPUT_NUM			4	//̽ͷ���·��
#define MAX_COM_NUM				2	//����������	
#define MAX_USER_NUM			5	//�û�����
#define MAX_LOGON_NUM			10	//���ͬʱ��¼�û���
#define MAX_LINKVIEW_NUM		16	//���ͬʱTCP��UDPԤ���û���
#define MAX_MULTIVIEW_NUM		60	//���ಥ�û���
#define DVS_NAME_LEN            32	//������Ƶ���������Ƴ���

#define CAM_TITLE_LEN_NEW		64	//31�����֣�63���ַ�
#define CAM_TITLE_LEN			16	//��������ⳤ��(8�����֣�16���ַ�)
#define USER_NAME_LEN 			16	//�û�������󳤶�
#define USER_PASSWD_LEN   		16	//�û�������󳤶�
	
#define DDNS_NAME_LEN			32	//ע���������Ƴ���
#define DDNS_PASS_LEN			16	//ע���������볤��	
#define	DDNS_SERVER_NAME_LEN	32
#define PPPPOE_NAME_LEN			32	//�����û�������
#define PPPPOE_PASSWD_LEN		16	//�����û�������
#define YUNTAI_NAME_LEN			32	//��̨Э�����Ƴ���
#define MAX_YUNTAI_PROTOCOL_NUM	36	//���������̨Э����
#define MAX_PTZ_PROTOCOL_NUM  	4	//�����̨Э����
#define	MAX_IP_NAME_LEN			128	//����IP�����ֵ���󳤶�
#define	IP_STR_LEN				16	//IP��

#define	DOMAIN_NAME_LEN			32  //�����ĳ���
#define EMAIL_TITLE_LEN         32	//EMAILͷ�����ݳ�
#define DD_URL_ADDR_LEN			32	//URL��ַ����
#define	DD_MAX_ADDR_NUM			32	//��ַ���ĵ�ַ����
#define	DD_MAX_ALARMINFO_NUM	64	//������¼�������ֵ
#define EMP_NO_LEN				32  //���ų���

//2����̨����
#define	YT_UP					1	//��̨��
#define	YT_DOWN					2	//��̨��	
#define	YT_LEFT					3	//��̨��
#define	YT_RIGHT				4	//��̨��
#define	YT_FOCUSADD				5	//�۽�+
#define	YT_FOCUSSUB				6	//�۽�-
#define	YT_IRISADD				7	//��Ȧ+
#define	YT_IRISSUB				8	//��Ȧ-
#define	YT_ZOOMADD				9	//�䱶+
#define	YT_ZOOMSUB				10	//�䱶-
#define	YT_AUTOOPEN				11	//�Զ���
#define	YT_AUTOCLOSE			12	//�Զ���
#define	YT_LAMPOPEN				13	//�ƹ⿪
#define	YT_LAMPCLOSE			14	//�ƹ��
#define	YT_BRUSHOPEN			15	//��ο�
#define	YT_BRUSHCLOSE			16	//��ι�
#define	YT_WATEROPEN			17	//��ˮ��
#define	YT_WATERCLOSE			18	//��ˮ��
#define	YT_PRESET				19	//Ԥ�� + ��
#define	YT_CALL					20	//���� + ��
#define	YT_STOP					21	//ֹͣ
#define	YT_UP_STOP				30	//��̨��-ͣ	
#define	YT_DOWN_STOP			31	//��̨��-ͣ	
#define	YT_LEFT_STOP			32	//��̨��-ͣ
#define	YT_RIGHT_STOP			33	//��̨��-ͣ
#define	YT_FOCUSADD_STOP		34	//�۽�+ -ͣ
#define	YT_FOCUSSUB_STOP		35	//�۽�- -ͣ
#define	YT_IRISADD_STOP			36	//��Ȧ+ -ͣ
#define	YT_IRISSUB_STOP			37	//��Ȧ- -ͣ
#define	YT_ZOOMADD_STOP			38	//�䱶+ -ͣ
#define	YT_ZOOMSUB_STOP			39	//�䱶- -ͣ	

//3������֡��־
#define FRAME_FLAG_VP			0x0b	//��Ƶ��P֡
#define FRAME_FLAG_VI			0x0e	//��Ƶ��I֡
#define FRAME_FLAG_A			0x0d	//��Ƶ֡


/*********************************  ����ö�����Ͷ���  ******************************/

//1��������Ƶ��������������
typedef enum	DVS_MACHINE_TYPE_
{
    HH5001C  = 0x00,  //һ·CIF������
    HH5002H  = 0x01,  //��·HalfD1������
    HH5001D  = 0x02,  //һ·D1������
    HH5004C  = 0x03,  //��·CIF������
    HH5104   = 0x04,  //��·������
    HH5108   = 0x05,  //��·������
    HH6104   = 0x06,  //��·���뿨

    HH5200   = 0x10,  //����
    HH5201   = 0x11,  //IPCamһ·CCD,D1����,HH9000ϵ��
    HH5201DI = 0X11,
    HH5201CI = 0x12,  //IPCamһ·CCD,CIF����,HH9000ϵ��
    HH5201MI = 0x13,  //IPCamһ·CMOS,HH9000ϵ��

    HH5201C  = 0x20,  //DVSһ·CIF
    HH5201D  = 0x21,  //DVSһ·D1
    HH5202C  = 0x22,  //DVS��·CIF
    HH5202H  = 0x23,  //DVS��·HD1
    HH5204C  = 0x24,  //DVS��·CIF
    HH5204D  = 0x25,  //DVS��·d1

    HH5301   = 0x30,  //H.264 ��·������(IPCam, HH52ϵ��, HH56ϵ��DVS)

    HH5700   = 0x35,  //HH57ϵ�� ������ (IPCam, HH52ϵ��, HH56ϵ��DVS)

    HH9800CI = 0x40,  //HH98ϵ�� IPCamһ·CCD
    HH9800MI,         //HH98ϵ�� IPCamһ·CMOS

    HH9800MIX,        //HH98ϵ�� IPCamһ·CMOS(����)

 

    HH5801C  = 0x45,  //HH58ϵ�� DVS 
    HH5801D, 
    HH5802C,
    HH5802H,
    HH5802D, 
    HH5804C,
    HH5804H,
    HH5804D, 

    HH7000 = 0x50,
}DVS_MACHINE_TYPE;

//2����Ƶ�����ʽ									
typedef enum  _ENCODE_VIDEO_TYPE
{
	EV_TYPE_NONE		= 0xFFFF,
	EV_TYPE_PAL_D1		= 0x00,		//PAL��D1		704 * 576
	EV_TYPE_PAL_HD1		= 0x01,		//PAL��HalfD1	704 * 288
	EV_TYPE_PAL_CIF		= 0x02,		//PAL��CIF		352 * 288
	EV_TYPE_VGA			= 0x03,		//VGA			640 * 480
	EV_TYPE_HVGA		= 0x04,		//HVGA			640 * 240
	EV_TYPE_CVGA		= 0x05,		//CVGA			320 * 240
	EV_TYPE_PAL_QCIF	= 0x06,		//PAL��QCIF		176 * 144
	EV_TYPE_QVGA		= 0x07,		//QVGA			160 * 120
	EV_TYPE_NTSC_D1		= 0x08,		//N��D1			704 * 480
	EV_TYPE_NTSC_HD1	= 0x09,		//N��HalfD1		704 * 240
	EV_TYPE_NTSC_CIF	= 0x0A,		//N��CIF		352 * 240
	EV_TYPE_NTSC_QCIF	= 0x0E,		//N��QCIF		176 * 120
	//
	EV_H264_PAL_D1		= 0x10,		//H264_2,PAL��D1		704 * 576
	EV_H264_PAL_HD1		= 0x11,		//H264_2,PAL��HalfD1	704 * 288
	EV_H264_PAL_CIF		= 0x12,		//H264_2,PAL��CIF		352 * 288
	EV_H264_VGA			= 0x13,		//H264_2,VGA			640 * 480
	EV_H264_HVGA		= 0x14,		//H264_2,HVGA			640 * 240
	EV_H264_CVGA		= 0x15,		//H264_2,CVGA			320 * 240
	EV_H264_PAL_QCIF	= 0x16,		//H264_2,PAL��QCIF		176 * 144
	EV_H264_QVGA		= 0x17,		//H264_2,QVGA			160 * 120
	EV_H264_NTSC_D1		= 0x18,		//H264_2,N��D1			704 * 480
	EV_H264_NTSC_HD1	= 0x19,		//H264_2,N��HalfD1		704 * 240
	EV_H264_NTSC_CIF	= 0x1A,		//H264_2,N��CIF			352 * 240
	EV_H264_NTSC_QCIF	= 0x1E,		//H264_2,N��QCIF		176 * 120
	//
	//��׼MPEG4
	EV_MPEG4_PAL_D1		= 0x20,		//PAL��D1				704 * 576
	EV_MPEG4_PAL_HD1	= 0x21,		//PAL��HalfD1			704 * 288
	EV_MPEG4_PAL_CIF	= 0x22,		//PAL��CIF				352 * 288
	EV_MPEG4_VGA		= 0x23,		//VGA					640 * 480
	EV_MPEG4_HVGA		= 0x24,		//HVGA					640 * 240
	EV_MPEG4_CVGA		= 0x25,		//CVGA					320 * 240
	EV_MPEG4_PAL_QCIF	= 0x26,		//PAL��QCIF				176 * 144
	EV_MPEG4_QVGA		= 0x27,		//QVGA					160 * 120
	EV_MPEG4_NTSC_D1	= 0x28,		//N��D1					704 * 480
	EV_MPEG4_NTSC_HD1	= 0x29,		//N��HalfD1				704 * 240
	EV_MPEG4_NTSC_CIF	= 0x2A,		//N��CIF				352 * 240
	EV_MPEG4_NTSC_QCIF	= 0x2E,		//N��QCIF				176 * 120
	//
	EA_G722_S16B16C1	= 0x0100,	//��Ƶ��G722
	EA_G711A_S16B16C1	= 0x0200,	//��Ƶ��G711A
	EA_G711MU_S16B16C1	= 0x0300,	//��Ƶ��G711MU
	EA_ADPCM_S16B16C1	= 0x0400,	//��Ƶ��ADPCM
	EA_G726_S16B16C1	= 0x0500,	//��Ƶ��G726
	EA_BUTT_S16B16C1	= 0x0600,	//��Ƶ��BUTT
	EA_MPT_S16B16C1		= 0x0700,	//��Ƶ��MPT
}ENCODE_VIDEO_TYPE;

//3����������
typedef enum _UPDATE_TYPE
{
	UPDATE_KERNEL,					//�����ں�
	UPDATE_YUNTAI1,					//������̨Э��1
	UPDATE_YUNTAI2,					//������̨Э��2
	UPDATE_YUNTAI3,					//������̨Э��3
	UPDATE_YUNTAI4,					//������̨Э��4
	UPDATE_YUNTAI5,					//������̨Э��5
	UPDATE_YUNTAI6,					//������̨Э��6
	UPDATE_OCX,						//�����ؼ�
	UPDATE_WEBPAGE,					//����ҳ��
	UPDATE_PATHFILE,				//�����ض�Ŀ¼�ļ�
}UPDATE_TYPE;

//4������Э������
typedef enum _NET_PROTOCOL_TYPE
{
    NET_PROTOCOL_TCP = 0,			//TCPЭ��
    NET_PROTOCOL_UDP = 1,			//UDPЭ��
    NET_PROTOCOL_MULTI = 2			//�ಥЭ��
}NET_PROTOCOL_TYPE;

//5������״̬
typedef enum _CONNECT_STATUS
{
	CONNECT_STATUS_NONE,			//δ����
	CONNECT_STATUS_OK,				//�Ѿ�����
}CONNECT_STATUS;

//6��ת������
typedef enum _RELAY_TYPE
{
	RELAY_LOGON,					//ת����¼����
	RELAY_PREVIEW,					//ת����ƵԤ������
	RELAY_TALK,						//ת���Խ�
	RELAY_AUDIOBRD,					//ת�������㲥
	RELAY_QUERY						//ת���Ĳ�ѯ
}RELAY_TYPE;

//7��֪ͨӦ�ó��򴰿���Ϣ����
typedef enum _HHMSG_NOTIFY

{
    HHMSG_CONNECT_CLOSE,             //��¼���ӹر� 

    HHMSG_CHANNEL_CLOSE,             //ͨ�����ӹر� 

    HHMSG_TALK_CLOSE,                //�Խ����ӹر� 

    HHMSG_ALARM_OUTPUT,              //�������                   98ϵ��58ϵ��֮ǰ�豸�ô˶��� 

    HHMSG_UPDATE_SEND_PERCENT,       //���������Ͱٷֱ� 

    HHMSG_UPDATE_SAVE_PERCENT,       //����д�뷢�Ͱٷֱ�

    HHMSG_VIEWPUSH_CLOSE ,           //��������Ƶ����ر� 

   	HHMSG_BROADCAST_ADD_FAILURE,     //���������㲥��ʧ�� 

   	HHMSG_BROADCAST_CLOSE,           //�����㲥��һ���Ͽ� 

   	HHMSG_SENSOR_CAPTURE,            //̽ͷ������ץ�� 

   	HHMSG_COM_DATA,                  //���ڲɼ����� 

   	HHMSG_ALARM_LOST,                //������ʧ                   98ϵ��58ϵ��֮ǰ�豸�ô˶���

    HHMSG_ALARM_OUTPUT_NEW,          //�������(��)               98ϵ��58ϵ���Ժ��豸�ô˶���
    HHMSG_ALARM_LOST_NEW,            //������ʧ(��)               98ϵ��58ϵ���Ժ��豸�ô˶���
    HHMSG_PICCHN_CLOSE,              //ץ��ͨ�����ӹر� 
	
	HHMSG_NETWORK_FAULT,			//�������(��)

}HHMSG_NOTIFY;


//8��������
typedef enum _HHERR_CODE
{
	HHERR_SUCCESS,					//�����ɹ�
	HHERR_FAILURE,					//����ʧ��
	HHERR_REFUSE_REQ,				//���󱻾ܾ�
	HHERR_USER_FULL,				//��¼�û�����
	HHERR_PREVIEW_FULL,				//Ԥ���û�����
	HHERR_TASK_FULL,				//ϵͳ����æ�����᳢������
	HHERR_CHANNEL_NOT_EXIST,		//Ҫ�򿪵�ͨ�������ڻ�����
	HHERR_DEVICE_NAME,				//�򿪵��豸������
	HHERR_IS_TALKING,				//���ڶԽ�
	HHERR_QUEUE_FAILUE,				//���г���
	HHERR_USER_PASSWORD,			//�û����������ϵͳ��ƥ��
	HHERR_SHARE_SOCKET,				//socket ����
	HHERR_RELAY_NOT_OPEN,			//ת������ķ���δ��
	HHERR_RELAY_MULTI_PORT,			//ת���ಥ�˿ڴ���
	HHERR_VIEWPUSH_CHANNEL_USING,	//��Ƶ�����ͨ���Ѿ���ռ��
	HHERR_VIEWPUSH_DECODE_TYPE,		//��Ƶ����ͨ���Ľ����ʽ����0ͨ��(4cif,2cif,cif),1ͨ��(2cif,cif),2ͨ��(cif),3ͨ��(cif)
	HHERR_AUTO_LINK_FAILURE,		//ת�����Զ�����ʧ��
	HHERR_NOT_LOGON,
	HHERR_IS_SETTING,
	HHERR_COMMAND_FAILURE,
	
	HHERR_INVALID_PARAMETER=100,	//���������Ч
	HHERR_LOGON_FAILURE,			//��¼ʧ��
	HHERR_TIME_OUT,					//������ʱ
	HHERR_SOCKET_ERR,				//SOCKET����
	HHERR_NOT_LINKSERVER,			//��δ���ӷ�����
	HHERR_BUFFER_EXTCEED_LIMIT,		//ʹ�û��峬������	
	HHERR_LOW_PRIORITY,				//����Ȩ�޲���
	HHERR_BUFFER_SMALL,				//����̫С
	HHERR_IS_BUSY,					//ϵͳ������æ
	HHERR_UPDATE_FILE,				//�����ļ�����
	HHERR_UPDATE_UNMATCH,			//�����ļ��ͻ�����ƥ��
	HHERR_PORT_INUSE,				//�˿ڱ�ռ��
	HHERR_RELAY_DEVICE_EXIST,		//�豸���Ѿ�����
	HHERR_CONNECT_REFUSED,			//����ʱ���ܾ�
	HHERR_PROT_NOT_SURPPORT,		//��֧�ָ�Э��

	HHERR_FILE_OPEN_ERR,            //���ļ�ʧ��
	HHERR_FILE_SEEK_ERR,            //fseekʧ�� 
	HHERR_FILE_WRITE_ERR,           //fwriteʧ�� 
	HHERR_FILE_READ_ERR,            //freadʧ�� 
	HHERR_FILE_CLOSING,             //���ڹر��ļ� 
	
}HHERR_CODE;

//9��������������
typedef enum _HHCMD_NET
{
	HHCMD_GET_ALL_PARAMETER,		//0. �õ����б���������
	HHCMD_SET_DEFAULT_PARAMETER,	//1. �ָ����б�����Ĭ�ϲ���
	HHCMD_SET_RESTART_DVS,			//2. ����������
	HHCMD_GET_SYS_CONFIG,			//3. ��ȡϵͳ����
	HHCMD_SET_SYS_CONFIG,			//4. ����ϵͳ����
	HHCMD_GET_TIME,					//5. ��ȡ������ʱ��
	HHCMD_SET_TIME,					//6. ���ñ�����ʱ��
	HHCMD_GET_AUDIO_CONFIG,			//7. ��ȡ��Ƶ����
	HHCMD_SET_AUDIO_CONFIG,			//8. ������Ƶ����
	HHCMD_GET_VIDEO_CONFIG,			//9. ��ȡ��Ƶ����
	HHCMD_SET_VIDEO_CONFIG,			//10.������Ƶ����
	HHCMD_GET_VMOTION_CONFIG,		//11.��ȡ�ƶ��������
	HHCMD_SET_VMOTION_CONFIG,		//12.�����ƶ��������
	HHCMD_GET_VMASK_CONFIG,			//13.��ȡͼ����������
	HHCMD_SET_VMASK_CONFIG,			//14.����ͼ����������
	HHCMD_GET_VLOST_CONFIG,			//15.��ȡ��Ƶ��ʧ����
	HHCMD_SET_VLOST_CONFIG,			//16.������Ƶ��ʧ����
	HHCMD_GET_SENSOR_ALARM,			//17.��ȡ̽ͷ�����������
	HHCMD_SET_SENSOR_ALARM,			//18.����̽ͷ�����������
	HHCMD_GET_USER_CONFIG,			//19.��ȡ�û�����
	HHCMD_SET_USER_CONFIG,			//20.�����û�����
	HHCMD_GET_NET_CONFIG,			//21.��ȡ�������ýṹ
	HHCMD_SET_NET_CONFIG,			//22.�����������ýṹ
	HHCMD_GET_COM_CONFIG,			//23.��ȡ��������
	HHCMD_SET_COM_CONFIG,			//24.���ô�������
	HHCMD_GET_YUNTAI_CONFIG,		//25.��ȡ������̨��Ϣ
	HHCMD_SET_YUNTAI_CONFIG,		//26.����������̨��Ϣ
	HHCMD_GET_VIDEO_SIGNAL_CONFIG,	//27.��ȡ��Ƶ�źŲ��������ȡ�ɫ�ȡ��Աȶȡ����Ͷȣ�
	HHCMD_SET_VIDEO_SIGNAL_CONFIG,	//28.������Ƶ�źŲ��������ȡ�ɫ�ȡ��Աȶȡ����Ͷȣ�
	HHCMD_SET_PAN_CTRL,				//29.��̨����
	HHCMD_SET_COMM_SENDDATA,		//30.͸�����ݴ���
	HHCMD_SET_COMM_START_GETDATA,	//31.��ʼ�ɼ�͸������
	HHCMD_SET_COMM_STOP_GETDATA,	//32.ֹͣ�ɼ�͸������
	HHCMD_SET_OUTPUT_CTRL,			//33.�̵�������
	HHCMD_SET_PRINT_DEBUG,			//34.������Ϣ����
	HHCMD_SET_ALARM_CLEAR,			//35.�������
	HHCMD_GET_ALARM_INFO,			//36.��ȡ����״̬�ͼ̵���״̬
	HHCMD_SET_TW2824,				//37.���ö໭��оƬ����(����)
	HHCMD_SET_SAVE_PARAM,			//38.���ñ������
	HHCMD_GET_USERINFO,				//39.��ȡ��ǰ��½���û���Ϣ
	HHCMD_GET_DDNS,					//40.��ȡDDNS
	HHCMD_SET_DDNS,					//41.����DDNS
	HHCMD_GET_CAPTURE_PIC,			//42.ǰ��ץ��
	HHCMD_GET_SENSOR_CAP,			//43.��ȡ����ץ������
	HHCMD_SET_SENSOR_CAP,			//44.���ô���ץ������
	HHCMD_GET_EXTINFO,				//45.��ȡ��չ����
	HHCMD_SET_EXTINFO,				//46.������չ����
	HHCMD_GET_USERDATA,				//47.��ȡ�û�����
	HHCMD_SET_USERDATA,				//48.�����û�����
	HHCMD_GET_NTP,					//49.��ȡNTP����
	HHCMD_SET_NTP,					//50.����NTP����
	HHCMD_GET_UPNP,					//51.��ȡUPNP����
	HHCMD_SET_UPNP,					//52.����UPNP����
	HHCMD_GET_MAIL,					//53.��ȡMAIL����
	HHCMD_SET_MAIL,					//54.����MAIL����
	HHCMD_GET_ALARMNAME,			//55.��ȡ����������
	HHCMD_SET_ALARMNAME,			//56.���ñ���������
	HHCMD_GET_WFNET,				//57.��ȡ������������
	HHCMD_SET_WFNET,				//58.����������������
	HHCMD_GET_SEND_DEST,			//59.������Ƶ������Ŀ���
	HHCMD_SET_SEND_DEST,			//60.������Ƶ������Ŀ���
	HHCMD_GET_AUTO_RESET,			//61.ȡ�ö�ʱ����ע��
	HHCMD_SET_AUTO_RESET,			//62.���ö�ʱ����ע��
	HHCMD_GET_REC_SCHEDULE,			//63.ȡ��¼�����
	HHCMD_SET_REC_SCHEDULE,			//64.����¼�����
	HHCMD_GET_DISK_INFO,			//65.ȡ�ô�����Ϣ
	HHCMD_SET_MANAGE,				//66.��������Ͳ���
	HHCMD_GET_CMOS_REG,				//67.ȡ��CMOS����
	HHCMD_SET_CMOS_REG,				//68.����CMOS����
	HHCMD_SET_SYSTEM_CMD,			//69.����ִ������
	HHCMD_SET_KEYFRAME_REQ,			//70.���ùؼ�֡����
	HHCMD_GET_CONFIGENCPAR,			//71.ȡ����Ƶ����
	HHCMD_SET_CONFIGENCPAR,			//72.������Ƶ����
	//--------------------------
	HHCMD_GET_ALL_PARAMETER_NEW,	//73.��ȡ���в���
	HHCMD_FING_LOG,					//74.������־(��ѯ��ʽ:0��ȫ����1�������ͣ�2����ʱ�䣬3����ʱ������� 0xFF-�رձ�������)
	HHCMD_GET_LOG,					//75.��ȡ���ҵ�����־	
	HHCMD_GET_SUPPORT_AV_FMT,		//76.��ȡ�豸֧�ֵı����ʽ����߼���Ƶ��ʽ
	HHCMD_GET_VIDEO_CONFIG_NEW,		//77.��Ƶ������new
	HHCMD_SET_VIDEO_CONFIG_NEW,		//78.
	HHCMD_GET_VMOTION_CONFIG_NEW,	//79.�ƶ�����������new
	HHCMD_SET_VMOTION_CONFIG_NEW,	//80.
	HHCMD_GET_VLOST_CONFIG_NEW,		//81.��Ƶ��ʧ����������new
	HHCMD_SET_VLOST_CONFIG_NEW,		//82.
	HHCMD_GET_SENSOR_ALARM_NEW,		//83.̽ͷ����������new
	HHCMD_SET_SENSOR_ALARM_NEW,		//84.
	HHCMD_GET_NET_ALARM_CONFIG,		//85.������ϱ���������new
	HHCMD_SET_NET_ALARM_CONFIG,		//86.
	HHCMD_GET_RECORD_CONFIG,		//87.��ʱ¼�����
	HHCMD_SET_RECORD_CONFIG,		//88.
	HHCMD_GET_SHOOT_CONFIG,			//89.��ʱץ�Ĳ���
	HHCMD_SET_SHOOT_CONFIG,			//90.
	HHCMD_GET_FTP_CONFIG,			//91.FTP����
	HHCMD_SET_FTP_CONFIG,			//92.
	HHCMD_GET_RF_ALARM_CONFIG,		//93.���߱�������
	HHCMD_SET_RF_ALARM_CONFIG,		//94.
	HHCMD_GET_EXT_DATA_CONFIG,		//95.������չ����(��ƽ̨������������)
	HHCMD_SET_EXT_DATA_CONFIG,		//96.
	HHCMD_GET_FORMAT_PROCESS,		//97.��ȡӲ�̸�ʽ������
	HHCMD_GET_PING_CONFIG,			//98.PING ���û�ȡ
	HHCMD_SET_PING_CONFIG,			//99.PING ��������

	//����������
	DDCMD_GET_ALL_PARAMETER = 100,	//��ȡ��������������
	DDCMD_GET_TIME,					//��ȡϵͳʱ��
	DDCMD_SET_TIME,					//����ϵͳʱ��
	DDCMD_GET_SYS_CONFIG,			//��ȡϵͳ����
	DDCMD_SET_SYS_CONFIG,			//����ϵͳ����
	DDCMD_GET_NET_CONFIG,			//��ȡ��������
	DDCMD_SET_NET_CONFIG,			//������������
	DDCMD_GET_COM_CONFIG,			//��ȡ��������
	DDCMD_SET_COM_CONFIG,			//���ô�������
	DDCMD_GET_VIDEO_CONFIG,			//��ȡ��Ƶ����
	DDCMD_SET_VIDEO_CONFIG,			//������Ƶ����
	DDCMD_GET_ALARM_OPT,			//��ȡ����ѡ��
	DDCMD_SET_ALARM_OPT,			//���ñ���ѡ��
	DDCMD_GET_USER_INFO,			//��ȡ�û�������Ϣ
	DDCMD_SET_USER_INFO,			//�����û�������Ϣ
	DDCMD_GET_ALARM_RECORD,			//��ȡ������¼��Ϣ
	DDCMD_GET_ADRRESS_BOOK,			//��ȡ��ַ������
	DDCMD_SET_ADRRESS_BOOK,			//���õ�ַ������
	DDCMD_SET_COMM,					//���÷��ʹ�������
	DDCMD_SET_CMD,					//����͸��������
	DDCMD_GET_YUNTAI_INFO,			//��ȡ��̨��Ϣ
	DDCMD_GET_YUNTAI_CONFIG,		//��ȡ��̨����
	DDCMD_SET_YUNTAI_CONFIG,		//������̨����
	DDCMD_GET_ONELINK_ADDR,			//��ȡ��������·���ӵ���Ϣ
	DDCMD_SET_ONELINK_ADDR,			//���ý�������·���ӵ���Ϣ
	DDCMD_GET_CYCLELINK_ADDR,		//��ȡ������ѭ�����ӵ���Ϣ
	DDCMD_SET_CYCLELINK_ADDR,		//���ý�����ѭ�����ӵ���Ϣ
	DDCMD_GET_DDNS,					//��ȡDDNS
	DDCMD_SET_DDNS,					//����DDNS

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
	

	//��̨������������
	HHCMD_GET_DOME_PTZ_CFG,
	HHCMD_SET_DOME_PTZ_CFG,	
	HHCMD_GET_DOME_PRESET_CFG,
	HHCMD_SET_DOME_PRESET_CFG,	
	HHCMD_MAX_CONFIG,	
	//

	HHCMD_GET_EMPNO,
	HHCMD_SET_EMPNO,

}HHCMD_NET;


//10. ����Ƶ�����ʽ(��)
//��98ϵ�С�58ϵ��֮����豸������չ֡ͷ
//����Ƶ�ı�����Ϣ����ͨ����չ֡ͷEXT_FRAME_HEAD���߲��ſ������

//��Ƶ�����㷨
typedef enum _HH_VIDEO_ENCODER_E

{

    HH_VENC_NONE  = 0x00,

    HH_VENC_H264  = 0x01,

    HH_VENC_MPEG4 = 0x02,

    HH_VENC_MJPEG = 0x03,

    HH_VENC_JPEG  = 0x04,

}HH_VIDEO_ENCODER_E;

//��Ƶ�����㷨
typedef enum _HH_AUDIO_ENCODER_E

{

    HH_AENC_NONE  = 0x00,

    HH_AENC_G726  = 0x01,

    HH_AENC_G722  = 0x02,

    HH_AENC_G711  = 0x03,

    HH_AENC_ADPCM = 0x04,

    HH_AENC_MP3   = 0x05,

}HH_AUDIO_ENCODER_E;

//��Ƶ������
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

//��Ƶ��������(G726)
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

//1����Ƶ��Ƶ����
typedef struct _HHAV_INFO
{
    //��Ƶ����
    UINT			nVideoEncodeType;		//��Ƶ�����ʽ
    UINT			nVideoHeight;			//��Ƶͼ���
    UINT			nVideoWidth;			//��Ƶͼ���
    //��Ƶ����
    UINT			nAudioEncodeType;		//��Ƶ�����ʽ
    UINT			nAudioChannels;			//ͨ����
    UINT			nAudioBits;				//λ��
    UINT			nAudioSamples;			//������
}HHAV_INFO,*PHHAV_INFO;

#endif //HHAV_INFO_DEFINE

/*********************************  �����ص�����  ******************************/

//ʵʱ����Ƶ�������ص�
typedef int  ( *ChannelStreamCallback)(HANDLE hOpenChannel,void *pStreamData,UINT dwClientID,void *pContext,ENCODE_VIDEO_TYPE encodeVideoType,ULONG frameno);

//ʵʱ�Խ���Ƶ�������ص�
typedef int  ( *TalkStreamCallback)(void *pTalkData,UINT nTalkDataLen,void *pContext);

//��Ϣ֪ͨ��֪ͨ����
typedef int  ( *MsgNotifyCallback)(DWORD dwMsgID,DWORD ip,DWORD port,HANDLE hNotify,void *pPar);

//����û����ͻ��˵�½ʱ���
typedef int  (*CheckUserPsw)(const CHAR *pUserName,const CHAR *pPsw);

//�ͻ��˴��ݵ���Ϣ
typedef int  (*ServerMsgReceive)(ULONG ip,ULONG port,CHAR *pMsgHead);

//����
typedef int	 (*ServerUpdateFile)(int nOperation,int hsock,ULONG ip,ULONG port,int nUpdateType,CHAR *pFileName,CHAR *pFileData,int nFileLen);

//

//3��ת��������û����ص�
typedef int	 (*RelayCheckUserCallback)(RELAY_TYPE relayType,UINT dwClientIP,USHORT wClientPort,CHAR *pszUserName,CHAR *pszPassword,CHAR *pszDeviceName,UINT dwRequstChannel,INT bOnline,CHAR *pDeviceIP,UINT *pdwDevicePort,CHAR *pContext);

//4�����ķ�����ģʽ�û����ص�
typedef int	 (*CenterCheckUserCallback)(INT bOnLine,DVS_MACHINE_TYPE machineType,UINT dwDeviceID,UINT dwChannelNum,UINT ip,USHORT port,CHAR *pszDeviceName,CHAR *pszUserName,CHAR *pszPassword,LPVOID pNetPar);

//5������¼��NVS�ص�
typedef void (*SearchRecNVSCallback)(CHAR *szNvsBuffer,int nBufferLen);

//6������¼���ļ�
//typedef void (WINAPI *SearchRecFileCallback)(void *pRecFile);
typedef void  (*SearchRecFileCallback)(UINT dwClientID,void *pRecFile);

//7������Ϣ�ص�����
typedef int	 (*MessageNotifyCallback)(UINT wParam, UINT lParam);

//8.����
typedef int (*CallbackServerFind)(DVS_MACHINE_TYPE nDeviceType,char *pDeviceName,
								char *pIP,unsigned char macAddr[6],unsigned short wPortWeb,unsigned short wPortListen,char *pSubMask,
								char *pGateway,char *pMultiAddr,char *pDnsAddr,unsigned short wMultiPort,int nChannelNum,int nFindCount,unsigned long dwDeviceID);


/******************************  �ġ��ӿڽṹ���Ͷ���  ***************************/
//2������Ƶ����֡ͷ
typedef struct _HV_FRAME_HEAD
{
	USHORT	zeroFlag;				// 0
	UCHAR   oneFlag;				// 1
	UCHAR	streamFlag;				// ����֡��־ FRAME_FLAG_VP��FRAME_FLAG_VI��FRAME_FLAG_A
	
	ULONG	nByteNum;				//����֡��С
	ULONG	nTimestamp;				//ʱ���
}HV_FRAME_HEAD;

//3,�������
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

//4������֪ͨ��Ϣ�ṹ
typedef struct _ALARM_MSG_NOTIFY
{
	HANDLE					hLogonServer;
	UINT					dwClientID;
	UINT					dwServerIP;
	UINT					dwServerPort;
	ALARM_STATUS_OUTPUT		alarmStatus;
}ALARM_MSG_NOTIFY;

//98ϵ�С�58ϵ��֮����豸�������½ṹ

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


//5������ץ��ͼ��
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

//6�����ڲɼ�����
//��������
typedef struct __COM_CONFIG
{
	UINT 				Baudrate;						//���ڲ�����				300---115200
	UCHAR				Databit;						//��������λ����			5=5λ 6=6λ 7=7λ 8=8λ	����=8λ
	UCHAR				Stopbit;						//ֹͣλλ��				1=1λ 2=2λ ����=1λ
	UCHAR				CheckType;						//У��						0=��  1=��  2=ż  3=��1  4=��0 
	UCHAR				Flowctrl; 						//������/Ӳ����/������		����
}COM_CONFIG;
//͸��ͨѶ
typedef struct __COMM_CTRL
{
	UCHAR				COMMNo;							//���ں�	0 ~ 1
	UCHAR				AD[3];
	
	COM_CONFIG			COMConfig;						//��������
	USHORT				DataLength;						//���ݳ���
	UCHAR				Data[256];						//����
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

//7������Ƶͨ������
typedef struct _HHOPEN_CHANNEL_INFO
{
	UINT					dwClientID;
	UINT					nOpenChannel;
	NET_PROTOCOL_TYPE		protocolType;
	ChannelStreamCallback	funcStreamCallback;
	void					*pCallbackContext;
}HHOPEN_CHANNEL_INFO;

//����ṹ����ǰ�Ľṹ��С��ȫ��ͬ��
//���Ҽ�����ǰ�Ľṹ��ʵ�ֶ�98ϵ�к�
//58ϵ�����������Ļ�ȡ��

typedef struct _HHOPEN_CHANNEL_INFO_EX
{
        ULONG                 dwClientID;             //�ص�����	(��Ӧ�ص��������dwClientID)
        UINT                  nOpenChannel:8;         //ͨ���ţ�0 �� 3��
        UINT                  nSubChannel:8;          //0: ��������      1: �򿪴�����
        UINT                  res:16;                 //����
        NET_PROTOCOL_TYPE     protocolType;           //���ӷ�ʽ��TCP��UDP���ಥ��  
        ChannelStreamCallback funcStreamCallback;     //����Ƶ�����ݻص����� 
        void                                          *pCallbackContext;   //�ص�����2(��Ӧ�ص��������pContext) 
}HHOPEN_CHANNEL_INFO_EX;

//8������Ƶͨ������
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

//9���򿪵ķ�������Ϣ

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
//10���򿪵�ͨ����Ϣ
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

//11���򿪵Ľ���������ͨ����Ϣ
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
	UINT				dwChannelNum;	//���������·��
}HH_VIEWPUSH_INFO;

//12���Խ�����Ϣ
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

//13�������㲥���û���Ϣ
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

//14��ת����Ƶ������
typedef struct _HH_RELAY_NVS
{
	RELAY_TYPE			relayType;
	CHAR				szServerIP[MAX_IP_NAME_LEN+1];
	USHORT				wServerPort;
	CHAR				szDeviceName[DVS_NAME_LEN+1];
	UINT				dwChannelNo;
	UINT				dwCount;
}HH_RELAY_NVS;	

//15���ٷֱ���Ϣ֪ͨ
typedef struct _HH_PERCENT_NOTIFY
{
	HANDLE				hLogon;
	UINT				dwClientID;
	UINT				dwPercent;
}HH_PERCENT_NOTIFY;

//16����Ƶ�ļ�����
typedef struct _HHFILE_INFO
{
	CHAR                szFileName[MAX_PATH];
	CHAR				szServerIP[MAX_IP_NAME_LEN+1];
	USHORT				wServerPort;
	CHAR				szUserName[USER_NAME_LEN+1];
	CHAR				szUserPassword[USER_PASSWD_LEN+1];
	INT                	bRelay     ; // ���ļ��Ƿ�ͨ��ת��
}HH_FILE_INFO;

//17������Ƶ�ļ�����
typedef struct _HHOPEN_FILE_INFO
{
	UINT				dwClientID  ;
	UINT				nOpenChannel;
	NET_PROTOCOL_TYPE	protocolType;
	CHAR				szDeviceName[DVS_NAME_LEN+1];
	HH_FILE_INFO        hhFile      ;       
	CHAR                szOpenMode[5];
	UINT				dwSocketTimeOut;
	
    // ���
	UINT				dwFileSize;         // �ļ���С
	UINT				dwStartTime;        // ���ſ�ʼʱ��(����)
	UINT				dwEndTime;          // ���Ž���ʱ��(����)
	
	UINT				nVideoEncodeType;	//��Ƶ�����ʽ
	UINT				nAudioEncodeType;	//��Ƶ�����ʽ	
}HHOPEN_FILE_INFO;

//18��������������������NVS
typedef struct _HH_SEARCH_REC_NVS
{
	UINT				dwClientID  ;
	// �洢¼���ļ�������
	CHAR                Date[11];// ����1 ¼������ yyyy-mm-dd
    UCHAR               recType ;// ����2 ¼������: 0-���У�1-������2-�ֶ���3-��ʱ
	
	//SearchRecNVSCallback	funcSearchRecNvsCallback;	
}HH_SEARCH_REC_NVS;

// 19��������������������¼���ļ�
typedef struct _HH_SEARCH_REC_FILE
{
	UINT				dwClientID  ;
	
	// �洢¼���ļ�������
    CHAR                szDir[MAX_PATH]; // ����1: " Datae\\Ip-NVS\\Camera\\"
	CHAR				szTime1[6];      // ����2 ʱ���1 hh:mm
	CHAR				szTime2[6];      // ����2 ʱ���2 hh:mm
    UCHAR               recType ;	     // ����3 ¼������: 0-���У�1-������2-�ֶ���3-��ʱ
	
	SearchRecFileCallback	funcSearchRecFileCallback;
}HH_SEARCH_REC_FILE;

//20��ת����ѯ
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

/********************************  �塢�����ӿڶ���  *****************************/

//��������
HHERR_CODE		HHNET_Startup(unsigned short nBasePort, MsgNotifyCallback msgCallback,CheckUserPsw checkUserPswCallback,ServerUpdateFile updateCallback,ServerMsgReceive msgCmdCallback,StreamWriteCheck streamWriteCheckCallback,ChannelStreamCallback funcChannelCallback);
//�رշ���
HHERR_CODE		HHNET_Cleanup();

//��¼������
HHERR_CODE		HHNET_LogonServer(IN  CHAR *pServerIP,IN  UINT nServerPort,IN  CHAR *pDeviceName,IN	 CHAR *pUserName,IN	 CHAR *pUserPassword,IN UINT dwClientID,OUT  HANDLE *hLogonServer);
//ע��������
HHERR_CODE		HHNET_LogoffServer(IN  HANDLE hServer);
//��ȡ��¼��������Ϣ
HHERR_CODE		HHNET_ReadServerInfo(IN  HANDLE hServer,OUT  HH_SERVER_INFO *serverInfo);

//��������
HHERR_CODE		HHNET_Update(IN HANDLE hServer,IN UPDATE_TYPE nUpdateType,IN CHAR *pFilePathName);


//��ȡ��¼������������Ϣ
HHERR_CODE		HHNET_GetServerConfig(IN  HANDLE hServer,IN  HHCMD_NET nConfigCommand,OUT  CHAR *pConfigBuf,IN OUT  UINT *nConfigBufSize,IN  OUT  UINT *dwAppend);
//���õ�¼������������Ϣ
HHERR_CODE		HHNET_SetServerConfig(IN  HANDLE hServer,IN  HHCMD_NET nConfigCommand,IN   CHAR *pConfigBuf,IN  UINT nConfigBufSize,IN  UINT dwAppend);


//����Ƶͨ��
HHERR_CODE		HHNET_OpenChannel(IN  CHAR *pServerIP,IN  UINT nServerPort,IN  CHAR *pDeviceName,IN  CHAR *pUserName,IN  CHAR *pUserPassword,IN  HHOPEN_CHANNEL_INFO *pOpenInfo,OUT  HANDLE *hOpenChannel);
//�ر���Ƶͨ��
HHERR_CODE		HHNET_CloseChannel(IN  HANDLE hOpenChannel);

//��ȡ����Ƶͨ����Ϣ
HHERR_CODE		HHNET_ReadChannelInfo(IN  HANDLE hOpenChannel,OUT  HH_CHANNEL_INFO *channelInfo);


//����򿪶Խ�
HHERR_CODE		HHNET_TalkRequsest(IN  char *pServerIP,IN  UINT nServerPort,IN  char *pDeviceName,IN	 char *pUserName,IN	 char *pUserPassword,IN TalkStreamCallback funcTalkCallback,IN void *pContext, OUT  TALKHANDLE *hTalkback);
//�����Խ�
HHERR_CODE		HHNET_TalkStop();

//��ȡ�򿪶Խ���Ϣ
HHERR_CODE		HHNET_TalkReadInfo(HH_TALK_INFO *talkInfo);
//���ͶԽ�����
HHERR_CODE		HHNET_TalkSend(IN  TALKHANDLE hTalkback, IN char *pTalkData,IN UINT nDataLen);


//���������豸
/*HHERR_CODE		HHNET_SearchAllServer(UINT nTimeWait,
														  void( *CallbackServerFind)(DVS_MACHINE_TYPE nDeviceType,CHAR *pDeviceName,
														  CHAR *pIP,UCHAR macAddr[6],USHORT wPortWeb,USHORT wPortListen,CHAR *pSubMask,
														  CHAR *pGateway,CHAR *pMultiAddr,CHAR *pDnsAddr,USHORT wMultiPort,int nChannelNum));
*/
HHERR_CODE	 HHNET_SearchAllServer(UINT dwTimeWait,CallbackServerFind serFindCallback);

//������Ƶ��������������
HHERR_CODE		HHNET_ConfigServer(UCHAR macAddr[6],CHAR *pUserName,CHAR *pUserPassword,
													   CHAR *pIP,CHAR *pDeviceName,CHAR *pSubMask,CHAR *pGateway,CHAR *pMultiAddr,
													   CHAR *pDnsAddr,USHORT wPortWeb,USHORT wPortListen,USHORT wPortMulti);


void HHNET_UpdatePercentNotify(int hsock,ULONG nPercent);


/************************  ����������Ƶ��������������Ϣ�ṹ  **********************/

//------------------------------(I)�������������ýṹ-----------------------------//
//1������ʱ��ṹ
typedef  struct  _DVS_DATE
{
	UCHAR		year;									//��
	UCHAR		month;									//��
	UCHAR		day;									//��
	UCHAR		week;									//��
	UCHAR		hour;									//Сʱ
	UCHAR		minute;									//����
	UCHAR		second;									//��
}PACKED DVS_DATE;

//2��ʱ��νṹ������һ�����ʼʱ��ͽ���ʱ��
typedef struct _TIME_SEGMENT
{
	UCHAR 		bDetectOpen;							//��⿪��
	UCHAR        nBgnHour ;								//��ʼʱ
	UCHAR        nBgnMinute ;							//��ʼ��
	UCHAR        nEndHour ;								//����ʱ
	UCHAR        nEndMinute ;							//������
}PACKED TIME_SEGMENT;

//3����Ƶ����
typedef struct _AUDIO_CONFIG
{
	UCHAR		Open:1;									//��Ƶ�Ƿ��
	UCHAR		MicOrLine:1;							//��Ƶ����ģʽ����˻�������
	UCHAR		resver:6;
	UCHAR		Type;
	UCHAR		AD[2];
				//ѹ����ʽ
	UINT		Bitrate ;								//����
	UINT		SampleBitrate ;
}PACKED AUDIO_CONFIG;

//4����Ƶ����
typedef struct _VIDEO_CONFIG
{	
	UINT		KeyInterval;							//I ֡���
	UINT		Bitrate ;								//����
	UCHAR		Qulity;									//����1--31
	UCHAR		AD[3];	
	
	float		FrameRate ;								//֡��
	UCHAR		BitflowType; 							//�������� 		   0:VBR,1:CBR
	
	UCHAR		DateOSD; 								// 0:����������,   1:�������� 
	UCHAR		TimeOSD; 								// 0:������ʱ��,   1:����ʱ�� 
	UCHAR		WeekOSD; 								// 0:����������,   1:�������� 
	UCHAR		TitleOSD;								// 0:�����ӱ���,   1:���ӱ��� 
	UCHAR		BitrateOSD;								// 0:����������,   1:�������� 	
	CHAR    	Title[CAM_TITLE_LEN+ 1];				// �����ַ�        16���ַ�  8������
	
	UCHAR 		Brightness;								//����
	UCHAR 		Hue;									//ɫ��
	UCHAR 		Saturation;								//���Ͷ�
	UCHAR 		Contrast;								//�Աȶ�
	UCHAR 		Protocol;								//Э��
	UCHAR 		YTAddr;									//��������ַ
	UCHAR 		AE[3];
}PACKED VIDEO_CONFIG;

//5���ƶ��������
typedef struct _VIDEO_MOTION_CONFIG
{
	UCHAR 		DetectLevel;							//�ƶ����������
	UCHAR 		DetectOpen;								//�ƶ���⿪��
	USHORT 		AutoClearTime;							//�ƶ������Զ����ʱ��	
	UCHAR 		Output;									//�ƶ������������				 0---3	
	UCHAR 		Record;									//�ƶ���������¼��				 0---3	
	UCHAR 		DetectTest;								//�ƶ����������Կ���
	UCHAR 		AD[1];
	UINT 		DetectArea[18];							//�ƶ��������	
	TIME_SEGMENT	tSchTable[8] ;						//�ƶ����ʱ���1				 0: ÿ��
}PACKED VIDEO_MOTION_CONFIG;

//6��ͼ����������
typedef struct _VIDEOMASK_CONFIG 
{
	UCHAR 		MaskOpen;								//��Ƶ���ο���		0:��         1����
	UCHAR		AD[3];
	UINT 		MaskArea[18];							//��Ƶ��������	
}PACKED VIDEOMASK_CONFIG;

//7����Ƶ��ʧ����
typedef struct _VIDEOLOSE_CONFIG
{
	UCHAR		DetectOpen;								//��Ƶ��ʧ���
	UCHAR 		Output;									//��Ƶ��ʧ�����������			 0---3		
	UCHAR 		Record;									//��Ƶ��ʧ����¼��				 0---3	
	UCHAR		AD[1];
	USHORT		AutoClearTime;							//��Ƶ��ʧ�����Զ����ʱ��
}PACKED VIDEOLOSE_CONFIG;

//8��̽ͷ�����������
typedef struct _SENSOR_CONFIG 
{
	UCHAR		SensorType;								//0:����̽ͷ	1:����̽ͷ
	UCHAR 		DetectOpen;								//��⿪��
	USHORT 		AutoClearTime;							//̽ͷ�����Զ����ʱ��	
	UCHAR 		Output;									//̽ͷ�����������				 0---3	
	UCHAR 		Record;									//̽ͷ��������¼��				 0---3	
	TIME_SEGMENT	tSchTable[8] ;						//̽ͷ���ʱ���1				 0: ÿ��
}PACKED SENSOR_CONFIG;

//9���û�����
typedef struct _USER_CONFIG
{
	UINT 		Level;									//Ȩ��
	CHAR 		Name[USER_NAME_LEN + 1];				//�û���
	CHAR 		Password[USER_PASSWD_LEN + 1];			//�û�����
	CHAR 		AD[2];
} PACKED USER_CONFIG;

//10���������ýṹ
typedef struct _NET_CONFIG
{	
	UINT             	IPAddr ;						//IP��ַ
	UINT             	SubNetMask ;					//����
	UINT             	GateWay ;						//����

   	USHORT             	ComPortNo;						//���ý��տͻ�������˿ں�        UDP	
   	USHORT             	WebPortNo;						//Webserver�˿�     			  TCP
	UINT             	MultiCastIPAddr ;				//�ಥIP��ַ
   	USHORT             	MultiCastPortNo;				//UDP������ʼ�˿�<�ಥ����>
	
	UCHAR			   	RT8139MAC[6];      				//�˹�����������MAC��ַ		5---0��Ч
   	UCHAR             	DHCP;							//DHCP ����					0	��		1:��
   	
	UCHAR             	PppoeOpen;						//PPPOE ����     	
	CHAR				PppoeName[PPPPOE_NAME_LEN+1];	//�����û���
	CHAR				PppoePass[PPPPOE_PASSWD_LEN+1]; //��������	
	UINT             	PppoeTimes;   					//����ʱ��
	UINT             	PppoeIPAddr ;					//PPPOEIP��ַ		�����ش�IP	
	
	UINT				DdnsOpen;						//DDNS����
	CHAR				DdnsName[DDNS_NAME_LEN+1];		//ע����������
	CHAR				DdnsPass[DDNS_PASS_LEN+1];		//ע����������	
	
	CHAR				DdnsIP[DDNS_SERVER_NAME_LEN+1];	//DDNS������
	CHAR				AAD[1];
	USHORT				DdnsPortNo;						//DDNS�������˿�
	USHORT				DdnsMapWebPort;					//����WEBӳ��˿�
	USHORT				DdnsMapDataPort;				//��������ӳ��˿�
	CHAR				ABD[2];

	UINT				DNSHostIP;						//DNS��IP

	INT					ConnectCenter;					//�Ƿ�������������
	CHAR				ConnectCenterIP[DDNS_SERVER_NAME_LEN+1];//����IP
	CHAR				ACD[1];
	USHORT				ConnectCenterPort;						//���Ķ˿�

	USHORT				appFunction;					//ʵ�ֹ��ܶ���,��bitλ��ʾ:0-PPPOE,1-NTP,2-UPNP,3-WF,4-MAIL,5-������
	UCHAR				tcpSendInterval;
	UCHAR				udpSendInterval;
	USHORT				PacketMTU;

	UCHAR				CaptureMode;					//ץ��ģʽ
	UCHAR				CapturePort[MAX_SENSOR_NUM];	//ץ��ͨ��(0-3bit: �ֱ��ʾ1 ~ 4��ͨ��  1:��  0: ��)
	CHAR				AED[1];
	union
	{
	  UINT       DdnsIP2;						
 	  UINT       DNSHostIP2;						
	};						//DDNS 2��IP,�������ֽڴ���
	USHORT				DdnsPortNo2;					//DDNS 2�Ķ˿�

	CHAR				sysByname[DVS_NAME_LEN+1];		//����
	UCHAR				domainSetState;					//0���ɹ���1�����ִ��ڣ��޸���������2���������룻3��ʧ��
}PACKED NET_CONFIG;


/**************************************************************************
2011.5.22�������3G���������ݽṹ
***************************************************************************/
typedef struct _3G_NET_CONFIG_S
{
	unsigned char      nSize;
	unsigned char       n3gOpen;					//3g ����
	unsigned char       n3gType;					//3g ���� 0 evdo 1 wcdma 2 td
	unsigned char       n3gSecType;				    //3g ��֤����  0 �Զ�ѡ�� 1 pap 2 chap
	unsigned char       n3gParam;		            //���Ҫ����Щ���� 
	char        		sz3gUsr[32];				//3g �����û���			
	char        		sz3gPsw[32];				//3g ��������
	char        		sz3gApn[32];				//3g apn 
	char        		sz3gTelNum[16];           	//3g ���ź���
	char        		sz3gLocalIp[16];
	char        		sz3gRemoteIp[16];
	char        		sz3gPara1[16];
	char        		sz3gPara2[16];
	unsigned char       res[16]; 
}PACKED T3G_NET_CONFIG_S;//200�ֽ�


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
	unsigned char	  c3gstatus	   ;// 3G״̬
	unsigned char     res          ;// ����ʧ�ܴ���,���Բ�ʹ��
	char      softWareVer[128];   // software version
	char      hardWareVer[128];   // hardware version
	char      moduleType[32] ;   // module type
}PACKED HH_3G_INFO_S, *PHH_3G_INFO_S;

// 3G��������ģʽ   0-������ 1-ÿ������ʱ��  2-ÿ������ʱ��  3-������ÿ���ʱ�䣬Ҳ����ÿ�µ�ʱ��
typedef enum T3G_TIME_CTRL_MODE
{
	NO_LIMITED    = 0x00,
	DAY_LIMITED   = 0x01,
	MONTH_LIMITED = 0x02,
	ALL_LIMITED   = 0x03,
}T3G_TIME_CTRL_MODE;// ����ģʽ


/**************************************************************************
2011.11.3���������Ƶ������������ݽṹ
***************************************************************************/
//��Ƶ�����ɫ�ʵ��ں�������ã����Ͷ���
typedef enum _VIDEO_IN_SENSOR_E
{
	//ɫ��
	VCT_BRIGHTNESS	=	0X00000001,//����
	VCT_HUE			=	0X00000002,//ɫ��
	VCT_CONTRAST	=	0X00000004,//�Աȶ�
	VCT_SATURATION	=	0X00000008,//���Ͷ�
	VCT_SHARPNESS	=	0X00000010,//���
	VCT_RED			=	0X00000020,//��ɫ
	VCT_GREEN		=	0X00000040,//��ɫ
	VCT_BLUE		=	0X00000080,//��ɫ
	VCT_GAMMA		=	0X00000100,//Gamma

	//��ƽ��
	VCT_AUTOAWB		=	0X00000200,//�Զ���ƽ��
	VCT_AWBRED		=	0X00000400,//��ƽ�� ��
	VCT_AWBGREEN	=	0X00000800,//��ƽ�� ��
	VCT_AWBBLUE		=	0X00001000,//��ƽ�� ��

	//����
	VCT_AUTOAGC		=	0X00002000,//�Զ�����
	VCT_AGCLEVEL	=	0X00004000,//����ֵ

	//���ⲹ��
	VCT_AUTOBLC		=	0X00008000,//�Զ�����
	VCT_BLCLEVEL	=	0X00010000,//����ֵ
	
	//�ع�
	VCT_AUTOEXPOSURE=	0X00020000,//�Զ��ع� 
	VCT_EXPOSURETIME=	0X00040000,//�ֶ��ع�ʱ�� 
	
	//����
	VCT_SHUTTERFIRST=	0X00080000,//���š��ع�����
	VCT_AUTOSHUTTER	=	0X00100000,//�Զ�����
	VCT_SHUTTERSPEED=	0X00200000,//�����ٶ�
	VCT_SLOWSHUTTER	=	0X00400000,//������
	VCT_SLOWSHUTTERLEVEL=0X00800000,//�������ٶ�

	VCT_AUTOAWBMODE =	0X01000000,//1080p Hispeed�Զ���ƽ��ģʽ

	VCT_SENSOR_ALL	=	0xFFFFFFFF,//�������Բ���
}VIDEO_IN_SENSOR_E;

//��Ƶ���볡�����ã����Ͷ���
typedef enum _VIDEO_IN_SCENE_E
{
	//��Ȧ
	VCT_AUTOIRIS	=	0X00000001,//�Զ���Ȧ
	VCT_IRISLEVEL	=	0X00000002,//��Ȧ��ƽ

	//�۽�
	VCT_AUTOFOCUS	=	0X00000004,//�Զ��۽�
	VCT_FOCUSLEVEL	=	0X00000008,//����

	//�䱶
	VCT_ZOOMSPEED	=	0X00000010,//�䱶�ٶ�
	VCT_AUTOPTZSPEED=	0X00000020,//�����������

	//��ƽ����
	VCT_AUTOALC		=	0X00000040,//�Զ���ƽ����
	VCT_ALCLEVEL	=	0X00000080, //��ƽ����ֵ
	
	//��ת��
	VCT_CTB			=	0X00000100,//��ת��

	//����
	VCT_SCENE		=	0X00000200,//����
	VCT_MIRROR		=	0X00000400,//����
	VCT_FLIP		=	0X00000800,//��ת
	VCT_AUTOFLIP	=	0X00001000,//�Զ���ת
	VCT_PWDFREQ1	=	0X00002000,//����Ƶ��1
	VCT_PWDFREQ2	=	0X00004000,//����Ƶ��2

	//����
	VCT_IREXIST		=	0X00008000,//�Ƿ��к���
	VCT_IRCFMODE	=	0X00010000,//IRCFģʽ
	VCT_IRLIGHTTYPE	=	0X00020000,//���������
	//
	VCT_WDR 		=	0X00040000,//�Ƿ��п�̬
	VCT_WDRLEVEL	=	0X00080000,//��̬��ֵ
	VCT_LOWILLUM	=	0X00100000,//���ն�
	VCT_IMAGEMODE	=	0X00200000,//ͼ��ģʽ
	//
	VCT_VI_SIZE     =   0X00400000,//��Ƶ����ߴ�
	VCT_CTBLEVEL	=	0X00800000,//��ת�ڷ�ֵ������ת��Ϊ�Զ�ʱ��Ч
	VCT_MINFOCUSLEN =   0X01000000,//������С�۽�����
	VCT_IRLEVEL		=   0X02000000,//ҹ��������		
	VCT_LENSCORRECTION =0X04000000,//��ͷУ��		
	VCT_SMARTNR     = 	0x08000000,//���ܽ��� 0 ~ 255  0Ϊ��
	VCT_3DNR   	    =	0X10000000,//3D����		
	VCT_3DNRLEVEL	= 	0x20000000,//3D����ֵ

	VCT_SCENE_ALL	=	0xFFFFFFFF,//�������Բ���
}VIDEO_IN_SCENE_E;

//��Ƶ�����ɫ�ʵ��ں�������� size=64+32=96
typedef struct _VIDEO_IN_SENSOR_S
{
	VIDEO_IN_SENSOR_E	eValidSupport;	/*��Ч֧�ֵĲ������ò�������ʱ����Ч
											�ڻ�ȡ��ʱ����Ч�������ж��豸�Ƿ�֧�ָò���
										*/

	VIDEO_IN_SENSOR_E	eValidSetting;	/*������Ч�Ĳ������ò�����ȡʱ����Ч
											�����õ�ʱ����Ч������ָ���������õĲ���
										*/

	//ɫ��
	UInt8		byBrightness;		/*����;			0 ~ 255*/
	UInt8		byBrightnessDefault;/*����ȱʡֵ;	*/
	UInt8		byBrightnessStep;	/*���ȵ��ڲ���;	*/

	UInt8		byHue;				/*ɫ��;			0 ~ 255*/
	UInt8		byHueDefault;		/*ɫ��ȱʡֵ;	*/
	UInt8		byHueStep;			/*ɫ�ȵ��ڲ���;	*/
	
	UInt8		byContrast;			/*�Աȶ�;	0 ~ 255*/
	UInt8		byContrastDefault;	/*�Աȶ�ȱʡֵ;	0 ~ 255*/
	UInt8		byContrastStep;		/*�Աȶȵ��ڲ���;	0 ~ 255*/

	UInt8		bySaturation;		/*���Ͷ�;	0 ~ 255*/
	UInt8		bySaturationDefault;/*���Ͷ�ȱʡֵ;*/
	UInt8		bySaturationStep;	/*���Ͷȵ��ڲ���;*/

	UInt8		bySharpness;		/*���;		0 ~ 255*/
	UInt8		bySharpnessDefault;	/*���ȱʡֵ;*/
	UInt8		bySharpnessStep;	/*��ȵ��ڲ���;*/

	UInt8		byRed;				/*��ɫ;		0 ~ 255*/
	UInt8		byRedDefault;		/*��ɫȱʡֵ;*/
	UInt8		byRedStep;			/*��ɫ���ڲ���;*/

	UInt8		byGreen;			/*��ɫ;		0 ~ 255*/
	UInt8		byGreenDefault;		/*��ɫȱʡֵ;*/
	UInt8		byGreenStep;		/*��ɫ���ڲ���;*/

	UInt8		byBlue;				/*��ɫ;		0 ~ 255*/
	UInt8		byBlueDefault;		/*��ɫȱʡֵ;*/
	UInt8		byBlueStep;			/*��ɫ���ڲ���;*/

	UInt8		byGamma;			/*gamma;	0 ~ 255*/
	UInt8		byGammaDefault;		/*gammaȱʡֵ;*/
	UInt8		byGammaStep;		/*gamma���ڲ���;*/


	//��ƽ��
	UInt8		byAutoAwb;			/*�Զ���ƽ��;	0�Զ�, 1 �ֶ�*/
	
	UInt8		byAwbRed;			/*��ƽ�� ��;	0 ~ 255*/
	UInt8		byAwbRedDefault;	/*��ƽ�� ��ȱʡֵ;*/
	UInt8		byAwbRedStep;		/*��ƽ�� ����ڲ���;*/

	UInt8		byAwbGreen;			/*��ƽ�� ��;	0 ~ 255*/
	UInt8		byAwbGreenDefault;	/*��ƽ�� ��ȱʡֵ;*/
	UInt8		byAwbGreenStep;		/*��ƽ�� �̵��ڲ���;*/

	UInt8		byAwBblue;			/*��ƽ�� ��;	0 ~ 255*/
	UInt8		byAwBblueDefault;	/*��ƽ�� ��ȱʡֵ;*/
	UInt8		byAwBblueStep;		/*��ƽ�� �����ڲ���;*/

	//2011.6.20 ���������   1080P   byAgcLevel --> �������ֵ
	//						  720P   byAgcLevel --> AGC
	//							     byAutoAgc  --> �������ֵ
 	//����
	UInt8		byAutoAgc;			/*�Զ�����;		0�Զ�, 1 �ֶ�*/
	UInt8		byAgcLevel;			/*����ֵ;		0 ~ 255*/
	UInt8		byAgcLevelDefault;	/*����ֵȱʡֵ;*/
	UInt8		byAgcLevelStep;		/*����ֵ���ڲ���;*/


	//���ⲹ��
	UInt8		byAutoBlc;			/*�Զ�����;		0�Զ�, 1 �ֶ�*/
	UInt8		byBlcLevel;			/*����ֵ;		0 ~ 255*/
	UInt8		byBlcLevelDefault;	/*����ֵȱʡֵ;*/
	UInt8		byBlcLevelStep;		/*����ֵ���ڲ���;*/
	

	//�ع�
	UInt8		byAutoExposure;		/*0�Զ� 1 �ֶ�*/
	UInt16		wExpoSuretime;		/*�ֶ��ع�ʱ��	F1.6=16
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


	//����
	UInt8		byShutterFirst;		/*���š��ع�����;	0��������, 1 �ع�����*/
	UInt8		byAutoShutter;		/*�Զ�����;		0�Զ�, 1 �̶�*/
	UInt16		wShutterSpeed;		/*�����ٶ�;		1		= 1
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
	UInt8		bySlowShutter;				/*������;		0��,   1 ��*/

	UInt8		bySlowShutterLevel;			/*�������ٶ�;	0 ~ 255*/
	UInt8		bySlowShutterLevelDefault;	/*�������ٶ�ȱʡֵ;*/
	UInt8		bySlowShutterLevelStep;		/*�������ٶȵ��ڲ���;*/

	UInt8		byAwbAutoMode;	//�Զ���ƽ��ģʽ,������ƽ��Ϊ�Զ�ʱ��Ч
	UInt8		byRes[31];
}VIDEO_IN_SENSOR_S,*LPVIDEO_IN_SENSOR_S;

//��Ƶ���볡��������� size=32+64=96
typedef struct _VIDEO_IN_SCENE_S
{
	VIDEO_IN_SCENE_E	eValidSupport;/*��Ч֧�ֵĲ������ò�������ʱ����Ч
											�ڻ�ȡ��ʱ����Ч�������ж��豸�Ƿ�֧�ָò���
										*/

	VIDEO_IN_SCENE_E	eValidSetting;/*������Ч�Ĳ������ò�����ȡʱ����Ч
											�����õ�ʱ����Ч������ָ���������õĲ���
										*/


	//��Ȧ
	UInt8		byAutoIris;			/*�Զ���Ȧ;		0�Զ�, 1 �ֶ�*/

	UInt8		byIrisLevel;		/*��Ȧ��ƽ;			0 ~ 255*/
	UInt8		byIrisLevelDefault;	/*��Ȧ��ƽȱʡֵ;*/
	UInt8		byIrisLevelStep;	/*��Ȧ��ƽ���ڲ���;*/


	//�۽�
	UInt8		byAutoFocus;		/*�Զ��۽�;		0�Զ�, 1 �ֶ�*/

	UInt8		byFocusLevel;		/*����;				0 �� 255*/
	UInt8		byFocusLevelDefault;/*����ȱʡֵ;*/
	UInt8		byFocusLevelStep;	/*������ڲ���;*/


	//�䱶
	UInt8		byZoomSpeed;		/*�䱶�ٶ�;		0 ����,  1 �����ٶ�*/
	UInt8		byAutoPtzSpeed;		/*�����������; 0��,   1 ��*/


	//��ƽ����
	UInt8		byAutoAlc;			/*�Զ���ƽ����;	AutoALC	0�Զ� 1 �ֶ�*/

	UInt8		byAlcLevel;			/*��ƽֵ;			ALC Level	0 ~ 255*/
	UInt8		byAlcLevelDefault;	/*��ƽȱʡֵ;		ALC Level	*/
	UInt8		byAlcLevelStep;		/*��ƽֵ���ڲ���;	ALC Level	*/


	//��ת��
	UInt8		byCtb;				/*��ת��;		0��,   1 ��*/


	//����
	UInt8		byScene;			/*����;			0 ~ 255*/
	UInt8		byMirror;			/*����;			0��,   1 ��*/
	UInt8		byFlip;				/*��ת;			0��,   1 ��*/
	UInt8		byAutoFlip;			/*�Զ���ת;		0��,  1 ��*/
	UInt8		byPwdFreq1;			/*����Ƶ��1;	0 60HZ,	1 50HZ*/
	UInt8		byPwdFreq2;			/*����Ƶ��2;	0 60HZ,	1 50HZ,	2 ����*/


	//����
	UInt8		byIRExist;			/*�Ƿ��к���	0��,   1 ��*/
	UInt8		byIRCFMode;			/*IRcfģʽ;		0 OUT=>IN, 1 IN=>OUT*/
	UInt8		byIRLightType;		/*���������;	0 ������,  1 850mm,   2 950mm*/
	UInt8		byWDR;				/*��̬		0��,   1 ��*/
	UInt8		byWDRLevel;			/*��̬		0 ~ 255*/
	UInt8		byLowIllumination;	/*���ն�		1Ĭ��AF
													2���ն�AF�Ż�����
													3���նȵ��ԴAF�Ż�����
									*/
	UInt8		byImageMode;		/*ͼ��ģʽ		0 ģʽ 1��  1 ģʽ 2 */

	UInt16      u16ViWidth;         /*��Ƶ���� ���*/
	UInt16		u16ViHeight;        /*��Ƶ���� �߶�*/
	UInt8		byCtbLevel;			/*��ת�ڷ�ֵ���Զ���ת��ʱ��Ч*/
	UInt8		byMinFocusLen;		/*������С�۽�����*/			  
	UInt8		byIRLevel;			/*ҹ�������� */		          
	UInt8 		byLensCorrection; 	/*��ͷУ��	0: ��	1����  */ 
	UInt8       bySmartNR;			//���ܽ���  0 ~ 255 0: �� 
	UInt8       bySmartNRDefault;	//���ܽ���  Ĭ��ֵ 
	UInt8 		by3DNR; 			/*3D ����   0: ��	1����  */  
	UInt8       by3DNRLevel;		//3D����ֵ 2011.6.15 miaor
	UInt8		byRes[48];			//2011.6.20 CYG
}VIDEO_IN_SCENE_S,*LPVIDEO_IN_SCENE_S;

//��Ƶ���������ɫ�ʵ��ںͳ�������
//��С196(sizeof(VIDEO_IN_CFG_S))
typedef struct _VIDEO_IN_CFG_S
{
	UInt32				dwSize;		    /*�ṹ��С*/
	VIDEO_IN_SENSOR_S	struViSensor;	/*��Ƶ��������*/
	VIDEO_IN_SCENE_S	struViScene;	/*��Ƶ���볡���������*/
}VIDEO_IN_CFG_S,*LPVIDEO_IN_CFG_S;

typedef struct _TIME_SEGMENT_NEW 
{
	UINT 		bDetectOpen;				//��⿪��
	UCHAR        nBgnHour ;					//��ʼʱ
	UCHAR        nBgnMinute ;				//��ʼ��
	UCHAR        nEndHour ;					//����ʱ
	UCHAR        nEndMinute ;				//������
}TIME_SEGMENT_NEW;

typedef struct _T3G_TIME_CTRL_S			// 20101125 �ṹ����,ʵ���ֽڶ���
{
	BYTE		t3gtimectrlopen;			// 3G������ʱ�Ƿ��� 0-�ر�  1-����
	BYTE		t3gdaylimitedend;			// ��־λ-ÿ����ʱ����     0-δ��  1-�ѵ�
	BYTE		t3gmonthlimitedend;			// ��־λ-ÿ����ʱ����   0-δ��  1-�ѵ�
	BYTE		t3gdaylimited;				// ����ÿ�첦��ʱ��   0-������
	T3G_TIME_CTRL_MODE	t3gtimectrlmode;	// 3Gʱ������ģʽ
	DWORD		t3gdialusedtime;			// �Ѿ�����ʱ��
	DWORD		t3gmonthlimited;			// ����ÿ�²���ʱ��   0-������
	BYTE		t3openlimitedmonth;			// �����趨��ʱ���·�
	BYTE		t3openlimitedday;			// �����趨��ʱ�ĺ���
	BYTE		revers[2];					// �ֽڶ���
	TIME_SEGMENT_NEW	t3gtimesegment[4];	// ����ÿ��4�����趨ʱ���
}PACKED T3G_TIME_CTRL_S;					// 50���ֽ� = 1+4+4+1+1+1+4+1+1+4*(4+4)



typedef struct _T3Ginfo_S
{
	T3G_NET_CONFIG_S  t_3ginfo;
	T3G_TIME_CTRL_S   t_3gTime;
	HH_3G_INFO_S	  t_3ginfo1;
}T3Ginfo_S;


//12��������Ϣ����
typedef struct _DEBUG_CONFIG
{
	UCHAR				Status;							//0����		1: ��
}DEBUG_CONFIG;

//13������̵�������
typedef struct __OUTPUT_CTRL
{
	UCHAR				ChannelNo;						//�̵�����	0 ~ MAX_OUTPUT_NUM - 1
	UCHAR				Status;							//0����		1: ��	
}OUTPUT_CTRL;


//14����̨����
typedef struct __PAN_CTRL
{
	UCHAR				ChannelNo;						//ͨ����	0 ~ PORTNUM - 1
	UCHAR				COMMNo;							//���ں�	0 ~ 1
	UCHAR				PanType;						//��̨Э����� 0 ~ YUNTAI_PROTOCOL_NUM - 1
	UCHAR				PanCmd;							//��̨��������
	UCHAR				Data1;							//����1		��Ԥ�á����úţ�
	UCHAR				Data2;							//����2		�����ã�
}PAN_CTRL;

//16����Ƶ�źŲ���
typedef struct __VIDEO_SIGNAL_CONFIG
{
	UCHAR				ChannelNo;						//ͨ����	0 ~ PORTNUM - 1
	UCHAR 				ChannelNum;						//ͨ����<NVS�ܵ�ͨ��������Ϊ��·����·�Ĳ���Ĭ��ֵ�ǲ�ͬ��>
	UCHAR 				Brightness;						//����
	UCHAR 				Hue;							//ɫ��
	UCHAR 				Saturation;						//���Ͷ�
	UCHAR 				Contrast;						//�Աȶ�
}VIDEO_SIGNAL_CONFIG;

//17��TW2824����
typedef struct _TW2824_CTRL
{
	UCHAR				Page;							//ҳ
	UCHAR 				RegNo;							//�Ĵ���
	UCHAR 				Data;							//����
	UCHAR				AD[1];
	UINT				nReserved[8];					//����
}TW2824_CTRL;

//18��������Ϣ
typedef  struct  _ALARM_INFO
{
	UCHAR	SensorAlarm[MAX_SENSOR_NUM];				//̽ͷ����
	UCHAR	SensorAlarmOut[MAX_SENSOR_NUM];				//̽ͷ�������
	UCHAR	MotionAlarm[MAX_VIDEO_NUM];					//��Ƶ�ƶ�
	UCHAR	MotionAlarmOut[MAX_VIDEO_NUM];				//��Ƶ�ƶ��������
	UCHAR	ViLoseAlarm[MAX_VIDEO_NUM];					//��Ƶ��ʧ
	UCHAR	ViLoseAlarmOut[MAX_VIDEO_NUM];				//��Ƶ��ʧ�������
} ALARM_INFO;

//19����̨��Ϣ
typedef struct _YUNTAI_INFO
{
	CHAR 		Name[YUNTAI_NAME_LEN + 1];				//��̨����
	CHAR 		AD[3];
	COM_CONFIG	ComSet;									//ͨѶЭ��<������...>
}PACKED YUNTAI_INFO;

//20��������Ϣ
typedef struct _DVS_CONFIG
{
   	CHAR               	sysName[DVS_NAME_LEN + 1];		//����
	UCHAR				sysInputNum;					//·��
	UCHAR				sysType;						//�����ͺ�	0:CIF  1:HD1  2:D1  
	UCHAR				sysVideoFormat;					//�����ʽ	
    UCHAR				sysLanguage;					//����
    UCHAR				sysStandard;					//��ʽ		0:PAL  1:NTSC
    UCHAR				AD[2];
	UINT      			sysID;  						//ÿ̨�����и�ID��  	
	UINT      			sysVer;  						//����汾  		
}PACKED DVS_CONFIG;

//21����¼���û��û���Ϣ
typedef struct _USER_DETAIL
{
	INT					bLogon;							//TRUE-��½�û�,FALSE-Ԥ���û�
	UINT 				Level;							//Ȩ��
	CHAR 				Name[USER_NAME_LEN+1];			//�û���
	CHAR 				Password[USER_PASSWD_LEN+1];	//�û�����
	NET_PROTOCOL_TYPE	protocolType;					//Э��
	UINT				clientIP;						//IP
	UINT				clientPort;						//�˿�
}PACKED4 USER_DETAIL;
typedef struct _USER_INFO
{
	UINT				dwLogonNum;
	UINT				dwPreviewNum;
	USER_DETAIL			userDetail[MAX_LOGON_NUM+MAX_LINKVIEW_NUM+MAX_MULTIVIEW_NUM];
}PACKED4 USER_INFO;

//22��DDNS����
typedef struct _DDNS_SET
{
	INT					bDdnsStart;
	CHAR				szDdnsIP[DDNS_SERVER_NAME_LEN+1];
	UINT				dwDdnsPort;
	CHAR				szDdnsName[DVS_NAME_LEN+1];
	UINT				dwMapWebPort;
	UINT				dwMapDataPort;
}PACKED4 DDNS_SET;

//23�����в�����Ϣ
typedef struct _DVS_Parameter 
{
   	CHAR               	sysName[DVS_NAME_LEN + 1];		//����
	UCHAR				sysInputNum;					//·��
	UCHAR				sysType;						//�����ͺ�	0:CIF  1:HD1  2:D1  
	UCHAR				sysVideoFormat;					//�����ʽ	
    UCHAR				sysLanguage;					//����
    UCHAR				sysStandard;					//��ʽ		0:PAL  1:NTSC
    UCHAR				AD[2];
	UINT      			sysID;  						//ÿ̨�����и�ID��  	
	UINT      			sysVer;  						//����汾  			
	VIDEO_CONFIG		sysVideo[MAX_VIDEO_NUM];		//��Ƶ
	VIDEO_MOTION_CONFIG	sysVideoMotion[MAX_VIDEO_NUM];	//��Ƶ�ƶ�
	VIDEOMASK_CONFIG	sysVideoMask[MAX_VIDEO_NUM];	//��Ƶ����
	VIDEOLOSE_CONFIG	sysVideoLose[MAX_VIDEO_NUM];	//��Ƶ��ʧ
	AUDIO_CONFIG		sysAudio[MAX_AUDIO_NUM];		//��Ƶ
	NET_CONFIG			sysNet;							//��������
	COM_CONFIG			sysCom[MAX_COM_NUM];			//����
	SENSOR_CONFIG		sysSensor[MAX_SENSOR_NUM];		//���
	USER_CONFIG			sysUser[MAX_USER_NUM];			//�û�
	UCHAR				YunTaiProtocolNum;				//��ͷЭ����
	UCHAR				AFD[3];
	YUNTAI_INFO 		YunTaiInfo[MAX_YUNTAI_PROTOCOL_NUM];//Э����Ϣ
} PACKED DVS_Parameter ;

typedef struct _NTP_CONFIG
{
	UINT			ntpOpen;					//NTP����
	UINT			ntpTimeZone;				//ʱ��
	CHAR			ntpHost[DOMAIN_NAME_LEN];	//NTP Server
}NTP_CONFIG;
typedef struct _UPNP_CONFIG
{
	USHORT			upnpOpen;					//UPNP����
	UCHAR			upnpEthNo;					//UPNP���� 0�����ߣ�1������
	UCHAR			upnpMode;					//UPNPģʽ 0��ָ����1���Զ�
	USHORT			upnpPortWeb;				//UPNP WEB�˿�
	USHORT			upnpPortData;				//UPNP DATA�˿�
	UINT			upnpHost;					//UPNP����
	USHORT			upnpStatusWeb;				//UPNP WEB״̬
	USHORT			upnpStatusData;				//UPNP DATA״̬
}UPNP_CONFIG;
typedef struct _MAIL_CONFIG
{
	CHAR			smtpServer[DOMAIN_NAME_LEN];	//���ͷ�����
	CHAR			pop3Server[DOMAIN_NAME_LEN];	//���շ�����
	CHAR			fromMailAddr[DOMAIN_NAME_LEN];	//�ʼ����͵�ַ
	CHAR			toMailAddr[DOMAIN_NAME_LEN];	//�ʼ����յ�ַ
	CHAR			ccMailAddr[DOMAIN_NAME_LEN];	//�ʼ����͵�ַ
	CHAR			smtpUser[DOMAIN_NAME_LEN];		//SMTP �û���
	CHAR			smtpPassword[DOMAIN_NAME_LEN];  //SMTP �û�����
	CHAR			pop3User[DOMAIN_NAME_LEN];		//POP3 �û���
	CHAR			pop3Password[DOMAIN_NAME_LEN];	//POP3 �û�����
		
	UINT			motionMailOpen;					//��Ƶ�ƶ�����MAIL����
	UINT			motionMail[MAX_VIDEO_NUM];		//��Ƶ�ƶ�����ץ�ķ���MAIL����
	UINT			sensorMailOpen;					//̽ͷ��������MAIL����
	UINT			sensorMail[MAX_SENSOR_NUM];		//̽ͷ��������ץ�ķ���MAIL����
	UINT			viloseMailOpen;		

	UINT			timeMailOpen;					//��ʱ����(/��)
	UINT			timeVideoMail[MAX_VIDEO_NUM];	//��Ƶ��ʱץ�ķ���MAIL����
	
	CHAR			subjectMail[EMAIL_TITLE_LEN];	//�ʼ�ͷ
	CHAR			textMail[EMAIL_TITLE_LEN];		//�ʼ�����
		
	UINT			sendMailCount;					//״̬: ���͵�email����	
	UINT			sendNow;						//��������
	USHORT			smtpPort;						//SMTP �˿�
	USHORT			popPort;						//POP3 �˿�
	USHORT			protocolType;					//SSL
	CHAR			res[6];
}MAIL_CONFIG;

typedef enum _WF_AUTH_TYPE		//����֤��������
{
	WF_AUTH_NONE	= 0x00,
	WF_AUTH_WEP		= 0x01,
	WF_AUTH_WPA		= 0x02,
	WF_AUTH_WPA2	= 0x03,
	WF_AUTH_WPAWPA2	= 0x04,
}WF_AUTH_TYPE;


typedef enum _WF_ENC_TYPE		//������֤����
{
	WF_ENC_NONE		= 0x00,		//WEP  ����ϵͳ
	WF_ENC_WEP		= 0x01,		//WEP  �����ܳ�
	WF_ENC_TKIP		= 0x02,		//WEP  �Զ�ѡ��
	WF_ENC_AES		= 0x03,
}WF_ENC_TYPE;

typedef struct _WF_NET_CONFIG
{
	UINT			dwSize;							//��С
	USHORT			wfOpen;							//�Ƿ������
	USHORT			dhcpOpen;						//DHCP����
	//
	UINT			ipAddress;						//IP��ַ
	UINT			subMask;						//��������
	UINT			gateWay;						//����
	UINT			dnsIP1;							//DNS������1 IP
	UINT			dnsIP2;							//DNS������2 IP
	UCHAR			macAddress[6];
	//
	UCHAR			ssidLen;						//SSID���Ƴ���
	UCHAR			pswLen;							//���볤��

	CHAR			ssidName[34];					//SSID����
	CHAR			pswText[34];					//����
	UINT			channel;						//ͨ��
	UCHAR			wfAuthType;						//����֤��������
	UCHAR			wfEncType;						//������֤����
	CHAR			reserve[10];
}WF_NET_CONFIG;
//
typedef struct _ALARM_INOUT_NAME
{
	CHAR			alarmInName[MAX_SENSOR_NUM][CAM_TITLE_LEN+2];	//̽ͷ��
	CHAR			alarmOutName[MAX_OUTPUT_NUM][CAM_TITLE_LEN+2];	//���������
}ALARM_INOUT_NAME;
//��Ƶ����������
typedef struct _SEND_DEST
{	
	UINT			dwSet[MAX_VIDEO_NUM];			//���Ϳ���
	UINT			dwStreamSend[MAX_VIDEO_NUM];	//���Ϳ���
	UINT			dwStreamDestIP[MAX_VIDEO_NUM];	//Ŀ��IP,�����ֽ�˳��
	UINT			dwStreamDestPort[MAX_VIDEO_NUM];//Ŀ�Ķ˿�
	CHAR			res[16];
}SEND_DEST;
//�Զ�����ע��
typedef struct _AUTO_RESET_TIME
{
	UCHAR			open;				//bit 1:hour,bit 2:day,bit 3:week	
	UCHAR			second;
	UCHAR			minute;
	UCHAR			hour;
	UCHAR			week;				//0 �����գ�1 ����һ��2 ���ڶ� 

	UCHAR			res[3];
}AUTO_RESET_TIME;

//29��¼�����
//��HH52ϵ����ʹ��
//��HH58��HH98ϵ���в���ʹ��

typedef struct _CH_RECORD_CONFIG		//sizeof() = 84
{
	USHORT 			KeepTime;			//ĳ��ͨ����¼���ļ���������
	USHORT     		reserve;
	TIME_SEGMENT	tSchTable1[8] ;		//ĳ��ͨ���Ķ�ʱ¼��ʱ���1 (40)
	TIME_SEGMENT	tSchTable2[8] ;		//ĳ��ͨ���Ķ�ʱ¼��ʱ���2 (40)
}CH_RECORD_CONFIG;
typedef struct _RECORD_CONFIG			//sizeof() = 360
{
	UCHAR		 PackageTime;	  		//�ļ����ʱ��
	UCHAR 		 OverWrite;        		//auto overwrite 
	UCHAR     	 reserve[22];
	CH_RECORD_CONFIG ChRecordCfg[MAX_VIDEO_NUM];//ͨ����¼�����(336)
}RECORD_CONFIG;

//30��������Ϣ
//��HH58��HH98ϵ��������ṹ����4���ֽ�
typedef struct _DISK_INFO
{
	UINT	DiskNum;					//���̸���
	UCHAR	DiskType[8];				//��������
	UINT	TotalSize[8];				//�����ܿռ��С
	UINT	FreeSize[8];				//����ʣ��ռ�
	UCHAR	Reserved[8];				//BYTE	Reserved[4];	2008.9.23
}DISK_INFO;

//31�����̲���
typedef struct _DISK_MANAGE
{
	UCHAR	Cmd;
	UCHAR	Data;
	UCHAR	Reserved[126];
}DISK_MANAGE;

//32�����̸�ʽ������
typedef struct _DISK_FORMAT_PROCESS
{
	UINT	DiskType;					//��������
	UINT	Status;						//��ʽ��״̬
	UINT	Process;					//����()
	UINT	Reserved[5];
}DISK_FORMAT_PROCESS;

//24����չ��Ϣ�ṹ
typedef struct _EXTINFO_CONFIG
{
	UINT			nSize;						//�ṹ��С

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

//34���û�����
typedef struct __USERDATA_CONFIG
{
	int		nDataLen;
	char	userData[252];
}USERDATA_CONFIG;



//=================================================================================
//��HH5800ϵ�м�֮��ϵ�ж������½ṹ
//=================================================================================

//========================================================================
//��չ֡ͷ
//========================================================================
#define	HH_EXT_HEAD_FLAG	0x06070809
#define	HH_EXT_TAIL_FLAG	0x0a0b0c0d

//��Ƶ����
typedef struct _EXT_FRAME_VIDEO
{
	unsigned short	nVideoEncodeType;	//��Ƶ�����㷨
	unsigned short	nVideoWidth;		//��Ƶͼ���
	unsigned short	nVideoHeight;		//��Ƶͼ���
	unsigned char   nPal;               //��ʽ
	unsigned char   bTwoFeild;			//�Ƿ�����������(������������룬PC����Ҫ��deinterlace)
	unsigned char   nFrameRate;			//֡��
	unsigned char   szReserve[7];		//20090305 CYG(2)

} EXT_FRAME_VIDEO;

//��Ƶ����
typedef struct _EXT_FRAME_AUDIO
{
	unsigned short	nAudioEncodeType;	//��Ƶ�����㷨
	unsigned short	nAudioChannels;		//ͨ����
	unsigned short	nAudioBits;			//λ��
	unsigned char   szReserve[2];
	unsigned long	nAudioSamples;		//������ 	
	unsigned long	nAudioBitrate;		//��Ƶ��������
} EXT_FRAME_AUDIO;

typedef union _EXT_FRAME_TYPE
{
	EXT_FRAME_VIDEO	szFrameVideo;
	EXT_FRAME_AUDIO	szFrameAudio;
} EXT_FRAME_TYPE;

typedef struct _EXT_FRAME_HEAD
{
    unsigned long	nStartFlag;			//��չ֡ͷ��ʼ��ʶ
    unsigned short	nVer;				//�汾
    unsigned short	nLength;			//��չ֡ͷ����
	EXT_FRAME_TYPE	szFrameInfo;		
	unsigned long   nTimestamp;			//�Ժ���Ϊ��λ��ʱ���
	unsigned long	nEndFlag;			//��չ֡ͷ��ʼ��ʶ
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
//������������
//=======================================
typedef struct _ALARM_LINKAGE 
{
	UINT 		Output;						//�����������				     bit.0---bit.3	
	UINT 		AutoClearTime;		        //�����Զ����ʱ��	

	UINT 		Record_PC;					//PC�˱�������¼��ͨ��			 bit.0---bit.3
	UINT 		Record_Dev;					//�豸�˱�������¼��ͨ��		 bit.0---bit.3
	UINT		RecordSvaeMode;				//bit0 ���ش洢  bit1 ftp�ϴ�  bit2 email
	UINT		RecordTime;					//����¼��ʱ��(��)

	UINT		ShootSaveMode;				//bit0 ���ش洢  bit1 ftp�ϴ�  bit2 email
	UINT		ShootChns;					//ץ��ͨ��(bit.0 ~ bit.3)
	UINT		ShootNum;					//����ץ������()
	float		ShootInterval;				//����ץ��ʱ����(��)  0: ����ץ��

	UINT		EMail;						//����email
	UINT		Reserved;					//����
} ALARM_LINKAGE;

//=======================================
//��Ƶ����(��)
//=======================================
typedef struct _HH_OSD_CTRL_ST
{
	UINT		Show;						//0: ��  1: ��
	USHORT		X;							//x��y����ʾ��λ�ã���λ�õķ�ΧΪ0-704��0-576����ͼ��ķֱ����޹أ�x����Ϊ4�ı�����
	USHORT		Y;
} HH_OSD_CTRL_ST ;

typedef struct _HH_VENC_CTRL_ST
{
	UINT       Open;						//�Ƿ������루��������
	UINT		EncType;					//�����㷨
	UINT		EncFormat;					//�����ʽ(D1, HD1, CIF)
	UINT		Width;						//���
	UINT		Height;						//�߶�
	
	UINT		KeyInterval;			    //I ֡���
	UINT		Bitrate ;					//����
	float		FrameRate ;					//֡��float
	UINT		BitflowType; 			    //��������(0:VBR, 1:CBR)
	UINT		Qulity;						//����0--5
	UINT       Reserved[8];
} HH_VENC_CTRL_ST ;

//=======================================
//ץ��ͼƬ����
//=======================================
typedef struct _PICTURE_CONFIG				//sizeof() = 148
{
	UINT		dwSize;						//���ṹ����

	UINT     	EncType;					//ץͼ��ʽ(.jpg, bmp) 
	UINT     	EncFormat;					//ͼƬ��������(24λ�� 32λ) 
	UINT     	Width;
	UINT     	Height;

	UCHAR     	reseved[44];
}PICTURE_CONFIG;

//��Ƶ���
typedef struct _VIDEO_SIZE
{
	USHORT		Width;						//��
	USHORT		Height;						//��
}VIDEO_SIZE;

//�豸֧�ֵı����ʽ�Ϳ��
typedef struct _SUPPORT_AV_FMT
{
	UINT		dwSize;						//���ṹ����
	
	UINT		MainVideoFmt[8];			//�����������ʽ
	UINT		MinVideoFmt[8];				//�����������ʽ
	UINT		PictureFmt[8];				//ͼƬ�����ʽ

	VIDEO_SIZE  MainVideoSize[8];			//������ ����	
	VIDEO_SIZE  MinVideoSize[8];			//������ ����	
	VIDEO_SIZE  PictureSize[8];				//ͼƬ ����	

	UINT		AudioFmt[8];				//��Ƶ�����ʽ
	UINT		AudioSampleRate[8];			//��Ƶ������
	UINT		AudioBitrate[8];			//��Ƶ����
	UINT		AuidoAEC;					//�Ƿ�֧�ֻ�������

	UCHAR     	reserve[32];	
}SUPPORT_AV_FMT;
#define YTENG_VERSION	1

//��Ƶ����
typedef struct _VIDEO_CONFIG_NEW
{
	UInt32			dwSize;					//���ṹ����

	HH_VENC_CTRL_ST stMainVEncCtrl;			//����������
	HH_VENC_CTRL_ST stMinVEncCtrl;			//����������
	PICTURE_CONFIG	stPictureCfg;			//ץ��ͼƬ����

	HH_OSD_CTRL_ST	stDateOSD; 				// 0:����������,   1:��������
	HH_OSD_CTRL_ST	stTimeOSD; 				// 0:������ʱ��,   1:����ʱ��
	HH_OSD_CTRL_ST	stWeekOSD; 				// 0:����������,   1:�������� 
	HH_OSD_CTRL_ST	stTitleOSD;				// 0:�����ӱ���,   1:���ӱ��� 
	HH_OSD_CTRL_ST	stBitrateOSD;			// 0:����������,   1:�������� 	

	char    	Title[CAM_TITLE_LEN_NEW];	//�����ַ�(64���ַ�  31������)

    UInt8 		Brightness;				    //����
	UInt8 		Hue;						//ɫ��
	UInt8 		Saturation;				    //���Ͷ�
	UInt8 		Contrast;					//�Աȶ�

	UInt16 		Protocol;					//Э����(0 ~ MAX_PAN_PROTOCOL_NUM - 1)
	UInt16 		YTAddr;						//��������ַ
	//george.sun 20090113
	UInt8		mtClear;
	UInt8		mtRed;
	UInt8		mtBlue;
	UInt8		mtGamma;

	UInt8       nOsdPrefer;   //OSDʱ����ʾ 0 ��Ϊ year-month-day
							  //            1 Ϊ   month-day-year 
							  //            2 Ϊ   day-month-year 		
	UInt8       nOsdColor;	  //osd ������ɫ
	UInt8       nScene;       //����ccd �����(0-9)
	UInt8       nOSDClientNum;// �Ƿ���ʾ�û�������
	UInt8       Reserved[24];
} PACKED VIDEO_CONFIG_NEW;


typedef struct _AREA_RECT
{
	USHORT		X;							//X����	
	USHORT		Y;							//Y����
	USHORT		W;							//���
	USHORT		H;							//�߶�
} AREA_RECT;

//=======================================
//�ƶ��������(��)
//=======================================
typedef struct _VIDEOMOTION_CONFIG_NEW
{
	UINT			dwSize;						//���ṹ����

	UINT 			DetectLevel;			    //�ƶ����������
	UINT 			DetectOpen;				    //�ƶ���⿪��

	AREA_RECT		DetectArea[9];				//�ƶ��������			

	TIME_SEGMENT_NEW  tSchTable1[8] ;		    //�ƶ����ʱ���1				 0: ÿ��
	TIME_SEGMENT_NEW  tSchTable2[8] ;		    //�ƶ����ʱ���1				 0: ÿ��

	ALARM_LINKAGE	stAlarmLink;				//��������

	UCHAR			reseved[128];
}VIDEOMOTION_CONFIG_NEW ;

//=======================================
//ͼ����������(��) ���ȣ��Ͻṹ��������������
//=======================================
typedef struct _VIDEOMASK_CONFIG_NEW
{
	UCHAR 			MaskOpen;					//��Ƶ���ο���		0:��         1����
	UCHAR			AA[3];
	AREA_RECT		MaskArea[9];				//��Ƶ��������		
}VIDEOMASK_CONFIG_NEW;

//=======================================
//��Ƶ��ʧ����(��)
//=======================================
typedef struct _VIDEOLOSE_CONFIG_NEW
{
	UINT			dwSize;						//���ṹ����

	UINT			DetectOpen;					//��Ƶ��ʧ���

	ALARM_LINKAGE	stAlarmLink;				//��������

	UCHAR			reseved[32];
} VIDEOLOSE_CONFIG_NEW;

//=======================================
//̽ͷ�����������(��)
//=======================================
typedef struct _SENSOR_CONFIG_NEW 
{
	UINT			dwSize;						//���ṹ����

	UINT			SensorType;					//0:����̽ͷ	1:����̽ͷ
	UINT 			DetectOpen;				    //��⿪��

	TIME_SEGMENT_NEW  tSchTable1[8] ;		    //̽ͷ���ʱ��1				     0: ÿ��
	TIME_SEGMENT_NEW  tSchTable2[8] ;		    //̽ͷ���ʱ��1				     0: ÿ��

	ALARM_LINKAGE	stAlarmLink;				//��������

	UCHAR			reseved[32];
}SENSOR_CONFIG_NEW;

//=======================================
//����̽ͷ����
//=======================================
typedef struct _RF_ALARM_CONFIG
{
	UINT			dwSize;						//���ṹ����

	UINT			SensorType;					//0:����̽ͷ	1:����̽ͷ
	UINT 			DetectOpen;				    //��⿪��

	TIME_SEGMENT_NEW  tSchTable1[8] ;		    //̽ͷ���ʱ��1				     0: ÿ��
	TIME_SEGMENT_NEW  tSchTable2[8] ;		    //̽ͷ���ʱ��1				     0: ÿ��

	ALARM_LINKAGE	stAlarmLink;				//��������

	UCHAR			reseved[32];
}RF_ALARM_CONFIG;


//=======================================
//������߱�������
//=======================================
typedef struct _NET_ALARM_CONFIG 
{
	UINT			dwSize;						//���ṹ����

	UINT 			DetectOpen;				    //��⿪��
	
	ALARM_LINKAGE	stAlarmLink;				//��������

	USHORT			reseved[32];
} NET_ALARM_CONFIG;

//=======================================
// FTP ����������
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
//��ý�����
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
//24.0 ��չ��Ϣ�ṹ(�޸Ķ��壬 ��С��ԭ�ṹ��ͬ�� ��������Ҳ��ͬ)
typedef struct _EXTINFO_CONFIG_NEW
{
	UINT				nSize;						//�ṹ��С(1328)

	NTP_CONFIG			ntpConfig;					//ntp
	
	UPNP_CONFIG			upnpConfig;					//upnp
		
	MAIL_CONFIG			mailConfig;					//MAIL
	
	ALARM_INOUT_NAME	alarmInOutName;				//ALARM IN/OUT NAME
	
	WF_NET_CONFIG		wfConfig;					//WF NETWORK
	
	SEND_DEST			sendDest;					//SEND DEST
	
	AUTO_RESET_TIME		autoResetTime;				//AUTO RESET 

	FTP_CONFIG			ftpCfg;						//FTP ����������

	MEDIA_SERVER		mediaServer;				//��ý�����

	GPS_INFO			gpsInfo;					//GPS ��Ϣ,

	UCHAR               reportWanIp;            	//ljm 20090721 �����ϱ�����IP��ַ
	UCHAR               reportIpInterval;          	//ljm 20090724
	char				reserve[14];				//cz 20090602 //ljm 20090724

	//char				reserve[16];  
	//char				reserve[40];  
}EXTINFO_CONFIG_NEW;

//=======================================
//����̽ͷ
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
//��ʱ¼��
//=======================================
typedef struct _CH_TIMER_RECORD_CONFIG		//sizeof() = 140
{
	USHORT					KeepTime;								//��������(��)
	USHORT					RecordSvaeMode;							//bit0 ���ش洢  bit1 ftp�ϴ�  bit2 email
	UINT					reserve[2];

	TIME_SEGMENT_NEW		tSchTable1[8] ;							//ĳ��ͨ���Ķ�ʱ¼��ʱ���1 (64)
	TIME_SEGMENT_NEW		tSchTable2[8] ;							//ĳ��ͨ���Ķ�ʱ¼��ʱ���2 (64)
}CH_TIMER_RECORD_CONFIG;	

typedef struct _TIMER_RECORD_CONFIG			//sizeof() = 592
{
	USHORT					PackageTime;	  						//���ʱ��(����)
	USHORT 					OverWrite;        						//�Զ�����
	USHORT     				MainVEnc;								//¼����� 0: ������  1: ������
	USHORT     				CheckDisk;								//ϵͳ����ʱ���д���ɨ��
	USHORT     				reserve[28];

	CH_TIMER_RECORD_CONFIG	ChRecordCfg[MAX_VIDEO_NUM];				//ͨ����¼�����(140 * 4 = 560)
}TIMER_RECORD_CONFIG;


//=======================================
//��ʱץ��
//=======================================
typedef struct _CH_TIMER_SHOOT_CONFIG		//sizeof() = 140
{
	USHORT 					KeepTime;								//��������(��)
	USHORT					ShootSaveMode;							//bit0 ���ش洢  bit1 ftp�ϴ�  bit2 email

	UINT					ShootNum;								//����ץ������()
	float					ShootInterval;							//����ץ��ʱ����(��)  0: ����ץ��

	TIME_SEGMENT_NEW		tSchTable1[8] ;							//ĳ��ͨ���Ķ�ʱץ��ʱ���1 (40)
	TIME_SEGMENT_NEW		tSchTable2[8] ;							//ĳ��ͨ���Ķ�ʱץ��ʱ���2 (40)
}CH_TIMER_SHOOT_CONFIG;

typedef struct _TIMER_SHOOT_CONFIG			//sizeof() = 592
{
	UCHAR 					OverWrite;								//�Զ�����
	UCHAR     				reserve[31];

	CH_TIMER_SHOOT_CONFIG	ChShootCfg[MAX_VIDEO_NUM];				//ͨ����¼�����(92 * 4 = 368)
}TIMER_SHOOT_CONFIG;

//=======================================
//������չ����(��ƽ̨������������)
//=======================================
typedef struct __EXT_DATA_CONFIG
{
	UINT		nSize;					//�ṹ��С
	UINT		nType;	
       UINT		nDataLen;
    char		szData[512];
}EXT_DATA_CONFIG;

//=======================================
//��־��ѯ
//=======================================
typedef struct _FIND_LOG_S
{
	UINT		nSize;					//�ṹ��С
	UINT		nSelectMode;			//��ѯ��ʽ:0��ȫ����1�������ͣ�2����ʱ�䣬3����ʱ�������
	UINT		nType;					//��������
    DVS_TIME	stStartTime;
	DVS_TIME	stEndTime;
}FIND_LOG_S;

typedef struct _LOG_ITEM_S
{
	UINT		nSize;					//�ṹ��С
	UINT		nAlarmType;				//��������
	UINT       nChn;					//ͨ���š����߱�����IP��ַ
	DVS_TIME	tAlarmTime;	
	char		szNote[12];
}LOG_ITEM_S;

//=======================================
//�豸���в�����sizeof = 10248��
//=======================================
typedef struct _DVS_Parameter_New
{
	UINT					dwSize;						//���ṹ����

    char                    sysName[DVS_NAME_LEN + 4];

	UCHAR					sysInputNum;		        //·��
	UCHAR					sysType;			        //�����ͺ�	0:CIF  1:HD1  2:D1  
	UCHAR					sysVideoFormat;		        //�����ʽ	0:D1,1:HD1,2:CIF,3:VGA 4:HVGA 5:CVGA 6:QCIF 7:QVGA
    UCHAR					sysLanguage;		        //����

    UINT					sysStandard;		        //��ʽ		0:PAL  1:NTSC

    UINT      				sysID;  	                //ÿ̨�����и�ID
	UINT      				sysVer;  	                //����汾  

	VIDEO_CONFIG_NEW	    sysVideo[MAX_VIDEO_NUM];	
	VIDEOMOTION_CONFIG_NEW	sysVideoMotion[MAX_VIDEO_NUM];
	VIDEOMASK_CONFIG_NEW    sysVideoMask[MAX_VIDEO_NUM];	
	VIDEOLOSE_CONFIG_NEW    sysVideoLose[MAX_VIDEO_NUM];	
	AUDIO_CONFIG		    sysAudio[MAX_AUDIO_NUM];
	NET_CONFIG			    sysNet;
	COM_CONFIG			    sysCom[MAX_COM_NUM];
	SENSOR_CONFIG_NEW	    sysSensor[MAX_SENSOR_NUM];
	USER_CONFIG			    sysUser[MAX_USER_NUM];

    EXTINFO_CONFIG_NEW		sysExtConfig;				//��չ����

	DISK_INFO				DiskInfo;					//�洢�豸��Ϣ

	TIMER_RECORD_CONFIG		TimerRecordCfg;
	TIMER_SHOOT_CONFIG		TimerShootCfg;				//��ʱץ�Ĳ���

	RF_ALARM_CONFIG			rfAlarmCfg[MAX_RF_SENSOR_NUM];	//����̽ͷ����
	NET_ALARM_CONFIG		netAlarmCfg;					//������߱���

	USERDATA_CONFIG			userData;					//�û�����

	UINT					YunTaiProtocolNum;
	YUNTAI_INFO 			YunTaiInfo[MAX_PTZ_PROTOCOL_NUM];	

	UCHAR					reserved[256];				//����

} DVS_Parameter_New;

//����1
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

//����2
typedef struct _PING_CONFIG
{
	BOOL	bPingOpen;
	BOOL	bDisconnectReboot;
	BOOL	bDisconnectAlarm;
	UINT	dwPingNum;
	UINT    dwPingPeriod;
	char	szPingServer[64];
}PING_CONFIG;

//���ùؼ�֡
typedef struct _HHCMD_SET_KEYFRAME_REQ_INFO    //add by come 20090924
{
	unsigned int 				    nOpenChannel:8; 			//ͨ���ţ�0 �� 3��
	unsigned int					nSubChannel:8;				//0: �������� 	 1: �򿪴�����
	unsigned int                    nRes:16;
}PACKED HHCMD_SET_KEYFRAME_REQ_INFO;


//------------------------------(II)�������������ýṹ----------------------------//
//1��ϵͳʱ��
typedef  struct  _DD_NVD_DATE
{
	UCHAR		year;									//��
	UCHAR		month;									//��
	UCHAR		day;									//��
	UCHAR		week;									//��
	UCHAR		hour;									//Сʱ
	UCHAR		minute;									//��
	UCHAR		second;									//��
}DD_NVD_DATE, *PDD_NVD_DATE;

//2��ϵͳ����
typedef struct _DD_SYSTEM_PARAM 
{
   	CHAR               	Name[DVS_NAME_LEN + 1];			//����
	UCHAR				Type;							//�����ͺ�	0:CIF  1:HD1  2:D1  
    UCHAR				Language;						//����
    UCHAR				Standard;						//��ʽ		0:PAL  1:NTSC
	UINT      			ID;  	        				//ÿ̨�����и�ID��  	
	UINT      			RS485Addr;       				//RS485��ַ  		
	UINT      			RS485Func;       				//RS485����  			
	UINT      			RS485Baud;       				//RS485������  			
	UINT      			Version;         				//����汾  
	UCHAR      			RemoteID;         				//ң��ID��  	
	UCHAR				Audio;							//��������	
	UCHAR				TimeOn;							//ʱ����ʾ����				
	UCHAR				DispMode;						//��ʾģʽ(1�����桢4�Ļ���)
	UCHAR				ImageQulity;					//����ͼ������
	UCHAR				Reserve[31];					//����
}PACKED DD_SYSTEM_PARAM;

//3���������
typedef struct _DD_NET_CONFIG
{
	UINT             	IPAddr ;						//IP��ַ
	UINT             	SubNetMask ;					//����
	UINT             	GateWay ;						//����

   	USHORT             	ComPortNo;						//���ý��տͻ�������˿ں�        UDP	
   	USHORT             	WebPortNo;						//Webserver�˿�     			  TCP
	UINT             	MultiCastIPAddr ;				//�ಥIP��ַ
   	USHORT             	MultiCastPortNo;				//UDP������ʼ�˿�<�ಥ����>
	
	UCHAR			   	RT8139MAC[6];      				//�˹�����������MAC��ַ		5---0��Ч
   	UCHAR             	DHCP;							//DHCP ����					0	��		1:��
	UCHAR				AD[1];
	
   	USHORT             	PppoeOpen;						//PPPOE ����         	
	UINT             	PppoeIPAddr ;					//PPPOEIP��ַ �������ش�IP��
	CHAR				PppoeName[PPPPOE_NAME_LEN+1];	//�����û���
	CHAR				PppoePass[PPPPOE_PASSWD_LEN+1];	//��������		
	CHAR				ADD[2];	
	UINT				DdnsOpen;						//DDNS����
	CHAR				DdnsName[DDNS_NAME_LEN+1];		//ע����������
	CHAR				DdnsPass[DDNS_PASS_LEN+1];		//ע����������	

	
	CHAR				DdnsIP[DDNS_SERVER_NAME_LEN+1];	//DDNS������
	CHAR				ASD[1];
	
	USHORT				DdnsPortNo;						//DDNS�������˿�
	USHORT				DdnsMapWebPort;					//����WEBӳ��˿�
	USHORT				DdnsMapDataPort;				//��������ӳ��˿�
	CHAR				ASDD[2];

	UINT				DNSHostIP;						//DNS��IP
	INT					ConnectCenter;					//�Ƿ�������������
	CHAR				ConnectCenterIP[DDNS_SERVER_NAME_LEN+1];//����IP
	CHAR				AAD[1];
	
	USHORT				ConnectCenterPort;				//���Ķ˿�

	USHORT				appFunction;					//fix me
	UCHAR				tcpSendInterval;
	UCHAR				udpSendInterval;
	USHORT				PacketMTU;

	UCHAR				CaptureMode;					//ץ��ģʽ
	UCHAR				CapturePort[MAX_SENSOR_NUM];	//ץ��ͨ��(0-3bit: �ֱ��ʾ1 ~ 4��ͨ��  1:��  0: ��)

	UINT				DdnsIP2;						//DDNS 2��IP,�������ֽڴ���
	USHORT				DdnsPortNo2;					//DDNS 2�Ķ˿�

	CHAR				sysByname[DVS_NAME_LEN+1];		//����
	UCHAR				NetReserve[1];					//����
} PACKED DD_NET_CONFIG ;

//4����������
typedef struct __DD_COM_PARAM
{
	UINT 				Baudrate;						//���ڲ�����				300---115200
	UCHAR				Databit;						//��������λ����			5=5λ 6=6λ 7=7λ 8=8λ	����=8λ
	UCHAR				Stopbit;						//ֹͣλλ��				1=1λ 2=2λ ����=1λ
	UCHAR				CheckType;						//У��						0=��  1=��  2=ż  3=��1  4=��0 
	UCHAR				Flowctrl; 						//������/Ӳ����/������		����
}PACKED DD_COM_CONFIG;

//5��ͼ�����
typedef struct _DD_IMAGE_PARAM
{
	UCHAR 	Bright;										// ����
	UCHAR 	Shades;										// ɫ��
	UCHAR 	Contrast;									// �Աȶ�
	UCHAR 	Saturate;									// ���Ͷ�
	UCHAR 	MenuBright;									// �˵�����
}PACKED DD_IMAGE_CONFIG;

//6����������
typedef struct __DD_ALARMOUT_PARAM
{
	UCHAR 				Open;							//��������<0: ��  1: ��>
	UCHAR				SensorAlarm[4];					//̽ͷ��������	.0 ~ 3 1--4��̽ͷ	0,1λ: �ֱ��ʾ�̵���1 2��״̬  <0: ��  1: ��>
	UCHAR				MotionAlarm[4];					//��Ƶ�ƶ�����	.0 ~ 3 1--4��̽ͷ	0,1λ: �ֱ��ʾ�̵���1 2��״̬  <0: ��  1: ��>
	UCHAR				ViLoseAlarm[4];					//��Ƶ��ʧ����	.0 ~ 3 1--4��̽ͷ	0,1λ: �ֱ��ʾ�̵���1 2��״̬  <0: ��  1: ��>
	UCHAR				Reserve[8];						//����	
}PACKED DD_ALARMOUT_CONFIG;


//7���û�����
typedef struct _DD_USER_CONFIG
{
	UINT 		Level;									//Ȩ��
	CHAR 		Name[17];								//�û���
	CHAR 		Password[17];							//�û�����
	CHAR 		AD[2];
}PACKED DD_USER_CONFIG;


//8��������Ϣ��Ŀ
typedef struct __DD_ALARM_ITEM
{
	UINT 				IPAddr;							//IP
	CHAR				URL[DD_URL_ADDR_LEN + 1];		//URL��ַ
	CHAR				AVD[3];
	UINT				ComPortNo;						//ͨѶ�˿�
	DD_NVD_DATE			AlarmTime;						//����ʱ��
	UCHAR				SensorAlarm;					//̽ͷ��������	.0 ~ 3 1--4��̽ͷ	<0: �ޱ���  1: �б���>
	UCHAR				MotionAlarm;					//��Ƶ�ƶ�����	.0 ~ 3 1--4����Ƶ	<0: �ޱ���  1: �б���>
	UCHAR				ViLoseAlarm;					//��Ƶ��ʧ����	.0 ~ 3 1--4����Ƶ	<0: �ޱ���  1: �б���>
	UCHAR				Reserve[8];						//����
	CHAR				AD[2];
}PACKED DD_ALARM_ITEM;


//9��������Ϣ��¼
typedef struct __DD_ALARM_INFO
{
	USHORT				Count;							//������¼����
	CHAR				AD[2];
	DD_ALARM_ITEM		Alarms[DD_MAX_ALARMINFO_NUM];	//������¼����
}PACKED DD_ALARM_INFO;


//10����ַ��
typedef struct __DD_ADDRBOOK_PARAM
{
	CHAR				Name[DDNS_NAME_LEN + 1];		//����
	CHAR				URL[DD_URL_ADDR_LEN + 1];		//URL��ַ
	USHORT             	ComPortNo;						//ͨѶ�˿�
	UCHAR				ChannelNo;						//ͨ����
	UCHAR				Protocol;						//0: TCP  1:�ಥ   2:UDP
	UCHAR				DNSOpen;						//0: ��   1:��
	UCHAR				AD;
	USHORT				StayTime;						//ͣ��ʱ��	5--3600��
	UCHAR				AutoLink;						//�Զ�����	0:��  1:��
	UCHAR				AudioOpen;						//������	0:��  1:��	
	UCHAR				TalkOpen;						//�Խ���	0:��  1:��
	CHAR				UserName[USER_NAME_LEN + 1];	//�û���
	CHAR				UserPass[USER_PASSWD_LEN + 1];	//�û�����	
	UCHAR				Reserve[8];						//����	
	UCHAR				AD2;
}PACKED DD_ADDRBOOK_CONFIG;


//11��͸��ͨѶ
typedef struct __DD_COMM_CTRL
{
	UCHAR				COMMNo;							//���ں�	0 ~ 1
	UCHAR				ADG[3];
	COM_CONFIG			COMConfig;						//��������
	USHORT				DataLength;						//���ݳ���
	UCHAR				Data[256];						//����
	UCHAR				AD[2];
}PACKED DD_COMM_CTRL;


//12��������������ṹ
typedef struct __DD_DEVICE_CTRL
{
	UCHAR				CMD;							//����
	UCHAR 				Data1;							//����1
	UCHAR 				Data2;							//����2
	UCHAR				AD[1];
	UINT				nReserved[8];					//����
}PACKED DD_DEVICE_CTRL;


//13����̨��Ϣ
typedef struct _DD_PROTOCOL_INFO
{
	CHAR 		Name[YUNTAI_NAME_LEN + 1];				//��̨����
	UCHAR		Exist;									//�Ƿ����
	UCHAR		nReserved[8];							//����
}PACKED DD_PROTOCOL_INFO;

//14����̨����

typedef struct _DD_YUNTAI_SET
{
	CHAR 		Name[YUNTAI_NAME_LEN + 1];				//��̨����
	UCHAR 		YTAddr;									//��������ַ
	UCHAR		AD[2];
	COM_CONFIG	ComSet;									//ͨѶЭ��<������...>
	
	UCHAR		nReserved[8];							//����
}PACKED DD_YUNTAI_SET;


//15��ϵͳ���в���(�������ò��������紫����)

typedef struct _DD_NVD_CONFIG 
{
	DD_SYSTEM_PARAM 		sysParam;					//ϵͳ����
	DD_NET_CONFIG			sysNet;						//��������
	DD_COM_CONFIG			sysCom[MAX_COM_NUM];		//��������
	DD_IMAGE_CONFIG			sysImage;					//ͼ�����
	UCHAR					ADD[3];
	DD_USER_CONFIG			sysUser[MAX_USER_NUM];		//�û�
	DD_ALARMOUT_CONFIG		sysAlarmOut;				//�������
		
	DD_PROTOCOL_INFO 		YunTaiInfo[MAX_VIDEO_NUM];	//��̨��Ϣ
	UCHAR					AD[2];
	DD_YUNTAI_SET 			YunTaiSet[MAX_VIDEO_NUM];	//��̨Э������		
} PACKED DD_NVD_CONFIG ;


//16����չ��Ϣ�ṹ
typedef struct _DD_EXTINFO_CONFIG
{
	UINT			nSize;						//�ṹ��С

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


