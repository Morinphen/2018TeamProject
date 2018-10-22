//シヨウスルヘッダーファイル
#include"GameL\DrawTexture.h"
#include"GameHead.h"
#include"Deck.h"
#include"GameL\WinInputs.h"
#include"GameL\HitBoxManager.h"
#include"GameL\DrawFont.h"
//使用するネームスペース

//イニシャライズ
void CObjDekc::Init()
{
	x = 650;
	y = 400;
	m_x = 100;
	m_y = 400;
	m_f = true;
	cardcou = 0;
	Start = false;
}

//アクション
void CObjDekc::Action()
{
	if(Start==false){
		for(int i=1;i<6;i++)
		{
			cardcou++;
			CObjCard* obj_b = new CObjCard(m_x * i,m_y);//カード作成
			Objs::InsertObj(obj_b, OBJ_CARD, 10);//作ったカードをオブジェクトマネージャーに登録
		}
		Start = true;
	}

	if (Input::GetVKey('Z') == true)
	{
		if (m_f == true)
		{
			cardcou++;
			//弾丸オブジェクト作成
			CObjCard* obj_b = new CObjCard(300,m_y);//カード作成
			Objs::InsertObj(obj_b, OBJ_CARD, 10);//作ったカードをオブジェクトマネージャーに登録
			m_f = false;
		}

	}

	else {
		m_f = true;
	}
}

//ドロー
void CObjDekc::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 64.0f;
	src.m_bottom = 64.0f;

	dst.m_top = 0.0f + y;
	dst.m_left = 0.0f + x;
	dst.m_right = 128.0f + x;
	dst.m_bottom = 192.0f + y;

	Draw::Draw(0, &src, &dst, c, 0.0f);
}