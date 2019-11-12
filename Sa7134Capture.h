#ifndef VC404_CAPTURE_SAA7134
#define VC404_CAPTURE_SAA7134

#ifdef SAA7134CAPTURE_EXPORTS
#define SAA7134CAPTURE_API __declspec(dllexport)
#else
#define SAA7134CAPTURE_API __declspec(dllimport)
#endif

static const ULONG BrightnessDefault = 0x80;
static const ULONG ContrastDefault   = 0x44;
static const ULONG SaturationDefault = 0x40;
static const ULONG HueDefault        = 0x00;
static const ULONG SharpnessDefault  = 0x00;

#define MIN_VAMP_BRIGHTNESS_UNITS    0
#define MAX_VAMP_BRIGHTNESS_UNITS  255

#define MIN_VAMP_CONTRAST_UNITS   -128 
#define MAX_VAMP_CONTRAST_UNITS    127 

#define MIN_VAMP_HUE_UNITS        -128
#define MAX_VAMP_HUE_UNITS         127

#define MIN_VAMP_SATURATION_UNITS -128 
#define MAX_VAMP_SATURATION_UNITS  127

#define MIN_VAMP_SHARPNESS_UNITS    -8
#define MAX_VAMP_SHARPNESS_UNITS     7

///////////////////////////////////////////////////////////
//注意：VC枚举类型为32位，4字节；这里的枚举类型为4字节。
//      C++ builder枚举类型为8位，1字节，要重定义，例如：
//typedef int COLORCONTROL;
//COLORCONTROL BRIGHTNESS  = 0;
//COLORCONTROL CONTRAST    = 1;
//COLORCONTROL SATURATION  = 2;
//COLORCONTROL HUE		   = 3;
//COLORCONTROL SHARPNESS   = 4;

//描述：在VC中enum、ULONG、LONG、BOOL、DWORD 都为32位，4字节，
//这里使用的是VC定义标准。
/////////////////////////////////////////////////////////////

typedef enum {		            //@enum Decoder control types
    BRIGHTNESS = 0,                 //@emem control for brightness
    CONTRAST   = 1,                   //@emem control for contrast
    SATURATION = 2,                 //@emem control for saturation
    HUE		   = 3,                        //@emem control for hue
    SHARPNESS  = 4                  //@emem control for sharpness
}COLORCONTROL;

typedef enum {		            //@enum Decoder control types
       XVID_CBR_MODE = 0,
	   XVID_VBR_MODE = 1//,
}COMPRESSMODE;

typedef enum{               
    COLOR_DECODER = 0, //解码器(包括视频预览和视频捕获)
    COLOR_PREVIEW = 1, //视频预览          
    COLOR_CAPTURE = 2  //视频捕获   
}COLORDEVICETYPE;


typedef enum{
    VID_CAPTURE_EVENT   = 0,
	AUD_CAPTURE_EVENT1  = 1,
	AUD_CAPTURE_EVENT2  = 2,
	IO_ALERT_EVENT		= 3,
	MOTION_DETECT		= 4,
	VID_PREVIEW_EVENT	= 5
}EVENTTYPE;


typedef enum
{
	RGB32	= 0x0,
	RGB24	= 0x1,
	RGB16	= 0x2,
	RGB15	= 0x3,
	YUY2	= 0x4,
	BTYUV	= 0x5,
	Y8		= 0x6,
	RGB8	= 0x7,
	PL422	= 0x8,
	PL411	= 0x9,
	YUV12	= 0xA,
	YUV9	= 0xB,
	RAW		= 0xE
}COLORFORMAT;

typedef enum
{
	CAP_NULL_STREAM		= 0,	//捕获无效
	CAP_ORIGIN_STREAM	= 1,	/*原始流回调*/
	CAP_MPEG4_STREAM	= 2,	/*Mpeg4流*/
	CAP_MPEG4_XVID_STREAM	= 3,
	CAP_ORIGIN_MPEG4_STREAM	= 4,	/*Mpeg4流*/
	CAP_ORIGIN_XVID_STREAM	= 5	/*Mpeg4流*/

}CAPMODEL;


