//シヨウスルヘッダーファイル
#include"GameL\DrawTexture.h"
#include"Card.h"
#include"GameHead.h"
#include"WatchCard.h"
#include"GameL\WinInputs.h"
#include"GameL\HitBoxManager.h"
#include"GameL\DrawFont.h"

#include"Cardlist.h"
#include"Mcardlist.h"

//使用するネームスペース

//イニシャライズ
void CObjWatchCard::Init()
{
	
}

//アクション
void CObjWatchCard::Action()
{
	//CHitBox*hit = Hits::GetHitBox(this);

	/*if (hit->CheckObjNameHit(OBJ_PLAYER) != nullptr)
	{

	}*/
}

//ドロー
void CObjWatchCard::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 64.0f;
	src.m_bottom = 64.0f;

	dst.m_top = 12.0f;
	dst.m_left = 13.0f;
	dst.m_right = 371.0f;
	dst.m_bottom = 491.0f;

	Draw::Draw(0, &src, &dst, c, 0);
}