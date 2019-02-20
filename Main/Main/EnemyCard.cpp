//シヨウスルヘッダーファイル
#include"GameL\DrawTexture.h"
#include"GameL\HitBoxManager.h"
#include"GameL\WinInputs.h"
#include"GameHead.h"
#include"EnemyCard.h"

#include"GameL\DrawFont.h"

//使用するネームスペース
CObjEnemyCard::CObjEnemyCard(float x, float y)
{
	m_x = x;
	m_y = y;
}

//イニシャライズ
void CObjEnemyCard::Init()
{
	CObjEnemyDeck*sc = (CObjEnemyDeck*)Objs::GetObj(OBJ_ENEMY_DECK);
	CObjEnemyHand*han = (CObjEnemyHand*)Objs::GetObj(OBJ_ENEMY_HAND);
	Number = sc->Cnanber;//bango 引いたカードの順番の固定
	Number2 = han->hand[Number - 1];
	Number3 = han->basyo[Number - 1];

	aaaa = sc->Cnanber;

	Number4= sc->EnemyDeck[sc->e_Card - 1];

	Opdraw = sc->EnemyDeck[sc->e_Card - 1];//test カード番号の保存
	Updraw = 0;//taka カードの描画位置の調整
	Rotdraw = 0;//test2 カードの回転描画調整

	CardHitCheck = false;
	Summon = false;
	StopSm = false;
	Shand = 0;

	Atacks = false;

	R_Summon = false;
	L_Summon = false;

	AtackUnit = 0;
	Dameg = 0;

	Opdraw--;
	Opdraw = Opdraw / 10;

	while (Opdraw>15)
	{
		Opdraw -= 15;//x位置をずらす
		Updraw++;
	}
	m_f = false;

	CObjMap* pos = (CObjMap*)Objs::GetObj(OBJ_MAP);

	Hits::SetHitBox(this, m_x, m_y, 128, 128, ELEMENT_CARD, OBJ_CARD, 1);
}

