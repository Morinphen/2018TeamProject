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
#include "SceneGameover.h"

//コンストラクタ
CSceneGameover::CSceneGameover()
{

}

//デストラクタ
CSceneGameover::~CSceneGameover()
{

}

//ゲームメイン初期化メソッド
void CSceneGameover::InitScene()
{
	//出力させる文字のグラフィックを作成
	Font::SetStrTex(L"Arma Batlle");
	Draw::LoadImageW(L"Game Over.png", 5, TEX_SIZE_1024);

	CObjGameover* obj = new CObjGameover();	//タイトルオブジェクト作成
	Objs::InsertObj(obj, OBJ_GAMEOVER, 10);//主人公オブジェクト登録

	//マウスオブジェクト作成
	CObjmouse* obj_mouse = new CObjmouse();
	Objs::InsertObj(obj_mouse, OBJ_MAUSE, 100);
}

//ゲームメイン実行中メソッド
void CSceneGameover::Scene()
{

}
