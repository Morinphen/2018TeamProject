#pragma once

#include"GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
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