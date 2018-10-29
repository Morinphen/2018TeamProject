#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\DrawFont.h"

#include "GameHead.h"
#include "point.h"

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
};

//アクション
void CObjpoint::Action()
{
	if (Input::GetVKey('P') == true)
	{
		if (m_p == true)
		{
			m_point++;
			m_p = false;
		}
	}
	else
	{
		m_p = true;
	}

};

//ドロー
void CObjpoint::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	wchar_t str[128];

	swprintf_s(str, L"%d", m_point);

	Font::StrDraw(str, 10, 10, 20, c);
};
