#include"GameL\DrawTexture.h"
#include"GameL\HitBoxManager.h"
#include"GameL\WinInputs.h"
#include"GameHead.h"
#include"PHero.h"
#include"Deck.h"
#include"Cardlist.h"
#include"GameL\Audio.h"

#include"GameL\DrawFont.h"

//使用するネームスペース
CObjPHero::CObjPHero()
{
	m_x = 738;
	m_y = 586;
}

//イニシャライズ
void CObjPHero::Init()
{
	Updraw = 0;//カードの描画位置の調整
	Rotdraw = 0;//カードの回転描画調整

	start = false;

	//ステータスの初期化
	Hp = 20;
	Atack = 1;
	Guard = 0;

	LWeapon = false;
	RWeapon = false;

	test = 1;

	//攻撃処理、装備処理初期化
	Punch = false;

	m_f = false;

	Hits::SetHitBox(this, m_x, m_y, 108, 144, ELEMENT_GREEN, OBJ_FIELD_PLAYER, 1);
}

//アクション
void CObjPHero::Action()
{
	m_l = Input::GetMouButtonL();
	CHitBox*hit = Hits::GetHitBox(this);
	CObjmouse*mou = (CObjmouse*)Objs::GetObj(OBJ_MAUSE);
	CObjMap* pos = (CObjMap*)Objs::GetObj(OBJ_MAP);

	if (start == false)
	{
		start = true;
		pos->PCard[0][0] = Hp;
		pos->PCard[0][1] = Atack;
		pos->PCard[0][2] = Guard;
		pos->PCard[0][3] = 0;
	}

	Hp = pos->PCard[0][0];
	if (Hp <= 0 || Input::GetVKey('Q'))
	{
		Scene::SetScene(new CSceneGameover());
	}

	if (m_l == true)
	{
		if (mou->EChoice == true && Punch == true)
		{
			if (pos->PCard[0][1] - pos->ECard[2] > 0)
				pos->ECard[0] -= pos->PCard[0][1] - pos->ECard[2];//敵のHPを自身の攻撃力-敵の守備分だけダメージを与える

			if (pos->ECard[1] - pos->PCard[0][2] > 0)
				pos->PCard[0][0] -= pos->ECard[1] - pos->PCard[0][2];//敵の攻撃力-自身のHPの分だけダメージを受ける

			//選択情報を元に戻す
			test = 1;
			Punch = false;
			Audio::Start(8);
		}

		else if (mou->EChoice2 == true && Punch == true)
		{
			if (pos->PCard[0][1] - pos->ECard2[2]>0)
				pos->ECard2[0] -= pos->PCard[0][1] - pos->ECard2[2];

			if (pos->ECard2[1] - pos->PCard[0][2]>0)
				pos->PCard[0][0] -= pos->ECard2[1] - pos->PCard[0][2];
			test = 1;
			Punch = false;
			Audio::Start(8);
		}

		else if (mou->EChoice3 == true && Punch == true)
		{

			if (pos->PCard[0][1] - pos->ECard3[2]>0)
				pos->ECard3[0] -= pos->PCard[0][1] - pos->ECard3[2];

			if (pos->ECard3[1] - pos->PCard[0][2]>0)
				pos->PCard[0][0] -= pos->ECard3[1] - pos->PCard[0][2];

			test = 1;
			Punch = false;
			Audio::Start(8);
		}

		else
		{
			test = 1;
			Punch = false;
		}

	}

	if (hit->CheckObjNameHit(OBJ_PLAYER) != nullptr && pos->Wtouch == false)
	{
		//CardHitCheck = true; //"マウスがカードに触れていない"状態にする
		Rotdraw = -3;
		SetPrio(11);
		if (m_l == true && pos->WSummon == false)
		{
			test = 0;
			Punch = true;
		}
	}

	else
	{
		//CardHitCheck = false; //"マウスがカードに触れていない"状態にする
		Rotdraw = 0;
		SetPrio(10);
	}
}

//ドロー
void CObjPHero::Draw()
{

	float c[4] = { 1.0f,test,1.0f,1.0f };
	float d[4] = { 1.0f,0.0f,0.0f,1.0f };
	RECT_F src;
	RECT_F dst;
	CHitBox*hit = Hits::GetHitBox(this);

	src.m_top = 64.0f;
	src.m_left = 0.0f;
	src.m_right = 64.0f;
	src.m_bottom = 128.0f;

	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x;
	dst.m_right = 108.0f + m_x;
	dst.m_bottom = 144.0f + m_y;

	Draw::Draw(0, &src, &dst, c, Rotdraw);

	//画面左上に拡大画像を表示させる

	if (hit->CheckObjNameHit(OBJ_PLAYER) != nullptr)
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
	Font::StrDraw(str, m_x + 10, m_y + 100, 20, d);
}