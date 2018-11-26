//�V���E�X���w�b�_�[�t�@�C��
#include"GameL\DrawTexture.h"
#include"GameL\HitBoxManager.h"
#include"GameL\WinInputs.h"
#include"GameHead.h"
#include"EnemyCard.h"

#include"GameL\DrawFont.h"

//�g�p����l�[���X�y�[�X
CObjEnemyCard::CObjEnemyCard(float x, float y)
{
	m_x = x;
	m_y = y;
}

//�C�j�V�����C�Y
void CObjEnemyCard::Init()
{
	CObjEnemyDeck*sc = (CObjEnemyDeck*)Objs::GetObj(OBJ_ENEMY_DECK);
	CObjEnemyHand*han = (CObjEnemyHand*)Objs::GetObj(OBJ_ENEMY_HAND);
	Nanber = sc->Cnanber;//bango �������J�[�h�̏��Ԃ̌Œ�
	Nanber2 = han->hand[Nanber - 1];
	Nanber3 = Nanber;

	Opdraw = sc->e_Card;//test �J�[�h�ԍ��̕ۑ�
	Updraw = 0;//taka �J�[�h�̕`��ʒu�̒���
	Rotdraw = 0;//test2 �J�[�h�̉�]�`�撲��

	Summon = false;
	Shand = 0;

	while (Opdraw>7)
	{
		Opdraw -= 7;//x�ʒu�����炷
		Updraw++;
	}
	m_f = false;

	CObjMap* pos = (CObjMap*)Objs::GetObj(OBJ_MAP);

	Hits::SetHitBox(this, m_x, m_y, 90, 120, ELEMENT_ENEMY, OBJ_ENEMY_CARD, 1);
}

//�A�N�V����
void CObjEnemyCard::Action()
{
	Rotdraw = 180;//�J�[�h��180����]
	CObjmouse*mou = (CObjmouse*)Objs::GetObj(OBJ_MAUSE);
	CObjEnemyHand*han = (CObjEnemyHand*)Objs::GetObj(OBJ_ENEMY_HAND);
	CObjEnemyDeck*sc = (CObjEnemyDeck*)Objs::GetObj(OBJ_ENEMY_DECK);

	CHitBox*hit = Hits::GetHitBox(this);

	Setcard = sc->Cnanber;//Setcard �J�[�h�̈ʒu�����ύX�p

	Posicard = Setcard - Nanber;//Posicard �J�[�h�̈ʒu�����ύX�p�Q

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

	if (Nanber - han->hensu > 0)
	{
		Nanber2 = han->basyo[Nanber - Shand];
	}

	CObjMap* pos = (CObjMap*)Objs::GetObj(OBJ_MAP);
	L_position = pos->L_position;
	S_position = pos->S_position;
	R_position = pos->R_position;

	if (Setcard <= 5 && Summon == false)
	{
		//m_x = 250+(90* Posicard);
		for (int i = 0; i < Setcard; i++)
		{
			if (han->hand[i] == Nanber2)
			{
				m_x = 927 - (90 * i);
			}
		}
	}

	else if (Summon == false) {
		for (int i = 0; i < Setcard; i++)
		{
			if (han->hand[i] == Nanber2)
			{
				m_x = 567 + ((450 / (Setcard))*Posicard);
			}
		}
	}

	if (Nanber < 4 && Summon==false)
	{
		Summon = true;
		//han->hand[Nanber3 - 1] = 0;//�o�����J�[�h�̃J�[�h�ԍ����폜
		//han->basyo[Nanber3 - 1] = 0;//�o�����J�[�h�̏ꏊ�����폜
		//han->hensu = Setcard - Nanber3;//��D�̍��v�Əo�����J�[�h�̍�����ۑ�
		//han->hensu3 = Nanber3;//�o�����J�[�h�̏ꏊ��ۑ�
		//sc->Cnanber -= 1;//�J�[�h�̍��v�������P���炷
		pos->m_f = true;
		//���u���̓G�����@��D�̏��Ԃ��P�C�Q�C�R�̃J�[�h������
		if (Nanber == 1) {
			m_x = 543;
			m_y = 195;
			//HitBox�̓���ւ��@����ōU���ΏۂɑI���ł���悤��
			Hits::DeleteHitBox(this);
			Hits::SetHitBox(this, m_x, m_y, 90, 120, ELEMENT_ITEM, OBJ_FIELD_ENEMY, 1);

			//ECard[0]=HP,ECard[1]=Atack,ECard[2]=Guard
			pos->ECard[0] = 1; pos->ECard[1] = 1; pos->ECard[2] = 0;
			Hp = 1; Atack = 1; Guard = 0;
		}
		if (Nanber == 2) {
			m_x = 747;
			m_y = 195;
			Hits::DeleteHitBox(this);
			Hits::SetHitBox(this, m_x, m_y, 90, 120, ELEMENT_ITEM, OBJ_FIELD_ENEMY2, 1);
			pos->ECard2[0] = 3; pos->ECard2[1] = 2; pos->ECard2[2] = 0;
			Hp = 3; Atack = 2; Guard = 0;
		}
		if (Nanber == 3) {
			m_x = 951;
			m_y = 195;
			Hits::DeleteHitBox(this);
			Hits::SetHitBox(this, m_x, m_y, 90, 120, ELEMENT_ITEM, OBJ_FIELD_ENEMY3, 1);
			pos->ECard3[0] = 5; pos->ECard3[1] = 4; pos->ECard3[2] = 2;
			Hp = 5; Atack = 4; Guard = 2;
		}
	}

	/*if (hit->CheckObjNameHit(OBJ_ENEMY) != nullptr && Summon == false)
	{
		Rotdraw = 180;//�J�[�h���R����]
		SetPrio(11);//�J�[�h�̕`��D��x�ύX
		if (mou->m_r == true)
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
	}*/

	if (Summon == true)
	{
		if (Nanber == 1)
		{
			//Hp�̍X�V
			Hp = pos->ECard[0];
		}
		if (Nanber == 2)
		{
			Hp = pos->ECard2[0];
		}
		if (Nanber == 3)
		{
			Hp = pos->ECard3[0];
		}
		if (Hp <= 0)
		{
			//HP���O�Ȃ����
			this->SetStatus(false);
			Hits::DeleteHitBox(this);
		}
	}

	hit->SetPos(m_x, m_y);
}

//�h���[
void CObjEnemyCard::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;
	if (Nanber < 4) {
		src.m_top = 0.0f + (Nanber + 1) * 64;
		src.m_left = 0.0f;
		src.m_right = 64.0f;
		src.m_bottom = 64.0f + (Nanber + 1) * 64;
	}
	else
	{
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 64.0f;
		src.m_bottom = 64.0f;
	}

	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x;
	dst.m_right = 90.0f + m_x;
	dst.m_bottom = 120.0f + m_y;

	Draw::Draw(0, &src, &dst, c, Rotdraw);
	if (Summon == true) {
		wchar_t str[128];
		swprintf_s(str, L"%d�@%d�@%d", Atack, Hp, Guard);
		Font::StrDraw(str, m_x + 10, m_y, 20, c);
	}
}