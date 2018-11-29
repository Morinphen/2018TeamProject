//シヨウスルヘッダーファイル
#include"GameL\DrawTexture.h"
#include"GameL\HitBoxManager.h"
#include"GameL\WinInputs.h"
#include"GameHead.h"
#include"Card.h"
#include"Deck.h"
#include"Cardlist.h"

#include"GameL\DrawFont.h"

//使用するネームスペース
CObjCard::CObjCard(float x,float y,int z)
{
	m_x = x;
	m_y = y;
	Type = z;//カードの種類によってタイプを変える
}

//イニシャライズ
void CObjCard::Init()
{
	CObjDekc*sc = (CObjDekc*)Objs::GetObj(OBJ_DEKC);
	CObjHand*han = (CObjHand*)Objs::GetObj(OBJ_HAND);
	Nanber = sc->Cnanber;//引いたカードの順番の固定
	Nanber2 = han->hand[Nanber-1];//カード番号の保存
	Nanber3 = han->basyo[Nanber - 1];//手札の順番変数
	Nanber4 = sc->Card;

	Opdraw = sc->Card;//カード番号の保存
	Updraw = 0;//カードの描画位置の調整
	Rotdraw = 0;//カードの回転描画調整

	//ステータスの初期化
	Hp = 0;
	Atack = 0;
	Guard = 0;

	//ステータスの種　０でHPを、１で攻撃力を、２で守備力をカードごとに参照できる
	SeedHp = 0;
	SeedAtack = 1;
	SeedGuard = 2;

	//マウス参照用変数初期化
	CardHitCheck = false;

	//召喚後カード位置制御初期化
	FSummon = false;
	FSummon2 = false;
	LWeapon = false;
	RWeapon = false;

	test = 1;
	//攻撃処理、装備処理初期化
	Punch = false;
	Set = false;

	//召喚制御初期化
	StopSm = false;
	Summon = false;

	while(Opdraw>7)
	{
		Opdraw -= 7;//x位置をずらす
		Updraw++;
	}
	m_f = false;

	Hits::SetHitBox(this, m_x, m_y, 90, 120, ELEMENT_CARD, OBJ_CARD, 1);
}

