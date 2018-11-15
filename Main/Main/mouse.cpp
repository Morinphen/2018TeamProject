//使用するヘッダーファイル
#include"GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\HitBoxManager.h"
#include"GameL\DrawTexture.h"
#include"GameHead.h"
#include"mouse.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjmouse::Init()
{
	m_r = false;
	m_f = false;

	EChoice = false;

	m_mouse_x = 0.0f;//マウスのX座標
	m_mouse_y = 0.0f;//マウスのY座標

	//当たり判定作成
	Hits::SetHitBox(this, m_mouse_x, m_mouse_y, 2, 2, ELEMENT_PLAYER, OBJ_PLAYER, 1);
}

//アクション
void CObjmouse::Action()
{
	m_r = Input::GetMouButtonR();

	//マウス座標取得
	m_mouse_x =(float) Input::GetPosX();
	m_mouse_y =(float) Input::GetPosY();

	//当たり判定更新
	CHitBox*hit = Hits::GetHitBox(this);
	if (hit->CheckObjNameHit(OBJ_FIELD_ENEMY) != nullptr)
	{
		EChoice = true;
	}

	else
	{
		EChoice = false;
	}

	hit->SetPos(m_mouse_x, m_mouse_y);
}

//ドロー
void CObjmouse::Draw()
{
	//色
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	//----------------------------------------------------
	//マウス座標の値描画(テスト用なのでのちに消す可能性)
	wchar_t str[128];
	swprintf_s(str, L"x:%f", m_mouse_x);
	Font::StrDraw(str,100,100,20,c);

	swprintf_s(str, L"y:%f", m_mouse_y);
	Font::StrDraw(str, 100, 120, 20, c);

	//----------------------------------------------------


	//----------------------------------------------------
	//ポインタ描画
	//カードの大きさは横３、縦４にする
	RECT_F src;
	RECT_F dst;
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 64.0f;
	src.m_bottom = 64.0f;

	dst.m_top = 0.0f + m_mouse_y;
	dst.m_left = 0.0f + m_mouse_x;
	dst.m_right = dst.m_left + 32.0f;
	dst.m_bottom = dst.m_top + 32.0f;

	Draw::Draw(0, &src, &dst, c, 0.0f);
}