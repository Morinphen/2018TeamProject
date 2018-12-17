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
	Number3 = Number;

	Opdraw = sc->e_Card;//test カード番号の保存
	Updraw = 0;//taka カードの描画位置の調整
	Rotdraw = 0;//test2 カードの回転描画調整

	CardHitCheck = false;
	Summon = false;
	Shand = 0;

	while (Opdraw>7)
	{
		Opdraw -= 7;//x位置をずらす
		Updraw++;
	}
	m_f = false;

	CObjMap* pos = (CObjMap*)Objs::GetObj(OBJ_MAP);

	Hits::SetHitBox(this, m_x, m_y, 90, 120, ELEMENT_CARD, OBJ_CARD, 1);
}

//アクション
void CObjEnemyCard::Action()
{
	Rotdraw = 180;//カードを180℃回転
	CObjEnemyHand*han = (CObjEnemyHand*)Objs::GetObj(OBJ_ENEMY_HAND);
	CObjEnemyDeck*sc = (CObjEnemyDeck*)Objs::GetObj(OBJ_ENEMY_DECK);

	CHitBox*hit = Hits::GetHitBox(this);
	CObjmouse*mou = (CObjmouse*)Objs::GetObj(OBJ_MAUSE);


	Setcard = sc->Cnanber;//Setcard カードの位置調整変更用

	Posicard = Setcard - Number;//Posicard カードの位置調整変更用２

								/*if (Nanber - Reset > 0 && Reset != 0 && Reset > 0)
								{
								Reflag = true;
								han->hensu -= 1;
								}

								if (Reflag == true)
								{
								Nanber3 = Nanber3;
								Nanber--;
								Reflag = false;
								}*/

	if (Number - han->hensu > 0)
	{
		Number2 = han->basyo[Number - Shand];
	}

	CObjMap* pos = (CObjMap*)Objs::GetObj(OBJ_MAP);
	L_position = pos->L_position;
	S_position = pos->S_position;
	R_position = pos->R_position;

	if (hit->CheckObjNameHit(OBJ_PLAYER) != nullptr)
	{
		CardHitCheck = true; //"マウスがカードに触れている"状態にする
	}
	else
	{
		CardHitCheck = false; //"マウスがカードに触れていない"状態にする
	}

	if (Setcard <= 5 && Summon == false)
	{
		//m_x = 250+(90* Posicard);
		for (int i = 0; i < Setcard; i++)
		{
			if (han->hand[i] == Number2)
			{
				m_x = 927 - (90 * i);
			}
		}
	}

	else if (Summon == false) {
		for (int i = 0; i < Setcard; i++)
		{
			if (han->hand[i] == Number2)
			{
				m_x = 567 + ((450 / (Setcard))*Posicard);
			}
		}
	}

	if (Number < 4 && Number!=2 && Summon==false)
	{
		Summon = true;
		//han->hand[Nanber3 - 1] = 0;//出したカードのカード番号を削除
		//han->basyo[Nanber3 - 1] = 0;//出したカードの場所情報を削除
		//han->hensu = Setcard - Nanber3;//手札の合計と出したカードの差分を保存
		//han->hensu3 = Nanber3;//出したカードの場所を保存
		//sc->Cnanber -= 1;//カードの合計枚数を１減らす
		pos->m_f = true;
		//仮置きの敵召喚　手札の順番が１，２，３のカードを召喚
		if (Number == 1) {
			m_x = 543;
			m_y = 195;
			//HitBoxの入れ替え　これで攻撃対象に選択できるように
			Hits::DeleteHitBox(this);
			Hits::SetHitBox(this, m_x, m_y, 90, 120, ELEMENT_ITEM, OBJ_FIELD_ENEMY2, 1);

			//ECard[0]=HP,ECard[1]=Atack,ECard[2]=Guard
			pos->ECard2[0] = 1; pos->ECard2[1] = 1; pos->ECard2[2] = 0;
			Hp = 1; Atack = 1; Guard = 0;
		}
		/*if (Number == 2) {
			m_x = 747;
			m_y = 195;
			Hits::DeleteHitBox(this);
			Hits::SetHitBox(this, m_x, m_y, 90, 120, ELEMENT_ITEM, OBJ_FIELD_ENEMY2, 1);
			pos->ECard2[0] = 3; pos->ECard2[1] = 2; pos->ECard2[2] = 0;
			Hp = 3; Atack = 2; Guard = 0;
		}*/
		if (Number == 3) {
			m_x = 951;
			m_y = 195;
			Hits::DeleteHitBox(this);
			Hits::SetHitBox(this, m_x, m_y, 90, 120, ELEMENT_ITEM, OBJ_FIELD_ENEMY3, 1);
			pos->ECard3[0] = 5; pos->ECard3[1] = 4; pos->ECard3[2] = 2;
			Hp = 5; Atack = 4; Guard = 2;
		}
	}

	if (Summon == true)
	{
		if (Number == 1)
		{
			//Hpの更新
			Hp = pos->ECard2[0];
		}
		/*if (Number == 2)
		{
			Hp = pos->ECard2[0];
		}*/
		if (Number == 3)
		{
			Hp = pos->ECard3[0];
		}
		if (Hp <= 0)
		{
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
	RECT_F src;
	RECT_F dst;
	if (Number < 4 && Number !=2) {
		src.m_top = 0.0f + (Number + 1) * 64;
		src.m_left = 0.0f;
		src.m_right = 64.0f;
		src.m_bottom = 64.0f + (Number + 1) * 64;
	}

	else
	{
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 64.0f;
		src.m_bottom = 64.0f;
	}

	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x;
	dst.m_right = 90.0f + m_x;
	dst.m_bottom = 120.0f + m_y;

	Draw::Draw(0, &src, &dst, c, Rotdraw);

	//画面左上に拡大画像を表示させる

	if (CardHitCheck == true)
	{
		dst.m_top = 13.0f;
		dst.m_left = 13.0f;
		dst.m_right = 371.0f;
		dst.m_bottom = 491.0f;

		Draw::Draw(0, &src, &dst, c, 0);
	}
	

	if (Summon == true) {
		wchar_t str[128];
		swprintf_s(str, L"%d　%d　%d", Atack, Hp, Guard);
		Font::StrDraw(str, m_x + 10, m_y, 20, c);
	}
}