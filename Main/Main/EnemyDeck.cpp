//シヨウスルヘッダーファイル
#include"GameL\DrawTexture.h"
#include"GameHead.h"
#include"EnemyDeck.h"
#include"GameL\WinInputs.h"
#include"GameL\HitBoxManager.h"
#include"GameL\DrawFont.h"
#include<stdlib.h>
#include<time.h>
//使用するネームスペース

//イニシャライズ
void CObjEnemyDeck::Init()
{
	//x.yデッキの位置
	x = 50;
	y = 100;
	//m_x,m_y カードの出現位置調整
	m_x = 500;
	m_y = 230;
	//長押しの防止判定
	m_f = true;

	//stop 同じカードの出現阻止
	stop = 0;

	//Cnanber カードの位置調整用
	Cnanber = 0;

	//Cardcount 現在ドローした枚数　現在プログラム作成中
	e_Cardcount = 0;

	//Start最初の５枚ドローのための変数
	Start = false;

	set = 0;
	Recount = 0;

	srand((unsigned)time(NULL));
}

//アクション
void CObjEnemyDeck::Action()
{
	CObjEnemyHand*sc = (CObjEnemyHand*)Objs::GetObj(OBJ_ENEMY_HAND);
	e_Card = rand() % 14 + 1;//同じ番号のカード呼出
	stop = 1;

	//別のカードが出るまでループ
	while (stop == 1) {
		stop = 0;
		e_Card = rand() % 14 + 1;

		for (int i = 0; i < e_Cardcount; i++)
		{
			if (EnemyDeck[i] == e_Card)
			{
				stop = 1;
			}
		}

	}

	//スタート処理
	if (Start == false) {
		EnemyDeck[e_Cardcount] = e_Card;//デッキにドローしたカードを登録
		sc->hand[Cnanber] = e_Card;//手札にドローしたカードを登録
		sc->basyo[Cnanber] = Cnanber + 1;
		Cnanber++;
		e_Cardcount++;
		CObjEnemyCard* obj_b = new CObjEnemyCard(m_x, m_y);//カード作成
		Objs::InsertObj(obj_b, OBJ_ENEMY_CARD, 10);//作ったカードをオブジェクトマネージャーに登録
	}

	if (e_Cardcount == 5)
	{
		Start = true;
	}

	if (Input::GetVKey('M') == true && Start == true)
	{
		if (m_f == true)
		{
			EnemyDeck[e_Cardcount] = e_Card;//デッキにドローしたカードを登録
			sc->hand[Cnanber] = e_Card;//手札にドローしたカードを登録
			sc->basyo[Cnanber] = Cnanber + 1;
			Cnanber++;
			e_Cardcount++;
			//カード作成
			CObjEnemyCard* obj_b = new CObjEnemyCard(500, m_y);//カード作成
			Objs::InsertObj(obj_b, OBJ_ENEMY_CARD, 10);//作ったカードをオブジェクトマネージャーに登録
			m_f = false;
		}

	}

	else {
		m_f = true;
	}
}

//ドロー
void CObjEnemyDeck::Draw()
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