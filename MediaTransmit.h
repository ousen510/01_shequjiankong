#ifndef	MEDIATRANSMIT_INCLUDE
#define	MEDIATRANSMIT_INCLUDE

#ifdef MEDIATRANSMIT_EXPORTS
#define MEDIATRANSMIT_API __declspec(dllexport)
#else
#define MEDIATRANSMIT_API __declspec(dllimport)
#endif

/*命令执行返回值 0-31为系统使用，32-63为用户自定义错误*/
#define		ERR_CMD_SUCCESS			0
#define		ERR_CMD_TIMEOUT			1
#define		ERR_CMD_INVALID			2
#define		ERR_CMD_OUTOFMEMORY		3
#define		ERR_CMD_OUTOFUSER		4
#define		ERR_CMD_REQ_EXIST		5
#define		ERR_CMD_OUTOFRESOURCE	6
#define		ERR_CMD_CRCCHECK		7
#define		ERR_CMD_SRVNOTFOUND		8				/*服务器没有注册*/

#define		ERR_CON_RESET		12		//connection reset.
#define		ERR_CON_REMOTE_CLOSE		13

/*系统错误常量定义 128 - ~*/
#define		ERR_SYS_NOTMCARD			128			/*没有VC404卡*/
#define		ERR_SYS_UNINITIALIZE		129			/*系统未初始化*/
#define		ERR_SYS_OUTOFMEMORY			130			/*内存资源请求错误*/
#define		ERR_SYS_NONEWCALL			131			/*没有创建Call资源*/
#define		ERR_SYS_NOCONNCALL			132			/*没有连接的Call*/		
#define		ERR_SYS_NONSTANDPARAM		133			/*使用非标准参数*/
#define		ERR_SYS_SETSOCKETBUF		134			/*设置网络收发缓冲时出错*/
#define		ERR_SYS_ROLEACT				135			/*角色错误*/
#define		ERR_SYS_OUTOFIDRANGE		136			/*非法call id*/
#define		ERR_SYS_WANMULTICAST		137			/*广域网多播错误*/
#define		ERR_SYS_MULTICASTADDR		138			/*多播地址错误*/
#define		ERR_SYS_JOINMULTIGROUP		139			/*加入多播组错误*/
#define		ERR_SYS_CREATWINDOW			140			/*创建overlay依附窗体时出错*/
#define		ERR_SYS_CREATEOVERLAY		141			/*overlay表面创建错误*/
#define		ERR_SYS_INVALIDWINDOW		142			/*创建视频设备时主窗口参数错误*/
#define		ERR_SYS_CAPMODE				143			/*捕获模式错误*/
#define		ERR_SYS_CREATECAPFILE		144			/*创建捕获文件时出错*/
#define		ERR_SYS_CAPAUDIO			145			/*音频捕获存盘错误*/
#define		ERR_SYS_CAPVIDEO			146			/*视频捕获存盘错误*/
#define		ERR_SYS_MPEG4				147			/*MPEG4初始化错误*/
#define		ERR_SYS_INVALDOBJECTID		148			/*无效的对象id,对象未初始化*/
#define		ERR_SYS_OPENPLAYFILE		149			/*回放文件不存在或格式错误*/
#define		ERR_SYS_PLAYFILETYPE		150			/*未知的播放媒体类型*/
#define		ERR_SYS_PLAYFILEFORMAT		151			/*播放文件格式错误*/
#define		ERR_SYS_GETBASETIME			152			/*不能获取播放文件基准时间*/
#define		ERR_SYS_UNINITPLAY			153			/*未成功初始化的回放操作*/
#define		ERR_SYS_PLAYLOCATE			154			/*回放文件定位错误*/
#define		ERR_SYS_PLAYMODE			155			/*无效的播放模式*/
#define		ERR_SYS_DISPLAYINIT			156			/*显示设备未初始化*/
#define		ERR_SYS_PARAMLEN			157			/*注册服务器时参数长度错误*/
#define		ERR_SYS_REGUSERNAME			158			/*非法注册用户名*/
#define		ERR_SYS_WAITFAILED			159			/*对象等待出错*/



/*角色定义*/
#define		WORK_AS_SERVER				0		/*发送端*/
#define		WORK_AS_CLIENT				1		/*接收端*/
#define		WORK_AS_SUPPLY				2		/*代理端*/

#define		SAVE_VIDEO_DATA				0x1		/*存储视频流*/
#define		SAVE_AUDIO_DATA				0x2		/*存储音频流*/
#define		PLAY_VIDEO_DATA				0x1		/*播放视频流*/
#define		PLAY_AUDIO_DATA				0x2		/*播放音频流*/


#ifndef WM_VIDEOWND_NOTIFY
	#define		WM_VIDEOWND_NOTIFY	WM_USER+0x501
#endif

