#pragma once
#include"GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト　カード
class CObjCard :public CObj
{
public:
	CObjCard(float x,float y,int z);
	~CObjCard() {};
	void Init();
	void Action();
	void Draw();

	bool Punch;//モンスターの攻撃
	bool Pusave;//モンスターの攻撃制御
	bool Set;//武器の装備制御

	int Bat;
	int Bat2;
	 
private:
	void Cardname();
	void Effect(float _Cnanber,bool *When,bool *Play,bool *Indu,int Position);
	void Wwindow(bool *_set,bool _delete);

	int m_x, m_y;//カードの描画位置
	int Setcard;//カードの場所
	int Posicard;//カードの場所２
	int Number;//順番の固定
	int Number2;//手札のカード番号
	int Number3;//カードの順番番号
	int Number4;//カード情報番号

	int Hp;//カードのhp
	int Atack;//カードの攻撃力
	int Guard;//カードの防御力
	int Ccost;//カードのコスト
	bool Wstop;//武器の装備制御変数
	int WSetting;//武器を装備した際に決める変数

	int TextD;//テキストデータ保存用変数
	int NTcard;//カードデータ番号
	int Cadata;//データ番号保存用変数

	bool WhenEfe;//召喚時効果変数
	bool PlayEfe;//起動効果変数
	bool InduEfe;//誘発効果変数

	int playertrun;
	int enemytrun;

	int Type;//カードの種類　1=キャラ,2=武器,3=防具

	//カードテキストの表示
	char *Name;
	char *Text;
	char text[256];
	int Tlong;

	bool CardHitCheck;//マウスがカードと触れているか参照する変数
	int Opdraw;//カードの切取り位置１
	int Updraw;//カードの切取り位置２
	int Rotdraw;//カードの角度調整

	bool Button;//ボタン用変数
	int BDraw;//ボタンdraw用変数
	//ボタン用表示位置
	float b_x;
	float b_y;

	//ウィンドウ用変数
	bool Wset;
	bool LDcard;
	bool RDcard;
	int WLcard;
	int WRcard;
	int WLupdraw;
	int WRupdraw;
	int Wcount;

	//モンスターの位置を保存
	bool FSummon;
	bool FSummon2;

	//武器の位置を保存
	bool LWeapon;
	bool RWeapon;

	bool Summon;//カードが召喚されたかどうか
	bool StopSm;//カードの召喚制御用

	bool m_f;
	bool m_l;
	bool m_c; //クリック長押し制御

	int test;

	//bool L_position;

	bool S_position;
	bool S_position2;

	//bool R_position;

	//コストを一旦保存
	int m_kos;
};