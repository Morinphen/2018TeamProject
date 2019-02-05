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
	m_y = 590;
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
	Pusave = false;

	//ボタン用変数の初期化
	BDraw = 1;
	Button = false;
	b_x = 0;
	b_y = 0;

	LWeapon = false;
	RWeapon = false;

	Deadt = 90;
	inviD = 1.0f;

	test = 1;

	Bat3 = 1;

	//攻撃処理、装備処理初期化
	Punch = false;

	m_f = false;

	//リタイアフラグ
	r_f = false;

	Hits::SetHitBox(this, m_x, m_y, 108, 144, ELEMENT_GREEN, OBJ_FIELD_PLAYER, 1);
}

//アクション
void CObjPHero::Action()
{
	m_l = Input::GetMouButtonL();
	CHitBox*hit = Hits::GetHitBox(this);
	CObjmouse*mou = (CObjmouse*)Objs::GetObj(OBJ_MAUSE);
	CObjMap* pos = (CObjMap*)Objs::GetObj(OBJ_MAP);
	CObjDekc*sc = (CObjDekc*)Objs::GetObj(OBJ_DEKC);



	if (sc->Turn == true)
	{
		Pusave = false;
	}

	if (start == false)
	{
		start = true;
		pos->PCard[0][0] = Hp;
		pos->PCard[0][1] = Atack;
		pos->PCard[0][2] = Guard;
		pos->PCard[0][3] = 0;
	}

	Hp=pos->PCard[0][0];
	Atack=pos->PCard[0][1];
	Guard=pos->PCard[0][2];

	//敗北条件・リタイア
	/*if (m_l == true)
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
	}*/

	if (Hp == 0)
	{
		Deadt--;
		inviD = Deadt / 90;
		if (Deadt == 0)
		{
			Scene::SetScene(new CSceneGameover());
		}
	}

	if (m_l == true)
	{
		if (mou->EChoice == true && Punch == true&&Bat3==1)
		{

			//武器を所持していた場合、耐久度減少
			if (pos->PCard[0][4] > 0)
			{
				pos->PCard[0][4] -= 1;
			}

			//２つ目の武器を所持していた場合、耐久度減少
			if (pos->PCard[0][6] > 0)
			{
				pos->PCard[0][6] -= 1;
			}

			if (pos->PCard[0][1] - pos->ECard[2] > 0)
				pos->ECard[0] -= pos->PCard[0][1] - pos->ECard[2];//敵のHPを自身の攻撃力-敵の守備分だけダメージを与える

			if (pos->ECard[1] - pos->PCard[0][2] > 0)
				pos->PCard[0][0] -= pos->ECard[1] - pos->PCard[0][2];//敵の攻撃力-自身のHPの分だけダメージを受ける

			//選択情報を元に戻す
			test = 1;
			Punch = false;
			Pusave = true;
			Audio::Start(8);
			Bat3 = 0;
		}

		else if (mou->EChoice2 == true && Punch == true && Bat3 == 1)
		{
			//武器を所持していた場合、耐久度減少
			if (pos->PCard[0][4] > 0)
			{
				pos->PCard[0][4] -= 1;
			}

			//２つ目の武器を所持していた場合、耐久度減少
			if (pos->PCard[0][6] > 0)
			{
				pos->PCard[0][6] -= 1;
			}

			if (pos->PCard[0][1] - pos->ECard2[2]>0)
				pos->ECard2[0] -= pos->PCard[0][1] - pos->ECard2[2];

			if (pos->ECard2[1] - pos->PCard[0][2]>0)
				pos->PCard[0][0] -= pos->ECard2[1] - pos->PCard[0][2];
			test = 1;
			Punch = false;
			Pusave = true;
			Audio::Start(8);
			Bat3 = 0;

		}

		else if (mou->EChoice3 == true && Punch == true && Bat3 == 1)
		{
			//武器を所持していた場合、耐久度減少
			if (pos->PCard[0][4] > 0)
			{
				pos->PCard[0][4] -= 1;
			}

			//２つ目の武器を所持していた場合、耐久度減少
			if (pos->PCard[0][6] > 0)
			{
				pos->PCard[0][6] -= 1;
			}

			if (pos->PCard[0][1] - pos->ECard3[2]>0)
				pos->ECard3[0] -= pos->PCard[0][1] - pos->ECard3[2];

			if (pos->ECard3[1] - pos->PCard[0][2]>0)
				pos->PCard[0][0] -= pos->ECard3[1] - pos->PCard[0][2];

			test = 1;
			Punch = false;
			Pusave = true;
			Audio::Start(8);
			Bat3 = 0;

		}

		else if (mou->Flee==true)
		{
			test = 1;
			Punch = false;
		}

	}

	if (test == 0)
		Button = false;

	if (Button == true)
	{
		SetPrio(12);
		if (m_f == false) {
			if (m_l == true)
			{
				//ボタンがクリックされたとき
				if (mou->m_mouse_x > b_x && mou->m_mouse_x < b_x + 64
					&& mou->m_mouse_y > b_y + 16 && mou->m_mouse_y < b_y + 48)
				{

					Button = false;
					m_f = true;

					test = 0;
					Punch = true;

					m_l = false;

				}

				else
				{
					Button = false;
				}

			}
		}
		else
		{
			m_f = false;
		}
	}

	if (hit->CheckObjNameHit(OBJ_PLAYER) != nullptr && pos->Wtouch == false)
	{
		Rotdraw = -3;
		SetPrio(11);
		if (m_l == true && pos->WSummon == false && test!=0 && Pusave==false
			&& pos->PTrun == true)
		{
			Button = true;
		}
	}

	else
	{
		//CardHitCheck = false; //"マウスがカードに触れていない"状態にする
		Rotdraw = 0;
		SetPrio(10);
	}

	if (sc->Turn == true)
	{
		Bat3 = 1;
	}
}

