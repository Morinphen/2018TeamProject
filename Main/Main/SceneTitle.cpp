#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include"GameL\DrawTexture.h"
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"

//使用するネームスペース
using namespace GameL;

#include "SceneMain.h"
#include "GameHead.h"
#include "SceneTitle.h"

//コンストラクタ
CSceneTitle::CSceneTitle()
{

}

//デストラクタ
CSceneTitle::~CSceneTitle()
{

}

//ゲームメイン初期化メソッド
void CSceneTitle::InitScene()
{
	//出力させる文字のグラフィックを作成
	Font::SetStrTex(L"Arma Batlle");
	Draw::LoadImageW(L"image4.png", 3, TEX_SIZE_512);
	Draw::LoadImageW(L"Title.png", 4, TEX_SIZE_512);

	//タイトルオブジェクト作成
	CObjTitle* obj = new CObjTitle();	//タイトルオブジェクト作成
	Objs::InsertObj(obj, OBJ_TITLE, 0);//主人公オブジェクト登録

	//マウスオブジェクト作成
	CObjmouse* obj_mouse = new CObjmouse();
	Objs::InsertObj(obj_mouse, OBJ_MAUSE, 100);
}

//ゲームメイン実行中メソッド
void CSceneTitle::Scene()
{
	
}
