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
	void SetpointFlag(bool b) { m_flag_point = b; }

	int Cnanber;//手札のカードの最大数
	int Card;//引いたカードの番号
	int m_point;
	int Cost;
	bool Turn;
private:
	int x, y;
	int m_x, m_y;
	int Ctype;//カードの種類

	int Cardcount;//引いたカードの合計
	int stop;

	int Deck[40];//

	

	bool m_f;
	bool m_f2;
	bool Start;
	bool m_flag_point;
};