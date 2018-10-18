//使用するヘッダーファイル
#include"GameL\DrawFont.h"
#include "GameHead.h"
#include "mouse.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjmouse::Init()
{
	POINT point;
}

//アクション
void CObjmouse::Action()
{
	GetCursorPos(&point);
}

//ドロー
void CObjmouse::Draw()
{
	float c[4] = { 1,1,1,1 };
	CDrawFont::StrDraw(L"aiueo",100,100,16,c);
}