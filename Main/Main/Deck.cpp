//�V���E�X���w�b�_�[�t�@�C��
#include"GameL\DrawTexture.h"
#include"GameHead.h"
#include"Deck.h"
#include"GameL\WinInputs.h"
#include"GameL\HitBoxManager.h"
#include"GameL\DrawFont.h"
#include<stdlib.h>
#include<time.h>

//�g�p����l�[���X�y�[�X

//�C�j�V�����C�Y
void CObjDekc::Init()
{
	//x.y�f�b�L�̈ʒu
	x = 900;
	y = 630;
	//m_x,m_y �J�[�h�̏o���ʒu����
	m_x = 500;
	m_y = 630;
	//�������̖h�~����
	m_f = true;

	//stop �����J�[�h�̏o���j�~
	stop = 0;

	//Cnanber �J�[�h�̈ʒu�����p
	Cnanber = 0;

	//Cardcount ���݃h���[���������@���݃v���O�����쐬��
	Cardcount = 0;

	//Start�ŏ��̂T���h���[�̂��߂̕ϐ�
	Start = false;

	//�����|�C���g
	m_point = 1;

	srand((unsigned)time(NULL));
}

//�A�N�V����
void CObjDekc::Action()
{
	CObjHand*sc = (CObjHand*)Objs::GetObj(OBJ_HAND);
	Card = rand() % 14+1;//�����ԍ��̃J�[�h�ďo
	stop = 1;

	//�ʂ̃J�[�h���o��܂Ń��[�v
	while(stop==1){
		stop = 0;
		Card = rand() % 14+1;

		for(int i=0;i<Cardcount;i++)
		{
			if(Deck[i]==Card)
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

	else
	{
		Ctype = shield;
	}


	//�X�^�[�g����
	if(Start==false){
		Deck[Cardcount] = Card;//�f�b�L�Ƀh���[�����J�[�h��o�^
		sc->hand[Cnanber] = Card;//��D�Ƀh���[�����J�[�h��o�^
		sc->basyo[Cnanber] = Cnanber + 1;
		Cnanber++;
		Cardcount++;
		CObjCard* obj_b = new CObjCard(m_x,m_y,Ctype);//�J�[�h�쐬
		Objs::InsertObj(obj_b, OBJ_CARD, 10);//������J�[�h���I�u�W�F�N�g�}�l�[�W���[�ɓo�^
	}

	if(Cardcount==5)
	{
		Start = true;
	}

	if (Input::GetVKey('Z') == true && Start == true)
	{
		if (m_f == true)
		{
			Deck[Cardcount] = Card;//�f�b�L�Ƀh���[�����J�[�h��o�^
			sc->hand[Cnanber] = Card;//��D�Ƀh���[�����J�[�h��o�^
			sc->basyo[Cnanber] = Cnanber + 1;
			Cnanber++;
			Cardcount++;
			//�J�[�h�쐬
			CObjCard* obj_b = new CObjCard(300,m_y, Ctype);//�J�[�h�쐬
			Objs::InsertObj(obj_b, OBJ_CARD, 10);//������J�[�h���I�u�W�F�N�g�}�l�[�W���[�ɓo�^
			m_f = false;
			
			//�h���[������|�C���g����
			m_point++;
		}

	}

	else {
		m_f = true;
	}
}

//�h���[
void CObjDekc::Draw()
{
	//�J�[�h�̑傫���͉��R�A�c�S�ɂ���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
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

	/*wchar_t str[128];

	swprintf_s(str, L"%d", m_point);

	Font::StrDraw(str, 10, 10, 20, c);*/

	Draw::Draw(0, &src, &dst, c, 0.0f);

}