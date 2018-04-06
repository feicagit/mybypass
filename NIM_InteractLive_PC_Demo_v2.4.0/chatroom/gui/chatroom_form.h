#pragma once
/*********************************** PC��·ֱ��Demo��һЩ˵�� **************************************
************************************** ��Ϣ��ʽ ****************************************************
*�������뷿���ext���ĸ�ʽ��.{type:xxxx} type��-1,1,2 ps.-1����δ����,1��audio��2��vedio.
*
*����������и�ʽ��      style:����,��Ƶ
*                        state:�ȴ��������У�������
*                        info:  nick:
*                               avactar:avatar_default
*
*������������֪ͨ��ʽ��      Data:uid: 
							      nick:
*                                 avatar:
*                                 style:   1.audio,2.vedio
*                            type:2,3  ps.2��ͬ������ 3�ǶϿ�����
*
*�Զ���ϵͳ֪ͨ��ʽ��  style:��������Ƶ
*                      command:֪ͨ����,1,2,3,4,5.ps.��PushMicNotificationType
*                      info: nick:
*                            avatar:
*                      roomid:
*                
***************************************** ����˵�� ****************************************
**********************��������������
*******************����*******************     *******************����*******************     
* ���Լ����뵽������                             
* �����Զ���֪ͨ������                          �յ��Զ���֪ͨ
* ui����                                        �����������߼����ڴ����
*                                               ui����
*
*******************��ʼ����
*******************����*******************      *******************������****************    ***��������***
* ѡ��-����������                                                    
* �����Զ���֪ͨ                                 �յ�ͬ��������Զ���֪ͨ
*                                                ������˻���  
* �յ������߼�������֪ͨ                       ui����                      
* ȫ�ַ����Զ�����Ϣ                                                                          �յ��Զ�����Ϣ
* ui����                                                                                      ui����
*
*******************������Ĺ��ڲ���
* ��֮ǰ�������ȡ�����Ҷ�����Ϣ
* �������У�����й��ڵ�״̬��������
* ��״̬�������ߵĹ��ڽ���ui���� 
*
*******************�Ͽ�����
****************�����Ͽ�
******************����********************       *******************������******************   ***��������***
* �������ߴ�Ӧ�÷����������������ȡ��             
* �����Զ�����Ϣ֪ͨȫ��                          �˳���Ƶ���䣬���л�������״̬
* �յ��������뿪��Ƶ�����֪ͨ                     
* ����ȫ���Զ�����Ϣ                                                                            �յ��Զ�����Ϣ
* ui����                                          ui����                                        ui����
*
****************�����߶Ͽ�
*****************������********************       ********************����********************   ****��������*****
* ��Ӧ�÷��������Լ������������ȡ��
* �˳����˻���                                      �����յ��������뿪��Ƶ�����֪ͨ
* �л�������                                        ����ȫ���Զ�����Ϣ                           �յ��Զ�����Ϣ
* �յ�֪ͨ                                          ui����                                       ui����
* ui����                                            
******************************************** ����˵�� *************************************************************
* ������������˳��������������� 
* ��������Ƶ���ɹ�֮�󣬷���һ���Ͽ������ȫ��֪ͨ
***********************************/

#include "module/emoji/richedit_util.h"
#include "module/emoji/richedit_olecallback.h"
#include "module/video/video_frame_mng.h"
#include "player/player_manager.h"
#include "gui/video/helper/ui_bitmap_control.h"
#include "gui/video/helper/ui_barrage_control.h"
#include "gui/video/screen_capture_tool.h"
#include <time.h>
#include <atlbase.h>
#include <WTypes.h>
#include <shellapi.h>


namespace nim_chatroom
{

	typedef enum NTESLiveMicState
	{
		NTESLiveMicStateWaiting=1,    //���еȴ�
		NTESLiveMicStateConnecting, //������
		NTESLiveMicStateConnected,  //������
	}NTESLiveMicState;

	enum NTESAnchorOperate
	{
		NTESAnchorAgree = 2,
		kNTESAnchorRejectOrDisConnect, //�����ܾ������ǶϿ����Ӳ���
	};

