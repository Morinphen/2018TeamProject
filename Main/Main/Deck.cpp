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
	m_x = 567;
	m_y = 743;
	//長押しの防止判定
	m_f = true;
	m_f2 = true;
	//ターン開始時
	Turn = true;

	//stop 同じカードの出現阻止
	stop = 0;

	//Cnanber カードの位置調整用
	Cnanber = 0;

	//Cardcount 現在ドローした枚数　現在プログラム作成中
	Cardcount = 0;

	//Start最初の５枚ドローのための変数
	Start = false;

	//初期ポイント
	m_point = 1;
	Cost = 0;
	m_flag_point = false;
	srand((unsigned)time(NULL));
}

//アクション
void CObjDekc::Action()
{
	CObjMap* pos = (CObjMap*)Objs::GetObj(OBJ_MAP);
	CObjHand*sc = (CObjHand*)Objs::GetObj(OBJ_HAND);
	Card = rand() % 14+1;//同じ番号のカード呼出
	stop = 1;

	//別のカードが出るまでループ
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

	if (Card <= 7)
	{
		Ctype = monster;
	}

	else if (Card <= 11)
	{
		Ctype = weapon;
	}

	else
	{
		Ctype = shield;
	}


	
	if (Turn==true && Start == true)
	{
		if (m_f == true)
		{
			Deck[Cardcount] = Card;//デッキにドローしたカードを登録
			sc->hand[Cnanber] = Card;//手札にドローしたカードを登録
			sc->basyo[Cnanber] = Cnanber + 1;
			Cnanber++;
			Cardcount++;
			//カード作成
			CObjCard* obj_b = new CObjCard(300,m_y, Ctype);//カード作成
			Objs::InsertObj(obj_b, OBJ_CARD, 10);//作ったカードをオブジェクトマネージャーに登録
			//CObjViewCard* obj_viewcard = new CObjViewCard(Ctype); //画面左上の観賞用カード作成
			//Objs::InsertObj(obj_viewcard, OBJ_VIEWCARD, 1); //作った観賞用カードをオブジェクトマネージャーに登録
			m_f = false;

			Turn = false;
			pos->PTrun = true;
			//ドローしたらポイント増加
			m_point++;
			Audio::Start(1);
		}

	}

	else {
		m_f = true;
	}

//スタート処理
	if(Start==false){
		Deck[Cardcount] = Card;//デッキにドローしたカードを登録
		sc->hand[Cnanber] = Card;//手札にドローしたカードを登録
		sc->basyo[Cnanber] = Cnanber + 1;
		Cnanber++;
		Cardcount++;
		CObjCard* obj_b = new CObjCard(m_x,m_y,Ctype);//カード作成
		Objs::InsertObj(obj_b, OBJ_CARD, 10);//作ったカードをオブジェクトマネージャーに登録
		//CObjViewCard* obj_viewcard = new CObjViewCard(Ctype); //画面左上の観賞用カード作成
		//Objs::InsertObj(obj_viewcard, OBJ_VIEWCARD, 1); //作った観賞用カードをオブジェクトマネージャーに登録
	}

	if(Cardcount==4)
	{
		Start = true;
	}

	if(Input::GetVKey('Z')&&pos->PTrun==false&&m_f2==true)
	{
		Turn = true;
		m_f2 = false;
	}
	else
	{
		m_f2 = true;
	}

	if (Input::GetVKey('E')&&m_f2==true)
	{
		pos->PTrun = false;
		m_f2 = false;
	}
	else
	{
		m_f2 = true;
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

	wchar_t str[128];

	swprintf_s(str, L"%d", Cost);

	Font::StrDraw(str, 10, 10, 20, c);

	Draw::Draw(0, &src, &dst, c, 0.0f);

}