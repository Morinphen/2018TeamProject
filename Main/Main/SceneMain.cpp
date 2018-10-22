//ＳＴＬデバッグ機能をＯＦＦにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include"GameL\DrawTexture.h"
#include"GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;
//使用ヘッダー
#include"SceneMain.h"
#include"GameHead.h"

//コンストラクタ
CSceneMain::CSceneMain()
{

}

//デストラクタ
CSceneMain::~CSceneMain()
{

}

//ゲームメイン初期化メソッド
void CSceneMain::InitScene()
{
	Draw::LoadImageW(L"image2.png", 0, TEX_SIZE_512);
	Draw::LoadImageW(L"sakura.png", 1, TEX_SIZE_512);

	CObjDekc*obj = new CObjDekc();
	Objs::InsertObj(obj, OBJ_DEKC, 1);

	CObjmouse* obj_mouse = new CObjmouse();
	Objs::InsertObj(obj_mouse, OBJ_MAUSE, 1);

	CObjMau*obja = new CObjMau();
	Objs::InsertObj(obja, OBJ_PLAYER, 11);
}

//ゲームメイン実行中メソッド
void CSceneMain::Scene()
{

}