//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\HitBoxManager.h"
#include"GameL\DrawTexture.h"
#include"GameHead.h"
#include"mouse.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjmouse::Init()
{
	m_mouse_x = 0.0f;//�}�E�X��X���W
	m_mouse_y = 0.0f;//�}�E�X��Y���W

	//�����蔻��쐬
	Hits::SetHitBox(this, m_mouse_x, m_mouse_y, 32, 32, ELEMENT_PLAYER, OBJ_PLAYER, 1);
}

//�A�N�V����
void CObjmouse::Action()
{
	//�}�E�X���W�擾
	m_mouse_x =(float) Input::GetPosX() - 16.0f;
	m_mouse_y =(float) Input::GetPosY() - 16.0f;

	//�����蔻��X�V
	CHitBox*hit = Hits::GetHitBox(this);
	hit->SetPos(m_mouse_x, m_mouse_y);
}

//�h���[
void CObjmouse::Draw()
{
	//�F
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	//----------------------------------------------------
	//�}�E�X���W�̒l�`��(�e�X�g�p�Ȃ̂ł̂��ɏ����\��)
	wchar_t str[128];
	swprintf_s(str, L"x:%f", m_mouse_x);
	Font::StrDraw(str,100,100,20,c);

	swprintf_s(str, L"y:%f", m_mouse_y);
	Font::StrDraw(str, 100, 120, 20, c);

	//----------------------------------------------------


	//----------------------------------------------------
	//�|�C���^�`��
	//�J�[�h�̑傫���͉��R�A�c�S�ɂ���
	RECT_F src;
	RECT_F dst;
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 64.0f;
	src.m_bottom = 64.0f;

	dst.m_top = 0.0f + m_mouse_y;
	dst.m_left = 0.0f + m_mouse_x;
	dst.m_right = dst.m_left + 32.0f;
	dst.m_bottom = dst.m_top + 32.0f;

	Draw::Draw(0, &src, &dst, c, 0.0f);
}