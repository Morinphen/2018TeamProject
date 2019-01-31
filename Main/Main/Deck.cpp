//シヨウスルヘッダーファイル
#include"GameL\DrawTexture.h"
#include"GameHead.h"
#include"Deck.h"
#include"GameL\WinInputs.h"
#include"GameL\HitBoxManager.h"
#include"GameL\DrawFont.h"
#include"GameL\Audio.h"
#include<stdlib.h>
#include<time.h>

//使用するネームスペース

//イニシャライズ
void CObjDekc::Init()
{
	//x.yデッキの位置
	x = 1086;
	y = 743;
	//m_x,m_y カードの出現位置調整
	//m_x = 567;
	m_y = 743;
	//長押しの防止判定
	m_f = true;
	m_f2 = true;
	//ターン開始時
	Turn = false;

	//ゲーム開始時
	StartG = false;

	//stop 同じカードの出現阻止
	stop = 0;

	srand((unsigned)time(NULL));

	for (int i = 0; i < 40; i++)
	{
		/*if(i<7)
			Deck[i] = 401;
		else if(i<11)
			Deck[i] = 491;
		else if (i<14)
			Deck[i] = 951;
		else if (i<40)
			Deck[i] = 1351;*/

		Data = rand() % 1531 + 10;

		Data = Data - (Data % 10);

		Data++;


		Deck[i] = Data;//同じ番号のカード呼出

	}

	//Cnanber カードの位置調整用
	Cnanber = 0;

	i = 1;

	//Cardcount 現在ドローした枚数　現在プログラム作成中
	Cardcount = 0;

	//Start最初の５枚ドローのための変数
	Start = false;
	Button2 = false;

	effect = false;

	//初期ポイント
	//m_point = 1;
	m_point = 100;
	Cost = 0;
	m_flag_point = false;

}

//アクション
void CObjDekc::Action()
{
	CObjMap* pos = (CObjMap*)Objs::GetObj(OBJ_MAP);
	CObjHand*sc = (CObjHand*)Objs::GetObj(OBJ_HAND);
	CObjCard*car = (CObjCard*)Objs::GetObj(OBJ_CARD);
	CObjmouse*mou = (CObjmouse*)Objs::GetObj(OBJ_MAUSE);

	if (StartG == true)
	{
		
		Card = rand() % 21 + 1;//同じ番号のカード呼出
		stop = 1;

		m_l = Input::GetMouButtonL();

		if (Cardcount >= 22)
		{
			Scene::SetScene(new CSceneGameover());
		}

		//別のカードが出るまでループ
		while (stop == 1) {

			stop = 0;
			Card = rand() % 21 + 1;

			if (Cardcount >= 21)
			{
				break;
			}

			for (int i = 0; i < Cardcount; i++)
			{
				if (Pullc[Card - 1] == Deck[Card - 1])
				{
					stop = 1;
				}
			}

		}

		if (Deck[Card - 1] <= 481)
		{
			Ctype = monster;
		}

		else if (Deck[Card - 1] <= 941)
		{
			Ctype = weapon;
		}

		else if (Deck[Card - 1] <= 1341)
		{
			Ctype = shield;
		}

		else
		{
			Ctype = item;
		}

		/*if (Card <= 7)
		{
			Ctype = monster;
		}

		else if (Card <= 11)
		{
			Ctype = weapon;
		}

		else if (Card <= 14)
		{
			Ctype = shield;
		}

		else
		{
			Ctype = item;
		}*/


		if (Turn == true && Start == true || effect == true)
		{
			if (m_f == true || effect == true)
			{
				Pullc[Card - 1] = Deck[Card - 1];//デッキにドローしたカードを登録
				sc->hand[Cnanber] = Card;//手札にドローしたカードを登録
				sc->basyo[Cnanber] = Cnanber + 1;
				Cnanber++;
				Cardcount++;
				//カード作成
				CObjCard* obj_b = new CObjCard(300, m_y, Ctype);//カード作成
				Objs::InsertObj(obj_b, OBJ_CARD, 10);//作ったカードをオブジェクトマネージャーに登録
				//CObjViewCard* obj_viewcard = new CObjViewCard(Ctype); //画面左上の観賞用カード作成
				//Objs::InsertObj(obj_viewcard, OBJ_VIEWCARD, 1); //作った観賞用カードをオブジェクトマネージャーに登録
				m_f = false;
				effect = false;

				if (Turn == true) {
					//ドローしたらポイント増加
					/*m_point++;
					car->Bat = 1;
					car->Bat2 = 1;*/

					m_point = m_point + i * 100;
					i++;
				}
				Turn = false;
				pos->PTrun = true;
				Audio::Start(2);

			}

		}

		else {
			m_f = true;
		}

		//スタート処理
		if (Start == false) {
			Pullc[Card - 1] = Deck[Card - 1];//デッキにドローしたカードを登録
			sc->hand[Cnanber] = Card;//手札にドローしたカードを登録
			sc->basyo[Cnanber] = Cnanber + 1;
			Cnanber++;
			Cardcount++;
			CObjCard* obj_b = new CObjCard(m_x, m_y, Ctype);//カード作成
			Objs::InsertObj(obj_b, OBJ_CARD, 10);//作ったカードをオブジェクトマネージャーに登録
			//CObjViewCard* obj_viewcard = new CObjViewCard(Ctype); //画面左上の観賞用カード作成
			//Objs::InsertObj(obj_viewcard, OBJ_VIEWCARD, 1); //作った観賞用カードをオブジェクトマネージャーに登録
		}

		if (Cardcount == 4 && Turn == true || Cardcount == 5 && Turn == false)
		{
			Start = true;
		}

		//ターン開始時　デッキをクリックしてドロー 
		if (mou->m_mouse_x > 1105.0f&&
			mou->m_mouse_x<1168.0f&&
			mou->m_mouse_y>700.0f&&
			mou->m_mouse_y < 764.0f&&
			pos->PTrun == false &&
			m_f2 == true &&
			m_l == true)
		{
			Turn = true;
			m_f2 = false;
			Button2 = false;
		}
		else
		{
			m_f2 = true;
		}

		//ターン終了ボタン
		if (m_l == true)
		{
			if (mou->m_mouse_x > 12 &&
				mou->m_mouse_x < 275 &&
				mou->m_mouse_y > 391 &&
				mou->m_mouse_y < 510 &&
				pos->PTrun == true &&
				m_f2 == true &&
				m_f3 == true)
			{
				pos->PTrun = false;
				m_f2 = false;
				m_l = false;
				Button2 = true;
			}
			else
			{
				m_f2 = true;
			}
			m_f3 = false;
		}
		else
		{
			m_f3 = true;
		}
		//敗北条件・リタイア
		if (m_l == true)
		{
			if (mou->m_mouse_x > 19 && mou->m_mouse_x < 162
				&& mou->m_mouse_y > 809 && mou->m_mouse_y < 880
				&& pos->PTrun == true)
			{
				r_f = true;
			}
		}
		if (r_f == true)
		{
			if (m_l == true)
			{
				if (mou->m_mouse_x > 600 && mou->m_mouse_x < 672
					&& mou->m_mouse_y > 420 && mou->m_mouse_y < 456)
				{
					Scene::SetScene(new CSceneGameover());
				}
				else if (mou->m_mouse_x > 900 && mou->m_mouse_x < 972
					&& mou->m_mouse_y > 420 && mou->m_mouse_y < 456)
				{
					r_f = false;
				}
			}
		}
	}
}

