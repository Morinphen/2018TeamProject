#pragma once

#include"GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
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