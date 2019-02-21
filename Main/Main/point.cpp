#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\DrawFont.h"
#include"GameL\HitBoxManager.h"


#include "GameHead.h"
#include "Deck.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�f�X�g���N�^
CObjpoint::CObjpoint()
{

};

CObjpoint::~CObjpoint()
{

};

//�C�j�V�����C�Y
void CObjpoint::Init()
{
	m_point = 0;
	m_flag_point = false;
	m_p=true;
	Cost = 100;
	e_Cost = 0;
	AddCost = 0;
	time = 0;
};

//�A�N�V����
void CObjpoint::Action()
{
	CObjDekc*sc = (CObjDekc*)Objs::GetObj(OBJ_DEKC);
	CObjEnemyDeck*pos = (CObjEnemyDeck*)Objs::GetObj(OBJ_ENEMY_DECK);
	if(sc->Turn==true)
	Cost = sc->m_point;
	AddCost = sc->i - 2;
	if (sc->Turn == true)
	{
		time++;
	}
	else
	{
		time = 0;
	}
		Cost = sc->m_point;
	if (pos->EDraw == false)
		e_Cost = pos->e_point;
};

//�h���[
void CObjpoint::Draw()
{
	CObjMap* pos = (CObjMap*)Objs::GetObj(OBJ_MAP);


	float c[4] = { 0.0f,0.0f,0.0f,1.0f };
	float d[4] = { 0.0f,0.0f,0.0f,1.0f };
	wchar_t str[128];

	//�������Ă���}�i(�S�[���h�H)��\��
	if (Cost >= 10000)
	{
		swprintf_s(str, L"%d", Cost);
		Font::StrDraw(str, 315, 425, 55, c);
	}
	else if (Cost >= 1000)
	{
		swprintf_s(str, L"%d", Cost);
		Font::StrDraw(str, 325, 420, 60, c);
	}
	else if (Cost >= 100)
	{
		swprintf_s(str, L"%d", Cost);
		Font::StrDraw(str, 340, 420, 60, c);
	}
	else
	{
		swprintf_s(str, L"%d", Cost);
		Font::StrDraw(str, 370, 420, 60, c);
	}



	//swprintf_s(str, L"%d", 100 * AddCost);
	//Font::StrDraw(str, 380, 200, 60, c);

	//�G�̏������Ă���}�i(�S�[���h�H)��\��
	if (e_Cost >= 10000)
	{
		swprintf_s(str, L"%d", e_Cost);
		Font::StrDraw(str, 1082, 58, 35, c);
	}
	else if (e_Cost >= 1000)
	{
		swprintf_s(str, L"%d", e_Cost);
		Font::StrDraw(str, 1085, 55, 40, c);
	}
	else if (e_Cost >= 100)
	{
		swprintf_s(str, L"%d", e_Cost);
		Font::StrDraw(str, 1095, 55, 40, c);
	}
	else
	{
		swprintf_s(str, L"%d", e_Cost);
		Font::StrDraw(str, 1116, 56, 40, c);
	}
};