//ドロー
void CObjDekc::Draw()
{
	CObjMap* pos = (CObjMap*)Objs::GetObj(OBJ_MAP);

	//カードの大きさは横３、縦４にする
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	float d[4] = { 0.0f,0.0f,0.0f,1.0f };
	RECT_F src;
	RECT_F dst;
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 128.0f;
	src.m_bottom = 128.0f;

	dst.m_top = 0.0f + y;
	dst.m_left = 0.0f + x;
	dst.m_right = 128.0f + x;
	dst.m_bottom = 128.0f + y;

	wchar_t str[128];

	swprintf_s(str, L"%d", Cost);
	Font::StrDraw(str, 10, 10, 20, c);
	Draw::Draw(0, &src, &dst, c, 0.0f);

	if (Button2 == true)
	{
		src.m_top = 128.0f;
		src.m_left = 0.0f;
		src.m_right = 64.0f;
		src.m_bottom = 172.0f;

		dst.m_top = 700.0f;
		dst.m_left = 1104.0f;
		dst.m_right = 1170.0f;
		dst.m_bottom = 764.0f;

		Draw::Draw(3, &src, &dst, c, 0);
	}	
	if (pos->PTrun == true)
	{
		//自ターン中Trun Endの文字を表示
		swprintf_s(str, L"Trun End");
		Font::StrDraw(str, 40, 425, 50, d);

		//"降参"の表示
		swprintf_s(str, L"リタイア");
		Font::StrDraw(str, 28, 827, 30, d);
	}
	if (r_f == true)
	{
		src.m_top = 64.0f;
		src.m_left = 0.0f;
		src.m_right = 189.0f;
		src.m_bottom = 121.0f;

		dst.m_top = 300.0f;
		dst.m_left = 500.0f;
		dst.m_right = 1100.0f;
		dst.m_bottom = 500.0f;

		Draw::Draw(3, &src, &dst, c, 0);

		swprintf_s(str, L"本当にリタイアしますか？");
		Font::StrDraw(str, 595, 330, 36, c);
		swprintf_s(str, L"はい");
		Font::StrDraw(str, 600, 420, 36, c);
		swprintf_s(str, L"いいえ");
		Font::StrDraw(str, 900, 420, 36, c);
	}
}