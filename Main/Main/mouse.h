#pragma once

#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�}�E�X
class CObjmouse : public CObj
{
	public:
		CObjmouse(){};
		~CObjmouse(){};
		void Init();
		void Action();
		void Draw();

		bool m_r;
		bool m_f;

		bool EChoice;

	private:
		float m_mouse_x;//�}�E�X��X���W
		float m_mouse_y;//�}�E�X��Y���W

};