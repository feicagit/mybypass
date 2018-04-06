#pragma once

#include "module/video/video_manager.h"


namespace nim_comp
{

typedef enum {
	EN_PLAYER_IDLE,
	EN_PLAYER_PREPARING,
	EN_PLAYER_PLAYING,
	EN_PLAYER_STOPPING,
	EN_PLAYER_STOPPED,
	EN_PLAYER_FAILED,
} EN_PLAYER_STATE;

typedef std::function<void(EN_PLAYER_STATE)> PlayerStateCallback;

/** @class VideoManager
* @brief ���Ź�����
* @copyright (c) 2016, NetEase Inc. All rights reserved
* @date 2016/09/18
*/
class PlayerManager : public nbase::SupportWeakCallback
{
public:
	SINGLETON_DEFINE(PlayerManager);

	/**
	* ���Ź�������Ӧ������Ϣ�ص�
	* @param[in] msg ��Ϣ
	@ return void	�޷���ֵ
	*/
	static void OnMessageCB(ST_NELP_MESSAGE msg);

	/**
	* ��Ƶ���ݵĻص�
	* @param[in] frame ��Ƶ����֡
	@ return void	�޷���ֵ
	*/
	static void OnGetVideoFrameCB(ST_NELP_FRAME *frame);

	/**
	* ��Դ�ͷųɹ��Ļص�
	@ return void	�޷���ֵ
	*/
	static void OnResourceReleaseSuccessCB();

	/**
	* ������Ƶ���������sdk��̬�⣨Ӧ���ڳ����ʼ��ʱ���ã�
	* @return void	�޷���ֵ
	*/
	void LoadPlayerDll();

	/**
	* ����UI���
	* @return void	�޷���ֵ
	*/
	void CleanupPlayer();

	/**
	* ��ʼ�������ţ�����ǰִ��Nelp_InitParam��Nelp_PrepareToPlay
	* @param[in] pull_rtmp_url ������ַ
	* @return bool �����Ƿ�ɹ�
	*/
	bool StartPlay(const std::string& pull_rtmp_url,const std::string& creater_id);

	/**
	* ֹͣ��������
	* @return void �޷���ֵ
	*/
	bool StopPlay();

	/**
	* ֹͣ��������
	* @return void �޷���ֵ
	*/

	/**
	* ����״̬�仯
	* @param in state ��״̬
	* @return void �޷���ֵ
	*/
	void PlayerStateChange(EN_PLAYER_STATE state);
	EN_PLAYER_STATE GetPlayerState(){ return player_state_; };

	/**
	* ע�Ქ��״̬�仯�ص�
	* @param in callback �ص��հ�
	* @return UnregisterCallback ���ط�ע��ص�
	*/
	UnregisterCallback RegPlayerStateCallback(const PlayerStateCallback& callback);

private:
	PlayerManager();
	~PlayerManager();
	void StopPlayOnError();\
	void DoStatPlay(const std::string& pull_rtmp_url, const std::string& creater_id);
	void DoStopPlay();
	void OnStartPlayTimeout();
	void OnGetVideoFrameTimeout();
	friend void UIPlayerReleaseCallback();
	friend void UIPlayerMessageCallBack(ST_NELP_MESSAGE msg);
	friend void UIPlayerGetVideoFrameCB(const std::shared_ptr<ST_NELP_FRAME>& frame);

private:
	EN_PLAYER_STATE player_state_ = EN_PLAYER_IDLE; // player��ǰ״̬
	EN_PLAYER_STATE stopped_state_ = EN_PLAYER_STOPPED; // player��ȫ�ر�ʱ��״̬
	std::map<int, std::unique_ptr<PlayerStateCallback>> player_state_cb_list_;
	nbase::NLock player_lock_; //������ͬ����
	nbase::WeakCallbackFlag start_play_timer_; //��ʱ��ʱ��
	nbase::WeakCallbackFlag video_frame_timer_; //��Ƶ���ݳ�ʱ��ʱ��
};
}