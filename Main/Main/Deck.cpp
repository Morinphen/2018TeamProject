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

//�g�p����l�[���X�y�[�X

//�C�j�V�����C�Y
void CObjDekc::Init()
{
	//x.y�f�b�L�̈ʒu
	x = 1086;
	y = 743;
	//m_x,m_y �J�[�h�̏o���ʒu����
	//m_x = 567;
	m_y = 743;
	//�������̖h�~����
	m_f = true;
	m_f2 = true;
	//�^�[���J�n��
	Turn = true;

	//stop �����J�[�h�̏o���j�~
	stop = 0;

	//Cnanber �J�[�h�̈ʒu�����p
	Cnanber = 0;

	i = 1;

	//Cardcount ���݃h���[���������@���݃v���O�����쐬��
	Cardcount = 0;

	//Start�ŏ��̂T���h���[�̂��߂̕ϐ�
	Start = false;

	effect = false;

	//�����|�C���g
	//m_point = 1;
	m_point = 100;
	Cost = 0;
	m_flag_point = false;
	srand((unsigned)time(NULL));

}

//�A�N�V����
void CObjDekc::Action()
{

	CObjMap* pos = (CObjMap*)Objs::GetObj(OBJ_MAP);
	CObjHand*sc = (CObjHand*)Objs::GetObj(OBJ_HAND);
	CObjCard*car = (CObjCard*)Objs::GetObj(OBJ_CARD);
	CObjmouse*mou = (CObjmouse*)Objs::GetObj(OBJ_MAUSE);
	Card = rand() % 21 + 1;//�����ԍ��̃J�[�h�ďo
	stop = 1;

	m_l = Input::GetMouButtonL();


	//�ʂ̃J�[�h���o��܂Ń��[�v
	while (stop == 1) {
		stop = 0;
		Card = rand() % 21 + 1;

		for (int i = 0; i < Cardcount; i++)
		{
			if (Deck[i] == Card)
			{
				stop = 1;
			}
		}

	}

	if (Card <= 7)
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
	}


	if (Turn == true && Start == true || effect == true)
	{
		if (m_f == true || effect == true)
		{
			Deck[Cardcount] = Card;//�f�b�L�Ƀh���[�����J�[�h��o�^
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

			if (Turn == true) {
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

	else {
		m_f = true;
	}

	//�X�^�[�g����
	if (Start == false) {
		Deck[Cardcount] = Card;//�f�b�L�Ƀh���[�����J�[�h��o�^
		sc->hand[Cnanber] = Card;//��D�Ƀh���[�����J�[�h��o�^
		sc->basyo[Cnanber] = Cnanber + 1;
		Cnanber++;
		Cardcount++;
		CObjCard* obj_b = new CObjCard(m_x, m_y, Ctype);//�J�[�h�쐬
		Objs::InsertObj(obj_b, OBJ_CARD, 10);//������J�[�h���I�u�W�F�N�g�}�l�[�W���[�ɓo�^
											 //CObjViewCard* obj_viewcard = new CObjViewCard(Ctype); //��ʍ���̊Ϗܗp�J�[�h�쐬
											 //Objs::InsertObj(obj_viewcard, OBJ_VIEWCARD, 1); //������Ϗܗp�J�[�h���I�u�W�F�N�g�}�l�[�W���[�ɓo�^
	}

	if (Cardcount == 4)
	{
		Start = true;
	}

	//�^�[���J�n���@�f�b�L���N���b�N���ăh���[
	if (mou->m_mouse_x > 1083.0f&&mou->m_mouse_x < 1175.0f
		&&mou->m_mouse_y < 860.0f&&mou->m_mouse_y < 860.0f&&
		pos->PTrun == false && m_f2 == true && m_l == true)
	{
		Turn = true;
		m_f2 = false;

	}
	else
	{
		m_f2 = true;
	}

	//�^�[���I���{�^��
	if (m_l == true)
	{
		if (mou->m_mouse_x > 12 && mou->m_mouse_x < 275
			&& mou->m_mouse_y > 391 && mou->m_mouse_y < 510
			&& pos->PTrun == true && m_f2 == true)
		{
			pos->PTrun = false;
			m_f2 = false;
			m_l = false;
		}
		else
		{
			m_f2 = true;
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
	src.m_right = 64.0f;
	src.m_bottom = 64.0f;

	dst.m_top = 0.0f + y;
	dst.m_left = 0.0f + x;
	dst.m_right = 90.0f + x;
	dst.m_bottom = 120.0f + y;

	wchar_t str[128];

	swprintf_s(str, L"%d", Cost);
	Font::StrDraw(str, 10, 10, 20, c);
	Draw::Draw(0, &src, &dst, c, 0.0f);
	
	if (pos->PTrun == true)
	{
		//���^�[����Trun End�̕�����\��
		swprintf_s(str, L"Trun End");
		Font::StrDraw(str, 40, 425, 50, d);

		//"�~�Q"�̕\��
		swprintf_s(str, L"���^�C�A");
		Font::StrDraw(str, 28, 827, 30, d);
	}
}