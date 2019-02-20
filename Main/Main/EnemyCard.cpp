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
	Number3 = han->basyo[Number - 1];

	aaaa = sc->Cnanber;

	Number4= sc->EnemyDeck[sc->e_Card - 1];

	Opdraw = sc->EnemyDeck[sc->e_Card - 1];//test �J�[�h�ԍ��̕ۑ�
	Updraw = 0;//taka �J�[�h�̕`��ʒu�̒���
	Rotdraw = 0;//test2 �J�[�h�̉�]�`�撲��

	CardHitCheck = false;
	Summon = false;
	StopSm = false;
	Shand = 0;

	Atacks = false;

	R_Summon = false;
	L_Summon = false;

	AtackUnit = 0;
	Dameg = 0;

	Opdraw--;
	Opdraw = Opdraw / 10;

	while (Opdraw>15)
	{
		Opdraw -= 15;//x�ʒu�����炷
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
	CObjDekc*pd = (CObjDekc*)Objs::GetObj(OBJ_DEKC);

	CHitBox*hit = Hits::GetHitBox(this);
	CObjmouse*mou = (CObjmouse*)Objs::GetObj(OBJ_MAUSE);


	Setcard = sc->Cnanber;//Setcard �J�[�h�̈ʒu�����ύX�p

	Posicard = Setcard - Number;//Posicard �J�[�h�̈ʒu�����ύX�p�Q

	CObjMap* pos = (CObjMap*)Objs::GetObj(OBJ_MAP);
	L_position = pos->L_position;
	S_position = pos->S_position;
	R_position = pos->R_position;

	if (hit->CheckObjNameHit(OBJ_PLAYER) != nullptr && Summon == true)
	{
		Cardname();
		CardHitCheck = true; //"�}�E�X���J�[�h�ɐG��Ă���"��Ԃɂ���
	}
	else
	{
		CardHitCheck = false; //"�}�E�X���J�[�h�ɐG��Ă��Ȃ�"��Ԃɂ���
	}

	Setcard = sc->Cnanber;//�J�[�h�̈ʒu�����ύX�p

	Posicard = Setcard - Number;//�J�[�h�̈ʒu�����ύX�p�Q

	if (Number3 - han->hensu3 > 0 && han->hensu > 0)//���݂̏ꏊ���o�����J�[�h������̏ꍇ�A�ЂƂ��炷
	{
		aaaa = aaaa;
		Number--;//�ԍ����P���炷
		han->hensu2++;
	}

	Number3 = han->basyo[Number - 1];//��D�̏ꏊ���X�V

	if (Setcard <= 5 && Summon == false)
	{
		for (int i = 0; i < Setcard; i++)
		{
			if (han->hand[i] == Number2)
			{
				aaaa = aaaa;
				m_x = 927 - (90 * i);
			}
		}
	}

	else if (Summon == false) {
		for (int i = 0; i < Setcard; i++)
		{
			if (han->hand[i] == Number2)
			{
				aaaa = aaaa;
				m_x = 567 + ((450 / (Setcard))*Posicard);
			}
		}
	}

	if (pd->STurn == false && pd->Start == true) {
		if (Summon == false && sc->Summon2 == false && sc->EDraw == true && aaaa == aaaa)
		{
			CObjPlist* PList = new CObjPlist();//�֐��Ăяo��

			PList->Action(&Name, Number4, &Ccost, &NTcard, &Hp, &Atack, &Guard, &Text);//�J�[�h�ԍ��ɉ�����HP�ϓ�
			Hp2 = Hp;
			Atack2 = Atack;
			Guard2 = Guard;

			pos->m_f = true;
			//���u���̓G�����@��D�̏��Ԃ��P�C�Q�C�R�̃J�[�h������
			if (Number == 1 && pos->ES_position == false || Number == 1 && pos->ES_position2 == false) {
				if (pos->ES_position == false)
				{
					m_x = 543;
					m_y = 191;
					pos->ECard2[0] = Hp; pos->ECard2[1] = Atack; pos->ECard2[2] = Guard;
					pos->ES_position = true;
					R_Summon = true;

					//HitBox�̓���ւ��@����ōU���ΏۂɑI���ł���悤��
					Hits::DeleteHitBox(this);
					Hits::SetHitBox(this, m_x, m_y, 90, 120, ELEMENT_ITEM, OBJ_FIELD_ENEMY2, 1);
				}
				else if (pos->ES_position2 == false)
				{
					m_x = 951;
					m_y = 191;
					pos->ECard3[0] = Hp; pos->ECard3[1] = Atack; pos->ECard3[2] = Guard;
					pos->ES_position2 = true;
					L_Summon = true;

					//HitBox�̓���ւ��@����ōU���ΏۂɑI���ł���悤��
					Hits::DeleteHitBox(this);
					Hits::SetHitBox(this, m_x, m_y, 90, 120, ELEMENT_ITEM, OBJ_FIELD_ENEMY3, 1);
				}

				Summon = true;
				sc->Summon2 = true;
			}
		}

		//�J�[�h���������ꂽ�Ƃ�
		if (Summon == true && StopSm == false)
		{
			han->hand[Number3 - 1] = 0; //�o�����J�[�h�̃J�[�h�ԍ����폜
			han->basyo[Number3 - 1] = 0; //�o�����J�[�h�̏ꏊ�����폜
			han->hensu = Setcard - Number3; //��D�̍��v�Əo�����J�[�h�̍�����ۑ�
			han->hensu3 = Number3; //�o�����J�[�h�̏ꏊ��ۑ�
			sc->Cnanber--; //�J�[�h�̍��v�������P���炷
			pos->m_f = true;
			StopSm = true;
		}
	}

	else
	{
		pos->EAtackt = 0;
		Atacks = false;
		Dameg = 0;
		AtackUnit = 0;
	}

	if (Summon == true)
	{
		if (pd->STurn == false) {
			//�퓬�v���O����
			if (Atacks == false)
				pos->EAtackt++;

			if (pos->EAtackt == 40 && Atacks == false)
			{
				for (int i = 0; i < 3; i++) {
					if (pos->PCard[i][0] >= 0) {
						Hpbox[i] = pos->PCard[i][0];
						Guardbox[i] = pos->PCard[i][2];
					}
					else
					{
						Hpbox[i] = 0;
						Guardbox[i] = 0;
					}

					if (Hpbox[i] != 0) {
						if (Dameg < Atack - pos->PCard[i][2]) {
							AtackUnit = i;
							Dameg = Atack - pos->PCard[i][2];
						}
					}
				}
				if (R_Summon == true) {
					//������������Ă����ꍇ�A�ϋv�x����
					if (pos->PCard[AtackUnit][4] > 0)
						pos->PCard[AtackUnit][4] -= 1;

					//�Q�ڂ̕�����������Ă����ꍇ�A�ϋv�x����
					if (pos->PCard[AtackUnit][6] > 0)
						pos->PCard[AtackUnit][6] -= 1;

					if (pos->ECard2[1] - pos->PCard[AtackUnit][2] > 0)
						pos->PCard[AtackUnit][0] -= pos->ECard2[1] - pos->PCard[AtackUnit][2];//�G��HP�����g�̍U����-�G�̎���������_���[�W��^����

					if (pos->PCard[AtackUnit][1] - pos->ECard2[2] > 0)
						pos->ECard2[0] -= pos->PCard[AtackUnit][1] - pos->ECard2[2];//�G�̍U����-���g��HP�̕������_���[�W���󂯂�
				}

				else if (L_Summon == true) {
					//������������Ă����ꍇ�A�ϋv�x����
					if (pos->PCard[AtackUnit][4] > 0)
						pos->PCard[AtackUnit][4] -= 1;

					//�Q�ڂ̕�����������Ă����ꍇ�A�ϋv�x����
					if (pos->PCard[AtackUnit][6] > 0)
						pos->PCard[AtackUnit][6] -= 1;

					if (pos->ECard3[1] - pos->PCard[AtackUnit][2] > 0)
						pos->PCard[AtackUnit][0] -= pos->ECard3[1] - pos->PCard[AtackUnit][2];//�G��HP�����g�̍U����-�G�̎���������_���[�W��^����

					if (pos->PCard[AtackUnit][1] - pos->ECard3[2] > 0)
						pos->ECard3[0] -= pos->PCard[AtackUnit][1] - pos->ECard3[2];//�G�̍U����-���g��HP�̕������_���[�W���󂯂�
				}
				pos->EAtackt++;
				Atacks = true;
			}
		}

		if (R_Summon == true)
		{
			//Hp�̍X�V
			Hp = pos->ECard2[0];
		}
		else if (L_Summon == true)
		{
			Hp = pos->ECard3[0];
		}

		if (Hp <= 0)
		{
			if (R_Summon == true)
			{
				pos->ES_position = false;
			}
			else if (L_Summon == true)
			{
				pos->ES_position2 = false;
			}

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
	if (Number < 4 && Number !=2 && Summon==true) {
		src.m_top = 0.0f + (128.0f*Updraw);
		src.m_left = 0.0f + (128.0f*Opdraw);
		src.m_right = 128.0f + (128.0f*Opdraw);
		src.m_bottom = 128.0f + (128.0f*Updraw);
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

			swprintf_s(str, L"�g  �o : %d/%d", Hp, Hp2);
			Font::StrDraw(str, 40, 600, 20, d);
			swprintf_s(str, L"�U���� : %d(%d+%d)", Atack, Atack2, Atack - Atack2);
			Font::StrDraw(str, 40, 620, 20, d);
			swprintf_s(str, L"�h��� : %d(%d+%d)", Guard, Guard2, Guard - Guard2);
			Font::StrDraw(str, 40, 640, 20, d);
			swprintf_s(str, L"�R�X�g : %d", Ccost);
			Font::StrDraw(str, 40, 660, 20, d);
			Draw::Draw(0, &src, &dst, c, 0);

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
	}
}

//Cardname�֐�
//Cardname()����͂���΁A�J�[�h�ɖ��O�ƃe�L�X�g���\�������悤�ɂȂ�
void CObjEnemyCard::Cardname()
{
	CObjMap* pos = (CObjMap*)Objs::GetObj(OBJ_MAP);

	FILE *fp;
	char fname[] = "CardList.csv";
	fp = fopen(fname, "r"); // �t�@�C�����J���B���s�����NULL��Ԃ��B
	int ret;
	int aaaa;//�_�~�[�f�[�^

	while ((ret = fscanf(fp, "%[^,],%d,%d,%d,%d,%d,%d,%[^\n] ,", pos->name, &aaaa, &TextD, &aaaa, &aaaa, &aaaa, &aaaa, text) != EOF))//���O�A�J�[�h�ԍ��A�e�L�X�g������
	{
		if (TextD == Number4)//�J�[�h�ԍ�����v�����Ƃ��A�����J�n
		{
			Tlong = strlen(text);//�e�L�X�g�̒��������߂�
			for (int j = 0; j < 6; j++)
			{
				pos->text2[j][0] = '\0';
			}
			for (int i = 0; i * 30 < Tlong; i++)//15�����Â��s���Ă���
			{
				strncpy(pos->text2[i], text + i * 30, 30);
				pos->text2[i][30] = '\0';
			}
			break;
		}
	}

	fclose(fp); // �t�@�C�������
}