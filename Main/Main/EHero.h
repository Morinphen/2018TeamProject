#pragma once
#include"GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト　デッキ
class CObjEHero :public CObj
{
public:
	CObjEHero();
	~CObjEHero() {};
	void Init();
	void Action();
	void Draw();

	bool Punch;//モンスターの攻撃制御
	bool Set;//武器の装備制御

private:
	bool start;
	int m_x, m_y;//カードの描画位置
	int playertrun;
	int enemytrun;

	int Hp;//カードのhp
	int Atack;//カードの攻撃力
	int Guard;//カードの防御力

	bool CardHitCheck;//マウスがカードと触れているか参照する変数
	int Opdraw;//カードの切取り位置１
	int Updraw;//カードの切取り位置２
	int Rotdraw;//カードの角度調整

				//武器の位置を保存
	bool LWeapon;
	bool RWeapon;

	bool m_f;
	bool m_l;

	int test;

	bool L_position;

	bool S_position;
	bool S_position2;

	bool R_position;
};