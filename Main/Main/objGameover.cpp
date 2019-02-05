//使用するヘッダー
#include "GameL\DrawFont.h"
#include"GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include"GameL\Audio.h"

#include "GameHead.h"
#include "ObjGameover.h"
#include "PHero.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjGameover::Init()
{

	m_key_flag = true;
	go = false;

	Audio::LoadAudio(9, L"Audio\\敗北.wav", BACK_MUSIC);


	Audio::Start(9);
}

//アクション
void CObjGameover::Action()
{
	CObjmouse*mou = (CObjmouse*)Objs::GetObj(OBJ_MAUSE);
	CObjPHero*ph = (CObjPHero*)Objs::GetObj(OBJ_PHERO);

	m_l = Input::GetMouButtonL();


	//スペースキーを押すとシーン変更
	/*if (m_l == true)
	{
		if (mou->m_mouse_x > 700 && mou->m_mouse_x < 994
			&& mou->m_mouse_y > 500 && mou->m_mouse_y < 542)
		{
			Scene::SetScene(new CSceneTitle());
		}
	}*/
}

//ドロー
void CObjGameover::Draw()
{

	CObjPHero*ph = (CObjPHero*)Objs::GetObj(OBJ_PHERO);

	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;
	RECT_F dst;
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 640.0f;
	src.m_bottom = 480.0f;

	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 1200.0f;
	dst.m_bottom = 900.0f;

	Draw::Draw(5, &src, &dst, c, 0.0f);

	if (ph->GO == true)
	{
		src.m_top = 172.0f;
		src.m_left = 0.0f;
		src.m_right = 64.0f;
		src.m_bottom = 236.0f;

		dst.m_top = 310.0f;
		dst.m_left = 360.0f;
		dst.m_right = 1100.0f;
		dst.m_bottom = 580.0f;

		Draw::Draw(3, &src, &dst, c, 0);
	}

	//Font::StrDraw(L"タイトルに戻る", 700, 500, 42, c);
}