#pragma once

#include"GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

class CObjCardlist : public CObj
{
	public:
		CObjCardlist() {};
		~CObjCardlist() {};
		void Init();
		void Action();
		void Draw();

	private:
		int Cardlist[50];
};