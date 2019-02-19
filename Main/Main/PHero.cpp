#include"GameL\DrawTexture.h"
#include"GameL\HitBoxManager.h"
#include"GameL\WinInputs.h"
#include"GameHead.h"
#include"PHero.h"
#include"Deck.h"
#include"Cardlist.h"
#include"GameL\Audio.h"

#include"GameL\DrawFont.h"

extern bool PrecedingAttack; //��s�͍U���ł��Ȃ��̂��Q�Ƃ���ϐ� true=�U���� false=�U���s��

//�g�p����l�[���X�y�[�X
CObjPHero::CObjPHero()
{
	m_x = 738;
	m_y = 590;
}

//�C�j�V�����C�Y
void CObjPHero::Init()
{
	Updraw = 0;//�J�[�h�̕`��ʒu�̒���
	Rotdraw = 0;//�J�[�h�̉�]�`�撲��

	start = false;

	//�X�e�[�^�X�̏�����
	Hp = 20;
	Atack = 1;
	Guard = 0;
	Pusave = false;

	//�{�^���p�ϐ��̏�����
	BDraw = 1;
	Button = false;
	b_x = 0;
	b_y = 0;

	LWeapon = false;
	RWeapon = false;

	Deadt = 90;
	inviD = 1.0f;

	test = 1;

	Bat3 = 1;

	time = 60;

	//�U�������A��������������
	Punch = false;

	m_f = false;

	//���^�C�A�t���O
	r_f = false;

	Hits::SetHitBox(this, m_x, m_y, 108, 144, ELEMENT_GREEN, OBJ_FIELD_PLAYER, 1);
}

