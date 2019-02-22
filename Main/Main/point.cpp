#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\DrawFont.h"
#include"GameL\HitBoxManager.h"


#include "GameHead.h"
#include "Deck.h"

//使用するネームスペース
using namespace GameL;

//デストラクタ
CObjpoint::CObjpoint()
{

};

CObjpoint::~CObjpoint()
{

};

//イニシャライズ
void CObjpoint::Init()
{
	m_point = 0;
	p_point = 0;
	m_flag_point = false;
	m_p=true;
	Cost = 100;
	PreviousCost = 0;
	e_Cost = 0;
	AddCost = 0;
	time = 0;
};

//アクション
void CObjpoint::Action()
{
	CObjDekc*sc = (CObjDekc*)Objs::GetObj(OBJ_DEKC);
	CObjEnemyDeck*esc = (CObjEnemyDeck*)Objs::GetObj(OBJ_ENEMY_DECK);
	if (sc->Turn == true)
		Cost = sc->p_point;
	if (esc->EDraw == false)
		e_Cost = esc->e_point;

	AddCost = sc->i - 1;
	PreviousCost = sc->p_point;
	if (sc->AddCostDisplay == true && AddCost > 0)
	{
		time++;
		if (time > 180)
		{
			sc->AddCostDisplay = false;
			time = 0;
		}
	}
};

//ドロー
void CObjpoint::Draw()
{
	CObjDekc*sc = (CObjDekc*)Objs::GetObj(OBJ_DEKC);
	CObjEnemyDeck*esc = (CObjEnemyDeck*)Objs::GetObj(OBJ_ENEMY_DECK);
	CObjMap* pos = (CObjMap*)Objs::GetObj(OBJ_MAP);

	float clear = 1.0 - time / 100.0;
	float c[4] = { 0.0f,0.0f,0.0f,1.0f };
	float d[4] = { 0.0f,0.0f,0.0f,1.0f };
	float e[4] = { 1.0f,1.0f,1.0f,clear };
	float f[4] = { 0.0f,0.0f,0.0f,clear };
	wchar_t str[128];
	RECT_F src;
	RECT_F dst;

	//所持しているマナ(ゴールド？)を表示
	if (time == 0)
	{
		if (sc->p_point >= 10000)
		{
			swprintf_s(str, L"%d", sc->p_point);
			Font::StrDraw(str, 315, 425, 55, c);
		}
		else if (sc->p_point >= 1000)
		{
			swprintf_s(str, L"%d", sc->p_point);
			Font::StrDraw(str, 325, 420, 60, c);
		}
		else if (sc->p_point >= 100)
		{
			swprintf_s(str, L"%d", sc->p_point);
			Font::StrDraw(str, 340, 420, 60, c);
		}
		else
		{
			swprintf_s(str, L"%d", sc->p_point);
			Font::StrDraw(str, 370, 420, 60, c);
		}
	}
	//追加ゴールドの画像表示
	else
	{
		src.m_top = 202.0f;
		src.m_left = 0.0f;
		src.m_right = 179.0f;
		src.m_bottom = 381.0f;

		dst.m_top = 180.0f + time;
		dst.m_left = 294.0f;
		dst.m_right = 473.0f;
		dst.m_bottom = 360.0f + time;

		Draw::Draw(3, &src, &dst, e, 0);

		if (AddCost * 100 >= 1000)
		{
			swprintf_s(str, L"%d", 100 * AddCost);
			Font::StrDraw(str, 325, 240 + time, 60, f);
		}
		else
		{
			swprintf_s(str, L"%d", 100 * AddCost);
			Font::StrDraw(str, 340, 240 + time, 60, f);
		}
		
		if (Cost >= 10000)
		{
			swprintf_s(str, L"%d", PreviousCost);
			Font::StrDraw(str, 315, 425, 55, c);
		}
		else if (Cost >= 1000)
		{
			swprintf_s(str, L"%d", PreviousCost);
			Font::StrDraw(str, 325, 420, 60, c);
		}
		else if (Cost >= 100)
		{
			swprintf_s(str, L"%d", PreviousCost);
			Font::StrDraw(str, 340, 420, 60, c);
		}
		else
		{
			swprintf_s(str, L"%d", PreviousCost);
			Font::StrDraw(str, 370, 420, 60, c);
		}
	}
	//敵の所持しているマナ(ゴールド？)を表示
	if (e_Cost >= 10000)
	{
		swprintf_s(str, L"%d", esc->e_point);
		Font::StrDraw(str, 1082, 58, 35, c);
	}
	else if (e_Cost >= 1000)
	{
		swprintf_s(str, L"%d", esc->e_point);
		Font::StrDraw(str, 1085, 55, 40, c);
	}
	else if (e_Cost >= 100)
	{
		swprintf_s(str, L"%d", esc->e_point);
		Font::StrDraw(str, 1095, 55, 40, c);
	}
	else
	{
		swprintf_s(str, L"%d", esc->e_point);
		Font::StrDraw(str, 1116, 56, 40, c);
	}
}