//使用するヘッダー
#include "GameL\DrawFont.h"
#include"GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"

#include "GameHead.h"
#include "ObjGameover.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjGameover::Init()
{

}

//アクション
void CObjGameover::Action()
{

}

//ドロー
void CObjGameover::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	Font::StrDraw(L"ヤラレチャッタ", 430, 220, 32, c);
}