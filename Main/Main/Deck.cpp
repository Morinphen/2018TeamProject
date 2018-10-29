//シヨウスルヘッダーファイル
#include"GameL\DrawTexture.h"
#include"GameHead.h"
#include"Deck.h"
#include"GameL\WinInputs.h"
#include"GameL\HitBoxManager.h"
#include"GameL\DrawFont.h"
#include<stdlib.h>
#include<time.h>
//使用するネームスペース

//イニシャライズ
void CObjDekc::Init()
{
	x = 900;
	y = 630;
	m_x = 500;
	m_y = 630;
	m_f = true;
	stop = 0;
	cardcou = 0;
	Cardcount = 0;
	Start = false;
	srand((unsigned)time(NULL));
}

//アクション
void CObjDekc::Action()
{
	Card = rand() % 14+1;
	stop = 1;
	while(stop==1){
		stop = 0;
		Card = rand() % 14+1;

		for(int i=0;i<Cardcount;i++)
		{
			if(Deck[i]==Card)
			{
				stop = 1;
			}
		}
	}

	if(Start==false){
		Deck[Cardcount] = Card;
		cardcou++;
		Cardcount++;
		CObjCard* obj_b = new CObjCard(m_x,m_y);//カード作成
		Objs::InsertObj(obj_b, OBJ_CARD, 10);//作ったカードをオブジェクトマネージャーに登録
	}

	if(Cardcount==5)
	{
		Start = true;
	}

	if (Input::GetVKey('Z') == true)
	{
		if (m_f == true)
		{
			Deck[Cardcount] = Card;
			cardcou++;
			Cardcount++;
			//カード作成
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
	//カードの大きさは横３、縦４にする
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 64.0f;
	src.m_bottom = 64.0f;

	dst.m_top = 0.0f + y;
	dst.m_left = 0.0f + x;
	dst.m_right = 90.0f + x;
	dst.m_bottom = 120.0f + y;

	Draw::Draw(0, &src, &dst, c, 0.0f);
}