typedef enum
{
	MPEG4_AVIFILE_ONLY = 0,			//存为MPEG文件
	MPEG4_CALLBACK_ONLY = 1,		//MPEG数据回调
	MPEG4_AVIFILE_CALLBACK = 2		//存为MPEG文件并回调
}MP4MODEL;

typedef enum  
{          //@enum Field frequency
    FIELD_FREQ_50HZ = 0,        //@emem source is 50 Hz (PAL)
    FIELD_FREQ_60HZ = 1,        //@emem source is 60 Hz (NTSC)
    FIELD_FREQ_0HZ  = 2         //@emem source is 0 Hz   (NO SIGNL)
}eFieldFrequency;

typedef enum {			        //电平等级
    HIGH_VOLTAGE = 0,			//高电平
    LOW_VOLTAGE = 1				//低电平
}eVOLTAGELEVEL;

typedef enum {		          
    NOT_DISPLAY = 0,          
    PCI_VIEDOMEMORY   = 1,    
    PCI_MEMORY_VIDEOMEMORY = 2
}DISPLAYTRANSTYPE;

typedef enum
{
	VideoStandard_None = 0x00000000,
	VideoStandard_NTSC_M = 0x00000001, 
	VideoStandard_NTSC_M_J = 0x00000002, 
	VideoStandard_NTSC_433 = 0x00000004,
	VideoStandard_PAL_B = 0x00000010,
	VideoStandard_PAL_D = 0x00000020,
	VideoStandard_PAL_H = 0x00000080,
	VideoStandard_PAL_I = 0x00000100,
	VideoStandard_PAL_M = 0x00000200,
	VideoStandard_PAL_N = 0x00000400,
	VideoStandard_PAL_60 = 0x00000800,
	VideoStandard_SECAM_B = 0x00001000,
	VideoStandard_SECAM_D = 0x00002000,
	VideoStandard_SECAM_G = 0x00004000,
	VideoStandard_SECAM_H = 0x00008000,
	VideoStandard_SECAM_K = 0x00010000,
	VideoStandard_SECAM_K1 = 0x00020000,
	VideoStandard_SECAM_L = 0x00040000,
	VideoStandard_SECAM_L1 = 0x00080000,
}
VideoStandard;

typedef struct
{

	LONG		cfHeight;		//字符高度
	LONG		cfWidth;		//字符宽度
	LONG		cfWeight;		//字符粗细
	LONG		cfSpacing;		//字符间距
	BOOL		cfItalic;		//斜体
	BOOL		cfUnderline;	//下划线
	BOOL		cfStrikeOut;	//删除线
	BOOL		bTransparent;   //透明
	COLORREF	cfBkColor;		//背景色 
	COLORREF	cfTextColor;	//前景色
	TCHAR		cfFaceName[32];	//字体名

}OSDPARAM;

//error define area

#define		ERR_SUCCESS					0			//no error,success
#define		ERR_NODEVICEFOUND			1			//no device found in system
#define		ERR_UNSUPPORTFUNC			2			//unsupport func tempro?
#define		ERR_ALLOCRESOURCE			3			//alloc resource error
#define		ERR_INITDIRECTDRAW			4			//Init Directdraw error
#define		ERR_INITDIRECTSOUND			5			//Init Directdraw error
#define		ERR_NOT_10MOONSDEV			6			//it is not device of 10Moons 

/////////////////////////////////////////////////////////////////////////////////////////////////
//VC4000/VC8000/VC404P公有函数
/////////////////////////////////////////////////////////////////////////////////////////////////

