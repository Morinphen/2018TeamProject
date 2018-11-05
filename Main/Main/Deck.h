#pragma once

#include"GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト　デッキ
class CObjDekc :public CObj
{
public:
	CObjDekc() {};
	~CObjDekc() {};
	void Init();
	void Action();
	void Draw();

	int Cnanber;
	int Card;

	int set;
	int Recount;
private:
	int x, y;
	int m_x, m_y;

	int Cardcount;
	int stop;

	int Deck[40];

	bool m_f;
	bool Start;
};