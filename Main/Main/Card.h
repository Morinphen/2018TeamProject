#pragma once
#include"GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト　デッキ
class CObjCard :public CObj
{
public:
	CObjCard(float x,float y,int z);
	~CObjCard() {};
	void Init();
	void Action();
	void Draw();

private:
	int m_x, m_y;//カードの描画位置
	int Setcard;//カードの場所
	int Posicard;//カードの場所２
	int Nanber;//カード番号
	int Nanber2;//手札のカード番号
	int Nanber3;//カードの順番番号
	int playertrun;
	int enemytrun;

	int Hp;//カードのhp
	int Atack;//カードの攻撃力
	int Guard;//カードの防御力

	int Type;//カードの種類

	int Opdraw;//カードの切取り位置１
	int Updraw;//カードの切取り位置２
	int Rotdraw;//カードの角度調整

	bool Punch;

	bool m_r;
	bool Summon;//カードが召喚されたかどうか
	bool m_f;
	bool m_l;

	int test;

	bool Kstop;

	bool L_position;
	bool L_position2;
	bool L_position3;
	bool S_position;
	bool S_position2;
	bool R_position;
	bool R_position2;
	bool R_position3;
};