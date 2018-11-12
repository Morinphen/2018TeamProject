//シヨウスルヘッダーファイル
#include"GameL\DrawTexture.h"
#include"GameL\HitBoxManager.h"
#include"GameL\WinInputs.h"
#include"GameHead.h"
#include"Card.h"

#include"Cardlist.h"
#include"Mcardlist.h"

#include"GameL\DrawFont.h"

//使用するネームスペース
CObjCard::CObjCard(float x,float y,int z)
{
	m_x = x;
	m_y = y;
	Type = z;//カードの種類によってタイプを変える
}

//イニシャライズ
void CObjCard::Init()
{
	CObjDekc*sc = (CObjDekc*)Objs::GetObj(OBJ_DEKC);
	CObjHand*han = (CObjHand*)Objs::GetObj(OBJ_HAND);
	Nanber = sc->Cnanber;//引いたカードの順番の固定
	Nanber2 = han->hand[Nanber-1];//カード番号の保存
	Nanber3 = han->basyo[Nanber - 1];//手札の順番変数

	Opdraw = sc->Card;//カード番号の保存
	Updraw = 0;//カードの描画位置の調整
	Rotdraw = 0;//カードの回転描画調整

	Hp = 0;
	Atack = 0;
	Guard = 0;

	Summon = false;

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

	Setcard = sc->Cnanber;//カードの位置調整変更用

	Posicard = Setcard - Nanber;//カードの位置調整変更用２
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

	if (Nanber3 - han->hensu3 > 0 && han->hensu>0)//現在の場所が出したカードよりも後の場合、ひとつずらす
	{
		Nanber--;//番号を１ずらす
		han->hensu2++;
	}

	Nanber3 = han->basyo[Nanber - 1];//手札の場所を更新

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
			if (pos->m_f == false) {
				CObjCardlist* List = new CObjCardlist();//関数呼び出し
				CObjMCardlist* Mlist = new CObjMCardlist();//関数呼び出し２

				Summon = true;
				han->hand[Nanber3 - 1] = 0;//出したカードのカード番号を削除
				han->basyo[Nanber3 - 1] = 0;//出したカードの場所情報を削除
				han->hensu = Setcard - Nanber3;//手札の合計と出したカードの差分を保存
				han->hensu3 = Nanber3;//出したカードの場所を保存
				sc->Cnanber -= 1;//カードの合計枚数を１減らす
				pos->m_f = true;

				if (L_position == false && Type == 2)
				{
					Atack = List->Action(Type, Nanber, Atack);
					m_x = 200;
					m_y = 200;

					pos->L_position = true;

					delete List;
					hit->SetPos(m_x, m_y);
				}
				else if (S_position == false && Type == 1)
				{
					Hp = List->Action(Type, Nanber, Hp);
					Atack = Mlist->Action(Nanber, Atack);

					m_x = 400;
					m_y = 200;

					pos->S_position = true;

					delete List;
					hit->SetPos(m_x, m_y);
				}
				else if (R_position == false && Type == 3)
				{
					Guard = List->Action(Type, Nanber, Guard);
					m_x = 600;
					m_y = 200;

					pos->R_position = true;

					delete List;
					hit->SetPos(m_x, m_y);
				}
				else
				{
					m_x = 0;
					m_y = 0;
					hit->SetPos(m_x, m_y);

					Summon = false;
				}
			}
		}
		else
		{
			pos->m_f = false;
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