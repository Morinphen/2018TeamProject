#pragma once

#include"GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクト：マップ
class CObjMap : public CObj
{
	public:
		CObjMap() {};
		~CObjMap() {};
		void Init();
		void Action();
		void Draw();

		//場にモンスターが出ているか判断する変数
		bool S_position, S_position2;

		bool ES_position, ES_position2;

		bool L_position;
		bool R_position;

		bool m_f;

		bool PTrun;

		//ウィンドウが出ているか判断する変数
		bool WiSummon;

		//カードテキスト表示用文字列
		char name[256];
		char text2[5][64];

		bool Wtouch;//武器がクリックされたとき、オンになる

		bool WSummon;//武器が召喚されたとき、オンになる
		int Cooltime;//様々な物が召喚されたときに使用するクールタイム用変数

		//Pcard[0][i]=主人公の情報,Pcard[1][i]=右の味方の情報,Pcard[2][i]=左の味方の情報
		//Pcard[i][0]=HP,Pcard[i][1]=ATACK,Pcard[i][2]=Guard,Pcard[i][3]=モンスター番号,Pcard[i][4]=武器のHP1,Pcard[i][5]=武器のナンバーその1,Pcard[i][6]=武器のHP2,Pcard[i][7]=武器のナンバーその2
		int PCard[3][8];//プレイヤーのカード情報

		int WPosition[6];//プレイヤーの武器の場所情報

		//敵のカード情報（仮）
		int ECard[8];
		int	ECard2[8];
		int	ECard3[8];

		int EAtackt;
	private:

};