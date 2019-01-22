#include"GameL\DrawTexture.h"
#include"GameL\HitBoxManager.h"
#include"GameL\WinInputs.h"
#include"GameHead.h"
#include"EHero.h"
#include"Deck.h"
#include"Cardlist.h"

#include"GameL\DrawFont.h"

//使用するネームスペース
CObjEHero::CObjEHero()
{
	m_x = 738;
	m_y = 166;
}

//イニシャライズ
void CObjEHero::Init()
{
	Updraw = 0;//カードの描画位置の調整
	Rotdraw = 180;//カードの回転描画調整

	start = false;

	//ステータスの初期化
	Hp = 20;
	Atack = 2;
	Guard = 0;

	LWeapon = false;
	RWeapon = false;

	test = 1;

	//攻撃処理、装備処理初期化
	Punch = false;

	m_f = false;

	Hits::SetHitBox(this, m_x, m_y, 108, 144, ELEMENT_ITEM, OBJ_FIELD_ENEMY, 1);
}

//アクション
void CObjEHero::Action()
{
	CHitBox*hit = Hits::GetHitBox(this);
	CObjmouse*mou = (CObjmouse*)Objs::GetObj(OBJ_MAUSE);
	CObjMap* pos = (CObjMap*)Objs::GetObj(OBJ_MAP);

	if (start == false)
	{
		start = true;
		pos->ECard[0] = Hp;
		pos->ECard[1] = Atack;
		pos->ECard[2] = Guard;
		pos->ECard[3] = 0;
	}

	Hp = pos->ECard[0];
	if (Hp <= 0)
	{
		Scene::SetScene(new CSceneClear());
	}

	if (hit->CheckObjNameHit(OBJ_PLAYER) != nullptr)
	{
		CardHitCheck = true; //"マウスがカードに触れている"状態にする
	}
	else
	{
		CardHitCheck = false; //"マウスがカードに触れていない"状態にする
	}

}

//ドロー
void CObjEHero::Draw()
{

	float c[4] = { 1.0f,test,1.0f,1.0f };
	float d[4] = { 1.0f,0.0f,0.0f,1.0f };
	RECT_F src;
	RECT_F dst;
	CHitBox*hit = Hits::GetHitBox(this);

	src.m_top = 192.0f;
	src.m_left = 0.0f;
	src.m_right = 64.0f;
	src.m_bottom = 256.0f;

	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x;
	dst.m_right = 108.0f + m_x;
	dst.m_bottom = 144.0f + m_y;

	Draw::Draw(0, &src, &dst, c, Rotdraw);

	//画面左上に拡大画像を表示させる

	if (CardHitCheck == true)
	{
		dst.m_top = 12.0f;
		dst.m_left = 12.0f;
		dst.m_right = 281.0f;
		dst.m_bottom = 371.0f;

		Draw::Draw(0, &src, &dst, c, 0);
	}
	/*else
	{

		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 64.0f;
		src.m_bottom = 64.0f;

		dst.m_top = 12.0f;
		dst.m_left = 13.0f;
		dst.m_right = 371.0f;
		dst.m_bottom = 491.0f;

		Draw::Draw(0, &src, &dst, c, 0);
	}*/

	wchar_t str[128];
	swprintf_s(str, L"%d　%d　%d", Atack, Hp, Guard);
	Font::StrDraw(str, m_x + 15, m_y + 120, 20, d);
}