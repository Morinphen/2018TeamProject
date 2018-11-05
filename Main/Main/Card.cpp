//シヨウスルヘッダーファイル
#include"GameL\DrawTexture.h"
#include"GameL\HitBoxManager.h"
#include"GameL\WinInputs.h"
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
	CObjHand*han = (CObjHand*)Objs::GetObj(OBJ_HAND);
	Nanber = sc->Cnanber;//bango 引いたカードの順番の固定
	Nanber2 = han->hand[Nanber-1];
	Nanber3 = Nanber;

	Opdraw = sc->Card;//test カード番号の保存
	Updraw = 0;//taka カードの描画位置の調整
	Rotdraw = 0;//test2 カードの回転描画調整

	Summon = false;
	Shand = 0;

	while(Opdraw>7)
	{
		Opdraw -= 7;//x位置をずらす
		Updraw++;
	}
	m_f = false;

	Hits::SetHitBox(this, m_x, m_y, 90, 120, ELEMENT_CARD, OBJ_CARD, 1);
}

//アクション
void CObjCard::Action()
{
	CObjmouse*mou = (CObjmouse*)Objs::GetObj(OBJ_MAUSE);
	CObjHand*han = (CObjHand*)Objs::GetObj(OBJ_HAND);
	CObjDekc*sc = (CObjDekc*)Objs::GetObj(OBJ_DEKC);

	CHitBox*hit = Hits::GetHitBox(this);

	Setcard = sc->Cnanber;//Setcard カードの位置調整変更用

	Posicard = Setcard - Nanber;//Posicard カードの位置調整変更用２

	/*if (Nanber - Reset > 0 && Reset != 0 && Reset > 0)
	{
		Reflag = true;
		han->hensu -= 1;
	}

	if (Reflag == true)
	{
		Nanber3 = Nanber3;
		Nanber--;
		Reflag = false;
	}*/

	if (Nanber - han->hensu > 0)
	{
		Nanber2 = han->basyo[Nanber - Shand];
	}

	CObjMap* pos = (CObjMap*)Objs::GetObj(OBJ_MAP);
	L_position = pos->L_position;
	S_position = pos->S_position;
	R_position = pos->R_position;
	
	if(Setcard <=5 && Summon == false)
	{
		//m_x = 250+(90* Posicard);
		for (int i = 0; i < Setcard; i++)
		{
			if (han->hand[i] == Nanber2)
			{
				m_x = 250 + (90 * i);
			}
		}
	}

	else if(Summon == false){
		for (int i = 0; i < Setcard; i++)
		{
			if (han->hand[i] == Nanber2)
			{
				m_x = 250 + ((450 / (Setcard))*Posicard);
			}
		}
	}

	if (hit->CheckObjNameHit(OBJ_PLAYER) != nullptr && Summon == false)
	{
		Rotdraw = 3;//カードを３℃回転
		SetPrio(11);//カードの描画優先度変更
		if (mou->m_r == true)
		{
			Summon = true;

			if (L_position == false && S_position == false && R_position == false)
			{
				m_x = 200;
				m_y = 200;

				pos->L_position = true;

				hit->SetPos(m_x, m_y);
			}
			else if (L_position == true && S_position == false && R_position == false)
			{
				m_x = 400;
				m_y = 200;

				pos->S_position = true;

				hit->SetPos(m_x, m_y);
			}
			else if (L_position == true && S_position == true && R_position == false)
			{
				m_x = 600;
				m_y = 200;

				pos->R_position = true;

				hit->SetPos(m_x, m_y);
			}
			else
			{
				hit->SetPos(m_x, m_y);

				Summon = false;
			}
		}
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