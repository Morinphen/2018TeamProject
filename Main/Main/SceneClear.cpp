#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"
#include"GameL\DrawTexture.h"

//使用するネームスペース
using namespace GameL;

#include "SceneClear.h"
#include "GameHead.h"
#include "SceneTitle.h"

//コンストラクタ
CSceneClear::CSceneClear()
{

}

//デストラクタ
CSceneClear::~CSceneClear()
{

}

//ゲームメイン初期化メソッド
void CSceneClear::InitScene()
{
	//出力させる文字のグラフィックを作成
	Font::SetStrTex(L"Arma Batlle");
	Draw::LoadImageW(L"image2.png", 0, TEX_SIZE_512);

	CObjClear* obj = new CObjClear();	//タイトルオブジェクト作成
	Objs::InsertObj(obj, OBJ_CLEAR, 10);//主人公オブジェクト登録

	//タイトルオブジェクト作成
	//CObjTitle* obj = new CObjTitle();	//タイトルオブジェクト作成
	//Objs::InsertObj(obj, OBJ_TITLE, 10);//主人公オブジェクト登録

}

//ゲームメイン実行中メソッド
void CSceneClear::Scene()
{

}
