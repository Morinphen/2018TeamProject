//�g�p����w�b�_�[
#include "GameL\DrawFont.h"
#include"GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include"GameL\Audio.h"

#include "GameHead.h"
#include "ObjClear.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjClear::Init()
{
	m_key_flag = true;
	gc = false;
	t_t = -500.0f;
	t_b = -328.0f;
	cou = 0;
	i = 0;
	j = 0;


	Audio::LoadAudio(10, L"Audio\\����.wav", BACK_MUSIC);
	Audio::LoadAudio(12, L"Audio\\�h��.wav", EFFECT);


	Audio::Start(10);
}

//�A�N�V����
void CObjClear::Action()
{
	CObjmouse*mou = (CObjmouse*)Objs::GetObj(OBJ_MAUSE);

	m_l = Input::GetMouButtonL();


	//�X�y�[�X�L�[�������ƃV�[���ύX
	if (m_l == true)
	{
		if (mou->m_mouse_x > 360 && mou->m_mouse_x < 770
			&& mou->m_mouse_y > 500 && mou->m_mouse_y < 540
			&& BGM == true)
		{
			Scene::SetScene(new CSceneTitle());
		}
	}
	if (t_t < 500 && t_b < 500)
	{
		t_t += 4.0f;

		t_b += 4.0f;
		i++;
	}

	if (i == 207)
	{
		Audio::Start(12);
		i++;
		gc = true;
	}

	if (gc == true)
	{
		for (j = 0; j < 15000; j++)
		{
			if (j == 14999)
				BGM = true;
		}
	}
}

//�h���[
void CObjClear::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;
	RECT_F dst;

	src.m_top = 130.0f;
	src.m_left = 201.0f;
	src.m_right = 388.0f;
	src.m_bottom = 180.0f;

	dst.m_top = t_t;
	dst.m_left = 310.0f;
	dst.m_right = 1010.0f;
	dst.m_bottom = t_b;

	Draw::Draw(3, &src, &dst, c, 0);

	if (BGM == true)
		Font::StrDraw(L"�������N���b�N�Ń^�C�g���ɖ߂�", 340, 500, 42, c);


}