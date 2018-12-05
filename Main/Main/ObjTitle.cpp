//�g�p����w�b�_�[
#include "GameL\DrawFont.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"

#include "GameHead.h"
#include "ObjTitle.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjTitle::Init()
{
	m_key_flag = false;
}

//�A�N�V����
void CObjTitle::Action()
{
	
	//S�L�[�������ƃV�[���ύX
	if (Input::GetVKey('S'))
	{
		m_key_flag = true;

		if (m_key_flag == true)
		{
			Scene::SetScene(new CSceneMain());
			m_key_flag = false;
		}
	}
	else if (Input::GetVKey('E'))
	{
		if (m_key_flag == false)
		{
			m_key_flag = true;
			exit(0);		//E�L�[�ŏI������			
		}
		else
		{
			m_key_flag = false;
		}
	}
}

//�h���[
void CObjTitle::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	Font::StrDraw(L"Arma Batlle",430, 220, 32, c);

	Font::StrDraw(L"Push'S'Key", 430, 400, 32, c);
	Font::StrDraw(L"Exit 'E'Key", 410, 500, 32, c);
}