//ドロー
void CObjPHero::Draw()
{

	float c[4] = { 1.0f,test,1.0f,inviD };
	float e[4] = { 1.0f,1.0f,1.0f,1.0f };

	//HP
	float h[4] = { 0.0f,1.0f,0.0f,1.0f };
	float h2[4] = { 0.7f,1.0f,0.0f,1.0f };

	//Atack
	float a[4] = { 1.0f,0.5f,0.7f,1.0f };
	float a2[4] = { 1.0f,0.0f,0.0f,1.0f };

	//Guard
	float g[4] = { 0.0f,1.0f,1.0f,1.0f };
	float g2[4] = { 0.0f,0.0f,1.0f,1.0f };

	RECT_F src;
	RECT_F dst;
	CHitBox*hit = Hits::GetHitBox(this);

	src.m_top = 0.0f + (128 * 10);
	src.m_left = 0.0f + (128 * 5);
	src.m_right = 128.0f + (128 * 5);
	src.m_bottom = 128.0f + (128 * 10);

	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x;
	dst.m_right = 144.0f + m_x;
	dst.m_bottom = 144.0f + m_y;

	Draw::Draw(0, &src, &dst, c, Rotdraw);

	//画面左上に拡大画像を表示させる

	if (hit->CheckObjNameHit(OBJ_PLAYER) != nullptr)
	{
		CObjMap* pos = (CObjMap*)Objs::GetObj(OBJ_MAP);
		Cardname();

		dst.m_top = 12.0f;
		dst.m_left = 12.0f;
		dst.m_right = 371.0f;
		dst.m_bottom = 371.0f;

		wchar_t atr[256];
		wchar_t aatr[5][64];
		mbstowcs(atr, pos->name, 256);//マルチバイトをワイドに変換
		Font::StrDraw(atr, 40, 595, 20, e);//テキストを表示

		for (int i = 0; i * 30 < Tlong; i++) {
			mbstowcs(aatr[i], pos->text2[i], 64);
			Font::StrDraw(aatr[i], 40, 640 + i * 20, 20, e);
		}

		Draw::Draw(0, &src, &dst, c, 0);
	}

	//ボタンの表示
	if (Button == true)
	{
		b_x = m_x - 20.0;
		b_y = m_y + 10.0;

		src.m_top = 0.0f;
		src.m_left = 0.0f + (BDraw * 64);
		src.m_right = 64.0f + (BDraw * 64);
		src.m_bottom = 64.0f;

		dst.m_top = 0.0f + b_y;
		dst.m_left = 0.0f + b_x;
		dst.m_right = 64.0f + b_x;
		dst.m_bottom = 64.0f + b_y;

		Draw::Draw(3, &src, &dst, c, Rotdraw);
	}
	wchar_t str[128];
	if (Atack == 1)
	{
		swprintf_s(str, L"%d", Atack);
		Font::StrDraw(str, 753, 701, 24, a);
	}
	else if (Atack != 1)
	{
		if (Atack >= 10)
		{
			swprintf_s(str, L"%d", Atack);
			Font::StrDraw(str, 746, 701, 24, a2);
		}
		else
		{
			swprintf_s(str, L"%d", Atack);
			Font::StrDraw(str, 753, 701, 24, a2);
		}
	}
	if (Hp == 20)
	{
		swprintf_s(str, L"%d", Hp);
		Font::StrDraw(str, 779, 701, 24, h);
	}
	else if (Hp != 20)
	{
		if (Hp >= 10)
		{
			swprintf_s(str, L"%d", Hp);
			Font::StrDraw(str, 779, 701, 24, h2);
		}
		else
		{
			swprintf_s(str, L"%d", Hp);
			Font::StrDraw(str, 786, 701, 24, h2);
		}
	}
	if (Guard == 0)
	{
		swprintf_s(str, L"%d", Guard);
		Font::StrDraw(str, 817, 701, 24, g);
	}
	else if (Guard != 0)
	{
		if (Guard >= 10)
		{
			swprintf_s(str, L"%d", Guard);
			Font::StrDraw(str, 810, 701, 24, g2);;
		}
		else
		{
			swprintf_s(str, L"%d", Guard);
			Font::StrDraw(str, 817, 701, 24, g2);
		}
	}

	//リタイア確認
	/*if (r_f == true)
	{
		src.m_top = 64.0f;
		src.m_left = 0.0f;
		src.m_right = 189.0f;
		src.m_bottom = 121.0f;

		dst.m_top = 300.0f;
		dst.m_left = 500.0f;
		dst.m_right = 1100.0f;
		dst.m_bottom = 500.0f;

		Draw::Draw(3, &src, &dst, c, 0.0f);

		swprintf_s(str, L"本当にリタイアしますか？");
		Font::StrDraw(str, 595, 330, 36, c);
		swprintf_s(str, L"はい");
		Font::StrDraw(str, 600, 420, 36, c);
		swprintf_s(str, L"いいえ");
		Font::StrDraw(str, 900, 420, 36, c);
	}*/
}

//Cardname関数
//Cardname()を入力すれば、カードに名前とテキストが表示されるようになる
void CObjPHero::Cardname()
{
	CObjMap* pos = (CObjMap*)Objs::GetObj(OBJ_MAP);

	FILE *fp;
	char fname[] = "CardList.csv";
	fp = fopen(fname, "r"); // ファイルを開く。失敗するとNULLを返す。
	int ret;
	int aaaa;//ダミーデータ

	while ((ret = fscanf(fp, "%[^,],%d,%d,%d,%d,%d,%d,%[^\n] ,", pos->name, &aaaa, &TextD, &aaaa, &aaaa, &aaaa, &aaaa, text) != EOF))//名前、カード番号、テキストを入れる
	{
		if (TextD == 1551)//カード番号が一致したとき、処理開始
		{
			Tlong = strlen(text);//テキストの長さを求める
			for (int j = 0; j < 6; j++)
			{
				pos->text2[j][0] = '\0';
			}
			for (int i = 0; i * 30 < Tlong; i++)//15文字づつ改行していく
			{
				strncpy(pos->text2[i], text + i * 30, 30);
				pos->text2[i][30] = '\0';
			}
			break;
		}
	}

	fclose(fp); // ファイルを閉じる
}