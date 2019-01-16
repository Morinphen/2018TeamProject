//シヨウスルヘッダーファイル
#include"GameL\DrawTexture.h"
#include"GameL\HitBoxManager.h"
#include"GameL\WinInputs.h"
#include"GameHead.h"
#include"Card.h"
#include"Deck.h"
#include"Cardlist.h"
#include"map.h"
#include"point.h"
#include"GameL\Audio.h"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

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
	Number = sc->Cnanber;//引いたカードの順番の固定
	Number2 = han->hand[Number -1];//カード番号の保存
	Number3 = han->basyo[Number - 1];//手札の順番変数

	Number4 = sc->Card;

	WhenEfe = false;
	PlayEfe = false;
	InduEfe = false;

	Opdraw = sc->Card;//カード番号の保存
	Updraw = 0;//カードの描画位置の調整
	Rotdraw = 0;//カードの回転描画調整

	//ボタン用変数の初期化
	Button = false;
	b_x = 0;
	b_y = 0;

	//ステータスの初期化
	Hp = 0;
	Atack = 0;
	Guard = 0;
	NTcard = 0;

	//召喚後カード位置制御初期化
	CardHitCheck = false;

	//マウス参照用変数初期化
	//CardHitCheck = false;

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

	name[0] = '\0';

	Tlong = 0;//テキストの文字列の長さを参照する変数

	m_f = false;

	Hits::SetHitBox(this, m_x, m_y, 90, 120, ELEMENT_CARD, OBJ_CARD, 1);

	Audio::LoadAudio(1, L"Audio\\召喚2.wav", EFFECT);
	Audio::LoadAudio(2, L"Audio\\ドロー.wav", EFFECT);
	Audio::LoadAudio(6, L"Audio\\装備.wav", EFFECT);


	//float Volume = Audio::VolumeMaster(0.1f);
}