//アクション
void CObjEnemyCard::Action()
{
	Rotdraw = 180;//カードを180℃回転
	CObjEnemyHand*han = (CObjEnemyHand*)Objs::GetObj(OBJ_ENEMY_HAND);
	CObjEnemyDeck*sc = (CObjEnemyDeck*)Objs::GetObj(OBJ_ENEMY_DECK);
	CObjDekc*pd = (CObjDekc*)Objs::GetObj(OBJ_DEKC);

	CHitBox*hit = Hits::GetHitBox(this);
	CObjmouse*mou = (CObjmouse*)Objs::GetObj(OBJ_MAUSE);


	Setcard = sc->Cnanber;//Setcard カードの位置調整変更用

	Posicard = Setcard - Number;//Posicard カードの位置調整変更用２

	CObjMap* pos = (CObjMap*)Objs::GetObj(OBJ_MAP);
	L_position = pos->L_position;
	S_position = pos->S_position;
	R_position = pos->R_position;

	if (hit->CheckObjNameHit(OBJ_PLAYER) != nullptr && Summon == true)
	{
		Cardname();
		CardHitCheck = true; //"マウスがカードに触れている"状態にする
	}
	else
	{
		CardHitCheck = false; //"マウスがカードに触れていない"状態にする
	}

	Setcard = sc->Cnanber;//カードの位置調整変更用

	Posicard = Setcard - Number;//カードの位置調整変更用２

	if (Number3 - han->hensu3 > 0 && han->hensu > 0)//現在の場所が出したカードよりも後の場合、ひとつずらす
	{
		aaaa = aaaa;
		Number--;//番号を１ずらす
		han->hensu2++;
	}

	Number3 = han->basyo[Number - 1];//手札の場所を更新

	if (Setcard <= 5 && Summon == false)
	{
		for (int i = 0; i < Setcard; i++)
		{
			if (han->hand[i] == Number2)
			{
				aaaa = aaaa;
				m_x = 927 - (90 * i);
			}
		}
	}

	else if (Summon == false) {
		for (int i = 0; i < Setcard; i++)
		{
			if (han->hand[i] == Number2)
			{
				aaaa = aaaa;
				m_x = 567 + ((450 / (Setcard))*Posicard);
			}
		}
	}

	if (pd->STurn == false && pd->Start == true) {
		if (Summon == false && sc->Summon2 == false && sc->EDraw == true && aaaa == aaaa)
		{
			CObjPlist* PList = new CObjPlist();//関数呼び出し

			PList->Action(&Name, Number4, &Ccost, &NTcard, &Hp, &Atack, &Guard, &Text);//カード番号に沿ってHP変動
			Hp2 = Hp;
			Atack2 = Atack;
			Guard2 = Guard;

			pos->m_f = true;
			//仮置きの敵召喚　手札の順番が１，２，３のカードを召喚
			if (Number == 1 && pos->ES_position == false || Number == 1 && pos->ES_position2 == false) {
				if (pos->ES_position == false)
				{
					m_x = 543;
					m_y = 191;
					pos->ECard2[0] = Hp; pos->ECard2[1] = Atack; pos->ECard2[2] = Guard;
					pos->ES_position = true;
					R_Summon = true;

					//HitBoxの入れ替え　これで攻撃対象に選択できるように
					Hits::DeleteHitBox(this);
					Hits::SetHitBox(this, m_x, m_y, 90, 120, ELEMENT_ITEM, OBJ_FIELD_ENEMY2, 1);
				}
				else if (pos->ES_position2 == false)
				{
					m_x = 951;
					m_y = 191;
					pos->ECard3[0] = Hp; pos->ECard3[1] = Atack; pos->ECard3[2] = Guard;
					pos->ES_position2 = true;
					L_Summon = true;

					//HitBoxの入れ替え　これで攻撃対象に選択できるように
					Hits::DeleteHitBox(this);
					Hits::SetHitBox(this, m_x, m_y, 90, 120, ELEMENT_ITEM, OBJ_FIELD_ENEMY3, 1);
				}

				Summon = true;
				sc->Summon2 = true;
			}
		}

		//カードが召喚されたとき
		if (Summon == true && StopSm == false)
		{
			han->hand[Number3 - 1] = 0; //出したカードのカード番号を削除
			han->basyo[Number3 - 1] = 0; //出したカードの場所情報を削除
			han->hensu = Setcard - Number3; //手札の合計と出したカードの差分を保存
			han->hensu3 = Number3; //出したカードの場所を保存
			sc->Cnanber--; //カードの合計枚数を１減らす
			pos->m_f = true;
			StopSm = true;
		}
	}

	else
	{
		pos->EAtackt = 0;
		Atacks = false;
		Dameg = 0;
		AtackUnit = 0;
	}

	if (Summon == true)
	{
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
				if (R_Summon == true) {
					//武器を所持していた場合、耐久度減少
					if (pos->PCard[AtackUnit][4] > 0)
						pos->PCard[AtackUnit][4] -= 1;

					//２つ目の武器を所持していた場合、耐久度減少
					if (pos->PCard[AtackUnit][6] > 0)
						pos->PCard[AtackUnit][6] -= 1;

					if (pos->ECard2[1] - pos->PCard[AtackUnit][2] > 0)
						pos->PCard[AtackUnit][0] -= pos->ECard2[1] - pos->PCard[AtackUnit][2];//敵のHPを自身の攻撃力-敵の守備分だけダメージを与える

					if (pos->PCard[AtackUnit][1] - pos->ECard2[2] > 0)
						pos->ECard2[0] -= pos->PCard[AtackUnit][1] - pos->ECard2[2];//敵の攻撃力-自身のHPの分だけダメージを受ける
				}

				else if (L_Summon == true) {
					//武器を所持していた場合、耐久度減少
					if (pos->PCard[AtackUnit][4] > 0)
						pos->PCard[AtackUnit][4] -= 1;

					//２つ目の武器を所持していた場合、耐久度減少
					if (pos->PCard[AtackUnit][6] > 0)
						pos->PCard[AtackUnit][6] -= 1;

					if (pos->ECard3[1] - pos->PCard[AtackUnit][2] > 0)
						pos->PCard[AtackUnit][0] -= pos->ECard3[1] - pos->PCard[AtackUnit][2];//敵のHPを自身の攻撃力-敵の守備分だけダメージを与える

					if (pos->PCard[AtackUnit][1] - pos->ECard3[2] > 0)
						pos->ECard3[0] -= pos->PCard[AtackUnit][1] - pos->ECard3[2];//敵の攻撃力-自身のHPの分だけダメージを受ける
				}
				pos->EAtackt++;
				Atacks = true;
			}
		}

		if (R_Summon == true)
		{
			//Hpの更新
			Hp = pos->ECard2[0];
		}
		else if (L_Summon == true)
		{
			Hp = pos->ECard3[0];
		}

		if (Hp <= 0)
		{
			if (R_Summon == true)
			{
				pos->ES_position = false;
			}
			else if (L_Summon == true)
			{
				pos->ES_position2 = false;
			}

			//HPが０なら消滅
			this->SetStatus(false);
			Hits::DeleteHitBox(this);
		}
	}

	hit->SetPos(m_x, m_y);
}

