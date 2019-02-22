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

	//EDraw �^�[���I�����A�J�[�h���ꖇ����
	EDraw = true;

	e_Deckcount = 40; //�f�b�L�̎c�薇��

	//Start�ŏ��̂T���h���[�̂��߂̕ϐ�
	Start = false;
	EStartG = false;
	//Summon2 �P�^�[���̏�������
	Summon2 = false;

	StartED = false;

	//ETruntime ���̓G�^�[���o�ߎ���
	ETruntime = 0;

	for (int i = 0; i < 40; i++)
	{

		Data = rand() % 1331 + 10;

		Data = Data - (Data % 10);

		Data++;

		EnemyDeck[i] = Data;//�����ԍ��̃J�[�h�ďo

	}

	//�����|�C���g
	e_point = 100;
	e_Cost = 0;

	i = 1145140;

	set = 0;
	Recount = 0;

	srand((unsigned)time(NULL));
}

//�A�N�V����
void CObjEnemyDeck::Action()
{
	Rotdraw = 180;//�J�[�h��180����]
	CObjEnemyHand*sc = (CObjEnemyHand*)Objs::GetObj(OBJ_ENEMY_HAND);
	CObjDekc*pd = (CObjDekc*)Objs::GetObj(OBJ_DEKC);

	if (EStartG == true) {
		e_Card = rand() % 39 + 1;//�����ԍ��̃J�[�h�ďo
		stop = 1;

		//�ʂ̃J�[�h���o��܂Ń��[�v
		while (stop == 1)
		{
			stop = 0;
			e_Card = rand() % 39 + 1;

			if (e_Cardcount >= 39)
			{
				break;
			}

			for (int i = 0; i < e_Cardcount; i++)
			{
				if (EPullc[e_Card - 1] == EnemyDeck[e_Card - 1])
				{
					stop = 1;
				}
			}
		}

		if (EnemyDeck[e_Card - 1] <= 481)
		{
			Ctype = monster;
		}
		else if (EnemyDeck[e_Card - 1] <= 941)
		{
			Ctype = weapon;
		}
		else
		{
			Ctype = shield;
		}

		if (EDraw == false && pd->STurn == false && Start == true)
		{
			EPullc[e_Card - 1] = EnemyDeck[e_Card - 1];//�f�b�L�Ƀh���[�����J�[�h��o�^
			sc->hand[Cnanber] = e_Card;//��D�Ƀh���[�����J�[�h��o�^
			sc->basyo[Cnanber] = Cnanber + 1;
			Cnanber++;
			e_Cardcount++;
			//�J�[�h�쐬
			CObjEnemyCard* obj_b = new CObjEnemyCard(500, m_y, Ctype);//�J�[�h�쐬
			Objs::InsertObj(obj_b, OBJ_ENEMY_CARD, 10);//������J�[�h���I�u�W�F�N�g�}�l�[�W���[�ɓo�^
			m_f = false;
			//�h���[������|�C���g����
			i++;
			EDraw = true;
		}

		//�X�^�[�g����
		if (Start == false)
		{
			EPullc[e_Card - 1] = EnemyDeck[e_Card - 1];//�f�b�L�Ƀh���[�����J�[�h��o�^
			sc->hand[Cnanber] = e_Card;//��D�Ƀh���[�����J�[�h��o�^
			sc->basyo[Cnanber] = Cnanber + 1;
			Cnanber++;
			e_Cardcount++;
			CObjEnemyCard* obj_b = new CObjEnemyCard(m_x, m_y, Ctype);//�J�[�h�쐬
			Objs::InsertObj(obj_b, OBJ_ENEMY_CARD, 10);//������J�[�h���I�u�W�F�N�g�}�l�[�W���[�ɓo�^
		}

		if (e_Cardcount == 5)
		{
			Start = true;
		}

		if (pd->STurn == false && Start == true)
		{
			if (ETruntime == 0 && StartED == false)
			{
				EDraw = false;
				e_point += i * 100;
			}
			else
			{
				StartED = false;
				if(ETruntime==0)
					i++;
			}

			ETruntime++;
			if (ETruntime == 200)
			{
				ETruntime = 0;
				Summon2 = false;
				pd->STurn = true;
			}
		}

		if (e_Cardcount >= 40)
		{
			Scene::SetScene(new CSceneClear());
		}
	}
}

//�h���[
void CObjEnemyDeck::Draw()
{
	//�J�[�h�̑傫���͉��R�A�c�S�ɂ���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	float d[4] = { 0.0f,0.0f,0.0f,1.0f };
	RECT_F src;
	RECT_F dst;

	wchar_t str[128];

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 128.0f;
	src.m_bottom = 128.0f;

	dst.m_top = 128.0f + y;
	dst.m_left = 128.0f + x - 36;
	dst.m_right = 0.0f + x - 36;
	dst.m_bottom = 0.0f + y;
	
	Draw::Draw(0, &src, &dst, c, 0.0f);

	//�f�b�L�̎c�薇���\��
	if (e_Deckcount - e_Cardcount >= 10)
	{
		swprintf_s(str, L"%d", e_Deckcount - e_Cardcount);
		Font::StrDraw(str, 428, 70, 50, d);
	}
	else
	{
		swprintf_s(str, L"%d", e_Deckcount - e_Cardcount);
		Font::StrDraw(str, 441, 70, 50, d);
	}
}