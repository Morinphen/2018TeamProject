//使用するヘッダーファイル
#include"GameL\DrawTexture.h"
#include"GameHead.h"
#include"BackGround.h"

//使用するネームスペース
using namespace GameL;

//-------------------------------------------------------------------------------------------------------------------------
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

	//線枠の表示
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
//-------------------------------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------------------------------
void CObjBackGround2::Init()
{

}

void CObjBackGround2::Action()
{
	
}

void CObjBackGround2::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;

	//左のブロック背景表示
	src.m_top = 901.0f;
	src.m_left = 0.0f;
	src.m_right = 382.0f;
	src.m_bottom = 1800.0f;

	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 383.0f;
	dst.m_bottom = 900.0f;

	Draw::Draw(2, &src, &dst, c, 0);
}
//-------------------------------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------------------------------
void CObjBackGround3::Init()
{
	time = 0;
}

void CObjBackGround3::Action()
{
	time++;
	if (time == 64 * 13)
		time = 0;
}

void CObjBackGround3::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;

	//左のブロック背景表示
	src.m_top = 901.0f;
	src.m_left = 0.0f;
	src.m_right = 382.0f;
	src.m_bottom = 1800.0f;

	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 383.0f;
	dst.m_bottom = 900.0f;

	Draw::Draw(2, &src, &dst, c, 0);

	//右のブロック背景表示
	src.m_top = 901.0f;
	src.m_left = 385.0f;
	src.m_right = 448.0f;
	src.m_bottom = 964.0f;

	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; j < 26; j++)
		{
			dst.m_top    = i*64.0f - 15 * 64.0f         + time;
			dst.m_left   = j*64.0f + 385.0f             - time;
			dst.m_right  = j*64.0f + 385.0f     + 64.0f - time;
			dst.m_bottom = i*64.0f - 15 * 64.0f + 64.0f + time;

			Draw::Draw(2, &src, &dst, c, 0);
		}
	}

}