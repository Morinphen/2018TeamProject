//�V���E�X���w�b�_�[�t�@�C��
#include"GameL\DrawTexture.h"
#include"GameHead.h"
#include"Deck.h"
#include"GameL\WinInputs.h"
#include"GameL\HitBoxManager.h"
#include"GameL\DrawFont.h"
//�g�p����l�[���X�y�[�X

//�C�j�V�����C�Y
void CObjDekc::Init()
{
	x = 650;
	y = 400;
	m_x = 100;
	m_y = 400;
	m_f = true;
	cardcou = 0;
	Start = false;
}

//�A�N�V����
void CObjDekc::Action()
{
	if(Start==false){
		for(int i=1;i<6;i++)
		{
			cardcou++;
			CObjCard* obj_b = new CObjCard(m_x * i,m_y);//�J�[�h�쐬
			Objs::InsertObj(obj_b, OBJ_CARD, 10);//������J�[�h���I�u�W�F�N�g�}�l�[�W���[�ɓo�^
		}
		Start = true;
	}

	if (Input::GetVKey('Z') == true)
	{
		if (m_f == true)
		{
			cardcou++;
			//�e�ۃI�u�W�F�N�g�쐬
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
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 64.0f;
	src.m_bottom = 64.0f;

	dst.m_top = 0.0f + y;
	dst.m_left = 0.0f + x;
	dst.m_right = 128.0f + x;
	dst.m_bottom = 192.0f + y;

	Draw::Draw(0, &src, &dst, c, 0.0f);
}