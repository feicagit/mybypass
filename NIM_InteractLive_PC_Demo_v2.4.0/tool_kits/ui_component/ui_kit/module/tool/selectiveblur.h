 #pragma once
//
//ѡ����ģ���㷨
//
#include<windows.h>
#include<sdkddkver.h>
#include<memory.h>
#include<math.h>
#include<stdlib.h>
#include<emmintrin.h>
namespace nim_comp
{
	const float Inv255 =(float)(1.0 / 255);
	const double Eps = 2.220446049250313E-16;

	enum EdgeMode									//	ĳЩ�����㷨�ı߽紦��ʽ
	{
		kTile = 0,									//	�ظ���Ե����
		kSmear = 1									//	�����Ե����
	};

	enum IS_RET
	{
		IS_RET_OK,									//	����
		IS_RET_ERR_OUTOFMEMORY,						//	�ڴ����
		IS_RET_ERR_STACKOVERFLOW,					//	��ջ���
		IS_RET_ERR_NULLREFERENCE,					//	������
		IS_RET_ERR_ARGUMENTOUTOFRANGE,				//	��������������Χ��
		IS_RET_ERR_PARAMISMATCH,					//	������ƥ��
		IS_RET_ERR_DIVIDEBYZERO,
		IS_RET_ERR_INDEXOUTOFRANGE,
		IS_RET_ERR_NOTSUPPORTED,
		IS_RET_ERR_OVERFLOW,
		IS_RET_ERR_FILENOTFOUND,
		IS_RET_ERR_UNKNOWN
	};

	enum IS_DEPTH
	{
		IS_DEPTH_8U = 0,			//	unsigned char
		IS_DEPTH_8S = 1,			//	char
		IS_DEPTH_16S = 2,			//	short
		IS_DEPTH_32S = 3,			//  int
		IS_DEPTH_32F = 4,			//	float
		IS_DEPTH_64F = 5,			//	double
	};

	struct TMatrix
	{
		int Width;					//	����Ŀ��
		int Height;					//	����ĸ߶�
		int WidthStep;				//	����һ��Ԫ�ص�ռ�õ��ֽ���
		int Channel;				//	����ͨ����
		int Depth;					//	����Ԫ�ص�����
		unsigned char *Data;		//	���������
		int Reserved;				//	����ʹ��
	};

	int IS_ELEMENT_SIZE(int Depth);																//	��ȡԪ�ش�С
	void *IS_AllocMemory(unsigned int Size, bool ZeroMemory = false);							//	�����ڴ棬32�ֽڶ���
	void IS_FreeMemory(void *Ptr);																//	�ͷ��ڴ�
	IS_RET IS_CreateMatrix(int Width, int Height, int Depth, int Channel, TMatrix **Matrix);	//	�������ݾ���
	IS_RET IS_FreeMatrix(TMatrix **Matrix);														//	�ͷ����ݾ���
	IS_RET IS_CloneMatrix(TMatrix *Src, TMatrix **Dest);	//	��¡���ݾ���

#define WIDTHBYTES(bytes) (((bytes * 8) + 31) / 32 * 4)
	unsigned char ClampToByte(int Value);
	void HistgramAddShort(unsigned short *X, unsigned short *Y);
	void HistgramSubShort(unsigned short *X, unsigned short *Y);
	void HistgramSubAddShort(unsigned short *X, unsigned short *Y, unsigned short *Z);
	IS_RET GetValidCoordinate(int Width, int Height, int Left, int Right, int Top, int Bottom, EdgeMode Edge, TMatrix **Row, TMatrix **Col);
	IS_RET SplitRGBA(TMatrix *Src, TMatrix **Blue, TMatrix **Green, TMatrix **Red, TMatrix **Alpha);
	IS_RET CombineRGBA(TMatrix *Dest, TMatrix *Blue, TMatrix *Green, TMatrix *Red, TMatrix *Alpha);
	IS_RET __stdcall SelectiveBlur(TMatrix *Src, TMatrix *Dest, int Radius, int Threshold, EdgeMode Edge);
}