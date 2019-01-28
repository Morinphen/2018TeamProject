//使用するヘッダー
#include "GameL\DrawFont.h"
#include"GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include"GameL\Audio.h"

#include "GameHead.h"
#include "ObjClear.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjClear::Init()
{
	m_key_flag = true;

	Audio::LoadAudio(10, L"Audio\\勝利.wav", BACK_MUSIC);


	Audio::Start(10);
}

//アクション
void CObjClear::Action()
{



	//スペースキーを押すとシーン変更
	if (Input::GetVKey(VK_SPACE))
	{
		if (m_key_flag == true)
		{
			m_key_flag = false;
			Scene::SetScene(new CSceneTitle());
		}
	}
}

//ドロー
void CObjClear::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	Font::StrDraw(L"アナタノカチ", 430, 220, 32, c);
	Font::StrDraw(L"スペースキーでタイトルに戻る", 410, 500, 32, c);
}