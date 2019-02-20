//�V���E�X���w�b�_�[�t�@�C��
#include"GameL\DrawTexture.h"
#include"GameHead.h"
#include"Deck.h"
#include"GameL\WinInputs.h"
#include"GameL\HitBoxManager.h"
#include"GameL\DrawFont.h"
#include"GameL\Audio.h"
#include<stdlib.h>
#include<time.h>

int TurnCount = 0; //���݂̃^�[������\�����邽�߂̕ϐ�
extern bool PrecedingAttack; //��s�͍U���ł��Ȃ��̂��Q�Ƃ���ϐ� true=�U���� false=�U���s��

//�g�p����l�[���X�y�[�X

//�C�j�V�����C�Y
void CObjDekc::Init()
{
	//x.y�f�b�L�̈ʒu
	x = 1082;
	y = 739;
	//m_x,m_y �J�[�h�̏o���ʒu����
	//m_x = 567;
	m_y = 743;
	//�������̖h�~����
	m_f = true;
	m_f2 = true;
	//�^�[���J�n��
	Turn = false;

	//�Q�[���J�n��
	StartG = false;

	//stop �����J�[�h�̏o���j�~
	stop = 0;

	srand((unsigned)time(NULL));

	for (int i = 0; i < 40; i++)
	{
		/*if(i<7)
			Deck[i] = 401;
		else if(i<11)
			Deck[i] = 491;
		else if (i<14)
			Deck[i] = 951;
		else if (i<40)
			Deck[i] = 1351;*/

		Data = rand() % 1341 + 10;

		Data = Data - (Data % 10);

		Data++;


		Deck[i] = Data;//�����ԍ��̃J�[�h�ďo

	}

	//Cnanber �J�[�h�̈ʒu�����p
	Cnanber = 0;

	i = 1;

	//Cardcount ���݃h���[���������@���݃v���O�����쐬��
	Cardcount = 0;

	Deckcount = 40; //�f�b�L�̎c�薇��

	//Start�ŏ��̂T���h���[�̂��߂̕ϐ�
	Start = false;
	Button2 = false;

	effect = false;

	//�����|�C���g
	//m_point = 1;
	m_point = 100;
	Cost = 0;
	m_flag_point = false;

	DrawButton_y = 0;
	DrawButton_time = 0;

}