//动态检测回调，
//如果VCAEnableMotionDetect 参数nPersistTime = －1;则回调运动检测地图。取消（开始、停止）回调。bMove将无效。
//如果VCAEnableMotionDetect 参数nPersistTime != －1;则回调开始、停止运动检测;取消回调运动检测地图。pbuff、dwSize将无效。
typedef void (CALLBACK *PrcCbMotionDetect)( DWORD dwCard, BOOL bMove, BYTE *pbuff, DWORD dwSize, LPVOID lpContext );
//视频捕获原始数据回调
typedef void (CALLBACK *PrcVidCapCallBack)( DWORD dwCard, BYTE *pbuff, DWORD dwSize );
//视频MPEG压缩数据回调
typedef void (CALLBACK *PrcVidMpegCallBack)( DWORD dwCard, BYTE *pbuff, DWORD dwSize, BOOL isKeyFrm );
//音频捕获原始数据回调
//音频包原始大小16 Bit PCM格式,8080 BYTE,2声道，32000Hz
typedef void (CALLBACK *PrcAudCapCallBack)( DWORD dwCard, BYTE *pbuff,DWORD dwSize );
//音频MPEG压缩数据回调
typedef void (CALLBACK *PrcAudMpegCallBack)( DWORD dwCard, BYTE *pbuff,DWORD dwSize );
//IO报警回调
typedef void (CALLBACK *PrcIoAlertCallBack)( DWORD dwCard );
//视频Mpeg处理回调 ,pPorcess 返回为TRUE 表示当前帧压缩；返回为FALSE 表示丢掉当前帧
typedef void (CALLBACK *PrcVidMpegPorCallBack)( DWORD dwCard, BOOL* pPorcess );
//音频Mpeg处理回调,pPorcess 返回为TRUE 表示当音频包压缩；返回为FALSE 表示丢掉当前音频包。
typedef void (CALLBACK *PrcAudMpegPorCallBack)( DWORD dwCard, BOOL* pPorcess );
//注册视频捕获原始数据回调
BOOL  WINAPI VCARegVidCapCallBack( DWORD dwCard, PrcVidCapCallBack ppCall );
//注册视频MPEG压缩数据回调
BOOL  WINAPI VCARegVidMpegCallBack( DWORD dwCard, PrcVidMpegCallBack ppCall );
//设置错误序号
void  WINAPI VCASetLastError( DWORD dwError );
//得到错误序号
DWORD WINAPI VCAGetLastError();
//初始化SDK,hWndMain:overlay窗口句柄，overlay窗口就是包含多路显示小窗口的大窗口。overlay窗口必须有一个，多路显示小窗口必须包含再其内部。
//bInitVidDev:是否初始化视频设备用于预览，当视频不显示，只需视频录像或音频处理时可以设置为FALSE.
//bInitAudDev:是否初始化音频设备用于声音播放，当不音频不需要播放，只需音频录像或视频处理时、或没有安装声卡，可以设置为FALSE.
BOOL  WINAPI VCAInitSdk( HWND hWndMain, DISPLAYTRANSTYPE eDispTransType = PCI_VIEDOMEMORY, BOOL bInitAudDev = FALSE  );
//释放SDK资源
void  WINAPI VCAUnInitSdk();
//得到设备总数
LONG  WINAPI VCAGetDevNum();
//打开设备,hPreviewWnd为视频预览窗口的句柄，该窗口背景色用户必需设置为RGB(255,0,255)
BOOL  WINAPI VCAOpenDevice( DWORD dwCard,HWND hPreviewWnd );
//关闭设备
BOOL  WINAPI VCACloseDevice( DWORD dwCard );
//开始视频预览
BOOL  WINAPI VCAStartVideoPreview( DWORD dwCard );
//停止视频预览
BOOL  WINAPI VCAStopVideoPreview( DWORD dwCard );
//更新视频预览，比如改变了显示窗口时，调用。
BOOL  WINAPI VCAUpdateVideoPreview( DWORD dwCard, HWND hPreviewWnd );
//更新overlay窗口，当overlay窗口句柄改变或尺寸，位置改变时调用，overlay窗口就是包含多路显示小窗口的大窗口。overlay窗口必须有一个，多路显示小窗口必须包含再其内部。
BOOL  WINAPI VCAUpdateOverlayWnd(HWND hOverlayWnd);

//保存快照数据到相应的缓冲区
BOOL  WINAPI VCASaveBitsToBuf( DWORD dwCard, PVOID pDestBuf, DWORD& dwWidth, DWORD& dwHeight );
//保存快照为JPEG文件
BOOL  WINAPI VCASaveAsJpegFile( DWORD dwCard, LPCTSTR lpFileName, DWORD dwQuality = 100 );
//保存快照为BMP文件
BOOL  WINAPI VCASaveAsBmpFile( DWORD dwCard, LPCTSTR lpFileName );
//开始视频捕获
BOOL  WINAPI VCAStartVideoCapture( DWORD		dwCard,
								   CAPMODEL	    enCapMode,
								   MP4MODEL		enMp4Mode,
								   LPCTSTR		lpFileName );
