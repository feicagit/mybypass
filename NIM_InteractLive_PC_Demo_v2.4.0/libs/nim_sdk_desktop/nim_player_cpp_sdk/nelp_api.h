/*
*	Author       biwei
*	Date         2016/10/19
*	Copyright    Hangzhou, Netease Inc.
*	Brief
*   Notice
*/

#ifndef _NELP_API_H_
#define _NELP_API_H_

#include "nelp_type.h"

#ifdef __cplusplus
extern "C" {
#endif

/*! \file */

/**
 * @brief ����������ʵ��
 * @param paLogpath:    ��־�ļ�·��   ���
 * @param phNLPService: ������ʵ��     ����
 *
 * @return NELP_RET: NELP_OK �ɹ�; NELP_ERR ʧ��
 */
EXPORTS_API NELP_RET Nelp_Create(const char *paLogpath, NELP_OUT _HNLPSERVICE *phNLPService);

/**
 * @brief ������ʾ���ھ����������ʾ
 * @param hNLPService:   ������ʵ��    ���
 * @param windowSurface: ��ʾ���ھ��  ���
 *
 * @return ��
 */
EXPORTS_API void     Nelp_SetDisPlay(_HNLPSERVICE hNLPService, void *windowSurface);

/**
 * @brief ��ʼ���������������ŵ�ַ������ģʽ��
 * @param hNLPService: ������ʵ��   ���
 * @param pstParam:    ��ز���     ���
 *
 * @return  NELP_RET: NELP_OK �ɹ�; NELP_ERR ʧ��
 */
EXPORTS_API NELP_RET Nelp_InitParam(_HNLPSERVICE hNLPService, ST_NELP_PARAM *pstParam);

/**
 * @brief Ԥ�������������������������ȣ�������ó�autoPlay����Ԥ������ɺ���Զ�����
 * @param hNLPService: ������ʵ��   ���
 *
 * @return ��
 */
EXPORTS_API void     Nelp_PrepareToPlay(_HNLPSERVICE hNLPService);

/**
 * @brief ��ͣ��ָ�����
 * @param hNLPService: ������ʵ��   ���
 *
 * @return ��
 */
EXPORTS_API void     Nelp_Start(_HNLPSERVICE hNLPService);

/**
 * @brief ��ͣ����
 * @param hNLPService: ������ʵ��   ���
 *
 * @return ��
 */
EXPORTS_API void     Nelp_Pause(_HNLPSERVICE hNLPService);

/**
 * @brief �رղ��������ͷ������Դ
 * @param hNLPService: ������ʵ��   ���
 *
 * @return ��
 */
EXPORTS_API void     Nelp_Shutdown(_HNLPSERVICE hNLPService);

/**
 * @brief ��������
 * @param hNLPService: ������ʵ��   ���
 * @param bIsMute: true ��������; false �����ָ�   ���
 *
 * @return ��
 */
EXPORTS_API void     Nelp_SetMute(_HNLPSERVICE hNLPService, bool bIsMute);

/**
 * @brief ��ȡ��ǰ����λ��
 * @param hNLPService: ������ʵ��   ���
 *
 * @return ��ǰ����λ��(��λ: �� s)   < 0: ��ȡʧ��
 */
EXPORTS_API long     Nelp_GetCurrentPlaybackTime(_HNLPSERVICE hNLPService);

/**
 * @brief ��ȡ�ļ���ʱ�����������ڵ㲥��
 * @param hNLPService: ������ʵ��   ���
 *
 * @return �ļ���ʱ��(��λ: �� s)   < 0: ��ȡʧ��
 */
EXPORTS_API long     Nelp_GetDuration(_HNLPSERVICE hNLPService);

/**
 * @brief ��ȡ��ǰ�ɲ��ŵ�λ�ã����ѻ����λ�ã��������ڵ㲥��
 * @param hNLPService: ������ʵ��   ���
 *
 * @return ��ǰ�ɲ���λ��(��λ: �� s)   < 0: ��ȡʧ��
 */
EXPORTS_API long     Nelp_GetPlayableDuration(_HNLPSERVICE hNLPService);

/**
 * @brief ָ����ĳһʱ��㲥�ţ��������ڵ㲥��
 * @param hNLPService: ������ʵ��              ���
 * @param lTime: ָ���Ĳ���ʱ���(��λ: �� s)   ���
 *
 * @return NELP_RET: NELP_OK  �ɹ�    NELP_ERR  ʧ��
 */
EXPORTS_API NELP_RET Nelp_SeekTo(_HNLPSERVICE hNLPService, long lTime);

/**
 * @brief ��������
 * @param hNLPService: ������ʵ��                                   ���
 * @param fVolume: ������С (��Χ: 0.0 ~ 1.0  0.0:����   1.0:���)   ���
 *
 * @return: NELP_RET: NELP_OK  �ɹ�    NELP_ERR  ʧ��
 */
EXPORTS_API NELP_RET Nelp_SetVolume(_HNLPSERVICE hNLPService, float fVolume);

/**
 * @brief ��ȡSDK�汾��
 * @param ppaVersion: SDK�汾��    ����
 *
 * @return ��
 */
EXPORTS_API void     Nelp_GetSDKVersion(NELP_OUT char **ppaVersion);

/**
 * @brief ע���ȡ��Ϣ�Ļص�, �û���Ҫʵ�ֻص�����cb�����������Ϣ
 * @param hNLPService:  ������ʵ��      ���
 * @param pMessageCB:   ��ȡ��Ϣ�Ļص�  ���

 * @return ��
 */
EXPORTS_API void     Nelp_RegisterMessageCB(_HNLPSERVICE hNLPService, P_NELP_MESSAGE_CB pMessageCB);


/**
 * @brief ע���ȡ��Ƶ֡���ݵĻص����û���Ҫʵ�ֻص�����cb��������Ƶ֡
 * @param hNLPService:   ������ʵ��      ���
 * @param bIsRender:     �Ƿ���ʾ        ���
 * @param eMFormat:      �ص�����Ƶ��ʽ  ���
 * @param pVideFrameCB:  ��ȡ��Ƶ֡�Ļص�    ����
 *
 * @return ��
 */
EXPORTS_API void     Nelp_RegisterGetVideoFrameCB(_HNLPSERVICE hNLPService, bool bIsRender, EN_NELP_MEDIA_FORMAT eMFormat, NELP_OUT P_NELP_VIDEO_FRAME_CB pVideFrameCB);

/**
* @brief ע���ȡ��Դ�ͷŽ�����Ϣ�Ļص�(��Դ�ͷ����첽��), �û���Ҫʵ�ֻص�����cb�����������Ϣ
* @param hNLPService:  ������ʵ��      ���
* @param pReleaseCB:   ��ȡ��Դ�ͷŽ�����Ϣ�Ļص�  ���
*
* @return ��
*/
EXPORTS_API void     Nelp_RegisterResourceReleaseSuccessCB(_HNLPSERVICE hNLPService, P_NELP_RESOURCE_RELEASE_SUCCESS_CB pReleaseCB);

/**
 * @brief ��ȡ��ǰ��������״̬
 * @param hNLPService: ������ʵ��     ���
 *
 * @return EN_NELP_PLAYBACK_STATE: ������״̬   ����	EN_NELP_GET_PLAYBACK_STATE_FAILED ���ʾ��ȡʧ��
 */
EXPORTS_API EN_NELP_PLAYBACK_STATE Nelp_GetPlaybackState(_HNLPSERVICE hNLPService);

/**
* @brief ��ͼ����, ÿ�ν�ͼ�ɹ��󷵻�һ��ͼƬ
* @param hNLPService: ������ʵ��    ���
* @param ePFormat: ͼƬ��ʽ         ���
*
* @return ST_NELP_PICTURE: ��������ͼƬ��ԭʼ���ݺ���Ϣ
*/
EXPORTS_API ST_NELP_PICTURE *Nelp_GetSnapshot(_HNLPSERVICE hNLPService, EN_NELP_PICTURE_FORMAT ePFormat);


#ifdef __cplusplus
}
#endif

#endif
