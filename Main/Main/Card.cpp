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
#include"Window.h"
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

	Number4 = sc->Deck[sc->Card - 1];

	WhenEfe = false;
	PlayEfe = false;
	InduEfe = false;

	BDraw = 0;

	Opdraw = sc->Deck[sc->Card - 1];//カード番号の保存

	Updraw = 0;//カードの描画位置の調整
	Rotdraw = 0;//カードの回転描画調整

	//ボタン用変数の初期化
	Button = false;
	b_x = 0;
	b_y = 0;

	//ウィンドウ用変数の初期化
	WLcard = 0;
	WRcard = 0;
	Wcount = 0;
	WLupdraw = 0;
	WRupdraw = 0;

	Wset = false;
	LDcard = false;
	RDcard = false;

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
	Pusave = false;
	Set = false;

	//召喚制御初期化
	StopSm = false;
	Summon = false;
	Wstop = false;
	WSetting = 0;

	Bat = 1;
	Bat2 = 1;

	m_c = true;

	Opdraw--;
	Opdraw = Opdraw / 10;

	while(Opdraw>15)
	{
		Opdraw -= 15;//x位置をずらす
		Updraw++;
	}

	Tlong = 0;//テキストの文字列の長さを参照する変数

	m_f = false;

	Hits::SetHitBox(this, m_x, m_y, 90, 120, ELEMENT_ENEMY, OBJ_CARD, 1);

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
	CObjMap* pos = (CObjMap*)Objs::GetObj(OBJ_MAP);
	CObjpoint* point = (CObjpoint*)Objs::GetObj(OBJ_POINT);
	CObjwindow* window = (CObjwindow*)Objs::GetObj(OBJ_WINDOW);

	if (sc->Turn == true)
	{
		PlayEfe = false;
		Pusave = false;
	}

	//手札のカードに触れたとき
	if (hit->CheckObjNameHit(OBJ_PLAYER) != nullptr && Summon == false && pos->Wtouch == false)
	{
		CardHitCheck = true; //"マウスがカードに触れている"状態にする
		Rotdraw = -3;//カードを３℃回転
		SetPrio(11);//カードの描画優先度変更

		CObjPlist* PList = new CObjPlist();//関数呼び出し
		PList->Action(&Name, Number4, &Ccost, &NTcard, &Hp, &Atack, &Guard, &Text);//カード番号に沿ってHP変動
		Hp2 = Hp;
		Atack2 = Atack;
		Guard2 = Guard;

		//カードの名前とテキストを出現させる
		Cardname();

		if (m_l == true && m_c == true)
		{
			if (pos->m_f == false && point->Cost > 0)
			{
				CObjCardlist* List = new CObjCardlist();//関数呼び出し

				Cadata = NTcard;

				if (point->Cost > Ccost)
				{
					//キャラの場合
					if (S_position == false &&
						pos->Wtouch == false &&
						Type == 1 || S_position2 == false &&
						pos->Wtouch == false &&
						Type == 1 &&
						pos->PTrun == true &&
						point->Cost > 0)
					{
						//左側のスペースが開いている場合
						if (S_position == false && point->Cost > 0 && pos->PTrun == true)
						{
							m_x = 543;
							m_y = 589;

							//Hitboxを更新し、フィールド内での処理ができるようにする
							Hits::DeleteHitBox(this);
							Hits::SetHitBox(this, m_x, m_y, 90, 120, ELEMENT_GREEN, OBJ_FIELD_PLAYER2, 1);
							//フィールドにカード情報を登録
							pos->PCard[1][0] = Hp;
							pos->PCard[1][1] = Atack;
							pos->PCard[1][2] = Guard;
							pos->PCard[1][3] = Number4;
							//召喚された情報を登録
							pos->S_position = true;
							FSummon = true;
							Summon = true;
						}

						//そうでない場合、右に召喚
						else if (point->Cost > 0 && pos->PTrun == true)
						{
							m_x = 951;
							m_y = 589;
							Hits::DeleteHitBox(this);
							Hits::SetHitBox(this, m_x, m_y, 90, 120, ELEMENT_GREEN, OBJ_FIELD_PLAYER3, 1);
							pos->PCard[2][0] = Hp;
							pos->PCard[2][1] = Atack;
							pos->PCard[2][2] = Guard;
							pos->PCard[2][3] = Number4;
							pos->S_position2 = true;
							FSummon2 = true;
							Summon = true;
						}

						pos->m_f = true;
						hit->SetPos(m_x, m_y);
					}

					//武器の場合
					else if (Type == 2 &&
						pos->Wtouch == false ||
						Type == 3 &&
						pos->Wtouch == false &&
						pos->PTrun == true)
					{
						for (int i = 0; i < 6; i++)
						{
							//武器を装備できる見方がいる場合、選択できるようにする
							if (pos->WPosition[i] <= 0)
							{
								Wwindow(&Wset, 0);
								test = 0;
								Set = true;
								pos->Wtouch = true;
								break;
							}
						}
					}

					//道具の場合
					else if (Type == 4 &&
						pos->Wtouch == false &&
						pos->PTrun == true)
					{
						Wwindow(&Wset, 0);
						test = 0;
						pos->Wtouch = true;
						Set = true;
					}

					delete PList;
				}
			}
			else
			{
				pos->m_f = false;
			}
		}
	}
	//ウィンドウが出ていない状態で、召喚されたモンスターに触れた場合
	else if (hit->CheckObjNameHit(OBJ_PLAYER) != nullptr &&
		Summon == true &&
		Type == 1 &&
		pos->WiSummon == false)
	{
		//カードの名前とテキストを出現させる
		Cardname();

		CardHitCheck = true; //"マウスがカードに触れている"状態にする

		if (Button == false)
		{
			Rotdraw = -3;
		}

		SetPrio(11);

		if (m_l == true && pos->WSummon == false && pos->PTrun == true)
		{
			Effect(Cadata, &WhenEfe, &PlayEfe, &InduEfe, 0);
			m_f = true;
			BDraw = 1;
			b_x = mou->m_mouse_x;
			b_y = mou->m_mouse_y;
		}
	}

	//ウィンドウが出ていない状態で、召喚された武器に触れた場合
	else if (hit->CheckObjNameHit(OBJ_PLAYER) != nullptr &&
		Summon == true &&
		Type >= 2 &&
		pos->WiSummon == false)
	{
		//カードの名前とテキストを出現させる
		Cardname();

		CardHitCheck = true; //"マウスがカードに触れている"状態にする

		if (Button == false)
		{
			Rotdraw = -3;
		}

		SetPrio(11);

		if (m_l == true && Button == false && pos->PTrun == true)
		{
			Effect(Cadata, &WhenEfe, &PlayEfe, &InduEfe, 0);
			m_f = true;
			BDraw = 0;
			b_x = mou->m_mouse_x;
			b_y = mou->m_mouse_y;
		}
	}

	else
	{
		CardHitCheck = false; //"マウスがカードに触れていない"状態にする
		Rotdraw = 0;
		if (Button == false || Wset == false)
			SetPrio(10);
	}

	//左クリックされたときの処理
	if (m_l == true)
	{
		//主人公にカードを使用する時の処理
		if (mou->m_mouse_x > 550 &&
			mou->m_mouse_x < b_x + 640 &&
			mou->m_mouse_y > 400 &&
			mou->m_mouse_y < 520 && 
			Wset == true &&
			pos->PTrun == true &&
			Set == true &&
			point->Cost>0)
		{
			//カードが武器or防具カードの時
			if (Type == 2 || Type == 3)
			{
				for (int i = 0; i < 2; i++)
				{
					if (pos->WPosition[i] <= 0 && Summon == false)
					{
						m_x = 700 + 97 * i;
						m_y = 462;

						//モンスターのパラメータ強化
						pos->PCard[i / 2][1] += Atack;
						pos->PCard[i / 2][2] += Guard;

						//武器の位置の右か左かを判断し、武器のHPとカード情報をフィールドに保存
						if (i == 0)
						{
							pos->PCard[i / 2][4] = Hp;

							for (int k = 1; k < 7; k++)
							{
								Wstop = false;

								for (int j = 0; j < 6; j++)
								{
									if (pos->WPosition[j] == k)
									{
										Wstop = true;
									}
								}
								if (Wstop == true)
								{
									;
								}
								else
								{
									pos->PCard[i / 2][5] = k;
									WSetting = k;
									break;
								}
							}

							RWeapon = true;
						}
						else
						{
							pos->PCard[i / 2][6] = Hp;

							for (int k = 1; k < 7; k++)
							{
								Wstop = false;

								for (int j = 0; j < 6; j++)
								{
									if (pos->WPosition[j] == k)
									{
										Wstop = true;
									}
								}
								if (Wstop == true)
								{
									;
								}
								else
								{
									pos->PCard[i / 2][7] = k;
									WSetting = k;
									break;
								}
							}

							LWeapon = true;
						}
						//効果関数呼び出し
						Effect(Cadata, &WhenEfe, &PlayEfe, &InduEfe, 0);
						Wwindow(&Wset, 1);
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
						pos->WPosition[i] = WSetting;
						Audio::Start(6);
					}
				}
			}
			//道具の時
			if (Type == 4)
			{
				//効果関数呼び出し
				Effect(Cadata, &WhenEfe, &PlayEfe, &InduEfe, 1);
				Wwindow(&Wset, 1);
				//召喚した扱いにする
				Summon = true;
				Audio::Start(6);
			}
		}
		//左側のモンスターにカードを使用する時の処理
		if (mou->m_mouse_x > 700 &&
			mou->m_mouse_x < b_x + 790 &&
			mou->m_mouse_y > 400 &&
			mou->m_mouse_y < 520 &&
			Wset == true &&
			pos->PTrun == true &&
			Set == true &&
			point->Cost>0)
		{
			//カードが武器or防具カードの時
			if (Type == 2 || Type == 3)
			{
				for (int i = 2; i < 4; i++)
				{
					if (pos->WPosition[i] <= 0 && i > 1 && Summon == false)
					{
						m_x = 496 + 97 * (i - 2);
						m_y = 462;

						//モンスターのパラメータ強化
						pos->PCard[i / 2][1] += Atack;
						pos->PCard[i / 2][2] += Guard;

						//武器の位置の右か左かを判断し、武器のHPとカード情報をフィールドに保存
						if (i - 2 == 0) {
							pos->PCard[i / 2][4] = Hp;
							for (int k = 1; k < 7; k++)
							{
								Wstop = false;
								for (int j = 0; j < 6; j++)
								{
									if (pos->WPosition[j] == k)
									{
										Wstop = true;
									}
								}
								if (Wstop == true)
								{
									;
								}
								else
								{
									pos->PCard[i / 2][5] = k;
									WSetting = k;
									break;
								}
							}
							RWeapon = true;
						}
						else
						{
							pos->PCard[i / 2][6] = Hp;

							for (int k = 1; k < 7; k++)
							{
								Wstop = false;
								for (int j = 0; j < 6; j++)
								{
									if (pos->WPosition[j] == k)
									{
										Wstop = true;
									}
								}
								if (Wstop == true)
								{
									;
								}
								else
								{
									pos->PCard[i / 2][7] = k;
									WSetting = k;
									break;
								}
							}
							LWeapon = true;
						}
						//効果関数呼び出し
						Effect(Cadata, &WhenEfe, &PlayEfe, &InduEfe, 0);
						Wwindow(&Wset, 1);
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
						pos->WPosition[i] = WSetting;
						Audio::Start(6);
					}
				}
			}
			//道具の時
			if (Type == 4)
			{
				//効果関数呼び出し
				Effect(Cadata, &WhenEfe, &PlayEfe, &InduEfe, 2);
				Wwindow(&Wset, 1);
				//召喚した扱いにする
				Summon = true;
				Audio::Start(6);
			}
		}
		//右側のモンスターにカードを使用する時の処理
		if (mou->m_mouse_x > 850 &&
			mou->m_mouse_x < b_x + 940 &&
			mou->m_mouse_y > 400 &&
			mou->m_mouse_y < 520 &&
			Wset == true &&
			pos->PTrun == true &&
			Set == true &&
			point->Cost>0)
		{
			//カードが武器or防具カードの時
			if (Type == 2 || Type == 3)
			{
				for (int i = 4; i < 6; i++)
				{
					if (pos->WPosition[i] <= 0 && i > 1 && Summon == false)
					{
						m_x = 904 + 97 * (i - 4);
						m_y = 462;
						pos->PCard[i / 2][1] += Atack;
						pos->PCard[i / 2][2] += Guard;

						//武器の位置の右か左かを判断し、武器のHPとカード情報をフィールドに保存
						if (i - 4 == 0)
						{
							pos->PCard[i / 2][4] = Hp;
							for (int k = 1; k < 7; k++)
							{
								Wstop = false;
								for (int j = 0; j < 6; j++)
								{
									if (pos->WPosition[j] == k)
									{
										Wstop = true;
									}
								}
								if (Wstop == true)
								{
									;
								}
								else
								{
									pos->PCard[i / 2][5] = k;
									WSetting = k;
									break;
								}
							}
							RWeapon = true;
						}
						else
						{
							pos->PCard[i / 2][6] = Hp;

							for (int k = 1; k < 7; k++)
							{
								Wstop = false;
								for (int j = 0; j < 6; j++)
								{
									if (pos->WPosition[j] == k)
									{
										Wstop = true;
									}
								}
								if (Wstop == true)
								{
									;
								}
								else
								{
									pos->PCard[i / 2][7] = k;
									WSetting = k;
									break;
								}
							}
							LWeapon = true;
						}
						//効果関数呼び出し
						Effect(Cadata, &WhenEfe, &PlayEfe, &InduEfe, 0);
						Wwindow(&Wset, 1);
						test = 1;
						Summon = true;
						Set = false;
						pos->Wtouch = false;
						pos->WSummon = true;
						//point--;
						pos->WPosition[i] = WSetting;
						Audio::Start(6);
					}
				}
			}

			//道具の時
			if (Type == 4)
			{
				//効果関数呼び出し
				Effect(Cadata, &WhenEfe, &PlayEfe, &InduEfe, 3);
				Wwindow(&Wset, 1);
				//召喚した扱いにする
				Summon = true;
				Audio::Start(6);
			}
		}

		//武器が召喚されなかった場合元に戻す
		if (Summon == false && mou->Touch == false && mou->Flee == true && Type == 2 ||
			Summon == false && mou->Touch == false && mou->Flee == true && Type == 3 ||
			Summon == false && mou->Touch == false && mou->Flee == true && Type == 4)
		{
			if (m_c == true)
			{
				if (test == 0)
				{
					Wwindow(&Wset, 1);
				}
				test = 1;
				Set = false;
				pos->Wtouch = false;
			}
		}

		if (m_f == false)
		{
			//主人公以外のキャラが相手の主人公に攻撃した時の処理
			if (mou->EChoice == true && Punch == true && pos->PTrun == true)
			{
				//FSummon=右側の味方、違う場合は左側
				if (FSummon == true && pos->PTrun == true && Bat == 1)
				{
					//武器を所持していた場合、耐久度減少
					if (pos->PCard[1][4] > 0)
					{
						pos->PCard[1][4] -= 1;
					}
					//２つ目の武器を所持していた場合、耐久度減少
					if (pos->PCard[1][6] > 0)
					{
						pos->PCard[1][6] -= 1;
					}
					//敵のHPを自身の攻撃力-敵の守備分だけダメージを与える
					if (pos->PCard[1][1] - pos->ECard[2] > 0)
					{
						pos->ECard[0] -= pos->PCard[1][1] - pos->ECard[2];
					}
					//敵の攻撃力-自身の防御力の分だけダメージを受ける
					if (pos->ECard[1] - pos->PCard[1][2] > 0)
					{
						pos->PCard[1][0] -= pos->ECard[1] - pos->PCard[1][2];//敵の攻撃力-自身のHPの分だけダメージを受ける
					}
					Bat = 0;
					Audio::Start(8);
				}
				else if (pos->PTrun == true && Bat2 == 1)
				{
					//武器を所持していた場合、耐久度減少
					if (pos->PCard[2][4] > 0)
					{
						pos->PCard[2][4] -= 1;
					}
					//２つ目の武器を所持していた場合、耐久度減少
					if (pos->PCard[2][6] > 0)
					{
						pos->PCard[2][6] -= 1;
					}
					//敵のHPを自身の攻撃力-敵の守備分だけダメージを与える
					if (pos->PCard[2][1] - pos->ECard[2] > 0)
					{
						pos->ECard[0] -= pos->PCard[2][1] - pos->ECard[2];
					}
					//敵の攻撃力-自身の防御力の分だけダメージを受ける
					if (pos->ECard[1] - pos->PCard[2][2] > 0)
					{
						pos->PCard[2][0] -= pos->ECard[1] - pos->PCard[2][2];
					}
					Audio::Start(8);
					Bat2 = 0;
				}
				//選択情報を元に戻す
				test = 1;
				Punch = false;
				Pusave = true;
			}

			//主人公以外のキャラが相手の左側のキャラに攻撃した時の処理
			else if (mou->EChoice2 == true && Punch == true && pos->PTrun == true)
			{
				//FSummon=左側の味方、違う場合は右側
				if (FSummon == true && Bat == 1)
				{
					//武器を所持していた場合、耐久度減少
					if (pos->PCard[1][4] > 0)
					{
						pos->PCard[1][4] -= 1;
					}
					//２つ目の武器を所持していた場合、耐久度減少
					if (pos->PCard[1][6] > 0)
					{
						pos->PCard[1][6] -= 1;
					}
					//敵のHPを自身の攻撃力-敵の守備分だけダメージを与える
					if (pos->PCard[1][1] - pos->ECard2[2] > 0)
					{
						pos->ECard2[0] -= pos->PCard[1][1] - pos->ECard2[2];
					}
					//敵の攻撃力-自身の防御力の分だけダメージを受ける
					if (pos->ECard2[1] - pos->PCard[1][2] > 0)
					{
						pos->PCard[1][0] -= pos->ECard2[1] - pos->PCard[1][2];
					}
					Audio::Start(8);
					Bat = 0;
				}
				else if (Bat2 == 1)
				{
					//武器を所持していた場合、耐久度減少
					if (pos->PCard[2][4] > 0)
					{
						pos->PCard[2][4] -= 1;
					}
					//２つ目の武器を所持していた場合、耐久度減少
					if (pos->PCard[2][6] > 0)
					{
						pos->PCard[2][6] -= 1;
					}
					//敵のHPを自身の攻撃力-敵の守備分だけダメージを与える
					if (pos->PCard[2][1] - pos->ECard2[2] > 0)
					{
						pos->ECard2[0] -= pos->PCard[2][1] - pos->ECard2[2];
					}
					//敵の攻撃力-自身の防御力の分だけダメージを受ける
					if (pos->ECard2[1] - pos->PCard[2][2] > 0)
					{
						pos->PCard[2][0] -= pos->ECard2[1] - pos->PCard[2][2];
					}
					Audio::Start(8);
					Bat2 = 0;
				}
				//選択情報を元に戻す
				test = 1;
				Punch = false;
				Pusave = true;
			}

			//主人公以外のキャラが相手の右側のキャラに攻撃した時の処理
			else if (mou->EChoice3 == true && Punch == true && pos->PTrun == true)
			{
				if (FSummon == true && Bat == 1)
				{
					//武器を所持していた場合、耐久度減少
					if (pos->PCard[1][4] > 0)
					{
						pos->PCard[1][4] -= 1;
					}
					//２つ目の武器を所持していた場合、耐久度減少
					if (pos->PCard[1][6] > 0)
					{
						pos->PCard[1][6] -= 1;
					}
					//敵のHPを自身の攻撃力-敵の守備分だけダメージを与える
					if (pos->PCard[1][1] - pos->ECard3[2] > 0)
					{
						pos->ECard3[0] -= pos->PCard[1][1] - pos->ECard3[2];
					}
					//敵の攻撃力-自身の防御力の分だけダメージを受ける
					if (pos->ECard3[1] - pos->PCard[1][2] > 0)
					{
						pos->PCard[1][0] -= pos->ECard3[1] - pos->PCard[1][2];
					}
					Bat = 0;
					Audio::Start(8);
				}
				else if (Bat2 == 1)
				{
					//武器を所持していた場合、耐久度減少
					if (pos->PCard[2][4] > 0)
					{
						pos->PCard[2][4] -= 1;
					}
					//２つ目の武器を所持していた場合、耐久度減少
					if (pos->PCard[2][6] > 0)
					{
						pos->PCard[2][6] -= 1;
					}
					//敵のHPを自身の攻撃力-敵の守備分だけダメージを与える
					if (pos->PCard[2][1] - pos->ECard3[2] > 0)
					{
						pos->ECard3[0] -= pos->PCard[2][1] - pos->ECard3[2];
					}
					//敵の攻撃力-自身の防御力の分だけダメージを受ける
					if (pos->ECard3[1] - pos->PCard[2][2] > 0)
					{
						pos->PCard[2][0] -= pos->ECard3[1] - pos->PCard[2][2];
					}
					Bat2 = 0;
					Audio::Start(8);
				}
				//選択情報を元に戻す
				test = 1;
				Punch = false;
				Pusave = true;
			}
			else if (Type == 1)
			{
				test = 1;
				Punch = false;
			}
		}
		m_c = false; //クリック長押し制御
	}
	else
	{
		m_c = true; //クリック長押し制御
	}

	//ボタン出現時
	if (test == 0)
	{
		Button = false;
	}

	if (Button == true)
	{
		SetPrio(12);

		if (m_f == false)
		{
			if (m_l == true)
			{
				//ボタンがクリックされたとき
				if (mou->m_mouse_x > b_x &&
					mou->m_mouse_x < b_x + 64 &&
					mou->m_mouse_y > b_y + 16 &&
					mou->m_mouse_y < b_y + 48 &&
					Type == 1)
				{
					Effect(Cadata, &WhenEfe, &PlayEfe, &InduEfe, 0);
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

	//現在の場所が出したカードよりも後の場合、ひとつずらす
	if (Number3 - han->hensu3 > 0 && han->hensu > 0)
	{
		Number--;//番号を１ずらす
		han->hensu2++;
	}

	Number3 = han->basyo[Number - 1];//手札の場所を更新

	//モンスターの位置更新
	S_position = pos->S_position;
	S_position2 = pos->S_position2;

	if (Setcard <= 5 && Summon == false)
	{
		for (int i = 0; i < Setcard; i++)
		{
			if (han->hand[i] == Number2)
			{
				m_x = 567 + (90 * i);
			}
		}
	}
	else if (Summon == false)
	{
		for (int i = 0; i < Setcard; i++)
		{
			if (han->hand[i] == Number2)
			{
				m_x = 927 - ((450 / (Setcard))*Posicard);
			}
		}
	}

	//手札のカードに触れたとき
	if (hit->CheckObjNameHit(OBJ_PLAYER) != nullptr && Summon == false && pos->Wtouch == false)
	{
		CardHitCheck = true; //"マウスがカードに触れている"状態にする
		Rotdraw = -3;//カードを３℃回転
		SetPrio(11);//カードの描画優先度変更

		//カードの名前とテキストを出現させる
		Cardname();

		if (m_l == true)
		{
			if (pos->m_f == false && point->Cost > 0) {

				CObjCardlist* List = new CObjCardlist();//関数呼び出し
				CObjPlist* PList = new CObjPlist();//関数呼び出し

				PList->Action(&Name, Number4, &Ccost, &NTcard, &Hp, &Atack, &Guard, &Text);//カード番号に沿ってHP変動
				Cadata = NTcard;

				if (point->Cost > Ccost)
				{
					//モンスターの場合
					if (S_position == false && pos->Wtouch == false && Type == 1 || S_position2 == false && pos->Wtouch == false && Type == 1 && pos->PTrun == true && point->Cost > 0)
					{
						//左側のスペースが開いている場合
						if (S_position == false && point->Cost > 0 && pos->PTrun == true) {
							m_x = 543;
							m_y = 589;
							//Hitboxを更新し、フィールド内での処理ができるようにする
							Hits::DeleteHitBox(this);
							Hits::SetHitBox(this, m_x, m_y, 90, 120, ELEMENT_GREEN, OBJ_FIELD_PLAYER2, 1);

							//フィールドにカード情報を登録
							pos->PCard[1][0] = Hp;
							pos->PCard[1][1] = Atack;
							pos->PCard[1][2] = Guard;
							pos->PCard[1][3] = Number4;
							//召喚された情報を登録
							pos->S_position = true;
							FSummon = true;
							Summon = true;
						}

						//そうでない場合、右に召喚
						else if (point->Cost > 0 && pos->PTrun == true) {
							m_x = 951;
							m_y = 589;
							Hits::DeleteHitBox(this);
							Hits::SetHitBox(this, m_x, m_y, 90, 120, ELEMENT_GREEN, OBJ_FIELD_PLAYER3, 1);
							pos->PCard[2][0] = Hp;
							pos->PCard[2][1] = Atack;
							pos->PCard[2][2] = Guard;
							pos->PCard[2][3] = Number4;
							pos->S_position2 = true;
							FSummon2 = true;
							Summon = true;
						}

						pos->m_f = true;
						hit->SetPos(m_x, m_y);
					}

					//武器の場合
					else if (Type == 2 && pos->Wtouch == false || Type == 3 && pos->Wtouch == false && pos->PTrun == true)
					{
						for (int i = 0; i < 6; i++) {

							//武器を装備できる見方がいる場合、選択できるようにする
							if (pos->WPosition[i] <= 0)
							{
								Wwindow(&Wset, 0);
								test = 0;
								Set = true;
								pos->Wtouch = true;
								break;
							}

						}
					}

					//道具の場合
					else if (Type == 4 && pos->Wtouch == false && pos->PTrun == true)
					{
						Wwindow(&Wset, 0);
						test = 0;
						pos->Wtouch = true;
						Set = true;
					}

					m_c = false; //クリック制御
					delete PList;
				}
				else
				{
					m_c = true; //クリック制御
				}
			}
			else
			{
				pos->m_f = false;
			}
		}
	}

		//ウィンドウが出ていない状態で、召喚されたモンスターに触れた場合
		else if (hit->CheckObjNameHit(OBJ_PLAYER) != nullptr && Summon == true && Type == 1
			&& pos->WiSummon == false)
		{
			//カードの名前とテキストを出現させる
			Cardname();

			CardHitCheck = true; //"マウスがカードに触れている"状態にする

			if (Button == false) {
				Rotdraw = -3;
			}

			SetPrio(11);

			if (m_l == true && pos->WSummon == false && pos->PTrun == true)
			{
				Effect(Cadata, &WhenEfe, &PlayEfe, &InduEfe, 0);
				m_f = true;
				BDraw = 1;
				b_x = mou->m_mouse_x;
				b_y = mou->m_mouse_y;
			}
		}

		//ウィンドウが出ていない状態で、召喚された武器に触れた場合
		else if (hit->CheckObjNameHit(OBJ_PLAYER) != nullptr && Summon == true && Type >= 2
			&& pos->WiSummon == false)
		{
			//カードの名前とテキストを出現させる
			Cardname();

			CardHitCheck = true; //"マウスがカードに触れている"状態にする

			if (Button == false) {
				Rotdraw = -3;
			}

			SetPrio(11);

			if (m_l == true && Button == false && pos->PTrun == true)
			{
				Effect(Cadata, &WhenEfe, &PlayEfe, &InduEfe, 0);
				m_f = true;
				BDraw = 0;
				b_x = mou->m_mouse_x;
				b_y = mou->m_mouse_y;
			}
		}

		else
		{
			CardHitCheck = false; //"マウスがカードに触れていない"状態にする
			Rotdraw = 0;
			if (Button == false || Wset == false)
				SetPrio(10);
		}

		if (Wset == true)
		{
			SetPrio(21);
		}

		//カードが召喚されたとき
		if (Summon == true && StopSm == false)
		{
			han->hand[Number3 - 1] = 0; //出したカードのカード番号を削除
			han->basyo[Number3 - 1] = 0; //出したカードの場所情報を削除
			han->hensu = Setcard - Number3; //手札の合計と出したカードの差分を保存
			han->hensu3 = Number3; //出したカードの場所を保存
			sc->Cnanber -= 1; //カードの合計枚数を１減らす
			pos->m_f = true;
			StopSm = true;
			Audio::Start(11);
			point->Cost -= Ccost;//コスト減少
			if (Type == 4)
			{
				Hits::DeleteHitBox(this);
				this->SetStatus(false);
			}
		}

		//召喚されたモンスターの処理
		if (Summon == true && Type == 1)
		{
			//右側、左側のモンスターのステータス更新
			if (FSummon == true)
			{
				Hp = pos->PCard[1][0];
				Atack = pos->PCard[1][1];
				Guard = pos->PCard[1][2];
			}
			else
			{
				Hp = pos->PCard[2][0];
				Atack = pos->PCard[2][1];
				Guard = pos->PCard[2][2];
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
				Audio::Start(7);
			}
		}

		//装備された武器の処理
		if (Summon == true && Type == 2 || Summon == true && Type == 3)
		{
			for (int i = 0; i < 3; i++)
			{
				//カードの情報を探し出し、該当した場合処理開始
				if (pos->PCard[i][5] == WSetting || pos->PCard[i][7] == WSetting)
				{
					//右側の場合はPCard[i][4]の値を、左側の場合はPCard[i][6]のHPを参照し、更新する
					if (RWeapon == true)
					{
						Hp = pos->PCard[i][4];
					}
					else
					{
						Hp = pos->PCard[i][6];
					}

					//装備モンスターがやられるか、武器の耐久が０になった場合消去
					if (pos->PCard[i][0] <= 0 || Hp <= 0)
					{
						pos->PCard[i][1] -= Atack;
						pos->PCard[i][2] -= Guard;

						if (RWeapon == true)
						{
							pos->PCard[i][4] = 0;
							RWeapon = false;
						}
						else
						{
							pos->PCard[i][6] = 0;
							LWeapon = false;
						}

						for (int j = 0; j < 6; j++)
						{
							if (pos->WPosition[j] == WSetting)
							{
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

		if (sc->Turn == true)
		{
			Bat = 1;
			Bat2 = 1;
		}

	hit->SetPos(m_x, m_y);
}

//ドロー
void CObjCard::Draw()
{
	float c[4] = { 1.0f,test,1.0f,1.0f };

	//左側のモンスター名、テキストの色
	float d[4] = { 1.0f,1.0f,1.0f,1.0f };

	float e[4] = { 1.0f,1.0f,1.0f,1.0f };

	//モンスターのステータスの色
	float f[4] = { 1.0f,0.0f,0.0f,1.0f };

	//武具耐久地の色
	float g[4] = { 1.0f,0.0f,0.0f,1.0f };

	//武具強化値の色
	float h[4] = { 1.0f,0.0f,0.0f,0.7f };

	RECT_F src;
	RECT_F dst;

	wchar_t str[128];

	src.m_top = 0.0f+ (128.0f*Updraw);
	src.m_left = 0.0f + (128.0f*Opdraw);
	src.m_right = 128.0f + (128.0f*Opdraw);
	src.m_bottom = 128.0f+ (128.0f*Updraw);

	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x;
	dst.m_right = 128.0f + m_x;
	dst.m_bottom = 128.0f + m_y;

	Draw::Draw(0, &src, &dst, c, Rotdraw);

	//画面左上に拡大画像を表示させる

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
			Font::StrDraw(aatr[i], 40, 670 + i * 20, 20, e);
		}

		//作成中
		if (Type == 1)
		{
			swprintf_s(str, L"Ｈ  Ｐ : %d/%d", Hp, Hp2);
			Font::StrDraw(str, 40, 600, 20, f);
			swprintf_s(str, L"攻撃力 : %d(%d+%d)", Atack, Atack2, Atack - Atack2);
			Font::StrDraw(str, 40, 620, 20, h);
			swprintf_s(str, L"防御力 : %d(%d+%d)", Guard, Guard2, Guard - Guard2);
			Font::StrDraw(str, 40, 640, 20, h);
		}
		if (Type == 2 || Type == 3)
		{
			swprintf_s(str, L"耐久値 : %d/%d", Hp, Hp2);
			Font::StrDraw(str, 40, 600, 20, f);
			swprintf_s(str, L"攻撃力 : %d", Atack);
			Font::StrDraw(str, 40, 620, 20, h);
			swprintf_s(str, L"防御力 : %d", Guard);
			Font::StrDraw(str, 40, 640, 20, h);
		}

		Draw::Draw(0, &src, &dst, d, 0);
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

	//ウィンドウの表示
	if (Wset == true)
	{
		src.m_top = 0.0f;
		src.m_left = 128.0f;
		src.m_right = 256.0f;
		src.m_bottom = 128.0f;

		dst.m_top = 0.0f + 400;
		dst.m_left = 0.0f + 550;
		dst.m_right = 128.0f + 550;
		dst.m_bottom = 128.0f + 400;

		Draw::Draw(0, &src, &dst, e, 0.0f);

		if (LDcard == true)
		{
			while (WLcard > 15)
			{
				WLcard -= 15;
				WLupdraw++;
			}

			src.m_top = 0.0f + (128.0f*WLupdraw);
			src.m_left = 0.0f + (128.0f*WLcard);
			src.m_right = 128.0f + (128.0f*WLcard);
			src.m_bottom = 128.0f + (128.0f*WLupdraw);

			dst.m_top = 0.0f + 400;
			dst.m_left = 0.0f + 700;
			dst.m_right = 128.0f + 700;
			dst.m_bottom = 128.0f + 400;

			Draw::Draw(0, &src, &dst, e, 0.0f);
		}

		if (RDcard == true)
		{
			while (WRcard > 15)
			{
				WRcard -= 15;
				WRupdraw++;
			}

			src.m_top = 0.0f + (128.0f*WRupdraw);
			src.m_left = 0.0f + (128.0f*WRcard);
			src.m_right = 128.0f + (128.0f*WRcard);
			src.m_bottom = 128.0f + (128.0f*WRupdraw);

			dst.m_top = 0.0f + 400;
			dst.m_left = 0.0f + 850;
			dst.m_right = 128.0f + 850;
			dst.m_bottom = 128.0f + 400;

			Draw::Draw(0, &src, &dst, e, 0.0f);
		}
	}

	if (Summon == true)
	{
		if (Type == 1)
		{
			swprintf_s(str, L"%d　%d　%d", Atack, Hp, Guard);
			Font::StrDraw(str, m_x + 10, m_y + 100, 20, f);
		}
		if (Type == 2 || Type == 3)
		{
			swprintf_s(str, L"%d　  %d", Atack, Guard);
			Font::StrDraw(str, m_x + 15, m_y + 100, 20, h);
		}
		if (Type == 2 || Type == 3)
		{
			swprintf_s(str, L"　 %d", Hp);
			Font::StrDraw(str, m_x + 10, m_y + 100, 20, g);
		}
	}
}

//Effect関数
//カードナンバー、召喚時効果、起動効果、誘発効果の変数をぶち込んで処理する
//Positionは召喚されているカードの場所により、入れる数値が変わる
//基本的に召喚されたモンスターなどに触れない場合は０を入れる
void CObjCard::Effect(float _Cnanber, bool *When, bool *Play, bool *Indu, int Position)
{
	CObjDekc*sc = (CObjDekc*)Objs::GetObj(OBJ_DEKC);
	CObjHand*han = (CObjHand*)Objs::GetObj(OBJ_HAND);
	CObjMap* pos = (CObjMap*)Objs::GetObj(OBJ_MAP);

	if (_Cnanber == 21)
	{
		//伝説の剣装備時、カードを１枚ドロー
		if (*When == false)
		{
			*When = true;
			sc->effect = true;
			sc->Action();
			han->Action();
		}

		//伝説の剣を装備している場合、タップしたらカードを１枚ドロー
		else if (*Play == false && Button == true)
		{
			*Play = true;
			sc->effect = true;
			sc->Action();
			han->Action();
		}
	}

	else if (_Cnanber == 1351)
	{
		pos->PCard[Position - 1][0]+=2;
	}

	if (Button == false && PlayEfe == false && Pusave == false)
	{
		Button=true;
	}
}

//Wwindow関数
//_set Wsetを入れる。これでウィンドウのオンオフが決めることができる
//_delete この中にはture,falseを入れる。ウィンドウを消したい時はtrueを入れよう。１でも可
void CObjCard::Wwindow(bool *_set,bool _delete)
{
	CObjwindow* window = (CObjwindow*)Objs::GetObj(OBJ_WINDOW);
	CObjMap* pos = (CObjMap*)Objs::GetObj(OBJ_MAP);	

	//ウィンドウが存在しない場合、ウィンドウしゅつげん
	if (*_set == false)
	{
		window = new CObjwindow(500, 350,Type);
		Objs::InsertObj(window, OBJ_WINDOW, 10);
		*_set = true;
		pos->WiSummon = true;

		//左側にモンスターがいる場合、選択肢に追加
		if (pos->S_position == true)
		{
			WLcard = pos->PCard[1][3] - 1;
			WLcard = WLcard / 10;
			LDcard = true;
			Wcount++;
		}

		//左側にモンスターがいる場合、選択肢に追加
		if (pos->S_position2 == true)
		{
			WRcard = pos->PCard[2][3] - 1;
			WRcard = WRcard / 10;
			RDcard = true;
			Wcount++;
		}
	}

	else
	{
		if (_delete == true)
		{
			window->Wdelete = true;
			*_set = false;
			pos->WiSummon = false;
			LDcard = false;
			RDcard = false;
			WLupdraw = 0;
			WRupdraw = 0;
			Wcount = 0;
		}
	}
}

//Cardname関数
//Cardname()を入力すれば、カードに名前とテキストが表示されるようになる
void CObjCard::Cardname()
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