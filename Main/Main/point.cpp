#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\DrawFont.h"

#include "GameHead.h"
#include "point.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�f�X�g���N�^
CObjpoint::CObjpoint()
{

};

CObjpoint::~CObjpoint()
{

};

//�C�j�V�����C�Y
void CObjpoint::Init()
{
	m_point = 0;
	m_flag_point = false;
	m_p=true;
};

//�A�N�V����
void CObjpoint::Action()
{
	if (Input::GetVKey('P') == true)
	{
		if (m_p == true)
		{
			m_point++;
			m_p = false;
		}
	}
	else
	{
		m_p = true;
	}

};

//�h���[
void CObjpoint::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	wchar_t str[128];

	swprintf_s(str, L"%d", m_point);

	Font::StrDraw(str, 10, 10, 20, c);
};
