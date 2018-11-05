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

		bool L_position;
		bool S_position;
		bool R_position;
	private:

};