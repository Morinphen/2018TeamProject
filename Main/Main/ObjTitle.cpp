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
	
	//�G���^�[�L�[�������ƃV�[���ύX
	if (GetKeyState(VK_UP))
	{
		m_key_flag = true;

		if (m_key_flag == true)
		{
			Scene::SetScene(new CSceneMain());
			m_key_flag = false;
		}
	}
	else if (GetKeyState(VK_SPACE))
	{
		exit(0);//�X�y�[�X�L�[�ŃQ�[�����I������
	}

}

//�h���[
void CObjTitle::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	Font::StrDraw(L"Arma Batlle",310, 220, 32, c);

	Font::StrDraw(L"PushRightclick", 300, 400, 32, c);
	Font::StrDraw(L"�I������ɂ̓X�y�[�X�L�[�������Ă�������", 200, 500, 32, c);
}