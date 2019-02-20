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
	Number = sc->Cnanber;//bango �������J�[�h�̏��Ԃ̌Œ�
	Number2 = han->hand[Number - 1];
	Number3 = Number;

	Opdraw = sc->e_Card;//test �J�[�h�ԍ��̕ۑ�
	Updraw = 0;//taka �J�[�h�̕`��ʒu�̒���
	Rotdraw = 0;//test2 �J�[�h�̉�]�`�撲��

	CardHitCheck = false;
	Summon = false;
	Shand = 0;

	while (Opdraw>7)
	{
		Opdraw -= 7;//x�ʒu�����炷
		Updraw++;
	}
	m_f = false;

	CObjMap* pos = (CObjMap*)Objs::GetObj(OBJ_MAP);

	Hits::SetHitBox(this, m_x, m_y, 128, 128, ELEMENT_CARD, OBJ_CARD, 1);
}

//�A�N�V����
void CObjEnemyCard::Action()
{
	Rotdraw = 180;//�J�[�h��180����]
	CObjEnemyHand*han = (CObjEnemyHand*)Objs::GetObj(OBJ_ENEMY_HAND);
	CObjEnemyDeck*sc = (CObjEnemyDeck*)Objs::GetObj(OBJ_ENEMY_DECK);

	CHitBox*hit = Hits::GetHitBox(this);
	CObjmouse*mou = (CObjmouse*)Objs::GetObj(OBJ_MAUSE);


	Setcard = sc->Cnanber;//Setcard �J�[�h�̈ʒu�����ύX�p

	Posicard = Setcard - Number;//Posicard �J�[�h�̈ʒu�����ύX�p�Q

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

	if (Number - han->hensu > 0)
	{
		Number2 = han->basyo[Number - Shand];
	}

	CObjMap* pos = (CObjMap*)Objs::GetObj(OBJ_MAP);
	L_position = pos->L_position;
	S_position = pos->S_position;
	R_position = pos->R_position;

	if (hit->CheckObjNameHit(OBJ_PLAYER) != nullptr)
	{
		CardHitCheck = true; //"�}�E�X���J�[�h�ɐG��Ă���"��Ԃɂ���
	}
	else
	{
		CardHitCheck = false; //"�}�E�X���J�[�h�ɐG��Ă��Ȃ�"��Ԃɂ���
	}

	if (Setcard <= 5 && Summon == false)
	{
		//m_x = 250+(90* Posicard);
		for (int i = 0; i < Setcard; i++)
		{
			if (han->hand[i] == Number2)
			{
				m_x = 927 - (90 * i);
			}
		}
	}

	else if (Summon == false) {
		for (int i = 0; i < Setcard; i++)
		{
			if (han->hand[i] == Number2)
			{
				m_x = 567 + ((450 / (Setcard))*Posicard);
			}
		}
	}

	if (Number < 4 && Number!=2 && Summon==false)
	{
		Summon = true;
		//han->hand[Nanber3 - 1] = 0;//�o�����J�[�h�̃J�[�h�ԍ����폜
		//han->basyo[Nanber3 - 1] = 0;//�o�����J�[�h�̏ꏊ�����폜
		//han->hensu = Setcard - Nanber3;//��D�̍��v�Əo�����J�[�h�̍�����ۑ�
		//han->hensu3 = Nanber3;//�o�����J�[�h�̏ꏊ��ۑ�
		//sc->Cnanber -= 1;//�J�[�h�̍��v�������P���炷
		pos->m_f = true;
		//���u���̓G�����@��D�̏��Ԃ��P�C�Q�C�R�̃J�[�h������
		if (Number == 1) {
			m_x = 543;
			m_y = 191;
			//HitBox�̓���ւ��@����ōU���ΏۂɑI���ł���悤��
			Hits::DeleteHitBox(this);
			Hits::SetHitBox(this, m_x, m_y, 90, 120, ELEMENT_ITEM, OBJ_FIELD_ENEMY2, 1);

			//ECard[0]=HP,ECard[1]=Atack,ECard[2]=Guard
			//�X�e�[�^�X�A�R�X�g���u��
			pos->ECard2[0] = 1; pos->ECard2[1] = 1; pos->ECard2[2] = 0;
			Hp = 1; Atack = 1; Guard = 0;
			Hp2 = 1; Atack2 = 1; Guard2 = 0;
			Ccost = 100;
		}
		/*if (Number == 2) {
			m_x = 747;
			m_y = 195;
			Hits::DeleteHitBox(this);
			Hits::SetHitBox(this, m_x, m_y, 90, 120, ELEMENT_ITEM, OBJ_FIELD_ENEMY2, 1);
			pos->ECard2[0] = 3; pos->ECard2[1] = 2; pos->ECard2[2] = 0;
			Hp = 3; Atack = 2; Guard = 0;
		}*/
		if (Number == 3) {
			m_x = 951;
			m_y = 191;
			Hits::DeleteHitBox(this);
			Hits::SetHitBox(this, m_x, m_y, 90, 120, ELEMENT_ITEM, OBJ_FIELD_ENEMY3, 1);
			//�X�e�[�^�X�A�R�X�g���u��
			pos->ECard3[0] = 5; pos->ECard3[1] = 4; pos->ECard3[2] = 2;
			Hp = 5; Atack = 4; Guard = 2;
			Hp2 = 5; Atack2 = 4; Guard2 = 2;
			Ccost = 1000;
		}
	}

	if (Summon == true)
	{
		if (Number == 1)
		{
			//Hp�̍X�V
			Hp = pos->ECard2[0];
		}
		/*if (Number == 2)
		{
			Hp = pos->ECard2[0];
		}*/
		if (Number == 3)
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
	float d[4] = { 1.0f,1.0f,1.0f,1.0f };
	//HP
	float h[4] = { 0.0f,1.0f,0.0f,1.0f };
	float h2[4] = { 0.2f,0.7,0.0f,1.0f };

	//Atack
	float a[4] = { 1.0f,0.5f,0.7f,1.0f };
	float a2[4] = { 1.0f,0.0f,0.0f,1.0f };

	//Guard
	float g[4] = { 0.0f,1.0f,1.0f,1.0f };
	float g2[4] = { 0.0f,0.0f,1.0f,1.0f };

	//cost
	float cost[4] = { 0.0f,0.0f,0.0f,1.0f };
	RECT_F src;
	RECT_F dst;

	wchar_t str[128];

	if (Number < 4 && Number !=2) {
		src.m_top = 0.0f + (Number + 1) * 128;
		src.m_left = 128.0f;
		src.m_right = 256.0f;
		src.m_bottom = 128.0f + (Number + 1) * 128;
	}

	else
	{
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 128.0f;
		src.m_bottom = 128.0f;
	}

	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x - 36;
	dst.m_right = 128.0f + m_x - 36;
	dst.m_bottom = 128.0f + m_y;

	Draw::Draw(0, &src, &dst, c, Rotdraw);

	//��ʍ���Ɋg��摜��\��������

	if (Summon == true)
	{
		if (CardHitCheck == true)
		{
			CObjMap* pos = (CObjMap*)Objs::GetObj(OBJ_MAP);

			dst.m_top = 12.0f;
			dst.m_left = 12.0f;
			dst.m_right = 371.0f;
			dst.m_bottom = 371.0f;

			wchar_t atr[256];
			wchar_t aatr[5][64];
			mbstowcs(atr, pos->name, 256);//�}���`�o�C�g�����C�h�ɕϊ�
			Font::StrDraw(atr, 40, 575, 20, d);//�e�L�X�g��\��

			for (int i = 0; i * 30 < Tlong; i++)
			{
				mbstowcs(aatr[i], pos->text2[i], 64);
				Font::StrDraw(aatr[i], 40, 670 + i * 20, 20, d);
			}

			//if (Type == 1)
			//{
				swprintf_s(str, L"�g  �o : %d/%d", Hp, Hp2);
				Font::StrDraw(str, 40, 600, 20, d);
				swprintf_s(str, L"�U���� : %d(%d+%d)", Atack, Atack2, Atack - Atack2);
				Font::StrDraw(str, 40, 620, 20, d);
				swprintf_s(str, L"�h��� : %d(%d+%d)", Guard, Guard2, Guard - Guard2);
				Font::StrDraw(str, 40, 640, 20, d);
				swprintf_s(str, L"�R�X�g : %d", Ccost);
				Font::StrDraw(str, 40, 660, 20, d);
				Draw::Draw(0, &src, &dst, c, 0);
			/*}
			if (Type == 2 || Type == 3)
			{
				swprintf_s(str, L"�ϋv�l : %d/%d", Hp, Hp2);
				Font::StrDraw(str, 40, 600, 20, d);
				swprintf_s(str, L"�U���� : %d", Atack);
				Font::StrDraw(str, 40, 620, 20, d);
				swprintf_s(str, L"�h��� : %d", Guard);
				Font::StrDraw(str, 40, 640, 20, d);
				swprintf_s(str, L"�R�X�g : %d", Ccost);
				Font::StrDraw(str, 40, 660, 20, d);
			}*/

			//�G�����X�^�[�̃X�e�[�^�X�\��
			//if (Type == 1)
			//{
			if (Atack >= 10)
			{
				swprintf_s(str, L"%d", Atack);
				Font::StrDraw(str, 50, 295, 50, a2);
			}
			else
			{
				swprintf_s(str, L"%d", Atack);
				Font::StrDraw(str, 60, 295, 50, a2);
			}

			if (Hp >= 10)
			{
				swprintf_s(str, L"%d", Hp);
				Font::StrDraw(str, 125, 295, 50, h2);
			}
			else
			{
				swprintf_s(str, L"%d", Hp);
				Font::StrDraw(str, 130, 295, 50, h2);
			}

			if (Guard >= 10)
			{
				swprintf_s(str, L"%d", Guard);
				Font::StrDraw(str, 185, 295, 50, g2);
			}
			else
			{
				swprintf_s(str, L"%d", Guard);
				Font::StrDraw(str, 200, 295, 50, g2);
			}
			//}
			//�G�����̃X�e�[�^�X�\��
			/*if (Type == 2 || Type == 3)
			{
				if (Atack >= 10)
				{
					swprintf_s(str, L"%d", Atack);
					Font::StrDraw(str, 50, 295, 50, a2);
				}
				else
				{
					swprintf_s(str, L"%d", Atack);
					Font::StrDraw(str, 60, 295, 50, a2);
				}

				if (Hp >= 10)
				{
					swprintf_s(str, L"%d", Hp);
					Font::StrDraw(str, 125, 295, 50, h2);
				}
				else
				{
					swprintf_s(str, L"%d", Hp);
					Font::StrDraw(str, 130, 295, 50, h2);
				}

				if (Guard >= 10)
				{
					swprintf_s(str, L"%d", Guard);
					Font::StrDraw(str, 185, 295, 50, g2);
				}
				else
				{
					swprintf_s(str, L"%d", Guard);
					Font::StrDraw(str, 200, 295, 50, g2);
				}
			}*/
			if (Ccost == 1000)
			{
				swprintf_s(str, L"%d", Ccost);
				Font::StrDraw(str, 30, 25, 50, cost);
			}
			else
			{
				swprintf_s(str, L"%d", Ccost);
				Font::StrDraw(str, 45, 25, 50, cost);
			}
			Draw::Draw(5, &src, &dst, c, 0);
		}
	}
	
	//�X�e�[�^�X�̕\��
	if (Summon == true)
	{
		if (Atack >= 10)
		{
			swprintf_s(str, L"%d", Atack);
			Font::StrDraw(str, m_x + 5, m_y + 10, 20, a2);
		}
		else
		{
			swprintf_s(str, L"%d", Atack);
			Font::StrDraw(str, m_x + 10, m_y + 10, 20, a2);
		}

		if (Hp >= 10)
		{
			swprintf_s(str, L"%d", Hp);
			Font::StrDraw(str, m_x + 33, m_y + 10, 20, h);
		}
		else
		{
			swprintf_s(str, L"%d", Hp);
			Font::StrDraw(str, m_x + 38, m_y + 10, 20, h2);
		}

		if (Guard >= 10)
		{
			swprintf_s(str, L"%d", Guard);
			Font::StrDraw(str, m_x + 62, m_y + 10, 20, g2);
		}
		else
		{
			swprintf_s(str, L"%d", Guard);
			Font::StrDraw(str, m_x + 67, m_y + 10, 20, g2);
		}

		if (Ccost == 1000)
		{
			swprintf_s(str, L"%d", Ccost);
			Font::StrDraw(str, m_x + 47, m_y + 105, 20, cost);
		}
		else
		{
			swprintf_s(str, L"%d", Ccost);
			Font::StrDraw(str, m_x + 52, m_y + 105, 20, cost);
		}
	}
}