//�A�N�V����
void CObjDekc::Action()
{
	CObjMap* pos = (CObjMap*)Objs::GetObj(OBJ_MAP);
	CObjHand*sc = (CObjHand*)Objs::GetObj(OBJ_HAND);
	CObjCard*car = (CObjCard*)Objs::GetObj(OBJ_CARD);
	CObjmouse*mou = (CObjmouse*)Objs::GetObj(OBJ_MAUSE);

	if (StartG == true)
	{
		
		Card = rand() % 39 + 1;//�����ԍ��̃J�[�h�ďo
		stop = 1;

		m_l = Input::GetMouButtonL();

		if (Cardcount >= 40)
		{
			Scene::SetScene(new CSceneGameover());
		}

		//�ʂ̃J�[�h���o��܂Ń��[�v
		while (stop == 1)
		{
			stop = 0;
			Card = rand() % 39 + 1;

			if (Cardcount >= 39)
			{
				break;
			}

			for (int i = 0; i < Cardcount; i++)
			{
				if (Pullc[Card - 1] == Deck[Card - 1])
				{
					stop = 1;
				}
			}
		}

		if (Deck[Card - 1] <= 481)
		{
			Ctype = monster;
		}

		else if (Deck[Card - 1] <= 941)
		{
			Ctype = weapon;
		}

		else if (Deck[Card - 1] <= 1341)
		{
			Ctype = shield;
		}

		else
		{
			Ctype = item;
		}

		/*if (Card <= 7)
		{
			Ctype = monster;
		}

		else if (Card <= 11)
		{
			Ctype = weapon;
		}

		else if (Card <= 14)
		{
			Ctype = shield;
		}

		else
		{
			Ctype = item;
		}*/


		if (Turn == true && Start == true || effect == true)
		{
			if (m_f == true || effect == true)
			{
				Pullc[Card - 1] = Deck[Card - 1];//�f�b�L�Ƀh���[�����J�[�h��o�^
				sc->hand[Cnanber] = Card;//��D�Ƀh���[�����J�[�h��o�^
				sc->basyo[Cnanber] = Cnanber + 1;
				Cnanber++;
				Cardcount++;
				//�J�[�h�쐬
				CObjCard* obj_b = new CObjCard(300, m_y, Ctype);//�J�[�h�쐬
				Objs::InsertObj(obj_b, OBJ_CARD, 10);//������J�[�h���I�u�W�F�N�g�}�l�[�W���[�ɓo�^
				//CObjViewCard* obj_viewcard = new CObjViewCard(Ctype); //��ʍ���̊Ϗܗp�J�[�h�쐬
				//Objs::InsertObj(obj_viewcard, OBJ_VIEWCARD, 1); //������Ϗܗp�J�[�h���I�u�W�F�N�g�}�l�[�W���[�ɓo�^
				m_f = false;
				effect = false;

				if (Turn == true)
				{
					//�h���[������|�C���g����
					/*m_point++;
					car->Bat = 1;
					car->Bat2 = 1;*/

					m_point = m_point + i * 100;
					i++;
				}
				Turn = false;
				pos->PTrun = true;
				Audio::Start(2);
			}
		}

		else
		{
			m_f = true;
		}

		//�X�^�[�g����
		if (Start == false)
		{
			Pullc[Card - 1] = Deck[Card - 1];//�f�b�L�Ƀh���[�����J�[�h��o�^
			sc->hand[Cnanber] = Card;//��D�Ƀh���[�����J�[�h��o�^
			sc->basyo[Cnanber] = Cnanber + 1;
			Cnanber++;
			Cardcount++;
			CObjCard* obj_b = new CObjCard(m_x, m_y, Ctype);//�J�[�h�쐬
			Objs::InsertObj(obj_b, OBJ_CARD, 10);//������J�[�h���I�u�W�F�N�g�}�l�[�W���[�ɓo�^
			//CObjViewCard* obj_viewcard = new CObjViewCard(Ctype); //��ʍ���̊Ϗܗp�J�[�h�쐬
			//Objs::InsertObj(obj_viewcard, OBJ_VIEWCARD, 1); //������Ϗܗp�J�[�h���I�u�W�F�N�g�}�l�[�W���[�ɓo�^
		}

		if (Cardcount == 4 && Turn == true || Cardcount == 5 && Turn == false)
		{
			Start = true;
		}

		//�N���b�N���̏���
		if (m_l == true)
		{
			//�^�[���J�n���@�f�b�L���N���b�N���ăh���[ 
			if (mou->m_mouse_x > 1082.0f&&
				mou->m_mouse_x < 1210.0f&&
				mou->m_mouse_y > 739.0f&&
				mou->m_mouse_y < 859.0f&&
				pos->PTrun == false &&
				m_l == true &&
				m_c == true &&
				m_f2 == true &&
				r_f != true)
			{
				Turn = true;
				m_f2 = false;
				Button2 = false;
				TurnCount++;
			}
			//�^�[���I���{�^��
			else if (mou->m_mouse_x > 12 &&
				mou->m_mouse_x < 275 &&
				mou->m_mouse_y > 391 &&
				mou->m_mouse_y < 510 &&
				pos->PTrun == true &&
				m_f2 == true &&
				m_c == true &&
				r_f != true)
			{
				pos->PTrun = false;
				m_f2 = false;
				m_l = false;
				Button2 = true;
				PrecedingAttack = false;
			}
			else
			{
				m_f2 = true;
			}

			//�s�k�����E���^�C�A
			if (mou->m_mouse_x > 19 &&
				mou->m_mouse_x < 162 &&
				mou->m_mouse_y > 809 &&
				mou->m_mouse_y < 880 &&
				pos->PTrun == true &&
				m_c == true &&
				r_f != true)
			{
				r_f = true; //�{���Ƀ��^�C�A���邩�̊m�F�E�B���h�E��\��
			}

			//�{���Ƀ��^�C�A���邩�̊m�F�E�B���h�E�̏���
			if (r_f == true)
			{
				//�u�͂��v�̏ꍇ
				if (mou->m_mouse_x > 600 &&
					mou->m_mouse_x < 672 &&
					mou->m_mouse_y > 420 &&
					mou->m_mouse_y < 456 &&
					m_c == true)
				{
					Scene::SetScene(new CSceneGameover());
				}
				//�u�������v�̏ꍇ
				else if (mou->m_mouse_x > 900 &&
					mou->m_mouse_x < 972 &&
					mou->m_mouse_y > 420 &&
					mou->m_mouse_y < 456 &&
					m_c == true)
				{
					r_f = false;
				}
			}

			m_c = false; //�N���b�N����
		}
		else
		{
			m_c = true; //�N���b�N����
		}
		if (Button2 == true)
		{
			DrawButton_time++;
			if (DrawButton_time < 30)
				DrawButton_y++;
			else if (DrawButton_time < 60)
				DrawButton_y--;
			else
			{
				DrawButton_time = 0;
				DrawButton_y = 0;
			}
		}
		else
		{
			DrawButton_time = 0;
			DrawButton_y = 0;
		}
	}
}

