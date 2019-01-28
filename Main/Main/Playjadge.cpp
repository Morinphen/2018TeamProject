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

};

//�A�N�V����
void CObjJadge::Action()
{
	CObjDekc*sc = (CObjDekc*)Objs::GetObj(OBJ_DEKC);

	srand(time(NULL));
	Random = rand() % 2;

	Stime++;
	SetPrio(20);

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
			sc->StartG = true;
		}
		else
		{
			sc->Turn = false;
			sc->StartG = true;
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
	if (Stime < 90 && Stime % 2 == 0 || First == true)
	{
		src.m_top = 0.0f;
		src.m_left = 128.0f;
		src.m_right = 192.0f;
		src.m_bottom = 64.0f;
	}

	else if (Stime < 90 && Stime % 2 == 1 || After == true)
	{
		src.m_top = 0.0f;
		src.m_left = 192.0f;
		src.m_right = 256.0f;
		src.m_bottom = 64.0f;
	}

	dst.m_top = 300.0f;
	dst.m_left = 650.0f;
	dst.m_right = 950.0f;
	dst.m_bottom = 600.0f;

	Draw::Draw(3, &src, &dst, c, 0.0f);

	wchar_t str[128];

	if (Stime < 90 && Stime % 2 == 0 || First == true) {
		swprintf_s(str, L"��U");
		Font::StrDraw(str, 735, 420, 60, c);
	}

	else if (Stime < 90 && Stime % 2 == 1 || After == true) {
		swprintf_s(str, L"��U");
		Font::StrDraw(str, 735, 420, 60, c);
	}
};
