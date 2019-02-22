#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\DrawFont.h"
#include"GameL\HitBoxManager.h"

#include<stdlib.h>
#include<time.h>

#include "GameHead.h"
#include "Deck.h"
#include "Playjadge.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

extern int TurnCount; //���݂̃^�[������\�����邽�߂̕ϐ�
bool PrecedingAttack = true; //��s�͍U���ł��Ȃ��̂��Q�Ƃ���ϐ� true=�U���� false=�U���s��

//�R���X�g���N�^
CObjJadge::CObjJadge()
{
	Stime = 0;
	GameStart = false;
	First = false;
	After = false;
};

CObjJadge::~CObjJadge()
{

};

//�C�j�V�����C�Y
void CObjJadge::Init()
{
	C_y = 0;
};

//�A�N�V����
void CObjJadge::Action()
{
	CObjDekc*sc = (CObjDekc*)Objs::GetObj(OBJ_DEKC);
	CObjEnemyDeck*ec = (CObjEnemyDeck*)Objs::GetObj(OBJ_ENEMY_DECK);

	srand(time(NULL));
	Random = rand() % 2;

	Stime++;
	SetPrio(20);

	if (Stime < 45)
		C_y += 3;
	else if (Stime <= 90)
		C_y -= 3;

	if (Stime == 90)
	{
		if (Random == 0)
		{
			First = true;
		}
		else
		{
			After = true;
		}
	}

	if (Stime == 150)
	{
		if (First == true)
		{
			sc->Turn = true;
			sc->STurn = true;
			sc->Button2 = false;
			sc->StartG = true;
			PrecedingAttack = true;
			TurnCount++;
			ec->EStartG = true;
		}
		else
		{
			sc->Turn = false;
			sc->STurn = false;
			sc->Button2 = true;
			sc->StartG = true;
			PrecedingAttack = false;
			ec->EStartG = true;
			ec->StartED = true;
		}

		Hits::DeleteHitBox(this);
		this->SetStatus(false);
	}
};

//�h���[
void CObjJadge::Draw()
{
	//�J�[�h�̑傫���͉��R�A�c�S�ɂ���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;
	if (Stime < 90 && Stime % 4 == 0 || First == true)
	{
		src.m_top = 0.0f;
		src.m_left = 127.0f;
		src.m_right = 188.0f;
		src.m_bottom = 63.0f;
	}

	else if (Stime < 90 && Stime % 4 == 2 || After == true)
	{
		src.m_top = 0.0f;
		src.m_left = 191.0f;
		src.m_right = 252.0f;
		src.m_bottom = 63.0f;
	}

	else if(Stime < 90 && Stime % 4 == 1 || Stime < 90 && Stime % 4 == 3)
	{
		src.m_top = 0.0f;
		src.m_left = 254.0f;
		src.m_right = 318.0f;
		src.m_bottom = 64.0f;
	}

	dst.m_top = 300.0f - C_y;
	dst.m_left = 650.0f;
	dst.m_right = 950.0f;
	dst.m_bottom = 600.0f - C_y;

	Draw::Draw(3, &src, &dst, c, 0.0f);

	wchar_t str[128];

	if (First == true) {
		swprintf_s(str, L"��U");
		Font::StrDraw(str, 735, 420 - C_y, 60, c);
	}

	else if (After == true) {
		swprintf_s(str, L"��U");
		Font::StrDraw(str, 735, 420 - C_y, 60, c);
	}
};
