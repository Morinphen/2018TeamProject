//�g�p����w�b�_�[
#include "GameL\DrawFont.h"
#include"GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include"GameL\Audio.h"

#include "GameHead.h"
#include "ObjGameover.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjGameover::Init()
{

	m_key_flag = true;

	Audio::LoadAudio(9, L"Audio\\�s�k.wav", BACK_MUSIC);

	Audio::Start(9);
}

//�A�N�V����
void CObjGameover::Action()
{
	CObjmouse*mou = (CObjmouse*)Objs::GetObj(OBJ_MAUSE);

	m_l = Input::GetMouButtonL();

	//�N���b�N�ŃV�[���ύX
	if (m_l == true)
	{
		if (mou->m_mouse_x > 564 && mou->m_mouse_x < 1014
			&& mou->m_mouse_y > 550 && mou->m_mouse_y < 580)
		{
			Scene::SetScene(new CSceneTitle());
		}
	}
}

//�h���[
void CObjGameover::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;
	RECT_F dst;
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 640.0f;
	src.m_bottom = 480.0f;

	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 1200.0f;
	dst.m_bottom = 900.0f;

	Draw::Draw(5, &src, &dst, c, 0.0f);

	Font::StrDraw(L"�������N���b�N�Ń^�C�g���ɖ߂�", 564, 550, 30, c);
}