//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameHead.h"
#include"mouse.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjmouse::Init()
{
	m_mouse_x = 0.0f;
	m_mouse_y = 0.0f;
}

//�A�N�V����
void CObjmouse::Action()
{
	m_mouse_x =(float) Input::GetPosX();
	m_mouse_y =(float) Input::GetPosY();
}

//�h���[
void CObjmouse::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	wchar_t str[128];
	swprintf_s(str, L"x:%f", m_mouse_x);
	Font::StrDraw(str,100,100,20,c);

	swprintf_s(str, L"y:%f", m_mouse_y);
	Font::StrDraw(str, 100, 120, 20, c);
}