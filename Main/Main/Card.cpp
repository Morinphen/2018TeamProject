//�V���E�X���w�b�_�[�t�@�C��
#include"GameL\DrawTexture.h"
#include"GameL\HitBoxManager.h"
#include"GameHead.h"
#include"Card.h"

#include"GameL\DrawFont.h"

//�g�p����l�[���X�y�[�X
CObjCard::CObjCard(float x,float y)
{
	m_x = x;
	m_y = y;
}

//�C�j�V�����C�Y
void CObjCard::Init()
{
	CObjDekc*sc = (CObjDekc*)Objs::GetObj(OBJ_DEKC);
	Nanber = sc->Cnanber;//bango �������J�[�h�̏��Ԃ̌Œ�

	Opdraw = sc->Card;//test �J�[�h�ԍ��̕ۑ�
	Updraw = 0;//taka �J�[�h�̕`��ʒu�̒���
	Rotdraw = 0;//test2 �J�[�h�̉�]�`�撲��

	while(Opdraw>7)
	{
		Opdraw -= 7;
		Updraw++;
	}

	Hits::SetHitBox(this, m_x, m_y, 90, 120, ELEMENT_CARD, OBJ_CARD, 1);
}

//�A�N�V����
void CObjCard::Action()
{
	CHitBox*hit = Hits::GetHitBox(this);

	CObjDekc*sc = (CObjDekc*)Objs::GetObj(OBJ_DEKC);

	Setcard = sc->Cnanber;//basyo �J�[�h�̈ʒu�����ύX�p

	Posicard = Setcard - Nanber;//genba �J�[�h�̈ʒu�����ύX�p�Q

	if(Setcard <=5)
	{
		m_x = 250+(90* Posicard);
	}

	else{

		m_x = 250 + ((450 / (Setcard))*Posicard);

	}

	if (hit->CheckObjNameHit(OBJ_PLAYER) != nullptr)
	{
		Rotdraw = 3;//�J�[�h���R����]
		SetPrio(11);//�J�[�h�̕`��D��x�ύX
	}
	else
	{
		Rotdraw = 0;
		SetPrio(10);
	}

	hit->SetPos(m_x, m_y);
}

//�h���[
void CObjCard::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;
	src.m_top = 0.0f+ (64.0f*Updraw);
	src.m_left = 0.0f + (64.0f*Opdraw);
	src.m_right = 64.0f + (64.0f*Opdraw);
	src.m_bottom = 64.0f+ (64.0f*Updraw);

	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x;
	dst.m_right = 90.0f + m_x;
	dst.m_bottom = 120.0f + m_y;

	Draw::Draw(0, &src, &dst, c, Rotdraw);
}