#pragma once

//オブジェクトネーム------------------------------
enum OBJ_NAME
{
	OBJ_NO_NAME,	//オブジェクト名無し(禁止)
	//ゲームで使うオブジェクトの名前
	//OBJ_○○と表記
	OBJ_DEKC,
	OBJ_ENEMY_DECK,
	OBJ_CARD,
	OBJ_ENEMY_CARD,
	OBJ_HAND,
	OBJ_ENEMY_HAND,
	OBJ_MAUSE,
	OBJ_PLAYER,
	OBJ_ENEMY,
	OBJ_MAP,
	OBJ_POINT,
	OBJ_BACKGROUND,
	OBJ_BACKGROUND2,
	OBJ_BACKGROUND3,
	OBJ_LIST,
	OBJ_WINDOW,
	OBJ_JADGE,
	OBJ_PHERO,


	OBJ_FIELD_PLAYER,
	OBJ_FIELD_PLAYER2,
	OBJ_FIELD_PLAYER3,

	OBJ_FIELD_ENEMY,
	OBJ_FIELD_ENEMY2,
	OBJ_FIELD_ENEMY3,

	OBJ_TITLE,
	OBJ_CLEAR,
	OBJ_GAMEOVER,
};
//------------------------------------------------

//当たり判定属性----------------------------------
enum HIT_ELEMENTS
{
	ELEMENT_NULL,//属性無し 全ての属性と当たり判定が実行される
	//以下　同じ属性同士では当たり判定は実行されない
	//属性は追加可能だが、デバック時の色は初期設定分しか無い
	ELEMENT_PLAYER,
	ELEMENT_ENEMY,
	ELEMENT_ITEM,
	ELEMENT_MAGIC,
	ELEMENT_FIELD,
	ELEMENT_RED,
	ELEMENT_GREEN,
	ELEMENT_BLUE,
	ELEMENT_BLACK,
	ELEMENT_WHITE,
	ELEMENT_CARD,
};
//------------------------------------------------

//------------------------------------------------
//セーブ＆ロードとシーン間のやり取りするデータ
struct UserData
{
	int mSeveData;	//サンプルセーブデータ
	
};
//------------------------------------------------


//ゲーム内で使用されるグローバル変数・定数・列挙--



//------------------------------------------------
//ゲーム内で使用するクラスヘッダ------------------


//------------------------------------------------

//ゲームシーンオブジェクトヘッダ------------------
#include"Deck.h"
#include"EnemyDeck.h"
#include"EnemyHand.h"
#include"Card.h"
#include"EnemyCard.h"
#include"mouse.h"
#include"map.h"
#include"point.h"
#include"testmau.h"
#include"HandCard.h"
#include"Cardlist.h"
#include"BackGround.h"
#include"PHero.h"
#include"EHero.h"
#include"PList.h"
#include"Window.h"
#include"Playjadge.h"

#include"Player.h"
#include"ObjTitle.h"
#include"ObjClear.h"
#include"objGameover.h"

//------------------------------------------------

//ゲームシーンクラスヘッダ------------------------
#include"SceneMain.h"
#include"SceneTitle.h"
#include"SceneClear.h"
#include"SceneGameover.h"
#include"point.h"
//-----------------------------------------------

//シーンスタートクラス---------------------------
//ゲーム開始時のシーンクラス登録
#define SET_GAME_START CSceneTitle
//-----------------------------------------------