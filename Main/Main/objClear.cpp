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

	Audio::LoadAudio(10, L"Audio\\����.wav", BACK_MUSIC);

	Audio::Start(10);
}

//�A�N�V����
void CObjClear::Action()
{
	//�X�y�[�X�L�[�������ƃV�[���ύX
	if (Input::GetVKey(VK_SPACE))
	{
		if (m_key_flag == true)
		{
			m_key_flag = false;
			Scene::SetScene(new CSceneTitle());
		}
	}
}

//�h���[
void CObjClear::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;
	RECT_F dst;
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 1013.0f;
	src.m_bottom = 685.0f;

	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 1200.0f;
	dst.m_bottom = 900.0f;

	Draw::Draw(6, &src, &dst, c, 0.0f);

	Font::StrDraw(L"You Win", 430, 220, 32, c);
	Font::StrDraw(L"�������N���b�N�Ń^�C�g���ɖ߂�", 410, 500, 32, c);
}