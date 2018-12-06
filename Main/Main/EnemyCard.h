#pragma once
#include"GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト　デッキ
class CObjEnemyCard :public CObj
{
public:
	CObjEnemyCard(float x, float y);
	~CObjEnemyCard() {};
	void Init();
	void Action();
	void Draw();

private:
	int m_x, m_y;
	int Setcard;
	int Nanber;
	int Nanber2;
	int Nanber3;
	int Posicard;
	int Reset;
	int playertrun;
	int enemytrun;

	int Hp;//カードのhp
	int Atack;//カードの攻撃力
	int Guard;//カードの防御力

	bool CardHitCheck;//マウスがカードと触れているか参照する変数

	int Shand;

	int Opdraw;
	int Updraw;
	int Rotdraw;

	bool m_r;
	bool Summon;
	bool m_f;
	bool Reflag;

	bool L_position;
	bool S_position;
	bool R_position;
};