#ifndef	MEDIATRANSMIT_INCLUDE
#define	MEDIATRANSMIT_INCLUDE

#ifdef MEDIATRANSMIT_EXPORTS
#define MEDIATRANSMIT_API __declspec(dllexport)
#else
#define MEDIATRANSMIT_API __declspec(dllimport)
#endif

/*����ִ�з���ֵ 0-31Ϊϵͳʹ�ã�32-63Ϊ�û��Զ������*/
#define		ERR_CMD_SUCCESS			0
#define		ERR_CMD_TIMEOUT			1
#define		ERR_CMD_INVALID			2
#define		ERR_CMD_OUTOFMEMORY		3
#define		ERR_CMD_OUTOFUSER		4
#define		ERR_CMD_REQ_EXIST		5
#define		ERR_CMD_OUTOFRESOURCE	6
#define		ERR_CMD_CRCCHECK		7
#define		ERR_CMD_SRVNOTFOUND		8				/*������û��ע��*/

#define		ERR_CON_RESET		12		//connection reset.
#define		ERR_CON_REMOTE_CLOSE		13

/*ϵͳ���������� 128 - ~*/
#define		ERR_SYS_NOTMCARD			128			/*û��VC404��*/
#define		ERR_SYS_UNINITIALIZE		129			/*ϵͳδ��ʼ��*/
#define		ERR_SYS_OUTOFMEMORY			130			/*�ڴ���Դ�������*/
#define		ERR_SYS_NONEWCALL			131			/*û�д���Call��Դ*/
#define		ERR_SYS_NOCONNCALL			132			/*û�����ӵ�Call*/		
#define		ERR_SYS_NONSTANDPARAM		133			/*ʹ�÷Ǳ�׼����*/
#define		ERR_SYS_SETSOCKETBUF		134			/*���������շ�����ʱ����*/
#define		ERR_SYS_ROLEACT				135			/*��ɫ����*/
#define		ERR_SYS_OUTOFIDRANGE		136			/*�Ƿ�call id*/
#define		ERR_SYS_WANMULTICAST		137			/*�������ಥ����*/
#define		ERR_SYS_MULTICASTADDR		138			/*�ಥ��ַ����*/
#define		ERR_SYS_JOINMULTIGROUP		139			/*����ಥ�����*/
#define		ERR_SYS_CREATWINDOW			140			/*����overlay��������ʱ����*/
#define		ERR_SYS_CREATEOVERLAY		141			/*overlay���洴������*/
#define		ERR_SYS_INVALIDWINDOW		142			/*������Ƶ�豸ʱ�����ڲ�������*/
#define		ERR_SYS_CAPMODE				143			/*����ģʽ����*/
#define		ERR_SYS_CREATECAPFILE		144			/*���������ļ�ʱ����*/
#define		ERR_SYS_CAPAUDIO			145			/*��Ƶ������̴���*/
#define		ERR_SYS_CAPVIDEO			146			/*��Ƶ������̴���*/
#define		ERR_SYS_MPEG4				147			/*MPEG4��ʼ������*/
#define		ERR_SYS_INVALDOBJECTID		148			/*��Ч�Ķ���id,����δ��ʼ��*/
#define		ERR_SYS_OPENPLAYFILE		149			/*�ط��ļ������ڻ��ʽ����*/
#define		ERR_SYS_PLAYFILETYPE		150			/*δ֪�Ĳ���ý������*/
#define		ERR_SYS_PLAYFILEFORMAT		151			/*�����ļ���ʽ����*/
#define		ERR_SYS_GETBASETIME			152			/*���ܻ�ȡ�����ļ���׼ʱ��*/
#define		ERR_SYS_UNINITPLAY			153			/*δ�ɹ���ʼ���ĻطŲ���*/
#define		ERR_SYS_PLAYLOCATE			154			/*�ط��ļ���λ����*/
#define		ERR_SYS_PLAYMODE			155			/*��Ч�Ĳ���ģʽ*/
#define		ERR_SYS_DISPLAYINIT			156			/*��ʾ�豸δ��ʼ��*/
#define		ERR_SYS_PARAMLEN			157			/*ע�������ʱ�������ȴ���*/
#define		ERR_SYS_REGUSERNAME			158			/*�Ƿ�ע���û���*/
#define		ERR_SYS_WAITFAILED			159			/*����ȴ�����*/



/*��ɫ����*/
#define		WORK_AS_SERVER				0		/*���Ͷ�*/
#define		WORK_AS_CLIENT				1		/*���ն�*/
#define		WORK_AS_SUPPLY				2		/*�����*/

#define		SAVE_VIDEO_DATA				0x1		/*�洢��Ƶ��*/
#define		SAVE_AUDIO_DATA				0x2		/*�洢��Ƶ��*/
#define		PLAY_VIDEO_DATA				0x1		/*������Ƶ��*/
#define		PLAY_AUDIO_DATA				0x2		/*������Ƶ��*/


#ifndef WM_VIDEOWND_NOTIFY
	#define		WM_VIDEOWND_NOTIFY	WM_USER+0x501
#endif

