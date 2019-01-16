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

	bool Punch;//モンスターの攻撃制御
	bool Set;//武器の装備制御

private:
	int m_x, m_y;//カードの描画位置
	int Setcard;//カードの場所
	int Posicard;//カードの場所２
	int Number;//順番の固定
	int Number2;//手札のカード番号
	int Number3;//カードの順番番号
	int Number4;//カード情報番号
	int playertrun;
	int enemytrun;

	int Hp;//カードのhp
	int Atack;//カードの攻撃力
	int Guard;//カードの防御力

	//カードテキストの表示
	char *Name;
	char *Text;
	char name[256];
	char text[256];
	char text2[5][64];
	int Tlong;

	//ダミーデータ
	int aaaa;
	int Nlist;

	int Type;//カードの種類　1=キャラ,2=武器,3=防具

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