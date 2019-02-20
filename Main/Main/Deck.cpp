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

int TurnCount = 0; //現在のターン数を表示するための変数
extern bool PrecedingAttack; //先行は攻撃できないのを参照する変数 true=攻撃可 false=攻撃不可

//使用するネームスペース

//イニシャライズ
void CObjDekc::Init()
{
	//x.yデッキの位置
	x = 1082;
	y = 739;
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

		Data = rand() % 1341 + 10;

		Data = Data - (Data % 10);

		Data++;


		Deck[i] = Data;//同じ番号のカード呼出

	}

	//Cnanber カードの位置調整用
	Cnanber = 0;

	i = 1;

	//Cardcount 現在ドローした枚数　現在プログラム作成中
	Cardcount = 0;

	Deckcount = 40; //デッキの残り枚数

	//Start最初の５枚ドローのための変数
	Start = false;
	Button2 = false;

	effect = false;

	//初期ポイント
	//m_point = 1;
	m_point = 100;
	Cost = 0;
	m_flag_point = false;

	DrawButton_y = 0;
	DrawButton_time = 0;

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
		
		Card = rand() % 39 + 1;//同じ番号のカード呼出
		stop = 1;

		m_l = Input::GetMouButtonL();

		if (Cardcount >= 40)
		{
			Scene::SetScene(new CSceneGameover());
		}

		//別のカードが出るまでループ
		while (stop == 1)
		{
			stop = 0;
			Card = rand() % 39 + 1;

			if (Cardcount >= 39)
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

				if (Turn == true)
				{
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

		else
		{
			m_f = true;
		}

		//スタート処理
		if (Start == false)
		{
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

		//クリック時の処理
		if (m_l == true)
		{
			//ターン開始時　デッキをクリックしてドロー 
			if (mou->m_mouse_x > 1082.0f&&
				mou->m_mouse_x < 1210.0f&&
				mou->m_mouse_y > 739.0f&&
				mou->m_mouse_y < 859.0f&&
				pos->PTrun == false &&
				m_l == true &&
				m_c == true &&
				m_f2 == true &&
				r_f != true)
			{
				Turn = true;
				m_f2 = false;
				Button2 = false;
				TurnCount++;
			}
			//ターン終了ボタン
			else if (mou->m_mouse_x > 12 &&
				mou->m_mouse_x < 275 &&
				mou->m_mouse_y > 391 &&
				mou->m_mouse_y < 510 &&
				pos->PTrun == true &&
				m_f2 == true &&
				m_c == true &&
				r_f != true)
			{
				pos->PTrun = false;
				m_f2 = false;
				m_l = false;
				Button2 = true;
				PrecedingAttack = false;
			}
			else
			{
				m_f2 = true;
			}

			//敗北条件・リタイア
			if (mou->m_mouse_x > 19 &&
				mou->m_mouse_x < 162 &&
				mou->m_mouse_y > 809 &&
				mou->m_mouse_y < 880 &&
				pos->PTrun == true &&
				m_c == true &&
				r_f != true)
			{
				r_f = true; //本当にリタイアするかの確認ウィンドウを表示
			}

			//本当にリタイアするかの確認ウィンドウの処理
			if (r_f == true)
			{
				//「はい」の場合
				if (mou->m_mouse_x > 600 &&
					mou->m_mouse_x < 672 &&
					mou->m_mouse_y > 420 &&
					mou->m_mouse_y < 456 &&
					m_c == true)
				{
					Scene::SetScene(new CSceneGameover());
				}
				//「いいえ」の場合
				else if (mou->m_mouse_x > 900 &&
					mou->m_mouse_x < 972 &&
					mou->m_mouse_y > 420 &&
					mou->m_mouse_y < 456 &&
					m_c == true)
				{
					r_f = false;
				}
			}

			m_c = false; //クリック制御
		}
		else
		{
			m_c = true; //クリック制御
		}
		if (Button2 == true)
		{
			DrawButton_time++;
			if (DrawButton_time < 30)
				DrawButton_y++;
			else if (DrawButton_time < 60)
				DrawButton_y--;
			else
			{
				DrawButton_time = 0;
				DrawButton_y = 0;
			}
		}
		else
		{
			DrawButton_time = 0;
			DrawButton_y = 0;
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

	//swprintf_s(str, L"%d", Cost);
	//Font::StrDraw(str, 10, 10, 20, c);
	Draw::Draw(0, &src, &dst, c, 0.0f);

	//デッキの残り枚数表示
	if (Deckcount - Cardcount >= 10)
	{
		swprintf_s(str, L"%d", Deckcount - Cardcount);
		Font::StrDraw(str, 1105, 780, 50, d);
	}
	else
	{
		swprintf_s(str, L"%d", Deckcount - Cardcount);
		Font::StrDraw(str, 1118, 780, 50, d);
	}

	if (Button2 == true)
	{
		src.m_top = 128.0f;
		src.m_left = 0.0f;
		src.m_right = 64.0f;
		src.m_bottom = 201.0f;

		dst.m_top = 690.0f - DrawButton_y;
		dst.m_left = 1100.0f;
		dst.m_right = 1160.0f;
		dst.m_bottom = 763.0f - DrawButton_y;

		Draw::Draw(3, &src, &dst, c, 0);
	}	
	if (pos->PTrun == true)
	{
		//自ターン中Trun Endの文字を表示
		swprintf_s(str, L"ターンエンド");
		Font::StrDraw(str, 30, 430, 37, d);

		//"降参"の表示
		swprintf_s(str, L"リタイア");
		Font::StrDraw(str, 28, 827, 30, d);

		//現在のターン数の表示
		float a[4] = { 1.0f,1.0f,0.0f,1.0f };
		swprintf_s(str, L"%dターン目", TurnCount);
		Font::StrDraw(str, 200, 827, 30, a);
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

		SetPrio(100);

		Draw::Draw(3, &src, &dst, c, 0);

		swprintf_s(str, L"本当にリタイアしますか？");
		Font::StrDraw(str, 595, 330, 36, c);
		swprintf_s(str, L"はい");
		Font::StrDraw(str, 600, 420, 36, c);
		swprintf_s(str, L"いいえ");
		Font::StrDraw(str, 900, 420, 36, c);
	}
}