//アクション
void CObjCard::Action()
{
	m_l = Input::GetMouButtonL();
	if (m_l == false)
		m_f = false;

	CHitBox*hit = Hits::GetHitBox(this);
	CObjmouse*mou = (CObjmouse*)Objs::GetObj(OBJ_MAUSE);
	CObjHand*han = (CObjHand*)Objs::GetObj(OBJ_HAND);
	CObjDekc*sc = (CObjDekc*)Objs::GetObj(OBJ_DEKC);
	CObjMap* pos = (CObjMap*)Objs::GetObj(OBJ_MAP);	//左クリックされたとき
	CObjpoint* point=(CObjpoint*)Objs::GetObj(OBJ_POINT);

	if (sc->Turn == true)
	{
		PlayEfe = false;
	}

	if (m_l == true)
	{
		//主人公に触れているとき武器を装備させる
		if (mou->Choice[0] == 1 && Set == true&&point->Cost>0) {

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
						pos->PCard[i / 2][5] = Number4;
						RWeapon = true;
					}
					else {
						pos->PCard[i / 2][6] = Hp;
						pos->PCard[i / 2][7] = Number4;
						LWeapon = true;
					}

					//効果関数呼び出し
					Effect(Type, &WhenEfe, &PlayEfe, &InduEfe);

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
					pos->WPosition[i] = Number4;
					Audio::Start(6);

				}

			}

		}

		//左側のモンスターに触れているとき武器を装備させる
		if (mou->Choice[1] == 1 && Set == true && pos->PTrun == true && point->Cost>0) {

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
						pos->PCard[i / 2][5] = Number4;
						RWeapon = true;
					}
					else {
						pos->PCard[i / 2][6] = Hp;
						pos->PCard[i / 2][7] = Number4;
						LWeapon = true;
					}

					//効果関数呼び出し
					Effect(Type, &WhenEfe, &PlayEfe, &InduEfe);

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
					pos->WPosition[i] = Number4;
					Audio::Start(6);

				}

			}

		}
		//右側のモンスターに触れているとき武器を装備させる
		if (mou->Choice[2] == 1 && Set == true && pos->PTrun == true && point->Cost>0){
			for (int i = 4; i < 6; i++) {
				if (pos->WPosition[i] <= 0 && i > 1 && Summon == false)
				{

					m_x = 906 + 90 * (i - 4);

					m_y = 466;
					pos->PCard[i / 2][1] += Atack;
					pos->PCard[i / 2][2] += Guard;

					if (i - 4 == 0) {
						pos->PCard[i / 2][4] = Hp;
						pos->PCard[i / 2][5] = Number4;
						RWeapon = true;
					}
					else  {
						pos->PCard[i / 2][6] = Hp;
						pos->PCard[i / 2][7] = Number4;
						LWeapon = true;
					}

					//効果関数呼び出し
					Effect(Type, &WhenEfe, &PlayEfe, &InduEfe);

					test = 1;
					Summon = true;
					Set = false;
					pos->Wtouch = false;
					pos->WSummon = true;
					//point--;
					pos->WPosition[i] = Number4;
					Audio::Start(6);

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

		if (m_f == false) {
			//モンスターが敵に攻撃したとき
			if (mou->EChoice == true && Punch == true && pos->PTrun == true)
			{
				//FSummon=右側の味方、違う場合は左側
				if (FSummon == true && pos->PTrun == true) {
					if (pos->PCard[1][1] - pos->ECard[2] > 0)
						pos->ECard[0] -= pos->PCard[1][1] - pos->ECard[2];//敵のHPを自身の攻撃力-敵の守備分だけダメージを与える

					if (pos->ECard[1] - pos->PCard[1][2] > 0)
						pos->PCard[1][0] -= pos->ECard[1] - pos->PCard[1][2];//敵の攻撃力-自身のHPの分だけダメージを受ける

				}
				else if (pos->PTrun == true)
				{
					if (pos->PCard[2][1] - pos->ECard[2] > 0)
						pos->ECard[0] -= pos->PCard[2][1] - pos->ECard[2];

					if (pos->ECard[1] - pos->PCard[2][2] > 0)
						pos->PCard[2][0] -= pos->ECard[1] - pos->PCard[2][2];
				}
				//選択情報を元に戻す
				test = 1;
				Punch = false;
			}

			else if (mou->EChoice2 == true && Punch == true && pos->PTrun == true)
			{
				if (FSummon == true) {
					if (pos->PCard[1][1] - pos->ECard2[2] > 0)
						pos->ECard2[0] -= pos->PCard[1][1] - pos->ECard2[2];

					if (pos->ECard2[1] - pos->PCard[1][2] > 0)
						pos->PCard[1][0] -= pos->ECard2[1] - pos->PCard[1][2];
				}
				else
				{
					if (pos->PCard[2][1] - pos->ECard2[2] > 0)
						pos->ECard2[0] -= pos->PCard[2][1] - pos->ECard2[2];

					if (pos->ECard2[1] - pos->PCard[2][2] > 0)
						pos->PCard[2][0] -= pos->ECard2[1] - pos->PCard[2][2];
				}
				test = 1;
				Punch = false;
			}

			else if (mou->EChoice3 == true && Punch == true && pos->PTrun == true)
			{
				if (FSummon == true) {
					if (pos->PCard[1][1] - pos->ECard3[2] > 0)
						pos->ECard3[0] -= pos->PCard[1][1] - pos->ECard3[2];

					if (pos->ECard3[1] - pos->PCard[1][2] > 0)
						pos->PCard[1][0] -= pos->ECard3[1] - pos->PCard[1][2];
				}
				else
				{
					if (pos->PCard[2][1] - pos->ECard3[2] > 0)
						pos->ECard3[0] -= pos->PCard[2][1] - pos->ECard3[2];

					if (pos->ECard3[1] - pos->PCard[2][2] > 0)
						pos->PCard[2][0] -= pos->ECard3[1] - pos->PCard[2][2];
				}
				test = 1;
				Punch = false;
			}

			else if (Type == 1)
			{
				test = 1;
				Punch = false;
			}
		}

	}

	//ボタン出現時
	if (Button == true)
	{
		SetPrio(12);
		if(m_f == false){
			if (m_l == true)
			{
				if (mou->m_mouse_x > b_x && mou->m_mouse_x < b_x + 64
					&& mou->m_mouse_y > b_y + 16 && mou->m_mouse_y < b_y + 48)
				{

					Effect(Type, &WhenEfe, &PlayEfe, &InduEfe);
					Button = false;
					m_f = true;
					if (Type == 1)
					{
						test = 0;
						Punch = true;
					}
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

	Setcard = sc->Cnanber;//カードの位置調整変更用

	Posicard = Setcard - Number;//カードの位置調整変更用２
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

	if (Number3 - han->hensu3 > 0 && han->hensu>0)//現在の場所が出したカードよりも後の場合、ひとつずらす
	{
		Number--;//番号を１ずらす
		han->hensu2++;
	}

	Number3 = han->basyo[Number + 1];//手札の場所を更新

	L_position = pos->L_position;

	S_position = pos->S_position;
	S_position2 = pos->S_position2;

	R_position = pos->R_position;
	
	if(Setcard <=5 && Summon == false)
	{
		//m_x = 250+(90* Posicard);
		for (int i = 0; i < Setcard; i++)
		{
			if (han->hand[i] == Number2)
			{
				m_x = 567 + (90 * i);
			}
		}
	}

	else if(Summon == false){
		for (int i = 0; i < Setcard; i++)
		{
			if (han->hand[i] == Number2)
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

		FILE *fp;
		char fname[] = "CardList.csv";
		fp = fopen(fname, "r"); // ファイルを開く。失敗するとNULLを返す。
		int ret;

		while ((ret = fscanf(fp, "%[^,],%d,%f,%d,%d,%d,%d,%[^\n] ,", name, &Nlist, &NTcard, &aaaa, &aaaa, &aaaa, &aaaa, text) != EOF))//名前、カード番号、テキストを入れる
		{
			if (Nlist == Type)//カード番号が一致したとき、処理開始
			{
				Tlong = strlen(text);//テキストの長さを求める
				for (int i = 0; i * 38 < Tlong; i++)//１９文字づつ改行していく
				{
					strncpy(text2[i], text + i * 38, 38);
					text2[i][38] = '\0';
				}
				break;
			}
		}

		fclose(fp); // ファイルを閉じる

		if (m_l == true)
		{
			if (pos->m_f == false) {
				CObjCardlist* List = new CObjCardlist();//関数呼び出し
				CObjPlist* PList = new CObjPlist();//関数呼び出し

				/*if (L_position == false && Type == 2)
				{
					Atack = List->Action(Type, Nanber, Atack);//カード番号に沿って攻撃力変動
					m_x = 543;
					m_y = 586;

					pos->L_position = true;

					delete List;
					hit->SetPos(m_x, m_y);
				}*/

				PList->Action(&Name, Type, &Number, &NTcard, &Hp, &Atack, &Guard, &Text);//カード番号に沿ってHP変動

				//モンスターの場合
				if (S_position == false && pos->Wtouch == false && Type == 1 || S_position2 == false && pos->Wtouch == false && Type == 1&&pos->PTrun==true&&point->Cost>0)
				{
					/*Hp = List->Action(Type, Nanber, SeedHp);//カード番号に沿ってHP変動
					Atack = List->Action(Type,Nanber, SeedAtack);//カード番号に沿って攻撃力変動
					Guard = List->Action(Type, Nanber, SeedGuard);//カード番号に沿って防御力変動*/

					//左側のスペースが開いている場合
					if (S_position == false&&point->Cost>0&&pos->PTrun==true) {
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
					else if(point->Cost>0&&pos->PTrun==true){
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

					pos->m_f = true;
					hit->SetPos(m_x, m_y);
				}

				//武器の場合
				else if (Type==2 && pos->Wtouch==false || Type==3 && pos->Wtouch == false&&pos->PTrun==true)
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

					//Hp = List->Action(Type, Nanber, SeedHp);//カード番号に沿ってHP変動
					//Atack = List->Action(Type,Nanber, SeedAtack);//カード番号に沿って攻撃力変動
					//Guard = List->Action(Type, Nanber, SeedGuard);//カード番号に沿って守備力変動
					//pos->m_f = true;
					//PList->Action(&Name, Type, &Nanber, &Hp, &Atack, &Guard, &Text);//カード番号に沿ってHP変動
				}
				delete PList;
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
		CardHitCheck = true; //"マウスがカードに触れている"状態にする

		if (Button == false) {
			Rotdraw = -3;
		}

		SetPrio(11);

		if (m_l == true && pos->WSummon == false)
		{
			Button = true;
			m_f = true;
		}
	}

	//召喚された武器に触れた場合
	else if (hit->CheckObjNameHit(OBJ_PLAYER) != nullptr && Summon == true && Type >= 2)
	{
		CardHitCheck = true; //"マウスがカードに触れている"状態にする

		if (Button == false) {
			Rotdraw = -3;
		}

		SetPrio(11);

		if (m_l == true)
		{
			Button = true;
			m_f = true;
		}
	}

	else
	{
		CardHitCheck = false; //"マウスがカードに触れていない"状態にする
		Rotdraw = 0;
		if(Button==false)
			SetPrio(10);
	}


	//カードが召喚されたとき
	if (Summon == true && StopSm==false) {
		han->hand[Number3 + 1] = 0; //出したカードのカード番号を削除
		han->basyo[Number3 - 1] = 0; //出したカードの場所情報を削除
		han->hensu = Setcard - Number3; //手札の合計と出したカードの差分を保存
		han->hensu3 = Number3; //出したカードの場所を保存
		sc->Cnanber -= 1; //カードの合計枚数を１減らす
		pos->m_f = true;
		StopSm = true;
		Audio::Start(1);
		point->Cost--;//コスト減少
		
		sc->m_point--; //コスト減少
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
			if (pos->PCard[i][5] == Number4 || pos->PCard[i][7] == Number4) {
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
						if (pos->WPosition[j] == Number4) {
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
	float e[4] = { 1.0f,1.0f,1.0f,1.0f };
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

	if (Button == true)
	{
		b_x = m_x + 90.0;
		b_y = m_y + 30.0;

		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 64.0f;
		src.m_bottom = 64.0f;

		dst.m_top = 0.0f + b_y;
		dst.m_left = 0.0f + b_x;
		dst.m_right = 64.0f + b_x;
		dst.m_bottom = 64.0f + b_y;

		Draw::Draw(3, &src, &dst, c, Rotdraw);
	}
	
	//画面左上に拡大画像を表示させる
	
	if (CardHitCheck == true)
	{
		//複数カードに触れているとテキストが２重になるため、仮置きの処置
		//--------------------
		dst.m_top = 491.0f;
		dst.m_left = 0.0f;
		dst.m_right = 383.0f;
		dst.m_bottom = 800.0f;
		Draw::Draw(1, &src, &dst, e, 0);
		//--------------------
		float c[4] = { 1.0f,1.0f,1.0f,1.0f };

		dst.m_top = 12.0f;
		dst.m_left = 13.0f;
		dst.m_right = 371.0f;
		dst.m_bottom = 491.0f;

		wchar_t atr[256];
		wchar_t aatr[5][64];
		mbstowcs(atr, name, 256);//マルチバイトをワイドに変換
		Font::StrDraw(atr, 0, 600, 20, d);//テキストを表示

		for (int i = 0; i * 38 < Tlong; i++) {
			mbstowcs(aatr[i], text2[i], 64);
			Font::StrDraw(aatr[i], 0, 650 + i * 20, 20, d);
		}

		Draw::Draw(0, &src, &dst, c, 0);
		/*mbstowcs(atr, text, 256);
		Font::StrDraw(atr, 0, 650, 20, d);
		Draw::Draw(0, &src, &dst, c, 0);*/
	}

	/*else
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
	}*/

	

	if (Summon == true) {
		wchar_t str[128];
		swprintf_s(str, L"%d　%d　%d", Atack, Hp, Guard);
		Font::StrDraw(str, m_x + 10, m_y + 100, 20, d);
	}
}

//Effect関数
//カードナンバー、召喚時効果、起動効果、誘発効果の変数をぶち込んで処理する
void CObjCard::Effect(int _Cnanber, bool *When, bool *Play, bool *Indu)
{
	if (_Cnanber == 2)
	{
		CObjDekc*sc = (CObjDekc*)Objs::GetObj(OBJ_DEKC);
		CObjHand*han = (CObjHand*)Objs::GetObj(OBJ_HAND);
		//伝説の剣装備時、カードを１枚ドロー
		if (*When == false)
		{
			*When = true;
			sc->effect = true;
			sc->Action();
			han->Action();
		}

		//伝説の剣を装備している場合、タップしたらカードを１枚ドロー
		else if (*Play == false)
		{
			*Play = true;
			sc->effect = true;
			sc->Action();
			han->Action();
		}
	}
}