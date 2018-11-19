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

		bool L_position, L_position2, L_position3;
		bool S_position,S_position2;
		bool R_position, R_position2, R_position3;
		bool m_f;

		int PCard[4], PCard2[4], PCard3[4];
		int ECard[4], ECard2[4], ECard3[4];
	private:

};