	enum PushMicNotificationType{
		kJoinQueue=1,     //�����������֪ͨ
		kExitQueue=2,     //�˳��������֪ͨ
		kConnectingMIC=3, //����ѡ��ĳ������
		kDisConnectingMIC=4,//�����Ͽ�����֪ͨ
		kRejectConnecting=5 //���ھܾ��������������� ps.������������->�����˳�����->��������->���ڷ���ϵͳ֪ͨ�ܾ���������->�������б���ɾ��
	};

	enum NotifyType{
		kP2P,//��Ե�֪ͨ
		kTeam,//֪ͨ���ڵ�ȫ����
	};

	enum InactionType{
		kUnLive = -1,//δ����ֱ��
		kAudio = 1,//��Ƶ����
		kVedio=2, //��Ƶ����
	};

	enum BypassMemberListOpt{
		kAdd=0, //���ӳ�Ա
		kUpdate=1,//���³�Ա
		kRemove=2,//ɾ����Ա
	};

	enum IdentityType{
		kLimitMember = -1,//�����û�
		kCustomMember=0,//��ͨ
		kCreater=1, //������
		kManager=2, //������
	};

	enum GiftType
	{
		kUnKnown = -1,
		kGiftRose = 0,
		kGiftChocolate,
		kGiftBear,
		kGiftIceCream,
		kGiftRedHeart
	};

	struct BypassMemberInfo{
		NTESLiveMicState state;
		InactionType    type;
		string  nick;
	};

	struct GiftInfo
	{
		ui::Control* pImage;
		ui::Label*	pInfo;
		ui::Label*  pCount;
	};

class ChatroomForm : public nim_comp::WindowEx
{
public:
	ChatroomForm(__int64 room_id);
	~ChatroomForm();

	virtual std::wstring GetSkinFolder() override;
	virtual std::wstring GetSkinFile() override;
	virtual ui::Control* CreateControl(const std::wstring& pstrClass) override;
	virtual ui::UILIB_RESOURCETYPE GetResourceType() const;
	virtual std::wstring GetZIPFileName() const;

	virtual std::wstring GetWindowClassName() const override;
	virtual std::wstring GetWindowId() const override;
	virtual UINT GetClassStyle() const override;
	virtual void OnEsc(BOOL &bHandled) override;

	virtual void InitWindow() override;
	virtual LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam) override;
	virtual void OnFinalMessage(HWND hWnd) override;

	void OnWndSizeMax(bool max);
	virtual bool Notify(ui::EventArgs* msg);
	virtual bool OnClicked(ui::EventArgs* msg);

public:
	void RequestEnter(const __int64 room_id);
	__int64 GetRoomId();
	std::string GetRoomSessionId();
	std::string GetRoomName();
	
	//��ͨ��Ϣ�ص�
	void OnReceiveMsgCallback(const ChatRoomMessage& result);
	void OnEnterCallback(int error_code, const ChatRoomInfo& info, const ChatRoomMemberInfo& my_info);
	void OnGetChatRoomInfoCallback(__int64 room_id, int error_code, const ChatRoomInfo& info);
	void OnNotificationCallback(const ChatRoomNotification& notification);
	void OnGetMembersCallback(__int64 room_id, int error_code, const std::list<ChatRoomMemberInfo>& infos);
	void GetMsgHistoryCallback(__int64 room_id, int error_code, const std::list<ChatRoomMessage>& msgs);
	
	void OnChatRoomRequestEnterCallback(int error_code, const std::string& result);
	void OnRegLinkConditionCallback(__int64 room_id, const NIMChatRoomLinkCondition condition);

	void RequestRoomError();

	//����ֱ��ģʽ����Ƶ 1. ��Ƶ 2.
	void SetLivingModel(InactionType living_model);
	
	void SetAudience(bool audience){ audience_ = audience; }

	//ֱ��

