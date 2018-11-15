//�V���E�X���w�b�_�[�t�@�C��
#include"GameL\DrawTexture.h"
#include"GameL\HitBoxManager.h"
#include"GameL\WinInputs.h"
#include"GameHead.h"
#include"Card.h"

#include"GameL\DrawFont.h"

//�g�p����l�[���X�y�[�X
CObjCard::CObjCard(float x,float y,int z)
{
	m_x = x;
	m_y = y;
	Type = z;//�J�[�h�̎�ނɂ���ă^�C�v��ς���
}

//�C�j�V�����C�Y
void CObjCard::Init()
{
	CObjDekc*sc = (CObjDekc*)Objs::GetObj(OBJ_DEKC);
	CObjHand*han = (CObjHand*)Objs::GetObj(OBJ_HAND);
	Nanber = sc->Cnanber;//�������J�[�h�̏��Ԃ̌Œ�
	Nanber2 = han->hand[Nanber-1];//�J�[�h�ԍ��̕ۑ�
	Nanber3 = han->basyo[Nanber - 1];//��D�̏��ԕϐ�

	Opdraw = sc->Card;//�J�[�h�ԍ��̕ۑ�
	Updraw = 0;//�J�[�h�̕`��ʒu�̒���
	Rotdraw = 0;//�J�[�h�̉�]�`�撲��

	Hp = 0;
	Atack = 0;
	Guard = 0;

	FSummon = false;
	FSummon2 = false;

	test = 1;
	Punch = false;

	Summon = false;

	while(Opdraw>7)
	{
		Opdraw -= 7;//x�ʒu�����炷
		Updraw++;
	}
	m_f = false;

	Hits::SetHitBox(this, m_x, m_y, 90, 120, ELEMENT_CARD, OBJ_CARD, 1);
}

