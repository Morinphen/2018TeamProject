#pragma once

#include"GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

enum type {
	monster = 1,
	weapon = 2,
	shield = 3
};

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
	int m_point;
private:
	int x, y;
	int m_x, m_y;
	int Ctype;

	int Cardcount;
	int stop;

	int Deck[40];

	

	bool m_f;
	bool Start;
};