//�A�N�V����
void CObjPHero::Action()
{
	m_l = Input::GetMouButtonL();
	CHitBox*hit = Hits::GetHitBox(this);
	CObjmouse*mou = (CObjmouse*)Objs::GetObj(OBJ_MAUSE);
	CObjMap* pos = (CObjMap*)Objs::GetObj(OBJ_MAP);
	CObjDekc*sc = (CObjDekc*)Objs::GetObj(OBJ_DEKC);

	if (sc->Turn == true)
	{
		Pusave = false;
	}

	if (start == false)
	{
		start = true;
		pos->PCard[0][0] = Hp;
		pos->PCard[0][1] = Atack;
		pos->PCard[0][2] = Guard;
		pos->PCard[0][3] = 0;
		Hp2 = Hp;
		Atack2 = Atack;
		Guard2 = Guard;
	}

	Hp=pos->PCard[0][0];
	Atack=pos->PCard[0][1];
	Guard=pos->PCard[0][2];

	//�s�k�����E���^�C�A
	/*if (m_l == true)
	{
		if (mou->m_mouse_x > 19 && mou->m_mouse_x < 162
			&& mou->m_mouse_y > 809 && mou->m_mouse_y < 880
			&& pos->PTrun == true)
		{
			r_f = true;
		}
	}
	if (r_f == true)
	{
		if (m_l == true)
		{
			if (mou->m_mouse_x > 600 && mou->m_mouse_x < 672
				&& mou->m_mouse_y > 420 && mou->m_mouse_y < 456)
			{
				Scene::SetScene(new CSceneGameover());
			}
			else if (mou->m_mouse_x > 900 && mou->m_mouse_x < 972
				&& mou->m_mouse_y > 420 && mou->m_mouse_y < 456)
			{
				r_f = false;
			}
		}
	}*/

	if (Hp <= 0)
	{
		Deadt--;
		inviD = Deadt / 90;
		if (Deadt == 0)
		{
			Scene::SetScene(new CSceneGameover());
		}
	}

	if (m_l == true)
	{
		if (mou->EChoice == true && Punch == true&&Bat3==1)
		{

			//������������Ă����ꍇ�A�ϋv�x����
			if (pos->PCard[0][4] > 0)
			{
				pos->PCard[0][4] -= 1;
			}

			//�Q�ڂ̕�����������Ă����ꍇ�A�ϋv�x����
			if (pos->PCard[0][6] > 0)
			{
				pos->PCard[0][6] -= 1;
			}

			if (pos->PCard[0][1] - pos->ECard[2] > 0)
				pos->ECard[0] -= pos->PCard[0][1] - pos->ECard[2];//�G��HP�����g�̍U����-�G�̎���������_���[�W��^����

			if (pos->ECard[1] - pos->PCard[0][2] > 0)
				pos->PCard[0][0] -= pos->ECard[1] - pos->PCard[0][2];//�G�̍U����-���g��HP�̕������_���[�W���󂯂�

			//�I���������ɖ߂�
			test = 1;
			Punch = false;
			Pusave = true;
			Audio::Start(8);
			Bat3 = 0;
		}

		else if (mou->EChoice2 == true && Punch == true && Bat3 == 1)
		{
			//������������Ă����ꍇ�A�ϋv�x����
			if (pos->PCard[0][4] > 0)
			{
				pos->PCard[0][4] -= 1;
			}

			//�Q�ڂ̕�����������Ă����ꍇ�A�ϋv�x����
			if (pos->PCard[0][6] > 0)
			{
				pos->PCard[0][6] -= 1;
			}

			if (pos->PCard[0][1] - pos->ECard2[2]>0)
				pos->ECard2[0] -= pos->PCard[0][1] - pos->ECard2[2];

			if (pos->ECard2[1] - pos->PCard[0][2]>0)
				pos->PCard[0][0] -= pos->ECard2[1] - pos->PCard[0][2];
			test = 1;
			Punch = false;
			Pusave = true;
			Audio::Start(8);
			Bat3 = 0;

		}

		else if (mou->EChoice3 == true && Punch == true && Bat3 == 1)
		{
			//������������Ă����ꍇ�A�ϋv�x����
			if (pos->PCard[0][4] > 0)
			{
				pos->PCard[0][4] -= 1;
			}

			//�Q�ڂ̕�����������Ă����ꍇ�A�ϋv�x����
			if (pos->PCard[0][6] > 0)
			{
				pos->PCard[0][6] -= 1;
			}

			if (pos->PCard[0][1] - pos->ECard3[2]>0)
				pos->ECard3[0] -= pos->PCard[0][1] - pos->ECard3[2];

			if (pos->ECard3[1] - pos->PCard[0][2]>0)
				pos->PCard[0][0] -= pos->ECard3[1] - pos->PCard[0][2];

			test = 1;
			Punch = false;
			Pusave = true;
			Audio::Start(8);
			Bat3 = 0;

		}

		else if (mou->Flee == true && time >= 30)
		{
			test = 1;
			Punch = false;
		}

	}

	if (test == 0)
		Button = false;

	if (Button == true)
	{
		SetPrio(12);
		time = 0;

		if (m_f == false)
		{
			if (m_l == true)
			{
				//�{�^�����N���b�N���ꂽ�Ƃ�
				if (mou->m_mouse_x > b_x &&
					mou->m_mouse_x < b_x + 64 &&
					mou->m_mouse_y > b_y + 16 &&
					mou->m_mouse_y < b_y + 48
					)
				{

					Button = false;
					m_f = true;

					test = 0;
					Punch = true;

					m_l = false;
				}
				else
				{
					Button = false;
				}
			}
		}
		else
		{
			m_f = false;
		}
	}
	else
	{
		time++;
		if (time == 60)
			time = 30;
	}

	if (hit->CheckObjNameHit(OBJ_PLAYER) != nullptr && pos->Wtouch == false)
	{
		Rotdraw = 0;
		SetPrio(11);
		if (m_l == true && pos->WSummon == false && test != 0 && Pusave == false
			&& pos->PTrun == true && PrecedingAttack == false)
		{
			Button = true;
		}
	}
	else
	{
		//CardHitCheck = false; //"�}�E�X���J�[�h�ɐG��Ă��Ȃ�"��Ԃɂ���
		Rotdraw = 0;
		SetPrio(10);
	}

	if (sc->Turn == true)
	{
		Bat3 = 1;
	}
}

