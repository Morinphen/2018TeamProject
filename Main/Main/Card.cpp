//シヨウスルヘッダーファイル
#include"GameL\DrawTexture.h"
#include"GameL\HitBoxManager.h"
#include"GameHead.h"
#include"Card.h"

#include"GameL\DrawFont.h"

//使用するネームスペース
CObjCard::CObjCard(float x,float y)
{
	m_x = x;
	m_y = y;
}

//イニシャライズ
void CObjCard::Init()
{
	CObjDekc*sc = (CObjDekc*)Objs::GetObj(OBJ_DEKC);
	Nanber = sc->Cnanber;//bango 引いたカードの順番の固定

	Opdraw = sc->Card;//test カード番号の保存
	Updraw = 0;//taka カードの描画位置の調整
	Rotdraw = 0;//test2 カードの回転描画調整

	while(Opdraw>7)
	{
		Opdraw -= 7;
		Updraw++;
	}

	Hits::SetHitBox(this, m_x, m_y, 90, 120, ELEMENT_CARD, OBJ_CARD, 1);
}

//アクション
void CObjCard::Action()
{
	CHitBox*hit = Hits::GetHitBox(this);

	CObjDekc*sc = (CObjDekc*)Objs::GetObj(OBJ_DEKC);

	Setcard = sc->Cnanber;//basyo カードの位置調整変更用

	Posicard = Setcard - Nanber;//genba カードの位置調整変更用２

	if(Setcard <=5)
	{
		m_x = 250+(90* Posicard);
	}

	else{

		m_x = 250 + ((450 / (Setcard))*Posicard);

	}

	if (hit->CheckObjNameHit(OBJ_PLAYER) != nullptr)
	{
		Rotdraw = 3;//カードを３℃回転
		SetPrio(11);//カードの描画優先度変更
	}
	else
	{
		Rotdraw = 0;
		SetPrio(10);
	}

	hit->SetPos(m_x, m_y);
}

//ドロー
void CObjCard::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;
	src.m_top = 0.0f+ (64.0f*Updraw);
	src.m_left = 0.0f + (64.0f*Opdraw);
	src.m_right = 64.0f + (64.0f*Opdraw);
	src.m_bottom = 64.0f+ (64.0f*Updraw);

	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x;
	dst.m_right = 90.0f + m_x;
	dst.m_bottom = 120.0f + m_y;

	Draw::Draw(0, &src, &dst, c, Rotdraw);
}