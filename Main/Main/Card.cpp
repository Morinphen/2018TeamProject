//シヨウスルヘッダーファイル
#include"GameL\DrawTexture.h"
#include"GameL\HitBoxManager.h"
#include"GameHead.h"
#include"Card.h"

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
	bango = sc->cardcou;
	test = sc->Card;
	taka = 0;
	test2 = 0;
	while(test>7)
	{
		test -= 7;
		taka++;
	}
	Hits::SetHitBox(this, m_x, m_y, 90, 120, ELEMENT_CARD, OBJ_CARD, 1);
}

//アクション
void CObjCard::Action()
{
	CHitBox*hit = Hits::GetHitBox(this);

	CObjDekc*sc = (CObjDekc*)Objs::GetObj(OBJ_DEKC);
	basyo = sc->cardcou;

	genba = basyo - bango;

	if(basyo<=5)
	{
		m_x = 100+(90*genba);
	}

	else{

		m_x = 100 + ((450 / (basyo))*genba);

		/*else if (bango == 1) {
			m_x = 100;
		}

		else{
			m_x = 550;
		}*/
	}

	/*if (genba == 0) {

		if (bango == 1) {
			;
		}
		else {
			m_x = 550;
		}
	}
	else {
		m_x = 550 - (genba * 90);
	}*/

	if (hit->CheckObjNameHit(OBJ_PLAYER) != nullptr)
	{
		test2 = 3;
		SetPrio(11);
	}
	else
	{
		test2 = 0;
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
	src.m_top = 0.0f+ (64.0f*taka);
	src.m_left = 0.0f + (64.0f*test);
	src.m_right = 64.0f + (64.0f*test);
	src.m_bottom = 64.0f+ (64.0f*taka);

	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x;
	dst.m_right = 90.0f + m_x;
	dst.m_bottom = 120.0f + m_y;

	Draw::Draw(0, &src, &dst, c, test2);
}