//ドロー
void CObjEnemyCard::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	float d[4] = { 1.0f,1.0f,1.0f,1.0f };
	//HP
	float h[4] = { 0.0f,1.0f,0.0f,1.0f };
	float h2[4] = { 0.2f,0.7,0.0f,1.0f };

	//Atack
	float a[4] = { 1.0f,0.5f,0.7f,1.0f };
	float a2[4] = { 1.0f,0.0f,0.0f,1.0f };

	//Guard
	float g[4] = { 0.0f,1.0f,1.0f,1.0f };
	float g2[4] = { 0.0f,0.0f,1.0f,1.0f };

	//cost
	float cost[4] = { 0.0f,0.0f,0.0f,1.0f };
	RECT_F src;
	RECT_F dst;
	wchar_t str[128];
	if (Number < 4 && Number !=2 && Summon==true) {
		src.m_top = 0.0f + (128.0f*Updraw);
		src.m_left = 0.0f + (128.0f*Opdraw);
		src.m_right = 128.0f + (128.0f*Opdraw);
		src.m_bottom = 128.0f + (128.0f*Updraw);
	}

	else
	{
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 128.0f;
		src.m_bottom = 128.0f;
	}

	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x - 36;
	dst.m_right = 128.0f + m_x - 36;
	dst.m_bottom = 128.0f + m_y;

	Draw::Draw(0, &src, &dst, c, Rotdraw);

	//画面左上に拡大画像を表示させる

	if (Summon == true)
	{
		if (CardHitCheck == true)
		{
			CObjMap* pos = (CObjMap*)Objs::GetObj(OBJ_MAP);

			dst.m_top = 12.0f;
			dst.m_left = 12.0f;
			dst.m_right = 371.0f;
			dst.m_bottom = 371.0f;

			wchar_t atr[256];
			wchar_t aatr[5][64];
			mbstowcs(atr, pos->name, 256);//マルチバイトをワイドに変換
			Font::StrDraw(atr, 40, 575, 20, d);//テキストを表示

			for (int i = 0; i * 30 < Tlong; i++)
			{
				mbstowcs(aatr[i], pos->text2[i], 64);
				Font::StrDraw(aatr[i], 40, 670 + i * 20, 20, d);
			}

			swprintf_s(str, L"Ｈ  Ｐ : %d/%d", Hp, Hp2);
			Font::StrDraw(str, 40, 600, 20, d);
			swprintf_s(str, L"攻撃力 : %d(%d+%d)", Atack, Atack2, Atack - Atack2);
			Font::StrDraw(str, 40, 620, 20, d);
			swprintf_s(str, L"防御力 : %d(%d+%d)", Guard, Guard2, Guard - Guard2);
			Font::StrDraw(str, 40, 640, 20, d);
			swprintf_s(str, L"コスト : %d", Ccost);
			Font::StrDraw(str, 40, 660, 20, d);
			Draw::Draw(0, &src, &dst, c, 0);

			//敵モンスターのステータス表示
			//if (Type == 1)
			//{
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
				Font::StrDraw(str, 125, 295, 50, h2);
			}
			else
			{
				swprintf_s(str, L"%d", Hp);
				Font::StrDraw(str, 130, 295, 50, h2);
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
			//}
			//敵装備のステータス表示
			/*if (Type == 2 || Type == 3)
			{
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
					Font::StrDraw(str, 125, 295, 50, h2);
				}
				else
				{
					swprintf_s(str, L"%d", Hp);
					Font::StrDraw(str, 130, 295, 50, h2);
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
			}*/
			if (Ccost == 1000)
			{
				swprintf_s(str, L"%d", Ccost);
				Font::StrDraw(str, 30, 25, 50, cost);
			}
			else
			{
				swprintf_s(str, L"%d", Ccost);
				Font::StrDraw(str, 45, 25, 50, cost);
			}
			Draw::Draw(5, &src, &dst, c, 0);
		}
	}
	
	//ステータスの表示
	if (Summon == true)
	{
		if (Atack >= 10)
		{
			swprintf_s(str, L"%d", Atack);
			Font::StrDraw(str, m_x + 5, m_y + 10, 20, a2);
		}
		else
		{
			swprintf_s(str, L"%d", Atack);
			Font::StrDraw(str, m_x + 10, m_y + 10, 20, a2);
		}

		if (Hp >= 10)
		{
			swprintf_s(str, L"%d", Hp);
			Font::StrDraw(str, m_x + 33, m_y + 10, 20, h);
		}
		else
		{
			swprintf_s(str, L"%d", Hp);
			Font::StrDraw(str, m_x + 38, m_y + 10, 20, h2);
		}

		if (Guard >= 10)
		{
			swprintf_s(str, L"%d", Guard);
			Font::StrDraw(str, m_x + 62, m_y + 10, 20, g2);
		}
		else
		{
			swprintf_s(str, L"%d", Guard);
			Font::StrDraw(str, m_x + 67, m_y + 10, 20, g2);
		}
	}
}

//Cardname関数
//Cardname()を入力すれば、カードに名前とテキストが表示されるようになる
void CObjEnemyCard::Cardname()
{
	CObjMap* pos = (CObjMap*)Objs::GetObj(OBJ_MAP);

	FILE *fp;
	char fname[] = "CardList.csv";
	fp = fopen(fname, "r"); // ファイルを開く。失敗するとNULLを返す。
	int ret;
	int aaaa;//ダミーデータ

	while ((ret = fscanf(fp, "%[^,],%d,%d,%d,%d,%d,%d,%[^\n] ,", pos->name, &aaaa, &TextD, &aaaa, &aaaa, &aaaa, &aaaa, text) != EOF))//名前、カード番号、テキストを入れる
	{
		if (TextD == Number4)//カード番号が一致したとき、処理開始
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