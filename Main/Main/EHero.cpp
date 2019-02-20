#include"GameL\DrawTexture.h"
#include"GameL\HitBoxManager.h"
#include"GameL\WinInputs.h"
#include"GameHead.h"
#include"EHero.h"
#include"Deck.h"
#include"Cardlist.h"

#include"GameL\DrawFont.h"

//使用するネームスペース
CObjEHero::CObjEHero()
{
	m_x = 738;
	m_y = 166;
}

//イニシャライズ
void CObjEHero::Init()
{
	Updraw = 0;//カードの描画位置の調整
	Rotdraw = 180;//カードの回転描画調整

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

	Hits::SetHitBox(this, m_x, m_y, 108, 144, ELEMENT_ITEM, OBJ_FIELD_ENEMY, 1);
}

//アクション
void CObjEHero::Action()
{
	CHitBox*hit = Hits::GetHitBox(this);
	CObjDekc*pd = (CObjDekc*)Objs::GetObj(OBJ_DEKC);
	CObjmouse*mou = (CObjmouse*)Objs::GetObj(OBJ_MAUSE);
	CObjMap* pos = (CObjMap*)Objs::GetObj(OBJ_MAP);

	if (start == false)
	{
		start = true;
		pos->ECard[0] = Hp;
		pos->ECard[1] = Atack;
		pos->ECard[2] = Guard;
		pos->ECard[3] = 0;
		Hp2 = Hp;
		Atack2 = Atack;
		Guard2 = Guard;
	}

	if (hit->CheckObjNameHit(OBJ_PLAYER) != nullptr)
	{
		CardHitCheck = true; //"マウスがカードに触れている"状態にする
	}
	else
	{
		CardHitCheck = false; //"マウスがカードに触れていない"状態にする
	}

	if (pd->STurn == false) {
		//戦闘プログラム
		if (Atacks == false)
			pos->EAtackt++;

		if (pos->EAtackt == 40 && Atacks == false)
		{
			for (int i = 0; i < 3; i++) {
				if (pos->PCard[i][0] >= 0) {
					Hpbox[i] = pos->PCard[i][0];
					Guardbox[i] = pos->PCard[i][2];
				}
				else
				{
					Hpbox[i] = 0;
					Guardbox[i] = 0;
				}

				if (Hpbox[i] != 0) {
					if (Dameg < Atack - pos->PCard[i][2]) {
						AtackUnit = i;
						Dameg = Atack - pos->PCard[i][2];
					}
				}
			}
				//武器を所持していた場合、耐久度減少
				if (pos->PCard[AtackUnit][4] > 0)
					pos->PCard[AtackUnit][4] -= 1;

				//２つ目の武器を所持していた場合、耐久度減少
				if (pos->PCard[AtackUnit][6] > 0)
					pos->PCard[AtackUnit][6] -= 1;

				if (pos->ECard[1] - pos->PCard[AtackUnit][2] > 0)
					pos->PCard[AtackUnit][0] -= pos->ECard[1] - pos->PCard[AtackUnit][2];//敵のHPを自身の攻撃力-敵の守備分だけダメージを与える

				if (pos->PCard[AtackUnit][1] - pos->ECard[2] > 0)
					pos->ECard[0] -= pos->PCard[AtackUnit][1] - pos->ECard[2];//敵の攻撃力-自身のHPの分だけダメージを受ける

			pos->EAtackt++;
			Atacks = true;
		}
	}

	else {
		pos->EAtackt = 0;
		Atacks = false;
		Dameg = 0;
		AtackUnit = 0;
	}

	Hp = pos->ECard[0];
	if (Hp <= 0)
	{
		Scene::SetScene(new CSceneClear());
	}

	if (hit->CheckObjNameHit(OBJ_PLAYER) != nullptr)
	{
		CardHitCheck = true; //"マウスがカードに触れている"状態にする
	}
	else
	{
		CardHitCheck = false; //"マウスがカードに触れていない"状態にする
	}
}

