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

		bool Touch;//�����̃J�[�h�ɐG�ꂽ�ꍇtrue�ɂȂ�
		bool Wtouch;//��D�̕����I�������ꍇtrue�ɂȂ�

		int Choice[3];//�����̃J�[�h�ɐG�ꂽ�Ƃ��̕ϐ�

		//�G�̃J�[�h�ɐG�ꂽ�Ƃ��̕ϐ�
		bool EChoice;
		bool EChoice2;
		bool EChoice3;

		float m_mouse_x;//�}�E�X��X���W
		float m_mouse_y;//�}�E�X��Y���W

	private:

};