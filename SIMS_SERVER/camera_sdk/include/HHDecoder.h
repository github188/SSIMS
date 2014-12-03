#ifndef _HHDecoder_H_
#define _HHDecoder_H_

#ifdef __cplusplus
extern "C" {
#endif

//========================================================
//�Ƶ�Ƶ�
//========================================================
#ifndef HHAV_INFO_DEFINE
#define HHAV_INFO_DEFINE

#define	AVFORMAT_IN_MPEG4					0xF000
#define	AVFORMAT_IN_H264					0xF001

/* typedef struct _HHAV_INFO
{
    //�Ƶ�
	unsigned int			nVideoEncodeType;		//�Ƶ��ʽ
    unsigned int			nVideoHeight;			//�Ƶͼ��
    unsigned int			nVideoWidth;			//�Ƶͼ��
    //�Ƶ�
	unsigned int			nAudioEncodeType;		//�Ƶ��ʽ
    unsigned int			nAudioChannels;			//ͨ�
    unsigned int			nAudioBits;				//λ�
    unsigned int			nAudioSamples;			//��
}HHAV_INFO, *PHHAV_INFO;  */

#endif //HHAV_INFO_DEFINE

#define HHDECODER_ERR_INVALID_PARAMETER  -1
#define HHDECODER_SUCCESS					0

#define HHDECODER_YUV_420 0x00
#define HHDECODER_YUV_422 0x01
#define HHDECODER_RGB_024 0x02
#define HHDECODER_ARGB_32 0x06


typedef struct _MP6_FILE_HEAD
{
	unsigned long	magicFlag;
	unsigned char	majorVideoType;
	unsigned char	minorVideoType;
	unsigned char	majorAudioType;
	unsigned char	minorAudioType;
	unsigned char	reserved[8];
}MP6_FILE_HEAD;

typedef struct ParseContext{
	unsigned int  FrameStartFound;
	unsigned int  iFrameLength;
	unsigned int  PrevFirstMBAddr;
} ParseContext;
#define MOST_BIT_MASK  0x80000000
#define MAX_AU_SIZE    0x80000

void *HHCreateH264Decoder();
int   HHDecoder_ReleaseDecoder(void* pDecoder);
int   HHDecoder_DecodeOneFrame(void* pDecoder, char* Buf_Src,  int Src_Len, char* Buf_Dst, ENCODE_VIDEO_TYPE encodeVideoType);
//int   Hi264DecLoadAU(unsigned char* pStream, unsigned int iStreamLen, ParseContext *pc);

int HHDecoder_InitDecoder_G726(void);
int   HHDecoder_DecodeData_G726(char *BuffIn, int InNum,unsigned short *BuffOut);
int HHDecoder_InitEncoder_G726(void);
int   HHDecoder_EncodeData_G726( unsigned short *BuffIn, int InNum, char *BuffOut);

#ifdef __cplusplus
}
#endif
#endif //_HHDecoder_H_

