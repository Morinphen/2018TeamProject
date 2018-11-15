//使用するヘッダーファイル
#include"GameL\DrawTexture.h"
#include"GameHead.h"
#include"BackGround.h"

//使用するネームスペース
using namespace GameL;

void CObjBackGround::Init()
{
	
}

void CObjBackGround::Action()
{

}

void CObjBackGround::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 1200.0f;
	src.m_bottom = 900.0f;

	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 1200.0f;
	dst.m_bottom = 900.0f;

	Draw::Draw(2, &src, &dst, c, 0);
}