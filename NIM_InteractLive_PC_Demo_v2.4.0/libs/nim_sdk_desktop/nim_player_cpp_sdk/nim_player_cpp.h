/** @file nim_chatroom_cpp.h
* @brief NIM�ṩ�Ĳ������ӿ�
* @copyright (c) 2015-2017, NetEase Inc. All rights reserved
* @author Oleg, Harrison
* @date 2015/12/29
*/

#ifndef _NIM_PLAYER_SDK_CPP_H_
#define _NIM_PLAYER_SDK_CPP_H_

#include <string>
#include <functional>
#include "nelp_define.h"
#include "nelp_type.h"

/**
* @namespace nim_player
* @brief ������
*/
namespace nim_player
{

/** @class ChatRoom
* @brief ������
*/
class Player
{

public:
	/** @fn  void RegMessageCB(MessgeCallbac& cb);
	* @brief ע���ȡ��Ϣ�Ļص�, �û���Ҫʵ�ֻص�����cb�����������Ϣ
	* @param cb[in]:   ��ȡ��Ϣ�Ļص�
	* @return ��
	*/
	static void RegMessageCB(P_NELP_MESSAGE_CB cb);

	/**@fn  NELP_RET RegGetVideoFrameCB(_GetVideoFrameCallback& cb)
	* @brief ע���ȡ��Ƶ֡���ݵĻص����û���Ҫʵ�ֻص�����cb��������Ƶ֡
	* @param cb[in]:  ��ȡ��Ƶ֡�Ļص�
	* @return  NELP_RET: NELP_OK �ɹ�; NELP_ERR ʧ��
	*/
	static NELP_RET RegGetVideoFrameCB(bool bIsRender, EN_NELP_MEDIA_FORMAT eMFormat, P_NELP_VIDEO_FRAME_CB cb);

	/**@fn void  RegResourceReleaseSuccessCB(ResourceRealeaseCallback&cb)
	* @brief ע���ȡ��Դ�ͷŽ�����Ϣ�Ļص�(��Դ�ͷ����첽��), �û���Ҫʵ�ֻص�����cb�����������Ϣ
	* @param cb[in]:   ��ȡ��Դ�ͷŽ�����Ϣ�Ļص�
	* @return �޷���ֵ
	*/
	static void  RegResourceReleaseSuccessCB(P_NELP_RESOURCE_RELEASE_SUCCESS_CB cb);

	/**@fnvoid  LoadPlayerDll( )
	* @brief ���ز�����sdk��̬��
	* @param ��
	* @return �޷���ֵ
	*/
	static void LoadPlayerDll();
	/**@fn NELP_RET Create(const std::string& paLogpath)
	* @brief ����������ʵ��
	* @param paLogpath[in]:    ��־�ļ�·��   ���
	* @return NELP_RET: NELP_OK �ɹ�; NELP_ERR ʧ��
	*/
	static NELP_RET Create(const std::string& paLogpath);

	/**@fn  void SetDisPlay( const std::string&windowSurface)
	* @brief ������ʾ���ھ����������ʾ
	* @param windowSurface[in]: ��ʾ���ھ��
	* @return �޷���ֵ
	*/
	static  void  SetDisPlay(const void* wnd);

	/**@fn NELP_RET InitParam( ST_NELP_PARAM *pstParam)
	* @brief ��ʼ���������������ŵ�ַ������ģʽ��
	* @param pstParam[in]:    ��ز���
	* @return  NELP_RET: NELP_OK �ɹ�; NELP_ERR ʧ��
	*/
	static NELP_RET InitParam(const ST_NELP_PARAM* pstParam);

	/**@fn void  PrepareToPlay(c)
	* @brief Ԥ�������������������������ȣ�������ó�autoPlay����Ԥ������ɺ���Զ�����
	* @return ��
	*/
	static void PrepareToPlay();