//ドロー
void CObjEHero::Draw()
{

	float c[4] = { 1.0f,test,1.0f,1.0f };
	float d[4] = { 1.0f,0.0f,0.0f,1.0f };
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

	wchar_t str[128];

	RECT_F src;
	RECT_F dst;
	CHitBox*hit = Hits::GetHitBox(this);

	src.m_top = 0.0f + (128 * 10);
	src.m_left = 0.0f + (128 * 6);
	src.m_right = 128.0f + (128 * 6);
	src.m_bottom = 128.0f + (128 * 10);

	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x - 36;
	dst.m_right = 144.0f + m_x - 36;
	dst.m_bottom = 144.0f + m_y;

	Draw::Draw(0, &src, &dst, c, Rotdraw);

	//画面左上に拡大画像を表示させる

	if (CardHitCheck == true)
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
		Font::StrDraw(atr, 40, 575, 20, e);//テキストを表示

		for (int i = 0; i * 30 < Tlong; i++) {
			mbstowcs(aatr[i], pos->text2[i], 64);
			Font::StrDraw(aatr[i], 40, 640 + i * 20, 20, e);
		}

		swprintf_s(str, L"Ｈ  Ｐ : %d/%d", Hp, Hp2);
		Font::StrDraw(str, 40, 600, 20, e);
		swprintf_s(str, L"攻撃力 : %d(%d+%d)", Atack, Atack2, Atack - Atack2);
		Font::StrDraw(str, 40, 620, 20, e);
		swprintf_s(str, L"防御力 : %d(%d+%d)", Guard, Guard2, Guard - Guard2);
		Font::StrDraw(str, 40, 640, 20, e);

		dst.m_top = 12.0f;
		dst.m_left = 12.0f;
		dst.m_right = 371.0f;
		dst.m_bottom = 371.0f;

		Draw::Draw(0, &src, &dst, c, 0);

		//左上に敵主人公のステータスを表示させる
		if (Atack >= 10)
		{
			swprintf_s(str, L"%d", Atack);
			Font::StrDraw(str, 50, 295, 50, a2);
		}
		else
		{
			swprintf_s(str, L"%d", Atack);
			Font::StrDraw(str, 60, 295, 50, a2);
		}

		if (Hp >= 10)
		{
			swprintf_s(str, L"%d", Hp);
			Font::StrDraw(str, 115, 295, 50, h);
		}
		else
		{
			swprintf_s(str, L"%d", Hp);
			Font::StrDraw(str, 130, 295, 50, h);
		}

		if (Guard >= 10)
		{
			swprintf_s(str, L"%d", Guard);
			Font::StrDraw(str, 185, 295, 50, g2);
		}
		else
		{
			swprintf_s(str, L"%d", Guard);
			Font::StrDraw(str, 200, 295, 50, g2);
		}

		Draw::Draw(5, &src, &dst, e, 0);
	}

	//カードの部分に敵主人公のステータスを表示
	if (Atack >= 10)
	{
		swprintf_s(str, L"%d", Atack);
		Font::StrDraw(str, 746, 176, 24, a2);
	}
	else
	{
		swprintf_s(str, L"%d", Atack);
		Font::StrDraw(str, 753, 176, 24, a2);
	}

	if (Hp >= 10)
	{
		swprintf_s(str, L"%d", Hp);
		Font::StrDraw(str, 779, 176, 24, h);
	}
	else
	{
		swprintf_s(str, L"%d", Hp);
		Font::StrDraw(str, 786, 176, 24, h);
	}

	if (Guard >= 10)
	{
		swprintf_s(str, L"%d", Guard);
		Font::StrDraw(str, 810, 176, 24, g2);
	}
	else
	{
		swprintf_s(str, L"%d", Guard);
		Font::StrDraw(str, 817, 176, 24, g2);
	}
}

//Cardname関数
//Cardname()を入力すれば、カードに名前とテキストが表示されるようになる
void CObjEHero::Cardname()
{
	CObjMap* pos = (CObjMap*)Objs::GetObj(OBJ_MAP);

	FILE *fp;
	char fname[] = "CardList.csv";
	fp = fopen(fname, "r"); // ファイルを開く。失敗するとNULLを返す。
	int ret;
	int aaaa;//ダミーデータ

	while ((ret = fscanf(fp, "%[^,],%d,%d,%d,%d,%d,%d,%[^\n] ,", pos->name, &aaaa, &TextD, &aaaa, &aaaa, &aaaa, &aaaa, text) != EOF))//名前、カード番号、テキストを入れる
	{
		if (TextD == 1561)//カード番号が一致したとき、処理開始
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