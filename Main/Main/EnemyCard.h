#pragma once
#include"GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト　デッキ
class CObjEnemyCard :public CObj
{
public:
	CObjEnemyCard(float x, float y, float z);
	~CObjEnemyCard() {};
	void Init();
	void Action();
	void Draw();

private:
	void Cardname();

	bool Atacks;//攻撃制御用変数
	//状況によって敵、味方のステータスを格納する配列
	int Hpbox[3];
	int GetAtackbox[3];
	int GetGuardbox[3];
	int Guardbox[3];

	int AtackUnit;//攻撃対象用変数
	int Dameg;//与ダメージ用変数
	int UpAtack;//あげる攻撃用変数
	int UpUnit;//装備をさせるユニット変数

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

	//カードの装備情報確認変数
	bool R_soubi;
	bool R_soubi2;
	bool L_soubi;
	bool L_soubi2;

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

	int TextD;//テキストデータ保存用変数
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

	int Type;
};