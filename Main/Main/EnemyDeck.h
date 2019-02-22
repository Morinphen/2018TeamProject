#pragma once

#include"GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト　デッキ
class CObjEnemyDeck :public CObj
{
public:
	CObjEnemyDeck() {};
	~CObjEnemyDeck() {};
	void Init();
	void Action();
	void Draw();

	int EnemyDeck[40];
	int Pullc[40];

	int Cnanber;
	int e_Card;

	bool Summon2;

	bool EDraw;

	bool EStartG;

	int e_point;
	int e_Cost;
	bool Turn;
	bool StartG;//ゲーム開始用変数

	bool StartED;//先行処理の変数

	int i;

	int set;
	int Recount;
private:
	int x, y;
	int m_x, m_y;
	int Ctype;//カードの種類

	int e_Cardcount;
	int stop;
	int Data;//デッキに登録するカードデータ
	int e_Deckcount; //デッキの残り枚数を参照する変数
	int Rotdraw;

	int ETruntime;

	bool m_f;
	bool Start;
};