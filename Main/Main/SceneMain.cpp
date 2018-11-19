//ＳＴＬデバッグ機能をＯＦＦにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include"GameL\DrawTexture.h"
#include"GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"
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
	Font::SetStrTex(L"0123456789");

	Draw::LoadImageW(L"image2.png", 0, TEX_SIZE_512);
	Draw::LoadImageW(L"sakura.png", 1, TEX_SIZE_512);
	Draw::LoadImageW(L"BackGround.png", 2, TEX_SIZE_2048);

	CObjDekc*obj = new CObjDekc();
	Objs::InsertObj(obj, OBJ_DEKC, 1);

	CObjEnemyDeck*obj_enemy = new CObjEnemyDeck();
	Objs::InsertObj(obj_enemy, OBJ_ENEMY_DECK, 1);

	CObjHand*obj_hand = new CObjHand();
	Objs::InsertObj(obj_hand, OBJ_HAND, 1);

	CObjEnemyHand*obj_enemy_hand = new CObjEnemyHand();
	Objs::InsertObj(obj_enemy_hand, OBJ_ENEMY_HAND, 1);

	CObjmouse* obj_mouse = new CObjmouse();
	Objs::InsertObj(obj_mouse, OBJ_MAUSE, 100);

//	CObjpoint* objt = new CObjpoint();
//	Objs::InsertObj(objt, OBJ_POINT, 11);

	CObjMap* obj_map = new CObjMap();
	Objs::InsertObj(obj_map, OBJ_MAP, 1);

	CObjBackGround* obj_background = new CObjBackGround();
	Objs::InsertObj(obj_background, OBJ_BACKGROUND, 1);

	CObjWatchCard* obj_watchcard = new CObjWatchCard();
	Objs::InsertObj(obj_watchcard, OBJ_WATCHCARD, 2);
}

//ゲームメイン実行中メソッド
void CSceneMain::Scene()
{

}