	bool NeedNotifyExt(){ return need_set_notify_ext_;}
	void SetNotifyExt(bool need){ need_set_notify_ext_ = need; }
	void CheckMaster();
	bool OnLiveStreamInit(bool camera);
	void SetRtmpUrl(std::string rtmp_url);
	void PopupMainMenu(POINT point);
	void ChangeCamera(bool open);
	void CloseDriver();

	bool StartLiveStream();
	void PushVideoStream();

	//callback
	void CreateRoomCallback(int code, __int64 channel_id, const std::string& json_extension);
	void JoinRoomCallback(int code, __int64 channel_id, const std::string& json_extension);
	void RoomConnectCallback(int code);
	
	//��Ա�仯�ص�
	void RoomPeopleChangeCallback(std::string uid, bool join_type);


	//���ڽ�֮ǰӦ���Ĳ���������һ�������Ҷ��У������������Ϣ,������ʼ����Ϣ
	void InitChatRoomQueueInfo();
	void UpdateBypassMembersState(string uid, NTESLiveMicState micstate, InactionType type, BypassMemberListOpt opt,string nick);
	void DeleteBypassMembers();
	void AudienceAfterAnchorOpt(NTESAnchorOperate opt);//���ڷ������������˲��������Ӧ���Ĳ���
	void SetChatRoomRoomName(string room_name){ room_name_ = room_name; }

	//����ʱ�������
	void PullPlayError(int code, const std::string& msg);
	
private:
	void PaintVideo();
private:
	void OnUserInfoChange(const std::list<nim::UserNameCard> &uinfos);
	void OnUserPhotoReady(PhotoType type, const std::string& account, const std::wstring& photo_path);
	void OnHttoDownloadReady(HttpResourceType type, const std::string& account, const std::wstring& photo_path);

	void StartLiveStreamRet(bool ret);
	bool OnStartLiveStream(ui::EventArgs* msg);
	bool OnStopLiveStream(ui::EventArgs* msg);

	void StopLiveStream();
	void OnLsErrorCallback(int errCode);

private:
	bool OnEditEnter(ui::EventArgs* param);
	void OnBtnEmoji();
	bool OnSelChanged(ui::EventArgs* param);
	void OnEmotionSelected(std::wstring emo);
	void OnEmotionSelectedSticker(const std::wstring &catalog, const std::wstring &name);
	void OnEmotionClosed();
	bool OnSelOnlineMembers(ui::EventArgs* param);
	bool OnSelBypassMembers(ui::EventArgs* param);

	bool OnLinkClick(WPARAM wParam, LPARAM lParam);

	bool VChatMenuItemClick(ui::EventArgs* args);

	void ShowBypassPrompt();

	//�������������߲˵�
	void ShowBypassOperateMenu(std::wstring &name);
	bool BypassAgreeMenuItemClick(ui::EventArgs* args);
	bool BypassRejectMenuItemClick(ui::EventArgs* args);
	bool OnMemberBypassMenu(ui::EventArgs* args);

private:
	void SetMemberAdmin(const std::string &id, bool is_admin);	//���ó�Ա�б������ĳ����Ա������
	void SetMemberBlacklist(const std::string &id, bool is_black);
	void SetMemberMute(const std::string &id, bool is_mute);
	void SetMemberFixed(const std::string &id, bool is_fixed);
	void RemoveMember(const std::string &uid);
	void UpdateOnlineCount();	// ˢ����������
	void GetMembers();
private:
	void AddMsgItem(const ChatRoomMessage& result, bool is_history);
	void AddNotifyItem(const ChatRoomNotification& notification, bool is_history);
	void OnBtnSend();
	void AddText(const std::wstring &text, const std::wstring &sender_name, bool is_history);
	void AddNotify(const std::wstring &notify, bool is_history);
	void SendText(const std::string &text);
	void OnBtnJsb();
	void AddJsb(const int value, const std::wstring &sender_name, bool is_history);
	void SendJsb(const std::string &attach);

	void ShowWindowSelect(); 
	void SelectWndCb(HWND id, bool cut);
private:
	// �ṩ����ͼƬ��Ϣ������
	void SendImage(const std::wstring &src);
	void OnUploadImageCallback(nim::NIMResCode res_code, const std::string& url, nim::IMImage img);


