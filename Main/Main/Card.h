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
	int Nanber;//順番の固定
	int Nanber2;//手札のカード番号
	int Nanber3;//カードの順番番号
	int Nanber4;//カード情報番号
	int playertrun;
	int enemytrun;

	int Hp;//カードのhp
	int Atack;//カードの攻撃力
	int Guard;//カードの防御力

	int SeedHp;//カードのhpのタネ
	int SeedAtack;//カードの攻撃力のタネ
	int SeedGuard;//カードの防御力のタネ

	int Type;//カードの種類

	bool CardHitCheck;//マウスがカードと触れているか参照する変数
	int Opdraw;//カードの切取り位置１
	int Updraw;//カードの切取り位置２
	int Rotdraw;//カードの角度調整

	//武器の位置を保存
	bool LWeapon;
	bool RWeapon;

	//モンスターの位置を保存
	bool FSummon;
	bool FSummon2;

	bool Punch;//モンスターの攻撃制御
	bool Set;//武器の装備制御

	bool m_r;
	bool Summon;//カードが召喚されたかどうか
	bool StopSm;//カードの召喚制御用
	bool m_f;
	bool m_l;

	int test;

	bool L_position;

	bool S_position;
	bool S_position2;

	bool R_position;

	//コストを一旦保存
	int m_kos;
};