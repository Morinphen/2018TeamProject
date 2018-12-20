#include"GameL\DrawTexture.h"
#include"GameL\HitBoxManager.h"
#include"GameL\WinInputs.h"
#include"GameHead.h"
#include"EHero.h"
#include"Deck.h"
#include"Cardlist.h"

#include"GameL\DrawFont.h"

//�g�p����l�[���X�y�[�X
CObjEHero::CObjEHero()
{
	m_x = 747;
	m_y = 195;
}

//�C�j�V�����C�Y
void CObjEHero::Init()
{
	Updraw = 0;//�J�[�h�̕`��ʒu�̒���
	Rotdraw = 180;//�J�[�h�̉�]�`�撲��

	start = false;

	//�X�e�[�^�X�̏�����
	Hp = 20;
	Atack = 2;
	Guard = 0;

	LWeapon = false;
	RWeapon = false;

	test = 1;

	//�U�������A��������������
	Punch = false;

	m_f = false;

	Hits::SetHitBox(this, m_x, m_y, 90, 120, ELEMENT_ITEM, OBJ_FIELD_ENEMY, 1);
}

//�A�N�V����
void CObjEHero::Action()
{
	CHitBox*hit = Hits::GetHitBox(this);
	CObjmouse*mou = (CObjmouse*)Objs::GetObj(OBJ_MAUSE);
	CObjMap* pos = (CObjMap*)Objs::GetObj(OBJ_MAP);

	if (start == false)
	{
		start = true;
		pos->ECard[0] = Hp;
		pos->ECard[1] = Atack;
		pos->ECard[2] = Guard;
		pos->ECard[3] = 0;
	}

	Hp = pos->ECard[0];
	if (Hp <= 0)
	{
		Scene::SetScene(new CSceneClear());
	}

}

//�h���[
void CObjEHero::Draw()
{

	float c[4] = { 1.0f,test,1.0f,1.0f };
	float d[4] = { 1.0f,0.0f,0.0f,1.0f };
	RECT_F src;
	RECT_F dst;

	src.m_top = 192.0f;
	src.m_left = 0.0f;
	src.m_right = 64.0f;
	src.m_bottom = 256.0f;

	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x;
	dst.m_right = 90.0f + m_x;
	dst.m_bottom = 120.0f + m_y;

	Draw::Draw(0, &src, &dst, c, Rotdraw);

	//��ʍ���Ɋg��摜��\��������

	if (CardHitCheck == true)
	{

		dst.m_top = 12.0f;
		dst.m_left = 13.0f;
		dst.m_right = 371.0f;
		dst.m_bottom = 491.0f;

		Draw::Draw(0, &src, &dst, c, 0);
	}
	else
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
	}


	wchar_t str[128];
	swprintf_s(str, L"%d�@%d�@%d", Atack, Hp, Guard);
	Font::StrDraw(str, m_x + 10, m_y + 100, 20, d);
}