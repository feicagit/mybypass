
#pragma once

#include "base/synchronization/lock.h"
#include "base/base_types.h"
#include <string>
#include <map>
#include"module/tool/selectiveblur.h"
#include"module/tool/smooth.h"
#include "module/tool/imagebright.h"
namespace nim_comp
{
struct PicRegion //һ����ɫ�����������������ڲ�������
{
	PicRegion()
	{
		pdata_ = NULL;
		//subtype_ = nim::kNIMVideoSubTypeARGB;
		size_max_ = 0;
		size_ = 0;
	}

	~PicRegion()
	{
		Clear();
	}
	void Clear()
	{
		if (pdata_)
		{
			delete[] pdata_;
			pdata_ = NULL;
		}
		size_max_ = 0;
		size_ = 0;
	}
	int ResetData(uint64_t time, const char* data, int size, unsigned int width, unsigned int height/*, nim::NIMVideoSubType subtype*/)
	{
		if (size > size_max_)
		{
			if (pdata_)
			{
				delete[] pdata_;
				pdata_ = NULL;
			}
			pdata_ = new char[size];
			size_max_ = size;
		}
		width_ = width;
		height_ = height;
		timestamp_ = time;
		//subtype_ = subtype;
		size_ = size;
		memcpy(pdata_, data, size);
		return size;
	}
	
	//nim::NIMVideoSubType subtype_;
	char*		pdata_;         //��ɫ�����׵�ַ
	int			size_max_;
	int			size_;
	long        width_;         //���ؿ��
	long        height_;        //���ظ߶�
	uint64_t	timestamp_;     //ʱ��������룩
};
class VideoFrameMng
{
	const int cachecapcity = 120;
public:
	enum FrameType
	{
		Ft_I420 = 0,
		Ft_ARGB,
		Ft_ARGB_r,
	};
	VideoFrameMng();
	~VideoFrameMng();

	void SetBeautyOpt(bool beauty);
	bool GetBeautyOptStatus();
	void Clear();
	void AddVideoFrame(bool capture, int64_t time, const char* data, int size, int width, int height, const std::string& json, FrameType frame_type = Ft_ARGB_r);
	bool GetVideoFrame(std::string account, int64_t& time, char* out_data, int& width, int& height, bool mirror = false, bool argb_or_yuv = true);
	void YUV420ToARGB(char* src, char* dst, int width, int height);
	void ARGBToYUV420(char* src, char* dst, int width, int height);
private:
	nbase::NLock  lock_;
	PicRegion capture_video_pic_;
	std::map<std::string, PicRegion*> recv_video_pic_list_;
	bool beauty_opt_;
	bool canbeauty_;
	std::vector<std::string> cache_video_;
	std::vector <PicRegion*> beauty_video_pic_list_;

	
};
}