//停止视频捕获
BOOL  WINAPI VCAStopVideoCapture( DWORD dwCard );
//设置视频捕获尺寸, dwWidth和dwHeight最好为16的倍数，否则，动态检测为16*16一个检测小块，检测将会不准确。
BOOL  WINAPI VCASetVidCapSize( DWORD dwCard, DWORD dwWidth, DWORD dwHeight );
//得到视频捕获尺寸
BOOL  WINAPI VCAGetVidCapSize( DWORD dwCard, DWORD &dwWidth, DWORD &dwHeight );

/*设置视频捕获帧率，bFrameRateReduction参数为保留参数。	
	PAL显示帧率显示帧率始终为25，NTSC显示帧率始终为30
	PAL捕获帧率最大为25，NTSC捕获帧率最大为30
*/	
BOOL  WINAPI VCASetVidCapFrameRate( DWORD dwCard, DWORD dwFrameRate, BOOL bFrameRateReduction = FALSE );

//设置MPEG压缩的位率,范围:56bps ~ 10Mbps; 单位Kbps
BOOL  WINAPI VCASetBitRate( DWORD dwCard, DWORD dwBitRate);
//设置MPEG压缩的关键帧间隔，必须大于等于帧率
BOOL  WINAPI VCASetKeyFrmInterval( DWORD dwCard, DWORD dwKeyFrmInterval);
//设置MPEG4_XVID压缩的质量 dwQuantizer: 1 ~ 31 (1为最小量度，压缩质量最好); dwMotionPrecision: 0 ~ 6 (0最小运动精度)
BOOL  WINAPI VCASetXVIDQuality( DWORD dwCard, DWORD dwQuantizer, DWORD dwMotionPrecision);
//设置MPEG4_XVID压缩模式
BOOL  WINAPI VCASetXVIDCompressMode( DWORD dwCard, COMPRESSMODE enCompessMode );

//设置动态检测，视频捕获停止时调用有效，VCASetVidCapSize 的设置参数 dwWidth和dwHeight最好为16的倍数，否则，动态检测因16*16一个检测小块，检测将会不准确。
BOOL  WINAPI VCAEnableMotionDetect( DWORD			  dwCard,				   
								    BOOL			  bEnaDetect,		  //是否允许动态检测
								    BYTE			  *pAreaMap,          //运动检测地图
								    LONG			  nSizeOfMap,		  //pAreaMap尺寸,以BYTE为单位
								    LONG			  nPersistTime,       //物体持续nPersistTime秒不动则认为停止 1-30s ,如果nPersistTime = －1;则回调运动检测地图。取消（开始、停止）回调。
								    LPVOID			  lpContext,		  //监测上下文
								    PrcCbMotionDetect OnObjectMove );     //运动/停止回调函数

//设置视频色彩
BOOL  WINAPI VCASetVidDeviceColor( DWORD dwCard, COLORCONTROL enCtlType, DWORD dwValue );

//得到视频源输入频率( 0HZ / 50HZ / 60HZ )对应( 无信号 / PAL制 / NTSC制 ), 参考枚举变量eFieldFrequency
BOOL  WINAPI VCAGetVidFieldFrq( DWORD dwCard, eFieldFrequency &eVidSourceFieldRate );
//设置视频源输入频率( 0HZ / 50HZ / 60HZ )对应( 无信号 / PAL制 / NTSC制 ), 参考枚举变量eFieldFrequency
BOOL  WINAPI VCASetVidFieldFrq( DWORD dwCard, eFieldFrequency eVidSourceFieldRate );

