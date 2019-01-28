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

	Audio::LoadAudio(9, L"Audio\\敗北.wav", BACK_MUSIC);


	Audio::Start(9);
}

//アクション
void CObjGameover::Action()
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
void CObjGameover::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	Font::StrDraw(L"ヤラレチャッタ", 430, 220, 32, c);
	Font::StrDraw(L"スペースキーでタイトルに戻る", 410, 500, 32, c);
}