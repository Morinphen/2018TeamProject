#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\DrawFont.h"
#include"GameL\HitBoxManager.h"


#include "GameHead.h"
#include "Deck.h"

//使用するネームスペース
using namespace GameL;

//デストラクタ
CObjpoint::CObjpoint()
{

};

CObjpoint::~CObjpoint()
{

};

//イニシャライズ
void CObjpoint::Init()
{
	m_point = 0;
	m_flag_point = false;
	m_p=true;
	Cost = 1;
};

//アクション
void CObjpoint::Action()
{
	CObjDekc*sc = (CObjDekc*)Objs::GetObj(OBJ_DEKC);
	if(sc->Turn==true)
	Cost = sc->m_point;

};

//ドロー
void CObjpoint::Draw()
{
	CObjMap* pos = (CObjMap*)Objs::GetObj(OBJ_MAP);


	float c[4] = { 100.0f,1.0f,1.0f,1.0f };
	wchar_t str[128];

	swprintf_s(str, L"%d", Cost);
	Font::StrDraw(str, 60, 10, 20, c);

	if (pos->PTrun==false)
	{
		swprintf_s(str, L"end");
		Font::StrDraw(str, 90, 150, 20, c);
	}

};