//アクション
void CObjCard::Action()
{
	m_l = Input::GetMouButtonL();
	CHitBox*hit = Hits::GetHitBox(this);
	CObjmouse*mou = (CObjmouse*)Objs::GetObj(OBJ_MAUSE);
	CObjHand*han = (CObjHand*)Objs::GetObj(OBJ_HAND);
	CObjDekc*sc = (CObjDekc*)Objs::GetObj(OBJ_DEKC);
	CObjMap* pos = (CObjMap*)Objs::GetObj(OBJ_MAP);
	CObjDekc* point = (CObjDekc*)Objs::GetObj(OBJ_DEKC);

	//左クリックされたとき
	if (m_l == true)
	{
		//主人公に触れているとき武器を装備させる
		if (mou->Choice[0] == 1 && Set == true) {

			for (int i = 0; i < 2; i++) {
				if (pos->WPosition[i] <= 0  && Summon == false)
				{

					m_x = 703 + 90 * i;

					m_y = 466;
					//モンスターのパラメータ強化
					pos->PCard[i / 2][1] += Atack;
					pos->PCard[i / 2][2] += Guard;

					//武器の位置の右か左かを判断し、武器のHPとカード情報を保存
					if (i - 2 == 0) {
						pos->PCard[i / 2][4] = Hp;
						pos->PCard[i / 2][5] = Nanber4;
						RWeapon = true;
					}
					else {
						pos->PCard[i / 2][6] = Hp;
						pos->PCard[i / 2][7] = Nanber4;
						LWeapon = true;
					}

					//色を元に戻す
					test = 1;
					//召喚した扱いにする
					Summon = true;
					//選択された情報を元に戻す
					Set = false;
					pos->Wtouch = false;
					//武器を召喚した情報を登録
					pos->WSummon = true;
					//武器の位置を保存しておく
					pos->WPosition[i] = Nanber4;
				}

			}

		}

		//右側のモンスターに触れているとき武器を装備させる
		if (mou->Choice[1] == 1 && Set == true) {

			for (int i = 2; i < 4; i++) {
				if (pos->WPosition[i] <= 0 && i > 1 && Summon == false)
				{

					m_x = 498 + 90 * (i - 2);

					m_y = 466;
					//モンスターのパラメータ強化
					pos->PCard[i / 2][1] += Atack;
					pos->PCard[i / 2][2] += Guard;

					//武器の位置の右か左かを判断し、武器のHPとカード情報を保存
					if (i - 2 == 0) {
						pos->PCard[i / 2][4] = Hp;
						pos->PCard[i / 2][5] = Nanber4;
						RWeapon = true;
					}
					else {
						pos->PCard[i / 2][6] = Hp;
						pos->PCard[i / 2][7] = Nanber4;
						LWeapon = true;
					}

					//色を元に戻す
					test = 1;
					//召喚した扱いにする
					Summon = true;
					//選択された情報を元に戻す
					Set = false;
					pos->Wtouch = false;
					//武器を召喚した情報を登録
					pos->WSummon = true;
					//武器の位置を保存しておく
					pos->WPosition[i] = Nanber4;
				}

			}

		}
		//左側のモンスターに触れているとき武器を装備させる
		if (mou->Choice[2] == 1 && Set == true){
			for (int i = 4; i < 6; i++) {
				if (pos->WPosition[i] <= 0 && i > 1 && Summon == false)
				{

					m_x = 906 + 90 * (i - 4);

					m_y = 466;
					pos->PCard[i / 2][1] += Atack;
					pos->PCard[i / 2][2] += Guard;

					if (i - 4 == 0) {
						pos->PCard[i / 2][4] = Hp;
						pos->PCard[i / 2][5] = Nanber4;
						RWeapon = true;
					}
					else  {
						pos->PCard[i / 2][6] = Hp;
						pos->PCard[i / 2][7] = Nanber4;
						LWeapon = true;
					}

					test = 1;
					Summon = true;
					Set = false;
					pos->Wtouch = false;
					pos->WSummon = true;
					point--;
					pos->WPosition[i] = Nanber4;
				}

			}

		}

		//武器が召喚されなかった場合元に戻す
		if (Summon == false && mou->Touch == false && Type == 2 || Summon == false && mou->Touch == false && Type == 3)
		{
			test = 1;
			Set = false;
			pos->Wtouch = false;
		}

		//モンスターが敵に攻撃したとき
		if(mou->EChoice==true && Punch==true)
		{
			//FSummon=右側の味方、違う場合は左側
			if (FSummon == true) {
				if (pos->PCard[1][1] - pos->ECard[2] > 0) 
					pos->ECard[0] -= pos->PCard[1][1] - pos->ECard[2];//敵のHPを自身の攻撃力-敵の守備分だけダメージを与える

				if (pos->ECard[1] - pos->PCard[1][2] > 0) 
					pos->PCard[1][0] -= pos->ECard[1] - pos->PCard[1][2];//敵の攻撃力-自身のHPの分だけダメージを受ける
				
			}
			else
			{
				if(pos->PCard[2][1] - pos->ECard[2]>0)
					pos->ECard[0] -= pos->PCard[2][1] - pos->ECard[2];

				if(pos->ECard[1] - pos->PCard[2][2]>0)
					pos->PCard[2][0] -= pos->ECard[1] - pos->PCard[2][2];
			}
			//選択情報を元に戻す
			test = 1;
			Punch = false;
		}

		else if (mou->EChoice2 == true && Punch == true)
		{
			if (FSummon == true) {
				if(pos->PCard[1][1] - pos->ECard2[2]>0)
					pos->ECard2[0] -= pos->PCard[1][1] - pos->ECard2[2];

				if (pos->ECard2[1] - pos->PCard[1][2]>0)
					pos->PCard[1][0] -= pos->ECard2[1] - pos->PCard[1][2];
			}
			else
			{
				if(pos->PCard[2][1] - pos->ECard2[2]>0)
					pos->ECard2[0] -= pos->PCard[2][1] - pos->ECard2[2];

				if(pos->ECard2[1] - pos->PCard[2][2]>0)
				pos->PCard[2][0] -= pos->ECard2[1] - pos->PCard[2][2];
			}
			test = 1;
			Punch = false;
		}

		else if (mou->EChoice3 == true && Punch == true)
		{
			if (FSummon == true) {
				if(pos->PCard[1][1] - pos->ECard3[2]>0)
					pos->ECard3[0] -= pos->PCard[1][1] - pos->ECard3[2];

				if(pos->ECard3[1] - pos->PCard[1][2]>0)
					pos->PCard[1][0] -= pos->ECard3[1] - pos->PCard[1][2];
			}
			else
			{
				if(pos->PCard[2][1] - pos->ECard3[2]>0)
					pos->ECard3[0] -= pos->PCard[2][1] - pos->ECard3[2];

				if(pos->ECard3[1] - pos->PCard[2][2]>0)
					pos->PCard[2][0] -= pos->ECard3[1] - pos->PCard[2][2];
			}
			test = 1;
			Punch = false;
		}

		else if(Type==1)
		{
			test = 1;
			Punch = false;
		}

	}

	Setcard = sc->Cnanber;//カードの位置調整変更用

	Posicard = Setcard - Nanber;//カードの位置調整変更用２
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

	if (Nanber3 - han->hensu3 > 0 && han->hensu>0)//現在の場所が出したカードよりも後の場合、ひとつずらす
	{
		Nanber--;//番号を１ずらす
		han->hensu2++;
	}

	Nanber3 = han->basyo[Nanber - 1];//手札の場所を更新

	L_position = pos->L_position;

	S_position = pos->S_position;
	S_position2 = pos->S_position2;

	R_position = pos->R_position;
	
	if(Setcard <=5 && Summon == false)
	{
		//m_x = 250+(90* Posicard);
		for (int i = 0; i < Setcard; i++)
		{
			if (han->hand[i] == Nanber2)
			{
				m_x = 927 - (90 * i);
			}
		}
	}

	else if(Summon == false){
		for (int i = 0; i < Setcard; i++)
		{
			if (han->hand[i] == Nanber2)
			{
				m_x = 927 - ((450 / (Setcard))*Posicard);
			}
		}
	}

	if (hit->CheckObjNameHit(OBJ_PLAYER) != nullptr && Summon == false && pos->Wtouch == false)
	{
		CardHitCheck = true; //"マウスがカードに触れている"状態にする
		Rotdraw = 3;//カードを３℃回転
		SetPrio(11);//カードの描画優先度変更
		if (m_l == true)
		{
			if (pos->m_f == false) {
				CObjCardlist* List = new CObjCardlist();//関数呼び出し

				/*if (L_position == false && Type == 2)
				{
					Atack = List->Action(Type, Nanber, Atack);//カード番号に沿って攻撃力変動
					m_x = 543;
					m_y = 586;

					pos->L_position = true;

					delete List;
					hit->SetPos(m_x, m_y);
				}*/

				//モンスターの場合
				if (S_position == false && pos->Wtouch == false && Type == 1 || S_position2 == false && pos->Wtouch == false && Type == 1)
				{
					Hp = List->Action(Type, Nanber, SeedHp);//カード番号に沿ってHP変動
					Atack = List->Action(Type,Nanber, SeedAtack);//カード番号に沿って攻撃力変動
					Guard = List->Action(Type, Nanber, SeedGuard);//カード番号に沿って防御力変動

					//左側のスペースが開いている場合
					if (S_position == false) {
						m_x = 543;
						m_y = 586;
						//Hitboxを更新し、フィールド内での処理ができるようにする
						Hits::DeleteHitBox(this);
						Hits::SetHitBox(this, m_x, m_y, 90, 120, ELEMENT_GREEN, OBJ_FIELD_PLAYER2, 1);

						//フィールドにカード情報を登録
						pos->PCard[1][0] = Hp;
						pos->PCard[1][1] = Atack;
						pos->PCard[1][2] = Guard;
						//召喚された情報を登録
						pos->S_position = true;
						FSummon = true;
						Summon = true;
					}
					//そうでない場合、右に召喚
					else {
						m_x = 951;
						m_y = 586;
						Hits::DeleteHitBox(this);
						Hits::SetHitBox(this, m_x, m_y, 90, 120, ELEMENT_GREEN, OBJ_FIELD_PLAYER3, 1);
						pos->PCard[2][0] = Hp;
						pos->PCard[2][1] = Atack;
						pos->PCard[2][2] = Guard;
						pos->S_position2 = true;
						FSummon2 = true;
						Summon = true;
					}

					delete List;
					pos->m_f = true;
					hit->SetPos(m_x, m_y);
				}

				//武器の場合
				else if (Type==2 && pos->Wtouch==false || Type==3 && pos->Wtouch == false)
				{
					for (int i = 0; i < 6; i++) {

						//武器を装備できる見方がいる場合、選択できるようにする
						if (pos->WPosition[i]<=0)
						{
							test = 0;
							Set = true;
							pos->Wtouch = true;
							break;
						}

					}

					Hp = List->Action(Type, Nanber, SeedHp);//カード番号に沿ってHP変動
					Atack = List->Action(Type,Nanber, SeedAtack);//カード番号に沿って攻撃力変動
					Guard = List->Action(Type, Nanber, SeedGuard);//カード番号に沿って守備力変動
					//pos->m_f = true;
					delete List;
				}

			}
		}

		else
		{
			pos->m_f = false;
		}
	}

	//召喚されたモンスターに触れた場合
	else if (hit->CheckObjNameHit(OBJ_PLAYER) != nullptr && Summon == true && Type==1)
	{
		CardHitCheck = true; //"マウスがカードに触れていない"状態にする
		Rotdraw = -3;
		SetPrio(11);
		if (m_l == true && pos->WSummon == false)
		{
			test = 0;
			Punch = true;
		}
	}

	//召喚された武器に触れた場合
	else if (hit->CheckObjNameHit(OBJ_PLAYER) != nullptr && Summon == true && Type >= 2)
	{
		CardHitCheck = true; //"マウスがカードに触れていない"状態にする
		Rotdraw = -3;
		SetPrio(11);
	}

	else
	{
		CardHitCheck = false; //"マウスがカードに触れていない"状態にする
		Rotdraw = 0;
		SetPrio(10);
	}


	//カードが召喚されたとき
	if (Summon == true && StopSm==false) {
		han->hand[Nanber3 - 1] = 0;//出したカードのカード番号を削除
		han->basyo[Nanber3 - 1] = 0;//出したカードの場所情報を削除
		han->hensu = Setcard - Nanber3;//手札の合計と出したカードの差分を保存
		han->hensu3 = Nanber3;//出したカードの場所を保存
		sc->Cnanber -= 1;//カードの合計枚数を１減らす
		pos->m_f = true;
		StopSm = true;
	}

	//召喚されたモンスターの処理
	if (Summon == true && Type==1)
	{
		//右側、左側のモンスターのHP更新
		if (FSummon == true)
		{
			Hp = pos->PCard[1][0];
		}
		else
		{
			Hp = pos->PCard[2][0];
		}

		//HPが０になった場合、位置情報を更新し、消去
		if (Hp <= 0)
		{
			if (FSummon == true)
			{
				pos->S_position = false;
				FSummon = false;
			}
			else
			{
				pos->S_position2 = false;
				FSummon2 = false;
			}

			Hits::DeleteHitBox(this);
			this->SetStatus(false);
		}
	}

	//装備された武器の処理
	if (Summon == true && Type == 2|| Summon == true && Type==3)
	{
		for (int i = 0; i < 3; i++)
		{
			//カードの情報を探し出し、該当した場合処理開始
			if (pos->PCard[i][5] == Nanber4 || pos->PCard[i][7] == Nanber4) {
				//右側の場合はPCard[i][4]の値を、左側の場合はPCard[i][6]のHPを参照し、更新する
				if(RWeapon==true)
					Hp = pos->PCard[i][4];
				else
					Hp = pos->PCard[i][6];

				//装備モンスターがやられるか、武器の耐久が０になった場合消去
				if (pos->PCard[i][0] <=0 || Hp==0)
				{
					pos->PCard[i][1] -= Atack;
					pos->PCard[i][2] -= Guard;
					pos->PCard[i][4] = 0;
					//pos->PCard[i][5] = 0;

					for (int j = 0; j < 6; j++) {
						if (pos->WPosition[j] == Nanber4) {
							pos->WPosition[j] = 0;
							break;
						}
					}

					Hits::DeleteHitBox(this);
					this->SetStatus(false);
				}
			}
		}
	}

	hit->SetPos(m_x, m_y);
}

