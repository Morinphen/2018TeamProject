//�V���E�X���w�b�_�[�t�@�C��
#include"GameL\DrawTexture.h"
#include"GameHead.h"
#include"Card.h"

//�g�p����l�[���X�y�[�X
CObjCard::CObjCard(float x,float y)
{
	m_x = x;
	m_y = y;
	test = 0;
}

//�C�j�V�����C�Y
void CObjCard::Init()
{
	CObjDekc*sc = (CObjDekc*)Objs::GetObj(OBJ_DEKC);
	bango = sc->cardcou;

	
}

//�A�N�V����
void CObjCard::Action()
{
	CObjDekc*sc = (CObjDekc*)Objs::GetObj(OBJ_DEKC);
	basyo = sc->cardcou;

	genba = basyo - bango;

	if (genba == 0) {

		if (bango == 1) {
			;
		}
		else {
			m_x = 400;
		}

		test = 0;
	}
	else {
		m_x = 400 - (genba * 50);
	}
}

//�h���[
void CObjCard::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;
	src.m_top = 0.0f;
	src.m_left = 64.0f + (64.0f*test);
	src.m_right = 128.0f + (64.0f*test);
	src.m_bottom = 64.0f;

	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x;
	dst.m_right = 128.0f + m_x;
	dst.m_bottom = 192.0f + m_y;

	Draw::Draw(0, &src, &dst, c, 0.0f);
}