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
void CObjGameover::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	Font::StrDraw(L"�������`���b�^", 430, 220, 32, c);
	Font::StrDraw(L"�X�y�[�X�L�[�Ń^�C�g���ɖ߂�", 410, 500, 32, c);
}