#pragma once

#include"GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

class CObjCardlist
{
	public:
		CObjCardlist() {};
		~CObjCardlist() {};
		void Init();
		int Action(int x,int y,int a);
		void Draw();

	private:
		//int Cardlist[50];
};