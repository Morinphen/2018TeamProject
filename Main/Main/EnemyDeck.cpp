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
	x = 408;
	y = 38;
	//m_x,m_y カードの出現位置調整
	m_x = 927;
	m_y = 38;
	//長押しの防止判定
	m_f = true;

	//stop 同じカードの出現阻止
	stop = 0;

	//カードの回転描画調整
	Rotdraw = 0;

	for (int i = 0; i < 40; i++)
	{
		Data = rand() % 1341 + 10;

		Data = Data - (Data % 10);

		Data++;


		EnemyDeck[i] = Data;//同じ番号のカード呼出
	}

	//Cnanber カードの位置調整用
	Cnanber = 0;

	//Cardcount 現在ドローした枚数　現在プログラム作成中
	e_Cardcount = 0;

	e_Deckcount = 40; //デッキの残り枚数

	//Start最初の５枚ドローのための変数
	Start = false;

	//初期ポイント
	e_point = 100;
	e_Cost = 0;

	i = 1;

	set = 0;
	Recount = 0;

	srand((unsigned)time(NULL));
}

//アクション
void CObjEnemyDeck::Action()
{
	Rotdraw = 180;//カードを180℃回転
	CObjEnemyHand*sc = (CObjEnemyHand*)Objs::GetObj(OBJ_ENEMY_HAND);
	e_Card = rand() % 14 + 1;//同じ番号のカード呼出
	stop = 1;

	if (StartG == true)
	{

		e_Card = rand() % 39 + 1;//同じ番号のカード呼出
		stop = 1;

		//別のカードが出るまでループ
		while (stop == 1)
		{
			stop = 0;
			e_Card = rand() % 39 + 1;

			if (e_Cardcount >= 39)
			{
				break;
			}

			for (int i = 0; i < e_Cardcount; i++)
			{
				if (EnemyDeck[i] == e_Card)
				{
					stop = 1;
				}
			}
		}
		if (EnemyDeck[e_Card - 1] <= 481)
		{
			Ctype = monster;
		}

		else if (EnemyDeck[e_Card - 1] <= 941)
		{
			Ctype = weapon;
		}

		else if (EnemyDeck[e_Card - 1] <= 1341)
		{
			Ctype = shield;
		}

		else
		{
			Ctype = item;
		}
	}

	//スタート処理
	if (Start == false)
	{
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

	if (Input::GetVKey('X') == true && Start == true)
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
			//ドローしたらポイント増加
			e_point = e_point + i * 100;
			i++;
		}
	}
	else
	{
		m_f = true;
	}

	if (e_Cardcount >= 40)
	{
		Scene::SetScene(new CSceneClear());
	}
}

//ドロー
void CObjEnemyDeck::Draw()
{
	//カードの大きさは横３、縦４にする
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	float d[4] = { 0.0f,0.0f,0.0f,1.0f };
	RECT_F src;
	RECT_F dst;

	wchar_t str[128];

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 128.0f;
	src.m_bottom = 128.0f;

	dst.m_top = 128.0f + y;
	dst.m_left = 128.0f + x - 36;
	dst.m_right = 0.0f + x - 36;
	dst.m_bottom = 0.0f + y;
	
	Draw::Draw(0, &src, &dst, c, 0.0f);

	//デッキの残り枚数表示
	if (e_Deckcount - e_Cardcount >= 10)
	{
		swprintf_s(str, L"%d", e_Deckcount - e_Cardcount);
		Font::StrDraw(str, 428, 70, 50, d);
	}
	else
	{
		swprintf_s(str, L"%d", e_Deckcount - e_Cardcount);
		Font::StrDraw(str, 441, 70, 50, d);
	}
}