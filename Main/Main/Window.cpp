#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\DrawFont.h"
#include"GameL\HitBoxManager.h"


#include "GameHead.h"
#include "Deck.h"
#include "Window.h"

//使用するネームスペース
using namespace GameL;

//デストラクタ
CObjwindow::CObjwindow(int _x,int _y,int _z)
{
	x = _x;
	y = _y;
	OpenT = _z;
	Wdelete = false;
};

CObjwindow::~CObjwindow()
{

};

//イニシャライズ
void CObjwindow::Init()
{

};

//アクション
void CObjwindow::Action()
{
	SetPrio(20);

	if (Wdelete == true)
	{
		Hits::DeleteHitBox(this);
		this->SetStatus(false);
	}
};

//ドロー
void CObjwindow::Draw()
{
	//カードの大きさは横３、縦４にする
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;
	src.m_top = 64.0f;
	src.m_left = 0.0f;
	src.m_right = 192.0f;
	src.m_bottom = 128.0f;

	dst.m_top = 0.0f + y - 80;
	dst.m_left = 0.0f + x;
	dst.m_right = 600.0f + x;
	dst.m_bottom = 320.0f + y - 80;

	Draw::Draw(3, &src, &dst, c, 0.0f);

	wchar_t str[128];

	if (OpenT == 2 || OpenT == 3) {
		swprintf_s(str, L"誰に装備する？");
		Font::StrDraw(str, 700, 320, 30, c);
	}

	else if (OpenT == 4) {
		swprintf_s(str, L"誰に使う？");
		Font::StrDraw(str, 720, 320, 30, c);
	}
};
