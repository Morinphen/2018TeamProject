//使用するヘッダー
#include "GameL\DrawFont.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"

#include "GameHead.h"
#include "ObjTitle.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjTitle::Init()
{
	m_key_flag = false;
}

//アクション
void CObjTitle::Action()
{
	
	//エンターキーを押すとシーン変更
	if (GetKeyState(VK_UP))
	{
		m_key_flag = true;

		if (m_key_flag == true)
		{
			Scene::SetScene(new CSceneMain());
			m_key_flag = false;
		}
	}
	else if (GetKeyState(VK_SPACE))
	{
		exit(0);//スペースキーでゲームを終了する
	}

}

//ドロー
void CObjTitle::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	Font::StrDraw(L"Arma Batlle",310, 220, 32, c);

	Font::StrDraw(L"PushRightclick", 300, 400, 32, c);
	Font::StrDraw(L"終了するにはスペースキーを押してください", 200, 500, 32, c);
}