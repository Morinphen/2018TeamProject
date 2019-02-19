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

	int set;
	int Recount;
private:
	int x, y;
	int m_x, m_y;

	int e_Cardcount;
	int stop;
	int Rotdraw;

	int ETruntime;

	int Data;//デッキに登録するカードデータ

	bool m_f;
	bool Start;
};