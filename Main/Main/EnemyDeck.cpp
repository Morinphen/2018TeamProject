//�V���E�X���w�b�_�[�t�@�C��
#include"GameL\DrawTexture.h"
#include"GameHead.h"
#include"EnemyDeck.h"
#include"GameL\WinInputs.h"
#include"GameL\HitBoxManager.h"
#include"GameL\DrawFont.h"
#include<stdlib.h>
#include<time.h>
//�g�p����l�[���X�y�[�X

//�C�j�V�����C�Y
void CObjEnemyDeck::Init()
{
	//x.y�f�b�L�̈ʒu
	x = 408;
	y = 38;
	//m_x,m_y �J�[�h�̏o���ʒu����
	m_x = 927;
	m_y = 38;
	//�������̖h�~����
	m_f = true;

	//stop �����J�[�h�̏o���j�~
	stop = 0;

	//�J�[�h�̉�]�`�撲��
	Rotdraw = 0;

	//Cnanber �J�[�h�̈ʒu�����p
	Cnanber = 0;

	//Cardcount ���݃h���[���������@���݃v���O�����쐬��
	e_Cardcount = 0;

	//Start�ŏ��̂T���h���[�̂��߂̕ϐ�
	Start = false;

	set = 0;
	Recount = 0;

	srand((unsigned)time(NULL));
}

//�A�N�V����
void CObjEnemyDeck::Action()
{
	Rotdraw = 180;//�J�[�h��180����]
	CObjEnemyHand*sc = (CObjEnemyHand*)Objs::GetObj(OBJ_ENEMY_HAND);
	e_Card = rand() % 14 + 1;//�����ԍ��̃J�[�h�ďo
	stop = 1;

	//�ʂ̃J�[�h���o��܂Ń��[�v
	while (stop == 1) {
		stop = 0;
		e_Card = rand() % 14 + 1;

		for (int i = 0; i < e_Cardcount; i++)
		{
			if (EnemyDeck[i] == e_Card)
			{
				stop = 1;
			}
		}

	}

	//�X�^�[�g����
	if (Start == false) {
		EnemyDeck[e_Cardcount] = e_Card;//�f�b�L�Ƀh���[�����J�[�h��o�^
		sc->hand[Cnanber] = e_Card;//��D�Ƀh���[�����J�[�h��o�^
		sc->basyo[Cnanber] = Cnanber + 1;
		Cnanber++;
		e_Cardcount++;
		CObjEnemyCard* obj_b = new CObjEnemyCard(m_x, m_y);//�J�[�h�쐬
		Objs::InsertObj(obj_b, OBJ_ENEMY_CARD, 10);//������J�[�h���I�u�W�F�N�g�}�l�[�W���[�ɓo�^
	}

	if (e_Cardcount == 5)
	{
		Start = true;
	}

	if (Input::GetVKey('X') == true && Start == true)
	{
		if (m_f == true)
		{
			EnemyDeck[e_Cardcount] = e_Card;//�f�b�L�Ƀh���[�����J�[�h��o�^
			sc->hand[Cnanber] = e_Card;//��D�Ƀh���[�����J�[�h��o�^
			sc->basyo[Cnanber] = Cnanber + 1;
			Cnanber++;
			e_Cardcount++;
			//�J�[�h�쐬
			CObjEnemyCard* obj_b = new CObjEnemyCard(500, m_y);//�J�[�h�쐬
			Objs::InsertObj(obj_b, OBJ_ENEMY_CARD, 10);//������J�[�h���I�u�W�F�N�g�}�l�[�W���[�ɓo�^
			m_f = false;
		}
	}

	else
	{
		m_f = true;
	}
}

//�h���[
void CObjEnemyDeck::Draw()
{
	//�J�[�h�̑傫���͉��R�A�c�S�ɂ���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 128.0f;
	src.m_bottom = 128.0f;

	dst.m_top = 128.0f + y;
	dst.m_left = 128.0f + x - 36;
	dst.m_right = 0.0f + x - 36;
	dst.m_bottom = 0.0f + y;

	Draw::Draw(0, &src, &dst, c, 0.0f);
}