//�V���E�X���w�b�_�[�t�@�C��
#include"GameL\DrawTexture.h"
#include"GameHead.h"
#include"testmau.h"
#include"GameL\WinInputs.h"
#include"GameL\HitBoxManager.h"
#include"GameL\DrawFont.h"
#include<stdlib.h>
#include<time.h>
//�g�p����l�[���X�y�[�X

//�C�j�V�����C�Y
void CObjMau::Init()
{
	m_x = 0;
	m_y = 0;
	Hits::SetHitBox(this, m_x, m_y, 32, 32, ELEMENT_PLAYER, OBJ_PLAYER, 1);
}

//�A�N�V����
void CObjMau::Action()
{
	m_x = (float)Input::GetPosX() - 32.0f;
	m_y = (float)Input::GetPosY() - 32.0f;

	CHitBox*hit = Hits::GetHitBox(this);
	hit->SetPos(m_x, m_y);
}

//�h���[
void CObjMau::Draw()
{
	//�J�[�h�̑傫���͉��R�A�c�S�ɂ���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 64.0f;
	src.m_bottom = 64.0f;

	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x;
	dst.m_right = 32.0f + m_x;
	dst.m_bottom = 32.0f + m_y;

	Draw::Draw(0, &src, &dst, c, 0.0f);
}