//暂停捕获，暂停视频捕获和音频捕获,可用于快速改变音视频捕获类型和文件切换，设置视频捕获字幕叠加
BOOL  WINAPI VCAPauseCapture( DWORD dwCard );
//设置视频捕获文本叠加
BOOL  WINAPI VCASetVidCapTextOSD( DWORD dwCard, BOOL bEnableOSD, TCHAR*	tcText, POINT& ptTopLeft, OSDPARAM* pOSDParm );
//设置视频捕获时间、日期叠加，在VCASetVidCapDateTimeOSDPARAM()函数设置后调用有效
BOOL  WINAPI VCASetVidCapDateTimeOSD( DWORD dwCard, BOOL bEnableOSD, POINT& ptTopLeft);
//设置视频捕获字幕叠加
BOOL  WINAPI VCASetVidCapDateTimeOSDParam( OSDPARAM* pOSDParm );
//允许视频Mpeg处理回调
BOOL  WINAPI VCAEnableVidMpegProcess( DWORD dwCard, BOOL bEnPorcess, PrcVidMpegPorCallBack ppCall );
//得到设备芯片ID
BOOL  WINAPI VCAGetDeviceID( DWORD dwCard, DWORD& dwDeviceID );
//初始化视频设备，当视频不显示，只需视频录像或音频处理时、或通过VCAInitSdk()函数已经初始化完成可以不初始化。
BOOL  WINAPI VCAInitVidDev( DISPLAYTRANSTYPE eDispTransType = PCI_VIEDOMEMORY);
//读E2C
BOOL  WINAPI VCAIsE2C( DWORD dwCard, BOOL& bIsE2C );
//读E2C
BOOL  WINAPI VCAGetE2C( DWORD dwCard, int iSubAddr, BYTE& ucData );
//写E2C
BOOL  WINAPI VCASetE2C( DWORD dwCard, int iSubAddr, BYTE ucData );
//检验客户信息 pKey:长度为16 字节,用户加密Key值;bSuccess:表示验证是否通过 。
BOOL  WINAPI VCACheckValidate( BYTE* pKey, BOOL& bSuccess );


/////////////////////////////////////////////////////////////////////////////////////////////////
//VC404P音频处理函数
/////////////////////////////////////////////////////////////////////////////////////////////////
//初始化音频设备，是否初始化音频设备用于声音播放，当不音频不需要播放，只需音频录像或视频处理时、或没有安装声卡或通过VCAInitSdk()函数已经初始化完成可以不初始化。
//dwAudFreq:音频播放频率,默认为32K,但有些主板因为某些原因，上传的音频频率可能高于或低于32K,所以根据实际情况，传入这个参数。
BOOL WINAPI VCAInitAudDev( DWORD dwAudFreq = 32000 );
//注册音频捕获原始数据回调
BOOL  WINAPI VCARegAudCapCallBack( DWORD dwCard, PrcAudCapCallBack ppCall );
//注册音频MPEG压缩数据回调
BOOL  WINAPI VCARegAudMpegCallBack( DWORD dwCard, PrcAudMpegCallBack ppCall );
//开始音频捕获，如果音频捕获方式为MPEG4,视频捕获MPEG4方式开始时，调用有效
BOOL  WINAPI VCAStartAudioCapture( DWORD		dwCard, 
								   CAPMODEL	    enCapMode,
								   MP4MODEL	    enMp4Mode );

//允许音频从声卡输出,当dwCard >= 100 时，为静音；开始音频捕获时有效
BOOL  WINAPI VCASetAudioCardOutOn( DWORD dwCard );
//停止音频捕获，如果音频捕获方式为MPEG4,视频捕获MPEG4方式开始时，调用有效
BOOL  WINAPI VCAStopAudioCapture( DWORD dwCard );
//允许音频Mpeg处理回调
BOOL  WINAPI VCAEnableAudMpegProcess( DWORD dwCard, BOOL bEnPorcess, PrcAudMpegPorCallBack ppCall );
/////////////////////////////////////////////////////////////////////////////////////////////////
//VC404P IO处理函数
/////////////////////////////////////////////////////////////////////////////////////////////////
//注册IO报警回调
BOOL  WINAPI VCARegIoAlertCallBack( DWORD dwCard, PrcIoAlertCallBack ppCall );
//设置IO输入报警当前电平
BOOL  WINAPI VCASetIOAlertLevelIn( DWORD dwCard, eVOLTAGELEVEL enCurrentLevel );
//开始IO输入报警，enSpringLevel为触发电平
BOOL  WINAPI VCAStartIOAlertIn( DWORD dwCard, eVOLTAGELEVEL enSpringLevel );
//停止IO输入报警
BOOL  WINAPI VCAStopIOAlertIn( DWORD dwCard );
//IO输出报警
BOOL  WINAPI VCAIOAlertOut( DWORD dwCard, eVOLTAGELEVEL enLevel );
#endif