//�h���[
void CObjDekc::Draw()
{
	CObjMap* pos = (CObjMap*)Objs::GetObj(OBJ_MAP);

	//�J�[�h�̑傫���͉��R�A�c�S�ɂ���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	float d[4] = { 0.0f,0.0f,0.0f,1.0f };
	RECT_F src;
	RECT_F dst;
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 128.0f;
	src.m_bottom = 128.0f;

	dst.m_top = 0.0f + y;
	dst.m_left = 0.0f + x;
	dst.m_right = 128.0f + x;
	dst.m_bottom = 128.0f + y;

	wchar_t str[128];

	//swprintf_s(str, L"%d", Cost);
	//Font::StrDraw(str, 10, 10, 20, c);
	Draw::Draw(0, &src, &dst, c, 0.0f);

	//�f�b�L�̎c�薇���\��
	if (Deckcount - Cardcount >= 10)
	{
		swprintf_s(str, L"%d", Deckcount - Cardcount);
		Font::StrDraw(str, 1105, 780, 50, d);
	}
	else
	{
		swprintf_s(str, L"%d", Deckcount - Cardcount);
		Font::StrDraw(str, 1118, 780, 50, d);
	}

	if (Button2 == true)
	{
		src.m_top = 128.0f;
		src.m_left = 0.0f;
		src.m_right = 64.0f;
		src.m_bottom = 201.0f;

		dst.m_top = 690.0f - DrawButton_y;
		dst.m_left = 1100.0f;
		dst.m_right = 1160.0f;
		dst.m_bottom = 763.0f - DrawButton_y;

		Draw::Draw(3, &src, &dst, c, 0);
	}	
	if (pos->PTrun == true)
	{
		//���^�[����Trun End�̕�����\��
		swprintf_s(str, L"�^�[���G���h");
		Font::StrDraw(str, 30, 430, 37, d);

		//"�~�Q"�̕\��
		swprintf_s(str, L"���^�C�A");
		Font::StrDraw(str, 28, 827, 30, d);

		//���݂̃^�[�����̕\��
		float a[4] = { 1.0f,1.0f,0.0f,1.0f };
		swprintf_s(str, L"%d�^�[����", TurnCount);
		Font::StrDraw(str, 200, 827, 30, a);
	}
	if (r_f == true)
	{
		src.m_top = 64.0f;
		src.m_left = 0.0f;
		src.m_right = 189.0f;
		src.m_bottom = 121.0f;

		dst.m_top = 300.0f;
		dst.m_left = 500.0f;
		dst.m_right = 1100.0f;
		dst.m_bottom = 500.0f;

		SetPrio(100);

		Draw::Draw(3, &src, &dst, c, 0);

		swprintf_s(str, L"�{���Ƀ��^�C�A���܂����H");
		Font::StrDraw(str, 595, 330, 36, c);
		swprintf_s(str, L"�͂�");
		Font::StrDraw(str, 600, 420, 36, c);
		swprintf_s(str, L"������");
		Font::StrDraw(str, 900, 420, 36, c);
	}
}