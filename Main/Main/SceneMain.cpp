//ＳＴＬデバッグ機能をＯＦＦにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include"GameL\DrawTexture.h"
#include"GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"
#include"GameL\Audio.h"
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

	Draw::LoadImageW(L"Card.png", 0, TEX_SIZE_2048);
	Draw::LoadImageW(L"sakura.png", 1, TEX_SIZE_512);
	Draw::LoadImageW(L"BackGround.png", 2, TEX_SIZE_2048);
	Draw::LoadImageW(L"image4.png", 3, TEX_SIZE_512);

	CObjDekc*obj = new CObjDekc();
	Objs::InsertObj(obj, OBJ_DEKC, 3);

	CObjEnemyDeck*obj_enemy = new CObjEnemyDeck();
	Objs::InsertObj(obj_enemy, OBJ_ENEMY_DECK, 3);

	CObjHand*obj_hand = new CObjHand();
	Objs::InsertObj(obj_hand, OBJ_HAND, 3);

	CObjEnemyHand*obj_enemy_hand = new CObjEnemyHand();
	Objs::InsertObj(obj_enemy_hand, OBJ_ENEMY_HAND, 3);

	CObjPHero*Hero = new CObjPHero();
	Objs::InsertObj(Hero, OBJ_FIELD_PLAYER, 3);

	CObjEHero*EHero = new CObjEHero();
	Objs::InsertObj(EHero, OBJ_FIELD_ENEMY, 3);

	CObjmouse* obj_mouse = new CObjmouse();
	Objs::InsertObj(obj_mouse, OBJ_MAUSE, 100);

	CObjpoint* objt = new CObjpoint();
	Objs::InsertObj(objt, OBJ_POINT, 11);

	CObjMap* obj_map = new CObjMap();
	Objs::InsertObj(obj_map, OBJ_MAP, 1);

	CObjJadge* obj_ja = new CObjJadge();
	Objs::InsertObj(obj_ja, OBJ_JADGE, 20);

	CObjBackGround* obj_background = new CObjBackGround();
	Objs::InsertObj(obj_background, OBJ_BACKGROUND, 1);

	CObjBackGround2* obj_background2 = new CObjBackGround2();
	Objs::InsertObj(obj_background2, OBJ_BACKGROUND2, 1);

	CObjBackGround3* obj_background3 = new CObjBackGround3();
	Objs::InsertObj(obj_background3, OBJ_BACKGROUND3, 0);

	//SE・BGM
	Audio::LoadAudio(0, L"Audio\\Eden.wav", BACK_MUSIC);
	Audio::LoadAudio(1, L"Audio\\召喚2.wav", EFFECT);
	Audio::LoadAudio(2, L"Audio\\ドロー.wav", EFFECT);
	Audio::LoadAudio(3, L"Audio\\Rock_ROLA.wav", BACK_MUSIC);
	Audio::LoadAudio(4, L"Audio\\Runners_High.wav", BACK_MUSIC);
	Audio::LoadAudio(5, L"Audio\\Super_Groove_1.wav", BACK_MUSIC);
	Audio::LoadAudio(6, L"Audio\\装備.wav", EFFECT);
	Audio::LoadAudio(7, L"Audio\\破壊.wav", EFFECT);
	Audio::LoadAudio(8, L"Audio\\ダメージ.wav", EFFECT);
	Audio::LoadAudio(11, L"Audio\\召喚3.wav", EFFECT);

	Audio::Start(5);
}

//ゲームメイン実行中メソッド
void CSceneMain::Scene()
{

}