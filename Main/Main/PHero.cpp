#include"GameL\DrawTexture.h"
#include"GameL\HitBoxManager.h"
#include"GameL\WinInputs.h"
#include"GameHead.h"
#include"PHero.h"
#include"Deck.h"
#include"Cardlist.h"
#include"GameL\Audio.h"

#include"GameL\DrawFont.h"

//�g�p����l�[���X�y�[�X
CObjPHero::CObjPHero()
{
	m_x = 738;
	m_y = 586;
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

	LWeapon = false;
	RWeapon = false;

	test = 1;

	//�U�������A��������������
	Punch = false;

	m_f = false;

	Hits::SetHitBox(this, m_x, m_y, 108, 144, ELEMENT_GREEN, OBJ_FIELD_PLAYER, 1);
}

//�A�N�V����
void CObjPHero::Action()
{
	m_l = Input::GetMouButtonL();
	CHitBox*hit = Hits::GetHitBox(this);
	CObjmouse*mou = (CObjmouse*)Objs::GetObj(OBJ_MAUSE);
	CObjMap* pos = (CObjMap*)Objs::GetObj(OBJ_MAP);

	if (start == false)
	{
		start = true;
		pos->PCard[0][0] = Hp;
		pos->PCard[0][1] = Atack;
		pos->PCard[0][2] = Guard;
		pos->PCard[0][3] = 0;
	}

	Hp = pos->PCard[0][0];
	if (Hp <= 0 || Input::GetVKey('Q'))
	{
		Scene::SetScene(new CSceneGameover());
	}

	if (m_l == true)
	{
		if (mou->EChoice == true && Punch == true)
		{
			if (pos->PCard[0][1] - pos->ECard[2] > 0)
				pos->ECard[0] -= pos->PCard[0][1] - pos->ECard[2];//�G��HP�����g�̍U����-�G�̎���������_���[�W��^����

			if (pos->ECard[1] - pos->PCard[0][2] > 0)
				pos->PCard[0][0] -= pos->ECard[1] - pos->PCard[0][2];//�G�̍U����-���g��HP�̕������_���[�W���󂯂�

			//�I���������ɖ߂�
			test = 1;
			Punch = false;
			Audio::Start(8);
		}

		else if (mou->EChoice2 == true && Punch == true)
		{
			if (pos->PCard[0][1] - pos->ECard2[2]>0)
				pos->ECard2[0] -= pos->PCard[0][1] - pos->ECard2[2];

			if (pos->ECard2[1] - pos->PCard[0][2]>0)
				pos->PCard[0][0] -= pos->ECard2[1] - pos->PCard[0][2];
			test = 1;
			Punch = false;
			Audio::Start(8);
		}

		else if (mou->EChoice3 == true && Punch == true)
		{

			if (pos->PCard[0][1] - pos->ECard3[2]>0)
				pos->ECard3[0] -= pos->PCard[0][1] - pos->ECard3[2];

			if (pos->ECard3[1] - pos->PCard[0][2]>0)
				pos->PCard[0][0] -= pos->ECard3[1] - pos->PCard[0][2];

			test = 1;
			Punch = false;
			Audio::Start(8);
		}

		else
		{
			test = 1;
			Punch = false;
		}

	}

	if (hit->CheckObjNameHit(OBJ_PLAYER) != nullptr && pos->Wtouch == false)
	{
		//CardHitCheck = true; //"�}�E�X���J�[�h�ɐG��Ă��Ȃ�"��Ԃɂ���
		Rotdraw = -3;
		SetPrio(11);
		if (m_l == true && pos->WSummon == false)
		{
			test = 0;
			Punch = true;
		}
	}

	else
	{
		//CardHitCheck = false; //"�}�E�X���J�[�h�ɐG��Ă��Ȃ�"��Ԃɂ���
		Rotdraw = 0;
		SetPrio(10);
	}
}

//�h���[
void CObjPHero::Draw()
{

	float c[4] = { 1.0f,test,1.0f,1.0f };
	float d[4] = { 1.0f,0.0f,0.0f,1.0f };
	RECT_F src;
	RECT_F dst;
	CHitBox*hit = Hits::GetHitBox(this);

	src.m_top = 64.0f;
	src.m_left = 0.0f;
	src.m_right = 64.0f;
	src.m_bottom = 128.0f;

	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x;
	dst.m_right = 108.0f + m_x;
	dst.m_bottom = 144.0f + m_y;

	Draw::Draw(0, &src, &dst, c, Rotdraw);

	//��ʍ���Ɋg��摜��\��������

	if (hit->CheckObjNameHit(OBJ_PLAYER) != nullptr)
	{

		dst.m_top = 12.0f;
		dst.m_left = 12.0f;
		dst.m_right = 281.0f;
		dst.m_bottom = 371.0f;

		Draw::Draw(0, &src, &dst, c, 0);
	}
	/*else
	{

		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 64.0f;
		src.m_bottom = 64.0f;

		dst.m_top = 12.0f;
		dst.m_left = 13.0f;
		dst.m_right = 371.0f;
		dst.m_bottom = 491.0f;

		Draw::Draw(0, &src, &dst, c, 0);
	}*/


	wchar_t str[128];
	swprintf_s(str, L"%d�@%d�@%d", Atack, Hp, Guard);
	Font::StrDraw(str, m_x + 10, m_y + 100, 20, d);
}