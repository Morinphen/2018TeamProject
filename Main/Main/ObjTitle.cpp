//使用するヘッダー
#include "GameL\DrawTexture.h"
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
	m_l = true;
	m_f2 = true;
}

//アクション
void CObjTitle::Action()
{
	CObjmouse*mou = (CObjmouse*)Objs::GetObj(OBJ_MAUSE);

	m_l = Input::GetMouButtonL();

	//シーン変更
	if (m_l == true)
	{
		//ゲーム画面に
		if (mou->m_mouse_x > 495 && mou->m_mouse_x < 707
			&& mou->m_mouse_y > 390 && mou->m_mouse_y < 458)
		{
			Scene::SetScene(new CSceneMain());
		}
		//ゲーム終了
		else if (mou->m_mouse_x > 495 && mou->m_mouse_x < 707
			&& mou->m_mouse_y > 490 && mou->m_mouse_y < 558)
		{
			exit(0);
		}
	}
}
//ドロー
void CObjTitle::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;
	RECT_F dst;

	src.m_top = 0.0f;
	src.m_left = 30.0f;
	src.m_right = 480.0f;
	src.m_bottom = 320.0f;

	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 1200.0f;
	dst.m_bottom = 900.0f;

	Draw::Draw(4, &src, &dst, c, 0.0f);
	Font::StrDraw(L"Arma Batlle", 470, 200, 48, c);

	src.m_top = 64.0f;
	src.m_left = 0.0f;
	src.m_right = 190.0f;
	src.m_bottom = 121.0f;

	dst.m_top = 390.0f;
	dst.m_left = 495.0f;
	dst.m_right = 707.0f;
	dst.m_bottom = 458.0f;

	Draw::Draw(3, &src, &dst, c, 0.0f);
	Font::StrDraw(L"スタート", 505, 400, 48, c);

	src.m_top = 64.0f;
	src.m_left = 0.0f;
	src.m_right = 190.0f;
	src.m_bottom = 121.0f;

	dst.m_top = 490.0f;
	dst.m_left = 495.0f;
	dst.m_right = 707.0f;
	dst.m_bottom = 558.0f;

	Draw::Draw(3, &src, &dst, c, 0.0f);
	Font::StrDraw(L"終了する", 505, 500, 48, c);
}