//�h���[
void CObjPHero::Draw()
{

	float c[4] = { 1.0f,test,1.0f,inviD };
	float e[4] = { 1.0f,1.0f,1.0f,1.0f };

	//HP
	float h[4] = { 0.0f,1.0f,0.0f,1.0f };
	float h2[4] = { 0.7f,1.0f,0.0f,1.0f };

	//Atack
	float a[4] = { 1.0f,0.5f,0.7f,1.0f };
	float a2[4] = { 1.0f,0.0f,0.0f,1.0f };

	//Guard
	float g[4] = { 0.0f,1.0f,1.0f,1.0f };
	float g2[4] = { 0.0f,0.0f,1.0f,1.0f };

	RECT_F src;
	RECT_F dst;
	CHitBox*hit = Hits::GetHitBox(this);

	src.m_top = 0.0f + (128 * 10);
	src.m_left = 0.0f + (128 * 5);
	src.m_right = 128.0f + (128 * 5);
	src.m_bottom = 128.0f + (128 * 10);

	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x;
	dst.m_right = 144.0f + m_x;
	dst.m_bottom = 144.0f + m_y;

	Draw::Draw(0, &src, &dst, c, Rotdraw);

	//��ʍ���Ɋg��摜��\��������

	if (hit->CheckObjNameHit(OBJ_PLAYER) != nullptr)
	{
		CObjMap* pos = (CObjMap*)Objs::GetObj(OBJ_MAP);
		Cardname();

		dst.m_top = 12.0f;
		dst.m_left = 12.0f;
		dst.m_right = 371.0f;
		dst.m_bottom = 371.0f;

		wchar_t str[128];

		wchar_t atr[256];
		wchar_t aatr[5][64];
		mbstowcs(atr, pos->name, 256);//�}���`�o�C�g�����C�h�ɕϊ�
		Font::StrDraw(atr, 40, 575, 20, e);//�e�L�X�g��\��

		for (int i = 0; i * 30 < Tlong; i++) {
			mbstowcs(aatr[i], pos->text2[i], 64);
			Font::StrDraw(aatr[i], 40, 640 + i * 20, 20, e);
		}

		swprintf_s(str, L"�g  �o : %d/%d", Hp, Hp2);
		Font::StrDraw(str, 40, 600, 20, e);
		swprintf_s(str, L"�U���� : %d(%d+%d)", Atack, Atack2, Atack - Atack2);
		Font::StrDraw(str, 40, 620, 20, e);
		swprintf_s(str, L"�h��� : %d(%d+%d)", Guard, Guard2, Guard - Guard2);
		Font::StrDraw(str, 40, 640, 20, e);

		Draw::Draw(0, &src, &dst, c, 0);

		//����Ɏ�l���̃X�e�[�^�X��\��������
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
			Font::StrDraw(str, 115, 295, 50, h);
		}
		else
		{
			swprintf_s(str, L"%d", Hp);
			Font::StrDraw(str, 130, 295, 50, h);
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

		Draw::Draw(5, &src, &dst, e, 0);
	}

	//�{�^���̕\��
	if (Button == true)
	{
		b_x = m_x + 25.0;
		b_y = m_y - 50.0;

		src.m_top = 0.0f;
		src.m_left = 0.0f + (BDraw * 64);
		src.m_right = 64.0f + (BDraw * 64);
		src.m_bottom = 64.0f;

		dst.m_top = 0.0f + b_y;
		dst.m_left = 0.0f + b_x;
		dst.m_right = 64.0f + b_x;
		dst.m_bottom = 64.0f + b_y;

		Draw::Draw(3, &src, &dst, c, Rotdraw);
	}
	wchar_t str[128];

	//�J�[�h�̕����Ɏ�l���̃X�e�[�^�X��\������
	if (Atack >= 10)
	{
		swprintf_s(str, L"%d", Atack);
		Font::StrDraw(str, 746, 701, 24, a2);
	}
	else
	{
		swprintf_s(str, L"%d", Atack);
		Font::StrDraw(str, 753, 701, 24, a2);
	}

	if (Hp >= 10)
	{
		swprintf_s(str, L"%d", Hp);
		Font::StrDraw(str, 779, 701, 24, h);
	}
	else
	{
		swprintf_s(str, L"%d", Hp);
		Font::StrDraw(str, 786, 701, 24, h);
	}

	if (Guard >= 10)
	{
		swprintf_s(str, L"%d", Guard);
		Font::StrDraw(str, 810, 701, 24, g2);
	}
	else
	{
		swprintf_s(str, L"%d", Guard);
		Font::StrDraw(str, 817, 701, 24, g2);
	}
}

//Cardname�֐�
//Cardname()����͂���΁A�J�[�h�ɖ��O�ƃe�L�X�g���\�������悤�ɂȂ�
void CObjPHero::Cardname()
{
	CObjMap* pos = (CObjMap*)Objs::GetObj(OBJ_MAP);

	FILE *fp;
	char fname[] = "CardList.csv";
	fp = fopen(fname, "r"); // �t�@�C�����J���B���s�����NULL��Ԃ��B
	int ret;
	int aaaa;//�_�~�[�f�[�^

	while ((ret = fscanf(fp, "%[^,],%d,%d,%d,%d,%d,%d,%[^\n] ,", pos->name, &aaaa, &TextD, &aaaa, &aaaa, &aaaa, &aaaa, text) != EOF))//���O�A�J�[�h�ԍ��A�e�L�X�g������
	{
		if (TextD == 1551)//�J�[�h�ԍ�����v�����Ƃ��A�����J�n
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