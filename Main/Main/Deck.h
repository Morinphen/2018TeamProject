#pragma once

#include"GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

enum type {
	monster = 1,
	weapon = 2,
	shield = 3,
	item = 4,
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
	int Deck[40];//デッキの中のカード配列
	int Pullc[40];

	int m_point;
	int p_point; //ターン終了時の所持ゴールドを一時保存する変数
	int Cost;
	bool Turn;
	bool STurn;
	bool AddCostDisplay; //ゴールド追加演出をする変数
	bool Start;//初期手札補充用変数
	bool StartG;//ゲーム開始用変数

	bool Button2;//ボタン出現用変数

	int i;

	bool effect;//カードの効果変数
	bool go;
private:
	int x, y;
	int m_x, m_y;
	bool m_l; //マウスのクリック判定
	bool m_c; //マウス押しっぱなしのまま反応しないように制御する変数
	int Ctype;//カードの種類

	int Deckcount; //デッキの残り枚数を参照する変数
	int Cardcount; //引いたカードの合計
	int stop;
	int Data;//デッキに登録するカードデータ

	bool m_f;
	bool m_f2;
	bool m_flag_point;
	bool r_f;

	int DrawButton_y; //ドローボタンのy軸座標
	int DrawButton_time; //ドローボタンの時間制御
	//int TurnCount; //現在のターン数を表示するための変数
};