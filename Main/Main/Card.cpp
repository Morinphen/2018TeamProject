//�V���E�X���w�b�_�[�t�@�C��
#include"GameL\DrawTexture.h"
#include"GameL\HitBoxManager.h"
#include"GameL\WinInputs.h"
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

	Summon = false;

	while(Opdraw>7)
	{
		Opdraw -= 7;//x�ʒu�����炷
		Updraw++;
	}

	Hits::SetHitBox(this, m_x, m_y, 90, 120, ELEMENT_CARD, OBJ_CARD, 1);
}

//�A�N�V����
void CObjCard::Action()
{
	m_r = Input::GetMouButtonR();

	CHitBox*hit = Hits::GetHitBox(this);

	CObjDekc*sc = (CObjDekc*)Objs::GetObj(OBJ_DEKC);

	Setcard = sc->Cnanber;//basyo �J�[�h�̈ʒu�����ύX�p

	Posicard = Setcard - Nanber;//genba �J�[�h�̈ʒu�����ύX�p�Q

	CObjMap* pos = (CObjMap*)Objs::GetObj(OBJ_MAP);
	L_position = pos->L_position;
	S_position = pos->S_position;
	R_position = pos->R_position;
	
	if(Setcard <=5 && Summon == false)
	{
		m_x = 250+(90* Posicard);
	}

	else if(Summon == false){

		m_x = 250 + ((450 / (Setcard))*Posicard);
	}

	if (hit->CheckObjNameHit(OBJ_PLAYER) != nullptr && Summon == false)
	{
		Rotdraw = 3;//�J�[�h���R����]
		SetPrio(11);//�J�[�h�̕`��D��x�ύX
		if (m_r == true)
		{
			Summon = true;

			if (L_position == false && S_position == false && R_position == false)
			{
				m_x = 200;
				m_y = 200;

				pos->L_position = true;

				hit->SetPos(m_x, m_y);
			}
			else if (L_position == true && S_position == false && R_position == false)
			{
				m_x = 400;
				m_y = 200;

				pos->S_position = true;

				hit->SetPos(m_x, m_y);
			}
			else if (L_position == true && S_position == true && R_position == false)
			{
				m_x = 600;
				m_y = 200;

				pos->R_position = true;

				hit->SetPos(m_x, m_y);
			}
			else
			{
				hit->SetPos(m_x, m_y);

				Summon = false;
			}
		}
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