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

	private:
		float m_mouse_x;
		float m_mouse_y;
};