typedef struct tagTrafficStatus
{
	DWORD Rxbitrate;		/*��ǰRx bit rate ͳ��ֵ*/
	DWORD Framerate;		/*��ǰFrame rate ͳ��ֵ*/
	DWORD IFramerate;		/*��ǰIFrame bitrate ͳ��ֵ*/
	DWORD PFramerate;		/*��ǰPFrame bit rate ͳ��ֵ,�ݲ���*/
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

/*���������������(0-15��ϵͳ������ʹ�ã�16-31��NTF֪ͨ����ʹ�ã�32-127Ϊ�Զ�����*/
#define		REQ_AV_STREAM			1						/*������Ƶ+��Ƶ��*/
#define		REQ_VI_STREAM			2						/*������Ƶ��*/
#define		REQ_AU_STREAM			3						/*������Ƶ��*/
#define		REQ_CLEAR_AV			4						/*����ر�AV��*/
#define		REQ_CLEAR_VI			5						/*����ر���Ƶ��*/
#define		REQ_CLEAR_AU			6						/*����ر���Ƶ��*/

#define		NTF_FREE_CALL			16						/*������֪ͨ,Զ����ֹ*/

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

MEDIATRANSMIT_API int  MTACreateVideoDevice(HWND hParentWnd,	/*������*/
										    HWND hNotifyWnd,	/*��Ϣ֪ͨ����*/
											RECT rect,
											int  nWidth, 
											int  nHeight, 
											int  nSpace,		/*���*/
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

MEDIATRANSMIT_API BOOL MTALoadLibrary(WORD usLocalPort,			/*����֡���˿�*/
									  WORD usRole);				/*��ɫ*/

MEDIATRANSMIT_API void MTAFreeLibrary();

MEDIATRANSMIT_API BOOL MTAConfigNetwork(int nCallID,int &iSndBufSize,int &iRcvBufSize);

MEDIATRANSMIT_API LONGLONG MTARequest(int			nCallID,		/*Call ID*/			
								      BYTE			biReqType,		/*����������*/
 									  BYTE			biMaxRepeat,	/*������Դ���*/
									  BYTE			*pAnnexData,	/*��������*/
								      WORD			inDataSize,		/*�������ݳ���*/
									  BYTE			*pRetBuffer,	/*�������ݴ�ŵ�ַ*/
									  WORD			retBufSize,		/*����������*/
									  HANDLE		hEventNotify,	/*֪ͨ�¼�*/
								      EvCmdRespond	evCallNotify);	/*֪ͨ�ص�����*/

MEDIATRANSMIT_API LONGLONG MTANotify(char			*pClientAddr,	/*�ͻ�����ַ*/
									 WORD			usClientPort,	/*�ͻ����˿�*/
									 BYTE			biReqType,		/*����������*/
 									 BYTE			biMaxRepeat,	/*������Դ���*/
									 BYTE			*pAnnexData,	/*��������*/
									 WORD			inDataSize,		/*�������ݳ���*/
									 BYTE			*pRetBuffer,	/*�������ݴ�ŵ�ַ*/
									 WORD			retBufSize,		/*����������*/
									 HANDLE			hEventNotify,	/*֪ͨ�¼�*/
									 EvCmdRespond	evCallNotify);	/*֪ͨ�ص�����*/

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
										 BOOL			bVStream,		/*TRUE:��Ƶ����FALSE:��Ƶ��*/
										 BOOL			bOpen,			/*TRUE:�򿪣�FALSE:�ر�*/
									     BYTE			*lpSndData,		/*��������ָ��*/
										 BYTE			 biSndSize,		/*�������ݳ���*/
										 HANDLE			hEventNotify,	/*֪ͨ�¼�*/
										 EvCmdRespond	evCallNotify);	/*֪ͨ�ص�����*/


typedef BYTE (*EvInComingRequest)(DWORD dwIp,WORD usPort,BYTE biCardNo,BYTE biCmd,BYTE *lpInData,WORD biInSize,BYTE *lpOutData,WORD &biOutSize);


MEDIATRANSMIT_API BOOL MTARegNotifier(EvInComingRequest evNotifier);


MEDIATRANSMIT_API BOOL MTAWriteVideo(BYTE  nCardNo, BYTE *pData,
									 LONG  lSize,   BOOL  bIFrm);

MEDIATRANSMIT_API BOOL MTAWriteAudio(BYTE  nCardNo, BYTE *pData,
									 LONG  lSize);

/*�طź�������*/
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

/*����-����ר�ú���*/
MEDIATRANSMIT_API BOOL MTARegServer(const char 	   *lpRegUserName,	/*ע���û���*/
									const char 	   *lpRegPassword,	/*ע������*/
									const char     *lpSupplyAddr,	/*�����ַ*/
									WORD			usSupplyPort,	/*����˿�*/
									EvCmdRespond	evCallNotify);	/*��Ӧ�ص�����*/

MEDIATRANSMIT_API BOOL MTAGetSrvAddr(int			nCallID,		/*call id*/
									 const char 	*lpServerName,	/*������ע����*/
									 const char     *lpSupplyAddr,	/*�����ַ*/
									 WORD			usSupplyPort);	/*����˿�*/
/*MPEG4 VERSION SET FUNCTION*/
MEDIATRANSMIT_API BOOL MTASetMpeg4Version(MPEG4_VERSION nVersion);

typedef void (*EvVidMpeg)(int nCallId, BYTE* pBuf, BOOL	bIntraFrm, DWORD dwFrmSize, DWORD dwTimeStramp);
MEDIATRANSMIT_API BOOL MTARegVidMpegCallBack(int nCallID, BOOL bEnCallBack, EvVidMpeg evVid);

typedef void (*EvAudMpeg)(int nCallId, BYTE* pBuf, DWORD dwFrmSize, DWORD dwTimeStramp);
MEDIATRANSMIT_API BOOL MTARegAudMpegCallBack(int nCallID, BOOL bEnCallBack, EvAudMpeg evAud);

MEDIATRANSMIT_API BOOL MTADrawFrame( int nIndex );

#endif