	/**@fn void Start(_const std::string& json_extension = "")
	* @brief ��ͣ��ָ�����
	* @param[in] json_extension json��չ���������ã�Ŀǰ����Ҫ��
	* @return �޷���ֵ
	*/
	static void Start();

	/**@fn Pause(const std::string& json_extension = "")
	* @brief ��ͣ����
	* @return �޷���ֵ
	*/
	static void Pause();

	/** @fn Shutdown()
	* @brief �رյ�ǰ������Ƶ
	* @return �޷���ֵ
	*/
	static void Shutdown();

	/** @fn Shutdown()
	* @brief �رղ��������ͷ������Դ
	* @return �޷���ֵ
	*/
	static void ClosePlayer();

	/**@fn SetMute( bool bIsMute)
	* @brief ��������
	* @param bIsMute[in]: true ��������; false �����ָ�   ���
	* @return �޷���ֵ
	*/
	static void SetMute(bool bIsMute);

	/**@fn GetCurrentPlaybackTime()
	* @brief ��ȡ��ǰ����λ�ã��������ڵ㲥��
	* @return ��ǰ����λ��
	*/
	static long GetCurrentPlaybackTime();

	/**@fn long  GetDuration()
	* @brief ��ȡ�ļ���ʱ�����������ڵ㲥��
	* @return �ļ���ʱ��
	*/
	static long GetDuration();

	/**@fn long  GetPlayableDuration()
	* @brief ��ȡ��ǰ�ɲ��ŵ�λ�ã����ѻ����λ�ã��������ڵ㲥��
	* @return ��ǰ�ɲ���λ��
	*/
	static long GetPlayableDuration();

	/**@fn SeekTo(const uint64_t lTime)
	* @brief ָ����ĳһʱ��㲥�ţ��������ڵ㲥��
	* @param lTime[in]: ָ���Ĳ���ʱ���(��λ: ���� ms)
	* @return NELP_RET: NELP_OK  �ɹ�    NELP_ERR  ʧ��
	*/
	static NELP_RET SeekTo(const long lTime);

	/**@fn  NELP_RET SetVolume(const float fVolume)
	* @brief ��������
	* @param fVolume: ������С (��Χ: 0.0 ~ 1.0  0.0:����   1.0:���) ���
	* @return: NELP_RET: NELP_OK  �ɹ�    NELP_ERR  ʧ��
	*/
	static NELP_RET SetVolume(const float fVolume);

	/**@fn void GetSDKVersion(const std::string& ppaVersion)
	* @brief ��ȡSDK�汾��
	* @param ppaVersion[in]: SDK�汾��    ��
	* @return �޷���ֵ
	*/
	static void GetSDKVersion(const std::string& ppaVersion);

	/**@fn EN_NELP_PLAYBACK_STATE GetPlaybackState()
	* @brief ��ȡ��ǰ��������״̬
	* @return EN_NELP_PLAYBACK_STATE: ������״̬   ����	EN_NELP_GET_PLAYBACK_STATE_FAILED ���ʾ��ȡʧ��
	*/
	static EN_NELP_PLAYBACK_STATE GetPlaybackState();

	/**@fn ST_NELP_PICTURE *GetSnapshot(const EN_NELP_PICTURE_FORMAT ePFormat)
	* @brief ��ͼ����, ÿ�ν�ͼ�ɹ��󷵻�һ��ͼƬ
	* @param ePFormat[in]: ͼƬ��ʽ
	* @return ST_NELP_PICTURE: ��������ͼƬ��ԭʼ���ݺ���Ϣ
	*/
	static ST_NELP_PICTURE *GetSnapshot(const EN_NELP_PICTURE_FORMAT ePFormat);

private:
	template <typename F>
	static F Function(const char* function_name)
	{
		F f = (F) ::GetProcAddress(instance_player_, function_name);
		assert(f);
		return f;
	}

private:
	static HINSTANCE  instance_player_;
	static _HNLPSERVICE phNLPService;
};

}
#endif //_NIM_PLAYER_SDK_CPP_H_