//ドロー
void CObjCard::Draw()
{

	float c[4] = { 1.0f,test,1.0f,1.0f };
	float d[4] = { 1.0f,0.0f,0.0f,1.0f };
	RECT_F src;
	RECT_F dst;

	src.m_top = 0.0f+ (64.0f*Updraw);
	src.m_left = 0.0f + (64.0f*Opdraw);
	src.m_right = 64.0f + (64.0f*Opdraw);
	src.m_bottom = 64.0f+ (64.0f*Updraw);

	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x;
	dst.m_right = 90.0f + m_x;
	dst.m_bottom = 120.0f + m_y;

	Draw::Draw(0, &src, &dst, c, Rotdraw);
	
	//画面左上に拡大画像を表示させる
	
	if (CardHitCheck == true)
	{

		dst.m_top = 12.0f;
		dst.m_left = 13.0f;
		dst.m_right = 371.0f;
		dst.m_bottom = 491.0f;

		Draw::Draw(0, &src, &dst, c, 0);
	}
	else
	{
		
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 64.0f;
		src.m_bottom = 64.0f;

		dst.m_top = 12.0f;
		dst.m_left = 13.0f;
		dst.m_right = 371.0f;
		dst.m_bottom = 491.0f;

		Draw::Draw(0, &src, &dst, c, 0);
	}

	

	if (Summon == true) {
		wchar_t str[128];
		swprintf_s(str, L"%d　%d　%d", Atack, Hp, Guard);
		Font::StrDraw(str, m_x + 10, m_y + 100, 20, d);
	}
}