#pragma once

#include"GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�}�b�v
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