//�A�N�V����
void CObjCard::Action()
{
	m_l = Input::GetMouButtonL();
	CHitBox*hit = Hits::GetHitBox(this);
	CObjmouse*mou = (CObjmouse*)Objs::GetObj(OBJ_MAUSE);
	CObjHand*han = (CObjHand*)Objs::GetObj(OBJ_HAND);
	CObjDekc*sc = (CObjDekc*)Objs::GetObj(OBJ_DEKC);
	CObjMap* pos = (CObjMap*)Objs::GetObj(OBJ_MAP);

	if (m_l == true)
	{
		if (mou->EChoice==false)
		{
			test = 1;
			Punch = false;
		}

		else if(mou->EChoice==true && Punch==true)
		{
			pos->ECard[0] -= Atack;
			if (FSummon == true) {
				pos->PCard2[0] -= pos->ECard[1];
			}
			else
			{
				pos->PCard3[0] -= pos->ECard[1];
			}
			test = 1;
			Punch = false;
		}

	}

	Setcard = sc->Cnanber;//�J�[�h�̈ʒu�����ύX�p

	Posicard = Setcard - Nanber;//�J�[�h�̈ʒu�����ύX�p�Q
	/*if (Nanber - Reset > 0 && Reset != 0 && Reset > 0)
	{
		Reflag = true;
		han->hensu -= 1;
	}

	if (Reflag == true)
	{
		Nanber3 = Nanber3;
		Nanber--;
		Reflag = false;
	}*/

	if (Nanber3 - han->hensu3 > 0 && han->hensu>0)//���݂̏ꏊ���o�����J�[�h������̏ꍇ�A�ЂƂ��炷
	{
		Nanber--;//�ԍ����P���炷
		han->hensu2++;
	}

	Nanber3 = han->basyo[Nanber - 1];//��D�̏ꏊ���X�V

	L_position = pos->L_position;
	L_position2 = pos->L_position2;
	L_position3 = pos->L_position3;

	S_position = pos->S_position;
	S_position2 = pos->S_position2;

	R_position = pos->R_position;
	R_position2 = pos->R_position2;
	R_position3 = pos->R_position3;
	
	if(Setcard <=5 && Summon == false)
	{
		//m_x = 250+(90* Posicard);
		for (int i = 0; i < Setcard; i++)
		{
			if (han->hand[i] == Nanber2)
			{
				m_x = 250 + (90 * i);
			}
		}
	}

	else if(Summon == false){
		for (int i = 0; i < Setcard; i++)
		{
			if (han->hand[i] == Nanber2)
			{
				m_x = 250 + ((450 / (Setcard))*Posicard);
			}
		}
	}

	if (hit->CheckObjNameHit(OBJ_PLAYER) != nullptr && Summon == false)
	{
		Rotdraw = 3;//�J�[�h���R����]
		SetPrio(11);//�J�[�h�̕`��D��x�ύX
		if (mou->m_r == true)
		{
			if (pos->m_f == false) {
				CObjCardlist* List = new CObjCardlist();//�֐��Ăяo��
				CObjMCardlist* Mlist = new CObjMCardlist();//�֐��Ăяo���Q

				Summon = true;
				han->hand[Nanber3 - 1] = 0;//�o�����J�[�h�̃J�[�h�ԍ����폜
				han->basyo[Nanber3 - 1] = 0;//�o�����J�[�h�̏ꏊ�����폜
				han->hensu = Setcard - Nanber3;//��D�̍��v�Əo�����J�[�h�̍�����ۑ�
				han->hensu3 = Nanber3;//�o�����J�[�h�̏ꏊ��ۑ�
				sc->Cnanber -= 1;//�J�[�h�̍��v�������P���炷
				pos->m_f = true;

				if (L_position == false && Type == 2)
				{
					Atack = List->Action(Type, Nanber, Atack);//�J�[�h�ԍ��ɉ����čU���͕ϓ�
					m_x = 200;
					m_y = 200;

					pos->L_position = true;

					delete List;
					hit->SetPos(m_x, m_y);
				}
				else if (S_position == false && Type == 1 || S_position2 == false && Type == 1)
				{
					Hp = List->Action(Type, Nanber, Hp);//�J�[�h�ԍ��ɉ�����HP�ϓ�
					Atack = Mlist->Action(Nanber, Atack);//�J�[�h�ԍ��ɉ����čU���͕ϓ�

					if (S_position == false) {
						m_x = 200;
						m_y = 500;
						pos->PCard2[0] = Hp;
						pos->PCard2[1] = Atack;
						pos->PCard2[3] = Opdraw + Updraw * 7;
						pos->S_position = true;
						FSummon = true;
					}
					else {
						m_x = 700;
						m_y = 500;
						pos->PCard3[0] = Hp;
						pos->PCard3[1] = Atack;
						pos->PCard3[3] = Opdraw + Updraw * 7;
						pos->S_position2 = true;
						FSummon2 = true;
					}

					delete List;
					hit->SetPos(m_x, m_y);
				}
				else if (R_position == false && Type == 3)
				{
					Guard = List->Action(Type, Nanber, Guard);//�J�[�h�ԍ��ɉ����Ď���͕ϓ�
					m_x = 600;
					m_y = 200;

					pos->R_position = true;

					delete List;
					hit->SetPos(m_x, m_y);
				}
				else
				{
					m_x = 0;
					m_y = 0;
					hit->SetPos(m_x, m_y);

					Summon = false;
				}
			}
		}
		else
		{
			pos->m_f = false;
		}
	}

	else if (hit->CheckObjNameHit(OBJ_PLAYER) != nullptr && Summon == true && Type==1)
	{
		Rotdraw = -3;
		SetPrio(11);
		if (m_l == true)
		{
			test = 0;
			Punch = true;
		}
	}
	else
	{
		Rotdraw = 0;
		SetPrio(10);
	}

	if (Summon == true)
	{
		if (FSummon == true)
		{
			Hp = pos->PCard2[0];
		}
		else
		{
			Hp = pos->PCard3[0];
		}

		if (Hp <= 0)
		{
			this->SetStatus(false);
			Hits::DeleteHitBox(this);
		}
	}

	hit->SetPos(m_x, m_y);
}

//�h���[
void CObjCard::Draw()
{
	float c[4] = { 1.0f,test,1.0f,1.0f };
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