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
	x = 900;
	y = 630;
	m_x = 500;
	m_y = 630;
	m_f = true;
	stop = 0;
	cardcou = 0;
	Cardcount = 0;
	Start = false;
	srand((unsigned)time(NULL));
}

//�A�N�V����
void CObjDekc::Action()
{
	Card = rand() % 14+1;
	stop = 1;
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

	if(Start==false){
		Deck[Cardcount] = Card;
		cardcou++;
		Cardcount++;
		CObjCard* obj_b = new CObjCard(m_x,m_y);//�J�[�h�쐬
		Objs::InsertObj(obj_b, OBJ_CARD, 10);//������J�[�h���I�u�W�F�N�g�}�l�[�W���[�ɓo�^
	}

	if(Cardcount==5)
	{
		Start = true;
	}

	if (Input::GetVKey('Z') == true)
	{
		if (m_f == true)
		{
			Deck[Cardcount] = Card;
			cardcou++;
			Cardcount++;
			//�J�[�h�쐬
			CObjCard* obj_b = new CObjCard(300,m_y);//�J�[�h�쐬
			Objs::InsertObj(obj_b, OBJ_CARD, 10);//������J�[�h���I�u�W�F�N�g�}�l�[�W���[�ɓo�^
			m_f = false;
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

	Draw::Draw(0, &src, &dst, c, 0.0f);
}