	//��·ֱ��
	void PopupInteractChoiceMenu(POINT point);
	void PopupCaptureChoiceMenu(POINT point);
	bool OnSingleWndClick(ui::EventArgs* param);
	bool OnWholeWndClick(ui::EventArgs* param);
	bool OnCameraWndClick(ui::EventArgs* param);
	
	//�����߻�������
	bool OnVideoInteractClick(ui::EventArgs* param);
	bool OnAudioInteractClick(ui::EventArgs* param);

	//�������Ҷ����������������
	void RequestPushMicLink(std::string roomid, std::string uid, std::string ext,InactionType type);
	//�������Ҷ�����ȡ����������
	void RequestPopMicLink(std::string roomid, std::string uid);

	//���������ҵ�ַ
	void RequestAddress(std::string roomid, std::string uid);

	//��·ֱ��ʱ��uid����һ��ϵͳ֪ͨ
	void SendSysNotifyMsg(PushMicNotificationType notifytype, string uid);

	//������������
	void SendCustomMsg(NTESAnchorOperate opt,std::string uid, InactionType type);
	
	//��������Ƶ������ȫ����Ϣ
	void SendInitMsg();
	//���Ļ�������״̬
	void SetInteractState(InactionType interactiontype);

	//���¶����е�״̬
	void UpdateChatRoomQueue(string uid, NTESLiveMicState state);

	//���ղ���
	void BeautyOperate();

	//��ѯ������״̬��Ϣ
	void CheckChatroomStatus();
	void UpdateChatroomInfo(bool live);
	void UpdateChatroomInfoWithClose(bool live);

	//����
	void AddGiftInfo(const std::string& id, GiftType type, int nummber);
	void AddGiftNumbers(GiftType type, int number);//������ˢ��

	void OnPullStreamPlayerStateChange(nim_comp::EN_PLAYER_STATE state);
	void SwitchPullStreamAndInteract(bool pull_stream); //����ֱ���л������ͻ���
public:
	static const LPTSTR kClassName;
	static const int kAllowClose = 10;
	static const int kMaxPullRetryTime;

private:
	string          room_name_;
	__int64			room_id_;
	std::string		room_enter_token_;
	bool            need_set_notify_ext_;
	bool            audience_;
	
private:	
	//ui::Control*	header_icon_ = NULL; //������ͷ��
	//ui label
	ui::Label	*name_ = NULL; //����������
	ui::Label	*ls_time_=NULL;
	ui::Label	*lb_gift_1_ = NULL;
	ui::Label	*lb_gift_2_ = NULL;
	ui::Label	*lb_gift_3_ = NULL;
	ui::Label	*lb_gift_4_ = NULL;
	ui::Label	*lb_gift_1_count_ = NULL;
	ui::Label	*lb_gift_2_count_ = NULL;
	ui::Label	*lb_gift_3_count_ = NULL;
	ui::Label	*lb_gift_4_count_ = NULL;

	//ui richedit
	ui::RichEdit	*bulletin_ = NULL;//����	
	ui::RichEdit	*input_edit_ = NULL;
	ui::RichEdit	*msg_list_ = NULL;

	//ui option
	ui::Option	*option_bypass_members_ = NULL;
	ui::Option	*option_bypass_gift_ = NULL;

	//ui tabbox
	ui::TabBox	*list_tab_ = NULL;
	ui::TabBox	*ls_tab_ = NULL;

	//ui checkbox
	ui::CheckBox	*btn_face_ = NULL;

	//ui button
	ui::Button	*btn_send_ = NULL;
	ui::Button	*btn_start_ls_ = NULL;
	ui::Button	*btn_stop_ls_ = NULL;
	ui::Button	*btn_camera_set_ = NULL;
	ui::Button	*btn_mic_set_ = NULL;
	ui::Button	*btn_model_set_ = NULL;
	ui::Button	*btn_interact_set_ = NULL;
	ui::Button  *btn_audiohook_set = NULL;
	
