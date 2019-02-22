//使用するヘッダー
#include "GameL\DrawFont.h"
#include"GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include"GameL\Audio.h"

#include "GameHead.h"
#include "ObjGameover.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjGameover::Init()
{

	m_key_flag = true;
	go = false;
	t_t = -500.0f;
	t_b = -328.0f;
	cou = 0;
	i = 0;
	j = 0;
	m_c = true;

	Audio::LoadAudio(9, L"Audio\\敗北.wav", BACK_MUSIC);
	Audio::LoadAudio(12, L"Audio\\ドン.wav", EFFECT);

	Audio::Start(9);
	

}

//アクション
void CObjGameover::Action()
{
	CObjmouse*mou = (CObjmouse*)Objs::GetObj(OBJ_MAUSE);

	m_l = Input::GetMouButtonL();


	//スペースキーを押すとシーン変更
	if (m_l == true)
	{
		if (mou->m_mouse_x > 0 && mou->m_mouse_x < 1200
			&& mou->m_mouse_y > 0 && mou->m_mouse_y < 900
			&& BGM == true && m_c == true)
		{
			Scene::SetScene(new CSceneTitle());
		}
		m_c = false;
	}
	else
	{
		m_c = true;
	}
	if (t_t < 500 && t_b < 500)
	{
		t_t += 4.0f;

		t_b += 4.0f;
		i++;
	}

	if (i == 207)
	{
		Audio::Start(12);
		i++;
		go = true;
	}

	if (go==true)
	{
		for (j = 0; j < 15000; j++)
		{
			if(j==14999)
			BGM = true;
		}	
	}





}

//ドロー
void CObjGameover::Draw()
{

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

	//Draw::Draw(5, &src, &dst, c, 0.0f);


		src.m_top = 67.0f;
		src.m_left = 200.0f;
		src.m_right = 388.0f;
		src.m_bottom = 122.0f;

		dst.m_top = t_t;
		dst.m_left = 310.0f;
		dst.m_right = 1010.0f;
		dst.m_bottom =t_b;

		Draw::Draw(3, &src, &dst, c, 0);

		if(BGM==true)
			Font::StrDraw(L"クリックでタイトルに戻る", 420, 500, 42, c);
}

//360.0f
// 570.0f