typedef struct tagTrafficStatus
{
	DWORD Rxbitrate;		/*当前Rx bit rate 统计值*/
	DWORD Framerate;		/*当前Frame rate 统计值*/
	DWORD IFramerate;		/*当前IFrame bitrate 统计值*/
	DWORD PFramerate;		/*当前PFrame bit rate 统计值,暂不用*/
}TRAFFIC_PARAM;

typedef enum tagDecoderType
{
	MPEG4_DEC,
	XVID_DEC

}DECODER_TYPE;

typedef enum Mpeg4Version
{
	MPEG4_V1 = 1,
    MPEG4_V2,
	MPEG4_V3,
	MPEG4_XVID
}MPEG4_VERSION;

/*命令请求参数定义(0-15供系统请求发送使用，16-31供NTF通知请求使用，32-127为自定义区*/
#define		REQ_AV_STREAM			1						/*请求视频+音频流*/
#define		REQ_VI_STREAM			2						/*请求视频流*/
#define		REQ_AU_STREAM			3						/*请求音频流*/
#define		REQ_CLEAR_AV			4						/*请求关闭AV流*/
#define		REQ_CLEAR_VI			5						/*请求关闭视频流*/
#define		REQ_CLEAR_AU			6						/*请求关闭音频流*/

#define		NTF_FREE_CALL			16						/*服务器通知,远端终止*/

#define		NET_STATUS				32		//connection status.

MEDIATRANSMIT_API WORD MTACalculateCrc(BYTE *pData,int nSize);

MEDIATRANSMIT_API void MTASetRequestTimeOut(WORD usTimeOut);

MEDIATRANSMIT_API BOOL MTASetVideoOut(int nCallID,int nIndex);
MEDIATRANSMIT_API int  MTAGetIndexByCallID(int nCallID);
MEDIATRANSMIT_API int  MTAGetCallIDByIndex(int nIndex);

MEDIATRANSMIT_API int  MTASetSplitMode(int nMode);
MEDIATRANSMIT_API int  MTAPageDown();
MEDIATRANSMIT_API int  MTAPageUp();
MEDIATRANSMIT_API int  MTAGetPageNo();

MEDIATRANSMIT_API BOOL MTACreateAudioDevice(HWND hMainWnd);
MEDIATRANSMIT_API BOOL MTASetAudioPass(int nObjID);
MEDIATRANSMIT_API void MTASendMessage(UINT nMessage,WPARAM wParam,LPARAM lParam);

MEDIATRANSMIT_API int  MTACreateVideoDevice(HWND hParentWnd,	/*父窗口*/
										    HWND hNotifyWnd,	/*消息通知窗口*/
											RECT rect,
											int  nWidth, 
											int  nHeight, 
											int  nSpace,		/*间隔*/
											BOOL bUseOverlay);	

MEDIATRANSMIT_API void MTASetLastError(int Errno);
MEDIATRANSMIT_API int  MTAGetLastError();
MEDIATRANSMIT_API BOOL MTASetWndPos(RECT rc);

MEDIATRANSMIT_API void MTAGetNetTraffic(int nCallID,TRAFFIC_PARAM &TrafficBuf);

typedef void (*EvCaptureAbnormity)(int nCallID,int nError);

MEDIATRANSMIT_API BOOL MTAStartCapture(int nCallID, 
									   const char *pFileName,
									   DWORD dwMode,
									   EvCaptureAbnormity evCapAbnormity);

MEDIATRANSMIT_API void MTAStopCapture(int nCallID);

MEDIATRANSMIT_API BOOL MTAGetCapState(int nCallID,BOOL &bCapVid,BOOL &bCapAud);

typedef void (*EvCmdRespond)(int nCallId,unsigned char biCmd,int nResult,BYTE *pRetData);

MEDIATRANSMIT_API BOOL MTALoadLibrary(WORD usLocalPort,			/*本地帧听端口*/
									  WORD usRole);				/*角色*/

MEDIATRANSMIT_API void MTAFreeLibrary();

MEDIATRANSMIT_API BOOL MTAConfigNetwork(int nCallID,int &iSndBufSize,int &iRcvBufSize);

MEDIATRANSMIT_API LONGLONG MTARequest(int			nCallID,		/*Call ID*/			
								      BYTE			biReqType,		/*请求命令字*/
 									  BYTE			biMaxRepeat,	/*最大重试次数*/
									  BYTE			*pAnnexData,	/*附加数据*/
								      WORD			inDataSize,		/*附加数据长度*/
									  BYTE			*pRetBuffer,	/*返回数据存放地址*/
									  WORD			retBufSize,		/*缓冲区长度*/
									  HANDLE		hEventNotify,	/*通知事件*/
								      EvCmdRespond	evCallNotify);	/*通知回调函数*/

MEDIATRANSMIT_API LONGLONG MTANotify(char			*pClientAddr,	/*客户机地址*/
									 WORD			usClientPort,	/*客户机端口*/
									 BYTE			biReqType,		/*请求命令字*/
 									 BYTE			biMaxRepeat,	/*最大重试次数*/
									 BYTE			*pAnnexData,	/*附加数据*/
									 WORD			inDataSize,		/*附加数据长度*/
									 BYTE			*pRetBuffer,	/*返回数据存放地址*/
									 WORD			retBufSize,		/*缓冲区长度*/
									 HANDLE			hEventNotify,	/*通知事件*/
									 EvCmdRespond	evCallNotify);	/*通知回调函数*/