	//ui listbox
	ui::ListBox	*online_members_list_ = NULL;
	ui::ListBox	*bypass_members_list_ = NULL;
	
	//ui control
	ui::Control	*bypass_prompt_ = NULL;
	ui::Control	*empty_members_list_ = NULL;
	ui::Control	*gift_png_1_ = NULL;
	ui::Control	*gift_png_2_ = NULL;
	ui::Control	*gift_png_3_ = NULL;
	ui::Control	*gift_png_4_ = NULL;

	//ui cbitmapcontrol
	ui::CBitmapControl	*video_show_ctrl_ = NULL;
	ui::CBitmapControl	*bypass_show_ctrl_ = NULL;

	//ui vbox
	ui::VBox	*gift_prompt_ = NULL;
	ui::VBox	*gift_info_ = NULL;
	ui::VBox	*gift_box_1_ = NULL;
	ui::VBox	*gift_box_2_ = NULL;
	ui::VBox	*gift_box_3_ = NULL;
	ui::VBox	*gift_box_4_ = NULL;

	IDropTarget	*droptarget_;
	nim_comp::IRichEditOleCallbackEx	*richeditolecallback_;
	HWND   cur_handle_id_;

private:
	//�������
	bool	has_enter_;
	bool	has_add_creater_;	//�Ƿ������߳�Ա������˴�����
	bool	is_loading_history_;
	bool	master_;
	bool	livestreaming_;
	bool	is_audio_interact_;
	bool	is_vedio_interact_;
	bool	is_Camera_;

	std::string	creater_id_;	//��������Ϣ
	std::string	clicked_user_account_;	//�������˵���Ϣ�б��е��ʺ�
	std::string	kicked_user_account_;	//���߳����ʺ�
	std::string	rtmp_url_;
	std::string	bypass_inact_account_; //menu�˵��в������˺�
	std::string	bypassingaccout_;//����������˺�

	std::map<std::string, ChatRoomMemberInfo>	managers_list_;//����Ա��Ϣ <id,info>
	std::map<std::string, ChatRoomMemberInfo>	members_list_;//��Ա��Ϣ <id,info>
	std::map<std::string, std::string>	nick_account_map_;//��¼���ܵ�����Ϣ���ǳƶ�Ӧ���ʺţ�����ͨ���ǳƲ鵽�ʺ�
	std::map < std::string, BypassMemberInfo>	bypassmembers_list_;//��·������Ա��Ϣ
	std::map<GiftType, GiftInfo>	gift_map_;

	time_t	time_refresh_;			//��һ��ˢ�����߳�Ա�б��ʱ��
	AutoUnregister	unregister_cb;


	nim_comp::ScreenCaptureTool	*screen_tool_wnd_;
	nim_comp::VideoFrameMng video_frame_mng_;
	nim_comp::CaptureType cur_capute_;
	nbase::WeakCallbackFlag paint_video_timer_;
	nbase::WeakCallbackFlag push_video_timer_;
	nbase::WeakCallbackFlag check_chatroom_status_timer_;
	std::unique_ptr<nbase::WeakCallback<StdClosure>> pull_stream_stopped_cb_; //����ֱ��ѧ����������ȫֹ֮ͣ��������磺���뻥����
	std::unique_ptr<nbase::WeakCallback<StdClosure>> interact_stopped_cb_; //����ֱ��ѧ���˻�����ȫ����֮��������磺��ʼ������

	int64_t channel_id_;
	int64_t start_time_stamp_;
	int64_t time_count_;
	int64_t	time_start_history;		//��ȡ���������ʷ��Ϣʱ��

	InactionType bypass_inact_type_;
	InactionType living_model_;

	int	gift_rose_count_;
	int	gift_bear_count_;
	int	gift_ice_count_;
	int	gift_cholocate_count_;


	
private: //�������
	bool	is_open_beauty_;//�Ƿ��ѿ�������

private: //�������
	bool	is_pull_normal_;//�����Ƿ�����
	std::wstring	rtmp_pull_url_;//������ַ
	NIMChatRoomLinkCondition chat_room_link_condition_;
	std::string pre_uid_;
};


}