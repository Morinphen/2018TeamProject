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
	void Cardname();

	int m_x, m_y;
	int Setcard;
	int Number;
	int Number2;
	int Number3;
	int Number4;
	int Posicard;
	int Reset;
	int playertrun;
	int enemytrun;

	bool R_Summon;
	bool L_Summon;

	int aaaa;

	int Hp;//カードのhp
	int Atack;//カードの攻撃力
	int Guard;//カードの防御力
	int Hp2;//カードの元々のhp
	int Atack2;//カードの元々の攻撃力
	int Guard2;//カードの元々の防御力
	int Ccost;//カードのコスト

	int Tlong;

	bool CardHitCheck;//マウスがカードと触れているか参照する変数

	//カードテキストの表示
	char *Name;
	char *Text;
	char text[256];
	int Tlong;

	int TextD;//テキストデータ保存用変数
	int Ccost;//カードのコスト
	int NTcard;//カードデータ番号

	int Shand;

	int Opdraw;
	int Updraw;
	int Rotdraw;

	bool m_r;
	bool Summon;
	bool StopSm;
	bool m_f;
	bool Reflag;

	bool L_position;
	bool S_position;
	bool R_position;

	int Type;//カードの種類　1=キャラ,2=武器,3=防具
};