MEDIATRANSMIT_API int   MTANewCall(char		*pRemoteIp,
								   WORD		 usRemotePort,
								   BYTE		 biCardNo);

MEDIATRANSMIT_API BOOL  MTAMakeCall(int				nCallID,
								    BYTE			biReqType,
									BOOL			bWANCall,
								    BYTE			*lpSndData,
								    BYTE			biSndSize, 
								    HANDLE			hEventNotify,
								    EvCmdRespond	evCallNotify);

MEDIATRANSMIT_API void MTAClearCall(int nCallId,BOOL bWait);

MEDIATRANSMIT_API void MTADiscardCall(BYTE	biCard,
									  DWORD dwRemoteIp,
									  WORD  usRemotePort,
									  BOOL  bWait);

MEDIATRANSMIT_API BOOL  MTARequestStream(int			nCallID,		/*Call ID*/
										 BOOL			bVStream,		/*TRUE:视频流，FALSE:音频流*/
										 BOOL			bOpen,			/*TRUE:打开，FALSE:关闭*/
									     BYTE			*lpSndData,		/*附加数据指针*/
										 BYTE			 biSndSize,		/*附加数据长度*/
										 HANDLE			hEventNotify,	/*通知事件*/
										 EvCmdRespond	evCallNotify);	/*通知回调函数*/


typedef BYTE (*EvInComingRequest)(DWORD dwIp,WORD usPort,BYTE biCardNo,BYTE biCmd,BYTE *lpInData,WORD biInSize,BYTE *lpOutData,WORD &biOutSize);


MEDIATRANSMIT_API BOOL MTARegNotifier(EvInComingRequest evNotifier);


MEDIATRANSMIT_API BOOL MTAWriteVideo(BYTE  nCardNo, BYTE *pData,
									 LONG  lSize,   BOOL  bIFrm);

MEDIATRANSMIT_API BOOL MTAWriteAudio(BYTE  nCardNo, BYTE *pData,
									 LONG  lSize);

/*回放函数定义*/
MEDIATRANSMIT_API int   MTANewPlayBack(LPCTSTR lpFileName);
MEDIATRANSMIT_API void  MTAFreePlayBack(int nPlayBackId);
MEDIATRANSMIT_API BOOL  MTAOpenFile(int nPlayBackID,LPCTSTR lpFileName);
MEDIATRANSMIT_API void  MTACloseFile(int nPlayBackID);
MEDIATRANSMIT_API BOOL  MTASetPlayPosition(int nPlayBackID, DWORD dwPlayTime);
MEDIATRANSMIT_API DWORD MTAGetPlayPosition(int nPlayBackID,BOOL &bPlaying);
MEDIATRANSMIT_API BOOL  MTAGetVideoSize(int nPlayBackID,WORD &usWidth,WORD &usHeight);
MEDIATRANSMIT_API BOOL  MTAStartPlay(int nPlayBackID,DWORD dwMode);
MEDIATRANSMIT_API void  MTAPausePlay(int nPlayBackID);
MEDIATRANSMIT_API int   MTAGetPlayTimeLen(int nPlayBackID);

/*内网-内网专用函数*/
MEDIATRANSMIT_API BOOL MTARegServer(const char 	   *lpRegUserName,	/*注册用户名*/
									const char 	   *lpRegPassword,	/*注册密码*/
									const char     *lpSupplyAddr,	/*代理地址*/
									WORD			usSupplyPort,	/*代理端口*/
									EvCmdRespond	evCallNotify);	/*响应回调函数*/

MEDIATRANSMIT_API BOOL MTAGetSrvAddr(int			nCallID,		/*call id*/
									 const char 	*lpServerName,	/*服务器注册名*/
									 const char     *lpSupplyAddr,	/*代理地址*/
									 WORD			usSupplyPort);	/*代理端口*/
/*MPEG4 VERSION SET FUNCTION*/
MEDIATRANSMIT_API BOOL MTASetMpeg4Version(MPEG4_VERSION nVersion);

typedef void (*EvVidMpeg)(int nCallId, BYTE* pBuf, BOOL	bIntraFrm, DWORD dwFrmSize, DWORD dwTimeStramp);
MEDIATRANSMIT_API BOOL MTARegVidMpegCallBack(int nCallID, BOOL bEnCallBack, EvVidMpeg evVid);

typedef void (*EvAudMpeg)(int nCallId, BYTE* pBuf, DWORD dwFrmSize, DWORD dwTimeStramp);
MEDIATRANSMIT_API BOOL MTARegAudMpegCallBack(int nCallID, BOOL bEnCallBack, EvAudMpeg evAud);

MEDIATRANSMIT_API BOOL MTADrawFrame( int nIndex );

#endif